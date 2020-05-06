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