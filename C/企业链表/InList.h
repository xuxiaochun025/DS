#pragma once

//企业链表
//LinkNode *node -----> LinkNode head -----> LinkNode node  把LinkNode类型结点用LinkNode *next串起来，
//                      char name[25]        char name[25]  所以数据类型应为LinkNode *data(用数据的地址来访问数据)
//                      int age              int age

//链表小结点
typedef struct LinkNode {
	struct LinkNode *next;//丢掉数据域
}LinkNode;

//链表结点
typedef struct LinkList {
	LinkNode head;//直接使用LinkNode类型结点，不需要指向它的指针
	int size;
}LinkList;

typedef void (*PrintNode)(LinkNode *);
typedef int (*Compare)(LinkNode *,LinkNode *);

//初始化
LinkList *Init_LinkList();
//插入
void Insert(LinkList *list, int pos, LinkNode *data);
//删除
void Del(LinkList *list, int pos);
//查找
void Find(LinkList *list, LinkNode *data,Compare find);
//返回大小
int Size(LinkList *list);
//打印
void Print_List(LinkList *list, PrintNode print);
//释放
void Free(LinkList *list);