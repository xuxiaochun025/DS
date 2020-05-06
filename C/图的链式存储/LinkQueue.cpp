#include<stdio.h>
#include<stdlib.h>
#include"LinkQueue.h"

//初始化
LinkQueue *Init1()
{
	LinkQueue *queue = (LinkQueue *)malloc(sizeof(LinkQueue));
	queue->size = 0;
	queue->head = (LinkNode1 *)malloc(sizeof(LinkNode1));
	queue->head->data = NULL;
	queue->head->next = NULL;
	queue->rear = queue->head;
	return queue;
}
//入队
void Push1(LinkQueue *queue, int data)
{
	if (queue == NULL) {
		return;
	}
	LinkNode1 *newNode = (LinkNode1 *)malloc(sizeof(LinkNode1));
	newNode->data = data;
	newNode->next = NULL;
	queue->rear->next = newNode;//头结点作为队头,入队采用尾插，最后的指针域要置为NULL
	queue->rear = newNode;
	queue->size++;
}
//返回队头元素
int Top_e1(LinkQueue *queue)
{
	if (queue == NULL) {
		return NULL;
	}
	if (queue->size == 0) {
		return NULL;
	}
	LinkNode1 *p = queue->head->next;
	return p->data;
}
//出队
void Pop1(LinkQueue *queue, int data)
{
	if (queue == NULL) {
		return;
	}
	if (queue->size == 0) {
		return;
	}
	LinkNode1 *q = queue->head->next;
	data = q->data;
	if (q->next == NULL) {
		queue->head->next = q->next;
		queue->rear = queue->head;
	}
	else {
		queue->head->next = q->next;
	}
	free(q);
	queue->size--;
}
//返回队尾元素
int Bot_e1(LinkQueue *queue)
{
	if (queue == NULL) {
		return NULL;
	}
	if (queue->size == 0) {
		return NULL;
	}
	LinkNode1 *p = queue->rear;
	return p->data;
}
//判断是否为空
int IsEmpty1(LinkQueue *queue)
{
	if (queue == NULL) {
		return -1;
	}
	if (queue->size == 0) {
		return 0;
	}
	return 1;
}
//返回队中元素个数
int Size1(LinkQueue *queue)
{
	return queue->size;
}
//销毁
void Free1(LinkQueue *queue)
{
	if (queue == NULL) {
		return;
	}
	LinkNode1 *p = queue->head;
	LinkNode1 *q = NULL;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	queue->size = 0;
}