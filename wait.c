#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int pid, status, exitch;
    if((pid=fork())==-1){
        perror("Error");
        exit(0);
    }else if(pid==0){
        sleep(2);
        printf("Child Process\n");
        exit(0);
    }else{
        printf("Parent Process\n");
        if((exitch=wait(&status))==-1){
            perror("During Wait\n");
            exit(0);
        }
        printf("Parent Process Existing\n");
        exit(0);
    }

    return 0;
}