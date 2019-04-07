#include "ItemType.h"
#include "NodeType.h"

#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

class CircularLinkedList{

 public:
  // Public Methods                                                                                                                                                                                        
  CircularLinkedList();
  ~CircularLinkedList();
  int lengthIs() const;
  void insertItem(ItemType &item);
  void deleteItem(ItemType &item);
  void help();
  void helpFirst();
  void next();
  void print();
  
private:
  int length;
  NodeType *head;
  NodeType *currentPos;
}; // CircularLinkedList

#endif
