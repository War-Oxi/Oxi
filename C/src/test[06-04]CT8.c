//! 링크법으로 생성된 이진트리 프로그램 8-1
/*
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

int main(void)
{
    TreeNode *n1, *n2, *n3;
    n1 = (TreeNode *)malloc(sizeof(TreeNode));
    n2 = (TreeNode *)malloc(sizeof(TreeNode));
    n3 = (TreeNode *)malloc(sizeof(TreeNode));
    n1->data = 10;
    n1->left = n2;
    n1->right = n3;
    
    n2->data = 20;
    n2->left = NULL;
    n2->right = NULL;
    
    n3->data = 30;
    n3->left = NULL;
    n3->right = NULL;
    free(n1);free(n2);free(n3);
    
    return 0;
}*/
//! 이진트리의 3가지 순회방법 프로그램 8-2
/*
//*중위 순회
void inorder(TreeNode *root){
    if(root != NULL){
        inorder(root->left);            //?왼쪽서브트리 순회
        printf("[%d] ", root->data);    //?노드 방문
        inorder(root->right);           //?오른쪽서브트리 순회
    }
}
//*전위 순회
void preorder(TreeNode *root){
    if(root != NULL){
        printf("[%d] ", root->data);    //?노드 방문
        preorder(root->left);           //?왼쪽서브트리 순회
        preorder(root->right);          //?오른쪽서브트리 순회
    }
}
//*후위 순회
void postorder(TreeNode *root){
    if(root != NULL){
        preorder(root->left);           //?왼쪽서브트리 순회
        preorder(root->right);          //?오른쪽서브트리 순회
        printf("[%d] ", root->data);    //?노드 방문
    }
}*/
//! 링크법으로 생선된 이진트리 프로그램 8-3
/*
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL};
TreeNode n3 = { 16, NULL, NULL};
TreeNode n4 = { 25, NULL, NULL};
TreeNode n5 = { 20, &n3, &n4};
TreeNode n6 = { 15, &n2, &n5};
TreeNode *root = &n6;
//?중위
void inorder(TreeNode *root){
    if (root != NULL){
        inorder(root->left);
        printf("[%d] ", root->data);
        inorder(root->right);
    }
}
//?전위
void preorder(TreeNode *root){
    if (root != NULL){
        printf("[%d] ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
//?후위
void postorder(TreeNode *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("[%d] ", root->data);
    }
}
int main(void)
{
    printf("중위 순회=");
    inorder(root);
    printf("\n");

    printf("전위 순회=");
    preorder(root);
    printf("\n");    

    printf("후위 순회=");
    postorder(root);
    printf("\n");
    
    return 0;
}*/
//! 반복적인 순회 프로그램 8-4
/*
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

#define SIZE 100
int top = -1;
TreeNode *stack[SIZE];

void push(TreeNode *p)
{
    if(top<SIZE -1)
        stack[++top] =p;
}

TreeNode *pop()
{
    TreeNode *p = NULL;
    if(top>=0)
        p=stack[top--];
    return p;
}

void inorder_iter(TreeNode *root)
{
    while (1){
        for(; root; root = root->left)
            push(root);
        root=pop();
        if(!root)break;
        printf("[%d] ", root->data);
        root = root->right;
    }
}

TreeNode n1 = { 1, NULL, NULL};
TreeNode n2 = { 4, &n1, NULL};
TreeNode n3 = { 16, NULL,NULL};
TreeNode n4 = { 25, NULL, NULL};
TreeNode n5 = { 20, &n3, &n4};
TreeNode n6 = { 15, &n2, &n5};
TreeNode *root = &n6;
int main(void)
{
    printf("중위 순회=");
    inorder_iter(root);
    printf("\n");

    return 0;
}
*/
//! 레벨 순회 프로그램 8-5
/*
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

#define MAX_QUEUE_SIZE 100
typedef TreeNode * element;
typedef struct{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q)
{
    q->front = q->rear = 0;
}

int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}

int is_full(QueueType *q)
{
    return ((q->rear +1)%MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, element item)
{
    if(is_full(q))
        error("큐가 포화상태입니다");
    q->rear = (q->rear +1)%MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q)
{
    if(is_empty(q))
        error("큐가 공백상태입니다.");
    q->front = (q->front +1)%MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void level_order(TreeNode *ptr)
{
    QueueType q;
    init_queue(&q);
    if(ptr==NULL)return;
    enqueue(&q, ptr);
    while (!is_empty(&q)){
        ptr = dequeue(&q);
        printf(" [%d] ", ptr->data);
        if(ptr->left)
            enqueue(&q, ptr->left);
        if(ptr->right)
            enqueue(&q, ptr->right);
    }
}

TreeNode n1 = {1,NULL,NULL};
TreeNode n2 = {4,&n1,NULL};
TreeNode n3 = {16,NULL,NULL};
TreeNode n4 = {25,NULL,NULL};
TreeNode n5 = {20,&n3,&n4};
TreeNode n6 = {15,&n2,&n5};
TreeNode *root = &n6;

int main(void)
{
    printf("레벨 순회=");
    level_order(root);
    printf("\n");
    return 0;
}*/
//! 수식 트리 계산 프로그램 8-6
/*
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, NULL, NULL};
TreeNode n3 = {'*', &n1, &n2};
TreeNode n4 = {16, NULL,NULL};
TreeNode n5 = {25, NULL,NULL};
TreeNode n6 = {'+', &n4, &n5};
TreeNode n7 = {'+', &n3, &n6};
TreeNode *exp = &n7;

int evaluate(TreeNode *root)
{
    if(root==NULL)
        return 0;
    if(root->left ==NULL && root->right == NULL)
        return root->data;
    else{
        int op1 = evaluate(root->left);
        int op2 = evaluate(root->right);
        printf("%d %c %d을 계산합니다.\n", op1, root->data, op2);
        switch(root->data){
        case '+':
            return op1+op2;
        case '-':
            return op1 -op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
        }
    }
    return 0;
}

int main(void)
{
    printf("수식의 값은 %d입니다. \n", evaluate(exp));
    return 0;
}*/
//! 디렉토리 용량 계산 프로그램 8-7
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

int calc_dir_size(TreeNode *root)
{
    int left_size, right_size;
    if(root==NULL) return 0;

    left_size = calc_dir_size(root->left);
    right_size = calc_dir_size(root->right);
    return (root->data + left_size + right_size);
}

int main(void)
{
    TreeNode n4 = {500, NULL,NULL};
    TreeNode n5 = {200, NULL, NULL};
    TreeNode n3 = {100, &n4, &n5};
    TreeNode n2 = {50 , NULL, NULL};
    TreeNode n1 = {0, &n2, &n3};

    printf("디렉토리의 크기 = %d\n", calc_dir_size(&n1));
}*/
//! 스레드 이진 트리 순회 프로그램 8-8
/*#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
    int is_thread;
} TreeNode;

TreeNode n1 = { 'A', NULL, NULL, 1};
TreeNode n2 = { 'B', NULL, NULL, 1};
TreeNode n3 = { 'C', &n1, &n2, 0};
TreeNode n4 = { 'D', NULL, NULL, 1};
TreeNode n5 = { 'E', NULL, NULL, 0};
TreeNode n6 = { 'F', &n4, &n5, 0};
TreeNode n7 = { 'G', &n3, &n6, 0};
TreeNode * exp = &n7;

TreeNode * find_successor(TreeNode *p)
{
    //? q는 p의 오른쪽 포인터
    TreeNode *q = p->right;
    //? 만약 오른쪽 포인터가 NULL이거나 스레드이면 오른쪽 포인터를 반환
    if (q == NULL || p->is_thread == TRUE)
        return q;
    //? 만약 오른쪽 자식이면 다시 가장 왼쪽 노드로 이동
    while (q->left != NULL) q = q->left;
    return q;
}

void thread_inorder(TreeNode * t)
{
    TreeNode * q;

    q=t;
    while(q->left)q = q->left;
    do{
        printf("%c -> ", q->data);
        q = find_successor(q);
    }while(q);
}
int main(void)
{
    //?스레드 설정
    n1.right = &n3;
    n2.right = &n7;
    n4.right = &n6;
    //?중위 순회
    thread_inorder(exp);
    printf("\n");
    return 0;
}*/
//! 순환적인 탐색함수 프로그램 8-9
/*TreeNode * search(TreeNode * node, int key)
{
    if(key == NULL) return NULL;
    if(key == node->key) return node;
    else if(key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}*/
//! 반복적인 탐색함수 프로그램 8-10
/*TreeNode * search(TreeNode * node, int key)
{
    while(node!=NULL){
        if(key==node->key)return node;
        else if(key < node->key)
            node = node->left;
        else
            node=node->right;
    }   
    return NULL;
}*/
//! 이진트리 삽입 프로그램 8-11
/*TreeNode * insert_node(TreeNode * node, int key)
{
    //?트리가 공백이면 새로운 노드를 반환한다.
    if (node == NULL)reutrn new_node(key);
    //?그렇지 않으면 순환적으로 트리를 내려간다.
    if(key<node->key)
        node->left = insert_node(node->left, key);
    else if(key> node->key)
        node->right = insert_node(node->right, key);
    //? 변경된 루트 포인터를 반환한다.
    return node;    
}*/
//! 이진 탐색 트리에서의 삭제 함수 프로그램 8-12
/*//?이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고
//?새로운 루트 노드를 반환한다.
TreeNode * delete_node(TreeNode * root, int key)
{
    if(root==NULL) return root;
    //?만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
    if(key < root->key)
        root->left = delete_node(root->left, key)
    //? 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
    else if(key > root->key)
        root->right = delete_node(root->right, key);
    //?키가 루트와 같으면 이 노드 삭제
    else{
        //?첫 번째나 두 번째 경우
        if(root->left == NULL){
            TreeNode * temp = root->left;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            TreeNode * temp = root->left;
            free(root);
            return temp;
        }
        //?세 번째 경우
        TreeNode *temp = min_value_node(root->right);
        //?중외 순회시 후계 노드를 복사한다.
        root->key = temp->key;
        //?중외 순회시 후계 노드를 삭제한다.
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}
TreeNode * min_value_node(TreeNode * node)
{
    TreeNode * current = node;
    //?맨 왼쪽 단말 노드를 찾으러 내려감
    while(current->left != NULL)
        current = current->left;
    return current
}*/
//! 이진 탐색 트리 프로그램 8-13
/*#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct TreeNode {
    element key;
    struct TreeNode *left, *right;
}TreeNode;
//?순환적인 탐색 함수
TreeNode * search(TreeNode * node, int key)
{
    if(node == NULL) return NULL;
    if(key == node->key) return node;
    else if(key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

TreeNode * new_node(int item)
{
    TreeNode * temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;    
}

TreeNode * insert_node(TreeNode * node, int key)
{
    //?트리가 공백이면 새로운 노드를 반환한다.
    if(node ==NULL) return new_node(key);
    //?그렇지 않으면 순환적으로 트리를 내려간다.
    if(key < node->key)
        node->left = insert_node(node->left, key);
    else if(key > node->key)
        node->right = insert_node(node->right, key);
    //?변경된 루트 포인터를 반환한다.
    return node;
}

TreeNode * min_value_node(TreeNode * node)
{
    TreeNode * current = node;
    //?맨 왼쪽 단말 노드를 찾으러 내려감
    while(current->left != NULL)
        current = current->left;

    return current;
}
//?이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고
//?새로운 루트 노드를 반환한다.
TreeNode * delete_node(TreeNode * root, int key)
{
    if(root==NULL)return root;
    //?만약 키가 루트보다 작으면 왼쪽 서브 트리에 있음.
    if(key <root->key)
        root->left = delete_node(root->left, key);
    //?키가 루트보다 크면 오른쪽 서브 트리에 있음
    else if(key > root->key)
        root->right = delete_node(root->right, key);
    //?키가 루트와 같으면 이 노드를 삭제
    else{
        //?첫번째나 두번째 경우
        if(root->left==NULL){
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        //?세 번째 경우
        TreeNode * temp = min_value_node(root->right);
        //?중외 순회시 후계 노드를 복사한다.
        root->key = temp -> key;
        //?중외 순회시 후계 노드를 삭제한다
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}
//?중위 순회
void inorder(TreeNode * root){
    if(root){
        inorder(root->left);
        printf("[%d] ", root->key);
        inorder(root->right);
    }
}
int main(void)
{
    TreeNode * root = NULL;
    TreeNode * tmp = NULL;

    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 10);
    root = insert_node(root, 40);
    root = insert_node(root, 50);
    root = insert_node(root, 60);

    printf("이진 탐색 트리 중위 순회 결과 \n");
    inorder(root);
    printf("\n\n");
    if(search(root, 30)!= NULL)
        printf("이진 탐색 트리에서 30을 발견함\n");
    else
        printf("이진 탐색 트리에서 30을 발견못함\n");
    return 0;
}*/
//!이진 탐색 트리를 이용한 영어 사전 프로그램 프로그램 8.14
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 200

typedef struct{
    char word[MAX_WORD_SIZE];
    char meaning[MAX_MEANING_SIZE];
}element;

typedef struct TreeNode {
    element key;
    struct TreeNode *left, *right;
} TreeNode;

int compare(element e1, element e2)
{
    return strcmp(e1.word, e2.word);
}
void display(TreeNode *p)
{
    if(p!= NULL){
        printf("\n");
        display(p->left);
        printf("%s:%s", p->key.word, p->key.meaning);
        display(p->right);
        printf("\n");
    }
}
TreeNode * search(TreeNode * root, element key)
{
    TreeNode * p = root;
    while(p!=NULL){
        if(compare(key, p->key)==0) return p;
        else if(compare(key, p->key) < 0)
            p = p->left;
        else if(compare(key, p->key) > 0)
            p= p->right;
    }   
    return p;
}
TreeNode * new_node(element item)
{
    TreeNode * temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;    
}
TreeNode * insert_node(TreeNode * node, element key)
{
    if(node ==NULL) return new_node(key);
    if(compare(key, node->key)<0)
        node->left = insert_node(node->left, key);
    else if(compare(key, node->key)>0)
        node->right = insert_node(node->right, key);
    return node;
}
TreeNode * min_value_node(TreeNode * node)
{
    TreeNode * current = node;
    while(current->left != NULL)
        current = current->left;
    return current;
}
TreeNode * delete_node(TreeNode * root, element key)
{
    if(root==NULL)return root;
    if(compare(key, root->key)<0)
        root->left = delete_node(root->left, key);
    else if(compare(key, root->key)>0)
        root->right = delete_node(root->right, key);
    else{
        if(root->left==NULL){
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        TreeNode * temp = min_value_node(root->right);
        root->key = temp -> key;
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

void help()
{
    printf("\n**** i: 입력, d: 삭제, s: 탐색, p: 출력, q: 종료 ****: ");
}

int main(void)
{
    char command;
    element e;
    TreeNode * root = NULL;
    TreeNode * tmp;

    do{
        help();
        command = getchar();
        getchar();
        switch(command){
        case 'i':
            printf("단어:");
            gets(e.word);
            printf("의미:");
            gets(e.meaning);
            root = insert_node(root, e);
            break;
        case 'd':
            printf("단어:");
            gets(e.word);
            root=delete_node(root,e);
            break;
        case 'p':
            display(root);
            printf("\n");
            break;
        case 's':
            printf("단어:");
            gets(e.word);
            tmp = search(root, e);
            if(tmp != NULL)
                printf("의미:%s\n", e.meaning);
            break;
        }
    }while (command != 'q');
    return 0;
}