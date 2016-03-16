//
//  main.cpp
//  28214120
//
//  Created by JacobLan on 16/3/9.
//  Copyright © 2016年 JacobLan. All rights reserved.
//


#include "sq_list.h"

int main(void)
{
    SqList<int> sl;
    int c = 0;
    while (c != '13')
    {
        cout << endl << "1. 生成线性表.";
        cout << endl << "2. 显示线性表.";
        cout << endl << "3. 检索元素.";
        cout << endl << "4.是否为空？";
        cout << endl << "5.是否为满？";
        cout << endl << "6.返回该位置的值。";
        cout << endl << "7.插入元素";
        cout << endl << "8.删除元素";
        cout << endl << "9.遍历";
        cout << endl << "10.清空";
        cout << endl << "11.销毁";
        cout << endl << "12.创建顺序表";
        cout << endl << "13. 按顺序插入";
        cout << endl << "14.退出" << endl;
        cout << endl << "选择功能(1~14):";
        cin >> c;
        switch (c)
        {
            case 1:
                int maxS;
                cout << endl << "Input maximum size: ";
                cin >> maxS;
                sl.Init(maxS);
                int e;
                cout << endl << "输入e(e = 0时退出):";
                cin >> e;
                while (e != 0)
                {
                    if(sl.CreateList(e) == 0)
                    {
                        break;
                    }
                    cin >> e;
                }
                break;
            case 2:
                sl.Traverse();
                break;
            case 3:
                int wantValue;
                cout << "Which value do you want to find out?" << endl;
                cin >> wantValue;
                int result;
                result = sl.Locate(wantValue);
                if (-1 == result)
                {
                     cout << "---NO THIS ITEM---" << endl;
                }
                else
                {
                    cout << "这是第 " << result << " 个元素！！" << endl;
                }
                break;
                
            case 4:
                if (true == sl.Empty()) {
                    cout << "---Is Empty---" << endl;
                    break;
                }
                cout << "---Not Empty---" << endl;
                break;
                
            case 5:
                if (true == sl.Full()) {
                    cout << "---Is Full---" << endl;
                    break;
                }
                
                cout << "---Not Full---" << endl;
                break;

                
            case 6:
                int getPosition;
                cout << "取出第几个数？" << endl;
                cin >> getPosition;
                int saveData;
                if (sl.GetElem(getPosition, saveData) == 0)
                {
                    cout <<"---Illegal data---" << endl;
                    break;
                }
                cout << "取出的值为 " << saveData << endl;
                break;
                
            case 7:
                int insertPosition;
                cout << "在第几个位置插入？" << endl;
                cin >> insertPosition;
                cout << "输入值：" << endl;
                int insertValue;
                cin >> insertValue;
                if (!sl.Insert(insertPosition, insertValue))
                {
                    cout << "---Illegal Value!!---" << endl;
                }
                else{
                    sl.Traverse();
                }
                break;
                
            case 8:
                int delPosition;
                cout << "将要删除第几个元素？" << endl;
                cin >> delPosition;
                int tempValue;
                if (!sl.Delete(delPosition, tempValue))
                {
                    cout << "---Illegal Value!!---" << endl;
                }
                
                cout << "---Done! delete " << tempValue << " Success---" << endl;
                break;
                
            case 9:
                sl.Traverse();
                break;
                
            case 10:
                char confirm;
                cout << "---Are You Sure?<Y/N>---";
                cin >> confirm;
                if (confirm == 'n' || confirm == 'N') {
                    break;
                }
                sl.Clear();
                cout << "---Done---" << endl;
                break;
                
            case 11:
                char isSure;
                cout << "---Are You Sure?<Y/N>---";
                cin >> confirm;
                if (isSure == 'n' || isSure == 'N') {
                    break;
                }
                sl.DestoryList();
                cout << "---Done---" << endl;
                break;

            case 12:
                sl.CreateListOrder(0);
                
                break;
                
            case 13:
            {
                int InsertValue;
                cin >> InsertValue;
                if(sl.InsertOrder(InsertValue))
                    cout << "---Done---" << endl;
                else
                    cout << "---Error---" << endl;
                
                break;
            }
            case 14:
                exit(1);
                
            default:
                break;
        }
    }
    }
