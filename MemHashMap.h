#ifndef _MEMHASHMAP_H_
#define _MEMHASHMAP_H_

#include "ArrayMap.h"

#include "IHash.h"
#include "Pair.h"

#include <stdlib.h>


class MemHashMap {
private:
	unsigned int _capacity;
	ArrayMap **_buckets; // array of MemHashMapBucket*
	IHash *_hash;

public:
	MemHashMap(unsigned int capacity, IHash *hash);
	virtual ~MemHashMap();

	int exists(const char *key);
	Pair *get(const char *key);
	bool put(Pair *p);
	bool remove(const char *key);
	unsigned int count();

protected:
	virtual unsigned int hash(const char *key);

private:
	ArrayMap *_getBucketForKey(const char *key);

};


#endif
