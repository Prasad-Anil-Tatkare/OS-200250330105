#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//Sender
int main(int argc, char const *argv[]){
    
    int fd;
    
    fd = open("desd", O_WRONLY);
    write(fd,"CDAC\n",5);
    close(fd);
    return 0;
}