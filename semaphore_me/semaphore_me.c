#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t count_sem;
int count = 0;

void *inc_thread (void *arg){
    while(1){
        sem_wait(&count_sem);
        count++;
        printf("Inc Thread: %d\n",count);
        sem_post(&count_sem);
    }
}

void *dec_thread (void *arg){
    while(1){
        sem_wait(&count_sem);
        count--;
        printf("Dec Thread: %d\n",count);
        sem_post(&count_sem);
    }
}

int main(int argc, char const *argv[]){

    pthread_t inc_tid, dec_tid;
    sem_init(&count_sem, 0, 1);

    pthread_create(&inc_tid, NULL, inc_thread, NULL);
    pthread_create(&dec_tid, NULL, dec_thread, NULL);
    
    pthread_join(inc_tid, NULL);
    pthread_join(dec_tid, NULL);
    sem_destroy(&count_sem);
    return 0;
}