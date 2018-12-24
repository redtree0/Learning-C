//
//  main.cpp
//  LinkedLists
//
//  Created by 김천규 on 24/12/2018.
//  Copyright © 2018 김천규. All rights reserved.
//

#include <iostream>
#define EMPTY -1

using namespace std;

class rnode {
public:
    
    int item;
    rnode *next;
    rnode();
//    ~rnode() {
//        cout << "delete " << item << endl;
//    }
    rnode(int value);
    
};

rnode::rnode() {
    next = NULL;
}

rnode::rnode(int value) {
    item = value;
    next = NULL;
}

class rLinkedLists {
        rnode *head = new rnode();
        rnode *tail = new rnode();
    
        int size = 0;
    public :
        rLinkedLists();
        int GetSize();
        bool IsEmpty();
        void PushFront(int value);
        void PushBack(int value);
        int PopFront();
        int PopBack();
        int Front();
        int Back();
        void Print();
        int ValueAt(int index);
    
};

rLinkedLists::rLinkedLists() {
    head->next = NULL;
    tail->next = NULL;
}

bool rLinkedLists::IsEmpty() {
    return size > 0 ? true : false;
}

void rLinkedLists::PushFront(int value) {
    rnode *node = new rnode(value);
    size++;
    
    if( head->next == NULL) {
        head->next = node;
        return;
    }
    
//    node->next = head;
    node->next = head->next;
    head->next = NULL;
    
    head->next = node;
}


void rLinkedLists::PushBack(int value) {
    rnode *node = new rnode(value);
    
    size++;
    if( head->next == NULL) {
        head->next = node;
        return;
    }
    
    rnode *tmp = head;
    while( ( tmp != NULL ) ) {
        if ( tmp->next == NULL ) {
            tmp->next = node;
            tail->next = node;
            break;
        }
        tmp = tmp->next;
    }
    
}

int rLinkedLists::PopFront() {
    
    if (!IsEmpty()) {
        return -1;
    }
    rnode *pop_node = head->next;
    delete pop_node;
    
    head->next = head->next->next;
    
    int value = pop_node->item;
    
    size--;
    
    return value;
}

int rLinkedLists::PopBack() {
    
    if (!IsEmpty()) {
        return -1;
    }
    
    rnode *tmp = head->next;
    while( ( tmp->next->next !=  NULL) ) {
        tmp = tmp->next;
    }
    rnode *pop_node = tmp->next;
    delete pop_node;
    
    tmp->next = NULL;
    
    int value = tmp->item;
    tail->next = tmp;
    
    size--;
    
    return value;
}

int rLinkedLists::Front() {
    
    if (!IsEmpty()) {
        return -1;
    }
    
    return head->next->item;
}

int rLinkedLists::Back(){
    
    if (!IsEmpty()) {
        return -1;
    }
    
    return tail->next->item;
}

void rLinkedLists::Print() {
    
    rnode *tmp = head->next;
    while( tmp != NULL ) {
        cout << tmp->item << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int rLinkedLists::ValueAt(int index) {
    rnode *tmp = head->next;
    
    for( int i=0 ; i<size ; i++ ) {
        
        if(i == index) {
            return tmp->item;
        }
        
        tmp = tmp->next;
    }
    
    return -1;
//    return
}


int main(int argc, const char * argv[]) {

    rLinkedLists *list = new rLinkedLists();
    
    list->PushBack(1);
    list->PushBack(2);
    list->PushBack(3);
    list->PushBack(4);
    list->Print();
    
    cout << list->PopBack() << endl;
    cout << list->Back() << endl;
    cout << list->Front() << endl;
    
    list->PushFront(5);
    list->Print();
    
    list->PopFront();
    list->Print();
    
    cout << list->ValueAt(2) << endl;
    list->Print();
    
    return 0;
}
