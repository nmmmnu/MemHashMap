#ifndef _MEMHASHMAPBUCKET_H_
#define _MEMHASHMAPBUCKET_H_

#include "Pair.h"


class MemHashMapBucket {
private:
	unsigned int _count;
	Pair **_pairs; // array of Pair*

public:
	Pair *getPair(const char *key);
	bool putPair(Pair *pair);
	bool removePair(const char *key);
	unsigned int getPairCount();

public: /* for now */
	bool putPair(const char *key, const char *value);

	void printPairs(const unsigned int cnt = 0);

private:
	unsigned int getPairID(const char *key);
};


#endif
