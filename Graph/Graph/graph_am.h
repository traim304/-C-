//
//  graph_am.h
//  Graph
//
//  Created by JacobLan on 16/5/10.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef graph_am_h
#define graph_am_h
#include "ver_am.h"

#include "veram.h"
template <class ElemType>
class GraphAM
{
protect:
    int  size;  //图的容量，即最大顶点数
    int verNum, edgeNum; //当前的顶点数和边数
    int kind; //图的类型，0无向图，1有向图，2无向网，3有向网
    char  *vertex ;            //顶点元素表
　   int  **edge ;       //存放边／弧的邻接矩阵
    
    void InitGraph(int k, int n);
    void Clear( );
    void DestoryGraph( );
    void CreateGraph();
    int LocateVer(ElemType e);
    int InsertVer(ElemType e);
    int InsertEdge(ElemType s, ElemType e);
    int InsertEdge( ElemType s, ElemType e, int w);
    void DeleteEdge(ElemType s, ElemType e);
    void DeleteVer(ElemType e);
    int SetElem(Elemtype e, ElemType x);
    int FirstAdjVer(ElemType  e);
    int FirstAdjVer(int pos,int s);
    int NextAdjVer(int v, int pos);
    int EdgeExsit (ElemType s, ElemType e);
    int SetWeight( ElemType s, ElemType e, int w);
    void Display();//显示邻接矩阵
    void TraverseDFS(int start) //深度优先遍历
    int DFS(int s, int tag[])//private
    void BFS( int start) //广度优先遍历
private:
    void Input_edge();
};

template <class MyType>
void Clear() {
    for (int i = 0; i != 10; i++) {
        for (int j = 0; j != 10; j++) {
            vertex[i][j] = 0;
        }
    }
}

template <class MyType>
void  Input_edge() {
    for (int i =0; i != size; i++) {
        for (int j = 0; j != size; j++) {
            vertex[i][j]
        }
    }
}

template <class MyType>
void  Graph<MyType>::InitGraph(int k, int n) {
    cout << "图的类型? (0无向图，1有向图，2网)" << endl;
    //判断kind是否有效
    while(cin >> kind)
    {
        if (kind!= 0 && kind!= 1 && kind != 2) {
            cout << "ARE YOU KIDDING ME ?" << endl;
            continue;
        }
        break;
    }
    
    cout << "该图的顶点数为？" << endl;
    cin >> size;
    int verNum = 0;
    int edgeNum =0;
    vertex = new char[size];
}

template <class MyType>
void Graph<MyType>::CreateGraph() {
    InitGraph();
    cout << "依次输入节点的字符."<< endl;
    char tmp_char;
    int i = 0;
    while (cin >> tmp_char) {
        vertex[i] = tmp_char;
    }
    
    //给邻接矩阵赋值
    vertex = new int*[size];
    for (int i = 0; i!=10; i++) {
        vertex[i] = new int[size];
    }
    
    cout << "输入每个节点对外的联通性";
    switch (kind) {
            case 0:
                {
                    //无向图
                    cout << "(不联通：0 联通:1)" << endl;
                    Input_edge();
                    break;
                }
         
            case 1:
                {
                    //有向图
                    cout << "(联通:0 不联通:1)" << endl;
                    Input_edge();
                    break;
                }
        
            case 2:
                {
                    //网
                    cout << "(不联通:0 联通:权值)" << endl;
                    Input_edge();
                    break;
                }
        default:
            break;
    }
    
}

















#endif /* graph_am_h */
