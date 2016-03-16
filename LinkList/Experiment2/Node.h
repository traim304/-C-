//
//  Node.h
//  Experiment2
//
//  Created by JacobLan on 16/3/15.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef Node_h
#define Node_h

// 结点类模板
template <class MyType>
struct Node
{
    // 数据成员:
    MyType data;				// 数据域
    Node<MyType> *pNext;		// 指针域
};

#endif /* Node_h */
