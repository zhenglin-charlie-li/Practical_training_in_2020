//
// 2020.7.20
//

#ifndef SUPERMARKET_STRUCTURAL_MORPHOLOGY_H
#define SUPERMARKET_STRUCTURAL_MORPHOLOGY_H
//商品属性
typedef struct goods
{
	int number;  //商品编号
	char name[10];//商品名称
	double cost; //商品的进价
	double price;//商品的售价
	int sale_number;//商品的销售数量
	int stay_number;//商品库存
	struct goods* next;
}goods;

//人属性
typedef struct staff
{
	char id[11];  //账号
	char passward[7];  //密码
	char name[16];//员工姓名
	int number;//职位编号
	int salary;//工资
	struct staff* next;
}staff;

#endif //SUPERMARKET_STRUCTURAL_MORPHOLOGY_H
