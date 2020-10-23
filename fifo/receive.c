#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[]){
    
    int fd;
    unsigned char read_buffer[128];

    fd = open("desd", O_RDONLY);
    read(fd,read_buffer,128);
    printf("Received: %s\n", read_buffer);
    close(fd);
    return 0;
}