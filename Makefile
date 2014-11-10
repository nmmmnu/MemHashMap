CC   = gcc -Wall -c
LINK = gcc -lstdc++ -o



all: test_IHash test_Pair test_MemHashMapBucket test_MemHashMap



clean:
	rm -f *.o test_



test_IHash: test_IHash.o DJBHash.o
	$(LINK) test_IHash test_IHash.o DJBHash.o

test_IHash.o: test_IHash.cc DJBHash.h IHash.h
	$(CC) test_IHash.cc

DJBHash.o: DJBHash.cc DJBHash.h IHash.h
	$(CC) DJBHash.cc



test_Pair: test_Pair.o Pair.o
	$(LINK) test_Pair test_Pair.o Pair.o

test_Pair.o: test_Pair.cc Pair.h
	$(CC) test_Pair.cc

Pair.o: Pair.cc Pair.h
	$(CC) Pair.cc



test_MemHashMapBucket: test_MemHashMapBucket.o MemHashMapBucket.o Pair.o
	$(LINK) test_MemHashMapBucket test_MemHashMapBucket.o MemHashMapBucket.o Pair.o

test_MemHashMapBucket.o: test_MemHashMapBucket.cc MemHashMapBucket.h
	$(CC) test_MemHashMapBucket.cc

MemHashMapBucket.o: MemHashMapBucket.cc MemHashMapBucket.h Pair.h
	$(CC) MemHashMapBucket.cc



test_MemHashMap: test_MemHashMap.o MemHashMap.o MemHashMapBucket.o Pair.o DJBHash.o
	$(LINK) test_MemHashMap test_MemHashMap.o MemHashMap.o MemHashMapBucket.o Pair.o DJBHash.o

test_MemHashMap.o: test_MemHashMap.cc MemHashMap.h IHash.h DJBHash.h
	$(CC) test_MemHashMap.cc

MemHashMap.o: MemHashMap.cc MemHashMap.h MemHashMapBucket.h Pair.h IHash.h
	$(CC) MemHashMap.cc


