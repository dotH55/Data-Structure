#include <iostream>
#include <string>

#include "ItemType.h"

using namespace std;

ItemType::ItemType(){
} // ItemType

ItemType::ItemType(int value_){
  value = value_;
} // ItemType

bool ItemType::operator<(const ItemType& item) const{
  return getValue() < item.getValue();
} // operator<

bool ItemType::operator>(const ItemType& item) const{
  return getValue() > item.getValue();
} // operator<

bool ItemType::operator==(const ItemType& item) const{
  return getValue() == item.getValue();
} // operator==

void ItemType::operator=(const ItemType& item){
  value = item.getValue();
} // operator=

ostream& operator<<(ostream& os, const ItemType &item ){
  os << item.getValue();
  return os;
} // operator=


Comparison ItemType::compareTo(ItemType item_){
  if(getValue() < item_.getValue()){
    return LESS;
  } else if(getValue() > item_.getValue()){
    return GREATER;
  } else{
    return EQUAL;
  } // else
} // ItemType

int ItemType::getValue() const{
  return value;
} // getValue

