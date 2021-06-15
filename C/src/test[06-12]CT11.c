//!프로그램 11-8 kruskal의 최소 비용 신장 트리 프로그램
/*#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];

void set_init(int n)
{
    for(int i=0; i<n; i++)
        parent[i] = -1;
}
//?curr가 속하는 집합을 반환한다.
int set_find(int curr)
{
    if (parent[curr] == -1)
        return curr;
    while(parent[curr] != -1) curr =parent[curr];
    return curr;
}
//?두개의 원소가 속한 집합을 합친다.
void set_union(int a, int b)
{
    int root1 = set_find(a);
    int root2 = set_find(b);
    if(root1 != root2)
        parent[root1] = root2;
}
struct Edge{ //?간선을 나타내는 구조체
    int start, end, weight;
};
typedef struct GraphType{
    int n;
    struct Edge edges[2 * MAX_VERTICES];
}GraphType;
//?그래프 초기화
void graph_init(GraphType* g){
    g->n = 0;
    for(int i =0; i < 2*MAX_VERTICES; i++){
        g->edges[i].start = 0;
        g->edges[i].end = 0;
        g->edges[i].weight = INF;
    }
}
//?간선 삽입 연산
void insert_edge(GraphType* g, int start, int end, int w){
    g->edges[g->n].start = start;
    g->edges[g->n].end = end;
    g->edges[g->n].weight = w;
    g->n++;
}
//?qsort()에 사용되는 함수
int compare(const void* a, const void* b){
    struct Edge* x = (struct Edge*)a;
    struct Edge* y = (struct Edge*)b;
    return (x->weight - y->weight);
}
//?kruskal의 최소 비용 신장 트리 프로그램
void kruskal(GraphType *g){
    int edge_accepted = 0;
    int uset, vset;
    struct Edge e;

    set_init(g->n);
    qsort(g->edges, g->n, sizeof(struct Edge), compare);

    printf("크루스칼 최소 신장 트리 알고리즘 \n");
    int i = 0;
    while (edge_accepted<(g->n-1)){
        e = g->edges[i];
        uset = set_find(e.start);
        vset = set_find(e.end);
        if(uset != vset){
            printf("간선 (%d,%d) %d 선택\n", e.start, e.end, e.weight);
            edge_accepted++;
            set_union(uset, vset);
        }
        i++;
    }
}
int main(void)
{
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    graph_init(g);

    insert_edge(g, 0, 1, 29);
    insert_edge(g, 1, 2, 16);
    insert_edge(g, 2, 3, 12);
    insert_edge(g, 3, 4, 22);
    insert_edge(g, 4, 5, 27);
    insert_edge(g, 5, 0, 10);
    insert_edge(g, 6, 1, 15);
    insert_edge(g, 6, 3, 18);
    insert_edge(g, 6, 4, 25);

    kruskal(g);
    free(g);
    return 0;
}*/
//!프로그램 11-9 Prim의 최소 비용 신장 트리 프로그램
/*#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType{
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];
//?최소 dist[v]값을 갖는 정점을 반환
int get_min_vertex(int n)
{
    int v, i;
    for(i=0; i<n; i++)
        if(!selected[i]){
            v=i;
            break;
        }
    for(i=0; i<n; i++)
        if(!selected[i]&&(distance[i]<distance[v])) 
            v = i;
    return (v);
}
//?
void prim(GraphType* g, int s)
{
    int i,u,v;
    for(u=0; u<g->n; u++)
        distance[u] = INF;
    distance[s] = 0;
    for(i=0; i<g->n; i++){
        u = get_min_vertex(g->n);
        selected[u] = TRUE;
        if(distance[u]==INF) return;
        printf("정점 %d 추가\n", u);
        for(v=0; v<g->n; v++)
            if(g->weight[u][v]!=INF)
                if(!selected[v]&&g->weight[u][v]< distance[v])
                    distance[v] = g->weight[u][v];
    }
}
int main(void)
{
    GraphType g = { 7,
    {{ 0, 29, INF, INF, INF, 10, INF},
    { 29, 0, 16, INF, INF, INF, 15},
    {INF, 16, 0, 12, INF, INF, INF},
    {INF, INF, 12, 0, 22, INF, 18},
    {INF, INF, INF, 22, 0, 27, 25},
    {10, INF, INF, INF, 27, 0, INF},
    {INF, 15, INF, 18, 25, INF, 0}}
    };
    prim(&g, 0);
    return 0;
}*/
//!프로그램 11-10 최단 경로 Dijkstra 프로그램
/*
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType{
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

int choose(int distance[], int n, int found[])
{
    int i, min, minpos;
    minpos = -1;
    for(i=0; i<n; i++)
        if(distance[i]<min && !found[i]){
            min = distance[i];
            minpos = i;
        }
    return minpos;
}
void print_status(GraphType* g)
{
    static int step=1;
    printf("STEP %d: ", step++);
    printf("distance: ");
    for (int i = 0; i< g->n; i++){
        if(distance[i] == INF)
            printf(" * ");
        else
            printf("2%d ", distance[i]);
    }
    printf("\n");
    printf(" found: ");
    for(int i=0; i<g->n; i++)
        printf("%2d ", found[i]);
    printf("\n\n");
}

void shortest_path(GraphType* g, int start)
{
    int i, u, w;
    for(i=0; i<g->n; i++)
    {
        distance[i] = g->weight[start][i];
        found[i] = FALSE;
    }
    found[start] = TRUE;
    distance[start] = 0;
    for (i=0; i<g->n-1; i++){
        print_status(g);
        u = choose(distance, g->n, found);
        found[u] = TRUE;
        for(w=0; w<g->n; w++)
            if(!found[w])
                if(distance[u] + g->weight[u][w]<distance[w])
                    distance[w] = distance[u] + g->weight[u][w];
    }
}

int main(void)
{
    GraphType g = {7,
    {{0,7,INF,INF,3,10,INF},
    {7,0,4,10,2,6,INF},
    {INF,4,0,2,INF,INF,INF},
    {INF,10,2,0,11,9,4},
    {3,2,INF,11,0,INF,5},
    {10,6,INF,9,INF,0,INF},
    {INF,INF,INF,4,5,INF,0}}
    };
    shortest_path(&g, 0);
    return 0;
}*/
//!프로그램 11.11 Floyd의 최단 경로 프로그램
/*#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType{
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;
int A[MAX_VERTICES][MAX_VERTICES];
void printA(GraphType *g)
{
    int i,j;
    printf("======================================\n");
    for(i=0;i<g->n;i++){
        for(j=0; j<g->n; j++){
            if(A[i][j] == INF)
                printf(" * ");
            else printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
    printf("======================================\n");
}

void floyd(GraphType* g)
{
    int i,j,k;
    for(i=0;i<g->n;i++)
        for(j=0; j<g->n; j++)
            A[i][j] = g->weight[i][j];
    printA(g);

    for(k=0; k<g->n; k++){
        for(i=0; i<g->n; i++)
            for(j=0; j<g->n; j++)
                if(A[i][k]+A[k][j]<A[i][j])
                    A[i][j] = A[i][k] + A[k][j];
        printA(g);
    }
}
int main(void)
{
    GraphType g = {7,
    {{0,7,INF,INF,3,10,INF},
    {7,0,4,10,2,6,INF},
    {INF,4,0,2,INF,INF,INF},
    {INF,10,2,0,11,9,4},
    {3,2,INF,11,0,INF,5},
    {10,6,INF,9,INF,0,INF},
    {INF,INF,INF,4,5,INF,0}}
    };
    floyd(&g);
    return 0;
}*/
//!프로그램 11-13 그래프 위상 정렬 전체 프로그램
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphNode{
    int vertex;
    struct GraphNode *link;
}GraphNode;

typedef struct GraphType{
    int n;
    GraphNode *adj_list[MAX_VERTICES];
}GraphType;

void graph_init(GraphType *g){
    int v;
    g->n = 0;
    for (v=0; v<MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}

void insert_vertex(GraphType *g, int v)
{
    if(((g->n)+1)>MAX_VERTICES){
        fprintf(stderr, "그래프 : 정점의 개수 초과");
        return;
    }
    g->n++;
}

void insert_edge(GraphType *g, int u, int v){
    GraphNode *node;
    if(u>=g->n || v>= g->n){
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    node = (GraphNode *)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct{
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;

void init(StackType *s){
    s->top = -1;
}

int is_empty(StackType *s){
    return(s->top==-1);
}

int is_full(StackType *s){
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item)
{
    if(is_full(s)){
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else s->stack[++(s->top)] = item;
}

element pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->stack[(s->top)--];
}

int topo_sort(GraphType *g)
{
    int i;
    StackType s;
    GraphNode *node;

    int *in_degree = (int *)malloc(g->n *sizeof(int));
    for (i=0; i<g->n; i++)
        in_degree[i] = 0;
    for (i=0; i<g->n; i++){
        GraphNode *node = g->adj_list[i];
        while (node!=NULL){
            in_degree[node->vertex]++;
            node = node->link;
        }
    }
    init(&s);
    for(i=0; i<g->n; i++){
        if(in_degree[i] == 0) push(&s, i);
    }
    while(!is_empty(&s)){
        int w;
        w = pop(&s);
        printf("정점 %d ->", w);
        node = g->adj_list[w];
        while (node != NULL){
            int u = node ->vertex;
            in_degree[u]--;
            if(in_degree[u] == 0) push(&s, u);
            node = node ->link;
        }
    }
    free(in_degree);
    printf("\n");
    return (i == g->n);
}

int main(void)
{
    GraphType g;

    graph_init(&g);
    insert_vertex(&g,0);
    insert_vertex(&g,1);
    insert_vertex(&g,2);
    insert_vertex(&g,3);
    insert_vertex(&g,4);
    insert_vertex(&g,5);

    insert_edge(&g, 0, 2);
    insert_edge(&g, 0, 3);

    insert_edge(&g, 1, 3);
    insert_edge(&g, 1, 4);

    insert_edge(&g, 2, 3);
    insert_edge(&g, 2, 5);

    insert_edge(&g, 3, 5);

    insert_edge(&g, 4, 5);

    topo_sort(&g);

    return 0;
}
