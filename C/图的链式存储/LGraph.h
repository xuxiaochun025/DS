#pragma once

#define MAXSIZE 50

typedef int Vertex;
typedef int Edge;

typedef struct ENode {//边的定义
	Vertex v1, v2;
	Edge Weight;
}ENode;

typedef struct ArcNode {//边表结点
	Edge adjvex;//存放该顶点的邻接点在顶点表中的"下标"
	Edge Weight;
	struct ArcNode *next;
}ArcNode;

typedef struct VNode {//顶点表头结点
	Vertex data;
	ArcNode *firstedge;
}AdjList[MAXSIZE];

typedef struct Graph {
	int e, v;
	AdjList G;
}LGraph;

int location(LGraph *, Vertex );
void Print(LGraph *);
void visit(Vertex );
void DFS(LGraph *, Vertex , void(*visit)(Vertex), int Visited[]);
void DFSTraverse(LGraph *);
void nrDFSTraverse(LGraph *graph);
void BFS(LGraph *, Vertex , void(*visit)(Vertex), int Visited[]);
void BFSTraverse(LGraph *);