#include<stdio.h>
#include<stdlib.h>
#include"SQueue.h"

//初始化
SeqQueue *Init()
{
	SeqQueue *queue = (SeqQueue *)malloc(sizeof(SeqQueue));
	for (int i = 0; i < MAX_SIZE; i++) {
		queue->data[i] = NULL;
	}
	queue->size = 0;
	return queue;
}
//入队
void Push(SeqQueue *queue, void *data)
{
	//数组左边作为队头
	if (queue == NULL) {
		return;
	}
	if (queue->size == MAX_SIZE) {
		return;
	}
	queue->data[queue->size] = data;
	queue->size++;
}
//返回队头元素
void *Top_e(SeqQueue *queue)
{
	if (queue == NULL) {
		return NULL;
	}
	if (queue->size == 0) {
		return NULL;
	}
	return queue->data[0];
}
//出队
void Pop(SeqQueue *queue, void *data)
{
	if (queue == NULL) {
		return;
	}
	if (queue->size == 0) {
		return;
	}
	data = queue->data[0];
	for (int i = 0; i < queue->size-1; i++) {
		queue->data[i] = queue->data[i + 1];
	}
	queue->size--;
}
//返回队尾元素
void *Bot_e(SeqQueue *queue)
{
	if (queue == NULL) {
		return NULL;
	}
	if (queue->size == 0) {
		return NULL;
	}
	return queue->data[queue->size - 1];
}
//判断是否为空
int IsEmpty(SeqQueue *queue)
{
	if (queue == NULL) {
		return -1;
	}
	if (queue->size == 0) {
		return  0;
	}
	return 1;
}
//返回队中元素个数
int Size(SeqQueue *queue)
{
	return queue->size;
}
//销毁
void Free(SeqQueue *queue)
{
	if (queue == NULL) {
		return;
	}
	free(queue);
	queue->size = 0;
}