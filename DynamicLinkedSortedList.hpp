//
//  DynamicLinkedSortedList.hpp
//  SortedType
//
//  Created by 김현우 on 1/20/25.
//

#ifndef DynamicLinkedUnsortedList_hpp
#define DynamicLinkedUnsortedList_hpp
#include <iostream>

template <class ItemType>
struct NodeType {
    ItemType info;
    NodeType<ItemType>* next;
};

template <class ItemType>
class SortedList {
public:
    SortedList();
    ~SortedList();
    
    void MakeEmpty();
    bool IsFull() const;
    int LengthIs() const;
    void InsertItem(ItemType item);
    void DeleteItem(ItemType item);
    void RetrieveItem(ItemType& item, bool& found);
    void ResetList();
    void GetNextItem(ItemType& item);
    
private:
    NodeType<ItemType>* listData;
    int length;
    NodeType<ItemType>* currentPos;
};

template <class ItemType>
SortedList<ItemType>::SortedList() {
    listData = nullptr;
    length = 0;
    currentPos = nullptr;
}

template <class ItemType>
SortedList<ItemType>::~SortedList() {
    MakeEmpty();
}

template <class ItemType>
void SortedList<ItemType>::MakeEmpty() {
    NodeType<ItemType>* tempPtr;
    
    while(listData != nullptr) {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    
    length = 0;
    currentPos = nullptr;
}

template <class ItemType>
bool SortedList<ItemType>::IsFull() const {
    try {
        NodeType<ItemType>* temp = new NodeType<ItemType>;
        delete temp;
        return false;
    } catch (std::bad_alloc&) {
        return true;
    }
}

template <class ItemType>
void SortedList<ItemType>::InsertItem(ItemType item) {
    NodeType<ItemType>* newNode = new NodeType<ItemType>;
    newNode->info = item;
    newNode->next = nullptr;
    
    if(listData == nullptr || listData->info >= item) { // 리스트가 비어있는 경우
        newNode->next = listData;
        listData = newNode;
    } else {
        NodeType<ItemType>* prev = nullptr;
        NodeType<ItemType>* curr = listData;
        
        while (curr != nullptr && curr->info < item) {
            prev = curr;
            curr = curr->next;
        }
        
        newNode->next = curr;
        prev->next = newNode;
    }
    
    length++;
}

template <class ItemType>
void SortedList<ItemType>::DeleteItem(ItemType item) {
    NodeType<ItemType>* prev = nullptr;
    NodeType<ItemType>* curr = listData;
    
    while (curr != nullptr && curr->info != item) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr == nullptr) {
        std::cout << "no item\n";
    } else {
        prev->next = curr->next;
        delete curr;
        length--;
    }
    
}

template <class ItemType>
void SortedList<ItemType>::RetrieveItem(ItemType& item, bool& found) {
    NodeType<ItemType>* curr = listData;
    found = false;
    
    while (curr != nullptr && !found) {
        if (curr->info == item) {
            found = true;
            item = curr->info;
        } else if (curr->info > item) {
            return;
        }
        
        curr = curr->next;
    }
}

template <class ItemType>
void SortedList<ItemType>::ResetList() {
    currentPos = nullptr;
}

template <class ItemType>
void SortedList<ItemType>::GetNextItem(ItemType& item) {
    if (currentPos == nullptr) {
        currentPos = listData;
    } else {
        currentPos = currentPos->next;
    }
    
    if (currentPos != nullptr) {
        item = currentPos->info;
    }
}
#endif /* DynamicLinkedSortedList_hpp */
