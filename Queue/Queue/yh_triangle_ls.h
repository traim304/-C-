//
//  yh_triangle.h
//  Queue
//
//  Created by JacobLan on 16/3/31.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef yh_triangle_ls_h
#define yh_triangle_ls_h
#include "lk_queue.h"

//前一行的队列，出一个队列x，读队头y，x+y入队列，直到为1停止，再入一个1；

void  print_yh_triangle_ls(int n)
{
    LinkQueue<int> lq;
    lq.Init();
    lq.InQueue(1);
    lq.InQueue(1);
    int x,y;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cout << " " << 1 << endl;
            continue;
        }
        else if(i == 2)
        {
            cout << " 1 1 ";
            continue;
        }
        else{
            for (int j = 0; j < i-2; j++) {
            lq.OutQueue(x);
            lq.GetHead(y);
            lq.InQueue(x+y);
        }
        lq.InQueue(1);
        cout << endl;
        lq.Traverse();
    }
}
    cout << endl;
}



#endif /* yh_triangle_h */
