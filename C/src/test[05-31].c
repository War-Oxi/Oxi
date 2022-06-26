//! 괄호 검사 프로그램 4-6
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
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

int check_matching(const char *in)
{
    StackType s;
    char ch, open_ch;
    int i, n = strlen(in);
    init_stack(&s);

    for (i=0; i<n; i++){
        ch = in[i];
        switch (ch){
        case '(': case '[': case '{':
            push(&s, ch);
            break;
        case ')': case ']': case '}':
            if (is_empty(&s)) return 0;
            else{
                open_ch = pop(&s);
                if((open_ch=='('&& ch !=')')||
                (open_ch == '['&& ch !=']')||
                (open_ch == '{'&& ch !='}')){
                return 0;
                }
                break;
            }
        }
    }
    if(!is_empty(&s)) return 0;
    return 1;
}

int main(void)
{
    char *p = "{ A[(i+1)]=0;  }";
    if (check_matching(p) ==1)
        printf("%s 괄호검사 성공\n", p);
    else
        printf("%s 괄호검사 실패\n", p);
    return 0;
}*/
//! 후휘표기식 계산 4-7
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
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
//*후위 표기 수식 계산 함수 **********************************************************
int eval(char exp[])
{
    int op1, op2, value, i = 0;
    int len = strlen(exp);
    char ch;
    StackType s;

    init_stack(&s);
    for(i=0; i<len; i++){
        ch = exp[i];
        if(ch != '+' && ch != '-' && ch != '*' && ch != '/'){
            value = ch - '0'; //*입력이 피연산자이면
            push(&s, value);
        }
        else{
            op2 = pop(&s);
            op1 = pop(&s);
            switch(ch){
            case '+': push(&s, op1 + op2); break;
            case '-': push(&s, op1 - op2); break;
            case '*': push(&s, op1 * op2); break;
            case '/': push(&s, op1 / op2); break;
            }
        }
    }
    return pop(&s);
}

int main(void)
{
    int result;
    printf("후위표기식은 82/3-32*+\n");
    result = eval("82/3-32*+");
    printf("결과값은 %d\n", result);
    return 0;
}*/
//! 중위 표기 수식을 후위 표기 수식으로 변환하는 프로그램 4-8
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
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

int prec(char op)
{
    switch (op){
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return -1;
}

void infix_to_postfix(char exp[])
{
    int i = 0;
    char ch, top_op;
    int len = strlen(exp);
    StackType s;

    init_stack(&s);
    for (i=0; i<len; i++){
        ch = exp[i];
        switch (ch){
        case '+': case '-': case '*': case '/':
            while (!is_empty(&s) && prec(ch) <= prec(peek(&s))) //? 이거 좀 이상한디
                printf("%c", pop(&s));
            push(&s, ch);
            break;
        
        case '(':
            push(&s, ch);
            break;
        case ')':
            top_op = pop(&s);
            while (top_op != '('){
                printf("%c", top_op);
                top_op = pop(&s);
            }
            break;
        default:
            printf("%c", ch);
            break;
        }
    }
    while (!is_empty(&s))
        printf("%c", pop(&s));
}

int main(void)
{
    char *s = "5*(10+2)%2";
    printf("중위표기수식 %s \n", s);
    printf("후위표기수식 ");
    infix_to_postfix(s);
    printf("\n");
    return 0;
}

