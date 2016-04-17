//
//  sort_queue.h
//  SimulateTheBankSystem
//
//  Created by JacobLan on 16/4/13.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef sort_queue_h
#define sort_queue_h

#include "queue.h"
//
//实现功能：
//    1.用户等待时间减一；
//    2.如处理时间到了，则出列
template <class MyType>
void sort_queue(Queue<MyType> &queue_1,Queue<MyType> &queue_2,Queue<MyType> &queue_3,Queue<MyType> &queue_4)
{
    
    //正在处理的人的等待时间减1
    queue_1.remain_time_refresh();
    queue_2.remain_time_refresh();
    queue_3.remain_time_refresh();
    queue_4.remain_time_refresh();
    
    //p_front 为空?
    //队列有人，且等待处理完成时间为0，出列
    
    if(queue_1.is_pop())
    {
        queue_1.pop();
    }
    
    if (queue_2.is_pop()) {
        queue_2.pop();
    }
    
    if (queue_3.is_pop()) {
        queue_3.pop();
    }
    
    if (queue_4.is_pop()) {
        queue_4.pop();
    }
    
}


#endif /* sort_queue_h */
