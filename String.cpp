
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define ERROR -1
#define OK 0
//串的堆分配存储表示结构体
typedef struct HString {
	char *ch;//ch指向字符串的首地址
	int length;//字符串的长度
}HString;

//初始化字符串
int InitString(HString &s)
{
	s.ch = NULL;
	s.length = 0;
	return OK;
}

//用char数组来初始化串T
int StrAssign(HString &T, char *chars)
{ 
	//用char数组生成HString对象
	//清空T
	if (T.ch) free(T.ch);
	//求chars的长度
	int length = strlen(chars);
	//判断传进来的数组是否是空的
	if (!length) { T.ch = NULL; T.length = 0; }
	else 
	{
		//不是空的则为T开辟空间并将数组值拷贝到T中
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
	//返回S的元素个数，称为串长
	return S.length;
}

int StrCompare(HString S, HString T) 
{
	//比较S，T的元素大小差
	//若S，T的元素都相同，就返回S，T的长度差
	//比如S = "abcde",T = "abcdefgh"则返回3
	//若元素不同就返回S，T那个序列更大
	//比如S = "abdfg",T = "abcfg",显然S > T所以返回大于零
	for (int i = 0; i < S.length && i < T.length; i++)
	{
		if (S.ch[i] != T.ch[i]) return S.ch[i] - T.ch[i];
	}
	return S.length - T.length;
}

int ClearString(HString &S)
{
	//将S清空
	if (S.ch) { 
		free(S.ch); 
		S.ch = NULL; 
	}
	S.length = 0;
	return OK;
}

int Concat(HString &T, HString S1, HString S2)
{
	//用T返回S1+S2的新串
	//比如S1 = "abc",S2 = "def",则 T = "abcdef"
	//清空目标串T
	if (T.ch) free(T.ch);
	//给目标串T分配S1加S2的长度空间
	if (!(T.ch = (char *)malloc((S1.length + S2.length) * sizeof(char)))) return ERROR;
	T.length = S1.length + S2.length;
	//把S1拷贝到T中
	for (int i = 0; i < S1.length; i++)
	{
		T.ch[i] = S1.ch[i];
	}
	//把S2拷贝到T中
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
	//用Sub返回串S第POS个字符起长度为len的子串
	//判断子串位置是否合理
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
	printf("----------开始打印字符串----------------\n");
	for (int i = 0;i < S.length; i++)
	{
		printf("%c", *S.ch++);
	}
	printf("\n----------结束打印字符串----------------\n");
} 

//判断一个串(T)是不是另一个串(S)的子串
int Index(HString S,HString T) 
{   //定义i,j分别为主串和子串的起始位置 
	int i=0, j=0;	
    //子串长度大于主串长度，返回 
	if(T.length>S.length)
	{		
		return ERROR;
	}
    //子串长度为空，返回0 
	if(T.length==0)
	{
		return 0; 
	}
	//当ij都未到末尾时，进入循环 
	while(i<S.length && j<T.length)
	{   //在当前位置，主串子串元素相等，则标志后移 
		if(S.ch[i] == T.ch[j]){
			i++;j++;
		}
		//不相等时，i指向本次匹配首位的下一位 ，j指向子串起始位置 
		else{
			i=i-j+1;
			j=0;
		}
	}
	//T为S子串，返回主串中子串起始位置；否则返回 
	if(j>=T.length){
		
		return (i-j);
	}
	else   
	    return ERROR;
}
//求最长回文子串 
char Substring(HString s)
{
	int i=0,j=0,p=0,q=0;
	int max=0;  
    // 当s长度为零时返回 
	if(s.length<=1){
		return 0;
	}	
	//设i为回文子串的中心位置 
	for(i=0 ; i<s.length-1 ; i++)  
	{
		for(j=0 ; j<=i ; j++){
			//判断若存在回文子串为奇数 ,将pq分别指向回文子串的起点终点
		    if(s.ch[i-j]==s.ch[i+j])
		    {	//定义max为"最长"回文子串，当回文子串长度大于当前max,则修改pq ，与max长度 
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
			//判断若存在回文子串为偶数 ,将pq分别指向回文子串的起点终点
		    if(s.ch[i-j]==s.ch[i+j+1]) 
		    {   //定义max为"最长"回文子串，当回文子串长度大于当前max,则修改pq，与max长度 
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
	// 遍历结束后，将p~q之间的元素输出
   	printf("最长字符串为："); 
    for (i=p;i<=q;i++)       
        printf("%c",s.ch[i]);
    return 0;
}


int main()
{
	char ch[10] = { 'a','a','a','a','a','a','a','a','a'};
	char ch2[5] = {};
	
/*	printf("char大小：%d\n", sizeof(char));
	printf("int大小：%d\n", sizeof(int));
	printf("float大小：%d\n", sizeof(float));
	printf("double大小：%d\n", sizeof(double));
	
    HString s;
	InitString(s);
	StrAssign(s, &ch[0]);
	printf("s的长度是：%d\n", StrLength(s));
	printfHString(s);  */
	HString S,T;
	InitString(S);
	InitString(T);
	StrAssign(S, &ch[0]);
	StrAssign(T, &ch2[0]);
	
	Substring(S);
	/*printf("S比T大:%d\n", StrCompare(S, T));
	ClearString(S);*/

	/*Index(S,T) ;
	if (Index(S,T) == ERROR)
	{
		printf("不是子串\n");
	}
	else
	{
		printf("字串初始位置在%d\n");
	}*/
	
	
/*	Concat(s, S, T);
	printfHString(s);
	SubString(S, s, 1, 4);
	printfHString(S);
	
	char temp = '\0';
	charAt(S, 5, temp);
	printf("字符是:%c\n", temp);
	return 0;*/
}
