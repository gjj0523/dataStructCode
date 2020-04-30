// insert_sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include "pch.h"
#include <iostream>
#include <stdio.h>

 // 数组长度
#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )

/*
 * 直接插入排序
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     n -- 数组的长度
 
void insertSort(int a[], int n)
{
	int temp, j, k;
	for (int i = 1; i < n; i++)
	{
		temp = a[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (a[j] < temp)
				break;
		}
		if (j != i-1)
		{
			for ( k = i - 1; k > j; k--)
			{
				a[k + 1] = a[k];					
			}
				a[k + 1] = temp;
		}		
	}
}*/

//折半插入排序
void insertSort(int a[], int n)
{
	int temp, j, k;
	int left = 0; int right = 0;
	for (int i = 1; i < n; i++)
	{
		for (int p = 0; p < i; p++)
		{
			left = 0;
			right = i - 1;
			
			while (left <= right)
			{   
				int m = (left + right) / 2;
				if (a[m] > a[i])
				{
					right = m - 1;
				}
				else
				{
					left = m + 1;
				}
			}
		}
		j = right;
		if (j != i - 1)
		{
			temp = a[i];
			for (k = i - 1; k > j; k--)
			{
				a[k + 1] = a[k];
			}			
			a[k + 1] = temp;
		}
	}
}

int main()
{
	int i;
	int a[] = { 20,40,30,30,10,50 };
	int ilen = LENGTH(a);

	printf("before sort:");
	for (i = 0; i < ilen; i++)
		printf("%d ", a[i]);
	printf("\n");

	insertSort(a, ilen);

	printf("after  sort:");
	for (i = 0; i < ilen; i++)
		printf("%d ", a[i]);
	printf("\n");
}