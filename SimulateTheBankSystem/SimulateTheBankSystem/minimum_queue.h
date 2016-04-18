//
//  minimum_queue.h
//  SimulateTheBankSystem
//
//  Created by JacobLan on 16/4/12.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef minimum_queue_h
#define minimum_queue_h
#include "queue.h"
#include "PATH.h"


//求当前等待人数最少的那排

template <class MyType>
Queue<MyType>* minimum_queue(Queue<MyType> *queue_1, Queue<MyType> *queue_2, Queue<MyType> *queue_3, Queue<MyType> *queue_4) {
    
    fstream outfile(PATH,ios::app);
    
    
    int minimum = queue_1->current_num;
    int queue_num = 1;
    
    
    cout << "～～～～～～～～～～" << "进入排队系统" << "～～～～～～～～～～" << endl;
    outfile << "～～～～～～～～～～" << "进入排队系统" << "～～～～～～～～～～" << endl;

    
    Queue<MyType>* minimum_queue = queue_1;
    if (minimum > queue_2->current_num)
    {
        minimum = queue_2->current_num;
        queue_num = 2;
        minimum_queue = queue_2;
    }
    if (minimum > queue_3->current_num) {
        minimum = queue_3->current_num;
        queue_num = 3;
        minimum_queue = queue_3;
    }
    if (minimum > queue_4->current_num) {
        minimum = queue_4->current_num;
        queue_num = 4;
        minimum_queue = queue_4;
    }
    
    cout << "       此时窗口"  << queue_num << "等待人数最少，将插入队列" << queue_num << endl;
    outfile << "       此时窗口"  << queue_num << "等待人数最少，将插入队列" << queue_num << endl;
    
    outfile.close();
    return minimum_queue;       //为什么return &minimum_queue编译也通过
    
}

#endif /* minimum_queue_h */
