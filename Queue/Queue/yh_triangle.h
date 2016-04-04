//
//  yh_triangle.h
//  Queue
//
//  Created by JacobLan on 16/3/31.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef yh_triangle_h
#define yh_triangle_h
#include "lk_queue.h"


void  print_yh_triangle(int n)
{
    LinkQueue<int> old_lq,new_lq;
    old_lq.Init(),new_lq.Init();
    
    for (int i = 1; i <= n; i++) {       //输出第i行
        for(int j = 0; j < i-1; j++)      //调用add_two_items()的次数
        {
            int save_add = old_lq.add_two_items();
            new_lq.InQueue(save_add);
            int junk_data;  //用于临时保存出队列的值
            old_lq.OutQueue(junk_data);
        }
        new_lq.Traverse();
        old_lq.change_pFront(new_lq.get_pFront());
        old_lq.change_pRear(new_lq.get_pRear());
        new_lq.Init();
        cout << endl;
    }
}



#endif /* yh_triangle_h */
