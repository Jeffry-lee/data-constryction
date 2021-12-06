#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
struct Arr
{
	int* first;//�洢���ǵ�һ��Ԫ�صĵ�ַ
	int len;//������������Ԫ�صĴ�С
	int cnt;//������ЧԪ��

};
void init_Arr(struct Arr*arr,int length);//��ʼ��
bool append_Arr(struct Arr* arr,int val);//׷��
bool insert_Arr(struct Arr* arr,int pos,int val);//����.pos�Ǵӵ�һ��Ԫ�ؿ�ʼ������0ָ��
bool delete_Arr(struct Arr*arr,int pos,int*pval);//ɾ����������ɾ����ֵ
int get();//�õ�Ԫ��
bool is_empty(struct Arr* arr);//�ж��Ƿ�Ϊ��
bool is_full(struct Arr* arr);//�ж��Ƿ�Ϊ��
void sortArr(struct Arr* arr);//����
void showArr(struct Arr*arr);//չʾ����
void inversionArr(struct Arr* arr);//����
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
		printf("ɾ���ɹ�\n");
		printf("��ɾ����Ԫ����%d\n", val);
	}
	else
	{
		printf("ɾ��ʧ��\n");
	}
	showArr(&arr);*/
	inversionArr(&arr);
	printf("���ú�:\n");
	showArr(&arr);
	sortArr(&arr);
	printf("�����:\n");
		showArr(&arr);

	system("pause");
	return 0;
}
void init_Arr(struct Arr* arr1,int length)
{
	arr1->first = (int*)malloc(sizeof(int) * length);
	if (NULL ==arr1->first)
	{
		printf("��̬�ڴ����ʧ��");
		exit(-1);//������ֹ
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
		arr1->first[arr1->cnt] = val;//cnt����ЧԪ�ض�Ӧ��ֵ
	arr1->cnt++;
	return true;
		

}
void showArr(struct  Arr*arr1)
{
	if (is_empty(arr1))
		printf("����Ϊ��\n");
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