#include <stdio.h>
#include <math.h>
#define MAX_DEGREE 101
#define MAX(a,b) (((a)>(b))?(a):(b))

void hanoi_tower(int n, char from, char tmp, char to)
{
    if(n==1)
    {
        printf("원판 1을 %c에서 %c으로 옮긴다. \n", from, to);
    }
    else
    {
        hanoi_tower(n-1, from, to, tmp);
        printf("원판 %d를 %c에서 %c으로 옮긴다. \n",n, from, to);
        hanoi_tower(n-1, tmp, from, to);
    }  
}

int recursive(int n)
{
    if(n!=1)recursive(n-1);
    printf("%d\n", n);
}

void unknown()
{
    int ch;
    if((ch=getchar())!= '\n')
        unknown();
    putchar(ch);
}

double recursive_ver2(double n)
{
    if(n==1)
        return 1;
        
    return recursive_ver2(n-1)+(1/n);  
}

int fib(int n)
{
    printf("fib(%d) is called\n", n);
    if(n==0) return 0;
    if(n==1) return 1;
    return (fib(n-1)+fib(n-2));
}

int sum(int n)
{
    int sum=0;
    for(int i=0;i<=n;i++)
    {
        sum += i;
    }

    return sum;
}

typedef struct studentTag{
    char name[10];
    int age;
    double gpa;
} student;

typedef struct PointTag{
    int x;
    int y;
} point;

double get_distance(point p1, point p2)
{
    double distance=0;
    distance = sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));

    return distance;
}

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
}polynomial;

polynomial poly_add1(polynomial A, polynomial B)
{
    polynomial C;
    int Apos = 0, Bpos = 0, Cpos = 0;
    int degree_a = A.degree;
    int degree_b = B.degree;
    C.degree = MAX(A.degree, B.degree);

    while (Apos <= A.degree && Bpos <= B.degree){
        if (degree_a > degree_b){
            C.coef[Cpos++] = A.coef[Apos++];
            degree_a--;
        }
        else if (degree_a == degree_b){
            C.coef[Cpos++] = B.coef[Bpos++] + A.coef[Apos++];
        }
        else{
            C.coef[Cpos++] = B.coef[Bpos++];
            degree_b--;
        }
    }
    return C;
}

void print_poly(polynomial p)
{
    
    for (int i = p.degree; i>0; i--)
            printf("%3.1lfx^%d + ", p.coef[p.degree - i], i);
    printf("%3.1lf \n", p.coef[p.degree]);
}

int main(void)
{
    polynomial a = {3,{1,0,2,3}};
    polynomial b = {3,{-1,0,4,-1}};
    polynomial c;
    
    print_poly(a);
    print_poly(b);
    c = poly_add1(a, b);
    printf("==============================================\n");

    print_poly(c);
    
    return 0;
}


//!5    4   3   2   1