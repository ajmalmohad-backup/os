#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main(){
    key_t key = 15678;
    int shmid = shmget(key,1024,0666|IPC_CREAT);
    char* str = (char *)shmat(shmid,0,0);
    printf("Data Read from Memory: %s",str);
    return 0;
}