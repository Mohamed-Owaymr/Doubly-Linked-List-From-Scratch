#pragma once
#include <iostream>
using namespace std;


template <typename Type>
class DoublyLinkedList {
public:
    class Node {
    private:
        Type data;
        Node* next;
        Node* previous;

    public:
        Type getData() const;
        void setData(Type data);

        Node* getNext() const;
        void setNext(Node* next);

        Node* getPrevious() const;
        void setPrevious(Node* previous);

        Node();
        Node(Type data);
    };
    
    

private:
    Node* head;
    size_t size;

private:
    void swapNextAndPrevious(Node* current);
    void validateIndex(size_t index) const;

public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList& other);

    Node* insertAtHead(Node* nodeToInsert);
    void insertAtHead(Type data);

    Node* insertAtTail(Node* nodeToInsert);
    void insertAtTail(Type data);

    void insertAfter(Node* currentNode , Node* nodeToInsert);
    void insertAfter(Node* currentNode , Type data);
    void insertAfter(size_t index , Type data);

    Node* find(Type data) const;

    Node* deleteHead();

    Node* deleteNode(Node* nodeToDelete);
    void deleteNode(Type data);

    void deleteAfter(Node* currentNode);
    void deleteAfter(Type data);

    Node* deleteTail(); 

    void clear();

    size_t getSize() const;

    bool empty() const;

    Node* reverse();

    Node* getNodeByIndex(size_t index) const;

    Type getItem(size_t index) const;

    void updateItem(size_t index , Type newValue);


    // for testing
    void display() {
        Node* current = head;
        while(current) {
            cout << current->getData();
            if(current->getNext()) {
                cout << " <-> ";
            }
            current = current->getNext();
        }
    }

};

// ----------------------------------------------- (Implementation Section) -----------------------------------------------

// Node Implementations
template <typename Type>
Type DoublyLinkedList<Type>::Node::getData() const{
    return data;
}

template <typename Type>
void DoublyLinkedList<Type>::Node::setData(Type data) {
    this->data = data;
}

template <typename Type>
typename DoublyLinkedList<Type>::Node* DoublyLinkedList<Type>::Node::getNext() const{
    return next;
}

template <typename Type>
void DoublyLinkedList<Type>::Node::setNext(Node* next) {
    this->next = next;
}

template <typename Type>
typename DoublyLinkedList<Type>::Node* DoublyLinkedList<Type>::Node::getPrevious() const{
    return previous;
}

template <typename Type>
void DoublyLinkedList<Type>::Node::setPrevious(Node* previous) {
    this->previous = previous;
}

template <typename Type>
DoublyLinkedList<Type>::Node::Node() : next(nullptr) , previous(nullptr) {}

template <typename Type>
DoublyLinkedList<Type>::Node::Node(Type data) : data(data) , next(nullptr) , previous(nullptr){}





// Doubly Linked List Implementation
template <typename Type>
DoublyLinkedList<Type>::DoublyLinkedList() : head(nullptr) , size(0) {}

template <typename Type>
DoublyLinkedList<Type>::DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr), size(0)  {
    Node* current = other.head;

    while (current) {
        Node* newNode = new Node(current->getData());
        insertAtTail(newNode);
        current = current->getNext();
    }
}

template <typename Type>
typename DoublyLinkedList<Type>::Node*  DoublyLinkedList<Type>::insertAtHead(Node* nodeToInsert) {
    if (!nodeToInsert) {
        return head; 
    } 

    nodeToInsert->setNext(head);     
    nodeToInsert->setPrevious(nullptr); 

    if (head) {                     
        head->setPrevious(nodeToInsert);
    }

    head = nodeToInsert;            
    ++size;                         
    return head;
}

template <typename Type>
void DoublyLinkedList<Type>::insertAtHead(Type data) {
    Node* nodeToInsert = new Node(data);
    insertAtHead(nodeToInsert);
}

template <typename Type>
typename DoublyLinkedList<Type>::Node* DoublyLinkedList<Type>::insertAtTail(Node* nodeToInsert) {
    if(!nodeToInsert) {
        return head;
    }

    if(!head) {
        return insertAtHead(nodeToInsert);
    }

    Node* currentTailNode = head;
    while (currentTailNode->getNext()) {
        currentTailNode = currentTailNode->getNext();
    }

    currentTailNode->setNext(nodeToInsert);
    nodeToInsert->setPrevious(currentTailNode);
    ++size;
    return head;
}

template <typename Type>
void DoublyLinkedList<Type>::insertAtTail(Type data) {
    Node* nodeToInsert = new Node(data);
    insertAtTail(nodeToInsert);
}

template <typename Type>
void DoublyLinkedList<Type>::insertAfter(Node* currentNode , Node* nodeToInsert) {
    if(!head || !currentNode || !nodeToInsert) return;

    Node* nodeAfter = currentNode->getNext();

    nodeToInsert->setNext(nodeAfter);
    nodeToInsert->setPrevious(currentNode);

    if(nodeAfter) {
        nodeAfter->setPrevious(nodeToInsert);
    }

    currentNode->setNext(nodeToInsert);
    ++size;
}


template <typename Type>
void DoublyLinkedList<Type>::insertAfter(Node* currentNode , Type data) {
    Node* nodeToInsert = new Node(data);
    insertAfter(currentNode , nodeToInsert);
}

template <typename Type>
void DoublyLinkedList<Type>::insertAfter(size_t index , Type data) {
    Node* nodeToInsertAfter = getNodeByIndex(index);
    insertAfter(nodeToInsertAfter , data);
}

template <typename Type>
typename DoublyLinkedList<Type>::Node* DoublyLinkedList<Type>::find(Type data) const {
    if(!head) {
        return nullptr;
    }

    Node* current = head;
    while (current) {
        if(current->getData() == data) {
            return current;
        }
        current = current->getNext();
    }

    return nullptr;
}

template <typename Type>
typename DoublyLinkedList<Type>::Node* DoublyLinkedList<Type>::deleteHead() {
    if(!head) {
        return head;
    }

    Node* nodeAfter = head->getNext();

    delete head;

    if(nodeAfter) {
        nodeAfter->setPrevious(nullptr);
    } 

    head = nodeAfter;
    --size;
    return head;
}

template <typename Type>
typename DoublyLinkedList<Type>::Node* DoublyLinkedList<Type>::deleteNode(Node* nodeToDelete) {
    if(!nodeToDelete || !head) {
        return head;
    }

    if(nodeToDelete == head) {
        return deleteHead();
    }

    Node* nodeAfter = nodeToDelete->getNext();
    Node* nodeBefore = nodeToDelete->getPrevious();

    if(nodeAfter) {
        nodeAfter->setPrevious(nodeBefore);
    } 

    if(nodeBefore) {
        nodeBefore->setNext(nodeAfter);
    }

    delete nodeToDelete;
    --size;
    return head;

}

template <typename Type>
void DoublyLinkedList<Type>::deleteNode(Type data) {
    Node* nodeToDelete = find(data);

    if(nodeToDelete) {
        deleteNode(nodeToDelete);
    }
}

template <typename Type>
void DoublyLinkedList<Type>::deleteAfter(Node* currentNode) {
    if(!head || !currentNode || !currentNode->getNext()) {
        return;
    }

    Node* nodeToDelete = currentNode->getNext();
    deleteNode(nodeToDelete);
}

template <typename Type>
void DoublyLinkedList<Type>::deleteAfter(Type data) {
    Node* currentNode = find(data);

    if (currentNode && currentNode->getNext()) {
        deleteAfter(currentNode);
    }
}

template <typename Type>
typename DoublyLinkedList<Type>::Node* DoublyLinkedList<Type>::deleteTail() {
    if(!head) {
        return head;
    }

    if(!head->getNext()) {
        return deleteHead();
    }

    Node* tailNodeToDelete = head;
    while (tailNodeToDelete->getNext()) {
        tailNodeToDelete = tailNodeToDelete->getNext();
    }
    
    return deleteNode(tailNodeToDelete);
}

template <typename Type>
size_t DoublyLinkedList<Type>::getSize() const{
    return size;
}

template <typename Type>
bool DoublyLinkedList<Type>::empty() const {
    return size == 0;
}

template <typename Type>
void DoublyLinkedList<Type>::clear() {
    while (!empty()) {
        deleteHead();
    }
}

template <typename Type>
void DoublyLinkedList<Type>::swapNextAndPrevious(Node* current) {
    if (!current) {
        return;
    }
    
    Node* previousTemporary = current->getPrevious();
    current->setPrevious(current->getNext());
    current->setNext(previousTemporary);
}

template <typename Type>
typename DoublyLinkedList<Type>::Node* DoublyLinkedList<Type>::reverse() {
    if (size <= 1)
        return head;

    Node* current = head;
    Node* previousTemporary = nullptr;

    while (current) {
        previousTemporary = current->getPrevious();
        swapNextAndPrevious(current);
        current = current->getPrevious();
    }

    if (previousTemporary)
        head = previousTemporary->getPrevious();

    return head;
}

template <typename Type>
void DoublyLinkedList<Type>::validateIndex(size_t index) const {
    if(empty()) {
        throw out_of_range("Cannot access element in an empty list");
    }

    if(index >= size) {
        throw out_of_range("Index is out of range");
    }
}

template <typename Type>
typename DoublyLinkedList<Type>::Node* DoublyLinkedList<Type>::getNodeByIndex(size_t index) const {
    validateIndex(index);

    size_t indexCounter = 0;
    Node* current = head;
    while (current) {
        if(index == indexCounter) {
            return current;
        }
        current = current->getNext();
        ++indexCounter;
    }

    throw logic_error("Unreachable code in getNodeByIndex()");
}

template <typename Type>
Type DoublyLinkedList<Type>::getItem(size_t index) const {
    Node* target = getNodeByIndex(index);
    return target->getData();
}

template <typename Type>
void DoublyLinkedList<Type>::updateItem(size_t index , Type newValue) {
    Node* target = getNodeByIndex(index);
    target->setData(newValue);
}