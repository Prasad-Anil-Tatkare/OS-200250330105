#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]){

    pid_t id;
    int pfd1[2],pfd2[2];     //Array of two integers
    pipe(pfd1);      //Pipe is created
    pipe(pfd2);

    id = fork();         //Child process is created using fork
    if(0 == id){
        //Child Process
        int val1,val2,sum;
        
        read(pfd1[0],&val1,sizeof(val1));
        read(pfd1[0],&val2,sizeof(val2));
        sum = val1 + val2;
        printf("In Child received values are : %d\t%d\n",val1,val2);
        write(pfd2[1],&sum,sizeof(sum));
        close(pfd1[0]);
        close(pfd2[1]);
    }else{
        //Parent Process
        int val1,val2,sum;
        printf("Enter two no.: ");
        scanf("%d %d",&val1, &val2);
        write(pfd1[1],&val1,sizeof(val1));
        write(pfd1[1],&val2,sizeof(val2));
        read(pfd2[0],&sum,sizeof(sum));
        printf("In Parent received sum is : %d\n",sum);
        close(pfd1[1]);
        close(pfd2[0]);
    }
    return 0;
}