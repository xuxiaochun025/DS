#include<stdio.h>
#include<stdlib.h>
#include"cLink.h"

//初始化
cLinkList *Init()
{
	cLinkList *list = (cLinkList *)malloc(sizeof(cLinkList));
	list->head = (cLinkNode *)malloc(sizeof(cLinkNode));
	list->head->data = NULL;
	list->head->next = list->head;
	list->size = 0;
	return list;
}
//插入
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
	cLinkNode *newNode = (cLinkNode *)malloc(sizeof(cLinkNode));
	newNode->data = data;
	newNode->next = p->next;
	p->next = newNode;
	list->size++;
}
//删除
void Delvalue(cLinkList *list, void *data, Compare compare)
{
	if (list == NULL) {
		return;
	}
	cLinkNode *q = list->head;
	cLinkNode *p = list->head->next;
	while (p != list->head) {
		if (compare(p->data, data)) {
			q->next = p->next;
			free(p);
			break;
		}
		else {
			q = p;
			p = p->next;
		}
	}
	if (p == list->head) {
		printf("No data,can't delete.\n");
	}
	else {
		printf("Delete success.\n");
		list->size--;
	}
}
//查找
void Search(cLinkList *list, void *data, Compare compare)
{
	if (list == NULL) {
		return;
	}
	cLinkNode *p = list->head->next;
	int isFound = 0;
	while (p != list->head) {
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
//打印
void PrintList(cLinkList *list, Print print)
{
	if (list == NULL) {
		return;
	}
	cLinkNode *p = list->head->next;
	while (p != list->head) {
		print(p->data);
		p = p->next;
	}
}
//释放
void Free(cLinkList *list)
{
	if (list == NULL) {
		return;
	}
	cLinkNode *p = list->head->next;
	cLinkNode *q = list->head;
	while (p!=list->head) {
		q = p;
		p = p->next;
		free(q);
	}
	list->size = 0;
}
