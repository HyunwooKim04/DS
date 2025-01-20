//
//  DynamicLinkedUnsortedList.hpp
//  UnsortedType
//
//  Created by 김현우 on 1/20/25.
//

#ifndef DynamicLinkedUnsortedList_hpp
#define DynamicLinkedUnsortedList_hpp

#include <stdio.h>

template<class ItemType>
struct NodeType {
    ItemType info;
    NodeType<ItemType>* next;
};

template<class ItemType>
class UnsortedType {
public:
    UnsortedType();
    ~UnsortedType();
    
    void MakeEmpty();
    bool IsFull() const;
    int LengthIs() const;
    void RetrieveItem(ItemType& item, bool& found);
    void InsertItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    void GetNextItem(ItemType& item);
    
private:
    NodeType<ItemType>* listData;
    int length;
    NodeType<ItemType>* currentPos;
};

template<class ItemType>
UnsortedType<ItemType>::UnsortedType() {
    length = 0;
    listData = NULL;
    currentPos = NULL;
}

template<class ItemType>
int UnsortedType<ItemType>::LengthIs() const {
    return length;
}

template<class ItemType>
bool UnsortedType<ItemType>::IsFull() const {
    try {
        NodeType<ItemType>* location = new NodeType<ItemType>;
        delete location;
        return false;
    } catch (std::bad_alloc&) {
        return true;
    }
}

template<class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType& item, bool& found) {
    NodeType<ItemType>* location = listData;
    found = false;
    
    while(location != NULL && !found) {
        if(item == location->info) {
            found = true;
            item = location->info;
        } 
        else {
            location = location->next;
        }
    }
}

template<class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item) {
    NodeType<ItemType>* location = new NodeType<ItemType>;
    location->info = item;
    location->next = listData;
    listData = location;
    length++;
}

template<class ItemType>
void UnsortedType<ItemType>::ResetList() {
    currentPos = NULL;
}

template<class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item) {
    NodeType<ItemType>* location = listData;
    NodeType<ItemType>* tempLocation;

    if (item == listData->info) {
        tempLocation = listData;
        listData = listData->next;
        delete tempLocation;
        length--;
    }
    else {
        while (location->next != NULL && location->next->info != item) {
            location = location->next;
        }

        if (location->next != NULL) {
            tempLocation = location->next;
            location->next = location->next->next;
            delete tempLocation;
            length--;
        }
    }
}

template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType& item) {
    if (currentPos == NULL) {
        currentPos = listData;
    } 
    else {
        currentPos = currentPos->next;
    }

    if (currentPos != NULL) {
        item = currentPos->info;  
    }
}
#endif /* DynamicLinkedUnsortedList_hpp */
