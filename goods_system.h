//
// 2020.7.20
//

#ifndef SUPERMARKET_GOODS_SYSTEM_H
#define SUPERMARKET_GOODS_SYSTEM_H
#include<stdio.h>
void saveToFile(struct goods *head, char name[]);

struct good *readFile();

int Disply(struct node *head);

//选项展示
int goodsmemu();

//商品录入
double addgoods();

//商品修改
int changegoods();

//查找商品
int findgoods();

//商品删除
double delgoods();

//商品统计
int sortgoods();



#endif //SUPERMARKET_GOODS_SYSTEM_H
