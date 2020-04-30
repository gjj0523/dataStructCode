
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define ERROR -1
#define OK 0
//���Ķѷ���洢��ʾ�ṹ��
typedef struct HString {
	char *ch;//chָ���ַ������׵�ַ
	int length;//�ַ����ĳ���
}HString;

//��ʼ���ַ���
int InitString(HString &s)
{
	s.ch = NULL;
	s.length = 0;
	return OK;
}

//��char��������ʼ����T
int StrAssign(HString &T, char *chars)
{ 
	//��char��������HString����
	//���T
	if (T.ch) free(T.ch);
	//��chars�ĳ���
	int length = strlen(chars);
	//�жϴ������������Ƿ��ǿյ�
	if (!length) { T.ch = NULL; T.length = 0; }
	else 
	{
		//���ǿյ���ΪT���ٿռ䲢������ֵ������T��
		if(!(T.ch = (char *)malloc(length * sizeof(char))))
			return ERROR;
		for (int i = 0; i < length; i++)
		{
			T.ch[i] = chars[i];
		}
		T.length = length;
	}
	return OK;
}

int StrLength(HString S)
{
	//����S��Ԫ�ظ�������Ϊ����
	return S.length;
}

int StrCompare(HString S, HString T) 
{
	//�Ƚ�S��T��Ԫ�ش�С��
	//��S��T��Ԫ�ض���ͬ���ͷ���S��T�ĳ��Ȳ�
	//����S = "abcde",T = "abcdefgh"�򷵻�3
	//��Ԫ�ز�ͬ�ͷ���S��T�Ǹ����и���
	//����S = "abdfg",T = "abcfg",��ȻS > T���Է��ش�����
	for (int i = 0; i < S.length && i < T.length; i++)
	{
		if (S.ch[i] != T.ch[i]) return S.ch[i] - T.ch[i];
	}
	return S.length - T.length;
}

int ClearString(HString &S)
{
	//��S���
	if (S.ch) { 
		free(S.ch); 
		S.ch = NULL; 
	}
	S.length = 0;
	return OK;
}

int Concat(HString &T, HString S1, HString S2)
{
	//��T����S1+S2���´�
	//����S1 = "abc",S2 = "def",�� T = "abcdef"
	//���Ŀ�괮T
	if (T.ch) free(T.ch);
	//��Ŀ�괮T����S1��S2�ĳ��ȿռ�
	if (!(T.ch = (char *)malloc((S1.length + S2.length) * sizeof(char)))) return ERROR;
	T.length = S1.length + S2.length;
	//��S1������T��
	for (int i = 0; i < S1.length; i++)
	{
		T.ch[i] = S1.ch[i];
	}
	//��S2������T��
	for (int i = S1.length; i < T.length; i++)
	{
		T.ch[i] = S2.ch[i - S1.length];
	}
	return OK;
}
int SubString(HString &Sub, HString S, int pos, int len)
{
	//S = "abcdefg"
	//pos = 1
	//len = 4
	//��Sub���ش�S��POS���ַ��𳤶�Ϊlen���Ӵ�
	//�ж��Ӵ�λ���Ƿ����
	if (pos<1 || pos>S.length || len < 0 || len > S.length - pos + 1)
	{
		return ERROR;
	}
	if (Sub.ch) free(Sub.ch);
	if (!len) { Sub.ch = NULL; Sub.length = 0; }
	else
	{
		Sub.ch = (char *)malloc(len * sizeof(char));
		for (int i = 0; i < len; i++)
		{
			Sub.ch[i] = S.ch[i + pos - 1];
		}
		Sub.length = len;
	}
	return OK;
}

int charAt(HString S, int pos,char &res)
{
	if (pos<1 || pos>S.length)
	{
		return ERROR;
	}
	res = S.ch[pos - 1];
}

void printfHString(HString S)
{
	printf("----------��ʼ��ӡ�ַ���----------------\n");
	for (int i = 0;i < S.length; i++)
	{
		printf("%c", *S.ch++);
	}
	printf("\n----------������ӡ�ַ���----------------\n");
} 

//�ж�һ����(T)�ǲ�����һ����(S)���Ӵ�
int Index(HString S,HString T) 
{   //����i,j�ֱ�Ϊ�������Ӵ�����ʼλ�� 
	int i=0, j=0;	
    //�Ӵ����ȴ����������ȣ����� 
	if(T.length>S.length)
	{		
		return ERROR;
	}
    //�Ӵ�����Ϊ�գ�����0 
	if(T.length==0)
	{
		return 0; 
	}
	//��ij��δ��ĩβʱ������ѭ�� 
	while(i<S.length && j<T.length)
	{   //�ڵ�ǰλ�ã������Ӵ�Ԫ����ȣ����־���� 
		if(S.ch[i] == T.ch[j]){
			i++;j++;
		}
		//�����ʱ��iָ�򱾴�ƥ����λ����һλ ��jָ���Ӵ���ʼλ�� 
		else{
			i=i-j+1;
			j=0;
		}
	}
	//TΪS�Ӵ��������������Ӵ���ʼλ�ã����򷵻� 
	if(j>=T.length){
		
		return (i-j);
	}
	else   
	    return ERROR;
}
//��������Ӵ� 
char Substring(HString s)
{
	int i=0,j=0,p=0,q=0;
	int max=0;  
    // ��s����Ϊ��ʱ���� 
	if(s.length<=1){
		return 0;
	}	
	//��iΪ�����Ӵ�������λ�� 
	for(i=0 ; i<s.length-1 ; i++)  
	{
		for(j=0 ; j<=i ; j++){
			//�ж������ڻ����Ӵ�Ϊ���� ,��pq�ֱ�ָ������Ӵ�������յ�
		    if(s.ch[i-j]==s.ch[i+j])
		    {	//����maxΪ"�"�����Ӵ����������Ӵ����ȴ��ڵ�ǰmax,���޸�pq ����max���� 
			    while(2*j+1 > max)	
				{
					max=2*j+1;					
		            p=i-j;
                    q=i+j;
				}
            }
			else 
			    break;
		}
		for(j=0 ; j<=i ; j++){
			//�ж������ڻ����Ӵ�Ϊż�� ,��pq�ֱ�ָ������Ӵ�������յ�
		    if(s.ch[i-j]==s.ch[i+j+1]) 
		    {   //����maxΪ"�"�����Ӵ����������Ӵ����ȴ��ڵ�ǰmax,���޸�pq����max���� 
		    	while(2*j+2 > max)
				{			
		    	    max=2*j+2;
			    	p=i-j;  
                    q=i+j+1;
				}
		    }
		    else
			    break;
		}			   
	}	
	// ���������󣬽�p~q֮���Ԫ�����
   	printf("��ַ���Ϊ��"); 
    for (i=p;i<=q;i++)       
        printf("%c",s.ch[i]);
    return 0;
}


int main()
{
	char ch[10] = { 'a','a','a','a','a','a','a','a','a'};
	char ch2[5] = {};
	
/*	printf("char��С��%d\n", sizeof(char));
	printf("int��С��%d\n", sizeof(int));
	printf("float��С��%d\n", sizeof(float));
	printf("double��С��%d\n", sizeof(double));
	
    HString s;
	InitString(s);
	StrAssign(s, &ch[0]);
	printf("s�ĳ����ǣ�%d\n", StrLength(s));
	printfHString(s);  */
	HString S,T;
	InitString(S);
	InitString(T);
	StrAssign(S, &ch[0]);
	StrAssign(T, &ch2[0]);
	
	Substring(S);
	/*printf("S��T��:%d\n", StrCompare(S, T));
	ClearString(S);*/

	/*Index(S,T) ;
	if (Index(S,T) == ERROR)
	{
		printf("�����Ӵ�\n");
	}
	else
	{
		printf("�ִ���ʼλ����%d\n");
	}*/
	
	
/*	Concat(s, S, T);
	printfHString(s);
	SubString(S, s, 1, 4);
	printfHString(S);
	
	char temp = '\0';
	charAt(S, 5, temp);
	printf("�ַ���:%c\n", temp);
	return 0;*/
}
