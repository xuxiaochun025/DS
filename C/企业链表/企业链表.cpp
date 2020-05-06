#include<stdio.h>
#include<stdlib.h>
#include"InList.h"

//��ʼ��
LinkList *Init_LinkList()
{
	LinkList *list = (LinkList *)malloc(sizeof(LinkList));//ָ�������̬�����ڴ�
	list->head.next = NULL;//listָ�������->,head�ṹ�������.
	list->size = 0;

	return list;
}
//����
void Insert(LinkList *list, int pos, LinkNode *data)
{
	if (list == NULL)
	{
		return;
	}
	if (pos<1 || pos>list->size) {
		pos = list->size + 1;
	}
	LinkNode *p = &(list->head);
	for (int i = 1; i < pos; i++) {
		p = p->next;
	}
	data->next = p->next;
	p->next = data;
	list->size++;
}
//ɾ��
void Del(LinkList *list, int pos)
{
	if (list == NULL) {
		return;
	}
	if (pos<1 || pos>list->size) {
		printf("position error!");
	}
	LinkNode *p = &(list->head);
	for (int i = 1; i < pos; i++) {
		p = p->next;
	}
	//LinkNode *q = p->next;
	//p->next = q->next;
	//free(q); ��û�����붯̬�ڴ���䣬���Բ���Ҫ�ͷ�
	p->next = p->next->next;
	list->size--;
}
//����
void Find(LinkList *list, LinkNode *data,Compare find) {
	if (list == NULL)
	{
		return;
	}
	LinkNode *p = list->head.next;
	int isFound = 0;
	while (p != NULL) {
		if (find(data,p)) {
			isFound = 1;
			break;
		}
		p = p->next;
	}
	if (isFound == 0) {
		printf("Not Find\n");
	}
	else {
		printf("Find\n");
	}
}
//���ش�С
int Size(LinkList *list)
{
	if (list == NULL)
	{
		return NULL;
	}
	return list->size;
}
//��ӡ
void Print_List(LinkList *list, PrintNode print)
{
	if (list == NULL) {
		return;
	}
	LinkNode *p = list->head.next;
	while (p != NULL) {
		print(p);
		p = p->next;
	}
}
//�ͷ�
void Free(LinkList *list) 
{
	if (list == NULL) {
		return;
	}
	free(list);//����list�����˶�̬�ڴ����
	list->size = 0;
}
