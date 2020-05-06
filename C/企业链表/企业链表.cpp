#include<stdio.h>
#include<stdlib.h>
#include"InList.h"

//初始化
LinkList *Init_LinkList()
{
	LinkList *list = (LinkList *)malloc(sizeof(LinkList));//指针变量动态分配内存
	list->head.next = NULL;//list指针访问用->,head结构体访问用.
	list->size = 0;

	return list;
}
//插入
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
//删除
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
	//free(q); 并没有申请动态内存分配，所以不需要释放
	p->next = p->next->next;
	list->size--;
}
//查找
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
//返回大小
int Size(LinkList *list)
{
	if (list == NULL)
	{
		return NULL;
	}
	return list->size;
}
//打印
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
//释放
void Free(LinkList *list) 
{
	if (list == NULL) {
		return;
	}
	free(list);//仅有list申请了动态内存分配
	list->size = 0;
}
