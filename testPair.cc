
#include <stdio.h>
#include <string.h>

#include "Pair.h"

#define KEY "name"

int main(){
	char key[] = KEY;

	Pair *p = new Pair(key, "Niki");

	key[0] = 'M';

	printf("Test via strcmp %s\n", strcmp(p->key, KEY) == 0 ? "OK" : "Fail");
	printf("Test via method %s\n", p->equals(KEY) ? "OK" : "Fail");
	printf("Test via op ==  %s\n", *p == (char *)KEY ? "OK" : "Fail");

	printf("\nPair Contents:\n");
	printf("key:   %s\n", p->key);
	printf("value: %s\n", p->value);

	printf("\nSizes:\n");
	printf("sizeof(Pair  ) : %10lu\n", sizeof(Pair) );
	printf("sizeof(Pair *) : %10lu\n", sizeof(Pair *) );

	delete p;
}
