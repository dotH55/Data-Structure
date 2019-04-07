#include <iostream>
#include <iomanip>
#include <cstddef>

#include "DoublyLinkedList.h"
#include "ItemType.h"
#include "NodeType.h"

using namespace std;

// Constructor
DoublyLinkedList::DoublyLinkedList(){
  head = NULL;
  tail = NULL;
} // DoublyLinkedList                                                                                                                                                                                       

//Destructor
DoublyLinkedList::~DoublyLinkedList(){
  NodeType *location = head;
  NodeType *tempLocation;
  while(location != NULL){
    tempLocation = location;
    location = location->next;
    delete tempLocation;
  } // while
} // ~DoublyLinkedList

void DoublyLinkedList::insertItem(ItemType &item_){
  NodeType *location = head;
  NodeType *newNode = new NodeType;
  int brake = 0;
  newNode->data = item_;

  // Empty List                                                     
  if(location == NULL){
    head = newNode;
    head->next = NULL;
    head->back = NULL;
   return;
  } // if                                                                     

  else if(item_.compareTo(location->data) == EQUAL){
      cout << "\n*Error: Duplication\n" << endl;
      delete newNode;
      return;
  } // else if
  
  //Insert at length = 0                                                                                              
  else if(item_.compareTo(location->data) == LESS){
      newNode->back = NULL;
      newNode->next = location;
      newNode->next->back = newNode;
      head = newNode;
      return;
  } // else if                                                                        

  else{
  //General Case
    //Find Location
      while(location->next != NULL && brake == 0){
        switch(item_.compareTo(location->data)){
          case GREATER:
            location = location->next;
            break;
        case EQUAL:
          cout << "\nError: Duplication\n";
	  delete newNode;
          return;
        case LESS:
          brake = 1;
          break;
        } // switch                                                                                     
      } // while

      if(item_.compareTo(location->data) == LESS){
	newNode->back = location->back;
	newNode->back->next = newNode;
	newNode->next = location;
	newNode->next->back = newNode;
      } else if(item_.compareTo(location->data) == EQUAL){
	cout << "\n*Error: Duplicate";
	return;
      } else{
	//item goes to end
	if(location->next == NULL){
	  newNode->back = location;
	  newNode->back->next = newNode;
	  newNode->next = NULL;
	  tail = newNode;
	  return;
	} else{
	  //Goes in between
	  newNode->next = location->next;
	  newNode->next->back = newNode;
	  newNode->back = location;
	  newNode->back->next = newNode;
	  return;
	} // else
      } // else
  } // else
} // insertItem

void DoublyLinkedList::deleteItem(ItemType &item_){
  NodeType *location = head;
  int brake = 0;

  // Empty List                                                   
  if(location == NULL){
    cout << "\n*Error: Empty List";
  } // if

  // Delete Head
  else if(item_.compareTo(location->data) == EQUAL){
    head = location->next;
    head->back = NULL;
    head->next->back = head;
    delete location;
  } // else if
  
  else{
    // General Case
    // Find Location
    while(location->next != NULL && brake == 0){
      switch(item_.compareTo(location->data)){
      case GREATER:
	location = location->next;
	break;
      case EQUAL:
	brake = 1;
	break;
      case LESS:
	cout << "\nError: Item Not Found";
	return;
      } // switch
    } // while

    if(item_.compareTo(location->data) == EQUAL){
      // Delete Tail
      if(location->next == NULL){
	tail = location->back;
	tail->next = NULL;
	delete location;
      } else{
	// Delete in between
	location->back->next = location->next;
	location->next->back = location->back;
	delete location;
      } // else
      } else{
	cout << "\n*Error: Item Not Found";
      } // else
  } // else
  return;
} // delete

int DoublyLinkedList::lengthIs() const{
  NodeType *location = head;
  int length = 0;
  while(location->next != NULL){
    length++;
      } // while
  return length;
} // lengthIs

void DoublyLinkedList::print(){
  NodeType *location = head;
  if(location != NULL){
    while(location != NULL){
      if(location->back == NULL){
	cout << "\nNULL";
      }else{
	cout << "\n" << setw(4) << location->back->data.getValue();
      } // else
      cout << ' ' << setprecision(0) << setw(5) << " <-[" << setw(3) << location->data.getValue() << "]-> ";
      if(location->next == NULL){
	cout << setw(5) << "NULL";
      } else{
	cout << ' ' << setprecision(0) << setw(4) << location->next->data.getValue();
      } // else
      location = location->next;
    } // while
  } // if
  else{
    cout << "\nCaution: Empty List";
  } // else
} //print

void DoublyLinkedList::help(){
  cout << "\n\ni - Insert";
  cout << "\nd - Delete";
  cout << "\np - Print";
  cout << "\nq - Quit";
} // help
