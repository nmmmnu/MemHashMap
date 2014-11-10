CC   = gcc -Wall -c
LINK = gcc -lstdc++ -o



all: test_IHash test_Pair test_ArrayMap test_MemHashMap



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



test_ArrayMap: test_ArrayMap.o ArrayMap.o Pair.o
	$(LINK) test_ArrayMap test_ArrayMap.o ArrayMap.o Pair.o

test_ArrayMap.o: test_ArrayMap.cc ArrayMap.h Pair.h
	$(CC) test_ArrayMap.cc

ArrayMap.o: ArrayMap.cc ArrayMap.h Pair.h
	$(CC) ArrayMap.cc



test_MemHashMap: test_MemHashMap.o MemHashMap.o ArrayMap.o Pair.o DJBHash.o
	$(LINK) test_MemHashMap test_MemHashMap.o MemHashMap.o ArrayMap.o Pair.o DJBHash.o

test_MemHashMap.o: test_MemHashMap.cc MemHashMap.h IHash.h DJBHash.h
	$(CC) test_MemHashMap.cc

MemHashMap.o: MemHashMap.cc MemHashMap.h ArrayMap.h Pair.h IHash.h
	$(CC) MemHashMap.cc


