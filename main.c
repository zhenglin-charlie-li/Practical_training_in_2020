#include<stdio.h>
#include"finance_system.h"//财务管理系统
#include"goods_system.h"//商品管理系统
#include"login_system.h"//主菜单
#include"staff_system.h"//管理员管理系统
#include "structural_morphology.h"

void goods_inquiry();
void staff_inquiry();
void finance_inquiry();
void super_staff_menu();
void staff_menu();

#define SUPER_STAFF 1
#define STAFF 2

int main()
{
	system("color 7D");
	int choice;           //记录用户的功能选项 
	char c;
	int identity = 0;
	double finance[2] = { 0.0, 0.0 }; //income and pay
	while (1)
	{
		
		choice = main_menu();
		system("cls");  //及时清屏以美化界面 
		if (choice == 1)
		{
			
				identity = login(1);
				if (identity == 1)
				{
					
					super_staff_menu(finance);
				}
				else
				{
					printf("超级管理员系统登陆失败了！\n\n\n");
				}
			
		}
		else if (choice == 2)
		{
			
				identity = login(2);
				if (identity == 2)
				{
					
					staff_menu(finance);
				}
				else
				{
					printf("管理员系统登陆失败了！\n\n\n");
				}
			
		}
		else if (choice == 0)
		{
			system("cls");
			printf("超市管理系统欢迎再次为您服务，再见~\n");
			exit(0);
		}
		else 
		{
			printf("输入有误，请重试\n");
		}
		system("pause");
	}
	return 0;
}
//使用
void super_staff_menu(double finance[]){
	int choice = 0;
	while (choice != 4) {
		printf("\n\n\n\n\n\t\t*********************************************************\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*             欢迎来到超级管理员信息查询系统            *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*********************************************************\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                  1. 查询管理信息                      *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                  2. 查询财务信息                      *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                  3. 修改密码功能                      *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                  4. 退出当前界面                      *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*********************************************************\t\t\n\n");
		printf("请输入你的选择：\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			staff_inquiry();
			break;
		case 2:
			finance_inquiry(finance);
			break;
		case 3:
			change_password();
			break;
		case 4:
			printf("您选择了退出系统，祝您生活愉快。\n");
			exit(0);
			break;
		default:
			printf("输入无效，请确认后重新输入。\n");
		}
	}
}
void staff_menu(double finance[]){
	int choice = 0;
	while (choice != 3) {
		printf("\n\n\n\n\n\t\t*********************************************************\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*             欢迎来到普通管理员信息查询系统            *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*********************************************************\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                  1. 查询商品信息                      *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                  2. 修改密码功能                      *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*                  3. 退出当前界面                      *\t\t\n");
		printf("\t\t*                                                       *\t\t\n");
		printf("\t\t*********************************************************\t\t\n\n");
		printf("请输入你的选择：\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			goods_inquiry(finance);
			break;
		case 2:
			change_password();
			break;
		case 3:
			printf("您选择了退出系统，祝您生活愉快。\n");
			break;
		default:
			printf("输入无效，请确认后重新输入。\n");
		}
	}
}
//使用货物管理系统
void goods_inquiry(double finance[]){
	int i;
	system("pause");
	system("cls");
	i = goodsmemu();
	while (i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6)
	{
		if (i == 1)  //添加商品
		{
			system("cls");
			finance[1] +=addgoods(); //调用添加商品的函数 
			system("pause");
			system("cls");
		}
		if (i == 2) //删除商品
		{
			system("cls");
			finance[0] += delgoods(); //调用删除商品的函数 
			system("pause");
			system("cls");
		}
		if (i == 3)  //修改商品
		{
			system("cls");
			changegoods(finance); //调用修改商品的函数
			system("pause");
			system("cls");
		}
		if (i == 4)  //统计商品 
		{
			system("cls");
			sortgoods(); //调用统计商品的函数 
			system("pause");
			system("cls");
		}
		if (i == 5)  //展示商品
		{
			system("cls");
			printf("\n编号\t名称\t进价\t\t售价\t\t销量\t库存\n");
			Disply(readFile()); //调用展示商品的函数
			system("pause");
			system("cls");
		}
		if (i == 6)  //查找商品
		{
			system("cls");
			findgoods(); //调用查找商品的函数
			system("pause");
			system("cls");
		}
		i = goodsmemu();
	}
	system("cls");
	system("pause");
	printf("商品管理系统欢迎再次为您服务，再见~\n");
}
//使用管理员管理系统
void staff_inquiry(){
	int i;
	system("pause");
	system("cls");
	i = staffmemu();
	while (i == 1 || i == 2 || i == 3 || i == 4)
	{
		if (i == 1)  //添加管理员
		{
			system("cls");
			add_staff();
			system("pause");
			system("cls");
		}
		if (i == 2) //删除管理员 
		{
			system("cls");
			delete_staff();
			system("pause");
			system("cls");
		}
		if (i == 3)  //修改管理员 
		{
			system("cls");
			change_staff();
			system("pause");
			system("cls");
		}
		if (i == 4)  //展示管理员的信息 
		{
			system("cls");
			Disply_staff(readFile_staff());
			system("pause");
			system("cls");
		}
		i = staffmemu();
	}
	system("cls");
	system("pause");
	printf("管理员管理系统欢迎再次为您服务，再见~\n");
}

//使用财务管理系统
void finance_inquiry(double finance[]){
	int i;
	system("pause");
	system("cls");
	i = financememu();
	while (i == 1 || i == 2 || i == 3)
	{
		if (i == 1)  //今日收入
		{
			system("cls");
			printf("今日收入:%5lf元", income(finance));
			system("pause");
			system("cls");
		}
		if (i == 2) //今日支出 
		{
			system("cls");
			printf("今日支出:%5lf元", pay(finance));
			system("pause");
			system("cls");
		}
		if (i == 3)  //今日盈利
		{
			system("cls");
			printf("今日盈利:%5lf元", gain(finance));
			system("pause");
			system("cls");
		}
		i = financememu();
	}
	system("pause");
	system("cls");
	printf("财务管理系统欢迎再次为您服务，再见~\n");
}
