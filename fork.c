#include <stdio.h>
#include <unistd.h>

int main(){
    int value = fork();
    printf("value is : %d \n", value);
}