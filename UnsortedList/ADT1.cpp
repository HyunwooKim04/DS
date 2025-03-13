//
//  ADT1.cpp
//  UnsortedList1.cpp
//
//  Created by 김현우 on 1/5/25.
//

#include "ADT1.hpp"

ArrayList::ArrayList() {
    m_Length = 0;
    m_CurPointer = -1;
}

ArrayList::~ArrayList() {}

void ArrayList::MakeEmpty() {
    m_Length = 0;
    m_CurPointer = -1;
}

int ArrayList::GetLength() {
    return m_Length;
}

int ArrayList::IsFull() {
    return m_Length == MAXSIZE;
}

void ArrayList::Add(const ItemType& data) {
    if(IsFull()) std::cout << "Array is full now." << std::endl;
    else m_Array[m_Length++] = data;
}

void ArrayList::ResetList() {
    m_CurPointer = -1;
}

int ArrayList::GetNextItem(ItemType& data) {
    if(m_CurPointer == m_Length) {
        m_CurPointer = -1;
        return 0;
    }
    else {
        data = m_Array[++m_CurPointer];
        return 1;
    }
}

