//主菜单
int main_menu()
{
	int choice;
	printf("\n\n\n\n\n\t\t*********************************************************\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*               欢迎来到超市信息管理系统                *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*********************************************************\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*             请根据您的身份输入对应的序号：            *\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                1. 超级管理员                          *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                2. 普通管理员                          *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                0. 退出当前界面                        *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*********************************************************\t\t\n\n");
	printf("请输入你的选择：");
	scanf("%d", &choice);
	return choice;
}

//选项展示
int staffmemu()  //管理员信息管理目录
{
	int a = 0;       //定义一个变量记录超管在管理员信息管理上的抉择
	printf("\n\n\n\t\t*********************************************************\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*               欢迎来到管理员管理系统                  *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*********************************************************\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  1、添加管理员                        *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  2、删除管理员                        *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  3、修改管理员                        *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  4、展示管理员                        *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*********************************************************\t\t\n\n");
	printf("请输入你的选择：\n");
	scanf("%d", &a);
	return a;
}

//财务管理系统菜单界面
int financememu()
{
	int a = 0;
	printf("\n\n\n\n\n\t\t*********************************************************\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*               欢迎来到财务管理系统                    *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*********************************************************\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  1、今日收入                          *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  2、今日支出                          *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  3、今日盈利                          *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  0、退出                              *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*********************************************************\t\t\n\n");
	printf("请输入你的选择：\n");
	scanf("%d", &a);
	return a;
}

//选项展示
int goodsmemu()
{
	int a = 0;
	printf("\n\n\n\n\n\t\t*********************************************************\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*               欢迎来到商品管理系统                    *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*********************************************************\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  1、添加商品                          *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  2、删除商品                          *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  3、修改商品                          *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  4、统计商品                          *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  5、展示所有商品                      *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  6、查找商品                          *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*                  0、退出                              *\t\t\n");
	printf("\t\t*                                                       *\t\t\n");
	printf("\t\t*********************************************************\t\t\n\n");
	printf("请输入你的选择：\n");
	scanf("%d", &a);
	return a;
}