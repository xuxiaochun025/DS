#include<stdio.h>
#include<string.h>
#include"ccLink.h"

typedef struct Person {
	char name[15];
	int age;
}Person;

int mycompare(void *data1, void *data2)
{
	Person *p1 = (Person *)data1;
	Person *p2 = (Person *)data2;
	if (p1->age == p2->age&&strcmp(p1->name, p2->name) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void myprint(void *data)
{
    Person *p = (Person *)data;
	printf("%s %d\n", p->name, p->age);
}

int main()
{
	Person p1, p2, p3, p4, p5;
	p1.age = 1;
	p2.age = 2;
	p3.age = 3;
	p4.age = 4;
	p5.age = 5;

	strcpy_s(p1.name, "aaa");
	strcpy_s(p2.name, "bbb");
	strcpy_s(p3.name, "ccc");
	strcpy_s(p4.name, "ddd");
	strcpy_s(p5.name, "eee");

	cLinkList *list = Init();
	Insert(list, 1, &p1);
	Insert(list, 2, &p2);
	Insert(list, 3, &p3);
	Insert(list, 2, &p4);
	PrintList(list, myprint);
	printf("\n");
	/*Search(list, &p5, mycompare);
	Search(list, &p4, mycompare);
	printf("\n");
	Delvalue(list, &p4, mycompare);
	PrintList(list, myprint);
	printf("\n");
	Delvalue(list, &p2, mycompare);
	PrintList(list, myprint);
	printf("\n");
	Insert(list, 3, &p5);
	PrintList(list, myprint);
	Free(list);*/
	return 0;
}