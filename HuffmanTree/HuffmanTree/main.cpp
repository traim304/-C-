//
//  main.cpp
//  HuffmanTree
//
//  Created by JacobLan on 16/5/3.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#include <iostream>
#include "HuffmanTree.h"

int main(int argc, const char * argv[]) {
    HuffmanTree<int> huffman_tree;
    huffman_tree.init();
    //huffman_tree.traverse();
    huffman_tree.print_key_value();
}
