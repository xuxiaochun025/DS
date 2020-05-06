#include<stdio.h>
#include"LinkStack.h"

int main()
{
	char str[] = "([[]4+((2+8)*[5/(9-7)]())])";
	char *p = str;
	LinkStack *stack = Init();
	int isMatch = 1;

	while (*p != '\0') {
		if (*p == '(' || *p == '[') {          //����������ţ���ջ
			Push(stack,p);
		}
		if (*p == ')' || *p == ']') {          //�����������
			if (IsEmpty(stack)) {
				char *q = (char *)Top_e(stack);//����ջ��Ԫ��
				if ((*q == '(' && *p==')')||(*q == '[' && *p == ']')) { //�����ƥ��������ţ���ջ
					Pop(stack, q);
				}
			}
			else {
				isMatch = 0;
				break;
			}
		}
		p++;
	}

	if (isMatch == 1 && stack->size==0) {
		printf("success.\n");
	}
	else {
		printf("fail.\n");
	}

	return 0;
}