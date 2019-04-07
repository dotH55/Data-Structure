#include <iostream>
#include <cstddef>
 
#include "CircularLinkedList.h"
#include "ItemType.h"
#include "NodeType.h"

using namespace std;

// Constructor
CircularLinkedList::CircularLinkedList(){
  length = 0;
  head = NULL;
} // CircularLinkedList                                                                                                                                                                                       

//Destructor
CircularLinkedList::~CircularLinkedList(){
  NodeType *location = head;
  NodeType *tempLocation;
  int i = 0;
  while(i < lengthIs()){
    tempLocation = location;
    location = location->next;
    delete tempLocation;
    i++;
  } // while
} // ~CircularLinkedList

void CircularLinkedList::insertItem(ItemType &item_){
  NodeType *location = head;
  NodeType *preLoc = NULL;
  NodeType *newNode = new NodeType;
  int brake = 0;
  newNode->data = item_;

  // Empty List
  if(location == NULL){
    head = newNode;
    head->next = head;
  } // if
  
  //Insert at length = 0
  else if(item_.compareTo(location->data) == LESS){
      preLoc = location;
      do{
	preLoc = preLoc->next;
      } while(preLoc->next != location);
      newNode->next = head;
      preLoc->next = newNode;
      head = newNode;
  } // else if

  //General Case
  else{
      while(location->next != head && brake == 0){
	switch(item_.compareTo(location->data)){
	case GREATER:
	  preLoc = location;
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

      // Check Location
      if(item_.compareTo(location->data) == LESS){
	preLoc->next = newNode;
	newNode->next = location;
      } else if(item_.compareTo(location->data) == EQUAL){
	cout << "\nError: Duplication\n";
	delete newNode;
	return;
      }else{
	//item goes to end
	if(location->next == head){
	  location->next = newNode;
	  newNode->next = head;
	} else{
	  //Goes in between
	  newNode->next = location;
	  preLoc->next = newNode;
	} // else
      } // else
  } // else
  length++;
  return;
} // insertItem

void CircularLinkedList::deleteItem(ItemType &item_){
  NodeType *location = head;
  NodeType *preLoc = NULL;
  int brake = 0;

  // Empty List
  if(head == NULL){
    cout << "\nError: Empty List";
   return;
  } // if

  // Delete First Item
  else if(item_.compareTo(location->data) == EQUAL){
    if(location->next == head){
      head = NULL;
    }else{
      //Find Tail
      preLoc = location;
      head = location->next;
      do{
	preLoc = preLoc->next;
	} while(preLoc->next != head);
      preLoc->next = head;
    } // else
  } // if
  
  //General Case
  else{
      do{
        switch(item_.compareTo(location->data)){
	case GREATER:
            preLoc = location;
            location = location->next;
            break;
	case EQUAL:
	  preLoc->next = location->next;
	  delete location;
	  //length--;
	  //return;
	  brake = 1;
          break;
        case LESS:
          cout << "\nError: Item Not Found";
	  return;
        } // switch                                               
      } while(location->next != head && brake == 0);
  } // else
  
  if(lengthIs() == 0){
    cout << "\nCaution: Empty List";
    head = NULL;
  } // if
  currentPos = head;
  delete location;
  length--;
  return;
} // deleteItem

int CircularLinkedList::lengthIs() const{
  return length;
} // lengthIs

void CircularLinkedList::print(){
  NodeType *location = head;
  int i = 0;
  cout << "\n-> ";
  while(i < lengthIs()){
    cout << (location->data).getValue() << " -> ";
    location = location->next;
    i++;
    } // while
  cout << "\n";
} //print

void CircularLinkedList::next(){
  if(currentPos != NULL){
    cout << "\n-> " << currentPos->data.getValue() << " ->";
    currentPos = currentPos->next;
  } // if
} // next

void CircularLinkedList::helpFirst(){
  currentPos = head;
  help();
} // helpFirst

void CircularLinkedList::help(){
  cout << "\n\ni - Insert";
  cout << "\nd - Delete";
  cout << "\nl - Length";
  cout << "\np - Print";
  cout << "\nq - Quit";
} // help
