//
//  bin_tree_node.h
//  BinTree
//
//  Created by JacobLan on 16/4/21.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef bin_tree_node_h
#define bin_tree_node_h

template <class MyType>
struct BinTreeNode
{
    // 数据成员:
    MyType data;				   	// 数据域
    BinTreeNode<MyType>  *left_child;	// 左孩子
    BinTreeNode<MyType>  *right_child;	// 右孩子
    
};



#endif /* bin_tree_node_h */
