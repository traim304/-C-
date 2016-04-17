//
//  staff_worktime_random.h
//  SimulateTheBankSystem
//
//  Created by JacobLan on 16/4/13.
//  Copyright © 2016年 JacobLan. All rights reserved.
//

#ifndef staff_worktime_random_h
#define staff_worktime_random_h

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int init_staff_worktime()
{
    srandom((unsigned) time(nullptr));
    return random() % 20;
}

#endif /* staff_worktime_random_h */
