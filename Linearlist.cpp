#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 10//���Ա�洢�ռ��ʼ������
#define LISTINCREMENT 10//���Ա�ÿ�η�������
typedef struct{//���Ա�ṹ��
    int *elem;//�洢�ռ����ַ
    int length;//��ǰ����
    int listSize;//�����ܳ�
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
		printf("����ʧ��"); 
	}else
	{
		printf("�����ɹ�");
	}
	for(int i = 0; i < 10; i++)
	{
		if(insertList(l, 0, num++) != NoneFlag)
		{
			printf("����ʧ��"); 
		}
	}
	printList(l);
}

/**
 * @brief List::creatList:�����ձ�
 * @param L
 * @return
 */
Flag creatList(SqList &L)
{
    //����һ�������Ա�L
    L.elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));//��̬������ô�������
    if(L.elem == NULL)//����ǿ�ָ��
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
    //���ж�i��λ���Ƿ�Ϸ�
    if(i < 0 || i > L.length)
    {
        return InsertWrongFlag;
    }
    //�жϿռ��Ƿ�����
    if(L.length >= L.listSize)
    {
        int *newBase = (int *)realloc(L.elem,(L.listSize + LISTINCREMENT)*(sizeof(int)));//���·���ռ�
        if(!newBase)//�������ʧ��
        {
            return CreatRoomFailFlag;
        }
        L.elem = newBase;
        L.listSize += LISTINCREMENT;
    }
    //Ԫ�غ���
    for(int j = L.length; j > i; j--)
    {
        L.elem[j] = L.elem[j - 1];
    }
    //����Ԫ��
    L.elem[i] = num;
    L.length++;
    return NoneFlag;
}

void printList(SqList L)
{
	for(int i = 0; i < L.length; i++)
	{
		printf("list�ĵ�%dλ:%d\r\n",i,L.elem[i]);
	}
}
