#pragma once

typedef struct cLinkNode {
	int data;
	struct cLinkNode *next;
}cLinkNode;

typedef struct cLinkList {
	cLinkNode *head;
	int size;
}cLinkList;

//初始化
cLinkList *Init();
//插入
void Insert(cLinkList *list, int pos, int data);
//删除
void Delvalue(cLinkList *list, int data);
//查找
void Search(cLinkList *list, int data);
//打印
void PrintList(cLinkList *list);
//释放
void Free(cLinkList *list); 
