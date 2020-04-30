#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//���Ա����ʽ�洢�ṹ
typedef struct LNode {
	int data;
	LNode *next;
}LNode, *LinkList;//����LNode�ı��� 


enum Flag
{
	NoneFlag, CreatFailFlag, DeleteWrongFlag, InsertWrongFlag, CreatRoomFailFlag,
	CompareSuccessFlag, noNextFlag, noPriorFlag, FindWrongFlag, EmptyFlag
};

Flag CreatLinkList(LinkList &L);
Flag ListInsert_L(LinkList &head, int i, int num);
Flag GetElem_L(LinkList head, int i, int &num);
void printLinkList(LinkList &head);
void reverselist(LinkList &res);
void mergeLinkList(LinkList list1, LinkList list2, LinkList &listSum);
void Num(LinkList &head,int &max,int &min);
int remove(LinkList &head,int x);
void renkList(LinkList &L);
void mergeLinkList2(LinkList list1, LinkList list2, LinkList &listSum);
 
int main()
{
	LinkList list1 = NULL,list2 = NULL,listSum = NULL;	
	int max,min;int x; int flag; 
	
	CreatLinkList(list1);
	CreatLinkList(list2);
	CreatLinkList(listSum);
	
	ListInsert_L(list1, 0, 7);
	ListInsert_L(list1, 0, 5);
	ListInsert_L(list1, 0, 4);
	ListInsert_L(list1, 0, 3);
	ListInsert_L(list1, 0, 1);
	
	ListInsert_L(list2, 0, 6);
	ListInsert_L(list2, 0, 4);
	ListInsert_L(list2, 0, 2);

	printLinkList(list1);
	printLinkList(list2);

/*	mergeLinkList(list1, list2, listSum);
	reverselist(list1);
	printLinkList(list1);*/
	mergeLinkList2(list1, list2, listSum);
	printLinkList(listSum);
/*	Num(list1,max,min);	
	printf("max:%d\n", max);
	printf("min:%d\n", min);
	remove(list1,7);
	printLinkList(list1);

    renkList(list1);
	printLinkList(list1);
	return 0;*/
}

void renkList(LinkList &L)
{
    LinkList p=L;
	LinkList q=L->next;
    LinkList r=NULL;
    if(L->next==NULL) //��ͷ���Ϊ�գ��˳����� 
	{
		return ;
	}
    while((L->next->next) != r)   //��һ�ε�����Ϊ�գ�����ѭ������2~n�ε�����û�дﵽ����״̬ʱ����ѭ�� ��r���λ��Ӧ�ö�Ϊ���� 
    {                             //��ͷ����nextΪrʱ��֤���������н���Ѿ����� 
        p = L;
        q = L->next;   //qָ��ͷ��� 
        while(q->next != r)   // һ�ε�����Ϊ�գ�����ѭ������2~n�ε�����û�дﵽ����״̬ʱ����ѭ��
        {
            if((q->data) > (q->next->data))  //��q����ֵ�������һ����ֵ 
            {
                p->next = q->next;
                q->next = q->next->next;
                p->next->next = q;
                q = p->next;               //����������λ��  
            }		
           q = q->next;   
           p = p->next;   //�ƶ�p,qָ�����������Ƚ� 
        }
        r=q  ; //���ƶ���Ԫ�ص�λ�õĵ�ַ����r,rΪ����߽��ٽ� 
    }
}
	

int remove(LinkList &head,int x){
	LinkList p=head->next;  //����pΪ����ͷ��� 
	LinkList q=head;    
	LinkList s=0;
	int flag=-1;  
	while(p)   //p��Ϊ�գ�����ѭ�� 
	{
		if(p->data!=x)  // p����ֵ��Ϊxʱ
		{
	     	q=p;   //��ֵ����p�������� 
	    	p=p->next; 
	    }	
		else
	    {             //p����ֵΪxʱ������ɾ��
	    	q->next = p->next;
			s=p;
			p=p->next;
	    	free(s);
			 flag= 0; 	    	
		}								    	
    } 			  
			return flag;	 
} 
/* 
void Num(LinkList &head,int &max,int &min){
	LinkList p=head->next;
	
	max=min=p->data;
	p=p->next;
	if(head==NULL){
		max=min=0;
		return;
	}
	while(p){
		max=max>p->data?max:p->data;
		min=min<p->data?min:p->data; 
		p=p->next;
	}
}


void Num2(LinkList &head,int &max,int &min) 
{
	LinkList p= head->next;
	LinkList q= head->next;
    max=p->data;
    min=q->data;
    p=p->next;
    if(head==NULL){
    	max=min=0;
    	return;
	}
    while(p)
   {
       if(max<p->data)
        {
            max=p->data;
        }
        p=p->next;
   }     
    while(q)
   {
       if(min>q->data)
        {
            min=q->data;
        }
        q=q->next;
   }   
}
*/

Flag CreatLinkList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	//�жϿռ��Ƿ����ɹ� 
	if (!L) return CreatFailFlag;
	L->next = NULL;
	return NoneFlag;
}
Flag ListInsert_L(LinkList &head, int i, int num)
{
	LinkList p = head;
	//�ȶ�λ��Ҫ�����λ�� 
	int j = 0;//������
	while (p&&j < i) { p = p->next; ++j; }
	//�жϲ���λ���Ƿ�Ϸ� 
	if (!p || j > i)return InsertWrongFlag;
	//���� 
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s->data = num;
	s->next = p->next;
	p->next = s;
	return NoneFlag;
}
Flag GetElem_L(LinkList head, int i, int &num)
{
	//����i��Ԫ�ش���ʱ�������ֵ��num������ok����wrong
	LinkList p = head->next;
	//��λ��Ҫ��ȡֵ��λ�� 
	int j = 0;
	while (p&&j < i)
	{
		p = p->next;
		++j;
	}
	//�ж�λ���Ƿ�Ϸ� 
	if (!p || j > i)return FindWrongFlag;
	num = p->data;
	return NoneFlag;
}

void printLinkList(LinkList &head)
{
	//�������� 
	int j = 0;
	LinkList p = head->next;
	while (p != NULL) { printf("��%d�����ǣ�%d\n", j, p->data); p = p->next; ++j; }
	//while(head->next != NULL){printf("��%d�����ǣ�%d\n",j,head->next->data);head->next = head->next->next;++j;}
	printf("--------------------------------\n");
}
/*
void printLinkList(LinkList &head)
{
	//�������� 
	int j = 0;
	LinkList p = head->next;
	LinkList max=p;
	LinkList q= head->next;
    LinkList min=q;
	while (p != NULL) { 
	 if(max->data<p->data)
        {
            max=p;
        }
        p = p->next; ++j;
 }
	printf("max:%d\n ", max->data);
	while(q)
   {
       if(min->data>q->data)
        {
            min=q;
        }
        q=q->next;++j;
   } 
   printf("min:%d\n", min->data);
}*/

void mergeLinkList(LinkList list1, LinkList list2, LinkList &listSum)  //��ת���� 
{
	LinkList l1 = list1->next;
    LinkList l2 = list2->next;
    LinkList now = listSum;
while (l1 && l2){
    if (l1->data < l2->data) //��l1l2�����յ�ʱ��l1Ԫ��С��l2ʱ 
	{
          now->next = l1;   //��l1Ԫ�ص�ֵ����now��next 
          now = now->next;  //now�Ƶ���һλ��Ҳ���Ǹո�l1Ԫ�ص�λ�� 
          l1 = l1->next;    //l1����l1��next 
    }
    else
    {                        //�ٱȽ�l1l2����l2Ԫ��С��l1ʱ 
          now->next = l2;    //��l1Ԫ�ص�ֵ����now��next 
          now = now->next;   //now�Ƶ���һλ��Ҳ���Ǹո�l2Ԫ�ص�λ�� 
          l2 = l2->next;     //l2����l2��next
    }
 }
//��l1��l2���ֿ�����ʱ 
 if (l1)            
 {
      now->next = l1;       //��l1����ʱ��nowָ��l1��ʣ��Ԫ�� 
 }
 if (l2)
 {
      now->next = l2;        //��l2����ʱ��nowָ��l2��ʣ��Ԫ�� 
 }
}

void reverselist(LinkList &res){  //��ת���� 
      LinkList p = NULL;
      CreatLinkList(p);
      res = res->next;  
      while(res)
	  {
	  	ListInsert_L(p, 0, res->data);
	  	res = res->next;
	  } 	  
      res = p;
}
/*
void mergeLinkList(LinkList list1, LinkList list2, LinkList &listSum) //�ϲ����������� 
{	LinkList l1 = list1->next;
    LinkList l2 = list2->next;
    LinkList now = listSum;
    now->next=NULL;
    
    LinkList s;
    s=(LinkList)malloc(sizeof(LNode)); 
	while(l1 && l2){
		if(l1->data < l2->data){			 
			 s=l1;
			 l1=l1->next;			 
		}else
		{			 
			 s=l2;
			 l2=l2->next;
		}
		s->next=now->next;
		now->next=s;
	}
	if(l1==NULL)
	    l1=l2;
	while(l1){
	    s=l1;
		l1=l1->next;
		s->next=now->next;
	    now->next=s;
	}
} 

Flag ListInsert_L(LinkList &head, int i, int num)//����Ԫ�� 
{
	LinkList p = head;
	//�ȶ�λ��Ҫ�����λ�� 
	int j = 0;//������
	while (p&&j < i) { p = p->next; ++j; }
	//�жϲ���λ���Ƿ�Ϸ� 
	if (!p || j > i)return InsertWrongFlag;
	//���� 
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s->data = num;
	s->next = p->next;
	p->next = s;
	return NoneFlag;
}
*/
void mergeLinkList2(LinkList list1, LinkList list2, LinkList &listSum){   //�ϲ����������� 
     LinkList l1 = list1->next;
      LinkList l2 = list2->next;
      int k = 0;
while (l1 && l2) {	
     if (l1->data < l2->data){          //��l1l2�����յ�ʱ��l1Ԫ��С��l2ʱ 
       ListInsert_L(listSum, k++, l1->data);
       l1 = l1->next;
     }
     else{
       ListInsert_L(listSum, k++, l2->data);
       l2 = l2->next;
     }
 }
 while (l1){
       ListInsert_L(listSum, k++, l1->data);
       l1 = l1->next;
 }
 while (l2){
       ListInsert_L(listSum, k++, l2->data);
       l2 = l2->next;
 }
}

