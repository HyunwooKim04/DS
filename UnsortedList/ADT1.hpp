//
//  ADT1.hpp
//  UnsortedList1.cpp
//
//  Created by 김현우 on 1/5/25.
//

#ifndef ADT1_hpp
#define ADT1_hpp

#include <stdio.h>
#include <fstream>
#include <iostream>
#include "ItemType1.hpp"
#define MAXSIZE 5

class ArrayList {
public:
    ArrayList();
    ~ArrayList();
    
    void MakeEmpty();
    int GetLength();
    int IsFull();
    void Add(const ItemType& data);
    void ResetList();
    int GetNextItem(ItemType& data);
    
private:
    ItemType m_Array[MAXSIZE];
    int m_Length;
    int m_CurPointer;
};
#endif /* ADT1_hpp */
