#include<stdio.h>
#include<stdlib.h>
#include"LinkQueue.h"

//��ʼ��
LinkQueue *Init()
{
	LinkQueue *queue = (LinkQueue *)malloc(sizeof(LinkQueue));
	queue->size = 0;
	queue->head = (LinkNode *)malloc(sizeof(LinkNode));
	queue->head->data = NULL;
	queue->head->next = NULL;
	queue->rear = queue->head;
	return queue;
}
//���
void Push(LinkQueue *queue, void *data)
{
	if (queue == NULL) {
		return;
	}
	LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));
	newNode->data = data;
	newNode->next = NULL;
	queue->rear->next = newNode;//ͷ�����Ϊ��ͷ,��Ӳ���β�壬����ָ����Ҫ��ΪNULL
	queue->rear = newNode;
	queue->size++;
}
//���ض�ͷԪ��
void *Top_e(LinkQueue *queue)
{
	if (queue == NULL) {
		return NULL;
	}
	if (queue->size == 0) {
		return NULL;
	}
	LinkNode *p = queue->head->next;
	return p->data;
}
//����
void Pop(LinkQueue *queue, void *data)
{
	if (queue == NULL) {
		return;
	}
	if (queue->size == 0) {
		return;
	}
	LinkNode *q = queue->head->next;
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
//���ض�βԪ��
void *Bot_e(LinkQueue *queue)
{
	if (queue == NULL) {
		return NULL;
	}
	if (queue->size == 0) {
		return NULL;
	}
	LinkNode *p = queue->rear;
	return p->data;
}
//�ж��Ƿ�Ϊ��
int IsEmpty(LinkQueue *queue)
{
	if (queue == NULL) {
		return -1;
	}
	if (queue->size == 0) {
		return 0;
	}
	return 1;
}
//���ض���Ԫ�ظ���
int Size(LinkQueue *queue)
{
	return queue->size;
}
//����
void Free(LinkQueue *queue)
{
	if (queue == NULL) {
		return;
	}
	LinkNode *p = queue->head;
	LinkNode *q = NULL;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	queue->size = 0;
}