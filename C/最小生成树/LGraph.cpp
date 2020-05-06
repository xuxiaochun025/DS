#include<stdio.h>
#include<stdlib.h>
#include"LGraph.h"

//邻接矩阵创建无向带权图
void CreateGraph(MGraph **graph)
{
	*graph = (MGraph *)malloc(sizeof(MGraph));
	printf("输入图的顶点数和边数:\n");
	scanf_s("%d %d", &((*graph)->v), &((*graph)->e));
	getchar();
	printf("输入%d个顶点:\n", (*graph)->v);
	for (int i = 0; i < (*graph)->v; i++) {
		scanf_s("%d", &((*graph)->vexs[i]));
		getchar();
	}
	for (int i = 0; i < (*graph)->v; i++) {
		printf("%d ", (*graph)->vexs[i]);
	}
	printf("\n");
	for (int i = 0; i < (*graph)->v; i++) {//初始化邻接矩阵
		for (int j = 0; j < (*graph)->v; j++) {
			(*graph)->arc[i][j] = INFINTE;
		}
	}
	ENode *E = (ENode *)malloc(sizeof(ENode));
	printf("输入边的信息:\n");
	for (int k = 0; k < (*graph)->e; k++) {
		scanf_s("%d %d %d", &(E->v1), &(E->v2), &(E->Weight));
		getchar();
		(*graph)->arc[E->v1][E->v2] = E->Weight;
		(*graph)->arc[E->v2][E->v1] = E->Weight;
	}
}

void Print(MGraph *G)
{
	for (int i = 0; i < G->v; i++) {
		printf("%d\n", G->vexs[i]);
	}
	printf("\n");
	for (int i = 0; i < G->v; i++) {
		printf("%8d", G->vexs[i]);
		for (int j = 0; j < G->v; j++) {
			printf("%8d", G->arc[i][j]);
		}
		printf("\n");
	}
}

int MinEdge(ShortEdge a, int n)
{
	int min = INFINTE;
	int	minj;
	for (int i = 1; i < n; i++) {
		if (a[i].lowcost < min&&a[i].lowcost != 0) {//已经加入集合U的点不计算
			min = a[i].lowcost;
			minj = i;
		}
	}
	return minj;
}

void Prim(MGraph *G)
{
	ShortEdge shortEdge;
	//以V0作为起点初始化
	for (int i = 1; i < G->v; i++) {
		shortEdge[i].adjvex = 0;
		shortEdge[i].lowcost = G->arc[i][0];
	}
	shortEdge[0].lowcost = 0;//把V0加入集合U
	int k;
	for (int i = 1; i < G->v; i++) {
		k = MinEdge(shortEdge, G->v);//距离当前树最小权值的邻接点
		printf("(%d,%d) %d\n", shortEdge[k].adjvex, k, shortEdge[k].lowcost);
		shortEdge[k].lowcost = 0;//把Vk加入集合U
		for (int j = 1; j < G->v; j++) {
			if (G->arc[j][k] < shortEdge[j].lowcost) {
				shortEdge[j].lowcost = G->arc[j][k];
				shortEdge[j].adjvex = k;
			}
		}
	}
}

//邻接矩阵创建无向带权图
void CreateGraph1(EdgeGraph **graph)
{
	*graph = (EdgeGraph *)malloc(sizeof(EdgeGraph));
	printf("输入图的顶点数和边数:\n");
	scanf_s("%d %d", &((*graph)->v), &((*graph)->e));
	getchar();
	printf("输入%d个顶点:\n", (*graph)->v);
	for (int i = 0; i < (*graph)->v; i++) {
		scanf_s("%d", &((*graph)->vexs[i]));
		getchar();
	}
	for (int i = 0; i < (*graph)->v; i++) {
		printf("%d ", (*graph)->vexs[i]);
	}
	printf("\n");
	ENode *E = (ENode *)malloc(sizeof(ENode));
	printf("输入边的信息:\n");
	for (int k = 0; k < (*graph)->e; k++) {
		scanf_s("%d %d %d", &(E->v1), &(E->v2), &(E->Weight));//输入的时候按从小到大顺序输入
		getchar();
		(*graph)->edge[k].v1 = (E->v1);
		(*graph)->edge[k].v2 = (E->v2);
		(*graph)->edge[k].Weight = (E->Weight);
	}
}

void Print1(EdgeGraph *G)
{
	for (int i = 0; i < G->v; i++) {
		printf("%d\n", G->vexs[i]);
	}
	printf("\n");
	printf("From ");
	for (int i = 0; i < G->e; i++) {
		printf("%2d ", G->edge[i].v1);
	}
	printf("\n");
	printf("To   ");
	for (int i = 0; i < G->e; i++) {
		printf("%2d ", G->edge[i].v2);
	}
	printf("\n");
	printf("W    ");
	for (int i = 0; i < G->e; i++) {
		printf("%2d ", G->edge[i].Weight);
	}
	printf("\n");
}

int Findroot(int parent[], Vertex v)
{
	Vertex t = v;
	while (parent[t] > -1) {
		t = parent[t];
	}
	return t;
}

void Kruskal(EdgeGraph *G)
{
	int parent[MAXSIZE];
	for (int i = 0; i < G->v; i++) {
		parent[i] = -1;
	}
	int num = 0;
	for (int i = 0; i < G->e; i++) {
		Vertex vex1 = Findroot(parent, G->edge[i].v1);//找最小权值边的根结点
		Vertex vex2 = Findroot(parent, G->edge[i].v2);
		if (vex1 != vex2) {
			printf("(%d,%d) %d\n", G->edge[i].v1, G->edge[i].v2, G->edge[i].Weight);
			parent[vex2] = vex1;//把两个连通分量的根结点合并
			num++;
			if (num == (G->v - 1)) {
				break;
			}
		}
	}
}

int main()
{
	//MGraph *G;
	//CreateGraph(&G);
	//Print(G);
	//Prim(G);
	EdgeGraph *G;
	CreateGraph1(&G);
	Print1(G);
	Kruskal(G);
	return 0;
}





