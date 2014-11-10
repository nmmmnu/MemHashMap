#ifndef _MEMHASHMAP_H_
#define _MEMHASHMAP_H_

#include "ArrayMap.h"

#include "IHash.h"

#include <stdlib.h>


class MemHashMap {
private:
	unsigned int _capacity;
	ArrayMap **_buckets; // array of MemHashMapBucket*
	IHash *_hash;

public:
	MemHashMap(unsigned int capacity, IHash *hash);
	virtual ~MemHashMap();

	virtual unsigned int hash(const char *key);

	int exists(const char *key);
	const char *get(const char *key);
	bool put(const char *key, const char *value);
	bool remove(const char *key);
	unsigned int count();

private:
	ArrayMap *_getBucketForKey(const char *key);

};


#endif
