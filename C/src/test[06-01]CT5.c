//!선형큐 프로그램 5-1
/*#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct{
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q)
{
    q->rear = -1;
    q->front = -1;
}

void queue_print(QueueType *q)
{
    for (int i=0; i<MAX_QUEUE_SIZE; i++){
        if(i <= q->front || i> q->rear)
            printf("   | ");
        else
            printf("%d | ", q->data[i]);
    }
    printf("\n");
}

int is_full(QueueType *q)
{
    if (q->rear == MAX_QUEUE_SIZE -1)
        return 1;
    else
        return 0;
}

int is_empty(QueueType *q)
{
    if (q->rear == q->front)
        return 1;
    else
        return 0;
}

void enqueue(QueueType *q, int ITEM)
{
    if (is_full(q)){
        error("큐가 포화상태입니다.");
        return;
    }
    q->data[++(q->rear)] = ITEM;
}

int dequeue(QueueType *q)
{
    if (is_empty(q)){
        error("큐가 공백상태입니다.");
        return -1;
    }
    int ITEM = q->data[++(q->front)];
    return ITEM;
}

int main(void)
{
    int ITEM = 0;
    QueueType q;

    init_queue(&q);

    enqueue(&q, 10); queue_print(&q);
    enqueue(&q, 20); queue_print(&q);
    enqueue(&q, 30); queue_print(&q);

    ITEM = dequeue(&q); queue_print(&q);
    ITEM = dequeue(&q); queue_print(&q);
    ITEM = dequeue(&q); queue_print(&q);

    return 0;
}*/
//!원형큐 프로그램 5-2
/*
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct{
    int front, rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_Queue(QueueType *q)
{
    q->front = q->rear = 0;
}

int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}

int is_full(QueueType *q)
{
    return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType *q)
{
    printf("QUEUE(front = %d, rear = %d) = ", q->front, q->rear);
    if(!is_empty(q)){
        int i = q->front;
        do{
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        }while (i != q->front);
    }
    printf("\n");
}

void enqueue(QueueType *q, element ITEM)
{
    if(is_full(q))
        error("큐가 포화상태입니다.");
    else{
        q->rear = (q->rear +1)%MAX_QUEUE_SIZE;
        q->data[q->rear] = ITEM;
    }
}

element dequeue(QueueType *q)
{
    if(is_empty(q))
        error("큐가 공백상태입니다.");
    q->front = (q->front +1)%MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element peek(QueueType *q)
{
    if (is_empty(q))
        error("큐가 공백상태입니다.");
    return q->data[(q->front +1)%MAX_QUEUE_SIZE];
}

int main(void)
{
    QueueType queue;
    int element;

    init_Queue(&queue);
    printf("--데이터 추가 단계--\n");
    while (!is_full(&queue))
    {
        printf("정수를 입력하시오: ");
        scanf("%d", &element);
        enqueue(&queue, element);
        queue_print(&queue);
    }
    printf("큐는 포화상태입니다. \n\n");
    printf("--데이터 삭제 단계--\n");

    while (!is_empty(&queue))
    {
        element = dequeue(&queue);
        printf("꺼내진 정수: %d \n", element);
        queue_print(&queue);
    }
    printf("큐는 공백상태입니다. \n");
    return 0;
}*/
//!큐 응용 프로그램 5-3
/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct{
    int front, rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_Queue(QueueType *q)
{
    q->front = q->rear = 0;
}

int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}

int is_full(QueueType *q)
{
    return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType *q)
{
    printf("QUEUE(front = %d, rear = %d) = ", q->front, q->rear);
    if(!is_empty(q)){
        int i = q->front;
        do{
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        }while (i != q->front);
    }
    printf("\n");
}

void enqueue(QueueType *q, element ITEM)
{
    if(is_full(q))
        error("큐가 포화상태입니다.");
    else{
        q->rear = (q->rear +1)%MAX_QUEUE_SIZE;
        q->data[q->rear] = ITEM;
    }
}

element dequeue(QueueType *q)
{
    if(is_empty(q))
        error("큐가 공백상태입니다.");
    q->front = (q->front +1)%MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element peek(QueueType *q)
{
    if (is_empty(q))
        error("큐가 공백상태입니다.");
    return q->data[(q->front +1)%MAX_QUEUE_SIZE];
}

int main(void)
{
    QueueType queue;
    int element;

    init_Queue(&queue);
    srand(time(NULL));
    for(int i=0; i<100; i++){
        if(rand()%5 ==0){
            enqueue(&queue, rand()%100);
        }
        queue_print(&queue);
        if(rand()%10 ==0){
            int data = dequeue(&queue);
        }
        queue_print(&queue);
    }
    return 0;
}*/
//!원형 덱 프로그램 5-4
/*#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} DequeType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_deque(DequeType *q)
{
    q->front = q->rear = 0;
}

int is_empty(DequeType *q)
{
    return (q->front == q->rear);
}

int is_full(DequeType *q)
{
    return ((q->rear +1)%MAX_QUEUE_SIZE == q->front);
}

void deque_print(DequeType *q)
{
    printf("Deque(front = %d, rear = %d) = ", q->front, q->rear);
    if (!is_empty(q)){
        int i = q->front;
        do{
            i = (i+1)%(MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if(i==q->rear)
                break;
        }while (i!= q->front);
    }
    printf("\n");
}

void add_rear(DequeType *q, element ITEM)
{
    if(is_full(q))
        error("큐가 포화상태입니다. ");
    q->rear = (q->rear+1)%MAX_QUEUE_SIZE;
    q->data[q->rear+1] = ITEM;
}

element delete_front(DequeType *q)
{
    if(is_empty(q))
        error("큐가 공백상태입니다. ");
    q->front = (q->front+1)%MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element get_front(DequeType *q)
{
    if(is_empty(q))
        error("큐가 공백상태입니다");
    return q->data[(q->front+1)%MAX_QUEUE_SIZE];
}

void add_front(DequeType *q, element val)
{
    if(is_full(q))
        error("큐가 포화상태입니다.");
    q->data[q->front] = val;
    q->front = (q->front -1 + MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;
}

element delete_rear(DequeType *q)
{
    int prev = q->rear;
    if(is_empty(q))
        error("큐가 공백입니다.");
    q->rear = (q->rear -1 +MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;
    return q->data[prev];
}

element get_rear(DequeType *q)
{
    if(is_empty(q))
        error("큐가 공백상태입니다.");
    return q->data[q->rear];
}

int main(void)
{
    DequeType queue;
    init_deque(&queue);

    for(int i = 0; i<3; i++){
        add_front(&queue, i);
        deque_print(&queue);
    }
    for(int i =0; i<3; i++){
        delete_rear(&queue);
        deque_print(&queue);
    }
    return 0;
}*/
//!은행 서비스 시뮬레이션 프로그램 5-5
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 5
typedef struct{
    int id;
    int arrival_time;
    int service_time;
} element;
typedef struct{
    int front, rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_Queue(QueueType *q)
{
    q->front = q->rear = 0;
}

int is_empty(QueueType *q)
{
    return (q->front == q->rear);
}

int is_full(QueueType *q)
{
    return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType *q)
{
    printf("QUEUE(front = %d, rear = %d) = ", q->front, q->rear);
    if(!is_empty(q)){
        int i = q->front;
        do{
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        }while (i != q->front);
    }
    printf("\n");
}

void enqueue(QueueType *q, element ITEM)
{
    if(is_full(q))
        error("큐가 포화상태입니다.");
    else{
        q->rear = (q->rear +1)%MAX_QUEUE_SIZE;
        q->data[q->rear] = ITEM;
    }
}

element dequeue(QueueType *q)
{
    if(is_empty(q))
        error("큐가 공백상태입니다.");
    q->front = (q->front +1)%MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element peek(QueueType *q)
{
    if (is_empty(q))
        error("큐가 공백상태입니다.");
    return q->data[(q->front +1)%MAX_QUEUE_SIZE];
}

int main(void)
{
    int minutes = 60;
    int total_wait = 0;
    int total_customers =0;
    int service_time=0;
    int service_customer;
    QueueType queue;
    init_Queue(&queue);

    srand(time(NULL));
    for (int clock = 0; clock <minutes; clock++){
        printf("현재시각=%d\n", clock);
        if ((rand()%10)<3){
            element customer;
            customer.id = total_customers++;
            customer.arrival_time =clock;
            customer.service_time = rand()%3+1;
            enqueue(&queue, customer);
            printf("고객 %d이 %d분에 들어옵니다. 업무처리시간= %d분\n",
            customer.id, customer.arrival_time, customer.service_time);
        }
        if(service_time > 0){
            printf("고객 %d 업무처리중입니다. \n", service_customer);
            service_time--;
        }
        else{
            if(!is_empty(&queue)){
                element customer = dequeue(&queue);
                service_customer = customer.id;
                service_time = customer.service_time;
                printf("고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다 \n",
                    customer.id, clock, clock - customer.arrival_time);
                total_wait += clock - customer.arrival_time;
            }
        }
    }
    printf("전체 대기 시간 = %d분 \n", total_wait);
    return 0;
}