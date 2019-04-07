#include "ItemType.h"
#include "NodeType.h"

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

class DoublyLinkedList{

 public:
  // Public Methods                                                                                                                                                                                        
  DoublyLinkedList();
  ~DoublyLinkedList();
  int lengthIs() const;
  void insertItem(ItemType &item);
  void deleteItem(ItemType &item);
  void help();
  void print();
  
private:
  NodeType *head;
  NodeType *tail;
}; // DoublyLinkedList

#endif
