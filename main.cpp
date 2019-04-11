#include <fstream>
#include <iostream>
#include <string>

#include "Node.h"
#include "ItemType.h"
#include "BinaryTree.h"


using namespace std;

const char INSERT = 'i';
const char DELETE = 'd';
const char RETRIEVE = 'r';
const char IS_FULL = 'f';
const char IS_EMPTY = 'e';
const char IN_ORDER = 'n';
const char POST_ORDER = 'o';
const char PRE_ORDER = 'p';
const char COUSINS = 'c';
const char PRINT_TREE = 't';
const char GET_HEIGHT = 'h';
const char LENGTH = 'l';
const char HELP = 'H';
const char QUIT = 'q';


int main(int argc, char ** argv){

  //Check number of arguments
  if(argc == 1 && argc > 2){
    cout << "\nUsage: ./main <fileName>\n";
    exit(0);
  } // if
  
  ItemType item;
  BinaryTree tree;
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
    item = ItemType(data);
    tree.insert(item);
    inFile >> data;
  } // while

  tree.printHelp();
  cout << "\n $. ";
  cin >> input;
  while(input){

    switch(input){
    case INSERT:
      cout << "Value: ";
      cin >> entry;
      item = ItemType(entry);
      tree.insert(item);
      break;
      
    case DELETE:
      cout << "Value: ";
      cin >> entry;
      item = ItemType(entry);
      tree.deleteItem(item);
      break;
      
    case RETRIEVE:
      cout << "Value: ";
      cin >> entry;
      item = ItemType(entry);
      bool found;
      found = false;
      tree.retrieve(item, found);
      cout << "Item Found: ";
      if(found){
        cout << "True";
      } else{
        cout << "False";
      } // else
      break;

    case IS_FULL:
      cout << "Is Full: ";
      if(tree.isFull() == 1){
	cout << "True";
      } else{
	cout << "False";
      } // else
      break;

    case IS_EMPTY:
      cout << "Is Empty: ";
      if(tree.isEmpty() == 1){
        cout <<	"True";
      } else{
	cout <<	"False";
      }	// else 
      break;
      
    case PRE_ORDER:
      tree.preOrder();
      break;
      
    case IN_ORDER:
      tree.inOrder();
      break;
      
    case POST_ORDER:
      tree.postOrder();
      break;

    case PRINT_TREE:
      tree.print();
      break;

    case GET_HEIGHT:
      tree.getHeight();
      break;
      
    case LENGTH:
      cout << "\nLength: " << tree.getLength() << endl;
      break;

    case COUSINS:
      cout << "\nNode: ";
      cin >> entry;
      item = ItemType(entry);
      tree.getSameLevelNonSiblings(item);
      break;
      
    case HELP:
      tree.printHelp();
      break;
      
    case QUIT:
      cout << "\nBye...\n";
      exit(0);
      break;
      
    default:
      cerr << "\nInvalid Input\n";
      tree.printHelp();
      break;
    } // switch
    
    cout << "\n $. ";
    cin >> input;
    } // while
  
} // main

