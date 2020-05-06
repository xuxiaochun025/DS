#include<stdio.h>
#include<stdlib.h>
#include"SeqStack.h"

//��ʼ��
SeqStack *Init()
{
	SeqStack *stack = (SeqStack *)malloc(sizeof(SeqStack));
	for (int i = 0; i < MAX_SIZE; i++) {
		stack->data[i] = NULL;
	}
	stack->size = 0;
	return stack;
}
//��ջ
void Push(SeqStack *stack, void *data)
{
	if (stack == NULL) {
		return;
	}
	if (stack->size == MAX_SIZE) {
		return;
	}
	stack->data[stack->size] = data;
	stack->size++;
}
//����ջ��Ԫ��
void *Top_e(SeqStack *stack)
{
	if (stack == NULL) {
		return NULL;
	}
	if (stack->size == 0) {
		return NULL;
	}
	return stack->data[stack->size - 1];
}
//��ջ
void Pop(SeqStack *stack, void *data)
{
	if (stack == NULL) {
		return;
	}
	if (stack->size == 0) {
		return;
	}
	data = stack->data[stack->size-1];
	stack->size--;
}
//�ж��Ƿ�Ϊ��
int IsEmpty(SeqStack *stack) 
{
	if (stack == NULL) {
		return -1;
	}
	if (stack->size == 0) {
		return 0;
	}
	return 1;
}
//����ջ��Ԫ�ظ���
int Size(SeqStack *stack)
{
	return stack->size;
}
//����
void Free(SeqStack *stack)
{
	if (stack == NULL) {
		return;
	}
	free(stack);
	stack->size = 0;
}
