#pragma once
#define MAXSIZE 100
#define INFINTE 65535

typedef char Vertex;//顶点类型
typedef int Edge;//边的权值类型

typedef struct ENode {
	Vertex v1, v2;
	Edge Weight;
}ENode;

typedef struct Graph {
	int v, e;          //顶点数和边数
	Edge arc[MAXSIZE][MAXSIZE];//邻接矩阵
	Vertex vexs[MAXSIZE];  //顶点表
}MGraph;

void CreateGraph(MGraph *);
int location(MGraph *, Vertex );
void Print(MGraph *);