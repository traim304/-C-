//
//  HuffmanTreeNode.h
//  BinTree
//
//  Created by JacobLan on 16/5/2.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef HuffmanTreeNode_h
#define HuffmanTreeNode_h

template <class MyType>
struct HuffmanTreeNode {
    int weight;
    int parent;
    int left_child;
    int right_child;
    char character;
    
};

#endif /* HuffmanTreeNode_h */
