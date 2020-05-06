#pragma once

typedef struct cLinkNode {
	struct cLinkNode *next;
}cLinkNode;

typedef struct cLinkList {
	cLinkNode head;
	int size;
}cLinkList;

typedef int (*Compare)(cLinkNode *data1, cLinkNode *data2);
typedef void(*Print)(cLinkNode *data);

//��ʼ��
cLinkList *Init_List();
//����
void Insert(cLinkList *list, int pos,cLinkNode *data);
//ɾ��
void Del(cLinkList *list, int pos);
void Delvalue(cLinkList *list,cLinkNode *data,Compare compare);
//����
void Search(cLinkList *list, cLinkNode *data, Compare compare);
//��ӡ
void Print_List(cLinkList *list, Print print);
//�ͷ�
void Free(cLinkList *list);