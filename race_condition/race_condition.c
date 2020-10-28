#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int count = 0;

void *inc_thread (void *arg){
    count++;
    printf("Inc Thread: %d\n",count);
}

void *dec_thread (void *arg){
    count--;
    printf("Dec Thread: %d\n",count);
}

int main(int argc, char const *argv[]){

    pthread_t tid;
    printf("Before thread creation.\n");
    pthread_create(&tid, NULL, thread, NULL);
    printf("After thread creation.\n");
    sleep(1);
    printf("After sleep creation.\n");

    return 0;
}