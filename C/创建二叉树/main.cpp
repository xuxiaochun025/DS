#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"

//按先序遍历创建二叉树(带返回值)--(1)(2)区别于二重指针的地方
BiNode *createBiTree1(BiNode *root)
{
	char ch;
	scanf_s("%c", &ch,12);//树的结点一次全部输入，如果要一次一个的输入，在%c前加个空格
	if (ch == '#') {      //12表示输入宽度，可自定义
		root = NULL;
	}
	else {
		root = (BiNode *)malloc(sizeof(BiNode));
		root->data = ch;
		root->lchild = createBiTree1(root->lchild);//不能少，不然只能返回一个root的值---(1)
		root->rchild = createBiTree1(root->rchild);
	}
	return root;//----(2)
}

//按先序遍历创建二叉树(不带返回值，使用二重指针)
void createBiTree2(BiNode **root)//root是指针bt的地址，root=&bt
{
	char ch;
	scanf_s("%c", &ch, 12);
	if (ch == '#') {
		*root = NULL;
	}
	else {
		*root = (BiNode *)malloc(sizeof(BiNode));
		(*root)->data = ch;
		createBiTree2(&(*root)->lchild);
		createBiTree2(&(*root)->rchild);
	}
}

//先序和中序创建二叉树
void createBiTreemp(BiNode **root, char m[], int i1, int j1, char p[], int i2, int j2)
{
	int i = i1;
	if (i2 <= j2) {
		*root = (BiNode *)malloc(sizeof(BiNode));
		(*root)->data = p[i2];
		while (m[i] != p[i2]) {
			i++;
		}
		createBiTreemp(&(*root)->lchild, m, i1, i - 1, p, i2 + 1, i - i1 + i2);
		createBiTreemp(&(*root)->rchild, m, i + 1, j1, p, i - i1 + i2 + 1, j2);
	}
	else {
		*root = NULL;
	}
}

//后序和中序创建二叉树(带返回值)
BiNode *createBiTreemb(BiNode *root,char m[],int i1,int j1,char b[],int i2,int j2)
{
	int i = i1;
	if (i2<=j2)
	{
		root = (BiNode *)malloc(sizeof(BiNode));
		root->data = b[j2];
		while (m[i] != b[j2]) {
			i++;
		}
		root->lchild = createBiTreemb(root->lchild, m, i1, i - 1, b, i2, i2 + i - i1 - 1);
		root->rchild = createBiTreemb(root->rchild, m, i + 1, j1, b, i2 + i - i1, j2 - 1);
	}
	else {
		root = NULL;
	}
	return root;
}

//后序和中序创建二叉树(不带返回值)
void createBiTreemb1(BiNode **root, char m[], int i1, int j1, char b[], int i2, int j2)
{
	//i不能从0开始遍历
	int i = i1;//用来在中序中定位根节点，所以初始值应为中序的起始位置，递归时也相应的为中序左右孩子的起始位置
	if (i2 <= j2)
	{
		*root = (BiNode *)malloc(sizeof(BiNode));
		(*root)->data = b[j2];
		while (m[i] != b[j2]) {
			i++;
		}
		createBiTreemb1(&(*root)->lchild, m, i1, i - 1, b, i2, i2 + i - i1 - 1);
		createBiTreemb1(&(*root)->rchild, m, i + 1, j1, b, i2 + i - i1, j2 - 1);
	}
	else {
		*root = NULL;
	}
}

void Recursionp(BiNode *root)
{
	if (root == NULL) {
		return;
	}
	printf("%c ", root->data);
	Recursionp(root->lchild);
	Recursionp(root->rchild);
}

void Recursionm(BiNode *root)
{
	if (root == NULL) {
		return;
	}
	Recursionm(root->lchild);
	printf("%c ", root->data);
	Recursionm(root->rchild);
}

void Recursionb(BiNode *root)
{
	if (root == NULL) {
		return;
	}
	Recursionb(root->lchild);
	Recursionb(root->rchild);
	printf("%c ", root->data);
}

int main()
{
	/*BiNode *bt = NULL;
	bt = createBiTree1(bt);
	Recursionm(bt);*/
	//BiNode *bt1 = NULL;//二重指针用法
	//createBiTree2(&bt1);
	//Recursionm(bt1);
	//printf("\n");
	char p[] = { 'A','B','C','D','E' };
	char m[] = { 'B','C','A','E','D' };
	char b[] = { 'C','B','E','D','A' };
	//BiNode *bt2 = NULL;
	//bt2 = createBiTreemb(bt2, m, 0, 4, b, 0, 4);
	//Recursionp(bt2);
	//BiNode *bt3 = NULL;//二重指针
	//createBiTreemb1(&bt3, m, 0, 4, b, 0, 4);
	//Recursionp(bt3);
	BiNode *bt4 = NULL;//二重指针
	createBiTreemp(&bt4, m, 0, 4, p, 0, 4);
	Recursionb(bt4);
	return 0;
}