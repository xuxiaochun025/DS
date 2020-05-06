#include<stdio.h>
#include"LinkStack.h"

typedef struct Student {
	char name[20];
	int age;
}Student;

int main()
{
	LinkStack *stack = Init();

	Student s1 = { "aaa",21 };
	Student s2 = { "bbb",22 };
	Student s3 = { "ccc",23 };
	Student s4 = { "ddd",24 };

	Push(stack, &s1);//��ջ
	Push(stack, &s2);
	Push(stack, &s3);
	Push(stack, &s4);

	while (IsEmpty(stack)) {
		Student *s = (Student *)Top_e(stack);//����ջ��Ԫ��
		printf("%s %d\n", s->name, s->age);
		Pop(stack, s);//��ջ
	}

	Free(stack);
	return 0;
}