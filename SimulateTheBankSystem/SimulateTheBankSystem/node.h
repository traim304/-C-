//
//  node.h
//  SimulateTheBankSystem
//
//  Created by JacobLan on 16/4/12.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef node_h
#define node_h

template <class MyType>
struct node {
    MyType id;
    MyType coming_time;
    node<MyType>* p_next;
    int process_time;
    int remain_time;
};

#endif /* node_h */
