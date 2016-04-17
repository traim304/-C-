//
//  queue.h
//  SimulateTheBankSystem
//
//  Created by JacobLan on 16/4/12.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef queue_h
#define queue_h
#include <iostream>
using namespace std;

#include "node.h"


template <class MyType>
class Queue {
public:
    node<MyType> * p_front;
    node<MyType> * p_tail;
    int current_num;
    
    bool is_pop();
    void init();
    void pop();
    void push(int id,int coming_time,int process_time);
    void remain_time_refresh();
};

template <class MyType>
void Queue<MyType>::remain_time_refresh() {
    if (p_front == nullptr) {
        return;
        
    }
    else
    {
        p_front->remain_time--;
    }
    
}

template <class MyType>
void Queue<MyType>::init() {
    current_num = 0;
    p_front = nullptr;
    p_tail = nullptr;
}



template <class MyType>
bool Queue<MyType>:: is_pop() {
    if (p_front == nullptr) {
        return false;
    }
    if ((current_num != 0) && (p_front->remain_time == 0)) {
        return true;
    }
    
    return false;
    }


template <class MyType>
void Queue<MyType>::pop() {
    
    
    cout << endl<<  "－－－－－－－出列操作－－－－－－－" << endl << "出队列者信息为:" <<"第" << p_front->id << "个人进银行" << "(" << p_front->coming_time <<" min)" << "  此次处理共耗时 " << p_front->process_time << " min" << endl;
    
    //信息输出完毕。滚！
    node<MyType>* tmp = p_front;
    p_front = p_front->p_next;
    current_num--;
    delete tmp;
}


template <class MyType>
void Queue<MyType>::push(int id,int coming_time,int process_time) {
    //给待插入的人分配空间，并赋值
    node<int> * tmp = new node<int>;
    tmp->id = id+1;
    tmp->coming_time = coming_time;
    tmp->process_time = process_time;
    tmp->p_next = nullptr;
    tmp->remain_time = process_time;
    
    //队伍为空时，特殊处理
    if(current_num == 0)
    {
        p_tail = tmp;
        p_front = p_tail;
        current_num++;
        return;
    }
    
    //不空，直接插入队列
    p_tail->p_next = tmp;
    p_tail = p_tail->p_next;
    current_num++;
    tmp = nullptr;
    delete tmp;
}


#endif /* queue_h */
