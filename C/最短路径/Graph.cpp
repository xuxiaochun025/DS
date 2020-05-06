#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Graph.h"

//�ڽӾ��󴴽������Ȩͼ
void CreateGraph(MGraph **graph)
{
	*graph = (MGraph *)malloc(sizeof(MGraph));
	printf("����ͼ�Ķ������ͱ���:\n");
	scanf_s("%d %d", &((*graph)->v), &((*graph)->e));
	getchar();
	printf("����%d������:\n", (*graph)->v);
	for (int i = 0; i < (*graph)->v; i++) {
		scanf_s("%d", &((*graph)->vexs[i]));
		getchar();
	}
	for (int i = 0; i < (*graph)->v; i++) {
		printf("%d ", (*graph)->vexs[i]);
	}
	printf("\n");
	for (int i = 0; i < (*graph)->v; i++) {//��ʼ���ڽӾ���
		for (int j = 0; j < (*graph)->v; j++) {
			(*graph)->arc[i][j] = INFINTE;
		}
	}
	ENode *E = (ENode *)malloc(sizeof(ENode));
	printf("����ߵ���Ϣ:\n");
	for (int k = 0; k < (*graph)->e; k++) {
		scanf_s("%d %d %d", &(E->v1), &(E->v2), &(E->Weight));
		getchar();
		(*graph)->arc[E->v1][E->v2] = E->Weight;
		//(*graph)->arc[E->v2][E->v1] = E->Weight;
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

void Dijkstra(MGraph *G, Vertex v)
{
	int s[MAXSIZE];//�Ѽ���Ľ����
	int path[MAXSIZE];//������·����
	int dist[MAXSIZE];//������·������
	//�ӽ��v��ʼ
	for (int i = 0; i < G->v; i++) {
		dist[i] = G->arc[v][i];
		path[i] = 0;
	}
	s[v] = 0;//v�Ѿ�����
	dist[v] = 0;//��v��ʼ����v���뼯��U
	int num = 1;
	while (num < G->v) {
		int k;
		int min = INFINTE;
		for (int i = 0; i < G->v; i++) {
			if (s[i] != 0 && dist[i] < min) {//�Ѿ����뼯��U�ĵ㲻����
				k = i;
				min = dist[i];
			}
		}
		for (int i = 0; i < G->v; i++) {
			printf("%d(%d,%d) %d %d\t", k, v, i, dist[i], path[i]);
		}
		//����path[4]=2,path[2]=1,path[1]=1,·��Ϊ1->2->4
		printf("\n");
		s[k] = 0;
		for (int i = 0; i < G->v; i++) {
			if (dist[i] > dist[k] + G->arc[k][i]) {
				dist[i] = dist[k] + G->arc[k][i];
				path[i] = k;
			}
		}
		num++;
	}
}

void Floyd(MGraph *G)
{
	int dist[MAXSIZE][MAXSIZE];
	int path[MAXSIZE][MAXSIZE];
	for (int i = 0; i < G->v; i++) {
		for (int j = 0; j < G->v; j++) {
			dist[i][j] = G->arc[i][j];
			path[i][j] = -1;
		}
	}

	for (int k = 0; k < G->v; k++) {
		for (int i = 0; i < G->v; i++) {
			for (int j = 0; j < G->v; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = k;
				}
			}
		}
	}

	for (int i = 0; i < G->v; i++) {
		for (int j = 0; j < G->v; j++) {
			printf("%d,%d\t", dist[i][j], path[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	MGraph *G;
	CreateGraph(&G);
	Print(G);
	Dijkstra(G, 0);
	Floyd(G);
	return 0;
}