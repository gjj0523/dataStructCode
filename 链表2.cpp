#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//线性表的链式存储结构
typedef struct LNode {
	int data;
	LNode *next;
}LNode, *LinkList;//不是LNode的变量 


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
    if(L->next==NULL) //若头结点为空，退出函数 
	{
		return ;
	}
    while((L->next->next) != r)   //第一次当链表不为空，进入循环；第2~n次当链表没有达到有序状态时进入循环 （r后的位置应该都为有序） 
    {                             //当头结点的next为r时，证明链表所有结点已经有序化 
        p = L;
        q = L->next;   //q指向头结点 
        while(q->next != r)   // 一次当链表不为空，进入循环；第2~n次当链表没有达到有序状态时进入循环
        {
            if((q->data) > (q->next->data))  //若q结点的值大于其后一结点的值 
            {
                p->next = q->next;
                q->next = q->next->next;
                p->next->next = q;
                q = p->next;               //交换两结点的位置  
            }		
           q = q->next;   
           p = p->next;   //移动p,q指针依次两两比较 
        }
        r=q  ; //将移动后元素的位置的地址赋给r,r为有序边界临界 
    }
}
	

int remove(LinkList &head,int x){
	LinkList p=head->next;  //定义p为链表头结点 
	LinkList q=head;    
	LinkList s=0;
	int flag=-1;  
	while(p)   //p不为空，进入循环 
	{
		if(p->data!=x)  // p结点的值不为x时
		{
	     	q=p;   //将值赋给p连入链表 
	    	p=p->next; 
	    }	
		else
	    {             //p结点的值为x时，将其删除
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
	//判断空间是否分配成功 
	if (!L) return CreatFailFlag;
	L->next = NULL;
	return NoneFlag;
}
Flag ListInsert_L(LinkList &head, int i, int num)
{
	LinkList p = head;
	//先定位到要插入的位置 
	int j = 0;//计数器
	while (p&&j < i) { p = p->next; ++j; }
	//判断插入位置是否合法 
	if (!p || j > i)return InsertWrongFlag;
	//插入 
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s->data = num;
	s->next = p->next;
	p->next = s;
	return NoneFlag;
}
Flag GetElem_L(LinkList head, int i, int &num)
{
	//当第i个元素存在时，将其幅值给num并返回ok否则wrong
	LinkList p = head->next;
	//定位到要获取值的位置 
	int j = 0;
	while (p&&j < i)
	{
		p = p->next;
		++j;
	}
	//判断位置是否合法 
	if (!p || j > i)return FindWrongFlag;
	num = p->data;
	return NoneFlag;
}

void printLinkList(LinkList &head)
{
	//遍历链表 
	int j = 0;
	LinkList p = head->next;
	while (p != NULL) { printf("第%d个数是：%d\n", j, p->data); p = p->next; ++j; }
	//while(head->next != NULL){printf("第%d个数是：%d\n",j,head->next->data);head->next = head->next->next;++j;}
	printf("--------------------------------\n");
}
/*
void printLinkList(LinkList &head)
{
	//遍历链表 
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

void mergeLinkList(LinkList list1, LinkList list2, LinkList &listSum)  //反转链表 
{
	LinkList l1 = list1->next;
    LinkList l2 = list2->next;
    LinkList now = listSum;
while (l1 && l2){
    if (l1->data < l2->data) //当l1l2都不空的时候，l1元素小于l2时 
	{
          now->next = l1;   //将l1元素的值赋给now的next 
          now = now->next;  //now移到下一位，也就是刚刚l1元素的位置 
          l1 = l1->next;    //l1等于l1的next 
    }
    else
    {                        //再比较l1l2，当l2元素小于l1时 
          now->next = l2;    //将l1元素的值赋给now的next 
          now = now->next;   //now移到下一位，也就是刚刚l2元素的位置 
          l2 = l2->next;     //l2等于l2的next
    }
 }
//当l1或l2出现空链表时 
 if (l1)            
 {
      now->next = l1;       //当l1不空时，now指向l1的剩余元素 
 }
 if (l2)
 {
      now->next = l2;        //当l2不空时，now指向l2的剩余元素 
 }
}

void reverselist(LinkList &res){  //反转链表 
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
void mergeLinkList(LinkList list1, LinkList list2, LinkList &listSum) //合并两有序链表 
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

Flag ListInsert_L(LinkList &head, int i, int num)//插入元素 
{
	LinkList p = head;
	//先定位到要插入的位置 
	int j = 0;//计数器
	while (p&&j < i) { p = p->next; ++j; }
	//判断插入位置是否合法 
	if (!p || j > i)return InsertWrongFlag;
	//插入 
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s->data = num;
	s->next = p->next;
	p->next = s;
	return NoneFlag;
}
*/
void mergeLinkList2(LinkList list1, LinkList list2, LinkList &listSum){   //合并两有序链表 
     LinkList l1 = list1->next;
      LinkList l2 = list2->next;
      int k = 0;
while (l1 && l2) {	
     if (l1->data < l2->data){          //当l1l2都不空的时候，l1元素小于l2时 
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

