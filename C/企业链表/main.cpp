#include<stdio.h>
#include"InList.h"
#include<string.h>

typedef struct Student {                                 //LinkNode * ----            ---->
	LinkNode node;//�����ڹ��ӣ�ֻ����next�򣬰����ݴ����� //Student * --   ->LinkNode -
	char name[20];                                       //            ---->char name
	int age;                                             //            ---->int age
}Student;

void myprint(LinkNode *data)
{
	Student *p = (Student *)data;//Student *��LinkNode * ��ָ���һ�����ݵĵ�ַ
	printf("%s %d\n", p->name, p->age);//LinkNode *ֻ�ܷ���LinkNode��㣬Student *���Է���ȫ�����
}

int mycompare(LinkNode *data1, LinkNode *data2)
{
	Student *p1 = (Student *)data1;//������Ҫǿ��ת��
	Student *p2 = (Student *)data2;
	if (p1->age == p2->age&&strcmp(p1->name, p2->name) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int main()
{
	Student s1, s2, s3, s4,s5;
	s1.age = 1;
	s2.age = 2;
	s3.age = 3;
	s4.age = 4;
	s5.age = 5;
	strcpy_s(s1.name, "aaa");
	strcpy_s(s2.name, "bbb");
	strcpy_s(s3.name, "ccc");
	strcpy_s(s4.name, "ddd");
	strcpy_s(s5.name, "eee");

	LinkList *list=Init_LinkList();
	Insert(list, 1, (LinkNode *)&s1);////������Ҫǿ��ת��
	Insert(list, 1, (LinkNode *)&s2);
	Insert(list, 1, (LinkNode *)&s3);
	Insert(list, 1, (LinkNode *)&s4);
	Print_List(list, myprint);
	int a = Size(list);
	printf("%d\n", a);
	Find(list, (LinkNode *)&s5, mycompare);
	Find(list, (LinkNode *)&s4, mycompare);
	Del(list, 1);
	Print_List(list, myprint);
	Del(list, 2);
	Print_List(list, myprint);
	Free(list);
	return 0;
}