#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"DynamicArray.h"

//初始化
Darr *init_Array()
{
	Darr *array = (Darr *)malloc(sizeof(Darr));
	array->size = 0;
	array->capacity = 20;
	array->pAddr = (int *)malloc(sizeof(int)*array->capacity);
	return array;
}
//插入
void Insert_Array(Darr *arr, int value,int pos)
{
	if (arr == NULL) {
		return;
	}
	//判断空间是否足够
	if (arr->size == arr->capacity)
	{
		int *newspace = (int *)malloc(sizeof(int)*arr->capacity * 2);
		memcpy(newspace, arr->pAddr, arr->capacity * sizeof(int));
		free(arr->pAddr);
		arr->capacity = arr->capacity * 2;
		arr->pAddr = newspace;
	}
	if (pos<0 || pos>arr->size - 1) {
		pos = arr->size;
		arr->pAddr[arr->size] = value;
	}
	else {
		for (int i = arr->size; i >= pos; i--) {
			arr->pAddr[i + 1] = arr->pAddr[i];
		}
		arr->pAddr[pos] = value;
	}
	arr->size++;
}
//删除
void Delpos_Array(Darr *arr, int pos)
{
	if (arr == NULL) {
		return;
	}
	if (pos<0 || pos>arr->size-1) {
		return;
	}
	for (int i = pos; i < arr->size; i++) {
		arr->pAddr[i] = arr->pAddr[i + 1];
	}
	arr->size--;
}
void Delval_Array(Darr *arr, int value)
{
	if (arr == NULL) {
		return;
	}
	int pos = -1;
	for (int i = 0; i < arr->size; i++) {
		if (arr->pAddr[i] == value) {
			pos = i;
			break;
		}
	}
	Delpos_Array(arr, pos);//调用值的删除
}
//查找
void Find_Array(Darr *arr, int value)
{
	if (arr == NULL) {
		return;
	}
	int isFind = -1;
	for (int i = 0; i < arr->size; i++) {
		if (arr->pAddr[i] == value) {
			isFind = 1;
			break;
		}
	}
	if (isFind == 1) {
		printf("Find %d\n",value);
	}
	else {
		printf("Not Find.\n");
	}
}
//打印
void Print_Array(Darr *arr)
{
	if (arr == NULL) {
		return;
	}
	for (int i = 0; i < arr->size; i++) {
		printf("%d ", arr->pAddr[i]);
	}
	printf("\n");
}
//释放内存
void Free_Array(Darr *arr)
{
	if (arr == NULL) {
		return;
	}
	if (arr->pAddr != NULL) {
		free(arr->pAddr);
	}
	free(arr);
}

void test()
{
	Darr *array = init_Array();
	for (int i = 0; i < 5; i++) {
		Insert_Array(array, i, i);
	}
	Print_Array(array);
	Insert_Array(array, 78, 3);
	Print_Array(array);
	Insert_Array(array, 34, 7);
	Print_Array(array);
	Find_Array(array, 4);
	Print_Array(array);
	Delpos_Array(array, 0);
	Print_Array(array);
	Delval_Array(array, 3);
	Print_Array(array);
	Free_Array(array);
	Print_Array(array);
}

int main()
{
	test();
	return 0;
}