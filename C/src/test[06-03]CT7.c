//!원형 연결 리스트 처음에 삽입하는 함수 프로그램 7-1
/*ListNode* insert_first(ListNode* head, element data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    if(head == NULL){
        head = node;
        node->link = head;
    }
    else{
        node->link = head->link;
        head->link = node
    }
}*/
//! 원형연결리스트의 끝에 삽입하는 함수 프로그램 7-2
/*ListNode* insert_last(ListNode* head, element data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    if(head ==NULL){
        head = node;
        node->link = head;
    }
    else{
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}
*/
//! 원형 연결 리스트 테스트 프로그램 7-3
/*#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

void print_list(ListNode* head)
{
    ListNode* p;
    if(head == NULL) return;
    p = head->link;
    do{
        printf("%d->", p->data);
        p = p->link;
    }while(p!= head);
    printf("%d->", p->data);
}

ListNode* insert_first(ListNode* head, element data)
{
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if(head == NULL){
        head = node;
        node->link = head;
    }
    else{
        node->link = head->link;
        head->link = node;
    }
    return head;
}

ListNode* insert_last(ListNode* head, element data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    if(head == NULL){
        head = node;
        node->link = head;
    }
    else{
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

int main(void)
{
    ListNode *head = NULL;

    head = insert_last(head, 20);
    head = insert_last(head, 30);
    head = insert_last(head, 40);
    head = insert_first(head, 10);
    print_list(head);
    return 0;
}*/
//! mulitgame.c 프로그램 7-4
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct ListNode{
    element data;
    struct ListNode *link;
} ListNode;


ListNode* insert_first(ListNode* head, element data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    strcpy(node->data, data);
    if(head == NULL){
        head = node;
        node->link = head;
    }
    else{
        node->link = head->link;
        head->link = node;
    }
    return head;
}

int main(void)
{
    ListNode *head = NULL;

    head = insert_first(head, "KIM");
    head = insert_first(head, "PARK");
    head = insert_first(head, "CHOI");

    ListNode* p = head;
    for(int i = 0; i<10; i++){
        printf("현재 차례=%s \n",p->data);
        p = p->link;
    }
    return 0;
}*/
//! 이중 연결 리스트에서의 삽입함수 프로그램 7-5
/*void dinsert(DListNode *before, element data)
{
    DListNode *newnode = (DListNdoe *)malloc(sizeof(DlistNode));
    newnode->data = data;
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink=newnode;
    before->rlink = newnode;
}*/
//! 이중 연결 리스트에서의 삭제함수 프로그램 7-6
/*
//*노드 removed를 삭제한다.
void ddelete(DListNode* head, DListNode* removed)
{
    if(removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}*/
//! 이중 연결 리스트에서의 삭제함수 프로그램 7-7
/*#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode{
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
}DListNode;

void init(DListNode* phead)
{
    phead->llink = phead;
    phead->rlink = phead;
}

void print_dlist(DListNode* phead)
{
    DListNode *p;
    for (p = phead->rlink; p!= phead; p = p->rlink){
        printf("<-| |%d| |-> ", p->data);
    }
    printf("\n");
}

void dinsert(DListNode *before, element data)
{
    DListNode* newnode = (DListNode *)malloc(sizeof(DListNode));
    newnode ->data = data;
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed)
{
    if(removed == head)return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

int main(void)
{
    DListNode* head = (DListNode *)malloc(sizeof(DListNode));
    init(head);
    printf("추가 단계\n");
    for (int i = 0; i<5; i++){
        dinsert(head, i);
        print_dlist(head);
    }
    printf("\n삭제 단계\n");
    for (int i=0; i<5; i++){
        print_dlist(head);
        ddelete(head, head->rlink);
    }
    free(head);
    return 0;
}*/
