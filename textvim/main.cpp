#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 240
#define NOT_FOUND -1
//��������    
void PrintWord(void);    //����ı������� 
void scanf_load();       //�Ӽ���¼���ı� 
void file_load();        //���ı��ļ������ݶ������Ա���
void findstr();          //�����ַ��� 
void delete1(int linenum);//ɾ��һ��
void delete2(int linenum,int position,int lenth);//ɾ��Īһ��,Ī�У����������� 
void insert1();           // ����һ������
void insert2(char str[], int linenum, int position);//�������ֵ��ı�Īһ��Īһ��
void replace();          //�滻
void Mainmenu();          //���˵�
void menu1();                //�ļ�¼�뷽ʽ�˵�
void menu2();               //�ı����ݴ���˵�
void menu_move();          //�ƶ��˵� 
int Index_BF(struct line *info,char *);
//����ṹ��
struct line
{
	char text[MAX];      //���е����� 
	int num;                 //������¼�к�
	struct line *prior;      //����ָ��ǰһ��
	struct line *next;       //����ָ����һ��
 };
struct line *start;          //ָ�����Ա�ĵ�һ��
struct line *last;           //ָ�����Ա�����һ��

//������ 
int main()
{	
	Mainmenu();
	return 0;	
}
// 	������������ 
void PrintWord()
{
	struct line *p = start;
	while(p != last)
	{
		printf("\n\t\t��%d��|%s",p->num,p->text);
		p = p->next;
	}
	//����ֻ��һ�е����
	printf("\n\t\t��%d��|%s",last->num,last->text);
	printf("\n");
}
//���ı��ļ������ݶ������Ա���
void file_load()
{
	struct line *info,*temp;   //��ָ�룬infoָ��ǰ�У�tempָ��info��ǰ���� 
	char ch;
	temp = NULL;
	int linenum,i=0;	   //�м�����,���ַ������±� 
	FILE *fp;          //�ļ�ָ�� 
	char name[20];
	printf("������Ҫ���ļ����֣�����c:\a.txt��");
	scanf("%s",name);		
	while ((fp=fopen(name,"r"))==NULL)
	{
			printf("\n���ļ�ʧ�ܣ�����������Ҫ�򿪵��ļ�����");
			scanf("%s",name);
    }
	start = (struct line*)malloc(sizeof(struct line));     //����һ�еĽ��ռ� 
	info = start;
	linenum = 1;
	
	while((ch = fgetc(fp)) != EOF)
	{     
			i = 0;
			info->text[i] = ch;
			i++;
			while((ch = fgetc(fp)) != '\n')      //���ļ��ж���һ���ַ������Ա��� 
			{	
				info->text[i] = ch;
				i++;
			}
	info->num = linenum++;
	info->next = (struct line*)malloc(sizeof(struct line));
	if (!info->next)
	{
		printf("\n\t\t�ڴ治��"); 
		getchar();
		exit(0);
	}

	temp = info;
	info = info->next;
	info->prior = temp;
 	} 
 	last = info->prior;
 	printf("\t\t�ļ��������\n"); 
 	fclose(fp);
 	
}

//�Ӽ���¼���ı� 
void scanf_load()
{	
	struct line *info,*temp;                 //��ָ�룬infoָ��ǰ�У�tempָ��info��ǰ���� 
	char ch;
	temp = NULL;
	int linenum,i;							   //�м�����,���ַ������±� 
	FILE *fp;                                 //�ļ�ָ�� 
	temp = NULL;
	start = (struct line*)malloc(sizeof(struct line));     //����һ�еĽ��ռ� 
	info = start;//��ǰ�ǵ�һ��
	linenum = 1;
	printf("\t\t��Ӽ���¼���ı�(����ʱ�س����У�������������µ�һ������#����¼��)\n\t\t"); 
	while((ch = getchar()) !='#')
	{
			i = 0;
			info->text[i] = ch;
			i++;
			while((ch = getchar()) != '\n')      //�Ӽ��̶���һ���ַ������Ա��� 
			{				
				info->text[i] = ch;
				i++;			
			}//��ѭ������������һ�����������Ȼ��ִ������Ĵ���
		printf("\t\t");		
		info->text[i] = '\0';
		info->num = linenum++;//���ٵڶ���
		info->next = (struct line*)malloc(sizeof(struct line));//��һ�з���ռ�
		info->prior = temp;
		temp = info;//��ǰ�и���ǰ����
		info = info->next;//��һ�и�����ǰ��
 	} //���������
 	temp->next = NULL;
 	last = temp;
 	free(info);
 	start->prior = NULL;
}

//�ļ�����
void save()
{
    system("cls");
	FILE *fp;
    line *info=start;
	int i=0;
    char name[20];
	printf("\n�����뱣���ַ(����: c:\\a.txt):");
	scanf("%s",name);
		while ((fp=fopen(name,"w+"))==NULL)
		{
			printf("�ļ������ڣ������������ļ�����");
			scanf("%s",name);
		} 
	while(info)
	{   
        while(info->text[i]!='\n')  
		{fprintf(fp,"%c",info->text[i]);
		 i++;
		}
		info = info->next;
		i = 0;
	}
	    
        fclose(fp);
		printf("\n�ļ�����ɹ�\n");	

}
//BF�㷨
int Index_BF(struct line *info,char *str){
	int i=1,j=1;
	//printf("test\n");
	while(i<=strlen(info->text)&&j<=strlen(str)){//������δ�ﵽĩβ
		if(info->text[i]==str[j]){
			++i;++j;//�����Ƚ�
		}else{
		i=i-j+2;j=1;//ָ���������ƥ��
		}
	}
	//printf("2test\n");
	if(j>strlen(str))
		return i-strlen(str);//ƥ��ɹ�
	else
		return 0;//ƥ��ʧ��
}

 //�����ַ��� 
void findstr(){

	PrintWord();
	char str[MAX];
	getchar();
	printf("\t\t ������Ҫ���ҵ��ַ�����");
	gets(str);
	printf("\t\t|>>________________________________________________<<|\n");
  	struct line *info;
	//int i = 0, find_len, found = 0, position;
	//char substring[MAX];
	info = start;
	//int find_num = 0;             //ƥ�䵽�Ĵ��� 
	//find_len = strlen(str);
	while (info)   //��ѯ
	{	
		//�������BF�㷨ʵ���ַ���ƥ��
		if(Index_BF(info,str))
			printf("\t\t������%d��%d��\n",info->num,Index_BF(info,str));
		else
			printf("\t\t���ݲ�����\n");

		/*i = 0;  //�м�ѭ��
		while (i <= (strlen(info->text) - find_len))  //���ڲ���ѭ��
		{	int k=0;
			
			for(int j=i;j<i+find_len;j++)   // ���ڵ��ַ����ӵ�һ����ʼ������find_len����substring 
			{	
				substring[k] = info->text[j]; 
				k++;
			}
			if (strcmp(substring,str) == 0)
			{	
				find_num++;
			
				printf("\t\t|��%d�γ����ڣ�%d��%d��\n",find_num,info->num,(i+1+1)/2);
				found = 1;
			}
				i++;
		}*/
		info = info->next;
	}
	/*if (found)  //���ҳɹ�
		printf("\t\t|\t\t�����ݳ��ֵ��ܴ���Ϊ%d\n",find_num);
	else   //���Ҳ��ɹ�
		printf("\t\t�����ݲ�����\n");*/
	printf("\t\t|>>________________________________________________<<|\n");
	
}

//ɾ��һ��
void delete1(int line_num)
{	
	struct line * info, *p;
	info = start;
	while ((info->num < line_num) && info)  //Ѱ��Ҫɾ������ 
		info = info->next;
	if (info == NULL)
		printf("���в�����");
	else
	{
		p = info->next;     //ָ��Ҫɾ�����к���һ�� 
		if (start == info) //���ɾ�����ǵ�һ��
		{
			start = info->next;
			if (start)  //���ɾ���󣬲�Ϊ��
				start->prior = NULL;
			else  //ɾ����Ϊ��
				last = NULL;
		}
		else
		{
			info->prior->next = info->next;  //ָ���е���һ��ָ��ָ���е���һ��
			if (info != last) //����������һ��
				info->next->prior = info->prior;  //�޸�����һ�е�ָ��ͷ��ָ�� 
			else  //��������һ�У��޸�βָ��
				last = info->prior;
		}
		free(info);
		while (p) //��ɾ����֮����кż�һ 
		{
			p->num = p->num - 1;
			p = p->next;
		}

	}

}

//ɾ��Īһ��,Ī�У����������� 
void delete2(int line_num,int position,int lenth)
{	
	
	struct line *info=start;
	char rest_str[MAX];
	if(line_num == 1)
	info = start;
	else
	for(int i=1;i<line_num;i++)     	 //��infoָ��ɾ������������ 
	info = info->next;      
	if (info == NULL)
		printf("����û���ַ���n");
	else
	{
		if (strlen(info->text) <= (position + lenth))  //���е��ַ�����<=��ɾ�����к�+ɾ�����ȣ�ֱ���ڵ�ǰλ�ò���'\0'
			info->text[position] = '\0';
		else
		{	int i;
			for(i = position-1;info->text[i+lenth]!='\0';i++)
			info->text[i]=info->text[i+lenth];
			info->text[i]='\0';
		}
	}
}


// ����һ������
void insert1()
{	
	int linenum; 
	printf("\t\t�������λ�õ��кţ�");
	scanf("%d", &linenum);
	struct line * info, * q, * p;
	p = start;
	q = NULL;

	while (p && p->num != linenum)               
	{
		q = p;				//������ǰ��һ�� 
		p = p->next;	   //�����к���һ��
	}

	if (p == NULL && (q->num + 1) != linenum)	//ָ���в����ڣ����ܲ���
	{
		printf("\t\t������кŲ�����");
	}

	else // ָ���д��ڣ����в���
	{
		info = (struct line *)malloc(sizeof(struct line));
		printf("\t\t����Ҫ������ַ���:");
		scanf("%s", info->text);
		info->num = linenum;
		if (linenum == 1)  			  //�����ڵ�һ��
		{
			info->next = p;
			p->prior = info;
			info->prior = NULL;
			start = info;
		}

		else if (q->num != linenum)  //���������һ��
		{
			q->next = info;
			info->next = p;
			info->prior = q;
		}

		else     //������������
		{
			q->next = info;
			info->next = p;
			p->prior = info;
			info->prior = q;
		}

		while (p)   //������ǲ��������һ�У������к�����кŶ���1
		{
			p->num = p->num + 1;
			p = p->next;
		}

	}

}

//�������ֵ��ı�Īһ��Īһ��
void insert2(char str[], int linenum, int position)
{
	
	struct line * info;
	int len, i;
	int lenth;
	char rest_str[MAX],kongge[2] = { " " };
	info = start;
	while (info && info->num != linenum)   //��ѯҪ�������
	{
		info = info->next;
	}
	if (info == NULL)
		printf("�����ڸ��У�\n");
	else if (position < 0)
		printf("�����ڸ��У�\n");
	else    //����к��ж����ڣ�����в���
	{
		lenth = strlen(info->text);
		if (lenth < position)	//�����д��ڱ����ļ�����
		{
			len = position - lenth - 1;
			for (i = 0; i < len; i++)
			strcat(info->text, kongge);   //������Ĳ��ֲ���ո��
			strcat(info->text, str);    //�����ַ����е�δβ
		}

		else   //�������ڱ������ֵ��м�
		{
			strcpy(rest_str, &info->text[position - 1]);
			strcpy(&info->text[position - 1], str);
			strcat(info->text, rest_str);
		}
	}
} 
 
//�滻
void replace()
{
	PrintWord();
	char str[MAX];
	printf("\t\t������Ҫ�滻���ַ�����\t\t");
	scanf("%s",&str);
	char replace[MAX]; 
	printf("\t\t�滻Ϊ��"); 
	scanf("%s",&replace);
  	struct line *info;
	int i = 0, find_len, found = 0, position;
	char bijiao[MAX];
	info = start;
	int find_num = 0;             //ƥ�䵽�Ĵ��� 
	find_len = strlen(str);
	while (info)   //��ѯ
	{	
		
		i = 0;  //�м�ѭ��
		while (i <= (strlen(info->text) - find_len))  //���ڲ���ѭ��
		{	int k=0;
			
			for(int j=i;j<i+find_len;j++)   // ���ڵ��ַ����ӵ�һ����ʼ������find_len����substring 
			{	
				bijiao[k] = info->text[j]; 
				k++;
			}
			if (strcmp(bijiao,str) == 0)
			{	
				find_num++;
				delete2(info->num,i+1,find_len);
				insert2(replace,info->num,i+1);
				found = 1;
			}
				i++;
		}
		info = info->next;
	}
	if (found)  //���ҳɹ�
		printf("\t\t�������滻���ܴ���Ϊ%d\n",find_num);
	else   //���Ҳ��ɹ�
		printf("\t\t�����ݲ�����\n");
	printf("\t\t�����滻�������Ϊ��\n");
	PrintWord();
	
	
 } 

//�ļ�¼�뷽ʽ�˵�
void menu1()
{	
	printf("\t\t|��ѡ��¼�뷽ʽ    1���Ӽ�������     2�����ļ�¼��   |\n\t\t");
	int i;
	scanf("%d",&i);
	getchar();
		if(i>2||i<1)    
	{   
		printf("\t\t�Բ�����������ȷ�Ĺ������!\n");
	}
	switch(i)
	{
		case 1:
			scanf_load();
			system("cls"); 
			break;
		case 2:
			file_load();
			system("cls"); 
			break;				 
 	} 
}

//�ƶ��˵� 
void menu_move()
{	
	
	int choice;
	printf("\n\t\t|______________�ƶ�����___________________|\n");
	printf("\n\t|----->1.      �����ƶ�һ��         <-----------|\n");
	printf("\t\t|----->2.      �����ƶ�һ��         <-----------|\n");
	printf("\t\t|----->3.      �����ƶ�һ��         <-----------|\n");
	printf("\t\t|----->4.      �����ƶ�һ��         <-----------|\n");
	printf("\t\t|----->5.      �����ϼ��˵�         <-----------|\n");
	printf("\t\t��ѡ��");
	scanf("%d",&choice); 
	int line_num,number;
	char str[2];
	switch (choice)
			{
			case 1:   // �����ƶ�һ��
				
				printf("\t\t����Ҫ�ƶ����ַ��������кţ�");
				scanf("%d", &line_num);
				struct line *info,*p;                    //�½�һ�п��� 
				info = (struct line *)malloc(sizeof(struct line));
				info->text[0] = ' ';
				info->text[1] = '\0';
				info->num = line_num;
				if (line_num == 1)    //����������
				{	
					info->next = start;
					start->prior = info;
					start = info;
					start->prior = NULL;
					p=start->next;
				}
				else  //������������
		        {
		       	p=start;
		    	while (p->num != line_num)
					p = p->next;                    //��pָ������� 
				info->next=p;
				info->prior=p->prior;
				p->prior->next=info;
				p->prior = info;}
				while (p)   //�����к�����кŶ���1
				 {
					p->num = p->num + 1;
					p = p->next;
				 }
				break;
			case 2:   //�����ƶ�һ��
				printf("\t\t����Ҫ�ƶ����ַ��������кţ�");
				scanf("%d",&line_num);
				delete1(line_num-1);
				break;
			case 3:   //�����ƶ�һ��
				printf("\t\t����Ҫ�ƶ����ַ��������кţ�");
				scanf("%d", &line_num);
				printf("\t\t����Ҫ�ƶ����ַ��������кţ�");
				scanf("%d", &number);
				str[0] = ' ';
				str[1] = '\0';
				insert2(str, line_num, number);
				break;
			case 4:   //�����ƶ�
				printf("\t\t����Ҫ�ƶ����ַ��������кţ�");
				scanf("%d", &line_num);
				printf("\t\t����Ҫ�ƶ����ַ��������кţ�");
				scanf("%d", &number);
				if (number <= 0)
					printf("\t\t���в�����");
				else
					delete2(line_num, number - 2, 1);
				break;
			case 5:   //�˳��ƶ�
				break;

} 
	
}

//�ı����ݴ���˵�
void menu2()
{  
	char str1[20];
	char str2[20];
	int a;
while(1)
{	

	printf("\t\t___________________\n");
	printf("\t\t1�������ַ����ַ���\n");
	printf("\t\t2��ɾ���ַ����ַ���\n");
	printf("\t\t3�������ַ����ַ���\n");
	printf("\t\t4���ƶ��ַ����ַ���\n");
	printf("\t\t5���滻�ַ����ַ���\n");
	printf("\t\t6���������˵�      \n");
	printf("\t\t7��ֱ���˳�ϵͳ    \n");
	printf("\t\t___________________\n");
	printf("\t\t    ��ѡ��:");
	scanf("%d",&a);
	switch(a)
	{
		case 1:   
	       	 system("cls"); 
	      	 
         	 findstr();
		  	 printf("\t\t���س�����������������");
			 getchar();
		   	 getchar();
			 system("cls");
		     break;
	   case 2:
	         system("cls"); 
	         
	         printf("\t\t|    1:ɾ��һ������    2:ɾ��ĳһ��,ĳ�У�����������|\n\t\t");
	         int delete_choice;
             scanf("%d",&delete_choice);
             getchar();
             if(delete_choice == 1)
           	{
				   int linenum;
				   printf("\t\t��ǰ�ı�Ϊ��\n");
				   PrintWord();
           		   printf("\t\t��������ɾ���е��кţ�");
			       scanf("%d",&linenum);
				   getchar(); 
           		   delete1(linenum);
			}
             else if(delete_choice == 2)
			{
				   int linenum, position,lenth;  //�У��У�ɾ������ 
				   printf("\t\t��ǰ�ı�Ϊ��\n");
				   PrintWord();
			       printf("\t\t������Ҫɾ�����������У��У�ɾ�������ֽڳ��ȣ��м��ÿո����\n");
				   printf("\t\t--->ע�⣺����ռ�����ֽ�\n\t\t");
				   scanf("%d %d %d",&linenum,&position,&lenth);
				   position = (position*2)-1;
				   getchar();
				   delete2(linenum,position,lenth);
			}
            printf("\t\tɾ���������Ϊ:\n");
            PrintWord();
		    printf("\t\t���س�����������������");
			getchar();
			getchar();
			system("cls");
		    break;
      case 3:
           
	        system("cls"); 
	        
            printf("\t\t|   1:����һ������      2���������ֵ��ı���һ�е��м�|\n\t\t");
            int insert_choice;
            scanf("%d",&insert_choice);
            if(insert_choice == 1)
            {
            printf("\t\t��ǰ�ı�Ϊ��\n");
			PrintWord();
			insert1();}
            else
           {
           	printf("\t\t��ǰ�ı�Ϊ��\n");
			PrintWord();
		    char str[MAX]; int linenum; int position;
		    printf("\t\t�������λ��һ�кţ�");
			scanf("%d", &linenum);
			printf("\t\t�������λ��-�кţ�");
			scanf("%d", &position);
			position = (position*2)-1;
			printf("\t\tҪ������ַ�����");
			scanf("%s", str);
			insert2(str,linenum,position);
		   }
           
            printf("\t\t�����ַ����ַ���������Ϊ:\n");
            PrintWord();
		    printf("\t\t���س�����������������");
			getchar();
			getchar();
			system("cls");
		    break;
	 case 4:
		    system("cls");
		    			
		    menu_move();
		    printf("\t\t�ƶ����ı�����Ϊ��\n");
			PrintWord();
		    printf("\t\t���س�����������������");
			getchar();
			getchar();
			system("cls");
		    break;
	 case 5: 
		    system("cls"); 

		    replace();
		    printf("\t\t���س�����������������");
			getchar();
			getchar();
			system("cls");
	        break;
	 case 6:
		 system("cls");
		 break;
	 case 7:
		 exit(0);
     }       
  }
}
//���˵�

void Mainmenu()
{	
	int t;
	while(1){
	printf("\n");
	printf("\t\t ____________________________________________________\n");
	printf("\t\t|                 ���˵�                             |\n");
	printf("\t\t|                                                    |\n");
	printf("\t\t|---->  1��������������                              |\n");
	printf("\t\t|---->  2�������������ݴ���˵�                      |\n");
	printf("\t\t|---->  3����ʾ��ǰ��������                          |\n");
	printf("\t\t|---->  4�������ı�                                  |\n");
	printf("\t\t|---->  5���˳��ı��༭��                            |\n");
	printf("\t\t|                                                    |\n");
	printf("\t\t|    ע����һ�����б�����ʱ��ѡ����1               |\n");
	printf("\t\t|____________________________________________________|\n");
	printf("  \t\t  ��ѡ��:");
	scanf("%d",&t);
	if(t>5||t<1)
	{   
		printf("�Բ����޴˹��ܣ���������ȷ�Ĺ������!\n");
	}
	else
	switch(t)
	{  
    	case 1:  
		     system("cls"); 		     
		     menu1();
			 printf("\t\t���س�����������������");
			 getchar();
			 getchar();
			 system("cls");
             break;
    	case 2:  
		     system("cls"); 
		     menu2();
			 break;
		case 3:
		     system("cls"); 
		     
			 printf("\n\t\t ____________________��������Ϊ______________________\n");
             PrintWord();
			 printf("\n");
			 printf("\t\t���س�����������������");
			 getchar();
			 getchar();
			 system("cls");
			 break;
		case 4:	 
		     save();
		     break;
		case 5:
			break;
	  }
   }
}