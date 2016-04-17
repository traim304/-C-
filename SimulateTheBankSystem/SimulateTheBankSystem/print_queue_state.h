//
//  print_queue_state.h
//  SimulateTheBankSystem
//
//  Created by JacobLan on 16/4/15.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

//#ifndef print_queue_state_h
//#define print_queue_state_h
#include "queue.h"


void print_queue_state(Queue<int>* queue,int queue_num)
{
    cout << "窗口" << queue_num << "等待人数为" <<  queue->current_num << "   处理完成还须等待";
    if (queue->p_front == nullptr)
    {
        cout << 0 <<"分钟" << endl;
    }
    else
    {
        cout << queue->p_front->remain_time <<"分钟"<< endl;
    }
}

//#endif /* print_queue_state_h */
