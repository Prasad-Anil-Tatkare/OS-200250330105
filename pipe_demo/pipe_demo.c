#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]){

    unsigned char read_buffer[128];
    pid_t id;
    int pfd[2];     //Array of two integers
    pipe(pfd);      //Pipe is created

    id = fork();         //Child process is created using fork
    if(0 == id){
        //Child Process
        read(pfd[0],read_buffer,128);
        printf("In Child: %s\n", read_buffer);
        close(pfd[0]);
    }else{
        //Parent Process
        write(pfd[1],"CDAC\n",5);
        close(pfd[1]);
    }
    return 0;
}