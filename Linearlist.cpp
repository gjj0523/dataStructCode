#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 10//线性表存储空间初始分配量
#define LISTINCREMENT 10//线性表每次分配增量
typedef struct{//线性表结构体
    int *elem;//存储空间基地址
    int length;//当前长度
    int listSize;//链表总长
}SqList; 

enum Flag
{
    NoneFlag,CreatFailFlag,DeleteWrongFlag,InsertWrongFlag,CreatRoomFailFlag,
    CompareSuccessFlag,noNextFlag,noPriorFlag,FindWrongFlag,EmptyFlag
};
Flag creatList(SqList &L);
Flag insertList(SqList &L, int i, int num);
void printList(SqList L);
int main()
{
	SqList l;
	int num = 0;
	if(creatList(l) == CreatFailFlag)
	{
		printf("创建失败"); 
	}else
	{
		printf("创建成功");
	}
	for(int i = 0; i < 10; i++)
	{
		if(insertList(l, 0, num++) != NoneFlag)
		{
			printf("插入失败"); 
		}
	}
	printList(l);
}

/**
 * @brief List::creatList:创建空表
 * @param L
 * @return
 */
Flag creatList(SqList &L)
{
    //构造一个空线性表L
    L.elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));//动态分配这么大的数组
    if(L.elem == NULL)//如果是空指针
    {
        return CreatFailFlag;
    }
    L.length = 0;
    L.listSize = LIST_INIT_SIZE;
    return NoneFlag;
}

/**
 * @brief List::insertList
 * @param L
 * @param i
 * @param num
 * @return
 */
Flag insertList(SqList &L, int i, int num)
{
    //先判断i的位置是否合法
    if(i < 0 || i > L.length)
    {
        return InsertWrongFlag;
    }
    //判断空间是否满了
    if(L.length >= L.listSize)
    {
        int *newBase = (int *)realloc(L.elem,(L.listSize + LISTINCREMENT)*(sizeof(int)));//重新分配空间
        if(!newBase)//如果分配失败
        {
            return CreatRoomFailFlag;
        }
        L.elem = newBase;
        L.listSize += LISTINCREMENT;
    }
    //元素后移
    for(int j = L.length; j > i; j--)
    {
        L.elem[j] = L.elem[j - 1];
    }
    //插入元素
    L.elem[i] = num;
    L.length++;
    return NoneFlag;
}

void printList(SqList L)
{
	for(int i = 0; i < L.length; i++)
	{
		printf("list的第%d位:%d\r\n",i,L.elem[i]);
	}
}
