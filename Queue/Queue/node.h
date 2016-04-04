//
//  node.h
//  Queue
//
//  Created by JacobLan on 16/3/30.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef node_h
#define node_h

// 结点类模板
template <class ElemType>
struct Node
{
    // 数据成员:
    ElemType data;			// 数据域
    Node<ElemType> *pNext;		// 指针域
};


#endif /* node_h */
