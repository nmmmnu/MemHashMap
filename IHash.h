#ifndef _HASH_H_
#define _HASH_H_


class IHash{
public:
	virtual ~IHash(){};
	virtual unsigned long int calculate(const char *)=0;
};


#endif
