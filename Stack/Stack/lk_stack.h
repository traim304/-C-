//
//  lk_stack.h
//  Stack
//
//  Created by JacobLan on 16/3/23.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef lk_stack_h
#define lk_stack_h
//#include <cstdlib>
using namespace std;


#include "Node.h"
// 链栈类模板
template<class MyType>
class LinkStack
{
private:
    Node<MyType> *pTop;	// 栈顶指针
    int  length; //栈长度
    bool isExist();
    bool isLegal();
public:
    void Init( );
    void  Clear( );
    bool  isEmpty( );
    int  Length( );
    bool Push(MyType e); //新元素入栈
    bool Pop(MyType &e); //出栈，即删除栈顶元素
    bool Top(MyType &e); //读栈，即读取栈顶元素
    void Traverse();
    
};
// 链栈类模板的实现部分

template <class MyType>
bool LinkStack<MyType>:: isLegal() {
    if (isExist()) {
        return 1;
    }
    else
    {
        cout << "---Illegal---" << endl;
        exit(1);
        return 0;
    }
}


template <class MyType>
bool LinkStack<MyType>:: isExist() {        //是否存在，存在返回1，否则为1
    if (length) {
        return 1;
    }
    else
    {
        return 0;
    }
}

template <class MyType>
void LinkStack<MyType>::Init() {
    pTop = new Node<MyType>;
    pTop->data = 0;
    pTop->pNext = nullptr;
    length = 1;
}

template <class MyType>
void LinkStack<MyType>::Clear() {
    isLegal();
    while (pTop != nullptr) {
        Node<MyType> *temPoint = nullptr;
        temPoint = pTop;
        pTop = pTop->pNext;
        delete [] temPoint;
        length  = 0;
    }
}

template <class MyType>
bool LinkStack<MyType>::isEmpty() {
    if (length == 0) {
        cout << "---Empty---" << endl;
        return true;
    }
    else
    {
        cout << "---Not Empty---" << endl;
        return false;
    }
}


template <class MyType>
int LinkStack<MyType>::Length() {
    isLegal();
    return length;
}


template <class MyType>
bool LinkStack<MyType>::Push(MyType e){
    isLegal();
    if (length == 1) {
        pTop->data = e;
    }
    else
    {
        Node<MyType> *temPoint =new Node<MyType>;
        temPoint->data = e;
        temPoint->pNext = pTop;
        pTop = temPoint;
    }
    length++;
    return true;
}

template <class MyType>
bool LinkStack<MyType>::Pop (MyType &e) {
    isLegal();
    Node<MyType> *temPoint = new Node<MyType>;
    pTop = pTop->pNext;
    e = temPoint->data;
    length--;
    delete [] temPoint;
    return true;
}

template <class MyType>
bool LinkStack<MyType>::Top(MyType &e) {
    isLegal();
    e = pTop->data;
    return true;
}


template <class MyType>
void LinkStack<MyType>::Traverse() {
    isLegal();
    Node<MyType> *temPoint = pTop;
    while (temPoint != nullptr) {
        cout << temPoint->data;
        temPoint = temPoint->pNext;
    }
}
#endif /* lk_stack_h */



















