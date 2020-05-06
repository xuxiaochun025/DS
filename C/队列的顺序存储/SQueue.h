#pragma once

#define MAX_SIZE 1024

typedef struct SeqQueue {
	void *data[MAX_SIZE];
	int size;
}SeqQueue;

//��ʼ��
SeqQueue *Init();
//���
void Push(SeqQueue *queue, void *data);
//���ض�ͷԪ��
void *Top_e(SeqQueue *queue);
//����
void Pop(SeqQueue *queue, void *data);
//���ض�βԪ��
void *Bot_e(SeqQueue *queue);
//�ж��Ƿ�Ϊ��
int IsEmpty(SeqQueue *queue);
//���ض���Ԫ�ظ���
int Size(SeqQueue *queue);
//����
void Free(SeqQueue *queue);