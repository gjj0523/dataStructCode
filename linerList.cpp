#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
Flag deletList(SqList &L, int i);
int locateList(SqList L, int num, Flag (*compare)(int, int));
Flag compareTwoNum(int a, int b);
Flag pingfang(int a,int b);
Flag kaifang(int a,int b);
Flag NextElem(SqList L, int i, int &res);
Flag PriorElem(SqList L, int i, int &bobo);
int list(SqList &la,SqList &lb);

int main()
{
	SqList la;
	int num = 0;
	printf("------建立la ------\r\n");
	if(creatList(la) == CreatFailFlag)
	{
		printf("创建失败\n"); 
	}else
	{
		printf("创建成功\n");
	}

	printList(la);
	
	SqList lb;
	int n = 0;
	printf("------建立lb ------\r\n");
	if(creatList(lb) == CreatFailFlag)
	{
		printf("创建失败\n"); 
	}else
	{
		printf("创建成功\n");
	}
	insertList(lb, 0, 15);
	insertList(lb, 0, 5);
	insertList(lb, 0, 3);
	insertList(lb, 0, 1);
	insertList(lb, 0, 7);
	insertList(lb, 0, 3);
	insertList(lb, 0, 1);
	insertList(lb, 0, 15);
	insertList(lb, 0, 2);
	printList(lb);
	printf("\n判断la是不是lb的连续子序列 \r\n");
	list(la,lb);
	
	/* 
	for(int i = 0; i < 5; i++)
	{
		if(insertList(l, 0,num++) == CreatFailFlag)
	{
		printf("创建失败\n"); 
	}else
	{
		printf("创建成功\n");
	}
	for(int i = 6; i < 10; i++)
	{
		if(insertList(l, 0, num++) != NoneFlag)
		{
			printf("插入失败\n"); 
		}
	}
	printList(l);*/ 
	
/*	printf("------删除前------\r\n");	
	for(int i = 0; i < 5; i++)
	{
		if(deletList(l, 0) != NoneFlag)
		{
			printf("删除失败\n"); 
		}
	}
	printList(l);	
	if(locateList(l, 3, compareTwoNum) != -1)
	{
		printf("找到平方:%d\n",locateList(l, 2, pingfang));
	}else
	{
		printf("未找到\n");
	}
	if(locateList(l, 4, compareTwoNum) != -1)
	{
		printf("找到开方:%d\n",locateList(l, 4, kaifang));
	}else
	{
		printf("未找到\n");
	}
	int res = 0; 
	NextElem(l, 0, res);
	printf("第0项的下一项是%d\r\n",res);
	int bobo = 0; 
	NextElem(l, 0, bobo);
	printf("第0项的上一项是%d\r\n",bobo);*/
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

//判断顺序表a是不是b的连续子序列，是的话返回1，不是的话返回0；
int list(SqList &la,SqList &lb) 
{
	int pa=0,p=0,pb=p;   //定义pa,p分别为la,lb表头第一个元素 ;先将p赋给Pb; 
	                   
    if(pa <0 || pb<0){
	    printf("-----不是");
		return 0;     //如果la或lb是空表，返回0；		          
	}
	while(lb.elem[p]){		//当p所指元素不为空 ，进入循环 
		if(lb.elem[p] == la.elem[pa])    //当p所指元素等于pa,进入循环； 
		{
			pb=p;            //将 p所指元素 的值赋给pb; 
			while(la.elem[pa] && lb.elem[pb]){    //pa,pb所指两元素不为空，进入循环 
			    if(lb.elem[pb] != la.elem[pa])
				{
			    	break;        //当pb不等于pa时，退出内部的while循环 
				}
		     	pa++;
		     	pb++;              //当pa,pb相等时， 将papb分别移动到lalb下一位 
		     }
			if(pa>la.length-1)
			{	
			    printf("-----是"); //如果pa指向空，说明是连续子序列，返回1； 
				return 1;			
			}
			pa=0;  //说明，不是连续子序列，重新将pa赋为第一个元素； 
			p++;
		}else
		{
			p++;   //p所指元素不等于pa,p移动到lb的下一位； 
		}
	}
	printf("-----不是"); 
	return 0;   //直到p为空，未找到连续子序列，则返回0； 
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

/*mergeLinkList(SqList l1, SqList l2, SqList &listSum) */


void printList(SqList L)
{
	for(int i = 0; i < L.length; i++)
	{
		printf("list的第%d位:%d\r\n",i,L.elem[i]);
	}
}

/**
 * @brief List::deletList
 * @param L
 * @param i
 * @return
 */
Flag deletList(SqList &L, int i)
{
    //先判断i的位置是否合法
    if(i < 0 || i > L.length - 1)
    {
        return DeleteWrongFlag;
    }
    //元素前移
    for(int j = i; j < L.length; j++)
    {
        L.elem[j] = L.elem[j + 1];
    }
    L.length--;
    return NoneFlag;
}

/**
 * @brief List::locateList
 * @param L
 * @param num
 * @param compare:存放了传入函数的函数指针，也就是放了传入的compare函数的地址
 * @return
 */
int locateList(SqList L, int num, Flag (*compare)(int, int))
{
    int i = 0;//记录找到数的位置 
    int *p = L.elem;
    while(i <= L.length && (* compare)(*p++,num) == NoneFlag) ++i;//这里（* compare）这是解指针的作用，也就是获取了函数的对象
    if(i < L.length) return i;
    else return -1;
}

/**
 * @brief List::compareTwoNum：compareTwoNum必须静态，静态成员是属于类的，而不是List声明的对象的，不是静态的话
 * 在调用locateList函数的时候传入compareTwoNum时会找不到他的地址，就是不知道它到底是哪个对象的。
 * @param a
 * @param b
 * @return
 */
Flag compareTwoNum(int a, int b)
{
    return a == b?CompareSuccessFlag:NoneFlag;
}

Flag pingfang(int a,int b)
{
	return a == b*b?CompareSuccessFlag:NoneFlag;
}

Flag kaifang(int a,int b)
{
	return a == sqrt( b )?CompareSuccessFlag:NoneFlag;
}

/**
 * @brief List::NextElem:查找下一项
 * @param L
 * @param i
 * @param res
 * @return
 */
Flag NextElem(SqList L, int i, int &res)
{
    //先判断i的位置是否合法
    if(i < 0 || i > L.length - 2)
    {
        return noNextFlag;
    }
    //获取下一个元素
    res = L.elem[i + 1];
    return NoneFlag;
}

/**
 * @brief List::PriorElem:查找上一项
 * @param L
 * @param i
 * @param res
 * @return
 */
Flag PriorElem(SqList L, int i, int &bobo)
{
	 if(i < 1 || i > L.length - 1)
    {
        return noPriorFlag;
    }
    bobo = L.elem[i - 1];
    return NoneFlag;
}
