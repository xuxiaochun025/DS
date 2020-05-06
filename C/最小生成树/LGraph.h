#pragma once

#define MAXSIZE 50
#define MAXEDGE 50
#define INFINTE 9999

typedef int Vertex;
typedef int Edge;

//�����
typedef struct ENode {
	Vertex v1, v2;
	Edge Weight;
}ENode;

/*�ڽӱ�*/
//����߱�
typedef struct ArcNode {
	Vertex adjvex;
	Edge Weight;
	struct ArcNode *next;
}ArcNode;

//���嶥���
typedef struct VNode {
	Vertex data;
	ArcNode *firstedge;
}AdjList[MAXSIZE];

typedef struct LGraph {
	int e, v;
	AdjList G;
}LGraph;

/*�ڽӾ���*/
typedef struct MGraph {
	int e, v;
	Edge arc[MAXSIZE][MAXSIZE];
	Vertex vexs[MAXSIZE];
}MGraph;

//Prim
typedef struct Matrix {
	int lowcost;//����ǰ��С����������СȨֵ
	int adjvex;//����ǰ��С���������ڽӵ�
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