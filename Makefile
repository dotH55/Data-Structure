all: main.o ItemType.o BinaryTree.o
	g++ -c ItemType.cpp
	g++ -c main.cpp
	g++ -c BinaryTree.cpp
	g++ -o main main.o ItemType.o BinaryTree.o
