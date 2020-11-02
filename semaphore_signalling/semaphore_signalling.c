#include <stdio.h>
#include <pthread.h>
//#include <unistd.h>
#include <semaphore.h>

sem_t ip2proc,proc2ip;
int a,b;

void *input_thread (void *arg){
    while(1){

        sem_wait(&proc2ip);
        printf("T1: Getting signal from processing thread.\n");
        scanf("%d %d",&a, &b);
        printf("T1: Sending signal to processing thread.\n");
        sem_post(&ip2proc);
    }
}

void *output_thread (void *arg){
    while(1){
        
        sem_wait(&ip2proc);
        printf("T2: Getting signal from input thread.\n");
        printf("Sum: %d\n",a+b);
        printf("T2: Sending signal to input thread.\n");
        sem_post(&proc2ip);
        }

}

int main(int argc, char const *argv[]){

    pthread_t input_tid, output_tid;
    sem_init(&ip2proc, 0, 0);
    sem_init(&proc2ip, 0, 1);

    pthread_create(&input_tid, NULL, input_thread, NULL);
    pthread_create(&output_tid, NULL, output_thread, NULL);

    pthread_join(input_tid, NULL);
    pthread_join(output_tid, NULL);
    sem_destroy(&ip2proc);
    sem_destroy(&proc2ip);
    return 0;
}