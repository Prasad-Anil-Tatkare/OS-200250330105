#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t id,fork_id,fork_ppid;
    printf("Before the fork\n");
    id = fork();
    printf("\nAfter the fork\n");
    //fork_id = getpid();
    //fork_ppid = getppid();
    printf("ID : %d\nPID : %d\n",id,getpid());
    printf("PPID : %d\n", getppid());

    return 0;
}