#include "ItemType.h"
#include "Node.h"

#ifndef BINARYTREE_H
#define BINARYTREE_H

using namespace std

class BinaryTree{

 public:
  BinaryTree();
  ~BinaryTree();
  void insert(ItemType &key);
  void deleteItem(ItemType &key);
  void retrieve(ItemType &item, bool &found);
  void preOrder() const;
  void inOrder() const;
  void postOrder() const;
  int getLength() const;
  //void getSameLevelNonsiblings(ItemType &key);
  void printTree() const;

 private:
  Node *root;
  int length;
}; // BinaryTree

#endif
