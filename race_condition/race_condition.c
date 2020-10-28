#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int count = 0;

void *inc_thread (void *arg){
    while(1){
        count++;
        printf("Inc Thread: %d\n",count);
    }
}

void *dec_thread (void *arg){
    while(1){
        count--;
        printf("Dec Thread: %d\n",count);
    }
}

int main(int argc, char const *argv[]){

    pthread_t inc_tid, dec_tid;

    pthread_create(&inc_tid, NULL, inc_thread, NULL);
    pthread_create(&dec_tid, NULL, dec_thread, NULL);
    
    pthread_join(inc_tid, NULL);
    pthread_join(dec_tid, NULL);
    
    return 0;
}