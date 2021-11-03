#include <cstddef>
#include <locale.h>
#include <stdio.h>

//********* ���� ***********************************
#define MAX_STACK_SIZE 100
#define I_AM_NO_A_VALID_RESULT 9999
typedef int StackElement;

// TODO �������� ����
struct Stack {
	char a[MAX_STACK_SIZE];
	size_t size;
	int top
};

// ������������������� ���������� ���������� ��������� �����
void stack_init(struct Stack* s) {
	s->top = 0;
}

// ������� ���������� ��������� � �����
size_t stack_size(struct Stack* s) {
	return s->top;
}

// ������� �������� �� �������� �����, ��� ��������� ��������
StackElement stack_peek(struct Stack* s) {
	if ((s->top) > 0) {
		return s->a[s->top - 1];
	}

}

// TODO �������� ����
// ��������� �������� x �� �������� �����
void stack_push(struct Stack* s, StackElement x) {
	if (s->top < MAX_STACK_SIZE) {
		s->a[s->top] = x;
		s->top++;
	}
	else
		printf("���� �����, ���������� ���������: %d !\n", s->top);
}

// ������� �������� � �������� �����
StackElement stack_pop(struct Stack* s) {
	if ((s->top) > 0) {
		return s->a[s->top - 1];
	}
	else {
		printf("���� ����!\n");
		return 0;
	}
}
#define check_expr(expr, expected) {\
	int result = (expr); \
	if (result != (expected)) {\
		printf("������:\t '" #expr "'\t to == '%d', ������� '%d' \t(������� %s � ������ %d).\n", \
			   (expected), result, __FUNCTION__, __LINE__);\
		error_count++;\
	}\
}

int error_count = 0;

void test_stack() {
	printf("\n���� 1\n");
	{
		struct Stack empty_stack;
		stack_init(&empty_stack);
		check_expr(stack_size(&empty_stack), 0);
	}
	printf("\n���� 2\n");
	{
		struct Stack simple_stack;
		stack_init(&simple_stack);

		stack_push(&simple_stack, 5);
		check_expr(stack_peek(&simple_stack), 5);
		check_expr(stack_size(&simple_stack), 1);
	}
	printf("\n���� 3\n");
	{
		struct Stack push_pop_stack;
		stack_init(&push_pop_stack);

		stack_push(&push_pop_stack, 5);
		check_expr(stack_pop(&push_pop_stack), 5);
	}
	printf("\n���� 4\n");
	{
		struct Stack complex_stack;
		stack_init(&complex_stack);
		for (int i = 1; i <= 80; i++) {
			stack_push(&complex_stack, i);
		}
		for (int i = 80; i > 40; i--) {
			stack_pop(&complex_stack);

		}
		check_expr(stack_size(&complex_stack), 40);
		check_expr(stack_peek(&complex_stack), 40);
		check_expr(stack_pop(&complex_stack), 40);
	}
}

//****************************************************************
int main() {
	setlocale(LC_ALL, "Russian");
	test_stack();

	if (error_count) {
		printf("\n\n!!!!!!!!!! ���������� ������ (��. ����), ��������� � ���������� ����� !!!!!!!!!!!!!!!\n");
		return 1;
	}
	else {
		printf("\n\n************ ��� ����� ������ *************\n");
		return 0;
	}
}
