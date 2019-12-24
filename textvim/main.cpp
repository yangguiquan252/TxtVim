#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRING_MAXSIZE 256   //���崮�ĳ���
#define ERR_NOMEMORY -1
char source_str[STRING_MAXSIZE]; //���ļ�����Դ���ַ������ڴ˱���
int len;    //�洢ԭʼ�ַ����ĳ���
//�������ݴ洢�Ľṹ�������ṹ�洢
typedef struct LNode
{
    char data;
    struct LNode *next;
} LNode,*LinkList;
LinkList L = 0;         //����ȫ�ֱ����ַ�������ʼָ��
void   menu();          //�˵���ʾ��������ʾ�˵����޴��ݲ�����
//�ӵ���
LinkList Init(char Init_str);  //��ʼ������������Դת��Ϊ���������//ʽ�ṹ���������Ϊ��Ҫ��ʼ�����ı���//����ֵΪLinkList���͵�ͷָ�롣
int Input(char input_string[]); //���뺯������Ĭ�����ı�ĩβ�����ı���//�������Ϊ��Ҫ������ı���Ϣ������//ֵΪ�޸ĺ���ı���Ϣ��
void Output();  //�������������ı�����������Ϣ����//����������޷���ֵ
int Search(char search_str[]);  //���Һ�����������Ӧ���ַ�����������//����Ϊָ���Ĳ����ı���Ϣ�����ز���//���Ĳ�����
void Replace(char bereplaced_str[],char replace_str[]);                      //�滻�������滻��Ӧ�ı���Ϣ�������//��Ϊ���滻���ı���Ϣ���Լ��滻����//����Ϣ��
void Insert(char insert_str[],int location);
//���뺯������ָ��λ�ò���ָ����Ϣ��//�������Ϊ��Ҫ������ı���Ϣ���Լ�//��������λ�á�
void Move(char bemoved_str[],int location);
//���ƶ����������ı���Ϣ�е�ָ����Ϣ//�ƶ���ָ��λ�ã��������Ϊ��Ҫ�ƶ�//���ı����Լ�ָ�����ƶ�λ�á�
void Delete(char delete_str[]);        //ɾ��������ɾ����Ӧ���ı���Ϣ������//����Ϊָ���ı�ɾ�����ı�
void Display(int len_dis);    //��ʾ�������������Ϊ��Ҫ��ʾ���ı�//���ȡ�
void save();    //���̺����������ı���ı����뵽����//�У��޴���������޷��ز���
void delay();       //��ʱ����
int StringLength( LinkList S );  //�󴮳��������������ΪҪ��Ĵ��ĳ�//�ȣ����ز���Ϊ�ı��ĳ���
void statistics();            //ͳ���������޴���������޷���ֵ��
void KMPGetNext(char *T,int n2,int nextval[]);
int KMPIndex(char *S,int n1,char *T,int n2); //KMP�㷨�����ı���λ��
void KMPGetNext(char *T,int n2,int nextval[])
//���Ӵ�T��next��������ֵ����������nextval
{
    int j=1,k=0;
    nextval[0]=-1;
    while(j<n2)
    {
        if(k==0||T[k]==T[j])
        {
            nextval[j]=T[k]==T[j]?nextval[k]:k;
            j++;
            k++;
        }
        else
            k=nextval[k];
    }
}
int KMPIndex(char *S,int n1,char *T,int n2)
//�����Ӵ�T��next������T������S�е�λ��
{
    int i=0,j=0;
    int *next=(int *)malloc(n2*sizeof(int));
    if(!next)
        return ERR_NOMEMORY ;
    KMPGetNext(T,n2,next);
    while(i<n1&&j<n2)
    {
        if(j==-1||S[i]==T[j])            //�����ȽϺ���ַ�
        {
            i++;
            j++;
        }
        else                            //ģʽ�������ƶ�
            j=next[j];
    }
    free(next);
    return (j>=n2?i-n2:-1);
}
int Search(char search_str[])
{
    char s[STRING_MAXSIZE];
    int i=0;
    int search_loc,search_len,s_len;
    LNode *p;
    p=L->next;
    while(p)                                //��ȡ�޸ĺ���ı���Ϣ
    {
        s[i++]=p->data;
        p=p->next;
    }
    s_len=strlen(s);
    search_len=strlen(search_str);
    if(search_len <= s_len)
    {
        search_loc = KMPIndex(s,s_len,search_str,search_len);        //����KMP�㷨��ȡ���ҵ�λ��
        return search_loc;
    }
    else
    {
        return -1;                            //δ�ҵ�
    }
}
int Replace(char replaced_str[],char replace_str[])
{
    int j=0;
    int replaced_str_loc,replaced_str_len,reped_len,source_str_len;
    LNode *p,*s,*z,*w;
    replaced_str_len = strlen(replaced_str);  //���滻���ַ��ĳ���
    reped_len = strlen(replace_str);          //��Ҫ�滻���ַ��ĳ���
    source_str_len = strlen(source_str);      //�����ַ��ĳ���
    replaced_str_loc = Search(replaced_str);  //���滻���ַ���λ��
    if(replaced_str_loc != -1)
    {
        LTmp = Init(replace_str);
        p = L;
        s = L;
        z = LTmp->next;
        w = LTmp;
        for(j = 0; j < replaced_str_loc; j++)
            p = p->next;
        for(j = 0; j < (replaced_str_loc + replaced_str_len); j++)
            s = s->next;
        for(j = 0; j < reped_len; j++)
            w = w->next;
        p->next = z;
        w->next = s->next;
        Display();
        return 0;
    }
    else
    {
        printf("**************************************\n");
        printf("* ���������������滻���ı�������Ŷ~~*\n");
        printf("**************************************\n");
    }
}
void Insert(char insert_str[],int location)
{
    int i,j,len_ins,source_str_len;
    LNode *p,*s;
    len_ins = strlen(insert_str);
    source_str_len = strlen(source_str);
    if((location <= source_str_len)&&(location >= 0))
    {
        p=L;
        j=0;
        for(i=0; i<len_ins; i++)                  //����Ĵ���
        {
            while(p&&j<location)
            {
                p=p->next;
                j++;
            }
            s=(LinkList)malloc(sizeof(LNode));    //�����½��
            s->data=insert_str[i];
            s->next=p->next;
            p->next=s;
            p=p->next;
        }
        len_ins=strlen(source_str)+len_ins;
        Display();
    }
    else
    {
        ����;
    }
}
void  Move(char bemoved_str[],int location)
{
    int j,bemoved_str_loc = 0,bemoved_str_len = 0,source_str_len;
    LNode *p,*s,*w,*temp;
    bemoved_str_loc = Search(bemoved_str) + 1;
    bemoved_str_len = strlen(bemoved_str);
    source_str_len = strlen(source_str);
    if((bemoved_str_loc) > 0)
    {
        if((location <= source_str_len)&&(location >= 0))
        {
            p = L;
            s = L;
            w = L;
            for(j = 0; j < bemoved_str_loc-1; j++)
            {
                p = p->next;
            }
            temp = p->next;
            for(j = 0; j < (bemoved_str_loc + bemoved_str_len-1); j++)
                s = s->next;
            for(j = 0; j < location; j++)
                w = w->next;
            p->next = s->next;
            s->next = w->next;
            w->next = temp;
            Display();
        }
        else
        {
            ����;
        }
    }
    else
    {
        ����;
    }
}
void Delete(char delete_str[])
{
    int loc;            //��¼Ҫɾ�����ı���λ��
    int i,j=0;
    int len_del;
    LNode *p,*q;
    p=L;
    len_del=strlen(delete_str);
    loc=Search(delete_str)+1;
    if((loc - 1) >= 0)
    {
        for(i=0; i<len_del; i++)      //Ҫɾ���Ľ��ĸ���
        {
            while(p->next&&j<loc-1)    //Ѱ�ҵ�loc[i]��Ԫ�أ�����pָ����ǰ��
            {
                p=p->next;
                j++;
            }
            q=p->next;                    //ɾ�����
            if(q->next->data== 10)
                q=q->next;
            p->next=q->next;
        }
        len=strlen(source_str)-len_del;
        Display();
    }
    else
    {
        ����;
    }
}
void OpenFile()
{
    char ch,meng[33];
    int i = 0,flag = 1,copy_num;
    FILE *fp1;
    printf("�����Ҫ����ʲô�������ı�·��(�ҿ��������f:\\1.txt) \n");
    scanf("%s",way);
    if((fp1=fopen(way,"r"))==NULL)
    {
        while(flag)
        {
            printf("��ͳ���ˣ������ļ����ڴ������أ��ǲ�����U��,�١���һ��!\n");
            scanf("%s",way);
            fp1 = fopen(way,"r");
            if(fp1 != NULL)
                flag = 0;
            else
                flag = 1;
        }
    }
    if((fp1=fopen(way,"r")) != NULL)
    {
        while(!feof(fp1))
        {
            ch = fgetc(fp1);
            source_str[i++] = ch;
        }
        source_str[i] = '\0';
        for(i = 0; i < strlen(source_str)-1; i++)
            source_str[i] = source_str[i];
        source_str[i] = '\0';
        for(copy_num = 0; copy_num < STRING_MAXSIZE; copy_num ++)
            changed_source_str[copy_num] = source_str[copy_num];
        printf("���Ѿ�����ӡ���Ժ����ˣ����㿴��һ������,��Ҫ׽��...\n");
        delay();
        fclose(fp1);
        system( "cls" ) ;
        menu();
    }
}
void delay()
{
    int i,j;
    for(i = 0; i < 55000; i++)
        for(j = 0; j < 11000; j++);
}
void save()
{
    FILE * fp2;
    fp2=fopen(way,"w");
    fprintf (fp2,"%s",changed_source_str);
    fclose (fp2);
}
int main()
{

    return 0;
}
