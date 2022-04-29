#include <stdio.h>
#include <string.h>


int main(void)
{
    char str[]="ABC가";
    int size=sizeof(str);
    int len=strlen(str);
    printf("배열의 크기 : %d \n", size);
    printf("문자열 크기 : %d \n", len);
}