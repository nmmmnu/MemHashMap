#include "MemHashMapBucket.h"

#include <stdlib.h>


unsigned int MemHashMapBucket::getPairID(const char *key){
	if (count == 0)
		return 0;

	unsigned int i;
	for(i = 0; i < count; i++){
		Pair *pair = pairs[i];

		if (pair->equals(key))
			return i + 1;
	}

	return 0;
}


Pair *MemHashMapBucket::getPair(const char *key){
	unsigned int pos = getPairID(key);

	if (pos)
		return pairs[pos - 1];

	return NULL;
}


int MemHashMapBucket::putPair(const char *key, const char *value){
	if (key == NULL || value == NULL)
		return 0;

	Pair *newpair = new Pair(key, value);

	// is bucket empty?
	if (count == 0){
		pairs = (Pair **)malloc(sizeof(Pair *));
		if (pairs == NULL){
			// error, but pairs were NULL
			return 0;
		}

		count = 1;
		pairs[0] = newpair;

		return 1;
	}

	// is key already in the bucket?
	unsigned int pos = getPairID(key);

	if (pos){
		delete pairs[pos - 1];
		pairs[pos - 1] = newpair;

		return 1;
	}

	// seems, the bucket is non empty.

	Pair **relocated_pairs = (Pair **) realloc(pairs, (count + 1) * sizeof(Pair *));
	if (relocated_pairs == NULL) {
		// error, but pairs are untouched
		return 0;
	}

	pairs = relocated_pairs;
	count++;

	pairs[count - 1] = newpair;

	return 1;
}


unsigned int MemHashMapBucket::getPairCount(){
	unsigned int cnt = 0;

	unsigned int i;
	for(i = 0; i < count; i++){
		Pair *pair = pairs[i];

		if (pair->key != NULL && pair->value != NULL)
			cnt++;
	}

	return cnt;
}

