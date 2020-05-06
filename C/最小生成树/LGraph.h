#pragma once

#define MAXSIZE 50
#define MAXEDGE 50
#define INFINTE 9999

typedef int Vertex;
typedef int Edge;

//定义边
typedef struct ENode {
	Vertex v1, v2;
	Edge Weight;
}ENode;

/*邻接表*/
//定义边表
typedef struct ArcNode {
	Vertex adjvex;
	Edge Weight;
	struct ArcNode *next;
}ArcNode;

//定义顶点表
typedef struct VNode {
	Vertex data;
	ArcNode *firstedge;
}AdjList[MAXSIZE];

typedef struct LGraph {
	int e, v;
	AdjList G;
}LGraph;

/*邻接矩阵*/
typedef struct MGraph {
	int e, v;
	Edge arc[MAXSIZE][MAXSIZE];
	Vertex vexs[MAXSIZE];
}MGraph;

//Prim
typedef struct Matrix {
	int lowcost;//到当前最小生成树的最小权值
	int adjvex;//到当前最小生成树的邻接点
}ShortEdge[MAXSIZE];

//Kurskal
typedef struct EdgeGraph {
	int e, v;
	Vertex vexs[MAXSIZE];
	ENode edge[MAXEDGE];
}EdgeGraph;

int MinEdge(ShortEdge a, int n);
void CreateGraph(MGraph **graph);
void Prim(MGraph *G);
void Print(MGraph *G);
void Kruskal(EdgeGraph *G);
void CreateGraph1(EdgeGraph **graph);
int Findroot(int parent[], Vertex v);