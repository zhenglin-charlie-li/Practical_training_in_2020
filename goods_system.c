//
// Created by 91601 on 2020/7/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "goods_system.h"

#include "structural_morphology.h"

#define GOODS sizeof(struct goods)

int Disply(struct goods *head)
{
	struct goods *node = head;
	int i = 0;
	while (node != NULL)  //若不是表尾，则循环打印节点的数值
	{
		printf("%d\t%s\t%lf\t%lf\t%d\t%d\n", node->number, node->name, node->cost, node->price, node->sale_number, node->stay_number);
		node = node->next;  //让p指向下一个节点
		i++;//计数器
	}
	return i;    //返回的是有多少个结点
}

struct good *readFile()
{
	FILE *fp = NULL;
	fp = fopen("goods.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败！");
		return NULL;
	}

	char buf[528];
	fgets(buf, 528, fp);  //跳过第一行

	struct goods *head = NULL;
	head = (struct goods*)malloc(sizeof(struct goods));
	if (head == NULL)
	{
		printf("没有足够的内存！");
		return NULL;
	}
	head->next = NULL;
	struct goods *L = head;
	while (!feof(fp))
	{
		struct goods *node = NULL;
		node = (struct goods*)malloc(sizeof(struct goods));
		fscanf(fp, "%d\t%s\t%lf\t%lf\t%d\t%d\n", &node->number, node->name, &node->cost, &node->price, &node->sale_number, &node->stay_number);
		//printf("%d\t%s\t%lf\t%lf\t%d\t%d\n", node->number, node->name, node->cost, node->price, node->sale_number, node->stay_munber);
		L->next = node;
		L = L->next;
	}
	L->next = NULL;

	fclose(fp);
	return head->next;
}

void saveToFile(struct goods *head, char name[])
{
	FILE* fp = NULL;
	fp = fopen(name, "w+");
	fprintf(fp, "编号\t名称\t进价\t售价\t销量\t库存\n");
	struct goods *node = head;
	while (node != NULL)  //若不是表尾，则循环打印节点的数值
	{
		fprintf(fp, "%d\t%s\t%lf\t%lf\t%d\t%d\n", node->number, node->name, node->cost, node->price, node->sale_number, node->stay_number);
		node = node->next;  //让p指向下一个节点
	}
	fclose(fp);
}

//查找商品
int findgoods()
{
	int choice=1;
	while (choice == 1)
	{
		printf("请输入想查找的商品的编号\n");
		int number;
		scanf("%d", &number);

		int exit = 0;//商品是否存在
		struct goods *head = readFile();
		struct goods *index = NULL;
		index = (struct goods *)malloc(sizeof(struct goods));
		struct goods *currtentNode = NULL;
		currtentNode = (struct goods *)malloc(sizeof(struct goods));
		if (index == NULL)
		{
			printf("没有足够的内存！");
			return 0;
		}
		index = head;
		while (index->next != NULL)
		{
			if (index->number == number)
			{
				currtentNode = index;
				exit = 1;
			}
			index = index->next;
		}
		if (exit == 0)
		{
			printf("你想查找商品的商品不存在\n");
			return 0;
		}
		else
		{
			printf("你想查找商品的商品存在\n");
			printf("\n编号\t名称\t进价\t\t售价\t\t销量\t库存\n");
			printf("%d\t%s\t%lf\t%lf\t%d\t%d\n", currtentNode->number, currtentNode->name, currtentNode->cost, currtentNode->price, currtentNode->sale_number, currtentNode->stay_number);
			return 1;
		}
		printf("你还想继续查找商品吗？\n");
		printf("1--是， 0--否\n");
		scanf("%d", &choice);
	}
	printf("退出查找商品\n");
}

//商品录入
double addgoods()
{
	double pay = 0.0;
	printf("你想新增商品吗？\n");
	printf("1--是， 0--否\n");
	int choice;
	scanf("%d", &choice);
	while (choice == 1)
	{
		printf("请输入商品的编号");
		int number;
		scanf("%d", &number);

		int exit = 0;//商品是否存在
		struct goods *head = readFile();
		struct goods *index = NULL;
		index = (struct goods *)malloc(sizeof(struct goods));
		if (index == NULL)
		{
			printf("没有足够的内存！");
			return 0;
		}
		index = head;
		while (index->next != NULL)
		{
			if (index->number == number)
			{
				exit = 1;
			}
			if (index->next->number == number)
			{
				exit = 1;
			}
			index = index->next;
		}

		if (exit == 1)
		{
			printf("你想新增商品的商品编号已经存在\n");
		}
		else
		{
			struct goods *new = NULL;
			new = (struct goods *)malloc(sizeof(struct goods));
			new->number = number;
			printf("请输入商品名称：  ");
			scanf("%s", new->name);
			printf("请输入商品进价：  ");
			scanf("%lf", &new->cost);
			printf("请输入商品售价：  ");
			scanf("%lf", &new->price);
			printf("请输入商品进货量（库存量）：  ");
			scanf("%d", &new->stay_number);
			new->sale_number = 0;
			new->next = NULL;
			index->next = new;
			printf("\n编号\t名称\t进价\t\t售价\t\t销量\t库存\n");
			Disply(new);
			printf("新增商品成功!\n");
			saveToFile(head, "goods.txt");
			pay += new->cost*new->stay_number;
		}

		printf("你还想继续新增商品吗？\n");
		printf("1--是， 0--否\n");
		scanf("%d", &choice);
	}
	printf("退出新增商品\n");
	return pay;//返回值是花费了多少钱
}

//商品修改
int changegoods(double arr[])
{
	printf("你想修改商品吗？\n");
	printf("1--是， 0--否\n");
	int choice;
	scanf("%d", &choice);
	while (choice == 1)
	{
		printf("请输入商品的编号");
		int number;
		scanf("%d", &number);
		struct goods *currtentNode = NULL;
		currtentNode = (struct goods *)malloc(sizeof(struct goods));

		int exit = 0;//商品是否存在
		struct goods *head = readFile();
		struct goods *index = NULL;
		index = (struct goods *)malloc(sizeof(struct goods));
		if (index == NULL)
		{
			printf("没有足够的内存！");
			return 0;
		}
		index = head;
		while (index->next != NULL)
		{
			if (index->number == number)
			{
				exit = 1;
				currtentNode = index;
			}
			index = index->next;
		}

		if (exit == 0)
		{
			printf("你想修改商品的商品不存在\n");
		}
		else
		{
#if(0)
			printf("请输入修改后商品编号：  ");
			scanf("%d", &currtentNode->number);
			printf("请输入修改后商品名称：  ");
			scanf("%s", currtentNode->name);
			printf("请输入修改后商品进价：  ");
			scanf("%lf", &currtentNode->cost);
			printf("请输入修改后商品售价：  ");
			scanf("%lf", &currtentNode->price);
			printf("请输入修改后商品的销售量：  ");
			scanf("%lf", &currtentNode->sale_number);
			printf("请输入修改后商品的库存量：  ");
			scanf("%d", &currtentNode->stay_munber);
#endif
			printf("\n编号\t名称\t进价\t售价\t销量\t库存\n");
			printf("%d\t%s\t%lf\t%lf\t%d\t%d\n", currtentNode->number, currtentNode->name, currtentNode->cost, currtentNode->price, currtentNode->sale_number, currtentNode->stay_number);
			printf("请选择你要修改的选项\n");
			printf("1--编号\t2--名称\t3--售价\n");
			printf("4--商品数量的变化，+代表进货，-代表售出\n");
			int choice2;
			scanf("%d", &choice2);
			switch (choice2)
			{
			case 1:
			{
					  int number1;
					  int i = 0;
					  printf("请输入修改后商品编号：  ");
					  scanf("%d", &number1);
					  do
					  {
						  i = 0;
						  index = head;
						  while (index->next != NULL)
						  {
							  if (index->number == number1)
							  {
								  i = 1;
								  printf("%d和现有商品的编号重复，请重新输入!", number1);
								  scanf("%d", &number1);
							  }
							  index = index->next;
						  }
					  } while (i);
					  currtentNode->number = number1;
					  break;
			}
			case 2:
			{
					  printf("请输入修改后商品名称：  ");
					  scanf("%s", currtentNode->name);
					  break;
			}
			case 3:
			{
					  printf("请输入修改后商品售价：  ");
					  scanf("%lf", &currtentNode->price);
					  break;
			}
			case 4:
			{
					  printf("请输入商品数量的变化：+代表进货，-代表售出");
					  int change;
					  scanf("%d", &change);
					  if (change > 0)
					  {
						  currtentNode->stay_number = change + currtentNode->stay_number;
						  arr[1] += (currtentNode->cost)*change;

					  }
					  else if (change < 0)
					  {
						  printf("%d", currtentNode->sale_number);
						  currtentNode->sale_number = -change + currtentNode->sale_number;
						  currtentNode->stay_number += change;
						  arr[0] += (currtentNode->price)*(-1)*change;
					  }
					  else{
						  printf("无变化！");
					  }
					  break;
			}
			}
			printf("修改商品成功!\n");
			printf("\n编号\t名称\t进价\t售价\t销量\t库存\n");
			printf("%d\t%s\t%lf\t%lf\t%d\t%d\n", currtentNode->number, currtentNode->name, currtentNode->cost, currtentNode->price, currtentNode->sale_number, currtentNode->stay_number);
			saveToFile(head, "goods.txt");
		}

		printf("你还想继续修改商品吗？\n");
		printf("1--是， 0--否\n");
		scanf("%d", &choice);
	}
	printf("退出修改商品\n");
}

//商品删除
double delgoods()
{
	double income = 0.0;
	printf("你想删除商品吗？\n");
	printf("1--是， 0--否\n");
	int choice;
	scanf("%d", &choice);
	while (choice == 1)
	{
		printf("请输入想删除的商品的编号\n");
		int number;
		scanf("%d", &number);
		struct goods *currtentNode = NULL;
		currtentNode = (struct goods *)malloc(sizeof(struct goods));
		struct goods *lastNode = NULL;
		lastNode = (struct goods *)malloc(sizeof(struct goods));

		int exit = 0;//商品是否存在
		struct goods *head = readFile();
		struct goods *index = NULL;
		index = (struct goods *)malloc(sizeof(struct goods));
		if (index == NULL)
		{
			printf("没有足够的内存！");
			return 0;
		}
		index = head;
		while (index->next != NULL)
		{
			if (index->next->number == number)
			{
				lastNode = index;
			}
			if (index->number == number)
			{
				exit = 1;
				currtentNode = index;
			}
			index = index->next;
		}

		if (exit == 0)
		{
			printf("你想删除商品的商品不存在\n");
		}
		else
		{
			printf("你确定删除下述商品？\n1--确定 0--退出\n\n");
			printf("\n编号\t名称\t进价\t\t售价\t\t销量\t库存\n");
			printf("%d\t%s\t%lf\t%lf\t%d\t%d\n", currtentNode->number, currtentNode->name, currtentNode->cost, currtentNode->price, currtentNode->sale_number, currtentNode->stay_number);
			int a;
			scanf("%d", &a);
			if (a == 1)
			{
				lastNode->next = currtentNode->next;
				printf("删除商品成功!\n");
				saveToFile(head, "goods.txt");
				income += currtentNode->stay_number*currtentNode->price;
			}
			else
			{
				printf("删除商品失败!\n");
			}
		}
		printf("你还想继续删除商品吗？\n");
		printf("1--是， 0--否\n");
		scanf("%d", &choice);
	}
	printf("退出删除商品\n");
	return income;
}

//商品统计
int sortgoods()
{
	struct goods *head = NULL;
	head = (struct goods*)malloc(sizeof(struct goods));
	head = readFile();
	int a = 0; //销售数量总和  
	double b = 0; //销售金额总和  
	int c = 0;  //商品种类总和
	double d = 0;  //进货金额总和 
	struct goods *p = NULL;
	for (p = head; p; p = p->next)
	{
		a += p->sale_number;
		b += p->price*p->sale_number;
		c++;
		d += p->cost*p->stay_number;
	}
	printf("统计数据后可知：\n");       //统计以后将结果反馈给用户 
	printf("1、共有%d种商品\n", c);
	printf("2、商品的进货金额总和为：%g\n", d);
	printf("3、商品的销售数量总和为：%d\n", a);
	printf("4、商品的销售金额总和为：%g\n", b);
	return 0;
}



	
