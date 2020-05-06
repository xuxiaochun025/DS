#pragma once
#pragma once

typedef struct cLinkNode {
	void *data;
	struct cLinkNode *pre;
	struct cLinkNode *next;
}cLinkNode;

typedef struct cLinkList {
	cLinkNode *head;
	int size;
}cLinkList;
typedef int(*Compare)(void *data1, void *data2);
typedef void(*Print)(void *data);

//��ʼ��
cLinkList *Init();
//����
void Insert(cLinkList *list, int pos, void *data);
//ɾ��
void Delvalue(cLinkList *list, void *data, Compare compare);
//����
void Search(cLinkList *list, void *data, Compare compare);
//��ӡ
void PrintList(cLinkList *list, Print print);
//�ͷ�
void Free(cLinkList *list);