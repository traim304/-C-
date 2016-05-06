//
//  main.cpp
//  BinTree
//
//  Created by JacobLan on 16/4/21.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "binary_tree.h"
#include "bin_tree_node.h"
using namespace std;

void print_interactive()
{
    cout << "1.初始化二叉树"<<endl;
    cout << "2.构造二叉树"<<endl;
    cout << "3.返回二叉树的根节点"<<endl;
    cout << "4.查找元素值为e的结点"<<endl;
    cout << "5.读取指定元素节点的左孩子"<<endl;
    cout << "6.读取指定元素节点的父节点"<<endl;
    cout << "7.读取指定元素的左兄弟" << endl;
    cout << "8.为指定元素所在的节点插入左右孩子" << endl;
    cout << "9.修改某元素的值" << endl;
    cout << "10.查询该二叉树共有多少节点" << endl;
    cout << "11.该二叉树的深度为" << endl;
    cout << "12.查询该二叉树叶子的个数" << endl;
    cout << "13.销毁该二叉树" << endl;
    cout << "14.退出" << endl;
    cout << "请选择: " << endl;
    
}

int main(int argc, const char * argv[]) {
    BinaryTree<char> char_bin_tree;
    cout <<"-----start-----"<< endl;
    int key;
    print_interactive();
    cin >> key;
    
    while (key != 14) {
        switch (key) {
            case 1:
            {
                char_bin_tree.InitBiTree();
                cout << "初始化完毕"<< endl << endl;
            }
                break;
            case 2:
            {
                char_bin_tree.CreateBiTree();
            }
                break;
            case 3:
            {
                BinTreeNode<char> *save_root;
                save_root = char_bin_tree.GetRoot();
                cout << "二叉树的根节点的值为"<< save_root->data <<endl;
            }
                break;
            case 4:
            {
                char e;
                cin >> e;
                if (char_bin_tree.Locate(e)) {
                    cout << "元素" << e << "存在";
                }
            }
                break;
            case 5:
            {
                cout << "该指定元素的值为: ";
                char save_data,find_data;
                cin >> save_data;
                char_bin_tree.GetLeft(find_data, save_data);
                cout << "该节点的左孩子为: " << endl;
                cout << save_data << endl;
            }
                break;
                
            case 6:
            {
                cout << "该指定元素为: ";
                char save_data,find_data;
                cin >> find_data;
                char_bin_tree.GetParent(find_data, save_data);
                cout << save_data;
                cout << endl;
            }
                break;
            case 7:
            {
                cout << "该指定元素为:";
                char save_data,find_data;
                cin >> find_data;
                char_bin_tree.GetLeftSibling(find_data, save_data);
                cout << save_data;
            }
                break;
            case 8:
            {
                cout << "该指定元素为:";
                char find_data;
                cin >> find_data;
                cout << "插入到该节点的左右孩子的值为:" << endl;
                char l_value,r_value;
                cin >> l_value >> r_value;
                char_bin_tree.Insert_child(find_data, l_value, r_value);

            }
                break;
            case 9:
            {
                cout << "待修改某素的值为: ";
                char find_data,later_data;
                char_bin_tree.SetElem(find_data, later_data);
            }
                break;
                
            case 10:
            {
                cout << "一共具有的元素个数为: ";
                cout << char_bin_tree.Size() << endl;
            }
                break;
            case 11:
            {
                cout <<"该二叉树的深度为: ";
                cout << char_bin_tree.Depth() << endl;
            }
                break;
            case 12:
            {
                cout << "该二叉树的叶子个数为: ";
                cout << char_bin_tree.Leaf() << endl;
            }
                break;
            case 13:
            {
                char_bin_tree.DestoryBiTree();
                cout << "Done" << endl;
            }
                break;
                
            case 14:
            {
                exit(14);
            }
        }
        
        
        print_interactive();
        cin >> key;
    }
    
    return 0;
}
