#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t id;
    printf("Before the fork\n");
    id = fork();
    printf("\nAfter the fork\n");

    if(0 == id){
        //Child Process
        printf("In child\n");
        printf("PID : %d\nPPID : %d\n",getpid(), getppid());
    }else{
        //Parent Process
        printf("In parent\n");
        printf("PID : %d\nPPID : %d\n",getpid(), getppid());
    }
    return 0;
}