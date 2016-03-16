//
//  sq_list.h
//  28214120
//
//  Created by JacobLan on 16/3/9.
//  Copyright © 2016年 JacobLan. All rights reserved.
//
#include <iostream>
#ifndef sq_list_h
#define sq_list_h

const int OK = 1;
const int ERRO = 0;
const int OVER_FLOW = 0;
using namespace std;

// 顺序表类模板
template <class ElemType>
class SqList
{
protected:
    // 顺序表实现的数据成员:
    int count;			// 元素个数
    int maxSize;		// 顺序表最大元素个数
    ElemType *elems;	// 元素存储空间
public:
    // 顺序表的方法声明：
    void Init(int size);	// 初始化线性表
    void DestoryList();    // 销毁线性表
    int CreateList(int num); //num为表的长度（实际元素个数）
    void Clear();		// 将线性表清空
    int Length() ;	// 求线性表长度
    bool Empty() ;	// 判断线性表是否为空
    bool Full() ;	// 判断线性表是否已满
    int SetElem(int position, ElemType e);// 设置指定位置的元素值
    int GetElem(int position, ElemType &e) ;	// 求指定位置的元素
    int Locate (ElemType  e); //元素定位
    int Insert(int position,  ElemType e);// 插入元素
    int Delete(int position, ElemType &e);// 删除元素
    void Traverse() ;			// 遍历线性表
    int  CreateListOrder(int n);
    int  InsertOrder(ElemType e);
    bool isOrder();
};
// 顺序表类模板的实现部分

template <class ElemType>
int SqList<ElemType>::InsertOrder(ElemType e) {
    int orderCase;
    if (!isOrder())
    {
        return 0;
    }
    orderCase = elems[0] > elems[count-1] ? 1 : 2; //如降序，因子为1，否则为2
    switch (orderCase) {
        case 1:
        {
            int i=0;
            while (i < count) {
                if (e > elems[i]) {
                    if(Insert(i+1, e))
                        return 1;
                    else
                        return 0;
                    
                }
                else
                    i++;
                
            }
            Insert(count, e);
            break;
        }
            
        case 2:
        {
            int i=0;
            while (i < count) {
                if (e < elems[i]) {
                    if(Insert(i+1, e))
                        return 1;
                    else
                        return 0;
                    
                }
                else
                    i++;
                
            }
            Insert(count, e);
            break;

            
        }
        default:
            break;
    }
    return 1;
}

template <class ElemType>
bool SqList<ElemType>::isOrder() {
    //定义一个标记顺序的变量
    int order;
    order =  elems[1]< elems[2] ? 1 : 2;
    switch(order)
    {
    case 1:
    for (int temp = 1; temp < count; temp++) {
        if (elems[temp - 1] > elems[temp])
            return false;
            
    }
            return true;
    break;
    
    case 2:
        for (int temp = 1; temp < count; temp++) {
            if (elems[temp - 1] < elems[temp])
                return false;}
            return true;
        break;
            
    default:
            return true;
            break;
}
    return true;
}

template <class ElemType>
int SqList<ElemType>::CreateListOrder(int n) {
    int maxS;
    cout << endl << "Input maximum size: ";
    cin >> maxS;
    Init(maxS);
    int e;
    cout << endl << "输入e(e = 0时退出):";
    cin >> e;
    while (e != 0)
    {
        if(CreateList(e) == 0)
        {
            break;
        }
        cin >> e;
    }
    
    if (isOrder())
    {
        return 1;
    }
    else
    {
        cout << "---Not Order---" << endl;
        exit(2);
    }

}



template <class ElemType>
void SqList<ElemType>::SqList<ElemType>::Traverse()
{
    int i = 0;
    while (i < count) {
        cout << " " << elems[i];
        i++;
    }
}



template <class ElemType>
int SqList<ElemType>::Delete(int position, ElemType &e)
{
    if (position < 1 || position >
        count) {
        return ERRO;
    }

    e = elems[position-1];
    for (int i = position-1; i < count; i++)
    {
        elems[i] = elems[i+1];
    }
    count--;
    return OK;
}

template <class ElemType>
int SqList<ElemType>::Insert(int position,  ElemType e)
{
    if (Full())
    {
        return OVER_FLOW;
    }
        
    if (position < 1 || position > count) {
        return ERRO;
    }
    
    for (int i = count; i > position-1; i--) {
        elems [i] = elems[i-1];
        
    }
    elems[position-1] = e;
    count++;
    return OK;
}

template <class ElemType>
int SqList<ElemType>::Locate (ElemType  e)
{
    int i = 0;
    while (elems[i] != e && i < count) {
        i++;
    }
    if(i == count)
    {
        return -1;
    }
    else
    return i+1;
}

template <class ElemType>
int SqList<ElemType>::GetElem(int position, ElemType &e)
{
    if (position < 1 || position > count) {
        return ERRO;
    }
    
    e = elems[position - 1];
    return OK;
}


template <class ElemType>
int SqList<ElemType>::SetElem(int position, ElemType e)
{
    if (position < 1 || position > count) {
        return ERRO;
    }
    
    elems[position - 1] = e;
    return OK;
}


template <class myType>
bool SqList<myType>::Empty()
{
    return count?false:true;
}



template <class myType>
bool SqList<myType>::Full()
{
    return count==maxSize?true :false;
}



template <class myType>
int SqList<myType>::Length()
{
    return count;
}


template <class myType>
void SqList<myType>::Clear()
{
    count = 0;
}



template <class myType>
int SqList<myType>::CreateList(int num)
{
    if (Full()) {
        return ERRO;
    }
    
    elems[count] = num;
    count++;
    return OK;
}



template <class myType>
void SqList<myType>::DestoryList()
{
    delete [] elems;
}




template <class myType>
void SqList<myType>::Init(int size)
{
    count = 0;
    maxSize = size;
    if ( nullptr != elems)
    {
        delete[] elems;
    }
    else
        elems = new myType[size];
}



#endif /* sq_list_h */
















