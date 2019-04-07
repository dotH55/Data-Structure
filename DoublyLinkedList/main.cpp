#include <fstream>
#include <iostream>
#include <stdlib.h>

#include "ItemType.h"
#include "DoublyLinkedList.h"

using namespace std;

const char INSERT = 'i';
const char DELETE = 'd';
const char PRINT = 'p';
const char LENGTH = 'l';
const char HELP = 'h';
const char QUIT = 'q';

int main(int argc, char** argv){

  //Check number of arguments  
  if(argc == 1 && argc > 2){
    cout << "\nUsage: ./main <fileName>\n";
    exit(0);
  } // if
  
  DoublyLinkedList list;
  ItemType item;
  int data;
  char input;
  int entry;

  ifstream inFile(argv[1], ios::in);

  // Checking File Existance  
  if(!inFile.is_open()){
    cerr << "\nError: File" << endl;
    exit(0);
  } // if

  // Insert
  inFile >> data;
  while(!inFile.eof()){
    item.initialize(data);
    list.insertItem(item);
    inFile >> data;
  } // while

  list.help();
  cout << "\n\n $. ";
  cin >> input;
  while(input){

    switch(input){
    case INSERT:
      cout << "Value: ";
      cin >> entry;
      item.initialize(entry);
      list.insertItem(item);
      list.print();
      break;

    case DELETE:
      cout << "Value: ";
      cin >> entry;
      item.initialize(entry);
      list.deleteItem(item);
      list.print();
      break;

    case PRINT:
      list.print();
      break;

    case LENGTH:
      cout << "\nLength: " << list.lengthIs() << endl;
      break;

    case HELP:
      list.help();
      break;

    case QUIT:
      cout << "\nBye...\n";
      exit(0);
      break;
      
    default:
      cerr << "\nInvalid Input\n";
      list.help();
      break;
    } // switch
    
    cout << "\n $. ";
    cin >> input;
  } // while
} // main
