#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "page_leader.h"
#include "page_staff.h"
#include "page_customer.h"

#define MAX_stdin 7

struct admin
{
	char account_number[MAX_stdin];       //账号
	char account_password[MAX_stdin];	  //密码
	char name[MAX_stdin];                 //用户名，姓名
	int staff_code;                       //员工编号
	int sale_number;                      //销售数量
	double sale_price;                    //销售金额
	double salary_basic;                  //基本工资

	double salary_percentage;             //提成工资
}admin;

struct staff
{
	char account_number[MAX_stdin];       //账号
	char account_password[MAX_stdin];	  //密码
	char name[MAX_stdin];                 //用户名，姓名
	int staff_code;                       //员工编号
	int sale_number;                      //销售数量
	double sale_price;                    //销售金额
	double salary_basic;                  //基本工资

	double salary_percentage;             //提成工资
	int department_code;                  //部门编号
	int post_code;                        //岗位编号
}staff;


struct customer
{
	char account_number[MAX_stdin];       //账号
	char account_password[MAX_stdin];	  //密码
	char name[MAX_stdin];                 //用户名，姓名
	int customer_code;                    //顾客编号
	int consumption_number_in_total;      //总购买数量
	double consumption_price_in_total;    //总购买金额
	int  bonus_points;                    //目前积分

	
}customer;

struct goods
{
	int goods_code;                        //商品编号
	int sale_number_in_total;              //商品总销售数量
	int type_code;                         //类型编号
	double price_in;                       //进货价格
	double price_out;                      //售出价格
}goods;

int main()
{
	
	int choice;
	do
	{
		show_mainMenu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
		{
				  printf("已退出系统");
				  break;
		}
		case 1:
		{
				  //店长页面
				  system("cls");  //及时清屏以美化界面 
				  int choice_eachPage;
				  securityCheck_admin();
				  do{
					  show_adminMenu();
					  scanf("%d", &choice_eachPage);
					  operation_admin(choice_eachPage);
				  } while (choice_eachPage);
				  break;
		}
		case 2:
		{
				  //员工页面
				  int choice_eachPage;
				  do{
					  show_staffMenu();
					  scanf("%d", &choice_eachPage);
					  operation_staff(choice_eachPage);
				  } while (choice_eachPage);
				  break;
		}
		case 3:
		{
				  //顾客页面
				  int choice_eachPage;
				  do{
					  show_customerMenu();
					  scanf("%d", &choice_eachPage);
					  operation_customer(choice_eachPage);
				  } while (choice_eachPage);
				  break;
		}
		default:
		{
				   printf("ERROR, 请输入正确的选项\n");
				   break;
		}
		}
	} while (choice);
	return 0;
}