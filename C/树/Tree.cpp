#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"

//     A
//  B      F
//     C      G
//   D   E  H
void CreateTree()
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

	Recursion(&node1);
	int leafnum = 0;
	calLeaf(&node1,&leafnum);
	printf("\n");
	printf("%d", leafnum);
	printf("\n");
	printf("%d",height(&node1));
	printf("\n");
	BiNode *root1 = CBTree(&node1);
	Recursion(root1);
	printf("\n");
	Free(root1);
	//Recursion(root1);
}

void Recursion(BiNode *root)
{
	if (root == NULL) {
		return;
	}
	//ÏÈÐò±éÀú
	printf("%c ", root->ch);
	Recursion(root->lchild);
	Recursion(root->rchild);
}

void calLeaf(BiNode *root,int *num)
{
	if (root == NULL) {
		return;
	}
	if (root->lchild == NULL && root->rchild == NULL) {
		(*num)++;
	}
	calLeaf(root->lchild,num);
	calLeaf(root->rchild,num);
}

int height(BiNode *root)
{
	if (root == NULL) {
		return 0;
	}
	int lh=height(root->lchild);
	int rh=height(root->rchild);
	return lh > rh ? lh + 1 : rh + 1;
}

BiNode *CBTree(BiNode *root)//¸´ÖÆ
{
	if (root == NULL) {
		return NULL;
	}
	BiNode *newNode = (BiNode *)malloc(sizeof(BiNode));
	newNode->ch = root->ch;
	newNode->lchild =CBTree(root->lchild);
	newNode->rchild =CBTree(root->rchild);
	return newNode;
}

void Free(BiNode *root)
{
	if (root == NULL) {
		return;
	}
	Free(root->lchild);
	Free(root->rchild);
	free(root);
}