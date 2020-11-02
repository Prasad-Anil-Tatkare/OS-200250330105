#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t sem_printer;
int a,b;

void *thread1 (void *arg){
    sem_wait(&sem_printer);
    printf("T1: Printer is allocated to Thread 1.\n");
    sleep(15);
    printf("T1: Printer is deallocated to Thread 1.\n");
    sem_post(&sem_printer);
}

void *thread2 (void *arg){
    sem_wait(&sem_printer);
    printf("T2: Printer is allocated to Thread 2.\n");
    sleep(10);
    printf("T2: Printer is deallocated to Thread 2.\n");
    sem_post(&sem_printer);
}

void *thread3 (void *arg){
    sem_wait(&sem_printer);
    printf("T3: Printer is allocated to Thread 3.\n");
    sleep(10);
    printf("T3: Printer is deallocated to Thread 3.\n");
    sem_post(&sem_printer);
}

void *thread4 (void *arg){
    sem_wait(&sem_printer);
    printf("T4: Printer is allocated to Thread 4.\n");
    sleep(10);
    printf("T4: Printer is deallocated to Thread 4.\n");
    sem_post(&sem_printer);
}

int main(int argc, char const *argv[]){
    pthread_t tid1, tid2, tid3, tid4;
    sem_init(&sem_printer, 0, 3);
    //sem_init(, 0, 1);

    pthread_create(&tid1, NULL, thread1, NULL);
    pthread_create(&tid2, NULL, thread2, NULL);
    pthread_create(&tid3, NULL, thread3, NULL);
    pthread_create(&tid4, NULL, thread4, NULL);
    
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    pthread_join(tid4, NULL);
    sem_destroy(&sem_printer);
    //sem_destroy();
    return 0;
}