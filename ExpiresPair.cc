#include "ExpiresPair.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#define MICRO_TIME_MULTIPLE 1000 * 1000

ExpiresPair::ExpiresPair(const char *key, const char *value, unsigned long int expires /* = 0 */) : Pair(key, value){
	_created = _now();
	_expires = expires;
}


ExpiresPair::~ExpiresPair(){

}


/* static */ unsigned long int ExpiresPair::_now(){
	struct timeval tv;

	gettimeofday(&tv,NULL);

	return tv.tv_sec * MICRO_TIME_MULTIPLE + tv.tv_usec;
}


// ExpiresPair must be valid Pair and not expired.
bool ExpiresPair::valid() const{
	return Pair::valid() && (! expired() );
}


bool ExpiresPair::expired() const{
	//printf("%ld %ld %ld %ld", created, expires, created + expires * MICRO_TIME_MULTIPLE,  _now());

	if (_expires)
		return _created + _expires * MICRO_TIME_MULTIPLE < _now();

	return false;
}

