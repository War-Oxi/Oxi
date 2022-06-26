//!프로그램 10.1 adg_mat.c
/*#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50
typedef struct GraphType
{
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;
//?그래프 초기화
void init(GraphType* g)
{
    int r, c;
    g->n = 0;
    for(r = 0; r<MAX_VERTICES; r++)
        for(c = 0; c<MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
}
//?정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
    if(((g->n) +1)> MAX_VERTICES){
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}
//?간선 삽입 연산
void insert_edge(GraphType* g, int start, int end)
{
    if(start>=g->n || end >= g->n){
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}
//?인접 행렬 출력 함수
void print_adj_mat(GraphType* g)
{
    for (int i=0; i< g->n; i++){
        for (int j = 0; j < g->n; j++){
            printf("%2d ", g->adj_mat[i][j]);
        }
        printf("\n");    
    }
}
void main()
{
    GraphType *g;
    g=(GraphType*)malloc(sizeof(GraphType));
    init(g);
    for(int i=0; i<4; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2 ,3);
    print_adj_mat(g);

    free(g);
}*/
//!프로그램 10-2 adg_list.c
/*#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphNode{
    int vertex;
    struct GraphNode* link;
} GraphNode;
typedef struct GraphType{
    int n; //? 정점의 개수
    GraphNode* adj_list[MAX_VERTICES];
}GraphType;
//?그래프 초기화
void init(GraphType* g)
{
    int v;
    g->n = 0;
    for(v = 0; v<MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}
//?정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
    if(((g->n)+1)>MAX_VERTICES){
        fprintf(stderr, "그래프: 정점 개수 초과");
        return;
    }
    g->n++;
}
//?간선 삽입 연산, v를 u의 인접리스트에 삽입한다.
void insert_edge(GraphType* g, int u, int v)
{
    GraphNode* node;
    if(u>= g->n || v>= g->n){
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

void print_adj_list(GraphType* g)
{
    for (int i = 0; i<g->n; i++){
        GraphNode* p = g->adj_list[i];
        printf("정점 %d의 인접 리스트 ", i);
        while (p!=NULL){
            printf("-> %d ", p->vertex);
            p = p->link;
        }
        printf("\n");
    }
}

int main()
{
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    init(g);
    for(int i=0;i<4;i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 1);
    insert_edge(g, 1, 0);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 0);
    insert_edge(g, 0 ,3);
    insert_edge(g, 3 ,0);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 3, 2);
    print_adj_list(g);
    free(g);
    return 0;
}*/
//!프로그램 10-3 인접 배열로 표현된 그래프에 대한 깊이우선탐색 프로그램
/*
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
typedef struct GraphType{
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;
int visited[MAX_VERTICES];
//? 그래프 초기화
void init(GraphType* g)
{
    int r, c;
    g->n = 0;
    for(r=0; r<MAX_VERTICES; r++)
        for (c=0;c<MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
}
//?정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
    if(((g->n)+1)>MAX_VERTICES){
        fprintf(stderr, "그래프: 정점 개수 초과");
        return;
    }
    g->n++;
}
//?간선 삽입 연산
void insert_edge(GraphType* g, int start, int end)
{
    if(start>= g->n || end>= g->n){
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}
//?인접 행렬로 표현된 그래프에 대한 깊이 우선 탐색
void dfs_mat(GraphType* g, int v)
{
    int w;
    visited[v] = TRUE;
    printf("정점 %d -> ", v);
    for(w=0; w<g->n; w++)
        if(g->adj_mat[v][w]&&!visited[w])
            dfs_mat(g, w); //?정점 w에서 DFS 새로 시작
}
int main(void)
{
    GraphType *g;
    g=(GraphType*)malloc(sizeof(GraphType));
    init(g);
    for(int i=0; i<4; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);

    printf("깊이 우선 탐색\n");
    dfs_mat(g, 0);
    printf("\n");
    free(g);
    return 0;
}*/
//!프로그램 10-5 너비 우선 탐색(인접 행렬 표현)프로그램
/*#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;
//?오류 함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}
//?큐 초기화
void queue_init(QueueType *q)
{
    q->front = q->rear = 0;
}
//? 공백 상태 검출 함수
int is_empty(QueueType *q)
{
    return(q->front==q->rear);
}
//?포화 상태 검출 함수
int is_full(QueueType *q)
{
    return((q->rear +1)%MAX_QUEUE_SIZE == q->front);
}
//?삽입 함수
void enqueue(QueueType *q, element item)
{
    if(is_full(q))
        error("큐가 포화상태입니다.");
    q->rear = (q->rear +1)%MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}
//?삭제 함수
element dequeue(QueueType *q)
{
    if(is_empty(q))
        error("큐가 공백상태입니다.");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}
#define MAX_VERTICES 50
typedef struct GraphType{
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;
int visited[MAX_VERTICES];
//?그래프 초기화
void graph_init(GraphType *g)
{
    int r, c;
    g->n = 0;
    for (r=0; r<MAX_VERTICES; r++)
        for(c=0; c<MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
}
//?정점 삽입 연산
void insert_vertex(GraphType *g, int v)
{
    if(((g->n)+1)>MAX_VERTICES){
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}
//?간선 삽입 연산
void insert_edge(GraphType* g, int start, int end)
{
    if(start >= g->n|| end >= g->n){
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}
void bfs_mat(GraphType* g, int v)
{
    int w;
    QueueType q;

    queue_init(&q);
    visited[v] = TRUE;
    printf("%d 방문 ->", v);
    enqueue(&q, v);
    while (!is_empty(&q)){
        v = dequeue(&q);
        for(w=0; w<g->n; w++)
            if(g->adj_mat[v][w] && !visited[w]){
                visited[w] = TRUE;
                printf("%d 방문 ->", w);
                enqueue(&q, w);
            }
    }
}


int main(void)
{
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    graph_init(g);
    for(int i=0; i<6; i++)
        insert_vertex(g,i);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 0, 4);
    insert_edge(g, 4, 5);
    insert_edge(g, 1, 5);

    printf("너비 우선 탐색\n");
    bfs_mat(g, 0);
    printf("\n");
    free(g);
    return 0;
}*/
//!프로그램 10-6 너비 우선 탐색(인접리스트)
/*void bts_list(GraphType *g, int v)
{
    GraphNode* w;
    QueueType q;

    init(&q); //? 큐 초기화
    visited[v]=TRUE; //? 정점 v 방문표시
    printf("%d방문 -> ",v);
    enqueue(&q, v); //? 시작 정점을 큐에 저장
    while(!is_empty(&q)){
        v = dequeue(&q); //? 큐에 저장된 정점 선택
        for(w = g->adj_list[v]; w; w = w->link) //? 인접 정점 탐색
            if(!visited[w->vertex]){ //? 미방문 정점 탐색
                visited[w->vertex] = TRUE; //? 방문 표시
                printf("%d 방문 ->", w->vertex);
                enqueue(&q, w->vertex);  //? 정점을 큐에 삽입
            }
    }
}*/

