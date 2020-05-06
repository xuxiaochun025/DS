#include<stdio.h>
#include<stdlib.h>
#include"SeqStack.h"

//初始化
SeqStack *Init()
{
	SeqStack *stack = (SeqStack *)malloc(sizeof(SeqStack));
	for (int i = 0; i < MAX_SIZE; i++) {
		stack->data[i] = NULL;
	}
	stack->size = 0;
	return stack;
}
//入栈
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
//返回栈顶元素
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
//出栈
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
//判断是否为空
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
//返回栈中元素个数
int Size(SeqStack *stack)
{
	return stack->size;
}
//销毁
void Free(SeqStack *stack)
{
	if (stack == NULL) {
		return;
	}
	free(stack);
	stack->size = 0;
}
