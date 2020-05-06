#include<stdio.h>
#include<string.h>
#include"xLink.h"

typedef struct Person {
	cLinkNode node;
	char name[20];
	int age;
}Person;

int mycompare(cLinkNode *data1, cLinkNode *data2)
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

void myprint(cLinkNode *data)
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
	strcpy_s(p5.name, "fff");

	cLinkList *list= Init_List();
	Insert(list, 1, (cLinkNode *)&p1);
	Insert(list, 1, (cLinkNode *)&p2);
	Insert(list, 1, (cLinkNode *)&p3);
	Insert(list, 1, (cLinkNode *)&p4);
	Print_List(list, myprint);
	Search(list, (cLinkNode *)&p5, mycompare);
	Search(list, (cLinkNode *)&p4, mycompare);
	Del(list, 1);
	Print_List(list, myprint);
	printf("\n");
	Delvalue(list, (cLinkNode *)&p1, mycompare);
	Print_List(list, myprint);
	printf("\n");
	Insert(list, 3, (cLinkNode *)&p5);
	Print_List(list, myprint);
	Free(list);

	return 0;
}