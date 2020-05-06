#include<stdio.h>
#include<string.h>
#include"LinkStack.h"

int priority(char op)
{
	if (op == '(') {
		return 1;
	}
	else if (op == '+' || op == '-') {
		return 2;
	}
	else {
		return 3;
	}
}

int main()
{
    char str[] = "8*(3-1)+5";//8 3 1 - * 5 +
	char *p = str;
	LinkStack *stack = Init();

	while (*p != '\0') {
		if (*p >= '0'&&*p <= '9') {
			printf("%c ", *p);
		}
		else if (*p == '(') {
			Push(stack, *p);
		}
		else if (*p == ')') {
			char q = Top_e(stack);
			while (q != '(') {
				printf("%c ", q);
				Pop(stack, q);
				q = Top_e(stack);
			}
			Pop(stack, '(');
		}
		else {
			if (IsEmpty(stack)) {
				char q = Top_e(stack);
				if (priority(*p) > priority(q)) {//当前元素优先级 > 栈顶元素
					Push(stack, *p);
				}
				else {
					printf("%c ", q);
					Pop(stack, q);
					Push(stack, *p);
				}
			}
			else {
				Push(stack, *p);
			}
		}
		p++;
	}

	while (IsEmpty(stack)) {
		char q = Top_e(stack);
		printf("%c ", q);
		Pop(stack, q);
	}
	Free(stack);
	printf("\n");

	return 0;
}	