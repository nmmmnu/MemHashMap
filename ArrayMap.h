#ifndef _ARRAYMAP_H
#define _ARRAYMAP_H

#include "IMap.h"
#include "Pair.h"


class ArrayMap : public IMap{
private:
	unsigned int _count;
	Pair **_pairs; // array of Pair*

public:
	virtual ~ArrayMap(){};

	virtual bool exists(const char *key) const;
	virtual const Pair *get(const char *key) const;
	virtual bool put(Pair *pair);
	virtual bool remove(const char *key);
	virtual unsigned int count() const;

	void print(const unsigned int cnt = 0);

private:
	unsigned int _getPairID(const char *key) const;
};


#endif
