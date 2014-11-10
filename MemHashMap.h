#ifndef _MEMHASHMAP_H_
#define _MEMHASHMAP_H_

#include "IMap.h"

#include "ArrayMap.h"

#include "IHash.h"
#include "Pair.h"

#include <stdlib.h>


class MemHashMap : public IMap{
private:
	unsigned int _capacity;
	ArrayMap **_buckets; // array of MemHashMapBucket*
	IHash *_hash;

public:
	MemHashMap(unsigned int capacity, IHash *hash);
	virtual ~MemHashMap();

	virtual bool exists(const char *key) const;
	virtual const Pair *get(const char *key) const;
	virtual bool put(Pair *p);
	virtual bool remove(const char *key);
	virtual unsigned int count() const;

protected:
	virtual unsigned int hash(const char *key) const;

private:
	ArrayMap *_getBucketForKey(const char *key) const;

};


#endif
