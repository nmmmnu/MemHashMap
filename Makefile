CC   = gcc -Wall -c
LINK = gcc -lstdc++ -o



all: testIHash testPair testMemHashMapBucket testMemHashMap



clean:
	rm -f *.o test



testIHash: testIHash.o DJBHash.o
	$(LINK) testIHash testIHash.o DJBHash.o

testIHash.o: testIHash.cc DJBHash.h IHash.h
	$(CC) testIHash.cc

DJBHash.o: DJBHash.cc DJBHash.h IHash.h
	$(CC) DJBHash.cc



testPair: testPair.o Pair.o
	$(LINK) testPair testPair.o Pair.o

testPair.o: testPair.cc Pair.h
	$(CC) testPair.cc

Pair.o: Pair.cc Pair.h
	$(CC) Pair.cc



testMemHashMapBucket: testMemHashMapBucket.o MemHashMapBucket.o Pair.o
	$(LINK) testMemHashMapBucket testMemHashMapBucket.o MemHashMapBucket.o Pair.o

testMemHashMapBucket.o: testMemHashMapBucket.cc MemHashMapBucket.h
	$(CC) testMemHashMapBucket.cc

MemHashMapBucket.o: MemHashMapBucket.cc MemHashMapBucket.h Pair.h
	$(CC) MemHashMapBucket.cc



testMemHashMap: testMemHashMap.o MemHashMap.o MemHashMapBucket.o Pair.o DJBHash.o
	$(LINK) testMemHashMap testMemHashMap.o MemHashMap.o MemHashMapBucket.o Pair.o DJBHash.o

testMemHashMap.o: testMemHashMap.cc MemHashMap.h IHash.h DJBHash.h
	$(CC) testMemHashMap.cc

MemHashMap.o: MemHashMap.cc MemHashMap.h MemHashMapBucket.h Pair.h IHash.h
	$(CC) MemHashMap.cc


