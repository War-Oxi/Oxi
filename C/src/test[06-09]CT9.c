//!히프의 구현
/*
#define MAX_ELEMENT 200
typedef struct{
    int key;
}element;
typedef struct{
    element heap[MAX_ELEMENT];
    int heap_size;
}HeapType;*/
//!프로그램 9.1 히프트리에서의 삽입 함수
/*void insert_max_heap(HeapType* h, element item)
{
    int i;
    i = ++(h->heap_size);
    while ((i!=1)&&(item.key > h->heap[i/2].key)){
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}*/
//!프로그램 9.2 히프트리에서의 삭제 함수
/*element delete_max_heap(HeapType* h)
{
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size){
        //?현재 노드의 자식노드 중 더 큰 자식노드를 찾는다.
        if((child<h->heap_size)&&
            (h->heap[child].key) < h->heap[child+1].key)
            child++;
        if (temp.key >= h->heap[child].key) break;
        //? 한 단계 아래로 이동
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}*/
//!프로그램 9.3 히프트리 테스트 프로그램
/*#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef struct {
    int key;
}element;
typedef struct{
    element heap[MAX_ELEMENT];
    int heap_size;
}HeapType;

HeapType* create(){
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h)
{
    h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item)
{
    int i;
    i = ++(h->heap_size);
    while ((i!=1)&&(item.key > h->heap[i/2].key)){
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

element delete_max_heap(HeapType* h)
{
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size){
        //?현재 노드의 자식노드 중 더 큰 자식노드를 찾는다.
        if((child<h->heap_size)&&
            (h->heap[child].key) < h->heap[child+1].key)
            child++;
        if (temp.key >= h->heap[child].key) break;
        //? 한 단계 아래로 이동
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

int main(void)
{
    element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
    element e4, e5, e6;
    HeapType* heap;
    heap = create();
    init(heap);

    insert_max_heap(heap,e1);
    insert_max_heap(heap,e2);
    insert_max_heap(heap,e3);

    e4 = delete_max_heap(heap);
    printf("< %d > ", e4.key);
    e5 = delete_max_heap(heap);
    printf("< %d > ", e5.key);
    e6 = delete_max_heap(heap);
    printf("< %d > \n", e6.key);

    free(heap);
    return 0;  
}*/
//!프로그램 9.4 히트 정렬 프로그램
/*#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef struct {
    int key;
}element;
typedef struct{
    element heap[MAX_ELEMENT];
    int heap_size;
}HeapType;

HeapType* create(){
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h)
{
    h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item)
{
    int i;
    i = ++(h->heap_size);
    while ((i!=1)&&(item.key > h->heap[i/2].key)){
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

element delete_max_heap(HeapType* h)
{
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size){
        //?현재 노드의 자식노드 중 더 큰 자식노드를 찾는다.
        if((child<h->heap_size)&&
            (h->heap[child].key) < h->heap[child+1].key)
            child++;
        if (temp.key >= h->heap[child].key) break;
        //? 한 단계 아래로 이동
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

void heap_sort(element a[], int n)
{
    int i;
    HeapType* h;
    h= create();
    init(h);
    for(i=0; i<n; i++){
        insert_max_heap(h, a[i]);
    }
    for(i = (n-1); i>=0; i--){
        a[i] = delete_max_heap(h);
    }
    free(h);
}
#define SIZE 8
int main(void)
{
    element list[SIZE] = {23,56,11,9,56,99,27,34};
    heap_sort(list, SIZE);
    for(int i =0; i<SIZE; i++){
        printf("%d ", list[i].key);
    }
    printf("\n");

    return 0;  
}*/
//!프로그램 9.5 LPT Program
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct{
    int id;
    int avail;
}element;
typedef struct{
    element heap[MAX_ELEMENT];
    int heap_size;
}HeapType;

HeapType* Create()
{
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h)
{
    h->heap_size = 0;
}
//?현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
void insert_min_heap(HeapType* h, element item)
{
    int i;
    i = ++(h->heap_size);

    while ((i != 1) && (item.avail < h->heap[i/2].avail)){
        h->heap[i] = h->heap[i/2];
        i/=2;
    }
    h->heap[i] = item;
}

element delete_min_heap(HeapType* h)
{
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size){
        if((child < h->heap_size) &&
        (h->heap[child].avail) > h->heap[child + 1].avail)
        child++;
        if(temp.avail < h->heap[child].avail) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

#define JOBS 7
#define MACHINES 3

int main(void)
{
    int jobs[JOBS] = { 8,7,6,5,3,2,1};
    element m = {0,0};
    HeapType* h;
    h = Create();
    init(h);

    for(int i = 0; i<MACHINES; i++){
        m.id = i+1;
        m.avail = 0;
        insert_min_heap(h,m);
    }
    for(int i=0; i< JOBS; i++){
        m = delete_min_heap(h);
        printf("JOB %d을 시간=%d부터 시간=%d까지 기계 %d번에 해당한다. \n",
        i, m.avail, m.avail+jobs[i] - 1, m.id);
        m.avail += jobs[i];
        insert_min_heap(h, m);
    }
    return 0;
}

