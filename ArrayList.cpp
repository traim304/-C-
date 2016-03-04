//
//  main.cpp
//  arrylist
//
//  Created by Jacob Lan on 16/3/3.
//  Copyright © 2016年 traim. All rights reserved.
//

#include <iostream>
using namespace std;
#define ERROR 0;
#define OK 1;

template <class ElemType>
class Sqlist {
    int count;
    int maxSize;
    ElemType *elems;
    
public:
    int init(int maxSize);
    void destoryList();
    int creatList(ElemType size);
    void clear();
    int length();
    bool isEmpty();
    bool isFull();
    ElemType setElem(int position, ElemType e); //第position个元素
    void getElem(int position, ElemType &e);
    bool insert(int position, ElemType e);
    void traverse();
};



template <class ElemType>
void Sqlist<ElemType>::getElem(int position, ElemType &e) {
    e = elems[position-1];
}


template <class TTTT>
bool Sqlist<TTTT>::insert(int position, TTTT e) {
    if(position < 1||position > count-1)
    {
        cout << "insert() ERROR" << endl;
        return 0;
    }
    
    for (int i = count; i != position - 1; i--) {
        elems[i] = elems[i-1];
    }
    
    elems[position-1] = e;
    count++;
    return 1;
}


template <class myType>
myType Sqlist<myType>::setElem(int position, myType e) {
    if(position < 1||position > count)
    {
        cout << "setElem() ERROR" << endl;
        return 0;
    }
    
    elems[position - 1] = e;
    return 1;
}


template <class TTT>
bool Sqlist<TTT>::isFull() {
    if(maxSize > count)
        return 0;
    return 1;
}


template <class TT>
bool Sqlist<TT>::isEmpty() {
    if(count)
        return 0;
    return 1;
}


template <class T>
int Sqlist<T>::length() {
    return count;
}


template <class ElemType>
int Sqlist<ElemType> :: init(int Size) {
    if (elems)
        delete []elems;
    
    elems = new ElemType(Size);
    
    if (!elems)
        return ERROR;
    
    this->maxSize = Size;
    count = 0;
    
    return OK;
}

template <class elemType>
void Sqlist<elemType>::destoryList() {
    
    delete [] elems;
    maxSize = 0;
    count = 0;
}

template <class ElemType>
void Sqlist<ElemType>::clear() {
    for (int i = 0; i < count; i++)
    {
        elems[i] = '\0';
    }
}

template <class ElemType>
int Sqlist<ElemType>::creatList(ElemType size) {
    if (size >= maxSize) {
        return ERROR;
    }
    
    cout << "Will creat a list and this list's length is " << size << endl;
    
    for(int i =0; i < size; i++)
    {
        printf("Please input elem[%d]: " , i);
        cin >> elems[i];
    }
    
    count = size;
    return OK;
}


template <class ElemType>
void Sqlist<ElemType>:: traverse() {
    for (int i = 0 ; i < count; i++) {
        cout << elems[i] << " ";
    }
}



int main(int argc, const char * argv[]) {
    int returnE;
    Sqlist<int> arryList;
    arryList.init(5);
    arryList.creatList(3);
    //arryList.insert(20, 8888);
    //arryList.setElem(30, 99999);
    //cout << arryList.isFull() << endl << arryList.isEmpty() << endl;
    //arryList.clear();
    //arryList.destoryList();
    //arryList.traverse();
    arryList.getElem(3, returnE);
    printf("%d",returnE);
    return 0;
}
