binarySearchTree: main.o binarySearchTree.o
        g++ -o binarySearchTree main.o binarySearchTree.o

main.o: main.cpp
        g++ -c main.cpp

binarySearchTree.o: binarySearchTree.cpp binarySearchTree.h
        g++ -c binarySearchTree.cpp

clean:
        rm -f binarySearchTree *.o *-
