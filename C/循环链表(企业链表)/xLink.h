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

//初始化
cLinkList *Init_List();
//插入
void Insert(cLinkList *list, int pos,cLinkNode *data);
//删除
void Del(cLinkList *list, int pos);
void Delvalue(cLinkList *list,cLinkNode *data,Compare compare);
//查找
void Search(cLinkList *list, cLinkNode *data, Compare compare);
//打印
void Print_List(cLinkList *list, Print print);
//释放
void Free(cLinkList *list);