p7: main.o binarySearchTree.o
        g++ -o p7 main.o binarySearchTree.o

main.o: main.cpp
        g++ -c main.cpp

binarySearchTree.o: binarySearchTree.cpp binarySearchTree.h
        g++ -c binarySearchTree.cpp

clean:
        rm -f p7 *.o *-
