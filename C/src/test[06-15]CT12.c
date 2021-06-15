//!프로그램 12.1 선택 정렬 함수
/*#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void selection_sort(int list[],int n)
{
    int i,j,least, temp;
    for(i=0; i<n-1; i++){
        least = i;
        for (j=i+1; j<n; j++)
            if(list[j]<list[least]) least = j;
        SWAP(list[i], list[least], temp);
    }
}*/
//!프로그램 12.2 선택 정렬 프로그램
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;
void selection_sort(int list[],int n)
{
    int i,j,least, temp;
    for(i=0; i<n-1; i++){
        least = i;
        for (j=i+1; j<n; j++)
            if(list[j]<list[least]) least = j;
        SWAP(list[i], list[least], temp);
    }
}
int main(void)
{
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for(i=0; i<n; i++)
        list[i] = rand() %100;

    selection_sort(list,n);
    for(i=0; i<n; i++)
        printf("%d ", list[i]);
    printf("\n"); return 0;
}
//! 프로그램 12-3 삽입 정렬 프로그램
void insertion_sort(int list[], int n )
{
    int i, j, key;
    for (i=1; i<n; i++){
        key = list[i];
        for(j=i-1; j>=0 && list[j]>key; j--)
            list[j+1]=list[j];
        list[j+1] = key;
    }
}
//! 프로그램 12-4 버블 정렬 프로그램
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
void bubble_sort(int list[], int n)
{
    int i, j, temp;
    for (i = n-1; i>0; i--){
        for(j=0; j<i; j++)
            if(list[j]>list[j+1])
                SWAP(list[j], list[j+1], temp);
    }
}
//! 프로그램 12-5 쉘 정렬 프로그램
inc_insertion_sort(int list[], int first, int last, int gap)
{
    int i, j, key;
    for(i=first +gap; i<=last; i=i+gap){
        key = list[i];
        for(j=i-gap; j>= first &&key<list[j]; j=j-gap)
            list[j+gap] = list[j];
        list[j+gap] = key;
    }
}

void shell_sort(int list[], int n)
{
    int i, gap;
    for(gap=n/2; gap>0; gap=gap/2){
        if((gap%2)==0)gap++;
        for(i=0;i<gap; i++)
            inc_insertion_sort(list, i, n-1, gap);
    }
}
//!프로그램 12.6 merge 알고리즘의 구현
int sorted[MAX_SIZE];
//?인덱스i,j,k i->정렬된 왼쪽 리스트 j->정렬된 오르쪽리스트 k->정렬될 리스트
void merge(int list[], int left, int mid, int right)
{
    int i,j,k,l;
    i=left; j= mid+1; k=left;

    while(i<=mid&&j<=right){
        if(list[i]<=list[j])
            sorted[k++]=list[i++];
        else
            sorted[k++]=list[j++];
    }
    if(i>mid) //?남아 있는 레코드의 일괄 복사
        for(l=j; l<=right; l++)
            sorted[k++] = list[l];
    else   
        for(l=i; l<=mid; l++)
            sorted[k++] = list[l];
    for (l=left; l<=right; l++) //?배열 sorted[]의 리스트를 배열 list[]로 재복사
        list[l] = sorted[l];
}   
void merge_sort(int list[], int left, int right)
{
    int mid;
    if(left<right){
        mid = (left+right)/2;
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        merge(list, left, mid, right);
    }
}