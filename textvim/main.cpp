#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string>
#include<iostream>
#include<conio.h>

#define Link_Size 100

int NUM,C,N;

typedef struct list
{
    char data[80];
    int length;
    struct list *next;
    struct list *pre;
    int row;
} LinkList;

int initlist(Sqlist *L)  //˳���ĳ�ʼ��

LinkList *CreatWord()    //�ı�������
{
    LinkList *temp;
    char ch;
    int i,j;
    head->next=(LinkList *)malloc(sizeof(LinkList));
    head->pre=NULL;

    temp=head->next;
    temp->pre=null;
    temp->length=0;

    for(i=0; i<80; i++)
        temp->data[i]='\0';//��ʼ����ֵ

    printf("��ʼ�����ı������������£�����#�Ž�������\n");
    for(j=0; j<Link_Size; j++)
    {
        for(i=0; i<80; i++)
        {
            ch=getchar();
            temp->data[i]=ch;
            temp->length++;
            if(ch=='#')
            {
                NUM=j;
                break;
            }
        }
        if(ch=='#')
        {
            temp->length=i;
            temp->next=NULL;
            break;
        }
        temp->next=(LinkList *)malloc(sizeof(LinkList));
        temp->next->pre=temp;
        temp=temp->next;
        for(i=0; i<80; i++)
            temp->data[i]='\0';
    }
    temp->row=NULL+1;
    system("cls");
    return temp;

}
void PrintWord()//�ı��������

{

    int i,j;

    LinkList *p;

    p=head->next;

    system("cls");

    //HeadWord();

    printf("\n��ǰ���µ�������:");

    for(j=0; j<=NUM&&p!=NULL; j++)

    {

        for(i=0; (i<80)&&(p->data[i])!='#'; i++)

        {

            printf("%c",p->data[i]);

        }

        p=p->next;

    }

}

void ReplaceWord(char *shr1,LinkList* temp)//�ı����滻����
{
    char Date1[20],Date2[20];
    int i,j,k=0,sum=0;
    int i=1;
    temp=head->next;
    strcpy(Date1,str1);//���滻���ݵĸ�ֵ
    strcpy(Date2,str2);//�滻���ݵĸ�ֵ

    for(i=0; i<=NUM; i++)

    {

        for(j=0; j<80; j++)

        {

            if((temp->data[j])==Data1[k])
                k++;

            else if(Data1[k]!='\0')

            {

                j=j-k;

                k=0;

            }

            if(Data1[k]=='\0')

            {
                int n;
                n=j-k+1;
                for(m=0; m<sizeof(str2); k++)
                {
                    temp->data[n]=Date2[m];//�滻ֵ
                    n++;
                }

                l++;

                k=0;

                continue;
            }

        }

        temp=temp->next;

    }
    printf("�滻����ı��������£�\n")��
    PrintWord();
}
void SearchWord(char *str1,LinkList* temp)//�ı����ݲ��Һ���

{

    char Data[20] ;

    int i,j,k=0,sum=0;

    int l=1;

    temp=head->next;

    strcpy(Data,str1);


    for(i=0; i<=NUM; i++)

    {

        for(j=0; j<80; j++)

        {

            if((temp->data[j])==Data[k])
                k++;

            else if(Data[k]!='\0')

            {

                j=j-k;

                k=0;

            }

            if(Data[k]=='\0')

            {

                sum++;

                j=j-k+1;

                printf("\t\t��%d�γ����ڵ�%d�е�%d��\n",l,i+1,j+1);

                l++;


                k=0;

                continue;
            }

        }

        temp=temp->next;

    }

    printf("\t\t\t�ַ����ܹ����ִ���Ϊ:%d\n\n",sum);

    C=sum;

    N=i*80+j;

}
void DeleteWord(char *str2)//�ı�����ɾ������

{
    char Data[20];

    LinkList *temp,*term;

    int i,j,k,m,y,num;

    strcpy(Data,str2);

    for(y=0; y<C; y++)

    {

        num=80;

        k=0,m=0;

        temp=head;

        for(i=0; i<=NUM; i++)

        {

            term=temp;

            temp=temp->next;

            for(j=0; j<80; j++)

            {

                if((temp->data[j])==Data[k])
                    k++;

                else if(Data[k]!='\0')
                {
                    j=j-k;
                    k=0;
                }

                if(Data[k]=='\0')

                {

                    num=j;

                    break;

                }

            }

            if(num<80)
                break;

        }

        for(; i<=NUM; i++)

        {

            for(; j<80; j++)

            {

                if(j+1<k)

                {

                    term->data[80-k+num]=temp->data[j+1];

                }

                else

                    temp->data[j-k+1]=temp->data[j+1];

            }

            term=temp;

            temp=temp->next;

            j=0;

        }

    }


}
LinkList * InsertWord(LinkList *temp)//�ı����ݲ��뺯��

{

    char Data[20];

    int h,l;


    printf("\n\t\t������Ҫ������ַ����ַ���:");

    getchar();

    gets(Data);

    printf("\n\t\t��ǰ��������Ϊ:");

    PrintWord();

    printf("\n\t\t������Ҫ�������:");

    scanf("%d",&h);

    printf("\n\t\t������Ҫ�������:");

    scanf("%d",&l);

    int i=(h-1)*80+l;

    LinkList *a;

    int n=strlen(Data);

    int m ;

    int insertRow=i/80+1;

    int row=temp->row;

    int j;

    if(insertRow==row)

    {

        for(m=temp->length-1; m>=(i%80)&&n>0; m--)

            temp->data[m+n]=temp->data[m];

        for(m=(i%80),j=0; m<n+(i%80); m++,j++)

        {

            temp->data[m]=Data[j];

        }

    }

    else

    {

        int r=0;

        for(int p=insertRow; p<row; p++)

        {

            if(p == insertRow)

                r=0;

            else

                r=n;


            for(m=temp->length-1-r; m>=0&&n>0; m--)

                temp->data[m+n]=temp->data[m];

            a=temp;

            temp = temp->pre;

            temp->length = 80;

            for(m = temp->length-n,j=0; m<temp->length; m++,j++)

                a->data[j]=temp->data[m];

        }

        for(m=temp->length-n-1; m>=(i%80); m--)

            temp->data[m+n]=temp->data[m];

        for(m=(i%80),j=0; m<(i%80)+n; m++,j++)

            temp->data[m] =Data[j];


    }

    return temp;

}

void FileSave()//�ļ����뺯��
{
    LinkList *s;
    s=head->next;

    FILE *fpWrite=fopen("data.txt","w");//���ݴ����ļ�
    if(fpWrite==NULL)
    {
        return 0;
    }
    for(j=0; j<Link_Size; j++)
    {
        for(i=0; i<80; i++)
        {
            j=s->data[i];
            fprintf(fpWrite,"%d ",j);
        }
    }
    fclose(fpWrite);
    printf("�����Ѵ��뵽�ļ��У�\n");

}

void FileRead()//�ļ��Ķ�ȡ
{
    LinkList *r;
    r=head->next;

    FILE *fpRead=fopen("data.txt","r");

    if(fpRead==NULL)

    {
        return 0;
    }

    for(j=0; j<Link_Size; j++)
    {
        for(i=0; i<80; i++)
        {
        fscanf(fpRead,"%d ",&s->date[i]);
        printf("%d ",s->date[i]);
    }

    printf("�����Ѵ��ļ��ж�ȡ�ɹ���\n");
    getchar();//�ȴ�
}

}





void main()
{
    printf("\t\t\t*************************************************************\t\t\t\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*                       �� �� �� �� ��                      *\n");
    printf("\t\t\t*                                                           *\n");
    printf("\t\t\t*************************************************************\t\t\t\n");
    printf("\t\t\t*                    �� ִ �� �� �� �� ��                   *\n");
    printf("\t\t\t*************************************************************\t\t\t\n");
    printf("\t\t\t* {1}���ı�������    \t\t\t    {2}���ı����޸� *        \n");
    printf("\t\t\t* {3}���ı���ɾ��    \t\t\t    {4}���ı��Ĳ��� *        \n");
    printf("\t\t\t* {5}���ı����滻    \t\t\t    {6}���ı��Ĳ��� *        \n");
    printf("\t\t\t* {7}���ı����ƶ�    \t\t\t    {8}���ı������ *        \n");
    printf("\t\t\t* {9}���ļ��Ĵ���    \t\t\t    {10}���ļ��Ķ�ȡ *        \n");
    printf("\t\t\t*************************************************************\t\t\t\n");
    printf("\t\t\t��ʾ��������ǵ�һ��ʹ���ı���������ѡ���һѡ��������ݵ����룡\n");
    printf("\t\t\t����������ѡ��\n");
    scanf("%d",&a);

    switch(a)

    {

    case 1:

        system("cls");

        CreatWord();

        printf("\t\t\t��������Ҫ������ı�����:\n");

        getchar();

        gets(str1);

        SearchWord(str1,temp);

        printf("���س�����������������");

        getchar();

        getchar();

        system("cls");

        break;

    /*case 2:

        system("cls");

    �޸ĺ���

        printf("\t\t\t��ѡ���������޸ĵ��ַ����ַ���:");

        getchar();

        gets(str2);

        SearchWord(str2,temp);

        DeleteWord(str2);

        printf("\t\t\t�޸ĺ������Ϊ:",str2);

        PrintWord();

        printf("���س�����������������");

        getchar();

        getchar();

        system("cls");

        break;*/

    case 3:

        system("cls");

        DeleteWord(temp);

        printf("\t\t\t�޸ĺ������Ϊ:");

        PrintWord();

        printf("���س�����������������");

        getchar();

        getchar();

        system("cls");

        break;

    case 4:

        system("cls");

        SearchWord()

        printf("���س�����������������");

        getchar();

        getchar();

        system("cls");

        break;

    case 5:

        system("cls");

        ReplaceWord();

        printf("���س�����������������");

        getchar();

        getchar();

        system("cls");

        break;

    case 6:

        system("cls");

        InsertWord();

        printf("���س�����������������");

        getchar();

        getchar();

        system("cls");

        break;

    /*case 7://�ı����ƶ�

        system("cls");

        SearchWord()

        printf("���س�����������������");

        getchar();

        getchar();

        system("cls");

        break;
*/
    case 8:

        system("cls");

        PrintWord()��

        printf("���س�����������������");

        getchar();

        getchar();

        system("cls");

        break;

    case 9://�ļ��Ĵ���

        system("cls");

        FileRead();

        printf("���س�����������������");

        getchar();

        getchar();

        system("cls");

        break;


    case 10://�ļ��Ķ�ȡ

        system("cls");

        FileRead();

        printf("���س�����������������");

        getchar();

        getchar();

        system("cls");

        break;


    }

}
