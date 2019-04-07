#include <fstream>
#include <iostream>

#include "ItemType.h"
#include "SortedLinkedList.h"

using namespace std;

const char INSERT = 'i';
const char DELETE = 'd';
const char SEARCH = 's';
const char ITR_NEXT = 'n';
const char RESET_ITR = 'r';
const char PRINT_ALL = 'p';
const char LENGTH = 'l';
const char REVERSE = 'b';
const char HELP = 'h';
const char QUIT = 'q';

SortedLinkedList list;

int main(int argc, char** argv){

  //Check number of arguments
  if(argc == 1 && argc > 2){
    cout << "\nUsage: ./main <fileName>\n";
    exit(0);
  } // if

  SortedLinkedList list;
  ItemType item;
  int data;
  char input;
  int entry;

  ifstream inFile(argv[1], ios::in);

  // Checking File Existance
  if(!inFile.is_open()){
    cerr << "\nCan't Open File" << endl;
    exit(0);
  } // if

  inFile >> data;  
  while(!inFile.eof()){
    item.initialize(data);
    list.insertItem(item);
    inFile >> data;
  } // while

  list.ResetList();
  cout << "\ni - Insert Value";
  cout << "\nd - Delete Value";
  cout << "\ns - Search Value";
  cout << "\nn - Print  Next Value";
  cout << "\nr - Reset  Iterator";
  cout << "\np - Print  List";
  cout << "\nl - Print  Length";
  cout << "\nb - Reverse";
  cout << "\nq - QUIT";
  
  cout << "\n $. ";
  cin >> input;
  while(input){

    switch(input){
    case INSERT:
      cout << "Value: ";
      cin >> entry;
      item.initialize(entry);
      list.insertItem(item);
      list.printList();
      break;
      
    case DELETE:
      cout << "Value: ";
      cin >> entry;
      item.initialize(entry);
      list.deleteItem(item);
      list.printList();
      break;
      
    case SEARCH:
      cout << "Value: ";
      cin >> entry;
      item.initialize(entry);
      cout << "Index: " << list.searchItem(item) << endl;
      break;
      
    case ITR_NEXT:
      cout << "Value: " << (list.GetNextItem()).getValue() << endl;
      break;
      
    case RESET_ITR:
      list.ResetList();
      cout << "ITR Reseted\n";
      break;
      
    case PRINT_ALL:
      list.printList();
      break;
      
    case LENGTH:
      cout << "\nLength: " << list.getLength() << endl;
      break;
      
    case REVERSE:
      list.reverse();
      list.printList();
      break;

    case HELP:
      list.printHelp();
      break;
      
    case QUIT:
      cout << "\nBye...\n";
      exit(0);
      break;
      
    default:
      cerr << "\nInvalid Input\n";
      list.printHelp();
      break;
    } // switch
    
    cout << "\n $. ";
    cin >> input;
  } // while
  
} // main

