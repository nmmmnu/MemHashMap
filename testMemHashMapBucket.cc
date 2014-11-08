#include <stdio.h>
#include <stdlib.h>

#include "MemHashMapBucket.h"


inline char *i2a(int i, char *buffer){
	sprintf(buffer, "%d", i);
	return buffer;
}


#define MAX 1024 * 4


int main(){
	MemHashMapBucket *b = new MemHashMapBucket();

	char buffer[100];
	unsigned int i;
	for(i = 0; i < MAX; i++){
		char *s = i2a(i, buffer);
		b->putPair(s, s);
	}

	printf("Test getPairCount %s\n", b->getPairCount() == MAX ? "OK" : "Fail");

	char *key = i2a(MAX / 3, buffer);

	Pair *p = b->getPair(key);

	printf("Test getPair      %s\n", *p == key ? "OK" : "Fail");


	printf("\nSizes:\n");
	printf("sizeof(MemHashMapBucket  ) : %10lu\n", sizeof(MemHashMapBucket) );
	printf("sizeof(MemHashMapBucket *) : %10lu\n", sizeof(MemHashMapBucket *) );

	delete b;
}
