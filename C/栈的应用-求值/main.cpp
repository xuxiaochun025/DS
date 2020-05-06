#include<stdio.h>
#include<string.h>
#include"LinkStack.h"

char oper(char a, char b, char op)
{
	if (a >= '0'&&a <= '9') {
		a = a - '0';
	}
	if (b >= '0'&&b <= '9') {
		b = b - '0';
	}
	if (op == '+') {
		return (char )(a + b);
	}
	else if (op == '-') {
		return (char )(a - b);
	}
	else if (op == '*') {
		return (char )(a * b);
	}
	else {
		return (char )(a / b);
	}
}

int main()
{
	LinkStack *stack1 = Init();
	char r[] = "831-*5+";//8*(3-1)+5
	char *t = r;
	while (*t != '\0') {
		if (*t == '+' || *t == '-'||*t=='*'||*t=='/') {
			char b = Top_e(stack1);
			Pop(stack1, b);
			char a = Top_e(stack1);
			Pop(stack1, a);
			char c =oper(a, b, *t);
			Push(stack1, c); 
		}
		else {
			Push(stack1, *t);
		}
		t++;
	}
	printf("%d\n", Top_e(stack1));

	return 0;
}