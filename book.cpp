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

void save_user(void);//���˺�д�����
void load_user(void);//���˺Ŷ����ڴ�
void save_book(void);//��ͼ��д�����
void load_book(void);//��ͼ������ڴ�

void user_menu(void);//�˺Ų˵� 
void add_user(void);//ע���˺� 
void login_user(void);//��¼�˺�
void reset_password(void);//�޸�����


void choose_menu(void);//ѡ��˵�
void function_menue(void);//���ܲ˵�
void developer_introduce(void);//������Ա���� 
void library_function(void);//ͼ�鹦�ܽ��� 


void entering_function(void);//¼�빦��	
void find_function(void);//���ҹ��� 
void sort_function(void);//������
void add_function(void);//��ӹ���
void delete_function(void);//ɾ������
void reset_function(void);//�޸Ĺ��� 
void look_function(void);//������� 

void sort_book_number(void);//���������
int cmp_book_number(struct message x,struct message y);//����������ж� 
void sort_book_name(void);//����������
int cmp_book_name(struct message x,struct message y);//�����������ж� 
void sort_book_price(void);//���������� 
int cmp_book_price(struct message x,struct message y);//�����������ж� 

void find_book_number(void);
void find_book_name(void);
void find_book_price(void);

int user_count=0;
int book_count=0;

int main()
{
	system("color 03");//������������ɫ 
	load_user();//���˺Ŷ����ڴ�
	load_book();//��ͼ������ڴ� 
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
	printf("\n\t\t*\t ��ӭ����С��ͼ�����ϵͳ\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      ��¼�˺��밴1\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      ע���˺��밴2\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      �޸������밴3\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      �˳�ϵͳ�밴0\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*****************************************");
	printf("\n\t\t\t\t");
	printf("\n\t\t\t       ������ѡ��:\n\t\t\t\t   ");
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
			printf("\n\t\t\t   �����������������\n\n\t\t\t    "); 
			system("PAUSE");  
        	system("cls"); 
		 	user_menu(); 
	}
}

void add_user(void)//ע���˺�
{  
    FILE *fp;  
    int i;  
    char str[101];  
    system("cls");  
    printf("\n");
    printf("\t\t\t�������˺ţ�\n\n\t\t\t   ");  
    scanf("%s",str);
	if(strlen(str)>16)
	{
		printf("\t\t�˺ų��ȴ���16λ������������\n");
		system("PAUSE");  
        system("cls");  
        printf("\n");  
        add_user();
		return;
	}	
    for(i=0;i<user_count;i++)
        if(strcmp(user[i].ID,str)==0)
		{  
            printf("\t\t���˺��ѱ�ע�ᣬ������ע��\n\n\t\t\t   ");  
            system("PAUSE");//�����������  
            add_user();  
        }
    strcpy(user[i].ID,str);  
    printf("\t\t\t���������룺\n\n\t\t\t   ");
	scanf("%s",str);
	while(strlen(str)>16)
	{
		system("cls");
		printf("\n");
		printf("\t\t���볤�ȴ���16λ������������\n\n");
		printf("\t\t\t���������룺\n\n\t\t\t   ");
		scanf("%s",str);	
	} 
    strcpy(user[i].password,str);  
    printf("\t\t\t���ٴ��������룺\n\n\t\t\t   ");  
    scanf("%s",str);  
    if(strcmp(user[i].password,str)!=0)
	{  
        printf("\t\t�������벻һ��,����������\n\n\t\t\t");  
        system("PAUSE");  
        system("cls");  
        printf("\n");  
        add_user();
        return;
    }
    save_user();//���˺�д����� 
    printf("\t\t\t�˺�����ɹ�\n\n\t\t\t");  
    user_count++;
    system("PAUSE");
	user_menu();   
} 

void load_user(void)//���˺Ŷ����ڴ�
{  
	FILE *fp;
    fp=fopen("�˺�.txt","r"); 
    while(fscanf(fp,"%s",user[user_count].ID)!=EOF)
	{  
        fscanf(fp,"%s",user[user_count].password); 
        user_count++;
    }
    fclose(fp);
}

void save_user(void)//���˺�д�����
{
    int i;
    FILE *fp;  
    fp=fopen("�˺�.txt","w");
	
    for(i=0;i<=user_count;i++)
	{
        fprintf(fp,"%s\n",user[i].ID);  
        fprintf(fp,"%s\n",user[i].password); 
    }  
    fclose(fp);  
} 

void login_user(void)//��¼�˺�
{
	int i,flag=0;
	char str[20];
	system("cls");  
	printf("\n");
	printf("\t\t\t�������˺ţ�\n\n\t\t\t   ");
	scanf("%s",str);
	for(i=0;i<user_count;i++)
		if(strcmp(user[i].ID,str)==0)
		{
			flag=1;
			break;
		}
	if(flag==0)
	{
		printf("\t\t���˺Ų����ڣ������µ�¼\n\n\t\t\t");
		system("PAUSE");  
        system("cls");  
        printf("\n");
        login_user(); 
        return;
	}
	printf("\t\t\t���������룺\n\n\t\t\t   ");
	scanf("%s",str);
	while(strcmp(user[i].password,str)!=0)
	{
		system("cls");  
        printf("\n");
		printf("\t\t\t�����������������\n\n\t\t\t\t");
		scanf("%s",str);	
	}
	printf("\t\t\t��¼�ɹ�\n\n\t\t\t");
	choose_menu();
}

void reset_password(void)//�޸�����
{
	int i,flag=0;
	char str[20];
	system("cls");  
	printf("\n");
	printf("\t\t\t�������˺ţ�\n\n\t\t\t   ");
	scanf("%s",str);
	for(i=0;i<user_count;i++)
		if(strcmp(user[i].ID,str)==0)
		{
			flag=1;
			break;
		}
	if(flag==0)
	{
		printf("\t\t���˺Ų����ڣ������µ�¼\n\n\t\t\t");
		system("PAUSE");  
        system("cls");  
        printf("\n");
        reset_password(); 
        return;
	}
	printf("\t\t\t���������룺\n\n\t\t\t   ");
	scanf("%s",str);
	while(strcmp(user[i].password,str)!=0)
	{
		system("cls");  
        printf("\n");
		printf("\t\t\t�����������������\n\n\t\t\t\t");
		scanf("%s",str);	
	}
	printf("\t\t\t������������\n\n\t\t\t   "); 
	scanf("%s",str);
	while(strlen(str)>16)
	{
		printf("\t\t���볤�ȴ���16λ������������\n");
		system("PAUSE");  
        system("cls");  
        printf("\n");  
        scanf("%s",str);
	} 
    strcpy(user[i].password,str);  
    printf("\t\t\t���ٴ��������룺\n\n\t\t\t   ");  
    scanf("%s",str);  
    while(strcmp(user[i].password,str)!=0)
	{  
        printf("\t\t�������벻һ��,����������\n\n\t\t\t");  
        system("PAUSE");  
        system("cls");  
        printf("\n");  
        scanf("%s",str);
    } 
    save_user();
	printf("\t\t\t�޸ĳɹ�\n\n\t\t\t"); 
	system("PAUSE");
	user_menu();
} 

void choose_menu(void)//ѡ��˵�
{
	int choose;
	while(1)
	{
		system("cls");
		printf("\n\n\t\t*****************************************");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t     ��ӭ����ѡ��˵�����\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      ͼ�鹦�ܹ����밴1\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      ������Ա�����밴2\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      ͼ�鹦�ܽ����밴3\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      ���ص���һ���밴0\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*****************************************");
		printf("\n\t\t\t\t");
		printf("\n\t\t\t       ������ѡ��:\n\t\t\t\t   ");
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
				printf("\n\t\t\t   �����������������\n\n\t\t\t    "); 
			system("PAUSE");  
	        system("cls");
		}		
	}		
} 

void function_menue(void)//���ܲ˵� 
{
	int choose;
	while(1)
	{
		system("cls");
		printf("\n\n\t\t*****************************************");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      ¼�빦���밴1\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      ���ҹ����밴2\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      �������밴3\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      ��ӹ����밴4\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      ɾ�������밴5\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      �޸Ĺ����밴6\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      ��������밴7\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t     ������һ���밴0\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*****************************************");
		printf("\n\t\t\t\t");
		printf("\n\t\t\t       ������ѡ��:\n\t\t\t\t   ");
		scanf("%d",&choose);
		switch(choose)
		{
			case 0:
				choose_menu(); 
			case 1:
				entering_function(); break;//¼�빦��
			case 2:
				 find_function(); break;//���ҹ���
			case 3:
				sort_function(); break;//������
			case 4:
				add_function(); break;//��ӹ��� 
			case 5:
				delete_function(); break;//ɾ������	
			case 6: 
				reset_function(); break;//�޸Ĺ��� 
			case 7:
				look_function(); break;//������� 
			default :
				printf("\n\t\t\t   �����������������\n\n\t\t\t    "); 
			system("PAUSE");  
		}	
	}
}

void developer_introduce(void)//������Ա���� 
{
	system("cls");
	printf("\n\n\t\t*****************************************");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      ������Ա��Ϣ��\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      	 2017�� \t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t     ��Ϣ������ѧ\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t         �ܼ���  \t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*****************************************");
	printf("\n\t\t");
    system("PAUSE");
    choose_menu();
}

void library_function(void)//ͼ�鹦�ܽ��� 
{
	system("cls");
	printf("\n\n\t\t*****************************************");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t   ��ϵͳ�������¹���\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      1�� ע���˺�\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      2�� ��¼�˺�\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      3�� �޸�����\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      4�� ¼�빦��\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      5�� ��ӹ���\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      6�� ɾ������\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      7�� �޸Ĺ���\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      8�� �������\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      9�� ��ѯ����\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*\t      10��������\t\t*");
	printf("\n\t\t*\t\t\t\t\t*");
	printf("\n\t\t*****************************************");
	printf("\n\t\t");
    system("PAUSE");
    choose_menu();
} 

void entering_function(void)//¼�빦��
{
	int i;
	system("cls");
	printf("\n\t\t\t   ������Ҫ¼���ͼ����\n\t\t\t\t");
	scanf("%d",&book_count);
	for(i=0;i<book_count;i++)
	{
		system("cls");
		printf("\n\t\t\t   ���������\n\t\t\t\t",i); 
		scanf("%s",book[i].book_number);
		printf("\n\t\t\t   ����������\n\t\t\t\t",i); 
		scanf("%s",book[i].book_name);
		printf("\n\t\t\t   ����������\n\t\t\t\t",i); 
		scanf("%s",book[i].book_writer);
		printf("\n\t\t\t   �����뵥��\n\t\t\t\t",i); 
		scanf("%s",book[i].book_price);
	}
	save_book();
	system("PAUSE");
}

void load_book(void)//��ͼ������ڴ�
{  
	FILE *fp;
    fp=fopen("ͼ��.txt","r"); 
    while(fscanf(fp,"%s",book[book_count].book_number)!=EOF)
	{  
        fscanf(fp,"%s",book[book_count].book_name); 
        fscanf(fp,"%s",book[book_count].book_writer);
        fscanf(fp,"%s",book[book_count].book_price);
        book_count++;
    }
    fclose(fp);
}

void save_book(void)//��ͼ��д�����
{
    int i;
    FILE *fp;  
    fp=fopen("ͼ��.txt","w");
    
    for(i=0;i<=book_count;i++)
	{
        fprintf(fp,"%s\n",book[i].book_number);  
        fprintf(fp,"%s\n",book[i].book_name);
        fprintf(fp,"%s\n",book[i].book_writer);
        fprintf(fp,"%s\n",book[i].book_price);
    }  
    fclose(fp);  
} 

void sort_function(void)//������ 
{
	int choose;
	while(1)
	{
		system("cls");
		printf("\n\n\t\t*****************************************");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t   ��ӭ���������ܹ���\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      ����������밴1\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      �����������밴2\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      �����������밴3\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*****************************************");
		printf("\n\t\t\t\t");
		printf("\n\t\t\t       ������ѡ��:\n\t\t\t\t   ");
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
				printf("\n\t\t\t   �����������������\n\n\t\t\t    "); 
			system("PAUSE");  
	        system("cls");
		}		
	}
} 

void sort_book_number(void)//���������
{
	int i;
	for(i=0;i<book_count;i++)
		sort(book,book+book_count,cmp_book_number);	
	printf("\n\t\t\t�������\n\n\t\t\t");
	save_book();
	system("PAUSE"); 
} 

void sort_book_name()//���������� 
{
	int i;
	for(i=0;i<book_count;i++)
		sort(book,book+book_count,cmp_book_name);	
	printf("\n\t\t\t�������\n\n\t\t\t");
	save_book();
	system("PAUSE");
}

void sort_book_price(void)//����������
{
	int i;
	for(i=0;i<book_count;i++)
		sort(book,book+book_count,cmp_book_price);	
	printf("\n\t\t\t�������\n\n\t\t\t");
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

void add_function(void)//��ӹ���
{
	int i;
	system("cls");
	printf("\n\t\t\t��ͼ��ϵͳ����%d����\n",book_count); 
	printf("\n\t\t\t������Ҫ��ӵ����\n\t\t\t\t",book_count); 
	scanf("%s",book[book_count].book_number);
	printf("\n\t\t\t������Ҫ��ӵ�����\n\t\t\t\t",book_count); 
	scanf("%s",book[book_count].book_name);
	printf("\n\t\t\t������Ҫ��ӵ�����\n\t\t\t\t",book_count); 
	scanf("%s",book[book_count].book_writer);
	printf("\n\t\t\t������Ҫ��ӵĵ���\n\t\t\t\t",book_count); 
	scanf("%s",book[book_count].book_price);
	printf("\n\t\t\t��ӳɹ�\n\t\t\t\t"); 
	book_count++;
	save_book();
	system("PAUSE");
	return; 
}

void find_function(void)//���ҹ���
{
	int choose;
	while(1)
	{
		system("cls");
		printf("\n\n\t\t*****************************************");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t   ��ӭ�������ҹ��ܹ���\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      ����Ų����밴1\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      �����������밴2\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*\t      �����۲����밴3\t\t*");
		printf("\n\t\t*\t\t\t\t\t*");
		printf("\n\t\t*****************************************");
		printf("\n\t\t\t\t");
		printf("\n\t\t\t       ������ѡ��:\n\t\t\t\t   ");
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
				printf("\n\t\t\t   �����������������\n\n\t\t\t    "); 
			system("PAUSE");  
	        system("cls");
		}		
	}
} 

void find_book_number(void)//����Ų���
{
	int i,t=-1;
	char str[20];
	while(1)
	{
		system("cls");
		printf("\n\t\t\t������Ҫ���ҵ����\n\t\t\t\t");
		scanf("%s",str);
		for(i=0;i<book_count;i++)
			if(strcmp(book[i].book_number,str)==0)
			{
				t=i;
				break;
			}
		if(t==-1)
		{
			printf("\n\t\t\t����Ų����ڣ�����������\n\n\t\t\t    ");
			system("PAUSE");
			continue;
		}
		printf("\n\t\t\t���ҳɹ�");
		printf("\n\t\t\t��ţ�%s",book[t].book_number);
		printf("\n\t\t\t������%s",book[t].book_name);
		printf("\n\t\t\t���ߣ�%s",book[t].book_writer);
		printf("\n\t\t\t���ۣ�%s",book[t].book_price);
		printf("\n\t\t\t"); 
		system("PAUSE");
		break;	
	}	
} 

void find_book_name(void)//����������
{
	int i,t=-1;
	char str[20];
	while(1)
	{
		system("cls");
		printf("\n\t\t\t������Ҫ���ҵ�����\n\t\t\t\t");
		scanf("%s",str);
		for(i=0;i<book_count;i++)
			if(strcmp(book[i].book_name,str)==0)
			{
				t=i;
				break;
			}
		if(t==-1)
		{
			printf("\n\t\t\t�����������ڣ�����������\n\n\t\t\t    ");
			system("PAUSE");
			continue;
		}
		printf("\n\t\t\t���ҳɹ�");
		printf("\n\t\t\t��ţ�%s",book[t].book_number);
		printf("\n\t\t\t������%s",book[t].book_name);
		printf("\n\t\t\t���ߣ�%s",book[t].book_writer);
		printf("\n\t\t\t���ۣ�%s",book[t].book_price);
		printf("\n\t\t\t"); 
		system("PAUSE");
		break;	
	}	
} 

void find_book_price(void)//�����۲���
{
	int i,t=-1;
	char str[20];
	while(1)
	{
		system("cls");
		printf("\n\t\t\t������Ҫ���ҵĵ���\n\t\t\t\t");
		scanf("%s",str);
		for(i=0;i<book_count;i++)
			if(strcmp(book[i].book_price,str)==0)
			{
				t=i;
				break;
			}
		if(t==-1)
		{
			printf("\n\t\t\t�õ��۲����ڣ�����������\n\n\t\t\t    ");
			system("PAUSE");
			continue;
		}
		printf("\n\t\t\t���ҳɹ�");
		printf("\n\t\t\t��ţ�%s",book[t].book_number);
		printf("\n\t\t\t������%s",book[t].book_name);
		printf("\n\t\t\t���ߣ�%s",book[t].book_writer);
		printf("\n\t\t\t���ۣ�%s",book[t].book_price);
		printf("\n\t\t\t"); 
		system("PAUSE");
		break;	
	}	
} 

void delete_function(void)//ɾ������
{
	int i,t=-1;
	char str[20];
	while(1)
	{
		system("cls");
		printf("\n\t\t\t������Ҫɾ�������\n\t\t\t\t");
		scanf("%s",str);
		for(i=0;i<book_count;i++)
			if(strcmp(book[i].book_number,str)==0)
			{
				t=i;
				break;
			}
		if(t==-1)
		{
			printf("\n\t\t\t   �����������������\n\n\t\t\t    ");
			system("PAUSE");
			continue;
		}
		printf("\n\t\t\t��ţ�%s",book[t].book_number);
		printf("\n\t\t\t������%s",book[t].book_name);
		printf("\n\t\t\t���ߣ�%s",book[t].book_writer);
		printf("\n\t\t\t���ۣ�%s",book[t].book_price);
		printf("\n\t\t\t�Ƿ�ȷ��ɾ��%d�������Ϣ",t);
		printf("\n\t\t\t���밴1"); 
		printf("\n\t\t\t���밴0\n\t\t\t\t");
		scanf("%d",&t);
		if(t==0)
			return; 
		strcpy(book[t].book_name,"");
		strcpy(book[t].book_number,"");
		strcpy(book[t].book_writer,"");	
		strcpy(book[t].book_price,"");
		printf("\n\t\t\tɾ���ɹ�\n\t\t\t\t");
		save_book();
		system("PAUSE");
		break;	
	}
} 

void reset_function(void)//�޸Ĺ��� 
{
	int i,t=-1;
	char str[20];
	while(1)
	{
		system("cls");
		printf("\n\t\t\t������Ҫ�޸ĵ����\n\t\t\t\t");
		scanf("%s",str);
		for(i=0;i<book_count;i++)
			if(strcmp(book[i].book_number,str)==0)
			{
				t=i;
				break;
			}
		if(t==-1)
		{
			printf("\n\t\t\t   �����������������\n\n\t\t\t    ");
			system("PAUSE");
			continue;
		}
		printf("\n\t\t\t��ţ�%s",book[t].book_number);
		printf("\n\t\t\t������%s",book[t].book_name);
		printf("\n\t\t\t���ߣ�%s",book[t].book_writer);
		printf("\n\t\t\t���ۣ�%s",book[t].book_price);
		printf("\n\t\t\t�����������\n\t\t\t\t");
		scanf("%s",book[t].book_number);
		printf("\n\t\t\t������������\n\t\t\t\t");
		scanf("%s",book[t].book_name);
		printf("\n\t\t\t������������\n\t\t\t\t");
		scanf("%s",book[t].book_writer);
		printf("\n\t\t\t�������µ���\n\t\t\t\t");
		scanf("%s",book[t].book_price);
		printf("\n\t\t\t�޸ĳɹ�\n\t\t\t\t");
		save_book();
		system("PAUSE");
		break;	
	}
}

void look_function(void)//�������
{
	int i;
	system("cls");
	for(i=0;i<book_count;i++)
	{
		printf("��ţ�%s",book[i].book_number);
		printf("\n������%s",book[i].book_name);
		printf("\n���ߣ�%s",book[i].book_writer);
		printf("\n���ۣ�%s",book[i].book_price);
		printf("\n\n");
	}
	system("PAUSE");
}
