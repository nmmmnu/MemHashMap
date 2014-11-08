#include <stdio.h>
#include <string.h>

#include "MemHashMap.h"
#include "DJBHash.h"

inline char *i2a(int i, char *buffer){
	sprintf(buffer, "%d", i);
	return buffer;
}

#define BUCKETS 1024

#define MAX 1024 * 4

int main(){
	char buffer[1024];

	MemHashMap *hm = new MemHashMap(BUCKETS, new DJBHash());

	int i;
	for(i = 0; i < MAX; i++){
		char *key = i2a(i, buffer);

		hm->put(key, key);

		if (i % 1000 == 0)
			printf("processed %d\n", i);
	}


	const char *key = i2a(MAX - 5, buffer);
	const char *value = hm->get(key);

	printf("Test get      %s\n", strcmp(key, value) == 0 ? "OK" : "Fail");

	printf("\nPair Contents:\n");
	printf("key:   %s\n", key);
	printf("value: %s\n", value);


	printf("\nSizes:\n");
	printf("sizeof(MemHashMap  ) : %10lu\n", sizeof(MemHashMap) );
	printf("sizeof(MemHashMap *) : %10lu\n", sizeof(MemHashMap *) );

	delete hm;

	return 0;
}

