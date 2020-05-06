#pragma once

#define MAXSIZE 50

typedef int Vertex;
typedef int Edge;

typedef struct ENode {//�ߵĶ���
	Vertex v1, v2;
	Edge Weight;
}ENode;

typedef struct ArcNode {//�߱���
	Edge adjvex;//��Ÿö�����ڽӵ��ڶ�����е�"�±�"
	Edge Weight;
	struct ArcNode *next;
}ArcNode;

typedef struct VNode {//�����ͷ���
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