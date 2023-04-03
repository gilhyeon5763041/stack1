#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_STACK_SIZE 10
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;
int is_empty() {
	return (top == -1);
}
int is_full() {
	return (top == (MAX_STACK_SIZE - 1));
}
void push(element item) {
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else stack[++top] = item;
}
element pop() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		return;
	}
	else return stack[top--];
}
int main(void) {
	int i;
	srand(time(NULL));
	for (i = 1; i <= 30; i++)
	{
		int rand_num = rand() % 100 + 1;
		if (rand_num % 2) {
			pop();
			printf("[%d] pop %d\n", i, rand_num);
		}
		else {
			push(rand_num);
			printf("[%d] push %d\n", i, rand_num);
		}
	}
	return 0;
}