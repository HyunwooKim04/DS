//
//  ItemType1.hpp
//  UnsortedList1.cpp
//
//  Created by 김현우 on 1/5/25.
//

#ifndef ItemType1_hpp
#define ItemType1_hpp

#include <stdio.h>
const int MAX_ITEM = 5;
enum RelationType {LESS, EQUAL, GREATER};

class ItemType {
public:
    RelationType ComparedTo(const ItemType& otherItem) const;
    void Print() const;
    void Initialize();
private:
    int value;
};
#endif /* ItemType1_hpp */
