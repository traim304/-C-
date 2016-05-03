//
//  HuffmanTree.h
//  BinTree
//
//  Created by JacobLan on 16/5/2.
//  Copyright © 2016年 JacobLan. All rights reserved.
//


#ifndef HuffmanTree_h
#define HuffmanTree_h

#include "key_value.h"
#include "HuffmanTreeNode.h"
#include <string>
#include <stdio.h>
using namespace std;

const int INDEFINITE = 999999999;
template <class MyType>
class HuffmanTree {
    HuffmanTreeNode<MyType> *node;
    int cur_num;    //记录的是当前数组的最后一个
    int num;        //节点的总数 2n-1 n为编码集的总数
    key_value *coder_list;      //指向 key_value 结构体的指针
    
public:
    void init();
    void creat_huffman_tree();
    string encoding(string);
    string decoding(string);
    void creat_key_value();
    void traverse();
    void get_value(char);
    void get_value_position(int position);
    void print_key_value();
};

template <class MyType>
void  HuffmanTree<MyType>::print_key_value() {
    int n = (num+1) /2;     // n为编码集的总数
    coder_list = new key_value[n];
    for (int i = 1; i <= n; i++) {
        get_value(node[i].character);
    }
    
    //遍历输出key_value对
    for (int i = 1; i <= n; i++) {
        cout << "key = " << coder_list[i].key  << "   code: " << coder_list[i].value << endl;
    }
}

template <class MyType>
void HuffmanTree<MyType>::get_value_position(int position) {
    string o = "0";
    string l = "1";
    int target_position = position;
    do {
        if (node[node[position].parent].left_child == position) {
                coder_list[target_position].value = coder_list[target_position].value + o;

        }
        else
        {
                coder_list[target_position].value = coder_list[target_position].value + l;
            
        }
        
        position = node[position].parent;
    } while (node[position].parent != 0);
    
    
}

//找到该字符所在的数组下标，作为参数传入get_value_position()
template <class MyType>
void HuffmanTree<MyType>::get_value(char character) {
    int i = 1;
    while (node[i].character != character) {
        i++;
    }
    coder_list[i].key = character;
    get_value_position(i);
}


template <class MyType>
void HuffmanTree<MyType>::init() {
    cout << "请输入字符集编码的个数！" << endl;
    int n;
    cin >> n;
    //n个字符的Huffman树有2n－1个节点
    const int m = 2 *n -1;
    num = m;
    node = new HuffmanTreeNode<MyType>[m+1];      //数组下标为0的空间不用
    int cur_num = n;
    num = m;
    
    cout << "请依次输入" << n <<  "个字符; " << endl;
    for (int i = 1; i <= n; i++) {
        cin >> node[i].character;
    }
    
    cout << "请依次输入" << n << "个字符的权值" << endl;
    for (int i = 1; i <= n; i++) {
        cin >>node[i].weight;
    }
    
    //结点的三个链域和权值为0
    
    for (int i = 0; i <= m; i ++) {
        node[i].parent = 0;
        node[i].left_child = 0;
        node[i].right_child = 0;
    }
    
    
    //n个叶子节点共需要合并n+1次
    for (int i = 0; i < n-1; i++) {
    
    //取出两个权值最小节点
    int min_node_weight = INDEFINITE,sec_min_node_weight = INDEFINITE-1;
    int min_node_flag = INDEFINITE, sec_min_flag = INDEFINITE-1;
    for (int i = 1; i <= cur_num; i++) {
        if (node[i].weight < min_node_weight && node[i].parent == 0) {
            min_node_weight = node[i].weight;
            min_node_flag = i;
        }else if(node[i].weight < sec_min_node_weight && node[i].parent == 0){
            sec_min_node_weight = node[i].weight;
            sec_min_flag = i;
        }
    }
    
    //在数组最后一项增加合并后的节点并修改数据
    int parent_weight = min_node_weight + sec_min_node_weight;
    cur_num++;
    node[cur_num].weight = parent_weight;
    node[cur_num].parent = 0;
    node[cur_num].left_child = min_node_flag;
    node[cur_num].right_child = sec_min_flag;
    
    //改变的两项的parent的值
    node[min_node_flag].parent = cur_num;
    node[sec_min_flag].parent = cur_num + 1;
}
}

template <class MyType>
void HuffmanTree<MyType>::traverse() {
    for (int i = 1; i <= num; i++) {
        cout << "flag: " << i;
        cout << "  weight: " << node[i].weight << "  parent: " << node[i].parent << " left_child: " << node[i].left_child << "  right_child: " << node[i].right_child << "  character: " << node[i].character << endl;
    }
}

template <class MyType>
void HuffmanTree<MyType>::creat_key_value() {
    int n = (num+1) /2;     // n为编码集的总数
    coder_list = new key_value[n];
    for (int i = 0; i < n; n++) {
        coder_list[i].key = node[i].character;
        coder_list[i].value = get_value(coder_list[i].key);
    }
}


#endif /* HuffmanTree_h */
