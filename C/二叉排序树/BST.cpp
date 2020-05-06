#include<stdio.h>
#include<stdlib.h>
#include"BST.h"

BiNode *Find(BiNode *root, int x)//递归算法
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

BiNode *nrFind(BiNode *root, int x)//非递归算法
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
	return root;//返回root或NULL
}

BiNode *FindMax(BiNode *root)//递归算法
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

BiNode *nrFindMax(BiNode *root)//非递归算法
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

void Insert(BiNode **root, int x)//递归算法
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

void nrInsert(BiNode **root, int x)//非递归算法
{
	if (*root == NULL) {
		(*root) = (BiNode *)malloc(sizeof(BiNode));
		(*root)->data = x;
		(*root)->lchild = NULL;
		(*root)->rchild = NULL;
	}
	else {
		BiNode *parent = NULL;
		BiNode *p = (*root);//不能用(*root)来遍历
		while (p) {//先找到要插入节点位置的父节点
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

//要删除的是叶结点：直接删除，并再修改其父结点指针置为NULL
//要删除的结点只有一个孩子结点::将其父结点的指针指向要删除结点的孩子结点
//要删除的结点有左、右两棵子树:用另一结点替代被删除结点：右子树的最小元素 或者 左子树的最大元素
void Delval(BiNode **root, int x)//递归算法
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
				//找左子树最大元素
				p = FindMax((*root)->lchild);//p必定至多只有一个孩子
				(*root)->data = p->data;//第一步：把被删结点的值替换掉
				Delval(&(*root)->lchild, p->data);//第二步：调用结点只有一个孩子的情况的删除方法来删除当前找到的替换结点
			}
			else {
				p = (*root);
				if (!(*root)->lchild) {//此时传入的是&(*root)->lchild
					(*root) = (*root)->rchild;//取代当前被删结点,会覆盖原来结点的值
				}
				else {
					(*root) = (*root)->lchild;
				}
				free(p);
			}
		}
	}
}

void nrDelval(BiNode **root, int x)//非递归算法
{
	if (*root == NULL) {
		return;
	}
	BiNode *dnode = NULL;
	BiNode *p = *root;
	BiNode *parent = NULL;
	//找到被删结点
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
	//删除被删结点
	if (p == NULL) {
		return;
	}
	//有左孩子,有右孩子
	if (p->lchild&&p->rchild) {
		BiNode *pd = p->rchild;//右子树中的最小值
		//parent = p;//重要-->205
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
			if (p == (*root)) {//删除的是总根节点,parent==NULL,单独考虑
				(*root) = p->rchild;//覆盖
			}
			else {
				if (p == parent->lchild) {//删除的是父节点的左孩子
					parent->lchild = p->rchild;
				}
				else {//删除的是父节点的右孩子
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