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
        char c = '0';
        while (c != '10')
        {
            cout << endl << "1. 生成线性表.";
            cout << endl << "2. 显示线性表.";
            cout << endl << "3. 检索元素.";
            cout << endl << "10. 退出";
            cout << endl << "选择功能(1~10):";
            cin >> c;
            switch (c)
            {
                case '1':
                {
                    int saveData = 1;       //使循环进行
                    while (saveData) {
                        cout << "Input The Data of Number " << llist.Length()+1 <<": " << endl;
                        cin >> saveData;
                        llist.CreateList(saveData);
                    }
                    break;
                }
                case '2':
                    llist.Traverse();
                    break;
                case '3':
                    int wantLocateData;
                    cout << "---Input A Number That You Want To Located---" << endl;
                    cin >> wantLocateData;
                    int locatedPosition = llist.Locate(wantLocateData);
                    if(locatedPosition != -1)
                    {
                        cout << "---This Number Located on Number " << wantLocateData << endl;
                    }
                    break;
            }
        }
        return 0;
    }

