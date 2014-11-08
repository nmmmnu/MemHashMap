#ifndef _MEMHASHMAPBUCKET_H_
#define _MEMHASHMAPBUCKET_H_

#include "Pair.h"


class MemHashMapBucket {
private:
	unsigned int count;
	Pair **pairs; // array of Pair*

public:
	Pair *getPair(const char *key);
	int putPair(const char *key, const char *value);
	unsigned int getPairCount();

private:
	unsigned int getPairID(const char *key);
};


#endif
