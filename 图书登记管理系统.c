#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	char num[10];/*���*/
	char bname[20];/*����*/
	char wname[20];/*����*/
	char publish[50];/*������*/ 
	char putime[20];/*����ʱ��*/
	double price;
}mbook;
typedef struct
{
	int count;/*��ı���*/ 
	mbook book[100];/*������100����*/ 
}mlibrary;
mlibrary library;
void init()/*ϵͳ��¼ҳ��*/
{
	printf("\n\n\n\n\n");
	printf("\t\t\t��ӭ����ͼ����Ϣ����ϵͳ \n");
	printf("\n\n");
	printf("\t\t\t    �밴��������� \n");
	getchar();
}
int login()/*�˺ŵ�¼ͼ��ϵͳ*/
{
	int a,b,flag=0,ans=0;
	system("cls");/*����*/
	while(1)
	{
		ans++; 
		printf("\n\n\t\t���������Ա�˺�:  ");/*��ʼ�˺�Ϊ100*/
	    scanf("%d",&a);
	    printf("\n\n\t\t���������Ա����:   ");/*��ʼ����Ϊ100*/
        scanf("%d",&b);
        if(ans>3)
	    break;
	    if(a==100&&b==100)
	    {
	    	flag=1;
	    	printf("��ϲ��������ȷ������\n");
	    	break;
		}
	    else
	    {
	    	printf("\n\n\t\t��Ǹ���������,���������롣����\n");
		}
	}
	if(flag==1)
	return 1;
	else
	return 0;
}
void save()/*����ͼ����Ϣ*/
{
	FILE *fp;
	if((fp=fopen("library.doc","w"))==NULL)
	{
		printf("\n���ܱ���ͼ����Ϣ\n");
		return;
	}
	fwrite(&library.count,sizeof(int),1,fp);
	fwrite(library.book,sizeof(library.book[0]),library.count,fp);
}
void add()      /*ͼ����Ϣ¼��*/
{ 
	int y=1;
	system("cls");/*����*/
	fflush(stdin);/*��Ļͣ��*/ 
	while(y)
	{ 
		printf("\t���������:");
		scanf("%s",library.book[library.count].num);
		printf("\t����������:");
		scanf("%s",library.book[library.count].bname);
		printf("\t������������:");
		scanf("%s",library.book[library.count].wname);
		printf("\t��������浥λ:");
		scanf("%s",library.book[library.count].publish);
		printf("\t���������ʱ��:");
		scanf("%s",library.book[library.count].putime);
		printf("\t���������ļ۸�:");
		scanf("%lf",&library.book[library.count].price);
		library.count++;
		printf("\n�Ƿ����¼��(1.����; 0.�˳�¼��):");
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
void lookup()  /*ͼ����Ϣ���*/
{
	int i;
	system("cls");/*����*/
	for (i=0;i<library.count;i++)
	{
		printf("���: \n");
		printf("%s\n",library.book[i].num);
		printf("ͼ����: \n");
		printf("%s\n",library.book[i].bname);
		printf("������: \n");
		printf("%s\n",library.book[i].wname);
		printf("���浥λ: \n");
		printf("%s\n",library.book[i].publish);
		printf("����ʱ��: \n");
		printf("%s\n",library.book[i].putime);
		printf("�۸�: \n");
		printf("%6.2lf\n",library.book[i].price);
	}
	printf("�ѵ����ĵ�β���밴���������\n") ;
	fflush(stdin);
	getchar();
}
void search_by_name()          /*��������ѯ*/
{   
	char s2[20]; 
	int flag=1;
	int i; 
	printf("\t\t������Ҫ��ѯ������: ");
	scanf("%s",s2);	
	for(i=0;i<library.count;i++)
	if(strcmp(s2,library.book[i].bname)==0)
	{  
		flag=0;
		printf("���: \n");
		printf("%s\n",library.book[i].num);
		printf("����: \n");
		printf("%s\n",library.book[i].bname);
		printf("������: \n");
		printf("%s\n",library.book[i].wname);
		printf("���浥λ: \n");
		printf("%s\n",library.book[i].publish);
		printf("����ʱ��: \n");
		printf("%s\n",library.book[i].putime);
		printf("�۸�: \n");
		printf("%6.2lf\n",library.book[i].price);
		getchar();
		break;
	} 
	if (flag)
	{
		printf("�����ҵ���Ϣ���밴���������\n");
	}
	getchar();
}
void search_by_author()/*����������ѯ*/
{   
	char s3[20];
	int flag=1;
	int i;
	printf("\t\t������Ҫ��ѯ���������: ");
	scanf("%s",s3);
	for( i=0;i<library.count;i++ )
	if(strcmp(s3,library.book[i].wname)==0)
	{  
		flag=0;
		printf("���: \n"); 
		printf("%s\n",library.book[i].num);
		printf("����: \n");
		printf("%s\n",library.book[i].bname);
		printf("������: \n");
		printf("%s\n",library.book[i].wname);
		printf("���浥λ: \n");
		printf("%s\n",library.book[i].publish);
		printf("����ʱ��: \n");
		printf("%s\n",library.book[i].putime);
		printf("�۸�: \n");
		printf("%6.2lf\n",library.book[i].price);
		getchar();
		break;
	} 
	if (flag)
	{
		printf("�����ҵ���Ϣ���밴���������");
	}
	getchar();
}
void search()        /*ͼ���ѯ*/
{  
	int a;
	system("cls");         /*��������*/
    printf("\t\t******************************\n");
    printf("\t\t******************************\n"); 
	printf("\t\t��ʼ��ѯ\n");
    printf("\t\t\t1.��������ѯ\n");
    printf("\t\t\t2.����������ѯ\n");
    printf("\t\t\t0.����\n");
    printf("\t\t******************************\n") ;
    printf("\t\t��ѡ������Ҫ�Ĳ�ѯ��ʽ:");
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
void del()                   /*ͼ����Ϣɾ��*/
{ 
	char number[10];
	int i,in;
	system("cls");            /*����*/
	printf("\n   ����������ɾ����ͼ���:");
	scanf("%s",number);
	printf("\t��ȷ��ɾ��������Ϣ��\n");
	printf("\t1.�� 2.��\n");
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
	    printf("\n �����ҵ�ͼ����Ϣ���밴���������������\n");
	    save();
	    printf("ͼ����Ϣ��ɾ�����밴���������\n");
	    getchar();
	 }
	else
	{
		printf("�밴���������\n"); 
		getchar();
	}
	save();
}
void change()/*�޸�ͼ����Ϣ*/
{
	char number[10];
	int i,in;
	system("cls");            /*����*/
	printf("\n   ����������Ҫ�޸ĵ�ͼ������ :");
	scanf("%s",number);
	printf("��ȷ���޸Ĵ�����Ϣ��\n");
	printf("1.�� 2.��\n");
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
		   printf("\n\t\t�������޸ĺ��ͼ�����Ϣ\n");
		   printf("\t������ͼ���:");
		   scanf("%s",book.num);
		   printf("\t������ͼ����:");
		   scanf("%s",book.bname);
		   printf("\t������������:");
		   scanf("%s",book.wname);
		   printf("\t�����������:");
		   scanf("%s",book.publish);
		   printf("\t���������ʱ��:");
		   scanf("%s",book.putime);
		   printf("\t���������ļ۸�:");
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
	   printf("\n �����ҵ�ͼ����Ϣ���밴�������������\n");
	   getchar();
    }
    else
    {
    	printf("�밴���������ѡ��\n");
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
		   printf("\n���ܴ�ͼ����Ϣ��\n");
		   fp=fopen("library.doc","w+");
		   printf("\n��ʼ��ͼ����Ϣ��,��ʼ��֮��Ҫ��������\n");
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
		   printf("\n\n\n\n\n\t\t\tͼ����Ϣ����ϵͳ\t\t\t\t\n");
		   printf("\t\t*********************************************\n\n\n");
		   printf("\t\t\t1. --------ͼ����Ϣ¼��--------\n");
		   printf("\t\t\t2. --------ͼ����Ϣ���--------\n");
   		   printf("\t\t\t3. --------ͼ����Ϣ��ѯ--------\n");
		   printf("\t\t\t4. --------ͼ����Ϣɾ��--------\n");
		   printf("\t\t\t5. --------ͼ����Ϣ�޸�--------\n");
		   printf("\t\t\t0. --------�˳�ͼ����Ϣϵͳ----\n\n\n");
		   printf("\t\t*********************************************\n");
		   printf("\t\t��ѡ���������:    ");
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
			     printf("\n\n�˳�\n\n");
			     break;
		      default:
			     printf("\nû�д���ܣ�����������\n");
	    }
     }while(a!=0);
	 save();
	}
}


