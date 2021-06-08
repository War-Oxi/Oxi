//!malloc2.c 동적 메모리 할당 사용 예제 프로그램 3.9
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentTag{
    char name[10];
    int age;
    double gpa;
} student;

int main(void)
{
    student *s;

    s = (student *)malloc(sizeof(student));
    if(s == NULL){
        fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다. \n");
        exit(1);
    }

    strcpy(s->name, "Park");
    s->age = 20;

    free(s);
    return 0;
}*/
//!연습문제 3-4
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct two_exponTag
{
    int two[10];
} two_expon;

int main(void)
{
    two_expon *s;
    if(s == NULL){
        fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다. \n");
    }
    s = (two_expon *)malloc(sizeof(two_expon));
    for (int i=0; i<10; i++)
    {
        s->two[i] = pow(2, i);
    }
    for(int i=0; i<10; i++)
    {
        printf("%d\n", s->two[i]);
    }

    return 0;
}*/
//!정수 배열 스택 프로그램 4-1
/*
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty()
{
    return (top == -1);
}

int is_full()
{
    return (top == (MAX_STACK_SIZE -1));
}

void push(element item)
{
    if (is_full()){
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else stack[++top] = item;
}

element pop()
{
    if (is_empty()){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top--];
}

element peek()
{
    if (is_empty()){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top];
}

int main(void)
{
    push(1);
    push(2);
    push(3);
    
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    

    return 0;
}*/
//! 구조체 배열 스택 프로그램 4-2
/*
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct{
    int studnet_no;
    char name[MAX_STRING];
    char address[MAX_STACK_SIZE];
} element;

element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty()
{
    return (top == -1);
}

int is_full()
{
    return (top == (MAX_STACK_SIZE - 1));
}

void push(element ITEM)
{
    if (is_full()){
        fprintf(stderr, "스택 포화 에러\n");
        exit(1);
    }
    else stack[++top] = ITEM;
}

element pop()
{
    if (is_empty()){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top--];
}

element peek()
{
    if(is_empty()){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top];
}

int main(void)
{
    element ie = {20190001, "Hong", "Soeul"};
    element oe;

    push(ie);
    oe = pop();

    printf("학번: %d\n", oe.studnet_no);
    printf("이름: %s\n", oe.name);
    printf("주소: %s\n", oe.address);

    return 0;
}*/
//! 일반적인 배열 스택 프로그램 4-3
/*#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;
//*스택 초기화 함수
void init_stack(StackType *s)
{
    s->top = -1;
}
//*공백 상태 검출 함수
int is_empty(StackType *s)
{
    return (s->top == -1);
}
//* 포화 상태 검출 함수
int is_full(StackType *s)
{
    return (s->top == (MAX_STACK_SIZE-1));
}

void push(StackType *s, element item)
{
    if (is_full(s)){
        fprintf(stderr,"스택 포화 에러\n");
        return;
    }
    else s->data[++(s->top)] = item;
}

element pop(StackType *s)
{
    if (is_empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

element peek(StackType *s)
{
    if (is_empty(s)){
        fprintf(stderr,"스택 공백 에러");
        exit(1);
    }
    else return s->data[s->top];
}

int main(void)
{
    StackType *s;
    s = (StackType *)malloc(sizeof(StackType));
    init_stack(s);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
    free(s);
    return 0;
}*/
//! 동적 배열 스택 프로그램 4-5
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct{
    element *data;
    int capacity;
    int top;
} StackType;

void init_Stack(StackType *s)
{
    s->top = -1;
    s->capacity = 1;
    s->data = (element *)malloc(s->capacity * sizeof(element));
}

int is_empty(StackType *s)
{
    return (s->top == -1);
}

int is_full(StackType *s)
{
    return (s->top == (s->capacity -1));
}

void push(StackType *s, element item)
{
    if(is_full(s)){
        s->capacity *= 2;
        s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
    }
    s->data[++(s->top)] = item;
}

element pop(StackType *s)
{
    if (is_empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

int main(void)
{
    StackType s;
    init_Stack(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    printf("%d \n", pop(&s));
    printf("%d \n", pop(&s));
    printf("%d \n", pop(&s));
    free(s.data);
    return 0;
}









