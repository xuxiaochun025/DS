#pragma once

typedef struct cLinkNode {
	int data;
	struct cLinkNode *next;
}cLinkNode;

typedef struct cLinkList {
	cLinkNode *head;
	int size;
}cLinkList;

//��ʼ��
cLinkList *Init();
//����
void Insert(cLinkList *list, int pos, int data);
//ɾ��
void Delvalue(cLinkList *list, int data);
//����
void Search(cLinkList *list, int data);
//��ӡ
void PrintList(cLinkList *list);
//�ͷ�
void Free(cLinkList *list); 
