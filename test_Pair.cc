
#include <stdio.h>
#include <string.h>

#include "Pair.h"

#define KEY "name"

#define TEST_FORMAT "%-20s %s\n"

int main(){
	char key[] = KEY;

	Pair *p  = new Pair(key, "Niki");
	Pair *p1 = new Pair(key, NULL);

	key[0] = 'M';

	printf(TEST_FORMAT, "Test via strcmp",		strcmp(p->key, KEY) == 0	? "OK" : "Fail"	);
	printf(TEST_FORMAT, "Test via method",		p->equals(KEY)			? "OK" : "Fail"	);
	printf(TEST_FORMAT, "Test via op == ",		*p == (char *)KEY		? "OK" : "Fail"	);
	printf(TEST_FORMAT, "Test Pair->valid()",	p1->valid() == 0		? "OK" : "Fail"	);

	printf("\nPair Contents:\n");
	p->print(1);

	printf("\nPair Contents:\n");
	p1->print(true);

	delete p;
	delete p1;

	printf("\nSizes:\n");
	printf("sizeof(Pair  ) : %10lu\n", sizeof(Pair) );
	printf("sizeof(Pair *) : %10lu\n", sizeof(Pair *) );
}
