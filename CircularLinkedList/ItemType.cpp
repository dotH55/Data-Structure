#include <iostream>
#include <string>

#include "ItemType.h"

using namespace std;

ItemType::ItemType(){
} // ItemType

void ItemType::initialize(int num){
    value = num;
} // initialize 

Comparison ItemType::compareTo(ItemType item_){
  if(getValue() < item_.getValue()){
    return LESS;
  } else if(getValue() > item_.getValue()){
    return GREATER;
  } else if(getValue() == item_.getValue()){
    return EQUAL;
  } // else                                                                                                                                                                                                 
} // ItemType                                                                                                                                                                                               
int ItemType::getValue() const{
  return value;
} // getValue                                                                                                                                                              
