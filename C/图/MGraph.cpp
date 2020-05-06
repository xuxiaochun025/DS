#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"MGraph.h"

//邻接矩阵创建有向带权图
void CreateGraph(MGraph **graph)
{
	*graph = (MGraph *)malloc(sizeof(MGraph));
	int i, j;
	printf("输入带权图的顶点数和边数:\n");
	scanf_s("%d %d", &((*graph)->v), &((*graph)->e));
	getchar();
	printf("输入%d个顶点:\n", (*graph)->v);
	for (int i = 0; i < (*graph)->v; i++) {
		scanf_s("%c", &((*graph)->vexs[i]), 1);
		getchar();
	}
	for (i = 0; i < (*graph)->v; i++) {
		printf("%c ", (*graph)->vexs[i]);
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
		scanf_s("%c %c %d", &(E->v1), 1, &(E->v2), 1, &(E->Weight));
		getchar();
		i = location((*graph), E->v1);
		j = location((*graph), E->v2);
		(*graph)->arc[i][j] = E->Weight;
	}
}

MGraph *CreateGraph1(MGraph *graph)
{
	graph = (MGraph *)malloc(sizeof(MGraph));
	int i, j;
	printf("输入带权图的顶点数和边数:\n");
	scanf_s("%d %d", &(graph->v), &(graph->e));
	getchar();
	printf("输入%d个顶点:\n", graph->v);
	for (int i = 0; i < graph->v; i++) {
		scanf_s("%c", &(graph->vexs[i]), 1);
		getchar();
	}
	for (i = 0; i < graph->v; i++) {
		printf("%c ", graph->vexs[i]);
	}
	printf("\n");
	for (int i = 0; i < graph->v; i++) {//初始化邻接矩阵
		for (int j = 0; j < graph->v; j++) {
			graph->arc[i][j] = INFINTE;
		}
	}
	ENode *E = (ENode *)malloc(sizeof(ENode));
	printf("输入边的信息:\n");
	for (int k = 0; k < graph->e; k++) {
		scanf_s("%c %c %d", &(E->v1), 1, &(E->v2), 1, &(E->Weight));
		getchar();
		i = location(graph, E->v1);
		j = location(graph, E->v2);
		graph->arc[i][j] = E->Weight;
	}
	return graph;
}

int location(MGraph *graph, Vertex v)
{
	for (int i = 0; i < graph->v; i++) {
		if ((int)(v - graph->vexs[i]) == 0) {
			return i;
		}
	}
	return -1;
}

void Print(MGraph *G)
{
	for (int i = 0; i < G->v; i++) {
		printf("%c\n", G->vexs[i]);
	}
	printf("\n");
	for (int i = 0; i < G->v; i++) {
		printf("%8c", G->vexs[i]);
		for (int j = 0; j < G->v; j++) {
			printf("%8d", G->arc[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	MGraph *graph=NULL;
	graph=CreateGraph1(graph);
	Print(graph);
	return 0;
}