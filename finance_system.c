//
// Created by 91601 on 2020/7/19.
//
#include<stdio.h>
#include "structural_morphology.h"


//今日收入
double income(double arr[])
{
	return arr[0];
}

//今日支出
double pay(double arr[])
{
	return arr[1];
}

//今日盈利
double gain(double arr[])
{
	return arr[0] - arr[1];
}

//备用
int gain_fuc(char filename[], struct goods *in)
{
	double gain1 = 0.0, gain2 = 0.0;
	struct goods *index = NULL;
	index = (struct goods*)malloc(sizeof(struct goods));
	if (index == NULL)
	{
		printf("内存不足！");
		return NULL;
	}
	index = in;
	while (index != NULL)
	{
		gain1 += index->price*index->sale_number - index->cost*index->stay_number;
		index = index->next;
	}


	FILE *fp = NULL;
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("文件打开失败！");
		return NULL;
	}
	char buf[528];
	fgets(buf, 528, fp);  //跳过第一行

	while (!feof(fp))
	{
		struct goods *node = NULL;
		node = (struct goods*)malloc(sizeof(struct goods));
		fscanf(fp, "%d\t%s\t%lf\t%lf\t%d\t%d\n", &node->number, node->name, &node->cost, &node->price, &node->sale_number, &node->stay_number);
		gain2 += node->price*node->sale_number - node->cost*node->stay_number;
	}
	fclose(fp);
	return gain1 - gain2;
}

