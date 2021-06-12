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
#include <stdio.h>
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
}


