#pragma once
#define MAXSIZE 50
#define INFINTE 9999

typedef int Vertex;
typedef int Edge;

typedef struct ENode {
	Vertex v1, v2;
	Edge Weight;
}ENode;

typedef struct MGraph {
	int e, v;
	Vertex vexs[MAXSIZE];
	Edge arc[MAXSIZE][MAXSIZE];
}MGraph;

int location(MGraph *graph, Vertex v);