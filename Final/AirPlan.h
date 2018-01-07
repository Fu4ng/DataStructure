//
// Created by Fu4ng on 2018/1/7.
//

#ifndef FINAL_AIRPLAN_H
#define FINAL_AIRPLAN_H

#include <string>

using namespace std;
#endif //FINAL_AIRPLAN_H
typedef struct Passenger{ //乘客
    string name;
};
typedef struct booking{  //订单
    int num;
    Passenger pas;
    booking *next;
};
typedef struct waitQueue{ //候补乘客
    Passenger pas;
    waitQueue *next;
};
typedef struct AirLine{
    string  finalSite; //终点站名
    string  flight;  //航班名
    string  model;   //机型
    int flyAcount;  //飞行周目
    int bookingAcount; //订票量
    int maxPassenger;  //成员定额
    booking *bookdone; //已订单的乘客
    waitQueue *wait;   //等待候补

};