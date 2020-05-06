#pragma once
//������ṹ��
typedef struct LinkNode {
	void *data;//void* �����������͵ĵ�ַ(�����ݵĵ�ַ����������)
	struct LinkNode *next;
}LinkNode;

//����ṹ��
typedef struct LinkList {
	LinkNode *pHeader;//ͷ��㣬�ǽ��ĵ�ַ
	int m_Size;//�������������ڴ�
}LinkList;

//typedef void (*printlinknode)(void *);//�����������͵ĺ���ָ��
typedef bool (*compare)(void *,void *);

//��ʼ��
LinkList *Init_LinkList();
//����
void Insert(LinkList *list, int pos, void *data);
//ɾ��
void Del(LinkList *list, int pos);
//����
void Find(LinkList *list, void *data,compare find);
//��ӡ
void Print_List(LinkList *list,void (*print)(void *));
//����
int Length(LinkList *list);
//�ͷ�
void Free(LinkList *list);

void change(LinkList *list, int pos, void *data);
