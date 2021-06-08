#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main()
{
    int Tree[MAX];

    

    for (int i= 1; i<=10; i++)
    {
        Tree[i] = 0;
    }
    Tree[1] = 10;
    Tree[3] = 20;
    Tree[5] = 30;
    Tree[6] = 25;
    for (int i= 1; i<10; i++)
    {
        printf("%d = %d\n",i,Tree[i]);
    }

    return 0;
}
