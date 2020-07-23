//
// 2020.7.20
//

#ifndef SUPERMARKET_FINANCE_SYSTEM_H
#define SUPERMARKET_FINANCE_SYSTEM_H
#include<stdio.h>
#include "structural_morphology.h"

//菜单界面
int financememu();

//今日收入
double income(double arr[]);

//今日支出
double pay(double arr[]);

//今日盈利
double gain(double arr[]);



#endif //SUPERMARKET_FINANCE_SYSTEM_H
