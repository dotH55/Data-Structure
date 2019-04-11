#include <iostream>
#include <string>

#include "BinaryTree.h"
#include "ItemType.h"
#include "Node.h"

using namespace std;

//Constructor
BinaryTree::BinaryTree(){
  root = NULL;
  length = 0;
} // BinaryTree

// Helper Method
void destroy(Node*& tree){
  if(tree != NULL){
    destroy(tree->left);
    destroy(tree->right);
    delete tree;
  } // if
} // destroy

BinaryTree::~BinaryTree(){
  destroy(root);
} // ~BInaryTree

// Helper Method
void insertItem(Node*& tree, ItemType& item){
  if(tree == NULL){
    tree = new Node;
    tree->right = NULL;
    tree->left = NULL;
    tree->key = item;
  } else if(item < tree->key){
    insertItem(tree->left, item);
  } else{
    insertItem(tree->right, item);
  } // else
} // InsertItem

// Helper Method
void getItem(Node* tree, ItemType& item, bool& found){
  if(tree == NULL){
    found = false;
  } else if(item < tree->key){
    getItem(tree->left, item, found);
  } else if(item > tree->key){
    getItem(tree->right, item, found);
  } else{
    item = tree->key;
    found = true;
  } // else
} // GetItem

// This methods call InsertItem(): recursive helper method
void BinaryTree::insert(ItemType &item){
  bool found;
  getItem(root, item, found);
  if(!found){
    insertItem(root, item);
    length++;
  } else{
    cout << "\n**Error: Duplicate\n"; 
  } // else
} // insert

// This helper method returns the right most node or predecessor
void getPredecessor(Node* tree, ItemType& data){
 while(tree->right != NULL){
    tree = tree->right;
  } // while
  data = tree->key;
} // getPredecessor

// This helper method deletes nodes
void BinaryTree::deleteNode(Node*& tree){
  ItemType data;
  Node* tempPtr = tree;
  if(tree->left == NULL){
    tree = tree->right;
    delete tempPtr;
  } else if(tree->right == NULL){
    tree = tree->left;
    delete tempPtr;
  } else{
    getPredecessor(tree->left, data);
    tree->key = data;
    Delete(tree->left, data);
  } // else
} // DeleteNode

// Helper Method
void BinaryTree::Delete(Node*& tree, ItemType item){
  if(item < tree->key){
    Delete(tree->left, item);
  } else if(item > tree->key){
    Delete(tree->right, item);
  } else{
    deleteNode(tree);
  } // else
} // Delete

void BinaryTree::deleteItem(ItemType& item){
  bool found;
  getItem(root, item, found);
  if(found){
    Delete(root, item);
    length--;
  } else{
    cout << "\n**Error: Item Not Found\n"; 
  } // else
} // delete

void BinaryTree::retrieve(ItemType &item, bool &found) const{
  getItem(root, item, found);
} // retrieve

void preOrderPrint(Node* tree){
  if(tree != NULL){
    cout << tree->key << "  \n";
    preOrderPrint(tree->left);
    preOrderPrint(tree->right);
  } // if
} // PrintPreOrder
void BinaryTree:: preOrder() const{
  preOrderPrint(root);
} // preOrder

// Helper Method
void inOrderPrint(Node* tree){
  if(tree != NULL){
    inOrderPrint(tree->left);
    cout << tree->key << "  \n";
    inOrderPrint(tree->right);
  } // if
} // printInOrder
void BinaryTree:: inOrder() const{
  inOrderPrint(root);
} // inOrder

// Helper Method
void postOrderPrint(Node* tree){
  if(tree != NULL){
    postOrderPrint(tree->left);
    postOrderPrint(tree->right);
    cout << tree->key << "  \n";
  } // if
} // PrintPreOrder

// Helper Method
void printTree(Node* tree, int space) {
  // Base case
  if(tree == NULL){
    return;
  } // if
  //Process right child first
  space += 10;
  printTree(tree->right, space);
  // Print current node
  cout << endl;
  for(int i = 10; i < space; i++){
    cout << " ";
  } // for
  cout << tree->key << "\n";
  // Print left child
  printTree(tree->left, space);
} // printTree

void BinaryTree::print() const{
  printTree(root, 0);
} // print

void BinaryTree:: postOrder() const{
  postOrderPrint(root);
} // postOrder

// Helper Method
void levels(Node* tree, ItemType& item, int index, int& level){
  // Base cases 
  if(tree == NULL || level){
    return;
  } // if
  if(tree->key.getValue() == item.getValue()){
    level = index;
  } // if
  // Recursive case
  levels(tree->left, item, index + 1, level);
  levels(tree->right, item, index + 1, level);
} // Level

// Helper Method
void printLevelNodes(Node* tree, ItemType& item, int level){
  // Base Case
  if(tree == NULL){
    return;
  } // if
  if(level == 1){

    if(tree->key.getValue() != item.getValue()){
      cout << tree->key << " ";
    } // if
    return;
  } // if
  // Recusive Case
  if(tree->left && tree->left->key.getValue() != item.getValue() && tree->right && tree->right->key.getValue() != item.getValue()){
    printLevelNodes(tree->left, item, level - 1);
    printLevelNodes(tree->right, item, level - 1);
  } // if
} // printLevelNodes

// Helper Method
void printCousins(Node* tree, ItemType& item){
  int level = 0;
  levels(tree, item, 1, level);
  printLevelNodes(tree, item, level);
} // printCousins

void BinaryTree::copyTree(Node*& copy, const Node* original){
    if(original == NULL){
      copy = NULL;
    } else{
      copy = new Node;
      copy->key	= original->key;
      copyTree(copy->left, original->left);
      copyTree(copy->right, original->right);
    } // else
} // copyTree

bool BinaryTree::isFull() const{
  try{
    Node* newNode = new Node;
    delete newNode;
    return false;
  } catch(std::bad_alloc exception){
    return true;
  } // catch
} // isFull

bool BinaryTree::isEmpty() const{
  return root == NULL;
} // isEmpty

int height(Node* tree){
  if(tree == NULL){
    return 0;
  } else{
    int leftHeight = height(tree->left);
    int rightHeight = height(tree->right);
    if(leftHeight > rightHeight){
      return leftHeight + 1;
    } else{
      return rightHeight + 1;
    } // else
  } // else
} // height

int BinaryTree::getHeight() const{
  return height(root);
} // getHeight

void BinaryTree::getSameLevelNonSiblings(ItemType& item){
  printCousins(root, item);
} // printAll cousins

void BinaryTree::printHelp() const{
  cout << "\ni - Insert";
  cout << "\nd - Delete";
  cout << "\nr - Retrieve";
  cout << "\ne - empty?";
  cout << "\nf - Full?";
  cout << "\nh - Height";
  cout << "\nl - Length";
  cout << "\nc - Cousins";
  cout << "\nt - Tree2D";
  cout << "\np - Pre-Order";
  cout << "\nn - In-Order";
  cout << "\no - PostOrder";
  cout << "\nH - Help";
  cout << "\nq - QUIT";
} // printHelp

int BinaryTree::getLength() const{
  return length;
} // 
