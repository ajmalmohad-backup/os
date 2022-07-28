#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int pid;
    char* args[] = {"/bin/ls","-l",0};
    printf("\nParent Process");
    pid=fork();
    if(pid==0){
        execv("/bin/ls", args);
        printf("\nChild Process");
    }else{
        wait(0);
        printf("\nParent Process");
        exit(0);
    }
}