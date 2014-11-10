#include "MemHashMap.h"

#include <stdio.h>
#include <string.h>


MemHashMap::MemHashMap(unsigned int capacity, IHash *hash){
	_capacity = capacity;
	_hash = hash;

	_buckets = (MemHashMapBucket **) malloc(_capacity * sizeof(MemHashMapBucket *));

	if (_buckets == NULL){
		printf("Not enought memory...");
		exit(1);
	}

	memset(_buckets, 0, _capacity * sizeof(MemHashMapBucket *));
}


MemHashMap::~MemHashMap(){
	unsigned int i;
	for(i = 0; i < _capacity; i++) {
		MemHashMapBucket *bucket = _buckets[i];

		if (bucket)
			delete bucket;
	}

	free(_buckets);
}


MemHashMapBucket *MemHashMap::getBucketForKey(const char *key){
	if (key == NULL)
		return NULL;

	unsigned int index = _hash->calculate(key) % _capacity;

	// if bucket is NULL, it is not created yet
	if (_buckets[index] == NULL)
		_buckets[index] = new MemHashMapBucket();

	return _buckets[index];
}


int MemHashMap::exists(const char *key){
	// this is handled by next function too...
	if (key == NULL)
		return 0;

	MemHashMapBucket *bucket = getBucketForKey(key);

	if (bucket == NULL)
		return 0;

	Pair *pair = bucket->getPair(key);

	return pair == NULL ? 0 : 1;
}


const char *MemHashMap::get(const char *key){
	if (key == NULL)
		return NULL;

	MemHashMapBucket *bucket = getBucketForKey(key);

	if (bucket == NULL)
		return NULL;

	Pair *pair = bucket->getPair(key);

	return pair->value;
}


unsigned int MemHashMap::count(){
	if (_capacity == 0)
		return 0;

	unsigned int cnt = 0;

	unsigned int i;
	for(i = 0; i < _capacity; i++){
		MemHashMapBucket *bucket = _buckets[i];

		if (bucket)
			cnt = cnt + bucket->getPairCount();
	}

	return cnt;
}



bool MemHashMap::put(const char *key, const char *value){
	if (key == NULL || value == NULL)
		return 0;

	MemHashMapBucket *bucket = getBucketForKey(key);

	return bucket->putPair(new Pair(key, value));
}


bool MemHashMap::remove(const char *key){
	if (key == NULL)
		return 0;

	MemHashMapBucket *bucket = getBucketForKey(key);
	return bucket->removePair(key);
}

