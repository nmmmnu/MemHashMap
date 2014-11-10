#ifndef _ARRAYMAP_H
#define _ARRAYMAP_H

#include "Pair.h"


class ArrayMap {
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
	unsigned int _getPairID(const char *key);
};


#endif