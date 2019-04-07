#include <iostream>
#include <string>

#ifndef ITEMTYPE_H
#define ITEMTYPE_H

using namespace std;

enum Comparison{LESS, EQUAL, GREATER};

class ItemType{

 public:
  ItemType();
  Comparison compareTo(ItemType);
  int getValue() const;
  void initialize(int);

 private:
  int value;
}; // ItemType

#endif

