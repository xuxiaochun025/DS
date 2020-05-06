#pragma once
#define MAXSIZE 100
#define INFINTE 65535

typedef char Vertex;//��������
typedef int Edge;//�ߵ�Ȩֵ����

typedef struct ENode {
	Vertex v1, v2;
	Edge Weight;
}ENode;

typedef struct Graph {
	int v, e;          //�������ͱ���
	Edge arc[MAXSIZE][MAXSIZE];//�ڽӾ���
	Vertex vexs[MAXSIZE];  //�����
}MGraph;

void CreateGraph(MGraph *);
int location(MGraph *, Vertex );
void Print(MGraph *);