//
//  main.cpp
//  Arrays
//
//  Created by 김천규 on 21/12/2018.
//  Copyright © 2018 김천규. All rights reserved.
//

#include <iostream>
using namespace std;

class rArrays {
    private:
        int size=0;
        int capacity=4;
        int *arr = new int[capacity];
        void resize(int capacity);
    public:
        int getSize();
        int getCapacity();
        bool isEmpty();
        void push(int);
        int pop();
    
        int at(int index);
        void insert(int index, int item);
        void prepend(int item);
        int find(int item);
        void remove(int index);
    
        void print();
        void checkCapacity();
};

void rArrays::resize(int capacity){
    int *tmp = new int[capacity];
    for(int i=0; i<capacity; i++){
        tmp[i] = arr[i];
    }
    delete [] arr;
    arr = tmp;
    delete [] tmp;
}

void rArrays::checkCapacity(){
    if(size == capacity){
        capacity *= 2;
        resize(capacity);
    }
}

int rArrays::getSize() {
    return size;
};

int rArrays::getCapacity() {
    return capacity;
};

bool rArrays::isEmpty() {
    return size == 0 ? true : false;
}

void rArrays::push(int data) {
    
    checkCapacity();
    
    arr[size] = data;
    size++;
};

int rArrays::pop() {
    int data = arr[size-1];
    arr[size-1] = NULL;
    size--;
    return data;
}

void rArrays::insert(int index, int item) {

    if ( index > size ) {
        return ;
    }
    
     checkCapacity();

    int tmp = arr[index];
    arr[index] = item;
    size++;
    
    int i = size-1;
    
    while (i > 0 && i > index){
        arr[i+1] = arr[i];
        i = i-1;
    }
    arr[i+1] = tmp;
}

void rArrays::prepend(int item) {
    
    checkCapacity();
    
    int tmp = arr[0];
    arr[0] = item;
    size++;
    
    int i = size-1;
    
    while (i > 0 ){
        arr[i+1] = arr[i];
        i = i-1;
    }
    arr[i+1] = tmp;
}

void rArrays::remove( int index ) {
    for( int i=index ; i < size -1 ; i++) {
        arr[i] = arr[i+1];
    }
    size--;
}

int rArrays::at(int index) {
    return arr[index];
}

void rArrays::print(){
    
    for ( int i=0 ; i<size; i++){
        std::cout << arr[i] << " ";
    }
    
    std::cout << std::endl;
}

int rArrays::find(int item) {
    
    for (int i=0; i < size ; i++ ){
        if ( arr[i] == item ) {
            return i;
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    rArrays *a = new rArrays();
    
    a->push(1);
    a->push(2);
    a->push(3);
    a->push(4);
    a->push(5);
    a->print();
    cout << a->find(5) << endl;
    cout << a->find(10) << endl;
    
//    cout << a->pop() << endl;
//    cout << a->getSize() << endl;
    a->insert(2, 10);
    a->print();
    
    a->prepend(13);
    a->print();
    
    a->remove(3);
    a->print();
    
    cout << "Capacitiy : " << a->getCapacity() << endl;
    cout << "Size : " << a->getSize() << endl;
    a->print();
    return 0;
}
