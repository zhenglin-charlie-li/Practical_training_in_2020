#include <stdio.h>
#include "menu.h"
#include "page_leader.h"

int main()
{
	int choice;
	do
	{
		choice = mainMenu();
		switch (choice)
		{
		case 0:
		{
				  break;
		}
		case 1:
		{
				  //case 1 code
				  int choice_leader;
				  do{
					  choice_leader = leaderMune();
					  operation_leader(choice_leader);
				  } while (choice_leader);
				  break;
		}
		case 2:
		{
				  //case 2 code
				  printf("case 2, do something\n");
				  int choice_staff = staffMune();
				  break;
		}
		case 3:
		{
				  //case 3 code
				  printf("case 3, do something\n");
				  int choice_customer = customerMune();
				  break;
		}
		case 4:
		{
				  //case 4 code
				  printf("即将退出系统，欢迎下次使用\n");
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