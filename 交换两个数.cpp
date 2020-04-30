#include <stdio.h>


void swap(int a,int b); 
void swap1(int *a,int *b);
void swap2(int &a,int &b);
int main()
{
	int a = 2; 
	int b=3;
	swap(a,b);
	printf("a = %d  b = %d\r\n",a,b);
	swap1(&a,&b);
	printf("a = %d  b = %d\r\n",a,b);
	swap2(a,b);
	printf("a = %d  b = %d\r\n",a,b);
	return 0;
}
void swap(int a,int b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

void swap1(int *a,int *b)
{
	int temp = 0;
	temp = *a; 
	*a=*b;
	*b = temp;
}

void swap2(int &a,int &b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}
