#pragma once
#define MAX_SIZE 1024

typedef struct SeqStack {
	void *data[MAX_SIZE];
	int size;
}SeqStack;

//��ʼ��
SeqStack *Init();
//��ջ
void Push(SeqStack *stack, void *data);
//����ջ��Ԫ��
void *Top_e(SeqStack *stack);
//��ջ
void Pop(SeqStack *stack, void *data);
//�ж��Ƿ�Ϊ��
int IsEmpty(SeqStack *stack);
//����ջ��Ԫ�ظ���
int Size(SeqStack *stack);
//����
void Free(SeqStack *stack);