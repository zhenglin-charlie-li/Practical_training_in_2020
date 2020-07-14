#include <stdio.h>

int mainMenu()
{
	int choice;
	printf("********************************\n");
	printf("超市信息管理系统\n");
	printf("请选择您的身份\n");
	printf("1--我是店长\n");
	printf("2--我是员工\n");
	printf("3--我是顾客\n");
	printf("0--我要退出\n");
	printf("********************************\n\n\n");
	scanf("%d", &choice);
	return choice;
}

int leaderMune()
{
	int choice_leader;
	printf("********************************\n");
	printf("店长页面\n");
	printf("请选择您的操作\n");
	printf("1--店长operation1\n");
	printf("2--店长operation2\n");
	printf("3--店长operation3\n");
	printf("4--店长operation4\n");
	printf("5--店长operation5\n");
	printf("0--退出\n");
	printf("********************************\n\n\n");
	scanf("%d", &choice_leader);
	return choice_leader;
}

int staffMune()
{
	int choice_staff;
	printf("********************************\n");
	printf("员工页面\n");
	printf("请选择您的操作\n");
	printf("1--000\n");
	printf("2--111\n");
	printf("3--222\n");
	printf("4--333\n");
	printf("********************************\n\n\n");
	scanf("%d", &choice_staff);
	return choice_staff;
}

int customerMune()
{
	int choice_customer;
	printf("********************************\n");
	printf("顾客页面\n");
	printf("请选择您的操作\n");
	printf("1--000\n");
	printf("2--111\n");
	printf("3--222\n");
	printf("4--333\n");
	printf("********************************\n\n\n");
	scanf("%d", &choice_customer);
	return choice_customer;
}