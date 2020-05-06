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

//初始化
cLinkList *Init();
//插入
void Insert(cLinkList *list, int pos, void *data);
//删除
void Delvalue(cLinkList *list, void *data, Compare compare);
//查找
void Search(cLinkList *list, void *data, Compare compare);
//打印
void PrintList(cLinkList *list, Print print);
//释放
void Free(cLinkList *list);