//
//  yh_triangle_sq.h
//  Queue
//
//  Created by JacobLan on 16/4/4.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef yh_triangle_sq_h
#define yh_triangle_sq_h

void print_yh_triangle_sq(int n)
{
    SqQueue<int> sq;
    sq.Init(50);
    sq.InQueue(1);
    sq.InQueue(1);
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
                sq.OutQueue(x);
                sq.GetHead(y);
                sq.InQueue(x+y);
            }
            sq.InQueue(1);
            cout << endl;
            sq.Traverse();
        }
    }
    cout << endl;

}


#endif /* yh_triangle_sq_h */
