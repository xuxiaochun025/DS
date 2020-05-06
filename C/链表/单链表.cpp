#include<stdio.h>
#include<stdlib.h>
#include"Link.h"

//初始化
LinkList *Init_LinkList()
{
	LinkList *list = (LinkList *)malloc(sizeof(LinkList));
	list->pHeader = (LinkNode *)malloc(sizeof(LinkNode));//list是head的地址
	list->pHeader->data = NULL;
	list->pHeader->next = NULL;
	list->m_Size = 0;
	
	return list;
}
//插入
void Insert(LinkList *list, int pos, void *data)
{
	if (list == NULL) {
		return;
	}
	if (pos<1 || pos>list->m_Size) {
		pos = list->m_Size + 1;
	}
	LinkNode *p = list->pHeader;
	for (int i = 1; i < pos; i++) {
		p = p->next;
	}
	LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));
	newNode->data = data;
	newNode->next = p->next;
	p->next = newNode;
	list->m_Size++;
}
//删除
void Del(LinkList *list, int pos)
{
	if (list == NULL)
	{
		return;
	}
	if (pos<1 || pos>list->m_Size) {
		printf("position error!\n");
	}
	LinkNode *p = list->pHeader;
	for (int i = 1; i < pos; i++) {
		p = p->next;
	}
	LinkNode *q = p->next;
	p->next = q->next;
	free(q);
	list->m_Size--;
}
//查找
void Find(LinkList *list, void *data, compare find)//用函数指针的原因：具体什么数据，怎么比较或打印，
{                                                  //取决于在测试阶段用户自己定义的数据类型，此处是
	if (list == NULL) {                            //为了定义一个通用的链表
		return;
	}
	LinkNode *p = list->pHeader->next;
	int isFound = 0;
	while (p!=NULL) {
		if (find(p->data,data)) {
			isFound = 1;
			break;
		}
		p = p->next;
	}
	if (isFound == 0) {
		printf("Not Find.\n");
	}
	else {
		printf("Find.\n");
	}
}
//打印
void Print_List(LinkList *list, void (*print)(void *))//函数指针作形参
{
	if (list == NULL) {
		return;
	}
	LinkNode *p = list->pHeader->next;
	while (p != NULL) {
		print(p->data);
		p = p->next;
	}
}
//长度
int Length(LinkList *list)
{
	if (list == NULL) {
		return 0;
	}
	else {
		return list->m_Size;
	}
}
//释放
void Free(LinkList *list)
{
	if (list == NULL) {
		return;
	}
	LinkNode *p = list->pHeader;
	LinkNode *q = NULL;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	/*free(list->pHeader);
	list->pHeader = NULL;*/
	list->m_Size = 0;
}

void change(LinkList *list,int pos, void *data)
{
	if (list == NULL) {
		return;
	}
	LinkNode *p = list->pHeader->next;
	for (int i = 1; i < pos; i++) {
		p = p->next;
	}
	p->data = data;
}