//
// Created by 91601 on 2020/7/19.
//
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include"staff_system.h"

#include "structural_morphology.h"

#define  STAFF sizeof(struct staff)


//展示管理员的信息
int Disply_staff(struct staff *head)
{
	struct staff *node = head;
	int i = 0;
	while (node != NULL)  //若不是表尾，则循环打印节点的数值
	{
		printf("%s\t%s\t%s\t%d\t\t%d\n", node->id, node->passward, node->name, node->number, node->salary);
		node = node->next;  //让p指向下一个节点
		i++;//计数器
	}
	return i;    //返回的是有多少个结点
}

//打开管理员信息文件
struct staff *readFile_staff()
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

//保存管理员信息
void storage_staff(struct staff* head)
{
	FILE* fp = NULL;
	fp = fopen("staff.txt", "w+");
	fprintf(fp, "账号\t密码\t姓名\t岗位编号\t工资\n");
	struct staff *node = head;
	while (node != NULL)  //若不是表尾，则循环打印节点的数值
	{
		fprintf(fp, "%s\t%s\t%s\t%d\t%d\n", node->id, node->passward, node->name, node->number, node->salary);
		node = node->next;  //让p指向下一个节点
	}
	fclose(fp);
}

//增加管理员
void add_staff()
{
	printf("你想新增管理员吗？\n");
	printf("1--是， 0--否\n");
	int choice;
	scanf("%d", &choice);
	while (choice == 1)
	{
		printf("请输入管理员账号");
		char id[11];
		scanf("%s", id);

		int exit = 0;//管理员是否存在
		struct staff * head = readFile_staff();
		struct staff *index = NULL;
		index = (struct staff *)malloc(sizeof(struct staff));
		if (index == NULL)
		{
			printf("没有足够的内存！");
			return 0;
		}
		index = head;
		while (index->next != NULL)
		{
			if (strcmp(index->id, id) == 0)
			{
				exit = 1;
			}
			if (strcmp(index->next->id, id) == 0)
			{
				exit = 1;
			}
			index = index->next;
		}

		if (exit == 1)
		{
			printf("你想新增的管理员账号已经存在\n");
		}
		else
		{
			struct staff *new = NULL;
			new = (struct staff *)malloc(sizeof(struct staff));
			strcpy(new->id, id);
			printf("请输入要新增的管理员密码：  ");
			scanf("%s", new->passward);
			printf("请输入要新增的管理员姓名：  ");
			scanf("%s", new->name);
			printf("请输入要新增的管理员岗位编号：  ");
			scanf("%d", &new->number);
			printf("请输入要新增的管理员工资：  ");
			scanf("%d", &new->salary);
			new->next = NULL;
			index->next = new;
			printf("\n账号\t密码\t姓名\t岗位编号\t工资\n");
			Disply_staff(new);
			printf("新增管理员成功!\n");
			storage_staff(head, "goods.txt");
		}

		printf("你还想继续新增管理员吗？\n");
		printf("1--是， 0--否\n");
		scanf("%d", &choice);
	}
	printf("正在退出新增管理员\n");
}

//删除指定管理员的信息
void delete_staff()
{
	printf("你想删除管理员吗？\n");
	printf("1--是， 0--否\n");
	int choice;
	scanf("%d", &choice);
	while (choice == 1)
	{
		printf("请输入想删除的管理员的账号\n");
		char id[11];
		scanf("%s", id);
		struct staff *currtentNode = NULL;
		currtentNode = (struct staff *)malloc(sizeof(struct staff));
		struct staff *lastNode = NULL;
		lastNode = (struct staff *)malloc(sizeof(struct staff));

		int exit = 0;//账号是否存在
		struct staff *head = readFile_staff();
		struct staff *index = NULL;
		index = (struct staff *)malloc(sizeof(struct staff));
		if (index == NULL)
		{
			printf("没有足够的内存！");
			return 0;
		}
		index = head;
		while (index->next != NULL)
		{
			if (strcmp(index->id, id) == 0)
			{
				lastNode = index;
			}
			if (strcmp(index->next->id, id) == 0)
			{
				exit = 1;
				currtentNode = index->next;
			}
			index = index->next;
		}

		if (exit == 0)
		{
			printf("你想删除的管理员的账号不存在\n");
		}
		else
		{
			printf("你确定删除下述管理员账号？\n1--确定 0--退出\n\n");
			printf("\n账号\t密码\t姓名\t岗位编号\t\t工资\n");
			printf("%s\t%s\t%s\t%d\t%d\n", currtentNode->id, currtentNode->passward, currtentNode->name, currtentNode->number, currtentNode->salary);
			int a;
			scanf("%d", &a);
			if (a == 1)
			{
				lastNode->next = currtentNode->next;
				printf("删除管理员成功!\n");
				storage_staff(head);
			}
			else
			{
				printf("删除管理员失败!\n");
			}
		}
		printf("你还想继续删除管理员吗？\n");
		printf("1--是， 0--否\n");
		scanf("%d", &choice);
	}
	printf("正在退出删除管理员\n");
}

//修改指定管理员的信息
void change_staff()
{
	printf("你想修改管理员吗？\n");
	printf("1--是， 0--否\n");
	int choice;
	scanf("%d", &choice);
	while (choice == 1)
	{
		printf("请输入管理员的账号");
		char id[11];
		scanf("%s", id);
		struct staff *currtentNode = NULL;
		currtentNode = (struct staff *)malloc(sizeof(struct staff));

		int exit = 0;//管理员是否存在
		struct staff *head = readFile_staff();
		struct staff *index = NULL;
		index = (struct staff *)malloc(sizeof(struct staff));
		if (index == NULL)
		{
			printf("没有足够的内存！");
			return 0;
		}
		index = head;
		while (index->next != NULL)
		{
			if (strcmp(index->id, id) == 0)
			{
				exit = 1;
				currtentNode = index;
			}
			index = index->next;
		}

		if (exit == 0)
		{
			printf("你想修改的管理员的账号不存在\n");
		}
		else
		{
			printf("\n账号\t密码\t姓名\t岗位编号\t工资\n");
			printf("%s\t%s\t%s\t%d\t%d\n", currtentNode->id, currtentNode->passward, currtentNode->name, currtentNode->number, currtentNode->salary);
			printf("请选择你要修改的选项\n");
			printf("1--账号\t2--姓名\t3--职位编号\t4--工资\n");
			int choice2;
			scanf("%d", &choice2);
			switch (choice2)
			{
			case 1:
			{
					  char id1[7];
					  int i = 0;
					  printf("请输入修改后管理员账号：  ");
					  scanf("%s", id1);
					  do
					  {
						  i = 0;
						  index = head;
						  while (index->next != NULL)
						  {
							  if (strcmp(index->id, id1) == 0)
							  {
								  i = 1;
								  printf("%s和现有管理员账号重复，请重新输入!", id1);
								  scanf("%s", id1);
							  }
							  index = index->next;
						  }
					  } while (i);
					  strcpy(currtentNode->id, id1);
					  break;
			}
			case 2:
			{
					  printf("请输入修改后的管理员姓名：  ");
					  scanf("%s", currtentNode->name);
					  break;
			}
			case 3:
			{
					  printf("请输入修改后的管理员职位编号：  ");
					  scanf("%d", &currtentNode->number);
					  break;
			}
			case 4:
			{
					  printf("请输入修改后的管理员职位工资");
					  scanf("%d", &currtentNode->salary);
					  break;
			}
			}
			printf("修改管理员信息成功!\n");
			printf("\n账号\t密码\t姓名\t岗位编号\t工资\n");
			printf("%s\t%s\t%s\t%d\t\t%d\n", currtentNode->id, currtentNode->passward, currtentNode->name, currtentNode->number, currtentNode->salary);
			storage_staff(head);
		}

		printf("你还想继续修改管理员信息吗？\n");
		printf("1--是， 0--否\n");
		scanf("%d", &choice);
	}
	printf("正在退出修改管理员信息\n");
}

//个人密码管理
void change_password()
{
	printf("请输入您的的账号");
	char id[11];
	scanf("%s", id);
	struct staff *currtentNode = NULL;
	currtentNode = (struct staff *)malloc(sizeof(struct staff));
	int exit = 0;//管理员是否存在
	struct staff *head = readFile_staff();
	struct staff *index = NULL;
	index = (struct staff *)malloc(sizeof(struct staff));
	if (index == NULL)
	{
		printf("没有足够的内存！");
		return 0;
	}
	index = head;
	while (index->next != NULL)
	{
		if (strcmp(index->id, id) == 0)
		{
			exit = 1;
			currtentNode = index;
		}
		index = index->next;
	}

	if (exit == 0)
	{
		printf("你想修改的管理员的账号不存在\n");
	}
	else
	{
		printf("请输入您的的密码\n");
		char password[7];
		scanf("%s", password);
		if (strcmp(password, currtentNode->passward) == 0)
		{

			printf("\n账号\t密码\t姓名\t岗位编号\t工资\n");
			printf("%s\t%s\t%s\t%d\t\t%d\n", currtentNode->id, currtentNode->passward, currtentNode->name, currtentNode->number, currtentNode->salary);

			printf("请输入修改后的密码\n");
			char passward1[7];
			scanf("%s", passward1);
			printf("请再次输入修改后的密码以确认\n");
			char passward2[7];
			scanf("%s", passward2);
			if (strcmp(passward1, passward2) == 0)
			{
				strcpy(currtentNode->passward, passward1);
				printf("修改管理员信息成功!\n");
				printf("\n账号\t密码\t姓名\t岗位编号\t工资\n");
				printf("%s\t%s\t%s\t%d\t\t%d\n", currtentNode->id, currtentNode->passward, currtentNode->name, currtentNode->number, currtentNode->salary);
				storage_staff(head);
			}
			else
			{
				printf("两次密码不一样！请检查\n");
			}
		}
		else
		{
			printf("密码错误！");
		}
	}
	printf("正在退出修改管理员信息\n");
}






