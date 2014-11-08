#ifndef _MEMHASHMAP_H_
#define _MEMHASHMAP_H_

#include "MemHashMapBucket.h"

#include "IHash.h"

#include <stdlib.h>


class MemHashMap {
private:
	unsigned int capacity;
	MemHashMapBucket **buckets; // array of MemHashMapBucket*
	IHash *hash;

public:
	MemHashMap(unsigned int capacity, IHash *hash);
	virtual ~MemHashMap();

	int exists(const char *key);
	const char *get(const char *key);
	int put(const char *key, const char *value);
	unsigned int count();

private:
	MemHashMapBucket *getBucketForKey(const char *key);

};


#endif
