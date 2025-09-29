# 1.Data Sharing Problem(Race Condition)
## What it is:
- Occurs when multiple processes/threads access and modify a shared variable at the same time.
- Final result becomes inconsistent because operations interleave unpredictably.
## Why it happens:
- CPU may switch between threads during a critical section.
- Example:two threads increment a variable, both read old value before either writes new->result incorrect.

## Example Code(without synchronization)
```c
#include<stdio.h>
#include<pthread.h>

int counter=0;

void increment(void *arg)
{
    for(int i=0;i<100000;i++)
    {
        counter++;
    }
    return NULL;
}
int main()
{
    pthread_t t1,t2;
    pthread_create(&t1,NULL,increment,NULL);
    pthread_create(&t2,NULL,increment,NULL);
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    
    printf("Final value of counter:%d\n",counter);
    return 0;
}
```
- Expected=2000000, but actual output is less.
- This is the data sharing problem.
- To avoid this synchronization problem we use "Semaphore".

# What is a semaphore?
- A synchronization tool used to control access to shared resources.
- Represented by an integer variable.
- Modified only by two atomic operations:
- wait()/P()/sem_wait() → decrement, block if value < 0.
- signal()/V()/sem_post() → increment, wake up a waiting process.
- Used to prevent race conditions and coordinate processes/threads.
# 2.Types of  Semaphores
- Binary Semaphore
- Counting Semaphore
- Mutex (Mutual Exclusion Lock)

# Binary Semaphore
## Why we need it:
- We want only one thread inside the critical section at a time.
- Binary semaphore works like a gate(0/1).
## Limitations:
- Works only for single resource at a time.
- If you have multiple identical resources (like printers), binary is not enough.

## Example code (Binary Semaphore)
```c
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int counter = 0;
sem_t sem;   

void* increment(void* arg) {
    for (int i = 0; i < 100000; i++) {
        sem_wait(&sem);   
        counter++;        
        sem_post(&sem);   
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    sem_init(&sem, 0, 1);  

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final counter value: %d\n", counter);

    sem_destroy(&sem);
    return 0;
}
```
# Counting Semaphore 
## Why we shift from binary to counting:
- Binary only allows 1 user at a time.
- But sometimes we have N identical resources (e.g., 3 printers, 5 DB connections).
- Counting semaphore lets up to N threads use the resource.

## Example Code (Counting Semaphore)
```c
// counting_semaphore.c
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;  
int counter;
void* task(void* arg) {
    int id = *(int*)arg;
    sem_wait(&sem);   
    printf("Thread %d entered critical section\n", id);
    sleep(1);         
    printf("Thread %d leaving critical section\n", id);
    sem_post(&sem);   
    return NULL;
}

int main() {
    pthread_t t[5];
    int ids[5] = {1, 2, 3, 4, 5};

    sem_init(&sem, 0, 5);   

    for (int i = 0; i < 5; i++)
        pthread_create(&t[i], NULL, task, &ids[i]);

    for (int i = 0; i < 5; i++)
        pthread_join(t[i], NULL);
    

    sem_destroy(&sem);
    return 0;
}
```
- At most 2 threads run at once.
- This shows resource pool management.

# Mutex 
## Why we shift from semaphore-mutex:
- Binary semaphore can be misused:one thread locks, another thread unlocks.
- No ownership->unsafe in multithreading.
- Mutex ensures :only the thread that locked can unlock.

## Example code:
```c
// mutex_example.c
#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t lock;

void* increment(void* arg) {
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&lock);   // lock
        counter++;
        pthread_mutex_unlock(&lock); // unlock
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final counter value: %d\n", counter);

    pthread_mutex_destroy(&lock);
    return 0;
}
```

