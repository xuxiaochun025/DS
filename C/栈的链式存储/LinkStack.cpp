#include<stdio.h>
#include<stdlib.h>
#include"LinkStack.h"

//初始化
LinkStack *Init()
{
	LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack));
	stack->head = (LinkNode *)malloc(sizeof(LinkNode));
	stack->head->data = NULL;
	stack->head->next = NULL;
	stack->size = 0;
	return stack;
}
//入栈
void Push(LinkStack *stack, void *data)
{
	if (stack == NULL) {
		return;
	}
	LinkNode *p = stack->head;//先进后出，要采用头插法
	LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));
	newNode->data = data;
	newNode->next = p->next;
	p->next = newNode;
	stack->size++;
}
//返回栈顶元素
void *Top_e(LinkStack *stack)
{
	if (stack == NULL) {
		return NULL;
	}
	if (stack->size == 0) {
		return NULL;
	}
	LinkNode *p = stack->head->next;
	return p->data;
}
//出栈
void Pop(LinkStack *stack, void *data)
{
	if (stack == NULL) {
		return;
	}
	if (stack->size == 0) {
		return;
	}
	LinkNode *q = stack->head->next;
	stack->head->next = q->next;
	free(q);
	stack->size--;
}
//判断是否为空
int IsEmpty(LinkStack *stack)
{
	if (stack == NULL) {
		return -1;
	}
	if (stack->size==0) {
		return 0;
	}
	return 1;
}
//返回栈中元素个数
int Size(LinkStack *stack)
{
	if (stack == NULL) {
		return NULL;
	}
	return stack->size;
}
//销毁
void Free(LinkStack *stack)
{
	if (stack == NULL) {
		return;
	}
	LinkNode *p = stack->head;
	LinkNode *q = NULL;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	stack->size = 0;
}