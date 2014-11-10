#ifndef _EXPIRESPAIR_H
#define _EXPIRESPAIR_H


#include "Pair.h"


class ExpiresPair : public Pair {
public:
	unsigned long int created;
	unsigned long int expires;

public:
	ExpiresPair(const char *key, const char *value, unsigned long int expires = 0);
	virtual ~ExpiresPair();

	virtual bool valid();

	bool expired();

private:
	static unsigned long int _now();

};


#endif
