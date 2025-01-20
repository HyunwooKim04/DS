//
//  Queue_LinkedStructure.hpp
//  QueueLinkedStructure
//
//  Created by 김현우 on 1/20/25.
//

#ifndef Queue_LinkedStructure_hpp
#define Queue_LinkedStructure_hpp

#include <cstdio>

template<class ItemType>
struct NodeType {
    ItemType info;
    NodeType<ItemType>* next;
};

template<class ItemType>
class QueType {
public:
    QueType();
    ~QueType();
    
    bool IsEmpty() const;
    void Enqueue(ItemType item);
    void Dequeue(ItemType& item);
    void MakeEmpty();
    
private:
    NodeType<ItemType>* qFront;
    NodeType<ItemType>* qRear;
};

template<class ItemType>
QueType<ItemType>::QueType() {
    qFront = NULL;
    qRear = NULL;
}

template<class ItemType>
bool QueType<ItemType>::IsEmpty() const {
    return qFront == NULL;
}

template<class ItemType>
void QueType<ItemType>::Enqueue(ItemType item) {
    NodeType<ItemType>* ptr;
    ptr = new NodeType<ItemType>;
    ptr->info = item;
    ptr->next = NULL;
    
    if(qFront == NULL) {
        qFront = ptr;
    } else {
        qRear->next = ptr;
    }
    qRear = ptr;
}

template<class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item) {
    NodeType<ItemType>* tempPtr;
    tempPtr = qFront;
    item = qFront->info;
    qFront = qFront->next;
    if(qFront == NULL) {
        qRear = NULL;
    }
    delete tempPtr;
}

template<class ItemType>
void QueType<ItemType>::MakeEmpty() {
    while(qFront != NULL) {
        NodeType<ItemType>* tempPtr;
        tempPtr = qFront;
        qFront = qFront->next;
        delete tempPtr;
    }
    qRear = NULL;
}

template<class ItemType>
QueType<ItemType>::~QueType() {
    this->MakeEmpty();
}
#endif /* Queue_LinkedStructure_hpp */
