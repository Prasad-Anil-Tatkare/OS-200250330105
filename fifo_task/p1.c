#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[]){

    int p1_var1=10,p1_var2=20,sum,fd,fd1;
    
    mkfifo("fifo", S_IRUSR | S_IWUSR);
    fd = open("fifo", O_WRONLY);
    write(fd,&p1_var1,sizeof(p1_var1));
    write(fd,&p1_var2,sizeof(p1_var2));
    close(fd);

    mkfifo("fifo1", S_IRUSR | S_IWUSR);
    fd1 = open("fifo1", O_RDONLY);
    read(fd1,&sum,sizeof(sum));
    printf("Received Sum is: %d\n",sum);
    close(fd1);
    return 0;

}