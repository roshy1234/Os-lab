#include <stdio.h>
#include <stdlib.h>


int n;
int mutex = 1, full = 0,empty, x = 0;

void producer() {
        --full; // wait until empty>0 and decrement empty
        --mutex; //lock aquired
        printf("Producer produces the item %d\n", ++x);
        ++mutex; //lock released
        --empty; // increment full
        //wait(1000);
}

void consumer() {
        --full; // wait until full>0 and decrement full
        --mutex; //lock aquired
        printf("Consumer consumed item %d\n", x--);
        ++mutex; //lock released
        ++empty; // increment empty
        //wait(1000);
    }

void main() {
    printf("Enter the size of buffer -- ");
    scanf("%d", &n);
    empty = n;
    int c;
    while(1) {
        printf("1. Producer\n2. Consumer\n3. Exit\n");
        printf("Enter your choice -- ");
        scanf("%d", &c);
        switch(c) {
            case 1: if((mutex == 1) && (empty != 0))
                        producer();
                    else
                        printf("Buffer is full\n");
                    break;
            case 2: if((mutex == 1) && (full != 0) && (x != 0))
                        consumer();
                    else
                        printf("Buffer is empty\n");
                    break;
            case 3: exit(0);
                    break;
            default: printf("Invalid choice\n");
        }
    }
}