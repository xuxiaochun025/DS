#pragma once

typedef struct LinkNode {
	void *data;
	struct LinkNode *next;
}LinkNode;

typedef struct LinkStack {
	LinkNode *head;
	int size;
}LinkStack;

//��ʼ��
LinkStack *Init();
//��ջ
void Push(LinkStack *stack, void *data);
//����ջ��Ԫ��
void *Top_e(LinkStack *stack);
//��ջ
void Pop(LinkStack *stack, void *data);
//�ж��Ƿ�Ϊ��
int IsEmpty(LinkStack *stack);
//����ջ��Ԫ�ظ���
int Size(LinkStack *stack);
//����
void Free(LinkStack *stack);


typedef struct LinkQueue {
	LinkNode *head;//ͷָ��
	LinkNode *rear;//βָ��
	int size;
}LinkQueue;

//��ʼ��
LinkQueue *Init1();
//���
void Push(LinkQueue *queue, void *data);
//���ض�ͷԪ��
void *Top_e(LinkQueue *queue);
//����
void Pop(LinkQueue *queue, void *data);
//���ض�βԪ��
void *Bot_e(LinkQueue *queue);
//�ж��Ƿ�Ϊ��
int IsEmpty(LinkQueue *queue);
//���ض���Ԫ�ظ���
int Size(LinkQueue *queue);
//����
void Free(LinkQueue *queue);