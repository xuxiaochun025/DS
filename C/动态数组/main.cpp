#include<stdio.h>
#include"Link.h"

typedef struct hero {
	char name[20];
	int age;
}hero;
hero h1 = { "zhongnanshan",84 };
hero h2 = { "lilanjuan",74 };
hero h3 = { "liwenliang",36 };
hero h4 = { "Chinese",100 };

void myprint(hero *h)
{
	printf("%s\n", h->name);
	printf("%d\n", h->age);
}
void test()
{
	LinkList *list = Init_LinkList();
	Insert(list, 1, &h1);
	Insert(list, 2, &h2);
	Insert(list, 3, &h3);
	Insert(list, 1, &h4);
	Print_List(list, myprint());

}
int main()
{

	test();
	return 0;
}