#pragma once

typedef struct LinkNode {
	void *data;
	struct LinkNode *next;
}LinkNode;

typedef struct LinkStack {
	LinkNode *head;
	int size;
}LinkStack;

//初始化
LinkStack *Init();
//入栈
void Push(LinkStack *stack, void *data);
//返回栈顶元素
void *Top_e(LinkStack *stack);
//出栈
void Pop(LinkStack *stack, void *data);
//判断是否为空
int IsEmpty(LinkStack *stack);
//返回栈中元素个数
int Size(LinkStack *stack);
//销毁
void Free(LinkStack *stack);


typedef struct LinkQueue {
	LinkNode *head;//头指针
	LinkNode *rear;//尾指针
	int size;
}LinkQueue;

//初始化
LinkQueue *Init1();
//入队
void Push(LinkQueue *queue, void *data);
//返回队头元素
void *Top_e(LinkQueue *queue);
//出队
void Pop(LinkQueue *queue, void *data);
//返回队尾元素
void *Bot_e(LinkQueue *queue);
//判断是否为空
int IsEmpty(LinkQueue *queue);
//返回队中元素个数
int Size(LinkQueue *queue);
//销毁
void Free(LinkQueue *queue);