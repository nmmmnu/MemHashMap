#ifndef _DJBHASH_H
#define _DJBHASH_H

#include "IHash.h"

class DJBHash : public IHash{
public:
	virtual unsigned long int calculate(const char *);
};

#endif
