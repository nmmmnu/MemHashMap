#include <stdio.h>


#include "IHash.h"
#include "DJBHash.h"

void hash_test(IHash *hash, const char *s){
	printf("Result = %10lu\n", hash->calculate(s));
}

int main(int argc, char *argv[]){
	const char *s = "Hello World";

	DJBHash *hash = new DJBHash();

	hash_test(hash, s);

	delete hash;

	//getchar();

	return 0;
}
