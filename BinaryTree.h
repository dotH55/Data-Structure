#include <iostream>
#include <string>

#include "ItemType.h"
#include "Node.h"

#ifndef BINARYTREE_H
#define BINARYTREE_H

using namespace std;

class BinaryTree{

 public:
  BinaryTree();
  ~BinaryTree();
  void insert(ItemType &);
  void deleteItem(ItemType &);
  void retrieve(ItemType &, bool &) const;
  void preOrder() const;
  void inOrder() const;
  void postOrder() const;
  int getLength() const;
  void Delete(Node*&, ItemType);
  void deleteNode(Node*&);
  void printHelp() const;
  void getSameLevelNonSiblings(ItemType&);
  void print() const;
  void copyTree(Node*&, const Node*);
  bool isFull() const;
  bool isEmpty() const;
  int getHeight() const;

 private:
  Node *root;
  int length;
}; // BinaryTree

#endif
