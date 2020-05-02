#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define LIST_INIT_SIZE 10 //���Ա�洢�ռ��ʼ������
#define LISTINCREMENT 10 //���Ա�ÿ�η�������

//���Ա�Ľṹ��
typedef struct {
	int *elem;  //�洢�ռ����ַ
	int length;  //��ǰ�ĳ���
	int listSize;  //�����ܳ�
}Sqlist;  //˳������͵Ķ���

enum Flag
{
	NoneFlag, CreatFailFlag, DeleteWrongFlag, InsertWrongFlag, CreatRoomFailFlag,
	CompareSuccessFlag, noNextFlag, noPriorFlag, FindWrongFlag, EmptyFlag
};

//����
Flag creatList(SqList &L);
Flag insertList(SqList &L, int i, int num);
void printList(SqList L);
Flag deletList(SqList &L, int i);
int locateList(SqList L, int num, Flag(*compare)(int, int));
Flag compareTwoNum(int a, int b);
Flag pingfang(int a, int b);
Flag kaifang(int a, int b);
Flag NextElem(SqList L, int i, int &res);
Flag PriorElem(SqList L, int i, int &bobo);
int list(SqList &la, SqList &lb);

int main()
{
	SqList la;
	int num = 0;
	printf("------����la ------\r\n");
	if (creatList(la) == CreatFailFlag)
	{
		printf("����ʧ��\n");
	}
	else
	{
		printf("�����ɹ�\n");
	}

	printList(la);

	SqList lb;
	int n = 0;
	printf("------����lb ------\r\n");
	if (creatList(lb) == CreatFailFlag)
	{
		printf("����ʧ��\n");
	}
	else
	{
		printf("�����ɹ�\n");
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
	printf("\n�ж�la�ǲ���lb������������ \r\n");
	list(la, lb);

	/*
	for(int i = 0; i < 5; i++)
	{
		if(insertList(l, 0,num++) == CreatFailFlag)
	{
		printf("����ʧ��\n");
	}else
	{
		printf("�����ɹ�\n");
	}
	for(int i = 6; i < 10; i++)
	{
		if(insertList(l, 0, num++) != NoneFlag)
		{
			printf("����ʧ��\n");
		}
	}
	printList(l);*/

	/*	printf("------ɾ��ǰ------\r\n");
		for(int i = 0; i < 5; i++)
		{
			if(deletList(l, 0) != NoneFlag)
			{
				printf("ɾ��ʧ��\n");
			}
		}
		printList(l);
		if(locateList(l, 3, compareTwoNum) != -1)
		{
			printf("�ҵ�ƽ��:%d\n",locateList(l, 2, pingfang));
		}else
		{
			printf("δ�ҵ�\n");
		}
		if(locateList(l, 4, compareTwoNum) != -1)
		{
			printf("�ҵ�����:%d\n",locateList(l, 4, kaifang));
		}else
		{
			printf("δ�ҵ�\n");
		}
		int res = 0;
		NextElem(l, 0, res);
		printf("��0�����һ����%d\r\n",res);
		int bobo = 0;
		NextElem(l, 0, bobo);
		printf("��0�����һ����%d\r\n",bobo);*/
}


//����һ���ձ�L
Flag creatList(SqList &L)
{
	L.elem = (int *)malloc(sizeof(int) * LIST_INIT_SIZE); //��̬������ô�������
	if (L.elem == NULL) //����ǿ�ָ��,����
	{
		return CreatFailFlag;
	}
	L.length = 0;
	L.listSize = LIST_INIT_SIZE;
	return NoneFlag;
}

//�ж�˳���a�ǲ���b�����������У��ǵĻ�����1�����ǵĻ�����0��
int list(SqList &la, SqList &lb)
{
	int pa = 0, p = 0, pb = p;   //����pa,p�ֱ�Ϊla,lb��ͷ��һ��Ԫ�� ;�Ƚ�p����Pb; 

	if (pa < 0 || pb < 0) {
		printf("-----����");
		return 0;     //���la��lb�ǿձ�����0��		          
	}
	while (lb.elem[p]) {		//��p��ָԪ�ز�Ϊ�� ������ѭ�� 
		if (lb.elem[p] == la.elem[pa])    //��p��ָԪ�ص���pa,����ѭ���� 
		{
			pb = p;            //�� p��ָԪ�� ��ֵ����pb; 
			while (la.elem[pa] && lb.elem[pb]) {    //pa,pb��ָ��Ԫ�ز�Ϊ�գ�����ѭ�� 
				if (lb.elem[pb] != la.elem[pa])
				{
					break; //��pb������paʱ���˳��ڲ���whileѭ�� 
				}
				pa++;
				pb++;   //��pa,pb���ʱ�� ��papb�ֱ��ƶ���lalb��һλ 
			}
			if (pa > la.length - 1)
			{
				printf("-----��"); //���paָ��գ�˵�������������У�����1�� 
				return 1;
			}
			pa = 0;  //˵�����������������У����½�pa��Ϊ��һ��Ԫ�أ� 
			p++;
		}
		else
		{
			p++;   //p��ָԪ�ز�����pa,p�ƶ���lb����һλ�� 
		}
	}
	printf("-----����");
	return 0;   //ֱ��pΪ�գ�δ�ҵ����������У��򷵻�0�� 
}


//˳���Ĳ��룬�ڵ�i��λ�ò���num
Flag insertList(SqList &L, int i, int num)
{
	//�жϲ���λ��i�Ƿ�Ϸ�
	if (i < 0 || i > L.length)
	{
		return InsertWrongFlag;
	}
	//�ж����ռ�����
	if (L.length >= L.listSize)
	{
		//���·���ռ�
		int *newBase = (int *)realloc(L.elem, (L.listSize + LISTINCREMENT) * sizeof(int));
		//�������ʧ��
		if (!newBase) 
		{
			return CreatRoomFailFlag;
		}
		L.elem = newBase;
		L.listSize += LISTINCREMENT;
	}
	//��iλ�ú��Ԫ�غ���
	for (int j = L.length; j > i; j--)
	{
		L.elem[j] = L.elem[j - 1];
	}
	//����Ԫ��
	L.elem[i] = num;
	L.length++;
	return NoneFlag;
}

//�����ӡ˳���
void printList(SqList L)
{
	for (int i = 0; i < L.length; i++)
	{
		printf("list�ĵ�%dλ�ǣ�%d\n", i, L.elem[i]);
	}
}

//ɾ��˳����е�i��λ�õ�Ԫ��
Flag deletList(SqList &L, int i)
{
	//���ж�i��λ���Ƿ�Ϸ�
	if (i < 0 || i > L.length - 1)
	{
		return DeleteWrongFlag;
	}
	//��i���Ԫ��ǰ��
	for (int j = i; j < L.length; j++)
	{
		L.elem[j] = L.elem[j + 1];
	}
	L.length--;
	return NoneFlag;;
}

//
/*compare:����˴��뺯���ĺ���ָ�룬Ҳ���Ƿ��˴����compare�����ĵ�ַ*/
int locateList(SqList L, int num, Flag(*compare)(int, int))
{
	int i = 0;//��¼�ҵ�����λ�� 
	int *p = L.elem;
	while (i <= L.length && (*compare)(*p++, num) == NoneFlag) ++i;//���* compare�����ǽ�ָ������ã�Ҳ���ǻ�ȡ�˺����Ķ���
	if (i < L.length) 
		return i;
	else 
		return -1;
}

/*compareTwoNum��compareTwoNum���뾲̬����̬��Ա��������ģ�������List�����Ķ���ģ����Ǿ�̬�Ļ�
* �ڵ���locateList������ʱ����compareTwoNumʱ���Ҳ������ĵ�ַ�����ǲ�֪�����������ĸ�����ġ�*/
Flag compareTwoNum(int a, int b)
{
	return a == b ? CompareSuccessFlag : NoneFlag;
}

Flag pingfang(int a, int b)
{
	return a == b * b ? CompareSuccessFlag : NoneFlag;
}

Flag kaifang(int a, int b)
{
	return a == sqrt(b) ? CompareSuccessFlag : NoneFlag;
}

//���ҵ�i��λ�õ���һ��
Flag NextElem(SqList L, int i, int &res)
{
	//���ж�i��λ���Ƿ�Ϸ�
	if (i < 0 || i > L.length - 2)
	{
		return noNextFlag;
	}
	//��ȡ��i��λ�õ���һ��Ԫ��
	res = L.elem[i + 1];
	return NoneFlag;
}

//���ҵ�i��λ�õ���һ��
Flag PriorElem(SqList L, int i, int &bobo)
{
	//���ж�i��λ���Ƿ�Ϸ�
	if (i < 1 || i > L.length - 1)
	{
		return noPriorFlag;
	}
	//��ȡ��i��λ�õ���һ��Ԫ��
	bobo = L.elem[i - 1];
	return NoneFlag;
}