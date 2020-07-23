//
// 2020.7.20

#ifndef SUPERMARKET_STAFF_SYSTEM_H
#define SUPERMARKET_STAFF_SYSTEM_H
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structural_morphology.h"

//展示管理员的信息
int Disply_staff(struct node *head);

//删除指定管理员的信息
void delete_staff();

//修改指定管理员的信息
void change_staff();

//增加管理员
void add_staff();

//打开管理员信息文件
struct staff *readFile_staff();

//保存管理员信息
void storage_staff(struct staff* head);

//个人密码管理
void change_password();

#endif //SUPERMARKET_STAFF_SYSTEM_H
