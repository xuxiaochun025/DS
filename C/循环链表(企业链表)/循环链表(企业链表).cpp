#include<stdlib.h>
#include<stdio.h>
#include"xLink.h"

//初始化
cLinkList *Init_List()
{
	cLinkList *list = (cLinkList *)malloc(sizeof(cLinkList));
	list->head.next = &(list->head);//list->head是cLinkNode类型，
	list->size = 0;                 //list->head.next是cLinkNode *类型
	return list;
}
//插入
void Insert(cLinkList *list, int pos, cLinkNode *data)
{
	if (list == NULL) {
		return;
	}
	if (pos<0 || pos>list->size) {
		pos = list->size + 1;
	}
	cLinkNode *p=&(list->head);
	for (int i = 1; i < pos; i++) {
		p = p->next;
	}
	data->next = p->next;
	p->next = data;
	list->size++;
}
//删除
void Del(cLinkList *list, int pos)
{
	if (list == NULL) {
		return;
	}
	if (pos<1 || pos>list->size) {
		printf("position error\n");
	}
	cLinkNode *p=&(list->head);
	for (int i = 1; i < pos; i++) {
		p = p->next;
	}
	p->next = p->next->next;
	list->size--;
}
void Delvalue(cLinkList *list, cLinkNode *data, Compare compare)
{
	if (list == NULL) {
		return;
	}
	cLinkNode *p = list->head.next;
	//cLinkNode *q1 = NULL;//两种方法的指针
	cLinkNode *q2 = &(list->head);
	while (p != &(list->head)) {
		/*if (compare(p, data)) {
			if (q1 == NULL) {
				list->head.next = p->next;
			}
			else {
				q1->next = p->next;
			}
			break;
		}
		else {
			q1 = p;
			p = p->next;
		}*/
		if (compare(p, data)) {
			q2->next = p->next;
			break;
		}
		else {
			q2 = p;
			p = p->next;
		}
	}
	if (p == &(list->head)) {
		printf("Not Find,Can't Delete.\n");
	}
	else {
		printf("Delete success.\n");
		list->size--;
	}

}
//查找
void Search(cLinkList *list, cLinkNode *data, Compare compare)
{
	if (list == NULL) {
		return;
	}
	int isFound = 0;
	cLinkNode *p = list->head.next;
	while (p != &(list->head)) {
		if (compare(p, data)) {
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
//打印
void Print_List(cLinkList *list, Print print)
{
	if (list == NULL) {
		return;
	}
	cLinkNode *p = list->head.next;
	while (p != &(list->head)) {
		print(p);
		p = p->next;
	}
}
//释放
void Free(cLinkList *list)
{
	if (list == NULL) {
		return;
	}
	free(list);
	list->size = 0;
}