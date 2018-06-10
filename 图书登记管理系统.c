#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	char num[10];/*书号*/
	char bname[20];/*书名*/
	char wname[20];/*作者*/
	char publish[50];/*出版社*/ 
	char putime[20];/*出版时间*/
	double price;
}mbook;
typedef struct
{
	int count;/*书的本数*/ 
	mbook book[100];/*最大可有100本书*/ 
}mlibrary;
mlibrary library;
void init()/*系统登录页面*/
{
	printf("\n\n\n\n\n");
	printf("\t\t\t欢迎进入图书信息管理系统 \n");
	printf("\n\n");
	printf("\t\t\t    请按任意键进入 \n");
	getchar();
}
int login()/*账号登录图书系统*/
{
	int a,b,flag=0,ans=0;
	system("cls");/*清屏*/
	while(1)
	{
		ans++; 
		printf("\n\n\t\t请输入管理员账号:  ");/*初始账号为100*/
	    scanf("%d",&a);
	    printf("\n\n\t\t请输入管理员密码:   ");/*初始密码为100*/
        scanf("%d",&b);
        if(ans>3)
	    break;
	    if(a==100&&b==100)
	    {
	    	flag=1;
	    	printf("恭喜，密码正确！！！\n");
	    	break;
		}
	    else
	    {
	    	printf("\n\n\t\t抱歉，密码错误,请重新输入。。。\n");
		}
	}
	if(flag==1)
	return 1;
	else
	return 0;
}
void save()/*保存图书信息*/
{
	FILE *fp;
	if((fp=fopen("library.doc","w"))==NULL)
	{
		printf("\n不能保存图书信息\n");
		return;
	}
	fwrite(&library.count,sizeof(int),1,fp);
	fwrite(library.book,sizeof(library.book[0]),library.count,fp);
}
void add()      /*图书信息录入*/
{ 
	int y=1;
	system("cls");/*清屏*/
	fflush(stdin);/*屏幕停留*/ 
	while(y)
	{ 
		printf("\t请输入书号:");
		scanf("%s",library.book[library.count].num);
		printf("\t请输入书名:");
		scanf("%s",library.book[library.count].bname);
		printf("\t请输入作者名:");
		scanf("%s",library.book[library.count].wname);
		printf("\t请输入出版单位:");
		scanf("%s",library.book[library.count].publish);
		printf("\t请输入出版时间:");
		scanf("%s",library.book[library.count].putime);
		printf("\t请输入该书的价格:");
		scanf("%lf",&library.book[library.count].price);
		library.count++;
		printf("\n是否继续录入(1.继续; 0.退出录入):");
		fflush(stdin);
		scanf("%d",&y);
		if (y!=1)
		{
			y=0;
			break;
		}
	}
	 save();
}
void lookup()  /*图书信息浏览*/
{
	int i;
	system("cls");/*清屏*/
	for (i=0;i<library.count;i++)
	{
		printf("书号: \n");
		printf("%s\n",library.book[i].num);
		printf("图书名: \n");
		printf("%s\n",library.book[i].bname);
		printf("作者名: \n");
		printf("%s\n",library.book[i].wname);
		printf("出版单位: \n");
		printf("%s\n",library.book[i].publish);
		printf("出版时间: \n");
		printf("%s\n",library.book[i].putime);
		printf("价格: \n");
		printf("%6.2lf\n",library.book[i].price);
	}
	printf("已到达文档尾，请按任意键返回\n") ;
	fflush(stdin);
	getchar();
}
void search_by_name()          /*按书名查询*/
{   
	char s2[20]; 
	int flag=1;
	int i; 
	printf("\t\t请输入要查询的书名: ");
	scanf("%s",s2);	
	for(i=0;i<library.count;i++)
	if(strcmp(s2,library.book[i].bname)==0)
	{  
		flag=0;
		printf("书号: \n");
		printf("%s\n",library.book[i].num);
		printf("书名: \n");
		printf("%s\n",library.book[i].bname);
		printf("作者名: \n");
		printf("%s\n",library.book[i].wname);
		printf("出版单位: \n");
		printf("%s\n",library.book[i].publish);
		printf("出版时间: \n");
		printf("%s\n",library.book[i].putime);
		printf("价格: \n");
		printf("%6.2lf\n",library.book[i].price);
		getchar();
		break;
	} 
	if (flag)
	{
		printf("不能找到信息，请按任意键返回\n");
	}
	getchar();
}
void search_by_author()/*按作者名查询*/
{   
	char s3[20];
	int flag=1;
	int i;
	printf("\t\t请输入要查询的书的作者: ");
	scanf("%s",s3);
	for( i=0;i<library.count;i++ )
	if(strcmp(s3,library.book[i].wname)==0)
	{  
		flag=0;
		printf("书号: \n"); 
		printf("%s\n",library.book[i].num);
		printf("书名: \n");
		printf("%s\n",library.book[i].bname);
		printf("作者名: \n");
		printf("%s\n",library.book[i].wname);
		printf("出版单位: \n");
		printf("%s\n",library.book[i].publish);
		printf("出版时间: \n");
		printf("%s\n",library.book[i].putime);
		printf("价格: \n");
		printf("%6.2lf\n",library.book[i].price);
		getchar();
		break;
	} 
	if (flag)
	{
		printf("不能找到信息，请按任意键返回");
	}
	getchar();
}
void search()        /*图书查询*/
{  
	int a;
	system("cls");         /*进行清屏*/
    printf("\t\t******************************\n");
    printf("\t\t******************************\n"); 
	printf("\t\t开始查询\n");
    printf("\t\t\t1.按书名查询\n");
    printf("\t\t\t2.按作者名查询\n");
    printf("\t\t\t0.返回\n");
    printf("\t\t******************************\n") ;
    printf("\t\t请选择你想要的查询方式:");
    scanf("%d",&a); 
    switch(a)
   {
	    case 1:
		search_by_name();
		break;      
	    case 2:
		search_by_author();
		break;
	    case 0: break;
	}
	getchar();
}
void del()                   /*图书信息删除*/
{ 
	char number[10];
	int i,in;
	system("cls");            /*清屏*/
	printf("\n   请输入你想删除的图书号:");
	scanf("%s",number);
	printf("\t你确定删除此条信息吗？\n");
	printf("\t1.是 2.否\n");
	scanf("%d",&in); 
	if(in==1)
	{
		for (i=0;i<library.count;i++)
	    {
		if(strcmp(number,library.book[i].num)==0)
		break;	
    	}
	    if (i!=library.count)
	    {
		    for(;i<library.count-1;i++)
		    {
			    strcpy(library.book[i].bname,library.book[i+1].bname);
			    strcpy(library.book[i].num,library.book[i+1].num);
			    strcpy(library.book[i].publish,library.book[i+1].publish);
			    strcpy(library.book[i].wname,library.book[i+1].wname);
			    strcpy(library.book[i].putime,library.book[i+1].putime);
			    library.book[i].price=library.book[i+1].price;
		    }
		    library.count--;
	     }
	    else
	    printf("\n 不能找到图书信息，请按按任意键重新输入\n");
	    save();
	    printf("图书信息已删除，请按任意键继续\n");
	    getchar();
	 }
	else
	{
		printf("请按任意键返回\n"); 
		getchar();
	}
	save();
}
void change()/*修改图书信息*/
{
	char number[10];
	int i,in;
	system("cls");            /*清屏*/
	printf("\n   请输入你想要修改的图书的书号 :");
	scanf("%s",number);
	printf("你确定修改此条信息吗？\n");
	printf("1.是 2.否\n");
	scanf("%d",&in);
	if(in==1)
	{
		for (i=0;i<library.count;i++)
	   {
	      if(strcmp(number,library.book[i].num)==0)
	      {
		      printf("%s\n",library.book[i].num);
		      printf("%s\n",library.book[i].bname);
		      printf("%s\n",library.book[i].wname);
		      printf("%s\n",library.book[i].publish);
		      printf("%s\n",library.book[i].putime);
		      printf("%6.2lf\n",library.book[i].price);
		      break;
	     }
	   }
        if (i!=library.count)
	   {
		   mbook book;
		   printf("\n\t\t请输入修改后此图书的信息\n");
		   printf("\t请输入图书号:");
		   scanf("%s",book.num);
		   printf("\t请输入图书名:");
		   scanf("%s",book.bname);
		   printf("\t请输入作者名:");
		   scanf("%s",book.wname);
		   printf("\t请输入出版社:");
		   scanf("%s",book.publish);
		   printf("\t请输入出版时间:");
		   scanf("%s",book.putime);
		   printf("\t请输入该书的价格:");
		   scanf("%f",&book.price);
		   strcpy(library.book[i].bname,book.bname);
		   strcpy(library.book[i].num,book.num);
		   strcpy(library.book[i].publish,book.publish);
		   strcpy(library.book[i].wname,book.wname);
		   strcpy(library.book[i].putime,book.putime);
		   library.book[i].price=book.price;
		   save();
	    }
       else
	   printf("\n 不能找到图书信息，请按任意键重新输入\n");
	   getchar();
    }
    else
    {
    	printf("请按任意键重新选择\n");
    	getchar();
	}
	save();
}
int main()
{
	FILE *fp;
	int a; 
	init();
	if(login()==1)
	{
		if((fp=fopen("library.doc","r"))==NULL)
	    {
		   printf("\n不能打开图书信息库\n");
		   fp=fopen("library.doc","w+");
		   printf("\n初始化图书信息库,初始化之后要重启程序\n");
		   library.count=0;
		   fwrite(&library.count,sizeof(int),1,fp);
		   fclose(fp);
		   return 0 ;
	    }
	    fread(&library.count,sizeof(int),1,fp);
	    fread(library.book,sizeof(library.book[0]),library.count,fp);
	    fclose(fp);
	    do
	    {
		   system("cls");
		   printf("\n\n\n\n\n\t\t\t图书信息管理系统\t\t\t\t\n");
		   printf("\t\t*********************************************\n\n\n");
		   printf("\t\t\t1. --------图书信息录入--------\n");
		   printf("\t\t\t2. --------图书信息浏览--------\n");
   		   printf("\t\t\t3. --------图书信息查询--------\n");
		   printf("\t\t\t4. --------图书信息删除--------\n");
		   printf("\t\t\t5. --------图书信息修改--------\n");
		   printf("\t\t\t0. --------退出图书信息系统----\n\n\n");
		   printf("\t\t*********************************************\n");
		   printf("\t\t请选择服务类型:    ");
		   scanf("%d",&a);
		   switch(a)
		   {
		      case 1:
			     add();
			     break;
		      case 2:
			     lookup();
			     break;
		      case 3:
			     search();
		         break;
		      case 4:
			     del();
			     break;
		      case 5:
			     change();
			     break;
		      case 0:
			     printf("\n\n退出\n\n");
			     break;
		      default:
			     printf("\n没有此项功能，请重新输入\n");
	    }
     }while(a!=0);
	 save();
	}
}


