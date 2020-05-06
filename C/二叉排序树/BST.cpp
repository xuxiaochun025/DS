#include<stdio.h>
#include<stdlib.h>
#include"BST.h"

BiNode *Find(BiNode *root, int x)//�ݹ��㷨
{
	if (root == NULL) {
		return NULL;
	}
	if (root->data < x) {
		return Find(root->rchild, x);
	}
	else if (root->data > x) {
		return Find(root->lchild, x);
	}
	else {
		return root;
	}
}

BiNode *nrFind(BiNode *root, int x)//�ǵݹ��㷨
{
	while (root) {
		if (root->data < x) {
			root = root->rchild;
		}
		else if (root->data > x) {
			root = root->lchild;
		}
		else {
			break;
		}
	}
	return root;//����root��NULL
}

BiNode *FindMax(BiNode *root)//�ݹ��㷨
{
	if (root == NULL) {
		return NULL;
	}
	if (!root->rchild) {
		return root;
	}
	else {
		return FindMax(root->rchild);
	}
}

BiNode *nrFindMax(BiNode *root)//�ǵݹ��㷨
{
	while (root->rchild) {
		root = root->rchild;
	}
	return root;
}

BiNode *FindMin(BiNode *root)
{
	if (root == NULL) {
		return NULL;
	}
	if (!root->lchild) {
		return root;
	}
	else {
		return FindMin(root->lchild);
	}
}

void Insert(BiNode **root, int x)//�ݹ��㷨
{
	if (*root == NULL) {
		*root = (BiNode *)malloc(sizeof(BiNode));
		(*root)->data = x;
		(*root)->lchild = NULL;
		(*root)->rchild = NULL;
	}
	else {
		if ((*root)->data < x) {
			Insert(&(*root)->rchild, x);
		}
		else {
			Insert(&(*root)->lchild, x);
		}
	}
}

void nrInsert(BiNode **root, int x)//�ǵݹ��㷨
{
	if (*root == NULL) {
		(*root) = (BiNode *)malloc(sizeof(BiNode));
		(*root)->data = x;
		(*root)->lchild = NULL;
		(*root)->rchild = NULL;
	}
	else {
		BiNode *parent = NULL;
		BiNode *p = (*root);//������(*root)������
		while (p) {//���ҵ�Ҫ����ڵ�λ�õĸ��ڵ�
			if (p->data < x) {
				parent = p;
				p = p->rchild;
			}
			else if (p->data > x) {
				parent = p;
				p = p->lchild;
			}
			else {
				break;
			}
		}
		if (parent->data < x) {
			BiNode *newNode = (BiNode *)malloc(sizeof(BiNode));
			newNode->data = x;
			newNode->lchild = NULL;
			newNode->rchild = NULL;
			parent->rchild = newNode;
		}
		if (parent->data > x) {
			BiNode *newNode = (BiNode *)malloc(sizeof(BiNode));
			newNode->data = x;
			newNode->lchild = NULL;
			newNode->rchild = NULL;
			parent->lchild = newNode;
		}
	}
}

//Ҫɾ������Ҷ��㣺ֱ��ɾ���������޸��丸���ָ����ΪNULL
//Ҫɾ���Ľ��ֻ��һ�����ӽ��::���丸����ָ��ָ��Ҫɾ�����ĺ��ӽ��
//Ҫɾ���Ľ����������������:����һ��������ɾ����㣺����������СԪ�� ���� �����������Ԫ��
void Delval(BiNode **root, int x)//�ݹ��㷨
{
	BiNode *p = NULL;
	if (root == NULL) {
		printf("error\n");
	}
	else {
		if (x < (*root)->data) {
			Delval(&(*root)->lchild, x);
		}
		else if (x > (*root)->data) {
			Delval(&(*root)->rchild, x);
		}
		else {//x==(*root)->data
			if ((*root)->lchild && (*root)->rchild) {
				//�����������Ԫ��
				p = FindMax((*root)->lchild);//p�ض�����ֻ��һ������
				(*root)->data = p->data;//��һ�����ѱ�ɾ����ֵ�滻��
				Delval(&(*root)->lchild, p->data);//�ڶ��������ý��ֻ��һ�����ӵ������ɾ��������ɾ����ǰ�ҵ����滻���
			}
			else {
				p = (*root);
				if (!(*root)->lchild) {//��ʱ�������&(*root)->lchild
					(*root) = (*root)->rchild;//ȡ����ǰ��ɾ���,�Ḳ��ԭ������ֵ
				}
				else {
					(*root) = (*root)->lchild;
				}
				free(p);
			}
		}
	}
}

void nrDelval(BiNode **root, int x)//�ǵݹ��㷨
{
	if (*root == NULL) {
		return;
	}
	BiNode *dnode = NULL;
	BiNode *p = *root;
	BiNode *parent = NULL;
	//�ҵ���ɾ���
	while (p) {
		if (p->data < x) {
			parent = p;
			p = p->rchild;
		}
		else if (p->data > x) {
			parent = p;
			p = p->lchild;
		}
		else {
			break;
		}
	}
	//ɾ����ɾ���
	if (p == NULL) {
		return;
	}
	//������,���Һ���
	if (p->lchild&&p->rchild) {
		BiNode *pd = p->rchild;//�������е���Сֵ
		//parent = p;//��Ҫ-->205
		//while (pd->lchild) {
		//	parent = pd;
		//	pd = pd->lchild;
		//}
		//p->data = pd->data;
		//if (pd == parent->lchild) {
		//	parent->lchild = pd->rchild;
		//}
		//else if (pd == parent->rchild) {
		//	parent->rchild = pd->rchild;
		//}
		while (pd->lchild) {
			parent = pd;
			pd = pd->lchild;
		}
		p->data = pd->data;
		if (parent == NULL) {
			p->rchild = pd->rchild;
		}
		else {
			if (pd == parent->lchild) {
				parent->lchild = pd->rchild;
			}
			else {
				p->rchild = pd->rchild;
			}
		}
		free(pd);
	}
	else {
		dnode = p;
		if (!p->lchild) {
			if (p == (*root)) {//ɾ�������ܸ��ڵ�,parent==NULL,��������
				(*root) = p->rchild;//����
			}
			else {
				if (p == parent->lchild) {//ɾ�����Ǹ��ڵ������
					parent->lchild = p->rchild;
				}
				else {//ɾ�����Ǹ��ڵ���Һ���
					parent->rchild = p->rchild;
				}
			}
		}
		else {
			if (p == (*root)) {
				(*root) = p->lchild;
			}
			else if (p == parent->lchild) {
				parent->lchild = p->lchild;
			}
			else {
				parent->rchild = p->lchild;
			}
		}
		free(dnode);
	}
}

void Inorder(BiNode *root)
{
	if (root == NULL) {
		return;
	}
	Inorder(root->lchild);
	printf("%d ", root->data);
	Inorder(root->rchild);
}

int main()
{
	int data[] = {18,20,22};
	//int data[] = {7,9,10,15,18,20,22 };
	BiNode *bt = NULL;
	for (int i = 0; i < 3; i++) {
		nrInsert(&bt, data[i]);
	}
	Inorder(bt);
	//printf("\n"); 
	//BiNode *p = nrFind(bt, 3);
	//printf("%d ", p->data);
	//BiNode *p = FindMin(bt);
	//printf("%d ", p->data);
	//printf("\n");
	//Delval(&bt, 10);
	//Inorder(bt);
	printf("\n");
	nrDelval(&bt, 18);
	Inorder(bt);
	return 0;
}