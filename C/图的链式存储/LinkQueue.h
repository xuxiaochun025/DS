#pragma once

typedef struct LinkNode1 {
	int data;
	struct LinkNode1 *next;
}LinkNode1;

typedef struct LinkQueue {
	LinkNode1 *head;//ͷָ��
	LinkNode1 *rear;//βָ��
	int size;
}LinkQueue;

//��ʼ��
LinkQueue *Init1();
//���
void Push1(LinkQueue *queue, int data);
//���ض�ͷԪ��
int Top_e1(LinkQueue *queue);
//����
void Pop1(LinkQueue *queue, int data);
//���ض�βԪ��
int Bot_e1(LinkQueue *queue);
//�ж��Ƿ�Ϊ��
int IsEmpty1(LinkQueue *queue);
//���ض���Ԫ�ظ���
int Size1(LinkQueue *queue);
//����
void Free1(LinkQueue *queue);