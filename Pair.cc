#include "Pair.h"

#include <string.h>
#include <stdlib.h>


Pair::Pair(const char *key, const char *value){
	this->key   = cloneStr(key);
	this->value = cloneStr(value);
}


Pair::~Pair(){
	free(this->key);
	free(this->value);
}


char *Pair::cloneStr(const char *src){
	size_t len = strlen(src);

	char *dest = (char *) malloc(len + 1);

	strncpy(dest, src, len + 1);

	return dest;
}


int Pair::equals(const char *s){
	return ! strcmp(this->key, s);
};


int Pair::operator == (const char *s){
	return equals(s);
}


