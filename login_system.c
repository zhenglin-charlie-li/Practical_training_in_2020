//
// Created by 91601 on 2020/7/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "login_system.h"
#include "structural_morphology.h"

//从文件读登陆所需的信息
struct good *readFile2()
{
	FILE *fp = NULL;
	fp = fopen("staff.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败！");
		return NULL;
	}

	char buf[528];
	fgets(buf, 528, fp);  //跳过第一行
	fgets(buf, 528, fp);  //跳过第二行

	struct staff *head = NULL;
	head = (struct staff*)malloc(sizeof(struct staff));
	if (head == NULL)
	{
		printf("没有足够的内存！");
		return NULL;
	}
	head->next = NULL;
	struct staff *L = head;
	while (!feof(fp))
	{
		struct staff *node = NULL;
		node = (struct staff*)malloc(sizeof(struct staff));
		fscanf(fp, "%s\t%s\t%s\t%d\t%d\n", node->id, node->passward, node->name, &node->number, &node->salary);
		//printf("%d\t%s\t%lf\t%lf\t%d\t%d\n", node->number, node->name, node->cost, node->price, node->sale_number, node->stay_munber);
		L->next = node;
		L = L->next;
	}
	L->next = NULL;
	fclose(fp);
	return head->next;
}


//登陆系统
int login(int person)
{
	char passward[7];
	char id[11];
	
	if (person == 1)
	{
		printf("\n\n\n\t\t\t\t欢迎您，超级管理员\n");
		printf("\n\n\n\t\t\t请输入您的密码：");
		scanf("%s", passward);
		FILE* fp = NULL;
		fp = fopen("staff.txt", "r");
		if (fp == NULL)
		{
			printf("文件打开失败");
			return 0;
		}

		char buf[528];
		fgets(buf, 528, fp);  //跳过第一行

		struct staff *node = NULL;
		node = (struct staff*)malloc(sizeof(struct staff));
		fscanf(fp, "%s\t%s\t%s\t%d\t%d\n", node->id, node->passward, node->name, &node->number, &node->salary);
		//printf("%d\t%s\t%lf\t%lf\t%d\t%d\n", node->number, node->name, node->cost, node->price, node->sale_number, node->stay_munber);
		if (strcmp(passward, node->passward) == 0)
		{
			system("cls");  //及时清屏以美化界面 
			printf("\t\t\t\t超级管理员登陆成功\n\n\n");
			printf("\t\t\t\t欢迎您！%s\n\n",node->name);

			fclose(fp);
			return 1;
		}
		else
		{
			printf("密码错误，请重新登录\n");
			fclose(fp);
			return 0;
		}
	}
	else if (person == 2)
	{
		struct staff *head = NULL;
		head = (struct staff *)malloc(sizeof(struct staff));
		head = readFile2();
		struct staff *node = head;
		int exit = 0,pass=0;
		printf("请输入账号\n");
		scanf("%s",id);
		while (node != NULL)  //若不是表尾，则循环打印节点的数值
		{
			if (strcmp(id, node->id) == 0)
			{
				exit = 1;
				printf("请输入密码\n");
				scanf("%s", passward);
				if (strcmp(passward, node->passward)==0)
				{
					pass = 1;
				}
			}
			node = node->next;
		}
		if (exit== 0)
		{
			printf("账号不存在，请检查。\n");
			return 0;
		}
		else if (exit == 1 && pass == 0)
		{
			printf("密码错误，请检查。\n");
			return 0;
		}
		else if (exit == 1 && pass == 1)
		{
			printf("登陆成功！\n");
			return 2;
		}
	}

}
