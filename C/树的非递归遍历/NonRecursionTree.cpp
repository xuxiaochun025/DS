#include<stdio.h>
#include<stdlib.h>
#include"LinkStack.h"

typedef struct BiNode {
	char ch;
	struct BiNode *lchild;
	struct BiNode *rchild;
}BiNode;

//����ǵݹ���� LDR
void mNonRecursion(BiNode *root)
{
	if (root == NULL) {
		return;
	}
	LinkStack *stack = Init();
	BiNode *p = root;
	while (p || IsEmpty(stack)) {
		while (p) {
			Push(stack, p);
			p = p->lchild;
		}
		if (IsEmpty(stack)) {
			p = (BiNode *)Top_e(stack);
			printf("%c ", p->ch);
			Pop(stack, p);
			p = p->rchild;
		}
	}
}

//����ǵݹ���� DLR
void pNonRecursion(BiNode *root)
{
	if (root == NULL) {
		return;
	}
	LinkStack *stack = Init();
	BiNode *p = root;
	while (p||IsEmpty(stack)) {
		while (p) {
			printf("%c ", p->ch);
			Push(stack, p);
			p = p->lchild;
		}
		if (IsEmpty(stack)) {
			p = (BiNode *)Top_e(stack);
			Pop(stack, p);
			p = p->rchild;
		}
	}
}

//����ǵݹ���� LRD
void bNonRecursion(BiNode *root)
{
	if (root == NULL) {
		return;
	}
	LinkStack *stack = Init();
	BiNode *p = root;
	BiNode *r = NULL;//���ʱ��
	while (p||IsEmpty(stack)) {
		while (p) {
			Push(stack, p);
			p = p->lchild;
		}
		p = (BiNode *)Top_e(stack);//��һ�ε���ջ��Ԫ��(���ڵ�)���ж���û��������
		if (p->rchild&&p->rchild!=r) {//һ�����ڵ㱻���ʵ�ǰ���ǣ����������������������ѱ����ʹ�
			p = p->rchild;
		}
		else {
			p = (BiNode *)Top_e(stack);
			printf("%c ", p->ch);
			Pop(stack, p);
			r = p;   //rָ���Ѿ����ʹ��Ľ��
			p = NULL;//��pת��69�У����·���ջ��
		}
	}
}

//��α��� 
void level(BiNode *root)
{
	if (root == NULL) {
		return;
	}
	LinkQueue *queue = Init1();
	BiNode *p = root;
	Push(queue, p);
	while (IsEmpty(queue)) {
		p = (BiNode *)Top_e(queue);
		printf("%c ", p->ch);
		Pop(queue, p);
		if (p->lchild) {
			Push(queue, p->lchild);
		}
		if (p->rchild) {
			Push(queue, p->rchild);
		}
	}
}

//     A
//  B      F
//     C      G    m:BDCEAFHG
//   D   E  H      b:DECBHGFA
void createTree()
{
	BiNode node1 = { 'A',NULL,NULL };
	BiNode node2 = { 'B',NULL,NULL };
	BiNode node3 = { 'C',NULL,NULL };
	BiNode node4 = { 'D',NULL,NULL };
	BiNode node5 = { 'E',NULL,NULL };
	BiNode node6 = { 'F',NULL,NULL };
	BiNode node7 = { 'G',NULL,NULL };
	BiNode node8 = { 'H',NULL,NULL };

	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;

	mNonRecursion(&node1);
	printf("\n");
	pNonRecursion(&node1);
	printf("\n");
	bNonRecursion(&node1);
	printf("\n");
	level(&node1);
}

int main()
{
	createTree();
	return 0;
}