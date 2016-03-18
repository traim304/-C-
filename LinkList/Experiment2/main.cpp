//
//  main.cpp
//  Experiment2
//
//  Created by JacobLan on 16/3/15.
//  Copyright © 2016年 JacobLan. All rights reserved.
//


#include <iostream>
#include "link_list.h"	// 单链表类

    
int main(void)
    {
        LinkList<int> llist;
        llist.Init();
        int c = 0 ;
        while (c != 12)
        {
            cout << endl << "1. 生成线性表.";
            cout << endl << "2. 显示线性表.";
            cout << endl << "3. 检索元素.";
            cout << endl << "4.清空线性表.";
            cout << endl << "5.销毁线性表.";
            cout << endl << "6.求线性表长度.";
            cout << endl << "7.判断线性表是否为空.";
            cout << endl << "8.修改指定元素的值.";
            cout << endl << "9.返回指定元素的值.";
            cout << endl << "10.插入元素到制定位置.";
            cout << endl << "11.删除指定位置的元素.";
            cout << endl << "12. 退出";
            cout << endl << "选择功能(1~12):";
            cin >> c;
            switch (c)
            {
                case 1:
                {
                    int saveData = 1;       //使循环进行
                    while (saveData) {
                        cout << "Input The Data of Number " << llist.Length()+1 <<": " << endl;
                        cin >> saveData;
                        if (saveData == 0) {
                            break;
                        }
                        else{
                            llist.CreateList(saveData);
                        }
                        
                    }
                    break;
                }
                case 2:
                {
                    llist.Traverse();
                    break;
                }
                    
                case 3:
                {
                    int wantLocateData;
                    cout << "---Input A Number That You Want To Located---" << endl;
                    cin >> wantLocateData;
                    int locatedPosition = llist.Locate(wantLocateData);
                    if(locatedPosition != -1)
                    {
                        cout << "---This Number Located on Number " << locatedPosition << " ---" << endl;
                    }
                    break;
                }
                    
                case 4:
                {
                    cout << "---Are You Sure ?---" << endl;
                    char confirm;
                    cin >> confirm;
                    if (confirm == 'y' || confirm == 'Y') {
                        llist.Clear();
                        cout << "---Done---";
                    }
                    break;
                }
                    
                    
                case  5:
                {
                    cout << "---Are You Sure ?---" << endl;
                    char confirm;
                    cin >> confirm;
                    if (confirm == 'y' || confirm == 'Y') {
                        llist.DestoryList();
                        cout << "---Done---" << endl;
                    }
                    break;
                    
                }
                    
                case 6:
                {
                    cout << "---This LinkList have " << llist.Length() << " members---" << endl;
                    break;
                }
                    
                case 7:
                {
                    if (llist.isEmpty()) {
                        cout << "---Empty---" << endl;
                        break;
                    }
                    else
                    {
                        cout << "---Not Empty---" << endl;
                        break;
                    }
                }
                    
                case 8:
                {
                    cout << "---Where Would You Like To Modify ?---" << endl;
                    int willSetPosition;
                    cin >> willSetPosition;
                    cout << "---Input The Value After You Modify---" << endl;
                    int willSetValue;
                    cin >> willSetValue;
                    llist.SetElem(willSetPosition, willSetValue);
                    break;
                }
                    
                case 9:
                {
                    cout << "---Which Item That You Feel Like To Get Value ?---" << endl;
                    int willGetPosition;
                    cin >> willGetPosition;
                    int saveGetData;
                    if (llist.GetElem(willGetPosition, saveGetData) == -1)
                    {
                        break;
                    }
                    cout << "---Return Value is " << saveGetData << " ---" << endl;
                    break;
                }
                    
                case 10:
                {
                    cout << "---Where Do You Want To Insert Element?---" << endl;
                    int insertPosition;
                    cin >> insertPosition;
                    cout << "---Input The Value Of This Element---" << endl;
                    int insertValue;
                    cin >> insertValue;
                    if (llist.Insert(insertPosition, insertValue) != -1)
                    {
                        cout << "---Done---" << endl;
                        break;
                    }
                    else
                    {
                        break;
                    }
                    
                }
                    
                case 11:
                {
                    cout << "---Which Position Do You Want to Delete?---" << endl;
                    int willDeletePosition;
                    cin >> willDeletePosition;
                    int saveDeletedValue = -999;
                    if (llist.Delete(willDeletePosition, saveDeletedValue) != -1)
                    {
                        cout << "---SUCCESS DELETE NUMBER " << willDeletePosition << " AND  VALUE IS " << saveDeletedValue << "---" << endl;
                        break;
                    }
                    
                    break;
                    
                }
            }
        }
        return 0;
    }

