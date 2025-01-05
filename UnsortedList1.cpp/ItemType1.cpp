//
//  ItemType1.cpp
//  UnsortedList1.cpp
//
//  Created by 김현우 on 1/5/25.
//

#include "ItemType1.hpp"
#include <iostream>

RelationType ItemType::ComparedTo(const ItemType& otherItem) const {
    if(value < otherItem.value) return LESS;
    else if(value > otherItem.value) return GREATER;
    else return EQUAL;
}

void ItemType::Print() const {
    std::cout << value << '\n';
}

void ItemType::Initialize() {
    int number;
    std::cin >> number;
    value = number;
}
