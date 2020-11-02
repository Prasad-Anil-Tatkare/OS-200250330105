#include <stdio.h>
#include <unistd.h>


int main(int argc, char const *argv[]){
    pid_t id;

    id = fork();
    if(0 == id){
        //Child
        printf("Child started\n");
        sleep(5);
        printf("Child exited\n");
    }else{

        printf("Parent started\n");
        sleep(2);
        printf("Parent exited\n");
    }

    return 0;
}