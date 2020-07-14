#include <stdio.h>
#include "menu.h"
#include "page_leader.h"
#include "page_staff.h"
#include "page_customer.h"

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
				  printf("即将退出系统");
				  break;
		}
		case 1:
		{
				  //店长页面
				  int choice_eachPage;
				  do{
					  show_leaderMune();
					  scanf("%d", &choice_eachPage);
					  operation_leader(choice_eachPage);
				  } while (choice_eachPage);
				  break;
		}
		case 2:
		{
				  //员工页面
				  int choice_eachPage;
				  do{
					  show_staffMune();
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
					  show_customerMune();
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