#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

#define ERROR -1
#define OK 0
#define STACK_INIT_SIZE 100//�洢�ռ��ʼ����ռ�
#define STACKINCREMENT 10//�洢�ռ��������
#define zuo 1
#define you 2

#define zuo1 3
#define you1 4
#define zuo2 5
#define you2 6
#define zuo3 7
#define you3 8

typedef struct SqStack {
	int *base;
	int *top;
	int stackSize;
}SqStack;


int InitStack(SqStack &STK)
{
	STK.base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));//����ַ
	if (!STK.base)return ERROR;
	STK.top = STK.base;
	STK.stackSize = STACK_INIT_SIZE;
	return OK;
}

int GetTop(SqStack STK, int &num)
{
	if (STK.top == STK.base) return ERROR;
	num = *(STK.top - 1);
	return num;
}

int GetBase(SqStack STK, int &num)
{
	if (STK.top == STK.base) return ERROR;
	num = *(STK.base);
	return OK;
}

int Pop(SqStack &STK, int &num)
{
	//�ж�ջ�Ƿ�Ϊ��
	if (STK.top == STK.base) return ERROR;
	num = *STK.top;
	*STK.top--;
	return num;
}

int Push(SqStack &STK, int num)
{
	//�ж��Ƿ�ջ��Ҫ�ӿռ�
	if (STK.top - STK.base >= STK.stackSize)
	{
		STK.base = (int *)realloc(STK.base, (STK.stackSize + STACKINCREMENT) * sizeof(int));
		if (!STK.base) return ERROR;

		STK.top = STK.base + STK.stackSize;
		STK.stackSize += STACKINCREMENT;
	}

	*STK.top = num;
	STK.top++;
	return OK;

}

int GetLength(SqStack STK)
{
	return STK.top - STK.base;
}

void printStack(SqStack STK)
{
	int *temp = STK.top - 1;
	printf("ջ�������ǣ�");
	while (temp >= STK.base)
	{
		printf("%d,", *temp);
		temp--;
	}
	printf("\n");
}
/*
//�ж������Ƿ���Ч����Ч�Ļ�����1����Ч����0�� {zuo1,zuo1,you1,you1};
int isValid(int *s)
{
	int i=0,num;		
	while(s[i]){    //���ַ�����Ϊ��ʱ������ѭ�� 
		if(s[i]){          //  ��ջ���գ�����ѭ�� 
			if(s[i]==zuo1|| s[i]==zuo2|| s[i]==zuo3){
				Push(STK, s[i]);           //��������������ţ�ѹջ 
			}
			else if(s[i]=you1){    //����ǵ�1�������� 
				if(GetTop(STK, num)==zuo1)
				{
					Pop(STK, num);    //��ջ��Ԫ��Ϊ��1�������ţ���ջ 
				}
				else
				printf("����\n");    //������Ϊ��Ч���� 
				return 0;
			}
			else if(s[i]=you2){   //����ǵ�2�������� 
				if(GetTop(STK, num)==zuo2)
				{
					Pop(STK, num);    //��ջ��Ԫ��Ϊ��2�������ţ���ջ
				}
				else
				printf("����\n");     //������Ϊ��Ч���� 
				return 0;
			}
			else if(s[i]=you3){    //����ǵ�3�������� 
				if(GetTop(STK, num)==zuo3)
				{
					Pop(STK, num);    //��ջ��Ԫ��Ϊ��3�������ţ���ջ
				}
				else
				printf("����\n");    //������Ϊ��Ч���� 
				return 0;
			}
			i++;						
		}
		else{
			Push(STK,s[i]);		// ��ջΪ�գ���Ԫ��ѹջ 	
			i++;
		}
	}
	if(STK.top == STK.base){
	    printf("��\n");     //�ж��������ǿ�ջ����Ϊ��Ч���ţ�����1 
	    return 1;
	}
	else{
		printf("����\n");
	    return 0;        //����Ϊ��Ч���ƣ�����0 
	}
}*/
	
int judgeBracket(SqStack &STK,int s[])
{	
    int num;//�������λ�õ�ǰһ���ַ�Ϊnum;
    int i=0; 
    while(s[i]){	 
        if(s[i] == zuo){
        	Push(STK,s[i]);  //���������������ţ�ѹջ 
        }
        else if(s[i] == you){  //���������������ţ�����if��� 
        	 if(GetTop(STK,num)!=ERROR)//�������λ��ǰ���ַ�������if��䣻���򷵻�error 
            {
                if(num!=zuo)
                    return ERROR;  //�������λ��ǰ�ַ����������ţ�����error 
                else
                    Pop(STK,num);//����λ��ǰ�ַ��������ţ��� ǰ�ַ� ��ջ 
            }else
        		return ERROR;
		}
    	++i;//��i��1�󣬸�ֵ����һ��=-= 
    }
    if(!(STK.top == STK.base))
	    return ERROR;   //���ջ��Ϊ�գ�����error,��������Ч 
	else
		return OK;
}

int dc(int *arr,int length)
{	
	SqStack STK;
    InitStack(STK);
	int i,	j;
	if(length<1)
	{
		printf("����\n");
		return 0;        //������Ϊ�գ����� 
	}
	if(length%2){	
    	for(i=0;i<=length/2;i++)
		{
			Push(STK, arr[i]);  //����Ϊż�����������飬��Ԫ����ջ 
    	}
	}
	else{
		for(i=0;i<=(length-1)/2;i++)
		{
			Push(STK, arr[i]);  //����Ϊ�������������飬��Ԫ����ջ 
    	}
	}	
	int *p = STK.top;
    while (p >= STK.base){	
		for(j=0;j<=(length-1)/2;j++)
        {  	
	        if(*p==arr[(length-1)/2+j] )    
	     	{					             
				STK.top--;
	     	}
	    	p=STK.top;	    	//����ջ����ջ��Ԫ��������Ԫ����ȣ���Ԫ�ص�ջ 
	    }
	}
	if (STK.top == STK.base) 
    	return 1;        //��ջΪ�գ���Ϊ�Գ� 
    else
	    return 0;       //����Ϊ���Գ� 
}

 


int main()
{   
    int arr[4]={1,2,2,1};
	dc(arr,4);
	
	/*int s[4] = {zuo1,zuo1,you1,you1};
	InitStack(STK);
	if(isValid(s) == OK)
		printf("ok");
	else
		printf("wrong");*/
		
	/*char temp[5] = {'a','b','c','d'};
	for(int i = 0; i < 5; i++)
	{
		printf("��%d���ǣ�%c\n",i,temp[i]);
	}*/

	
	/*SqStack stack;
	int s[5] = { zuo,you,zuo,zuo,zuo };
	InitStack(stack);
	if (judgeBracket(stack, s) == ERROR)
	{
		printf("����\n");
	}
	else
	{
		printf("��\n");
	}
	return 0;*/
	
	
	
	/*SqStack sq;
	if (InitStack(sq) == ERROR)
	{
		printf("�ռ����ʧ��\n");
		return -1;
	}
	else
	{
		printf("ջ��ʼ���ɹ�\n");
	}
	printStack(sq);
	Push(sq, 5);
	Push(sq, 4);
	Push(sq, 3);
	Push(sq, 2);
	printStack(sq);
	int num = 0;
	Pop(sq,num);
	printStack(sq);
	GetTop(sq, num);
	printf("top�ǣ�%d\n", num);
	GetBase(sq, num);
	printf("base�ǣ�%d\n", num);*/
	
}

/*//����{}����
bool is_Valid(char * s){
    //���ַ�����Ȼ����
    if(*s == 0) return true;

    int len = strlen(s);

    //�������ȵ��ַ�����Ȼ������
    if(len & 1) return false;

    char stack[len];
    int top = -1;
    for(int i=0; i<len; ++i){
        //������������ǣ���ӭ��ջ
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            stack[++top] = s[i];
        //�����������ǣ����ջ�����޷���ԣ�������
        else if(top == -1) return false;
        //�����������ǣ�ջ�ǿգ���ǰ��ջ����ԣ�����
        else if(s[i] == stack[top]+1 || s[i] == stack[top]+2)  //ascii�����ֵ 
            stack[top--] = 0;
        //�����������ǣ�ջ�ǿգ���ǰ��ջ������ԣ�������
        else return false;
    }
    //���ջΪ������ϣ���Ϊ���򲻷���
    return top == -1;
}
*/
