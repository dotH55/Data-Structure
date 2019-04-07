#include "ItemType.h"
#include "ListNode.h"

#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

class SortedLinkedList{

 public:

  //Public Data Members
  ItemType item;
  ListNode *next;

  // Public Methods
  SortedLinkedList();
  ~SortedLinkedList();
  int getLength() const;
  void insertItem(ItemType);
  void deleteItem(ItemType);
  int searchItem(ItemType &item);
  ItemType GetNextItem();
  void ResetList();
  void printHelp();
  void printList();
  void reverse();


private:
  int length;
  ListNode *head;
  ListNode *currentPos;
}; // SortedLinkedList

#endif
