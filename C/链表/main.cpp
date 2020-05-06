#include<stdio.h>
#include<string>
#include"Link.h"

typedef struct hero {
	char name[20];
	int age;
}hero;
hero h1 = { "zhongnanshan",84 };
hero h2 = { "lilanjuan",74 };
hero h3 = { "liwenliang",36 };
hero h4 = { "Chinese",100 };
hero h5 = { "America",200 };

void myprint(void *data)//打印任意类型数据  void (*print)-->void myprint
{
	hero *h = (hero *)data;//强制转换
	printf("%s %d\n", h->name,h->age);
}

bool mycompare(void *data1,void *data2)//函数指针 int (*mycompare)-->int  mycompare
{
	hero *h1 = (hero *)data1;
	hero *h2 = (hero *)data2;
	if (h1->age == h2->age && strcmp(h1->name, h2->name) == 0) {
		return true;
	}
	else {
		return false;
	}
}

void test()
{
	LinkList *list = Init_LinkList();
	printf("%p\n", list);            //00C25788  
	printf("%p\n", &(list->pHeader));//00C25788
	Insert(list, 1, &h1);
	Insert(list, 2, &h2);
	Insert(list, 3, &h3);
	Insert(list, 2, &h4);
	Print_List(list, myprint);
	change(list, 1, &h5);
	Print_List(list, myprint);
	/*int a=Length(list);
	printf("%d\n", a);
	Find(list, &h5, mycompare);
	Find(list, &h4, mycompare);
	Del(list, 1);
	Print_List(list, myprint);
	Del(list, 2);
	Print_List(list, myprint);
	Free(list);*/
	//Print_List(list, myprint);
}
int main()
{
	test();
	return 0;
}