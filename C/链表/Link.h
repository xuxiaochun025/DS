#pragma once
//链表结点结构体
typedef struct LinkNode {
	void *data;//void* 保存任意类型的地址(用数据的地址来访问数据)
	struct LinkNode *next;
}LinkNode;

//链表结构体
typedef struct LinkList {
	LinkNode *pHeader;//头结点，是结点的地址
	int m_Size;//根据所需申请内存
}LinkList;

//typedef void (*printlinknode)(void *);//任意数据类型的函数指针
typedef bool (*compare)(void *,void *);

//初始化
LinkList *Init_LinkList();
//插入
void Insert(LinkList *list, int pos, void *data);
//删除
void Del(LinkList *list, int pos);
//查找
void Find(LinkList *list, void *data,compare find);
//打印
void Print_List(LinkList *list,void (*print)(void *));
//长度
int Length(LinkList *list);
//释放
void Free(LinkList *list);

void change(LinkList *list, int pos, void *data);
