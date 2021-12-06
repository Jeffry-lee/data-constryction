#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
struct Arr
{
	int* first;//存储的是第一个元素的地址
	int len;//数组所能容纳元素的大小
	int cnt;//数组有效元素

};
void init_Arr(struct Arr*arr,int length);//初始化
bool append_Arr(struct Arr* arr,int val);//追加
bool insert_Arr(struct Arr* arr,int pos,int val);//插入.pos是从第一个元素开始而不是0指针
bool delete_Arr(struct Arr*arr,int pos,int*pval);//删除，并返回删除的值
int get();//得到元素
bool is_empty(struct Arr* arr);//判断是否为空
bool is_full(struct Arr* arr);//判断是否为满
void sortArr(struct Arr* arr);//排序
void showArr(struct Arr*arr);//展示排序
void inversionArr(struct Arr* arr);//倒置
int main()
{
	struct Arr arr;
	int val;
	init_Arr(&arr, 6);
	showArr(&arr);
	append_Arr(&arr, 12);
	append_Arr(&arr, 15);
	append_Arr(&arr, 19);
	append_Arr(&arr, 20);
	append_Arr(&arr, 25);
	insert_Arr(&arr, 2, 48);
	showArr(&arr);
	/*if (delete_Arr(&arr, 1, &val))
	{
		printf("删除成功\n");
		printf("您删除的元素是%d\n", val);
	}
	else
	{
		printf("删除失败\n");
	}
	showArr(&arr);*/
	inversionArr(&arr);
	printf("倒置后:\n");
	showArr(&arr);
	sortArr(&arr);
	printf("排序后:\n");
		showArr(&arr);

	system("pause");
	return 0;
}
void init_Arr(struct Arr* arr1,int length)
{
	arr1->first = (int*)malloc(sizeof(int) * length);
	if (NULL ==arr1->first)
	{
		printf("动态内存分配失败");
		exit(-1);//程序终止
	}
	else
	{
		arr1->len = length;
		arr1->cnt = 0;
	}
	return;
}
bool is_empty(struct Arr*arr1)
{
	if (0 == arr1->cnt)
		return true;
	else
		return false;
}
bool is_full(struct Arr* arr1)
{
	if (arr1->cnt == arr1->len)
		return true;
	else
		return false;
}
bool append_Arr(struct Arr*arr1,int val)
{
	if (is_full(arr1))
		return false;
	else
		arr1->first[arr1->cnt] = val;//cnt个有效元素对应的值
	arr1->cnt++;
	return true;
		

}
void showArr(struct  Arr*arr1)
{
	if (is_empty(arr1))
		printf("数组为空\n");
	else
		for (int i = 0; i <arr1->cnt; i++)
		{
			printf("%d", arr1->first[i]);
			printf("\n");
		}
	
}
bool insert_Arr(struct Arr* arr1, int pos, int val)
{
	if (is_full(arr1))
		return false;
	if (pos<0 || pos>arr1->cnt + 1)
		return false;
	for (int i =arr1->cnt-1; i >=pos-1; i--)
	{
		arr1->first[i + 1] = arr1->first[i];
	}
	arr1->first[pos - 1] = val;
	(arr1->cnt)++;
}
bool delete_Arr(struct Arr* arr1, int pos, int* pval)
{
	if (is_empty(arr1))
		return false;
	if (pos<0 || pos>arr1->cnt)
		return false;
	*pval = arr1->first[pos - 1];
	for (int i = pos; i < arr1->cnt; i++)
	{
		arr1->first[i - 1] = arr1->first[i];
	}
	arr1->cnt--;
}
void inversionArr(struct Arr* arr1)
{
	int i = 0;
	int j = arr1->cnt - 1;
	int t;
	while (i<j)
	{
		t = arr1->first[i];
		arr1->first[i] = arr1->first[j];
		arr1->first[j] = t;
		i++;
		j--;

	}
	return;
}
void sortArr(struct Arr* arr1)
{
	int i; int j; int t;
	for (i = 0; i < arr1->cnt;++i)
	{
		for (j = i + 1;j < arr1->cnt; ++j)
		{
			if (arr1->first[i] > arr1->first[j])
			{
				t = arr1->first[i];
				arr1->first[i] = arr1->first[j];
				arr1->first[j] = t;
			}
		}
	}
}