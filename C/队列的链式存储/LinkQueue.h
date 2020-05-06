#pragma once

typedef struct LinkNode {
	void *data;
	struct LinkNode *next;
}LinkNode;

typedef struct LinkQueue {
	LinkNode *head;//ͷָ��
	LinkNode *rear;//βָ��
	int size;
}LinkQueue;

//��ʼ��
LinkQueue *Init();
//���
void Push(LinkQueue *queue, void *data);
//���ض�ͷԪ��
void * Top_e(LinkQueue *queue);
//����
void Pop(LinkQueue *queue, void * data);
//���ض�βԪ��
void * Bot_e(LinkQueue *queue);
//�ж��Ƿ�Ϊ��
int IsEmpty(LinkQueue *queue);
//���ض���Ԫ�ظ���
int Size(LinkQueue *queue);
//����
void Free(LinkQueue *queue);