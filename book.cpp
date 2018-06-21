#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct asccount{  
    char ID[28];  
    char password[28]; 
}user[2000];

struct message{
	char book_number[20];
	char book_name[20];
	char book_writer[20];
	char book_price[20];
}book[2000];

void save_user(void);//将账号写入磁盘
void load_user(void);//将账号读入内存
void save_book(void);//将图书写入磁盘
void load_book(void);//将图书读入内存

void user_menu(void);//账号菜单 
void add_user(void);//注册账号 
void login_user(void);//登录账号
void reset_password(void);//修改密码


void choose_menu(void);//选择菜单
void function_menue(void);//功能菜单
void developer_introduce(void);//开发人员介绍 
void library_function(void);//图书功能介绍 


void entering_function(void);//录入功能	
void find_function(void);//查找功能 
void sort_function(void);//排序功能
void add_function(void);//添加功能
void delete_function(void);//删除功能
void reset_function(void);//修改功能 
void look_function(void);//浏览功能 

void sort_book_number(void);//按书号排序
int cmp_book_number(struct message x,struct message y);//按书号排序判断 
void sort_book_name(void);//按书名排序
int cmp_book_name(struct message x,struct message y);//按书名排序判断 
void sort_book_price(void);//按单价排序 
int cmp_book_price(struct message x,struct message y);//按单价排序判断 

void find_book_number(void);
void find_book_name(void);
void find_book_price(void);

int user_count=0;
int book_count=0;

int main()
{
	system("color 03");//背景与字体颜色 
	load_user();//将账号读入内存
	load_book();//将图书读入内存 
	user_menu();
	return 0;
}

void user_menu(void)
{
	int choose;
	system("cls");
	printf("\n\n\t\t*****************************************");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t 欢迎来到小型图书管理系统\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      登录账号请按1\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      注册账号请按2\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      修改密码请按3\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      退出系统请按0\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*****************************************");
	printf("\n\t\t\t\t");
	printf("\n\t\t\t       请输入选项:\n\t\t\t\t   ");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
			login_user(); break;
		case 2:
			add_user(); break;
		case 3:
			reset_password(); break;
		case 0:
			return; 
		default :
			printf("\n\t\t\t   输入错误，请重新输入\n\n\t\t\t    "); 
			system("PAUSE");  
        	system("cls"); 
		 	user_menu(); 
	}
}

void add_user(void)//注册账号
{  
    FILE *fp;  
    int i;  
    char str[101];  
    system("cls");  
    printf("\n");
    printf("\t\t\t请输入账号：\n\n\t\t\t   ");  
    scanf("%s",str);
	if(strlen(str)>16)
	{
		printf("\t\t账号长度大于16位，请重新输入\n");
		system("PAUSE");  
        system("cls");  
        printf("\n");  
        add_user();
		return;
	}	
    for(i=0;i<user_count;i++)
        if(strcmp(user[i].ID,str)==0)
		{  
            printf("\t\t该账号已被注册，请重新注册\n\n\t\t\t   ");  
            system("PAUSE");//按任意键继续  
            add_user();  
        }
    strcpy(user[i].ID,str);  
    printf("\t\t\t请输入密码：\n\n\t\t\t   ");
	scanf("%s",str);
	while(strlen(str)>16)
	{
		system("cls");
		printf("\n");
		printf("\t\t密码长度大于16位，请重新输入\n\n");
		printf("\t\t\t请输入密码：\n\n\t\t\t   ");
		scanf("%s",str);	
	} 
    strcpy(user[i].password,str);  
    printf("\t\t\t请再次输入密码：\n\n\t\t\t   ");  
    scanf("%s",str);  
    if(strcmp(user[i].password,str)!=0)
	{  
        printf("\t\t两次密码不一致,请重新申请\n\n\t\t\t");  
        system("PAUSE");  
        system("cls");  
        printf("\n");  
        add_user();
        return;
    }
    save_user();//将账号写入磁盘 
    printf("\t\t\t账号申请成功\n\n\t\t\t");  
    user_count++;
    system("PAUSE");
	user_menu();   
} 

void load_user(void)//将账号读入内存
{  
	FILE *fp;
    fp=fopen("账号.txt","r"); 
    while(fscanf(fp,"%s",user[user_count].ID)!=EOF)
	{  
        fscanf(fp,"%s",user[user_count].password); 
        user_count++;
    }
    fclose(fp);
}

void save_user(void)//将账号写入磁盘
{
    int i;
    FILE *fp;  
    fp=fopen("账号.txt","w");
	
    for(i=0;i<=user_count;i++)
	{
        fprintf(fp,"%s\n",user[i].ID);  
        fprintf(fp,"%s\n",user[i].password); 
    }  
    fclose(fp);  
} 

void login_user(void)//登录账号
{
	int i,flag=0;
	char str[20];
	system("cls");  
	printf("\n");
	printf("\t\t\t请输入账号：\n\n\t\t\t   ");
	scanf("%s",str);
	for(i=0;i<user_count;i++)
		if(strcmp(user[i].ID,str)==0)
		{
			flag=1;
			break;
		}
	if(flag==0)
	{
		printf("\t\t该账号不存在，请重新登录\n\n\t\t\t");
		system("PAUSE");  
        system("cls");  
        printf("\n");
        login_user(); 
        return;
	}
	printf("\t\t\t请输入密码：\n\n\t\t\t   ");
	scanf("%s",str);
	while(strcmp(user[i].password,str)!=0)
	{
		system("cls");  
        printf("\n");
		printf("\t\t\t密码错误，请重新输入\n\n\t\t\t\t");
		scanf("%s",str);	
	}
	printf("\t\t\t登录成功\n\n\t\t\t");
	choose_menu();
}

void reset_password(void)//修改密码
{
	int i,flag=0;
	char str[20];
	system("cls");  
	printf("\n");
	printf("\t\t\t请输入账号：\n\n\t\t\t   ");
	scanf("%s",str);
	for(i=0;i<user_count;i++)
		if(strcmp(user[i].ID,str)==0)
		{
			flag=1;
			break;
		}
	if(flag==0)
	{
		printf("\t\t该账号不存在，请重新登录\n\n\t\t\t");
		system("PAUSE");  
        system("cls");  
        printf("\n");
        reset_password(); 
        return;
	}
	printf("\t\t\t请输入密码：\n\n\t\t\t   ");
	scanf("%s",str);
	while(strcmp(user[i].password,str)!=0)
	{
		system("cls");  
        printf("\n");
		printf("\t\t\t密码错误，请重新输入\n\n\t\t\t\t");
		scanf("%s",str);	
	}
	printf("\t\t\t请输入新密码\n\n\t\t\t   "); 
	scanf("%s",str);
	while(strlen(str)>16)
	{
		printf("\t\t密码长度大于16位，请重新输入\n");
		system("PAUSE");  
        system("cls");  
        printf("\n");  
        scanf("%s",str);
	} 
    strcpy(user[i].password,str);  
    printf("\t\t\t请再次输入密码：\n\n\t\t\t   ");  
    scanf("%s",str);  
    while(strcmp(user[i].password,str)!=0)
	{  
        printf("\t\t两次密码不一致,请重新申请\n\n\t\t\t");  
        system("PAUSE");  
        system("cls");  
        printf("\n");  
        scanf("%s",str);
    } 
    save_user();
	printf("\t\t\t修改成功\n\n\t\t\t"); 
	system("PAUSE");
	user_menu();
} 

void choose_menu(void)//选择菜单
{
	int choose;
	while(1)
	{
		system("cls");
		printf("\n\n\t\t*****************************************");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t     欢迎来到选择菜单管理\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      图书功能管理请按1\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      开发人员介绍请按2\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      图书功能介绍请按3\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      返回到上一层请按0\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*****************************************");
		printf("\n\t\t\t\t");
		printf("\n\t\t\t       请输入选项:\n\t\t\t\t   ");
		scanf("%d",&choose);
		switch(choose)
		{
			case 0:
				 user_menu(); return;
			case 1:
				 function_menue(); return;
			case 2:
				 developer_introduce(); return;
			case 3:
				 library_function(); return;
			default:
				printf("\n\t\t\t   输入错误，请重新输入\n\n\t\t\t    "); 
			system("PAUSE");  
	        system("cls");
		}		
	}		
} 

void function_menue(void)//功能菜单 
{
	int choose;
	while(1)
	{
		system("cls");
		printf("\n\n\t\t*****************************************");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      录入功能请按1\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      查找功能请按2\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      排序功能请按3\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      添加功能请按4\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      删除功能请按5\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      修改功能请按6\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      浏览功能请按7\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t     返回上一层请按0\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*****************************************");
		printf("\n\t\t\t\t");
		printf("\n\t\t\t       请输入选项:\n\t\t\t\t   ");
		scanf("%d",&choose);
		switch(choose)
		{
			case 0:
				choose_menu(); 
			case 1:
				entering_function(); break;//录入功能
			case 2:
				 find_function(); break;//查找功能
			case 3:
				sort_function(); break;//排序功能
			case 4:
				add_function(); break;//添加功能 
			case 5:
				delete_function(); break;//删除功能	
			case 6: 
				reset_function(); break;//修改功能 
			case 7:
				look_function(); break;//浏览功能 
			default :
				printf("\n\t\t\t   输入错误，请重新输入\n\n\t\t\t    "); 
			system("PAUSE");  
		}	
	}
}

void developer_introduce(void)//开发人员介绍 
{
	system("cls");
	printf("\n\n\t\t*****************************************");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      开发人员信息：\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      	 2017级 \t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t     信息与计算科学\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t         周冀豪  \t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*****************************************");
	printf("\n\t\t");
    system("PAUSE");
    choose_menu();
}

void library_function(void)//图书功能介绍 
{
	system("cls");
	printf("\n\n\t\t*****************************************");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t   该系统包括以下功能\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      1、 注册账号\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      2、 登录账号\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      3、 修改密码\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      4、 录入功能\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      5、 添加功能\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      6、 删除功能\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      7、 修改功能\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      8、 浏览功能\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      9、 查询密码\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      10、排序功能\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*****************************************");
	printf("\n\t\t");
    system("PAUSE");
    choose_menu();
} 

void entering_function(void)//录入功能
{
	int i;
	system("cls");
	printf("\n\t\t\t   请输入要录入的图书数\n\t\t\t\t");
	scanf("%d",&book_count);
	for(i=0;i<book_count;i++)
	{
		system("cls");
		printf("\n\t\t\t   请输入书号\n\t\t\t\t",i); 
		scanf("%s",book[i].book_number);
		printf("\n\t\t\t   请输入书名\n\t\t\t\t",i); 
		scanf("%s",book[i].book_name);
		printf("\n\t\t\t   请输入作者\n\t\t\t\t",i); 
		scanf("%s",book[i].book_writer);
		printf("\n\t\t\t   请输入单价\n\t\t\t\t",i); 
		scanf("%s",book[i].book_price);
	}
	save_book();
	system("PAUSE");
}

void load_book(void)//将图书读入内存
{  
	FILE *fp;
    fp=fopen("图书.txt","r"); 
    while(fscanf(fp,"%s",book[book_count].book_number)!=EOF)
	{  
        fscanf(fp,"%s",book[book_count].book_name); 
        fscanf(fp,"%s",book[book_count].book_writer);
        fscanf(fp,"%s",book[book_count].book_price);
        book_count++;
    }
    fclose(fp);
}

void save_book(void)//将图书写入磁盘
{
    int i;
    FILE *fp;  
    fp=fopen("图书.txt","w");
    
    for(i=0;i<=book_count;i++)
	{
        fprintf(fp,"%s\n",book[i].book_number);  
        fprintf(fp,"%s\n",book[i].book_name);
        fprintf(fp,"%s\n",book[i].book_writer);
        fprintf(fp,"%s\n",book[i].book_price);
    }  
    fclose(fp);  
} 

void sort_function(void)//排序功能 
{
	int choose;
	while(1)
	{
		system("cls");
		printf("\n\n\t\t*****************************************");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t   欢迎来到排序功能管理\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      按书号排序请按1\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      按书名排序请按2\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      按单价排序请按3\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*****************************************");
		printf("\n\t\t\t\t");
		printf("\n\t\t\t       请输入选项:\n\t\t\t\t   ");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:
				sort_book_number(); return;
			case 2:
				 sort_book_name(); return;
			case 3:
				 sort_book_price(); return;
			default:
				printf("\n\t\t\t   输入错误，请重新输入\n\n\t\t\t    "); 
			system("PAUSE");  
	        system("cls");
		}		
	}
} 

void sort_book_number(void)//按书号排序
{
	int i;
	for(i=0;i<book_count;i++)
		sort(book,book+book_count,cmp_book_number);	
	printf("\n\t\t\t排序完成\n\n\t\t\t");
	save_book();
	system("PAUSE"); 
} 

void sort_book_name()//按书名排序 
{
	int i;
	for(i=0;i<book_count;i++)
		sort(book,book+book_count,cmp_book_name);	
	printf("\n\t\t\t排序完成\n\n\t\t\t");
	save_book();
	system("PAUSE");
}

void sort_book_price(void)//按单价排序
{
	int i;
	for(i=0;i<book_count;i++)
		sort(book,book+book_count,cmp_book_price);	
	printf("\n\t\t\t排序完成\n\n\t\t\t");
	save_book();
	system("PAUSE");
	return;	
} 

int cmp_book_number(struct message x,struct message y)
{
	if(strcmp(x.book_number,y.book_number)==-1)
		return 1;
	return 0;
}

int cmp_book_name(struct message x,struct message y)
{
	if(strcmp(x.book_name,y.book_name)==-1)
		return 1;
	return 0;
}

int cmp_book_price(struct message x,struct message y)
{
	if(strcmp(x.book_price,y.book_price)==-1)
		return 1;
	return 0;
}

void add_function(void)//添加功能
{
	int i;
	system("cls");
	printf("\n\t\t\t本图书系统已有%d本书\n",book_count); 
	printf("\n\t\t\t请输入要添加的书号\n\t\t\t\t",book_count); 
	scanf("%s",book[book_count].book_number);
	printf("\n\t\t\t请输入要添加的书名\n\t\t\t\t",book_count); 
	scanf("%s",book[book_count].book_name);
	printf("\n\t\t\t请输入要添加的作者\n\t\t\t\t",book_count); 
	scanf("%s",book[book_count].book_writer);
	printf("\n\t\t\t请输入要添加的单价\n\t\t\t\t",book_count); 
	scanf("%s",book[book_count].book_price);
	printf("\n\t\t\t添加成功\n\t\t\t\t"); 
	book_count++;
	save_book();
	system("PAUSE");
	return; 
}

void find_function(void)//查找功能
{
	int choose;
	while(1)
	{
		system("cls");
		printf("\n\n\t\t*****************************************");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t   欢迎来到查找功能管理\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      按书号查找请按1\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      按书名查找请按2\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      按单价查找请按3\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*****************************************");
		printf("\n\t\t\t\t");
		printf("\n\t\t\t       请输入选项:\n\t\t\t\t   ");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:
				find_book_number(); return;
			case 2:
				 find_book_name(); return;
			case 3:
				 find_book_price(); return;
			default:
				printf("\n\t\t\t   输入错误，请重新输入\n\n\t\t\t    "); 
			system("PAUSE");  
	        system("cls");
		}		
	}
} 

void find_book_number(void)//按书号查找
{
	int i,t=-1;
	char str[20];
	while(1)
	{
		system("cls");
		printf("\n\t\t\t请输入要查找的书号\n\t\t\t\t");
		scanf("%s",str);
		for(i=0;i<book_count;i++)
			if(strcmp(book[i].book_number,str)==0)
			{
				t=i;
				break;
			}
		if(t==-1)
		{
			printf("\n\t\t\t该书号不存在，请重新输入\n\n\t\t\t    ");
			system("PAUSE");
			continue;
		}
		printf("\n\t\t\t查找成功");
		printf("\n\t\t\t书号：%s",book[t].book_number);
		printf("\n\t\t\t书名：%s",book[t].book_name);
		printf("\n\t\t\t作者：%s",book[t].book_writer);
		printf("\n\t\t\t单价：%s",book[t].book_price);
		printf("\n\t\t\t"); 
		system("PAUSE");
		break;	
	}	
} 

void find_book_name(void)//按书名查找
{
	int i,t=-1;
	char str[20];
	while(1)
	{
		system("cls");
		printf("\n\t\t\t请输入要查找的书名\n\t\t\t\t");
		scanf("%s",str);
		for(i=0;i<book_count;i++)
			if(strcmp(book[i].book_name,str)==0)
			{
				t=i;
				break;
			}
		if(t==-1)
		{
			printf("\n\t\t\t该书名不存在，请重新输入\n\n\t\t\t    ");
			system("PAUSE");
			continue;
		}
		printf("\n\t\t\t查找成功");
		printf("\n\t\t\t书号：%s",book[t].book_number);
		printf("\n\t\t\t书名：%s",book[t].book_name);
		printf("\n\t\t\t作者：%s",book[t].book_writer);
		printf("\n\t\t\t单价：%s",book[t].book_price);
		printf("\n\t\t\t"); 
		system("PAUSE");
		break;	
	}	
} 

void find_book_price(void)//按单价查找
{
	int i,t=-1;
	char str[20];
	while(1)
	{
		system("cls");
		printf("\n\t\t\t请输入要查找的单价\n\t\t\t\t");
		scanf("%s",str);
		for(i=0;i<book_count;i++)
			if(strcmp(book[i].book_price,str)==0)
			{
				t=i;
				break;
			}
		if(t==-1)
		{
			printf("\n\t\t\t该单价不存在，请重新输入\n\n\t\t\t    ");
			system("PAUSE");
			continue;
		}
		printf("\n\t\t\t查找成功");
		printf("\n\t\t\t书号：%s",book[t].book_number);
		printf("\n\t\t\t书名：%s",book[t].book_name);
		printf("\n\t\t\t作者：%s",book[t].book_writer);
		printf("\n\t\t\t单价：%s",book[t].book_price);
		printf("\n\t\t\t"); 
		system("PAUSE");
		break;	
	}	
} 

void delete_function(void)//删除功能
{
	int i,t=-1;
	char str[20];
	while(1)
	{
		system("cls");
		printf("\n\t\t\t请输入要删除的书号\n\t\t\t\t");
		scanf("%s",str);
		for(i=0;i<book_count;i++)
			if(strcmp(book[i].book_number,str)==0)
			{
				t=i;
				break;
			}
		if(t==-1)
		{
			printf("\n\t\t\t   输入错误，请重新输入\n\n\t\t\t    ");
			system("PAUSE");
			continue;
		}
		printf("\n\t\t\t书号：%s",book[t].book_number);
		printf("\n\t\t\t书名：%s",book[t].book_name);
		printf("\n\t\t\t作者：%s",book[t].book_writer);
		printf("\n\t\t\t单价：%s",book[t].book_price);
		printf("\n\t\t\t是否确定删除%d号书的信息",t);
		printf("\n\t\t\t是请按1"); 
		printf("\n\t\t\t否请按0\n\t\t\t\t");
		scanf("%d",&t);
		if(t==0)
			return; 
		strcpy(book[t].book_name,"");
		strcpy(book[t].book_number,"");
		strcpy(book[t].book_writer,"");	
		strcpy(book[t].book_price,"");
		printf("\n\t\t\t删除成功\n\t\t\t\t");
		save_book();
		system("PAUSE");
		break;	
	}
} 

void reset_function(void)//修改功能 
{
	int i,t=-1;
	char str[20];
	while(1)
	{
		system("cls");
		printf("\n\t\t\t请输入要修改的书号\n\t\t\t\t");
		scanf("%s",str);
		for(i=0;i<book_count;i++)
			if(strcmp(book[i].book_number,str)==0)
			{
				t=i;
				break;
			}
		if(t==-1)
		{
			printf("\n\t\t\t   输入错误，请重新输入\n\n\t\t\t    ");
			system("PAUSE");
			continue;
		}
		printf("\n\t\t\t书号：%s",book[t].book_number);
		printf("\n\t\t\t书名：%s",book[t].book_name);
		printf("\n\t\t\t作者：%s",book[t].book_writer);
		printf("\n\t\t\t单价：%s",book[t].book_price);
		printf("\n\t\t\t请输入新书号\n\t\t\t\t");
		scanf("%s",book[t].book_number);
		printf("\n\t\t\t请输入新书名\n\t\t\t\t");
		scanf("%s",book[t].book_name);
		printf("\n\t\t\t请输入新作者\n\t\t\t\t");
		scanf("%s",book[t].book_writer);
		printf("\n\t\t\t请输入新单价\n\t\t\t\t");
		scanf("%s",book[t].book_price);
		printf("\n\t\t\t修改成功\n\t\t\t\t");
		save_book();
		system("PAUSE");
		break;	
	}
}

void look_function(void)//浏览功能
{
	int i;
	system("cls");
	for(i=0;i<book_count;i++)
	{
		printf("书号：%s",book[i].book_number);
		printf("\n书名：%s",book[i].book_name);
		printf("\n作者：%s",book[i].book_writer);
		printf("\n单价：%s",book[i].book_price);
		printf("\n\n");
	}
	system("PAUSE");
}
