#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>
void *runner(void *param);
int value;

int main()
{
    value = 0;
    pid_t pid;
    pthread_t tid;
    pthread_attr_t attr;
    pid = fork();
    if (pid == 0) {
        value++;
        pthread_attr_init(&attr);
        pthread_create(&tid, &attr, runner, NULL);
        pthread_join(tid, NULL);
        printf("pid: %d, A %d\n", getpid(), value);
        return 1;
    } else if (pid>0)
    {
        value++;
        wait(NULL);
        printf("pid: %d, B %d\n", getpid(), value);
    }
    return 0;
}


void *runner(void *param)
{
    printf("pid: %d, C %d\n", getpid(), value);
    value++;
    pthread_exit(0);
}