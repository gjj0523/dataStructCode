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

/*①从现象上看，指针在运行时可以改变其所指向的值，而引用一旦和某个对象
* 绑定后就不再改变。这句话可以理解为：指针可以被重新赋值以指向另一个不
* 同的对象。但是引用则总是指向在初始化时被指定的对象，以后不能改变，但
* 是指定的对象其内容可以改变。
* ②从内存分配上看，程序为指针变量分配内存区域，而不为引用分配内存区域，
* 因为引用声明时必须初始化，从而指向一个已经存在的对象。引用不能指向空值。*/
Flag CreatLinkList(LinkList &L);
Flag ListInsert_L(LinkList &head, int i, int num);
Flag GetElem_L(LinkList head, int i, int &num);
int Length_L(LinkList head);
Flag listDelete_L(LinkList &head, int i, int &num);
void printLinkList(LinkList &head);

int main()
{
	LinkList head;
	if (CreatLinkList(head) != NoneFlag)
	{
		printf("创建失败！\n");
	}
	else
	{
		printf("创建成功！\n");
	}

	for (int i = 0; i < 10; i++)
	{
		if (ListInsert_L(head, 0, i) != NoneFlag)
		{
			printf("插入%d失败！\n", i);
			break;
		}
	}
	printLinkList(head);
	int x;
	if (listDelete_L(head, 0, x) != NoneFlag)
	{
		printf("删除%d失败！\n", x);

	}

	printLinkList(head);
	Length_L(head);

	int num;
	GetElem_L(head, 0, num);
	printf("第0个元素是：%d\r\n", num);

}

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
int Length_L(LinkList head)
{
	int j = 0;
	LinkList p = head->next;
	while (p != NULL) { p = p->next; ++j; }
	printf("链表长度是：%d\n", j);
	return 0;
}

Flag listDelete_L(LinkList &head, int i, int &num)
{
	LinkList p = head;
	//先定位到要删除的位置 
	int j = 0;//计数器
	while (p&&j < i) { p = p->next; ++j; }
	//判断删除位置是否合法 
	if (!p || j > i)return InsertWrongFlag;
	//删除 
	LinkList m = (LinkList)malloc(sizeof(LNode));
	m = p->next;
	p->next = m->next;
	free(m);
	return NoneFlag;
}

void printLinkList(LinkList &head)
{
	//遍历链表 
	int j = 0;
	LinkList p = head->next;
	while (p != NULL) { printf("第%d个数是：%d\n", j, p->data); p = p->next; ++j; }
	//while(head->next != NULL){printf("第%d个数是：%d\n",j,head->next->data);head->next = head->next->next;++j;}
	printf("打印完成\n");
}

