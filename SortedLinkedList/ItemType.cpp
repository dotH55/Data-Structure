#include <iostream>
#include <string>

#include "ItemType.h"

using namespace std;

ItemType::ItemType(){
} // ItemType

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

void ItemType::initialize(int num){
    value = num;
} // initialize

