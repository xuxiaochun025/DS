#include<stdio.h>
#include<stdlib.h>
#include"ccLink.h"

//��ʼ��
cLinkList *Init()
{
	cLinkList *list = (cLinkList *)malloc(sizeof(cLinkList));
	list->size = 0;
	list->head = (cLinkNode *)malloc(sizeof(cLinkNode));
	list->head->data = NULL;
	list->head->pre = NULL;
	list->head->next = NULL;
	return list;
}
//����
void Insert(cLinkList *list, int pos, void *data)
{
	if (list == NULL) {
		return;
	}
	if (pos<1 || pos>list->size) {
		pos = list->size + 1;
	}
	cLinkNode *p = list->head;
	for (int i = 1; i < pos; i++) {
		p = p->next;
	}
	if (p->next == NULL) {
		cLinkNode *newNode = (cLinkNode *)malloc(sizeof(cLinkNode));
		newNode->data = data;
		newNode->pre = p;
		p->next = newNode;
		newNode->next = NULL;
	}
	else {
		cLinkNode *newNode = (cLinkNode *)malloc(sizeof(cLinkNode));
		newNode->data = data;
		newNode->pre = p;//˳��Ψһ���Լ�ע�⼴��
		p->next->pre = newNode;
		newNode->next = p->next;
		p->next = newNode;
	}
	list->size++;
}
//ɾ��
void Delvalue(cLinkList *list, void *data, Compare compare)
{
	if (list == NULL) {
		return;
	}
	cLinkNode *p = list->head->next;
	while (p != NULL) {
		if (compare(p->data, data)) {
			if (p->next == NULL) {
				p->pre->next = NULL;
			}
			else {
				p->pre->next = p->next;
				p->next->pre = p->pre;
			}
			free(p);
			break;
		}
		p = p->next;
	}
	if (p == NULL) {
		printf("Delete fail.\n");
	}
	else {
		printf("Delete success.\n");
		list->size--;
	}
}
//����
void Search(cLinkList *list, void *data, Compare compare)
{
	if (list == NULL) {
		return;
	}
	cLinkNode *p = list->head->next;
	int isFound = 0;
	while (p != NULL) {
		if (compare(p->data, data)) {
			isFound = 1;
			break;
		}
		p = p->next;
	}
	if (isFound == 0) {
		printf("Search fail.\n");
	}
	else {
		printf("Search success.\n");
	}
}
//��ӡ
void PrintList(cLinkList *list, Print print)
{
	if (list == NULL) {
		return;
	}
	cLinkNode *p = list->head;
	cLinkNode *q = NULL;
	while (p->next != NULL) {
   		p = p->next;
		print(p->data);
	}
	q = p;//�������
	while (q->pre != NULL) {//��һ������preָ��head�����Բ��ǿ�
		print(q->data);
		q = q->pre;
	}
	printf("%p\n", list->head);
	printf("%p\n", q);
}
//�ͷ�
void Free(cLinkList *list)
{
	if (list == NULL) {
		return;
	}
	cLinkNode *p = list->head;
	cLinkNode *q = NULL;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	list->size = 0;
}