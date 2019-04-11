#include <iostream>
#include <string>

#ifndef ITEMTYPE_H
#define ITEMTYPE_H

using namespace std;

enum Comparison{LESS, EQUAL, GREATER};

class ItemType{

 public:
  ItemType();
  ItemType(int value_);
  bool operator<(const ItemType& item) const;
  bool operator>(const ItemType& item) const;
  bool operator==(const ItemType& item) const;
  void operator=(const ItemType& item);
  friend ostream& operator<<(ostream& os, const ItemType& item);
  void operator<<(const ItemType& item) const;
  Comparison compareTo(ItemType);
  int getValue() const;

 private:
  int value;
}; // ItemType

#endif

