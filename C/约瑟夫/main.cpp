#include<stdio.h>
#include"ysf.h"

int main()
{
	cLinkList *list = Init();
	for (int i = 1; i <= 8; i++) {
		Insert(list, i, i);
	}
	PrintList(list);
	printf("\n");
	//printf("%d\n", list->size);
	int index = 1;//��1�ſ�ʼ��8�Ž���
	cLinkNode *p = list->head->next;
	cLinkNode *q = NULL;
	while (list->size > 1) {
		if (index == 3) {
			printf("%d ", p->data);
			q = p->next;
			Delvalue(list, p->data);
			p = q;
			if (p == list->head) {//ͷ�������
				p = p->next;
			}
			index = 1;
		}
		p = p->next;
		if (p == list->head) {//ͷ�������
			p = p->next;
		}
		index++;
	}
	if (list->size == 1) {
		printf("%d\n", p->data);
	}
	return 0;
}