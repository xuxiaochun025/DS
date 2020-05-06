#include<stdio.h>
#include<stdlib.h>
#include"LinkQueue.h"

//��ʼ��
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
//���
void Push1(LinkQueue *queue, int data)
{
	if (queue == NULL) {
		return;
	}
	LinkNode1 *newNode = (LinkNode1 *)malloc(sizeof(LinkNode1));
	newNode->data = data;
	newNode->next = NULL;
	queue->rear->next = newNode;//ͷ�����Ϊ��ͷ,��Ӳ���β�壬����ָ����Ҫ��ΪNULL
	queue->rear = newNode;
	queue->size++;
}
//���ض�ͷԪ��
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
//����
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
//���ض�βԪ��
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
//�ж��Ƿ�Ϊ��
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
//���ض���Ԫ�ظ���
int Size1(LinkQueue *queue)
{
	return queue->size;
}
//����
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