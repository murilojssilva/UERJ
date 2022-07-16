#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include </usr/include/semaphore.h>

#define BUFF_SIZE   5		/* total number of slots */
#define NP          2		/* total number of producers */
#define NCP         1		/* total number of consumers/producers */
int NITERS;		/* number of items produced/consumed */

typedef struct {
    int buf[BUFF_SIZE];   /* shared var */
    int in;         	  /* buf[in%BUFF_SIZE] is the first empty slot */
    int out;        	  /* buf[out%BUFF_SIZE] is the first full slot */
    sem_t full;     	  /* keep track of the number of full spots */
    sem_t empty;    	  /* keep track of the number of empty spots */
    sem_t mutex;    	  /* enforce mutual exclusion to shared data */
} sbuf_t;

sbuf_t shared;

void *Producer(void *arg)
{
    int i, item, index;

    index = *((int *)arg);

    for (i=0; i < NITERS; i++) {

        /* Produce item */
        item = i;
        /* Prepare to write item to buf */

        /* If there are no empty slots, wait */
        sem_wait(&shared.empty);
        /* If another thread uses the buffer, wait */
        sem_wait(&shared.mutex);
        shared.buf[shared.in] = item;
        shared.in = (shared.in+1)%BUFF_SIZE;
        printf("[P%d] Producing %d ...\n", index, item); fflush(stdout);
        /* Release the buffer */
        sem_post(&shared.mutex);
        /* Increment the number of full slots */
        sem_post(&shared.full);
    }
    return NULL;
}

void *ConsumerProducer(void *arg)
{
    int i, item1, item2, index;

    index = *((int *)arg);

    for (i=0; i < NITERS; i++) {

	/* Prepare to read item from buf */

        /* If there are no filled slots, wait */
        sem_wait(&shared.full);
        /* If another thread uses the buffer, wait */
        sem_wait(&shared.mutex);
        item1 = shared.buf[shared.out];
        shared.out = (shared.out+1)%BUFF_SIZE;
        item2 = shared.buf[shared.out];
        shared.out = (shared.out+1)%BUFF_SIZE;
        printf("[CP] Consuming %d and %d ...\n", item1, item2); fflush(stdout);
        /* Release the buffer */
        sem_post(&shared.mutex);
        /* Increment the number of empty slots */
        sem_post(&shared.empty);

	//Change consumed item
        item1 += item2;

        /* Prepare to write item to buf */

        /* If there are no empty slots, wait */
        sem_wait(&shared.empty);
        /* If another thread uses the buffer, wait */
        sem_wait(&shared.mutex);
        shared.buf[shared.in] = item1;
        shared.in = (shared.in+1)%BUFF_SIZE;
        printf("[CP] Producing %d ...\n", index, item1); fflush(stdout);
        /* Release the buffer */
        sem_post(&shared.mutex);
        /* Increment the number of full slots */
        sem_post(&shared.full);

    }
    return NULL;
}


int main(int argc, char ** argv)
{

    NITERS = atoi(argv[1]);

    pthread_t idP, idC, idCP;
    int index = 0;
    int sP[NP], sCP[NCP];

    sem_init(&shared[index].full, 0, 0);
    sem_init(&shared[index].empty, 0, BUFF_SIZE);
    sem_init(&shared[index].mutex, 0, 1);

    for (index = 0; index < NP; index++)
    {
       sP[index]=index;
       /* Create a new producer */
       pthread_create(&idP, NULL, Producer, &sP[index]);
    }

    for (index = 0; index < NCP; index++)
    {
       sCP[index]=index;
       /* Create a new producer */
       pthread_create(&idCP, NULL, ConsumerProducer, &sCP[index]);
    }

    pthread_exit(NULL);
}

