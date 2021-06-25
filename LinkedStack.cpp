//
// Created by Elizabeth Vana on 6/23/21.
//

#include "LinkedStack.h"
<ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr) {}

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack) {
    Node<ItemType>* origChainPtr = aStack.topPtr;

    if (origChainPtr == nullptr) {
        topPtr = nullptr;
    } else {
        topPtr = new Node<ItemType>();
        topPtr->setItem(origChainPtr->getItem());

        Node<ItemType>* newChainPtr = topPtr;

        origChainPtr = origChainPtr->getNext(); //advance original chain pointer

        while (origChainPtr != nullptr) {
            ItemType nextItem = origChainPtr->getItem(); //get next item from original chain
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
            newChainPtr->setNext(newNodePtr);
            newChainPtr = newChainPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        }

        newChainPtr->setNext(nullptr);
    }
}

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack() {
    while (!isEmpty()) { //pop until stack is empty
        pop();
    }
}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const{
    return topPtr == nullPtr;
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newEntry) {
    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry, topPtr);
    topPtr = newNodePtr;
    newNodePtr = nullptr;

    return true;
}

template<class ItemType>
bool LinkedStack<ItemType>::pop() {
    if (!isEmpty()) {
        //stack is not empty; delete top
        Node<ItemType>* nodeToDeletePtr = topPtr;
        topPtr = topPtr->getNext();

        //return deleted node to system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;

        return true;
    }

    return false;
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const{
    if (isEmpty()) {
        throw(PrecondViolatedExcep("peek() called with empty stack"));
    }

    return topPtr->getItem(); //stack is not empty; return top
}