//
//  link_list.h
//  Experiment2
//
//  Created by JacobLan on 16/3/15.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef link_list_h
#define link_list_h

const int ERROR = -1;
const int SUCCESS = 0;

#include "node.h"				// 结点类模板
using namespace std;
// 简单线性链表类模板
template <class MyType>
class LinkList
{
private:
    Node<MyType> *pHead;		// 头结点指针
    Node<MyType> *pTail;      //尾节点
    Node<MyType> *curPoint;     //当前指针
    int CurPosition;
    int length;     //当前链表中的元素个数
    
public:
    //线性链表方法声明:
    void Init();	// 初始化线性表
    void CreateList( MyType num);
    void Clear();	// 将线性表清空
    void DestoryList();   // 销毁线性表
    int Length();		// 求线性表长度
    bool isEmpty();	// 判断线性表是否为空
    int SetElem(int position, MyType e);
    int GetElem(int position, MyType &e);
    int  Locate(MyType  e);
    int Insert(int position, MyType e);// 插入元素
    int Delete (int position, MyType &e);
    void Traverse();
    int  GetPrior(MyType e, MyType &x);
    int GetNext(MyType e, MyType &x);
    Node<MyType> *GetElemPtr(int position) ;
    int  CreateListOrder(int n);
    int  InsertOrder(MyType e);
};
// 单链表类模板的实现部分







template <class MyType>
Node<MyType>* LinkList<MyType>::GetElemPtr(int position) {
    int uselessData;
    GetElem(position, uselessData);
    return curPoint;
}




template <class MyType>
int LinkList<MyType>::GetNext(MyType e, MyType &x)
{
    if (isEmpty())
    {
        cout << "---LinkList is Empty !!! ---" << endl;
        return ERROR;
    }
        
    Node<MyType> *nextPoint = new  Node<MyType>;
    nextPoint = pHead->pNext;
    Node<MyType> *curPoint = new  Node<MyType>;
    curPoint = pHead;
    
    while (nextPoint != nullptr && curPoint->data != e ) {
        curPoint = curPoint->pNext;
        nextPoint = nextPoint->pNext;
        
    }
    
    if (curPoint == nullptr) {
        cout << "---Can't Find This Item---";
        return ERROR;
    }
    else if (nextPoint == nullptr)
    {
        cout << "---This is the finish Item---" << endl;
        return 0;
    }
    else
    {
        e = nextPoint->data;
        cout << "---This Prior Item is " << e << " ---" << endl;
    }
    return 1;
        }


template <class MyType>
int LinkList<MyType>::GetPrior(MyType e, MyType &x)
{
    if (isEmpty())
    {
        cout << "---LinkList is Empty !!! ---" << endl;
        return ERROR;
    }
    Node<MyType> *priorPoint = new  Node<MyType>;
    priorPoint = pHead;
    Node<MyType> *curPoint = new  Node<MyType>;
    curPoint = pHead;
    
    while (curPoint !=nullptr && curPoint->data != e ) {
        priorPoint = curPoint;
        curPoint = curPoint->pNext;
        
        
    }
    
    if (curPoint == nullptr) {
        cout << "---Can't Find This Item---";
        return ERROR;
    }
    else if (priorPoint == pHead)
    {
        cout << "---This is the first Item---" << endl;
        return 0;
    }
    else
    {
        e = priorPoint->data;
        cout << "---This Prior Item is " << e << " ---" << endl;
    }
    return 1;
}


template <class MyType>
int LinkList<MyType>::Delete(int position, MyType &e) {
    if (position < 1 || position > length) {
        cout << "---Get Position Error---";
        return ERROR;
    }
    
    Node<MyType> *temPoint = nullptr;
    temPoint = pHead;
    
    if (position > CurPosition){
        temPoint = curPoint;
        for (int i = CurPosition; i != position-1; i++) {
            temPoint = temPoint->pNext;
        }
    }
    else
    {
        for (int i = 0; i != position-1; i++) {
            temPoint = temPoint->pNext;
        }
    }
    
    //此时tempoint指向待删除节点前一节点
    Node<MyType> *p = temPoint->pNext;      //p指向待删除的变量
    curPoint = temPoint;
    temPoint  = nullptr;
    CurPosition = position-1;
    curPoint->pNext = curPoint->pNext->pNext;
    CurPosition++;
    e = p->data;
    delete [] p;
    length--;
    return 0;
}



template <class Mytype>
int LinkList<Mytype>::Insert(int position, Mytype e) {
    if (position < 1 || position > length + 1) {
        cout << "---Get Position Error---";
        return ERROR;
    }
    
    Node<Mytype> *temPoint = nullptr;
    
    if (position > CurPosition)
    {
        temPoint = curPoint;
        for (int i = CurPosition; i != position -1 ; i++) {
            temPoint = temPoint->pNext;
        }
        
        CurPosition = position;
        curPoint = temPoint;
        temPoint = new Node<Mytype>;
        temPoint->data = e;
        temPoint->pNext = nullptr;
        temPoint->pNext = curPoint->pNext;
        curPoint->pNext = temPoint;
        length++;
        return SUCCESS;
    }
    else
    {
        
        temPoint = pHead;
        for (int i = 0; i != position-1; i++) {
            temPoint = temPoint->pNext;
        }
        
        curPoint = temPoint;
        temPoint = new Node<Mytype>;
        temPoint->data = e;
        temPoint->pNext = curPoint->pNext;
        curPoint->pNext = temPoint;
        CurPosition = position-1;
        return SUCCESS;
        
    }

}


template <class MyType>
int LinkList<MyType>::Locate(MyType  e) {
    Node<MyType> *temPoint = nullptr;
    temPoint = pHead;
    int count = 0;
    while (temPoint != nullptr && temPoint->data != e ) {
        temPoint = temPoint->pNext;
        count++;
    }
    if (temPoint == nullptr)
    {
        cout << "---Can't Find This Item---" << endl;
        return -1;
    }
    curPoint = temPoint;
    CurPosition = count;
    return count;
}




template <class MyType>
void LinkList<MyType>::Traverse() {
    Node<MyType> *temPoint = nullptr;
    if (length == 0) {
        cout << "---None Nodes---" << endl;
    }
    temPoint = pHead->pNext;

    while (temPoint != nullptr) {
        MyType saveData = temPoint->data;
        cout <<  saveData << " ";
        temPoint = temPoint->pNext;
    }
    delete temPoint;
}


template <class MyType>
int LinkList<MyType>::GetElem(int position, MyType &e) {
    if (position < 1 || position > length) {
        cout << "---Get Position Error---";
        return ERROR;
    }

    Node<MyType> *temPoint = nullptr;
    temPoint = pHead;

    if (position > CurPosition)     //position在curposition之后
    {
        temPoint = curPoint;
        for (int i = CurPosition; i != position; i++) {
            temPoint = temPoint->pNext;
        }
    }
    else        //position在curposition之前
    {
        for (int i = 1; i != position; i++) {
            temPoint = temPoint->pNext;
        }
    }
    
    CurPosition = position;
    curPoint = temPoint;
    e = temPoint->data;
    if (temPoint != nullptr) {
        delete [] temPoint;
    }
    return SUCCESS;
}



template <class MyType>
int LinkList<MyType>::SetElem(int position, MyType e) {
    if (position < 1 || position > length) {
        cout << "---Get Position Error---";
        return ERROR;
    }
    
    Node<MyType> *temPoint = nullptr;
    temPoint = pHead;
    
    if (position > CurPosition)     //position在curposition之后
    {
        temPoint = curPoint;
        for (int i = CurPosition; i != position; i++) {
            temPoint = temPoint->pNext;
        }
    }
    else        //position在curposition之前
    {
        for (int i = 0; i != position; i++) {
            temPoint = temPoint->pNext;
        }
    }

    temPoint->data = e;
    curPoint = temPoint;
    CurPosition = position;
    return SUCCESS;
}

template <class MyType>
bool LinkList<MyType>::isEmpty() {
    return length == 0 ? 1 : 0;
}


template <class MyType>
int LinkList<MyType>::Length() {
    return length;
}



template <class MyType>
void LinkList<MyType>::DestoryList() {
    while (nullptr != pHead->pNext) {
        Node<MyType> *temPoint = nullptr;
        temPoint = pHead->pNext;
        pHead->pNext = pHead->pNext->pNext;
        delete[] temPoint;
    }
    delete [] pHead;
    length = 0;
    CurPosition = 0;
    curPoint = nullptr;
}


template <class MyType>
void LinkList<MyType>::Clear() {
    length = 0;
    curPoint = pHead;
    CurPosition = 0;
    pTail = pHead;
}



template <class MyType>
void  LinkList<MyType>::Init() {
    pHead = new Node<MyType>;
    pTail = pHead;
    CurPosition = 0;
    curPoint = pHead;
    length = 0;
    
}

template <class MyType>
void LinkList<MyType>::CreateList(MyType num) {
    Node<MyType> *temPoint = new Node<MyType>;
    if (nullptr == temPoint) {
        cout << "---Allocate Space Error---" << endl;       //分配空间错误
        exit(-1);
    }
    temPoint->data = num;
    temPoint->pNext = nullptr;
    length++;
    pTail->pNext = temPoint;
    pTail = temPoint;
    temPoint = nullptr;
    delete [] temPoint;
}



#endif /* link_list_h */
