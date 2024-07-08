#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *shm;
    //create the key 
    key_t key = ftok("shmfile",'R');

    //create the shared memory
    int shmid = shmget(key,1024,0666|IPC_CREAT);

    //attach the shared memory
    shm = shmat(shmid,NULL,0);

    //write to the shared memory
    char str[100];
    printf("Enter the string -- ");
    scanf("%s", str);
    strcpy(shm,str);
    printf("Data written in shard memory: %s\n",(char *)shm);

    //detach from  the shared memory
    shmdt(shm);
    return 0;
}