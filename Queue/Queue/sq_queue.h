//
//  sq_queue.h
//  Queue
//
//  Created by JacobLan on 16/3/30.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef sq_queue_h
#define sq_queue_h
using namespace std;

template<class ElemType>
class SqQueue
{
    //约定rear为最后一个元素的下一个数据位
private:
    ElemType *elems;		// 元素存储空间
    int front, rear;		// 队头队尾
    int maxSize;		// 队列最大元素个数
    int length;
public:
    //  抽象数据类型方法声明
        void Init(int size);
        void Clear();
        void  DestroyQueue();
        bool  is_empty( );
        int  Length( );
        bool is_full();
        bool  InQueue(ElemType  e);
        bool  OutQueue(ElemType  &e);
        bool GetHead(ElemType &e);
        void  Traverse();
};

template <class MyType>
void SqQueue<MyType>::Traverse() {
    if(is_empty())
    {
        cout<<"1";
        return;
    }
    int temp = front;
    int i = length;
    while (i--) {
        cout << "front = " << temp << "zhiwei ";
        cout << " " << elems[temp] << endl;
        temp = (temp + 1 + maxSize)%maxSize;
    }
}

template <class MyType>
bool SqQueue<MyType>::GetHead(MyType &e) {
    if (is_full() || is_empty()) {
        return false;
    }
    e = *elems[front];
    return true;
}

template <class MyType>
bool SqQueue<MyType>::InQueue(MyType e ) {
    if (is_full()) {
        cout << "---Full---" << endl;
        return false;
    }
    
    elems[rear] = e;
    rear = (rear +1 + maxSize) % maxSize;
    length++;
    return true;
}

template <class MyType>
bool SqQueue<MyType>::OutQueue (MyType &e) {
    if (is_empty()) {
        return false;
    }
        
    e = elems[front];
    cout << "outqueue = " << e << endl;
    front = (front+1+maxSize) % maxSize;
    length--;
    return true;
}

template <class MyType>
void SqQueue<MyType>::Init(int size) {
    elems = new MyType[size];
    front = rear = 0;
    length=0;
    maxSize = size;
}

template <class MyType>
void SqQueue<MyType>::Clear() {
    rear = front = 0;
    length = 0;
}

template <class MyType>
void SqQueue<MyType>::DestroyQueue () {
    length = -1;
    maxSize = -1;
    front = -1;
    rear = -1;
    delete elems;
}

template <class MyType>
bool SqQueue<MyType>::is_empty() {
    return !length;      //空1
}

template <class MyType>
int SqQueue<MyType>::Length () {
    return length;
}

template <class MyType>
bool SqQueue<MyType>::is_full () {
    return length == maxSize;
}

#endif /* sq_queue_h */
