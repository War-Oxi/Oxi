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