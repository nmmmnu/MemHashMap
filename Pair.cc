#include "Pair.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


Pair::Pair(const char *key, const char *value){
	this->key   = cloneStr(key);
	this->value = cloneStr(value);
}


Pair::~Pair(){
	free(this->key);
	free(this->value);
}


char *Pair::cloneStr(const char *src){
	if (src == NULL)
		return NULL;

	size_t len = strlen(src);

	char *dest = (char *) malloc(len + 1);

	strncpy(dest, src, len + 1);

	return dest;
}


bool Pair::equals(const char *s){
	return ! strcmp(this->key, s);
};


bool Pair::operator == (const char *s){
	return equals(s);
}

// For the moment validity is simple,
// both key and value must be not NULL.
int Pair::valid(){
	return key != NULL && value != NULL;
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

