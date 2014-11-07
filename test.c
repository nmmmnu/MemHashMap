#include <stdio.h>

#include "strmap.h"

#define BUFFER_MAX	1024
#define MAX		10 * 1000 * 1000
#define BUCKETS		1 * 1000 * 1000


inline char *i2a(int i, char *buffer){
    sprintf(buffer, "%010d", i);
    return buffer;
}



int main(unsigned int argc, char *argv[]){
   char buffer[BUFFER_MAX];
   char buffer2[BUFFER_MAX];

   StrMap *sm = sm_new(BUCKETS);

   if (sm == NULL) {
	printf("Error allocating...\n");
	return 1;
   }


   int i;
   for(i = 0; i < MAX; i++){
      char *key = i2a(i, buffer);

      sm_put(sm, key, key);

      if (i % 100000 == 0)
         printf("processed %d\n", i);
   }



   if ( sm_get(sm, i2a(MAX - 5, buffer), buffer2, sizeof(buffer2)) == 0){
	printf("Error retreiving data...\n");
	return 1;
   }

   printf("value: %s\n", buffer2);

   getchar();

   return 0;
}
