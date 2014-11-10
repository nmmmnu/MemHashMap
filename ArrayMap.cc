#include "ArrayMap.h"

#include <stdlib.h>
#include <stdio.h>


unsigned int ArrayMap::_getPairID(const char *key){
	if (_count == 0)
		return 0;

	unsigned int i;
	for(i = 0; i < _count; i++){
		Pair *pair = _pairs[i];

		if (pair)
			if (pair->equals(key))
				return i + 1;
	}

	return 0;
}


Pair *ArrayMap::getPair(const char *key){
	unsigned int pos = _getPairID(key);

	if (pos)
		return _pairs[pos - 1];

	return NULL;
}


bool ArrayMap::putPair(Pair *newpair){
	if (newpair == NULL)
		return false;

	if (! newpair->valid())
		return false;

	// is bucket empty?
	if (_count == 0){
		_pairs = (Pair **)malloc(sizeof(Pair *));
		if (_pairs == NULL){
			// error, but pairs were NULL anyway.
			return false;
		}

		_count = 1;
		_pairs[0] = newpair;

		return true;
	}

	// is key already in the bucket?
	unsigned int pos = _getPairID(newpair->key);

	if (pos){
		delete _pairs[pos - 1];
		_pairs[pos - 1] = newpair;

		return true;
	}

	// seems, the bucket is non empty and pair is not in the bucket.

	Pair **relocated_pairs = (Pair **) realloc(_pairs, (_count + 1) * sizeof(Pair *));
	if (relocated_pairs == NULL) {
		// error, but pairs are untouched
		return false;
	}

	_pairs = relocated_pairs;
	_count++;

	_pairs[_count - 1] = newpair;

	return true;
}


bool ArrayMap::putPair(const char *key, const char *value){
	if (key == NULL || value == NULL)
		return false;

	return putPair(new Pair(key, value));
}


bool ArrayMap::removePair(const char *key){
	if (key == NULL)
		return false;

	// is key already in the bucket?
	unsigned int pos = _getPairID(key);

	if (pos == 0){
		// no problem to remove something that does not exists
		return true;
	}

	delete _pairs[pos - 1];

	if (_count == 1){
		free(_pairs);
		_count = 0;
		return true;
	}

	if (pos < _count){
		// "swap" with last one
		_pairs[pos - 1] = _pairs[_count - 1];
		// clean up in case realloc fails...
		_pairs[_count - 1] = NULL;
	}

	// remove last element
	Pair **relocated_pairs = (Pair **) realloc(_pairs, (_count - 1) * sizeof(Pair *));
	if (relocated_pairs == NULL) {
		// error, but pairs are untouched
		// last one is NULL, but this is relatively OK.
		return false;
	}

	_pairs = relocated_pairs;
	_count--;

	return true;
}


unsigned int ArrayMap::getPairCount(){
	unsigned int cnt = 0;

	unsigned int i;
	for(i = 0; i < _count; i++){
		Pair *pair = _pairs[i];

		if (pair)
			if (pair->valid())
				cnt++;
	}

	return cnt;
}


void ArrayMap::printPairs(const unsigned int cnt /* = 0 */){
	printf("Pair count: %u\n", _count);

	unsigned int i;
	for(i = 0; i < _count; i++){
		Pair *pair = _pairs[i];

		if (pair == NULL){
			printf("(NULL)\n");
			continue;
		}

		pair->print();

		if (i >= cnt && cnt != 0)
			break;
	}
}
