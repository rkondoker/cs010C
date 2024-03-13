#include "IntList.h"
#include <iostream>

using namespace std;

IntList::IntList(){
    IntNode* head = new IntNode(0);
    IntNode* tail = new IntNode(0);
    dummyHead = head;
    dummyTail = tail;
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;

}

IntList::~IntList(){
    while(!empty()){
        pop_back();
    }
}


void IntList::push_front(int value){
    IntNode* newNode = new IntNode(value);
    if(empty()){
        dummyHead->next = newNode;
        newNode->next= dummyTail;
        newNode->prev = dummyHead;
        dummyTail->prev = newNode;
    }
    else {
         IntNode* tempNode = dummyHead->next;
         dummyHead->next = newNode;
         newNode->next = tempNode;
         tempNode->prev = newNode;
         newNode->prev = dummyHead;
    }
}

void IntList::pop_front(){
    if(empty()){
        return;
    }
    else {
        IntNode* temp = dummyHead->next;
        dummyHead->next = temp->next;
        temp->next->prev = dummyHead;
        delete temp;
    }

}

void IntList::push_back(int value){
    IntNode* newNode = new IntNode(value);
    if(empty()){
        dummyHead->next = newNode;
        newNode->next= dummyTail;
        newNode->prev = dummyHead;
        dummyTail->prev = newNode;
    }
    else {
        IntNode* temp = dummyTail->prev;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = dummyTail;
        dummyTail->prev = newNode;
    }
}

void IntList::pop_back(){
    if (empty()) return;
    IntNode* temp = dummyTail->prev;
    temp->prev->next = dummyTail;
    dummyTail->prev = temp->prev;
    delete temp;
}

bool IntList::empty() const{
    if (dummyHead->next == dummyTail) return true;
    return false;
}

ostream & operator<<(ostream& out, const IntList& rhs){
    if (rhs.dummyHead->next == rhs.dummyTail) return out;

    IntNode* curr = rhs.dummyHead->next;
    while (curr->next != rhs.dummyTail){
        out << curr->data << ' ';
        curr = curr->next;
    }
    out << curr->data;
    return out;
}

void IntList::printReverse() const{
    if (empty()) {
        return;
    }
    IntNode* curr = dummyTail->prev;
    while (curr != dummyHead){
        cout << curr->data << ' ';
        curr = curr->prev;
    }
    
}
