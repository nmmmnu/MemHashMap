#include "MemHashMap.h"

#include <stdio.h>
#include <string.h>


MemHashMap::MemHashMap(unsigned int capacity, IHash *hash){
	this->capacity = capacity;
	this->hash = hash;

	buckets = (MemHashMapBucket **) malloc(capacity * sizeof(MemHashMapBucket *));

	if (buckets == NULL){
		printf("Not enought memory...");
		exit(1);
	}

	memset(buckets, 0, capacity * sizeof(MemHashMapBucket *));
}


MemHashMap::~MemHashMap(){
	unsigned int i;
	for(i = 0; i < capacity; i++) {
		MemHashMapBucket *bucket = buckets[i];

		if (bucket)
			delete bucket;
	}

	free(buckets);
}


MemHashMapBucket *MemHashMap::getBucketForKey(const char *key){
	if (key == NULL)
		return NULL;

	unsigned int index = hash->calculate(key) % capacity;

	// if bucket is NULL, it is not created yet
	if (buckets[index] == NULL)
		buckets[index] = new MemHashMapBucket();

	return buckets[index];
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
	if (capacity == 0)
		return 0;

	unsigned int cnt = 0;

	unsigned int i;
	for(i = 0; i < capacity; i++){
		MemHashMapBucket *bucket = buckets[i];

		if (bucket)
			cnt = cnt + bucket->getPairCount();
	}

	return cnt;
}



int MemHashMap::put(const char *key, const char *value){
	if (key == NULL || value == NULL)
		return 0;

	MemHashMapBucket *bucket = getBucketForKey(key);

	return bucket->putPair(key, value);
}



