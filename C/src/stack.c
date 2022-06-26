#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct{
	element *data;
	int capacity;
	int top;
} Stacktype;

void init_stack(Stacktype *s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element *)malloc(s->capacity * sizeof(element));
}

int is_empty(Stacktype *s)
{
	return (s->top == -1);
}

int is_full(Stacktype *s){
	return (s->top == (s->capacity - 1));
}

void push(Stacktype *s, element item){
	if (is_full(s)){
		s->capacity *= 2;
		s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}

element pop(Stacktype *s)
{
	if (is_empty(s)){
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

int main(void){
	Stacktype s;
	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);
	printf("%d \n", pop(&s));
	printf("%d \n", pop(&s));
	printf("%d \n", pop(&s));
	printf("%d \n", pop(&s));
	free(s.data);
	return 0;
}