#ifndef binary_tree_h
#define binary_tree_h

// 二叉树类模板
#include "bin_tree_node.h"
#include <iostream>

using namespace std;


template <class MyType>
class BinaryTree
{
private:
    //  二叉树的数据成员:
    BinTreeNode<MyType> *root;
    int size;       //结点个数
    // 二叉树的私有函数:
    void PreOrderHelp(BinTreeNode<MyType> *r);      //先序遍历
    void InOrderHelp(BinTreeNode<MyType> *r);       //中序遍历
    void PostOrderHelp(BinTreeNode<MyType> *r);     //后序遍历
    void Creat(BinTreeNode<MyType> *r, int flag);       //递归创建子树
    
    BinTreeNode<MyType> *private_Locate(BinTreeNode<MyType> *r, MyType e);      //查找元素值为e的结点,返回指针.
    BinTreeNode<MyType>* left_child(MyType e);      //定位指定元素的左孩子，返回其指针。
    BinTreeNode<MyType>* Parent(BinTreeNode<MyType>*r, MyType e);       //定位指定元素的父结点
    BinTreeNode<MyType>* LeftSibling(MyType e);     //定位指定元素的左兄弟
    int Size(BinTreeNode<MyType> *r);
    int Depth(BinTreeNode<MyType> *r);
    int Leaf(BinTreeNode<MyType> *r);       //统计并返回叶子结点个数
    void Clear(BinTreeNode<MyType> *r);
    void DisplayTreeeHelp(BinTreeNode<MyType> *r, int level);// 按树状形式显示以r为根的二叉树，level为层次数，可设根结点的层次数为1
    
public:
    void InitBiTree();      // 无参数的构造函数模板
    void CreateBiTree();        // 构造二叉树
    BinTreeNode<MyType> *GetRoot();					// 返回二叉树的根
    void InOrder();         //二叉树的中序遍历
    void PreOrder();        // 二叉树的先序遍历
    void PostOrder();       // 二叉树的后序遍历
    bool Locate(MyType e);       //查找元素值为e的结点。
    int GetLeft(MyType e, MyType &c);       //读取指定元素的左孩子
    int GetParent(MyType e, MyType &f);     //读取指定元素的父元素
    int GetLeftSibling(MyType e, MyType &s);        //读取指定元素的左兄弟
    int Insert_child(MyType e,MyType x,MyType y);       //为指定元素 e 插入左、右孩子
    int SetElem(MyType  e, MyType  x);      //更新指定元素
    int Size();
    int Depth();
    int Leaf();     //统计并返回叶子结点个数
    void DestoryBiTree();       //销毁二叉树
    void DisplayTree();
};

template <class MyType>
int BinaryTree<MyType>::Size (BinTreeNode<MyType> *r) {
    BinTreeNode<MyType> *p;
    if (r == nullptr) {
        return 0;
    }
    
    return Size(r->left_child) + Size(r->right_child)+1;
}


template <class MyType >
void BinaryTree<MyType>::PreOrderHelp(BinTreeNode<MyType> *r) {
    if (r == nullptr) {
        return;
    }
    
    cout << r->data;
    PreOrderHelp(r->left_child);
    PreOrderHelp(r->right_child);
}

template <class MyType>
void BinaryTree<MyType>:: DisplayTreeeHelp(BinTreeNode<MyType> *r, int level){
    if(r != NULL)
{     DisplayTreeHelp(r->rightChild, level + 1);
    //显示右子树
    cout << endl;	                //显示新行
    for(int i = 0; i < level - 1; i++)
        cout << " ";	     //确保在第level列显示结点
    cout << r->data;	    //显示结点
    DisplayTreeHelp(r->leftChild, level + 1);
}
}

template <class MyType>
void BinaryTree<MyType>:: DisplayTree(){
    DisplayTreeHelp(root, 1);
    cout << endl;
}



template <class MyType>
void BinaryTree<MyType>::Clear(BinTreeNode<MyType> *r) {
    //后序遍历 左右根
    if (r!=nullptr) {
        Clear(r->left_child);
        Clear(r->right_child);
        delete r;
        size--;
    }
}

template <class MyType>
void BinaryTree<MyType>::DestoryBiTree() {
    Clear(root);
    root = nullptr;
}


template <class MyType>
int BinaryTree<MyType>::Leaf(BinTreeNode<MyType>*r) {
    if (r == root ) {
        return  0;
    }
    if (r->left_child ==nullptr && r->right_child ==nullptr) {
        return 1;
    }
    
    return Leaf(r->right_child) + Leaf(r->left_child);
}


template <class MyType>
int BinaryTree<MyType>::Leaf() {
    return Leaf(root);
}

template <class MyType>
int BinaryTree<MyType>::Depth(BinTreeNode<MyType>*r) {
    int l_depth;
    int r_depth;
    if (nullptr != r) {
        l_depth = Depth(r->left_child);
        r_depth = Depth(r->right_child);
    }
    
    
    return 1+(l_depth>r_depth ? l_depth : r_depth);
}

template <class MyType>
int BinaryTree<MyType>::Depth() {
    return Depth(root);
}

template <class MyType>
int BinaryTree<MyType>::Size() {
    return size;
}


template <class MyType>
int BinaryTree<MyType>::SetElem(MyType e, MyType x) {
    BinTreeNode<MyType> *p;
    p = private_Locate(root, e);
    if (p == nullptr) {
        return -1;
    }
    
    p->data = x;
    return 0;
}


//要插入的节点为e，x为要插入的节点的左节点，y为要插入的节点的右节点
template <class MyType>
int BinaryTree<MyType>::Insert_child(MyType e,MyType x, MyType y) {
    BinTreeNode<MyType> *parent, *l_child,*r_child;
    parent = private_Locate(root, e);
    
    if (parent != nullptr) {
        //为左子树初始化
        l_child = new BinTreeNode<MyType>;
        l_child->data = e;
        l_child->left_child = parent->left_child;
        l_child->right_child = nullptr;
        
        //为右子树初始化
        r_child->data = e;
        r_child->left_child = nullptr;
        r_child->right_child = parent->right_child;
        
        //插入到树中
        parent->left_child = l_child;
        parent->right_child = r_child;
        
        size += 2;
        return 1;
    }
   
    return -1;
}



template <class MyType>
int BinaryTree<MyType>::GetLeftSibling(MyType e, MyType &s) {
    BinTreeNode<MyType> *p = LeftSibling(e);
    if (p != nullptr) {
        s = p->data;
        return 1;
    }
    
    return 0;
}

template <class MyType>
BinTreeNode<MyType>* BinaryTree<MyType>::LeftSibling(MyType e) {
    BinTreeNode<MyType> *p;
    p = Parent(root, e);
    if (p != nullptr) {
        return p->left_child;
    }
    else{
        return nullptr;
    }
    
}

template <class MyType>
int BinaryTree<MyType>::GetParent(MyType e, MyType &f) {
    BinTreeNode<MyType> *p;
    p = Parent(root, e);
    if (p == nullptr) {
        return 0;
    }
    f = p->data;
    return 1;
}

template <class MyType>
BinTreeNode<MyType>* BinaryTree<MyType>::Parent(BinTreeNode<MyType>*r, MyType e) {
    BinTreeNode<MyType> *p;
    if (r == nullptr) {
        return nullptr;
    }
    
    if (r->data == e || r->data == e) {
        return r;
    }
    
    p = private_Locate(r->left_child, e);
    if (p == nullptr) {
        private_Locate(r->right_child, e);
    }
    
    return p;
}

template <class MyType>
int BinaryTree<MyType>::GetLeft(MyType e,MyType &c) {
    BinTreeNode<MyType> *p;
    p = left_child(e);
    c = p->data;
    return 1;
}

template <class MyType>
BinTreeNode<MyType>* BinaryTree<MyType>::left_child(MyType e) {
    BinTreeNode<MyType> *p = private_Locate(root, e);
    if( p == nullptr)
    {
        return nullptr;
    }
    else
        return p->left_child;
    
}

template <class MyType>
bool BinaryTree<MyType>::Locate(MyType e) {
    if (private_Locate(root, e) == nullptr) {
        return false;
    }
    return true;
}

//形参一般为根地址，返回的是该节点的指针
template <class MyType>
BinTreeNode<MyType>* BinaryTree<MyType>::private_Locate(BinTreeNode<MyType> *r, MyType e) {
    BinTreeNode<MyType> *p;
    if (r->data == e) {
        return r;
    }
    
    if (r == nullptr) {
        return nullptr;
    }
    
    p = private_Locate(r->left_child, e);
    if (p == nullptr) {
        private_Locate(r->right_child, e);
    }
    
    return p;
}


template <class MyType>
BinTreeNode<MyType> * BinaryTree<MyType>::GetRoot() {
    return root;
}


template <class MyType>
//此处的r可以看成是root，
void BinaryTree<MyType>::Creat(BinTreeNode<MyType> *r,int flag) {
    BinTreeNode<MyType> *p = new BinTreeNode<MyType>;
    //MyType x;
    cin >> p->data;
    p->left_child = p->right_child = nullptr;
    
    //x不为 '^' '#'
    if (p->data != '^' && p->data != '#') {
        if (flag == 0) {
            r->left_child = p;
        } else {
            r->right_child = p;
        }
        
        Creat(p, 0);
        Creat(p, 1);
    }
    
}




//利用递归的思想，先序输入，
//给根节点赋值，再左子树，然后右子树
template <class MyType>
void BinaryTree<MyType>::CreateBiTree() {
    
    BinTreeNode<MyType> *r = new BinTreeNode<MyType>;
    cout << "按照先序序列的顺序输入一颗二叉树。结束标志为‘＃’，空标志为‘^’"<< endl;
    cin >> r->data;

    root = r;
    size++;
    
    //当标记为0时，递归创建左子树
    Creat(r,0);
    //当标记为1时，递归创建右子树
    Creat(r,1);
    
    return;
}


template <class MyType>
void BinaryTree<MyType>::InitBiTree() {
    root = nullptr;
    size = 0;
}


#endif /* binary_tree_h */