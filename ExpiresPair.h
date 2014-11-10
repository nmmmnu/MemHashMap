#ifndef _EXPIRESPAIR_H
#define _EXPIRESPAIR_H


#include "Pair.h"


class ExpiresPair : public Pair {
private:
	unsigned long int _created;
	unsigned long int _expires;

public:
	ExpiresPair(const char *key, const char *value, unsigned long int expires = 0);
	virtual ~ExpiresPair();

	virtual bool valid() const;

	bool expired() const;

private:
	static unsigned long int _now();

};


#endif
