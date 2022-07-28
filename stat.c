#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    struct stat *file;
    file = (struct stat*)malloc(sizeof(struct stat));
    char path1[10];
    printf("Enter the File: ");
    scanf("%s",&path1);
    stat(path1,file);
    printf("User ID: %d\n", file->st_uid);
    printf("Block Size: %d\n", file->st_blksize);
    printf("Last Access Time: %d\n", file->st_atim);
    printf("Production Mode: %d\n", file->st_mode);
    printf("Size of File: %d\n", file->st_nlink);
}