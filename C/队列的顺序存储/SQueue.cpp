#include<stdio.h>
#include<stdlib.h>
#include"SQueue.h"

//��ʼ��
SeqQueue *Init()
{
	SeqQueue *queue = (SeqQueue *)malloc(sizeof(SeqQueue));
	for (int i = 0; i < MAX_SIZE; i++) {
		queue->data[i] = NULL;
	}
	queue->size = 0;
	return queue;
}
//���
void Push(SeqQueue *queue, void *data)
{
	//���������Ϊ��ͷ
	if (queue == NULL) {
		return;
	}
	if (queue->size == MAX_SIZE) {
		return;
	}
	queue->data[queue->size] = data;
	queue->size++;
}
//���ض�ͷԪ��
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
//����
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
//���ض�βԪ��
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
//�ж��Ƿ�Ϊ��
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
//���ض���Ԫ�ظ���
int Size(SeqQueue *queue)
{
	return queue->size;
}
//����
void Free(SeqQueue *queue)
{
	if (queue == NULL) {
		return;
	}
	free(queue);
	queue->size = 0;
}