//
//  Node.h
//  Stack
//
//  Created by JacobLan on 16/3/23.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef Node_h
#define Node_h

// 结点类模板
template <class ElemType>
struct Node
{
    // 数据成员:
    ElemType data;			// 数据域
    Node<ElemType> *pNext;		// 指针域
};


#endif /* Node_h */
