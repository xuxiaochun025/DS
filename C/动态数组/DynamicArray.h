#pragma once
typedef struct DynamicArray {
	int *pAddr;//������ݵ�ַ
	int size;//��ǰԪ�ظ���
	int capacity;//�������
}Darr;

//��ʼ��
Darr *init_Array();//Darr����ָ�����
//����
void Insert_Array(Darr *arr,int value,int pos);
//ɾ��
void Delpos_Array(Darr *arr, int pos);
void Delval_Array(Darr *arr, int value);
//����
void Find_Array(Darr *arr, int value);
//��ӡ
void Print_Array(Darr *arr);
//�ͷ��ڴ�
void Free_Array(Darr *arr);