#include <stdio.h>
#include <string.h>

int securityCheck_admin()
{
	FILE *fp = fopen("securityCheck_admin.txt", "r");
	char temp[100] = { 0 };
	int check = 0,i=0;
	char id[7];
	char password[7];
	//printf("请输入您的ID");
	//scanf("%s", id);
	while (!feof(fp))
	{
		memset(temp, 0, sizeof(temp));
		fgets(temp, sizeof(temp)-1, fp);

		printf("%s", temp);
	}
	fclose(fp);
	return 0;
}

void operation_admin(int choice_eachPage)
{
	switch (choice_eachPage)
	{
	case 0:
	{
			  printf("已退出管理员页面，回到主菜单页面\n\n\n\n");
			  break;
	}
	case 1:
	{
			  FILE *fp = fopen("leader_list.txt", "a+");
			  char ID[10],name[10],password[10];
			  printf("增加管理员正在执行\n");
			  printf("请输入要新增的店长的ID\n");
			  scanf("%s", ID);
			  fputs(strcat(ID,"\t"), fp);
			  printf("请输入要新增的店长的姓名\n");
			  scanf("%s", name);
			  fputs(strcat(name, "\t"), fp);
			  printf("请输入要新增的店长的密码\n");
			  scanf("%s", password);
			  fputs(strcat(password, "\n"), fp);
			  fclose(fp);
			  break;
	}
	case 2:
	{
			  printf("do operation leader_2\n");
			  break;
	}
	case 3:
	{
			  printf("do operation leader_3\n");
			  break;
	}
	case 4:
	{
			  printf("do operation leader_4\n");
			  break;
	}
	default:
	{
			   printf("ERROR, 请输入正确的选项\n");
			   break;
	}
	}
}

