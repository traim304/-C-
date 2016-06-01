#ifndef HuffmanTree_h
#define HuffmanTree_h

#include "key_value.h"
#include "HuffmanTreeNode.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "outfile_PATH.h"
#include <stdio.h>
#include <cstring>
using namespace std;

const int INDEFINITE = 666666;

template <class MyType>
class HuffmanTree {
private:
    HuffmanTreeNode<MyType> *node;
    int cur_num;    //记录的是当前数组的最后一个
    int num;        //节点的总数 2n-1 n为编码集的总数
    key_value *coder_list;      //指向 key_value 结构体的指针
    
    void str_reverse(string &str);
    void get_value(char);       //传入字符得到编码
    void creat_key_value();     //创建键值对
    void get_value_position(int position);      ////传入数组下标得到编码
    
public:
    void init();
    void creat_huffman_tree();
    void encoding();
    void decoding();
    void traverse();
    void print_key_value();
};


template <class MyType>
void HuffmanTree<MyType>::encoding() {
    int n = (num+1) /2;     // n为编码集的总数
    cout << "请输入要编码的原文(自动保存在row_txt.txt)中:" << endl;
    ofstream fout;
    fout.open(row_txt_path);
    string row = "THIS PROGRAM IS MY FAVORITE";
    
    
//    while (cin>>row[row_size] && row[row_size] != '#') {
//        row_size++;
//    }
    
    
//    cout << "要编码的原文是:  " << endl;
//    for (int i = 1; i <= row_size; i++) {
//        cout << row[i];
//    }
    
    cout << row << endl;
    fout << row;
    
    cout << "Encoding " << endl;
    
    ifstream fin;
    fin.open(key_value_path);
    
    
    char *key = new char[n];
    char cc;
    for (int i = 0; i < n; i++) {
        fin >> cc;
        cout << cc;
    }
    
    cout << "key = " << key; //shu chu
    
    string *value = new string[n];
    for (int i =1; i <= n; i++) {
        fin >> value[i];
    }
    
    //对应翻译
    //coded为编码后
    string coded;
    //每循环一次取出一个字符
    int *locate_key_flag;
    for (int i = 1; i <= n; i++) {
        string keying = &key[i];  //当前对应的key
        //循环对比出keying在key_value中的位置，将位置下标交给locate_key
        for (int i = 1; i <= n ; i++) {
            if (keying == coder_list[i].key) {
                *locate_key_flag = i;
                break;
            }
        }
        
        
        if (locate_key_flag == nullptr || *locate_key_flag > n || *locate_key_flag < n) {
            exit(9);
        }
        
        
        
        
        string cur_code = coder_list[*locate_key_flag].value;
        coded = coded + cur_code;
    }
    
    
    cout << "codeing zhi hou :" << endl << coded << endl;
}


template <class MyType>
void HuffmanTree<MyType>::str_reverse(string& str) {
    unsigned long len = str.length();
    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = tmp;
    }
}

template <class MyType>
void  HuffmanTree<MyType>::print_key_value() {
    int n = (num+1) /2;     // n为编码集的总数
    coder_list = new key_value[n];
    for (int i = 1; i <= n; i++) {
        get_value(node[i].character);
    }
    
    //反转
    for (int i =1; i <= n; i++) {
        str_reverse(coder_list[i].value);
    }
    
    //遍历输出key_value对 并保存到文件 格式为 key一行 code一行
    ofstream fout;
    fout.open(key_value_path);
    for (int i = 1; i <= n; i++) {
        cout << "key = " << coder_list[i].key  << "   value: " << coder_list[i].value << endl;
        fout << coder_list[i].key;
    }
    fout << endl;
    for (int i = 1; i <= n ; i++) {
        fout << coder_list[i].value << " " ;
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
    
    char c;
    cout << "请依次输入" << n <<  "个字符; " << endl;
    while(cin.get() != '\n')
    {
        continue;
    }
    for (int i = 1; i <= n; i++) {
        cin.get(c);
        node[i].character = c;
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
        //求最小
        if (node[i].weight < min_node_weight && node[i].parent == 0) {
            min_node_weight = node[i].weight;
            min_node_flag = i;
        }
}
        
        for (int i =1; i <= cur_num; i++) {
            //第二小
            if (i == min_node_flag) {
                continue;
            }
            if (node[i].weight < sec_min_node_weight && node[i].parent == 0) {
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
    node[cur_num].character = ' ';
    
    //改变的两项的parent的值
    node[min_node_flag].parent = cur_num;
    node[sec_min_flag].parent = cur_num;
        
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
