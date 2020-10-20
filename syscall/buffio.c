#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[]){

    printf("Hello\nWorld!!!\n");
    return 0;
}


// When "\n" is not included write is called once.
// When "\n" is included twice write is also called twice.
