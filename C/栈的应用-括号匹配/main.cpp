#include<stdio.h>
#include"LinkStack.h"

int main()
{
	char str[] = "([[]4+((2+8)*[5/(9-7)]())])";
	char *p = str;
	LinkStack *stack = Init();
	int isMatch = 1;

	while (*p != '\0') {
		if (*p == '(' || *p == '[') {          //如果是左括号，入栈
			Push(stack,p);
		}
		if (*p == ')' || *p == ']') {          //如果是右括号
			if (IsEmpty(stack)) {
				char *q = (char *)Top_e(stack);//弹出栈顶元素
				if ((*q == '(' && *p==')')||(*q == '[' && *p == ']')) { //如果是匹配的左括号，出栈
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