#pragma once

typedef struct LinkNode {
	char data;
	struct LinkNode *next;
}LinkNode;

typedef struct LinkStack {
	LinkNode *head;
	int size;
}LinkStack;

//初始化
LinkStack *Init();
//入栈
void Push(LinkStack *stack, char data);
//返回栈顶元素
char Top_e(LinkStack *stack);
//出栈
void Pop(LinkStack *stack, char data);
//判断是否为空
int IsEmpty(LinkStack *stack);
//返回栈中元素个数
int Size(LinkStack *stack);
//销毁
void Free(LinkStack *stack);