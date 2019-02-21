CC = clang++
CFLAGS = -Wall -Wextra -c -std=c++11
DEPS = HashItem.h HashTable.h FSTree.h Index.h DirNode.h

%.o: %.cpp %(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

gerp: driver.o HashItem.o HashTable.o FSTree.o Index.o DirNode.o
	$(CC) -o gerp driver.o HashItem.o HashTable.o FSTree.o Index.o DirNode.o

clean:
	rm -f *.o core* *~ gerp