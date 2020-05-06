#pragma once

typedef struct LinkNode1 {
	int data;
	struct LinkNode1 *next;
}LinkNode1;

typedef struct LinkQueue {
	LinkNode1 *head;//头指针
	LinkNode1 *rear;//尾指针
	int size;
}LinkQueue;

//初始化
LinkQueue *Init1();
//入队
void Push1(LinkQueue *queue, int data);
//返回队头元素
int Top_e1(LinkQueue *queue);
//出队
void Pop1(LinkQueue *queue, int data);
//返回队尾元素
int Bot_e1(LinkQueue *queue);
//判断是否为空
int IsEmpty1(LinkQueue *queue);
//返回队中元素个数
int Size1(LinkQueue *queue);
//销毁
void Free1(LinkQueue *queue);