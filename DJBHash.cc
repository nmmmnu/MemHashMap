#include "DJBHash.h"

unsigned long DJBHash::calculate(const char *str){
	unsigned long hash = 5381;

	int c;
	// double () is to avoid C++ warning...
	while( (c = *str++) ) {
		hash = ((hash << 5) + hash) + c;
	}

	return hash;
}

