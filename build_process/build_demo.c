#include <stdio.h>
int add(int, int);
int sub(int, int);
int main(int argc, char const *argv[])
{
    printf("Addition: %d\n", add(10,5));
    printf("Subtraction: %d\n", sub(10,5));
    return 0;
}