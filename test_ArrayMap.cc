#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayMap.h"


inline char *i2a(int i, char *buffer){
	sprintf(buffer, "%d", i);
	return buffer;
}


#define MAX 1000 * 10

#define TESTKEY MAX / 2


int main(int argc, char *argv[]){
	ArrayMap *b = new ArrayMap();

	char buffer[100];
	unsigned int i;
	for(i = 0; i < MAX; i++){
		char *s = i2a(i, buffer);
		b->putPair(new Pair(s, s));

		if (i % (MAX / 10) == 0)
			printf("Processing %10d\n", i);
	}

	const char *key = i2a(TESTKEY, buffer);
	const char *val = "hello world";

	// put duplicate
	b->putPair(key, val);

	b->removePair("0");
	b->removePair("10");
	b->removePair("20");

	printf("Test getPairCount %s\n", b->getPairCount() == MAX - 3 ? "OK" : "Fail");


	Pair *p = b->getPair(key);

	if (p == NULL){
		printf("NULL returned, halt\n");
		exit(1);
	}

	printf("Test getPair      %s\n", *p == key ? "OK" : "Fail");
	printf("Test getPair      %s\n", strcmp(p->value, val) == 0 ? "OK" : "Fail");

	printf("\nList Pairs:\n");
	b->printPairs(30);

	printf("\nSizes:\n");
	printf("sizeof(ArrayMap  ) : %10lu\n", sizeof(ArrayMap) );
	printf("sizeof(ArrayMap *) : %10lu\n", sizeof(ArrayMap *) );

	delete b;
}
