#pragma once
#define MAX_SIZE 1024

typedef struct SeqStack {
	void *data[MAX_SIZE];
	int size;
}SeqStack;

//初始化
SeqStack *Init();
//入栈
void Push(SeqStack *stack, void *data);
//返回栈顶元素
void *Top_e(SeqStack *stack);
//出栈
void Pop(SeqStack *stack, void *data);
//判断是否为空
int IsEmpty(SeqStack *stack);
//返回栈中元素个数
int Size(SeqStack *stack);
//销毁
void Free(SeqStack *stack);