#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int count = 0;
pthread_mutex_t count_mutex;

void *inc_thread (void *arg){
    while(1){

        pthread_mutex_lock(&count_mutex);
        //Accessing Critical Section
        count++;
        printf("Inc Thread: %d\n",count);
        pthread_mutex_unlock(&count_mutex);

    }
}

void *dec_thread (void *arg){
    while(1){

        pthread_mutex_lock(&count_mutex);
        //Accessing Critical Section
        count--;
        printf("Dec Thread: %d\n",count);
        pthread_mutex_unlock(&count_mutex);

    }
}

int main(int argc, char const *argv[]){

    pthread_t inc_tid, dec_tid;
    pthread_mutex_init(&count_mutex, NULL);

    pthread_create(&inc_tid, NULL, inc_thread, NULL);
    pthread_create(&dec_tid, NULL, dec_thread, NULL);
    
    pthread_join(inc_tid, NULL);
    pthread_join(dec_tid, NULL);
    pthread_mutex_destroy(&count_mutex);
    
    return 0;
}