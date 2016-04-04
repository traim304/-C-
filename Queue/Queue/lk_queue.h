//
//  lk_queue.h
//  Queue
//
//  Created by JacobLan on 16/3/30.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef lk_queue_h
#define lk_queue_h

#include "node.h"
// 链栈类模板
#include "cstdlib"
using namespace std;

template<class MyType>
class LinkQueue
{
private:                    //  链队列实现的数据成员:
    Node<MyType> *pFront, *pRear;// 队头队尾指指
    int length;             //队列长度
public:
    //  抽象数据类型方法声明
        void Init();
        void Clear();
        void DestroyQueue();
        bool isEmpty( );
        int  Length( );
        bool InQueue(MyType  e);
        bool OutQueue(MyType  &e);
        bool GetHead(MyType &e);
        void Traverse();
};
// 链队类模板的实现部分


template <class MyType>
void LinkQueue<MyType>::Traverse() {
    Node<MyType> *p;
        p = pFront;
    while (nullptr != p) {
        cout << " " << p->data;
        p = p->pNext;
    }
}

template <class MyType>
bool LinkQueue<MyType>::GetHead(MyType &e) {
    if (nullptr == pRear) {
        cout << endl << "---Error---" << endl;
        return false;
    }
    e = pFront->data;
    return true;
}

template <class MyType >
void LinkQueue<MyType>::Init() {
    pFront = new Node<MyType>;
    pRear = pFront;
    pRear->pNext = nullptr;
    length = 1;
}

template <class MyType>
void LinkQueue<MyType>::Clear() {
    Node<MyType> *p;
    while (p != nullptr) {
        p = pFront;
        pFront = pFront->pNext;
    }
    pRear = pFront = new Node<MyType>;
    pFront->data = 1;
    length = 1;
}

template <class MyType>
void LinkQueue<MyType>::DestroyQueue()
{
    Clear();
    delete  pRear;
    delete  pFront;
}

template <class MyType>
bool LinkQueue<MyType>::isEmpty() {
    return length;
}

template <class MyType>
int LinkQueue<MyType>::Length() {
    return length;
}

template <class MyType>
bool LinkQueue<MyType>::InQueue(MyType  e) {
    if(length == 1)
    {
        pRear->data = e;
        pRear->pNext = nullptr;
        length++;
        return true;
    }
    Node<MyType> * p = new Node<MyType>;
    p->data = e;
    p->pNext = nullptr;
    pRear->pNext = p;
    pRear = p;
    length++;
    return true;
}


template <class MyType>
bool LinkQueue<MyType>::OutQueue(MyType  &e) {
    e = pFront->data;
    Node<MyType> *p = new Node<MyType>;
    p = pFront;
    pFront = pFront->pNext;
    length--;
    delete p;
    return true;
}

#endif /* lk_queue_h */
