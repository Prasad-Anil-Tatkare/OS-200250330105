#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[]){

    int fd;
    fd = open("desd.txt", O_WRONLY | O_CREAT);
    
    if(-1 == fd){
        perror("Error in open");
        return -1;
    }
    printf("FD is %d\n", fd);
    write(fd,"Prasad",6);
    close(fd);
    return 0;
}