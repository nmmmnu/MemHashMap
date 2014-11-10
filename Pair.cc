#include "Pair.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#define MICRO_TIME_MULTIPLE 1000 * 1000

Pair::Pair(const char *key, const char *value, unsigned long int expires /* = 0 */){
	this->key     = _cloneStr(key);
	this->value   = _cloneStr(value);
	this->created = _now();
	this->expires = expires;
}


Pair::~Pair(){
	free(this->key);
	free(this->value);
}


/* static */ char *Pair::_cloneStr(const char *src){
	if (src == NULL)
		return NULL;

	size_t len = strlen(src);

	char *dest = (char *) malloc(len + 1);

	strncpy(dest, src, len + 1);

	return dest;
}


/* static */ unsigned long int Pair::_now(){
	struct timeval tv;

	gettimeofday(&tv,NULL);

	return tv.tv_sec * MICRO_TIME_MULTIPLE + tv.tv_usec;
}


bool Pair::equals(const char *s){
	return ! strcmp(this->key, s);
};


bool Pair::operator == (const char *s){
	return equals(s);
}

// For the moment validity is simple,
// both key and value must be not NULL.
bool Pair::valid(){
	return key != NULL && value != NULL && (! expired() );
}

bool Pair::expired(){
	//printf("%ld %ld %ld %ld", created, expires, created + expires * MICRO_TIME_MULTIPLE,  _now());

	if (expires)
		return created + expires * MICRO_TIME_MULTIPLE < _now();

	return false;
}

void Pair::print(const bool pretty /* = 0 */){
	const char *mask;

	if (pretty){
		mask =	"key:   %s\n"
			"value: %s\n";
	}else{
		mask = "%-10s = %s\n";
	}

	if (! valid()){
		printf(mask, "(INVALID)", "(INVALID)");
		return;
	}

	printf(mask, key, value);
}

