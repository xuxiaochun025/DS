#pragma once

typedef struct LinkNode {
	char data;
	struct LinkNode *next;
}LinkNode;

typedef struct LinkStack {
	LinkNode *head;
	int size;
}LinkStack;

//��ʼ��
LinkStack *Init();
//��ջ
void Push(LinkStack *stack, char data);
//����ջ��Ԫ��
char Top_e(LinkStack *stack);
//��ջ
void Pop(LinkStack *stack, char data);
//�ж��Ƿ�Ϊ��
int IsEmpty(LinkStack *stack);
//����ջ��Ԫ�ظ���
int Size(LinkStack *stack);
//����
void Free(LinkStack *stack);