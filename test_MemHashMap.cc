#include <stdio.h>
#include <string.h>

#include "MemHashMap.h"
#include "DJBHash.h"
#include "Pair.h"

inline char *i2a(int i, char *buffer){
	sprintf(buffer, "%d", i);
	return buffer;
}

#define BUCKETS 1024

#define MAX 1024 * 100

#define TEST_FORMAT "%-20s %s\n"


int main(int argc, char *argv[]){
	char buffer[1024];
	char buffer2[1024];

	MemHashMap *hm = new MemHashMap(BUCKETS, new DJBHash());

	int i;
	for(i = 0; i < MAX; i++){
		char *key = i2a(i, buffer);

		hm->put(new Pair(key, key));

		if (i % (MAX / 10) == 0)
			printf("processed %d\n", i);
	}

	const char *key = i2a(MAX - 5, buffer);
	Pair *p = hm->get(key);

	const char *keyr = i2a(MAX / 2, buffer2);

	hm->remove(keyr);


	printf(TEST_FORMAT, "Test get",		strcmp(key, p->value) == 0	? "OK" : "Fail");
	printf(TEST_FORMAT, "Test exists",	hm->exists(key)			? "OK" : "Fail");
	printf(TEST_FORMAT, "Test ! exists",	! hm->exists(keyr)		? "OK" : "Fail");
	printf(TEST_FORMAT, "Test count",	hm->count() == MAX - 1		? "OK" : "Fail");

	printf("\nPair Contents:\n");
	printf("key:   %s\n", key);
	printf("value: %s\n", p->value);


	printf("\nSizes:\n");
	printf("sizeof(MemHashMap  ) : %10lu\n", sizeof(MemHashMap) );
	printf("sizeof(MemHashMap *) : %10lu\n", sizeof(MemHashMap *) );

	delete hm;

	return 0;
}

