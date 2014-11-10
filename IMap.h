#ifndef _IHASHMAP_H
#define _IHASHMAP_H

#include "Pair.h"

class IMap {
public:
	virtual ~IMap(){};

	virtual bool exists(const char *key) const =0;
	virtual const Pair *get(const char *key) const =0;
	virtual bool put(Pair *p) =0;
	virtual bool remove(const char *key) =0;
	virtual unsigned int count() const =0;

	//virtual void print(const unsigned int cnt = 0) =0;
};


#endif
