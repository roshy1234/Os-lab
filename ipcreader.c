#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *shm;
    //create the key 
    key_t key = ftok("shmfile",'R');

    //located shared memory
    int shmid = shmget(key,1024,0666);
    if(shmid < 0) {
        printf("Error in locating the shared memory\n");
        exit(1);
    }

    //attach the shared memory
    shm = shmat(shmid,NULL,0);

    //read from the shared memory
    printf("Data written in shard memory: %s\n",(char *)shm);

    //detach from  the shared memory
    if(shmdt(shm) == -1) {
        printf("Error in detaching the shared memory\n");
        exit(1);
    }
    if(shmctl(shmid,IPC_RMID,NULL) == -1) {
        printf("Error in removing the shared memory\n");
        exit(1);
    }
    return 0;
}