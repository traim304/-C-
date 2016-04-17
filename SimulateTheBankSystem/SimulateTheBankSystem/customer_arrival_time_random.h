//
//  customer_arrival_time_random.h
//  SimulateTheBankSystem
//
//  Created by JacobLan on 16/4/13.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef customer_arrival_time_random_h
#define customer_arrival_time_random_h

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int* customer_arrival_time_random()
{
    int *array_customer = new int[100];
    
    for (int i = 0; i < 100; i++)
    {
        array_customer[i] = random() % 480;
    }
    
    //排序
    for (int i = 0; i < 99; i++)
        for(int j = 0; j < 99-i; j++)
        {
            if (array_customer[j] > array_customer[j+1]) {
                int tmp = 0;
                tmp = array_customer[j];
                array_customer[j] = array_customer[j+1];
                array_customer[j+1] = tmp;
            }
        }
    
    return array_customer;
}



#endif /* customer_arrival_time_random_h */
