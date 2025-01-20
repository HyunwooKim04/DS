#include <iostream>

template<class ItemType>
struct Node {
    ItemType info;
    Node<ItemType>* next;
};

template<class ItemType>
class StackType {
public:
    StackType();
    
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    void Push(ItemType item);
    void Pop(ItemType& item);
    ~StackType();
    
private:
    Node<ItemType>* topPtr;
};

template<class ItemType>
StackType<ItemType>::StackType() {
    topPtr = NULL;
}

template<class ItemType>
bool StackType<ItemType>::IsEmpty() const {
    return topPtr == NULL;
}

template<class ItemType>
void StackType<ItemType>::Push(ItemType newItem) {
    if(IsFull())
        return;
    Node<ItemType>* location;
    location = new Node<ItemType>;
    location->info = newItem;
    location->next = topPtr;
    topPtr = location;
}

template<class ItemType>
void StackType<ItemType>::Pop(ItemType& item) {
    if(IsEmpty())
        return;
    Node<ItemType>* tempPtr;
    item = topPtr->info;
    tempPtr = topPtr;
    topPtr = topPtr->next;
    delete tempPtr;
}

template<class ItemType>
bool StackType<ItemType>::IsFull() const {
    Node<ItemType>* location;
    try {
        location = new Node<ItemType>;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception) {
        return true;
    }
}

template<class ItemType>
void StackType<ItemType>::MakeEmpty() {
    Node<ItemType>* tempPtr;
    while(topPtr == NULL) {
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
}

template<class ItemType>
StackType<ItemType>::~StackType() {
    MakeEmpty();
}

