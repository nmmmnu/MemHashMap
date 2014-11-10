#ifndef _MEMHASHMAP_H_
#define _MEMHASHMAP_H_

#include "MemHashMapBucket.h"

#include "IHash.h"

#include <stdlib.h>


class MemHashMap {
private:
	unsigned int _capacity;
	MemHashMapBucket **_buckets; // array of MemHashMapBucket*
	IHash *_hash;

public:
	MemHashMap(unsigned int capacity, IHash *hash);
	virtual ~MemHashMap();

	int exists(const char *key);
	const char *get(const char *key);
	bool put(const char *key, const char *value);
	bool remove(const char *key);
	unsigned int count();

private:
	MemHashMapBucket *getBucketForKey(const char *key);

};


#endif
