#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    int pid = getpid();
    printf("\nChild Process ID: %d", pid);
    pid = getppid();
    printf("\nParent Process ID: %d", pid);
}