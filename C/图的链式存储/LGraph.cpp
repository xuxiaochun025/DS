#include<stdio.h>
#include<stdlib.h>
#include"LGraph.h"
#include"LinkQueue.h"
#include"LinkStack.h"

//邻接表创建无向带权图
void CreateGraph(LGraph **graph)
{
	*graph = (LGraph *)malloc(sizeof(LGraph));
	printf("输入图的顶点数和边数:\n");
	scanf_s("%d %d", &((*graph)->v), &((*graph)->e));
	getchar();
	printf("输入图的%d个顶点:\n", (*graph)->v);
	for (int i = 0; i < (*graph)->v; i++) {
		scanf_s("%d", &(*graph)->G[i].data);//顶点表初始化
		getchar();
		(*graph)->G[i].firstedge = NULL;
	}
	printf("输入边表信息:\n");
	ENode *E = (ENode *)malloc(sizeof(ENode));
	for (int k = 0; k < (*graph)->e; k++) {
		scanf_s("%d %d %d", &(E->v1), &(E->v2), &(E->Weight));
		getchar();
		//以v1为起点，v2为终点建立边
		ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
		//头插法
		p->adjvex = E->v2;
		p->Weight = E->Weight;
		p->next = (*graph)->G[E->v1].firstedge;
		(*graph)->G[E->v1].firstedge = p;
		//尾插法
		//ArcNode *r = (*graph)->G[v1].firstedge;
		//p->adjvex = v2;
		//p->Weight = E->Weight;
		//r->next = p;
		//r = p;
		//r->next = NULL;
		//以v2为起点，v1为终点建立边(无向图)
		ArcNode *q = (ArcNode *)malloc(sizeof(ArcNode));
		//头插法
		q->adjvex = E->v1;
		q->Weight = E->Weight;
		q->next = (*graph)->G[E->v2].firstedge;
		(*graph)->G[E->v2].firstedge = q;
	}
}

void Print(LGraph *graph)
{
	for (int i = 0; i < graph->v; i++) {
		printf("%d ", graph->G[i].data);
	}
	printf("\n");
	for (int i = 0; i < graph->v; i++) {
		ArcNode *p = graph->G[i].firstedge;
		int j = 0;
		while (p) {
			if (j == 0) {
				printf("%d-->%d", graph->G[i].data, graph->G[p->adjvex].data);
				j = 1;
			}
			else {
				printf("-->%d", graph->G[p->adjvex].data);
			}
			p = p->next;
		}
		printf("\n");
	}
}

void visit(Vertex v)
{
	printf("%d\t", v);
}

void DFS(LGraph *graph, Vertex v, void(*visit)(Vertex), int Visited[])
{
	visit(v);
	Visited[v] = 1;
	ArcNode *p = graph->G[v].firstedge;
	while (p) {
		if (!Visited[p->adjvex]) {
			DFS(graph, p->adjvex, visit, Visited);
		}
		p = p->next;
	}
}

void nrDFS(LGraph *graph, Vertex v, void(*visit)(Vertex), int Visited[])
{
	LinkStack *stack = Init();
	Push(stack, v);
	visit(v);
	Visited[v] = 1;
	int e;
	ArcNode *p = graph->G[v].firstedge;
	while (p||IsEmpty(stack)) {
		while (p) {
			if (!Visited[p->adjvex]) {
				visit(p->adjvex);
				Visited[p->adjvex] = 1;
				Push(stack, p->adjvex);
				p = graph->G[p->adjvex].firstedge;
			}
			else {
				p = p->next;//用来退出循环
			}
		}
		if (!p && !IsEmpty(stack)) {
			break;
		}
		e = Top_e(stack);
		if (Visited[e]==1) {
			v = e;
			Pop(stack, v);
			p = graph->G[v].firstedge->next;
		}
	}
	
}

void nrDFSTraverse(LGraph *graph)
{
	int Visited[MAXSIZE];
	for (int i = 0; i < graph->v; i++) {
		Visited[i] = 0;
	}
	Vertex v = 0;
	nrDFS(graph, v, visit, Visited);
}

void DFSTraverse(LGraph *graph)
{
	int Visited[MAXSIZE];
	for (int i = 0; i < graph->v; i++) {
		Visited[i] = 0;
	}
	Vertex v = 0;
	DFS(graph, v, visit, Visited);
}

void BFS(LGraph *graph, Vertex v, void(*visit)(Vertex), int Visited[])
{
	LinkQueue *queue = Init1();
	visit(v);
	Visited[v] = 1;
	Push1(queue, v);
	while (IsEmpty1(queue)) {
		int e = Top_e1(queue);
		Pop1(queue, e);
		ArcNode *p = graph->G[e].firstedge;
		while (p) {
			if (!Visited[p->adjvex]) {
				visit(p->adjvex);
				Visited[p->adjvex] = 1;
				Push1(queue, p->adjvex);
			}
			p = p->next;
		}
	}
}

void BFSTraverse(LGraph *graph)
{
	int Visited[MAXSIZE];
	for (int i = 0; i < graph->v; i++) {
		Visited[i] = 0;
	}
	Vertex v = 0;
	BFS(graph, v, visit, Visited);
}

int main()
{
	LGraph *graph;
	CreateGraph(&graph);
	Print(graph);
	DFSTraverse(graph);
	//BFSTraverse(graph);
	printf("\n");
	nrDFSTraverse(graph);
	return 0;
}