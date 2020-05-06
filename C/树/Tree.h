#pragma once

typedef struct BiNode {
	char ch;
	struct BiNode *lchild;
	struct BiNode *rchild;
}BiNode;

void CreateTree();
void Recursion(BiNode *);
void calLeaf(BiNode *,int *);
int height(BiNode *);
BiNode *CBTree(BiNode *);
void Free(BiNode *);