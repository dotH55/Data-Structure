#include <iostream>
#include <cstddef>

#include "SortedLinkedList.h"
#include "ItemType.h"
#include "ListNode.h"

using namespace std;

//Constructor
SortedLinkedList::SortedLinkedList(){
  length = 0;
  head = NULL;
} // SortedLinkedList

//Destructor
SortedLinkedList::~SortedLinkedList(){
  ListNode *location = head;
  ListNode *tempLocation;
  while(location != NULL){
    tempLocation = location->next;
    location = location->next;
    delete tempLocation;
  } // while
  cout << "/nDestructor Called/n";
} // ~SortedLinkedList

void SortedLinkedList:: insertItem(ItemType item_){
  ListNode *location = head;
  ListNode *preLoc = NULL;  
  ListNode *newNode;
  int brake = 0;

  //Empty List
  if(head == NULL){
    head = new ListNode;
    head->item = item_;
    head->next = NULL;
    length++;
   return;
  } // if

  //Insert at length = 0
  if(item_.compareTo(location->item) == LESS){
      newNode = new ListNode;
      newNode->item = item_;
      newNode->next = location;
      head = newNode;
      length++;
      return;
  } // if
  
  if(item_.compareTo(location->item) == EQUAL){
      cout << "\nError: Duplication\n" << endl;
      return;
  } // if

  //General Case
      while(location->next != NULL && brake == 0){
	switch(item_.compareTo(location->item)){
	  case GREATER:
	    preLoc = location;
	    location = location->next;
	    break;
	case EQUAL:
	  cout << "\nError: Duplication\n";
	  return;
	case LESS:
	  brake = 1;
	  break;
	} // switch
      } // while
      
	    //item goes to end
	    if(location->next == NULL){
	      newNode = new ListNode;
	      newNode->item = item_;
	      location->next = newNode;
	      location = location->next;
	      location->next = NULL;
	      length++;
	      return;
	    } else{
	      //Goes in between
	      newNode = new ListNode;
	      newNode->item = item_;
	      newNode->next = location;
	      preLoc->next = newNode;
	      length++;
	      return;
	    } // else
} // insertItem

void SortedLinkedList::deleteItem(ItemType item_){
  
  ListNode *location = head;
  ListNode *preLocation = NULL;
  int brake = 0;
  
  //Empty List
  if(head == NULL){
    cout << "\nError: Empty List\n";
   return;
  } // if

  // Delete at index 0
  if(item_.compareTo(location->item) == EQUAL){
      head = location->next;
      delete location;
      length--;
      return;
  } // if
  
  //General Case
      while(location->next != NULL && brake == 0){
        switch(item_.compareTo(location->item)){
          case GREATER:
            preLocation = location;
            location = location->next;
            break;
        case EQUAL:
	  brake = 1;
          break;
	case LESS:
          cout << "\nError: Item Not Found\n";
	  return;
        } // switch
      } // while
      
            // Delete Last Index
            if(location->next == NULL){
	      preLocation->next = NULL;
	      delete location;
              length--;
              return;
            } else{
              // Delete in between
	      preLocation->next = location->next;
	      delete location;
              length--;
              return;
            } // else   
} // deleteItem   

int SortedLinkedList:: searchItem(ItemType &item_){
  int index = 0;
  ListNode *location = head;
  bool moreToSearch = (location != NULL);

  while(moreToSearch){
    switch(item_.compareTo(location->item)){
    case GREATER:
      location = location->next;
      moreToSearch = (location != NULL);
      index++;
      break;
    case EQUAL: moreToSearch = false;
      break;
    case LESS: moreToSearch = false;
      index = -1;
      cout << "\nItem Not Found" << endl;
      break;
    } // switch
  } // while
  return index;
} // searchItem

ItemType SortedLinkedList::GetNextItem(){
    if(currentPos == NULL){
    currentPos = head;
  } else{
    currentPos = currentPos->next;
  } // else
  return (currentPos)->item;
} // GetNextItem

void SortedLinkedList::ResetList(){
  currentPos = NULL;
} // ResetList

int SortedLinkedList::getLength() const{
  return length;
} // length

void SortedLinkedList::reverse(){
  ListNode *location = head;
  ListNode *sucLocation = NULL;
  ListNode *predLocation = NULL;
  bool moreToSearch = (location != NULL);

  while(moreToSearch){
    sucLocation = location->next;
    location->next = predLocation;
    predLocation = location;
    location = sucLocation;
    moreToSearch = (location != NULL);
  } // while
  head = predLocation;
} // reverse

void SortedLinkedList::printList(){
  ListNode *location = head;
  cout << "\n* ";
  while(location != NULL){
    cout << (location->item).getValue() << " -> ";
    location = location->next;
    } // while
  cout << " ||\n";
} // printList

void SortedLinkedList::printHelp(){
  cout << "\ni - Insert Value\n";
  cout << "\nd - Delete Value\n";
  cout << "\ns - Search Value\n";
  cout << "\nn - Print  Next Value\n";
  cout << "\nr - Reset  Iterator\n";
  cout << "\np - Print  List\n";
  cout << "\nl - Print  Length\n";
  cout << "\nb - Reverse\n";
  cout << "\nq - QUIT\n";
} // printHelp
