#pragma once

#define MAX_SIZE 1024

typedef struct SeqQueue {
	void *data[MAX_SIZE];
	int size;
}SeqQueue;

//初始化
SeqQueue *Init();
//入队
void Push(SeqQueue *queue, void *data);
//返回队头元素
void *Top_e(SeqQueue *queue);
//出队
void Pop(SeqQueue *queue, void *data);
//返回队尾元素
void *Bot_e(SeqQueue *queue);
//判断是否为空
int IsEmpty(SeqQueue *queue);
//返回队中元素个数
int Size(SeqQueue *queue);
//销毁
void Free(SeqQueue *queue);