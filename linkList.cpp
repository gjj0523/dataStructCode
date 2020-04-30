#include <stdio.h>
#include <stdlib.h>
//���Ա����ʽ�洢�ṹ
typedef struct LNode{
    int data;
    LNode *next;
}LNode,*LinkList;//����LNode�ı��� 


enum Flag
{
    NoneFlag,CreatFailFlag,DeleteWrongFlag,InsertWrongFlag,CreatRoomFailFlag,
    CompareSuccessFlag,noNextFlag,noPriorFlag,FindWrongFlag,EmptyFlag
};

 /*�ٴ������Ͽ���ָ��������ʱ���Ըı�����ָ���ֵ��������һ����ĳ������
 * �󶨺�Ͳ��ٸı䡣��仰�������Ϊ��ָ����Ա����¸�ֵ��ָ����һ����
 * ͬ�Ķ��󡣵�������������ָ���ڳ�ʼ��ʱ��ָ���Ķ����Ժ��ܸı䣬��
 * ��ָ���Ķ��������ݿ��Ըı䡣
 * �ڴ��ڴ�����Ͽ�������Ϊָ����������ڴ����򣬶���Ϊ���÷����ڴ�����
 * ��Ϊ��������ʱ�����ʼ�����Ӷ�ָ��һ���Ѿ����ڵĶ������ò���ָ���ֵ��*/ 
Flag CreatLinkList(LinkList &L);
Flag ListInsert_L(LinkList &head,int i,int num);
Flag GetElem_L(LinkList head,int i,int &num);
int Length_L(LinkList head);    
Flag listDelete_L(LinkList &head,int i,int &num); 
void printLinkList(LinkList &head);

int main()
{
	LinkList head;
	if(CreatLinkList(head) != NoneFlag)
	{
		printf("����ʧ�ܣ�\n");
	}else
	{
		printf("�����ɹ���\n");
	}
	
	for(int i = 0; i < 10; i++)
	{
		if(ListInsert_L(head,0,i) != NoneFlag)
		{
			printf("����%dʧ�ܣ�\n",i);
			break; 
		}
}
	printLinkList(head);
	     int x;
		if(listDelete_L(head,0,x) != NoneFlag)
		{
			printf("ɾ��%dʧ�ܣ�\n",x);
			
		}
   
	printLinkList(head);
	Length_L(head); 
	
	int num;
	GetElem_L(head,0,num);
	printf("��0��Ԫ���ǣ�%d\r\n",num);
	
}
    
Flag CreatLinkList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	//�жϿռ��Ƿ����ɹ� 
	if(!L) return CreatFailFlag;
	L->next = NULL;
	return NoneFlag;
}
Flag ListInsert_L(LinkList &head,int i,int num)
{
	LinkList p = head;
	//�ȶ�λ��Ҫ�����λ�� 
    int j = 0;//������
    while(p&&j<i){p = p->next;++j;}
    //�жϲ���λ���Ƿ�Ϸ� 
    if(!p||j>i)return InsertWrongFlag;
    //���� 
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = num;
    s->next = p->next;
    p->next = s;
    return NoneFlag;
}
Flag GetElem_L(LinkList head,int i,int &num)
{
	//����i��Ԫ�ش���ʱ�������ֵ��num������ok����wrong
    LinkList p = head->next;
    //��λ��Ҫ��ȡֵ��λ�� 
    int j = 0;
    while(p&&j<i)
    {
        p = p->next;
        ++j;
    }
    //�ж�λ���Ƿ�Ϸ� 
    if(!p||j>i)return FindWrongFlag;
    num = p->data;
    return NoneFlag;
}
int Length_L(LinkList head)
{
	int j = 0;
	LinkList p = head->next;
	while(p != NULL){p = p->next;++j;}
	printf("�������ǣ�%d\n",j);
}

Flag listDelete_L(LinkList &head,int i,int &num)
{
	LinkList p = head;
	//�ȶ�λ��Ҫɾ����λ�� 
    int j = 0;//������
    while(p&&j<i){p = p->next;++j;}
    //�ж�ɾ��λ���Ƿ�Ϸ� 
    if(!p||j>i)return InsertWrongFlag;
    //ɾ�� 
    LinkList m = (LinkList)malloc(sizeof(LNode));
    m = p->next;
	p->next = m->next;
	free(m);
    return NoneFlag;
}

void printLinkList(LinkList &head)
{
	//�������� 
	int j = 0;
	LinkList p = head->next;
	while(p != NULL){printf("��%d�����ǣ�%d\n",j,p->data);p = p->next;++j;}
	//while(head->next != NULL){printf("��%d�����ǣ�%d\n",j,head->next->data);head->next = head->next->next;++j;}
	printf("��ӡ���\n");
} 

