#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[]){

    int p2_var1,p2_var2,sum,fd,fd1;
    
    mkfifo("fifo", S_IRUSR | S_IWUSR);
    fd = open("fifo", O_RDONLY);
    read(fd,&p2_var1,sizeof(p2_var1));
    read(fd,&p2_var2,sizeof(p2_var2));
    close(fd);
    
    printf("VAR1: %d\nVAR2: %d\n",p2_var1,p2_var2);
    sum = p2_var1 + p2_var2;

    mkfifo("fifo1", S_IRUSR | S_IWUSR);
    fd1 = open("fifo1", O_WRONLY);
    write(fd,&sum,sizeof(sum));
    close(fd1);
    return 0;

}