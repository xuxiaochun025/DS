#pragma once

//��ҵ����
//LinkNode *node -----> LinkNode head -----> LinkNode node  ��LinkNode���ͽ����LinkNode *next��������
//                      char name[25]        char name[25]  ������������ӦΪLinkNode *data(�����ݵĵ�ַ����������)
//                      int age              int age

//����С���
typedef struct LinkNode {
	struct LinkNode *next;//����������
}LinkNode;

//������
typedef struct LinkList {
	LinkNode head;//ֱ��ʹ��LinkNode���ͽ�㣬����Ҫָ������ָ��
	int size;
}LinkList;

typedef void (*PrintNode)(LinkNode *);
typedef int (*Compare)(LinkNode *,LinkNode *);

//��ʼ��
LinkList *Init_LinkList();
//����
void Insert(LinkList *list, int pos, LinkNode *data);
//ɾ��
void Del(LinkList *list, int pos);
//����
void Find(LinkList *list, LinkNode *data,Compare find);
//���ش�С
int Size(LinkList *list);
//��ӡ
void Print_List(LinkList *list, PrintNode print);
//�ͷ�
void Free(LinkList *list);