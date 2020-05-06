#include<stdio.h>
#include"SQueue.h"

typedef struct Student {
	char name[20];
	int age;
}Student;

int main()
{
	SeqQueue *queue = Init();

	Student s1 = { "aaa",21 };
	Student s2 = { "bbb",22 };
	Student s3 = { "ccc",23 };
	Student s4 = { "ddd",24 };

	Push(queue, &s1);//入队
	Push(queue, &s2);
	Push(queue, &s3);
	Push(queue, &s4);

	Student *ss = (Student *)Bot_e(queue);
	printf("%s %d\n", ss->name, ss->age);
	printf("\n");

	while (IsEmpty(queue)) {
		Student *s = (Student *)Top_e(queue);//返回队头元素
		printf("%s %d\n", s->name, s->age);
		Pop(queue, s);//出队
	}

	Free(queue);
	return 0;
}