#pragma once
typedef struct DynamicArray {
	int *pAddr;//存放数据地址
	int size;//当前元素个数
	int capacity;//最大容量
}Darr;

//初始化
Darr *init_Array();//Darr类型指针变量
//插入
void Insert_Array(Darr *arr,int value,int pos);
//删除
void Delpos_Array(Darr *arr, int pos);
void Delval_Array(Darr *arr, int value);
//查找
void Find_Array(Darr *arr, int value);
//打印
void Print_Array(Darr *arr);
//释放内存
void Free_Array(Darr *arr);