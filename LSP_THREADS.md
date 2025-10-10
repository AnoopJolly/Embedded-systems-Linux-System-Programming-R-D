## 1.Write a C program to create a thread that prints "Hello, World!"?
```c
#include<stdio.h>
#include<pthread.h>
void *task (void *arg)
{
        printf("Hellow, World\n");
}
int main()
{
        pthread_t t;

        pthread_create(&t,NULL,task,NULL);
        pthread_join(t,NULL);
        printf("This is main process\n");
        return 0;
}
```
## 2.Modify the above program to create multiple threads, each printing its own message?
```c
#include<stdio.h>
#include<pthread.h>
void *task1 (void *arg)
{
        printf("Thread 1\n");
}
void *task2 (void *arg)
{
        printf("Thread 2\n");
}
void *task3 (void *arg)
{
        printf("Thread 3\n");
}


int main()
{
        pthread_t t1,t2,t3;

        pthread_create(&t1,NULL,task1,NULL);
        pthread_create(&t2,NULL,task2,NULL);
        pthread_create(&t3,NULL,task3,NULL);

        pthread_join(t1,NULL);
        pthread_join(t2,NULL);
        pthread_join(t3,NULL);

        printf("This is main process\n");
        return 0;
}
```
## 3.Develop a C program to create two threads that print numbers from 1 to 10 concurrently?
```c
#include <stdio.h>
#include <pthread.h>

void* counter(void* arg) {
    int thread_id = *(int*)arg;

    for (int i = 0; i < 10; i++) {
        printf("Thread %d: %d\n", thread_id, i);
    }

    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    pthread_create(&t1, NULL, counter, &id1);
    pthread_create(&t2, NULL, counter, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
```
## 4.Implement a C program to create a thread that calculates the factorial of a given number?
```c
#include<stdio.h>
#include<pthread.h>

void *fact(void  *arg)
{
        int n=*(int *)arg;
        int facto=1;
        while(n>0)
        {
                facto=facto*(n);
                n=n-1;
        }
        printf("factorial of %d is %d\n",*(int*)arg,facto);

        return NULL;
}

int main()
{
        pthread_t t1,t2;
        int num[]={5,3};
        pthread_create(&t1,NULL,fact,&num[0]);
        pthread_create(&t2,NULL,fact,&num[1]);
        pthread_join(t1,NULL);
        pthread_join(t2,NULL);

        return 0;
}
```
## 5.Write a C program to create two threads that print their thread IDs?
```c
#include<stdio.h>
#include<pthread.h>

void *printid(void *arg)
{
        int id=*(int*)arg;
        printf("the ID is %d\n",id);
        return NULL;
}
int main()
{
        pthread_t t1,t2;
        int id[]={3,4};
        pthread_create(&t1,NULL,printid,&id[0]);
        pthread_create(&t2,NULL,printid,&id[1]);
        pthread_join(t1,NULL);
        pthread_join(t2,NULL);

        return 0;
}
```
## 6.Develop a C program to create a thread that prints the sum of two numbers?
```c
#include<stdio.h>
#include<pthread.h>

struct input_data
{
        int id;
        int a;
        int b;
};

void *sum(void *arg)
{
        struct input_data *data=(struct input_data*)arg;
        int result=data->a+data->b;
        printf("id is %d, The sum of %d and %d is %d\n",data->id,data->a,data->b,result);
        return NULL;
}

int main()
{
        pthread_t t1,t2;
        struct input_data data1,data2;
        data1.id=1;
        printf("Thread 1 - Enter value 1: ");
        scanf("%d",&data1.a);
        printf("thread 1 - Enter value 2: ");
        scanf("%d",&data1.b);

        data2.id=2;
        printf("Thread 2 - Enter value 1: ");
        scanf("%d",&data2.a);
        printf("thread 2 - Enter value 2: ");
        scanf("%d",&data2.b);

        pthread_create(&t1,NULL,sum,&data1);
        pthread_create(&t2,NULL,sum,&data2);
        pthread_join(t1,NULL);
        pthread_join(t2,NULL);

        return 0;
}
```
## 7.Implement a C program to create a thread that calculates the square of a number?
```c
#include<stdio.h>
#include<pthread.h>

void *square(void *arg)
{
        int n=*(int*)arg;
        int sqr=1;
        sqr=n*n;
        printf("Square of %d is %d\n",n,sqr);
}

int main()
{
        pthread_t t1;
        int value=5;
        if((pthread_create(&t1,NULL,square,&value))!=0)
        {
                perror("Thread creation failed");
                return 1;
        }
        pthread_join(t1,NULL);
        return 0;
}
```
## 8.Write a C program to create a thread that prints the current date and time?
```c
#include<stdio.h>
#include<pthread.h>
#include<time.h>
void *datetime (void *arg)
{
        time_t now=time(NULL);
        printf("Current Date and Time: %s",ctime(&now));
        return NULL;
}
int main()
{
        pthread_t t;
        pthread_create(&t,NULL,datetime,NULL);
        pthread_join(t,NULL);
        return 0;
}
```
## 9.Develop a C program to create a thread that checks if a number is prime?
```c
#include<stdio.h>
#include<pthread.h>
void *prime(void *arg)
{
        int n=*(int*)arg;
        int flag=1;
        if(n==1)
        {
                printf("Not prime\n");
                return NULL;
        }
        for(int i=2;i<=n/2;i++)
        {
                if(n%i==0)
                {
                        flag=0;
                        break;
                }
        }
        if(flag==1)
        {
                printf("Prime number\n");
        }
        else
        {
                printf("Not a prime number\n");
        }
        return NULL;
}
int main()
{
        pthread_t t1;
        int val;
        printf("Enter the number\n");
        scanf("%d",&val);
        pthread_create(&t1,NULL,prime,&val);
        pthread_join(t1,NULL);

        return 0;
}
```
## 10.Implement a C program to create a thread that checks if a given string is a palindrome?
```c
#include<stdio.h>
#include<string.h>
#include<pthread.h>
void *palindrome(void *arg)
{
        char arr[100];
        strcpy(arr,(char*)arg);
        int n=strlen(arr);
        int j=0;
        int flag=1;
        for(int i=0;i<n/2;i++)
        {

                if(arr[i]!=arr[n-i-1])
                {
                        flag=0;
                        break;
                }

        }
        if(flag==1)
                printf("palindrome\n");
        else
                printf("not palindrome\n");

}

int main()
{
        pthread_t t1;
        char str[]="malayalam";
        pthread_create(&t1,NULL,palindrome,str);
        pthread_join(t1,NULL);

        return 0;
}
```
## 11.Write a C program to create a thread that prints "Hello, World!" with thread synchronization?
```c
#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mtx;
void *print(void *arg)
{
        pthread_mutex_lock(&mtx);

        printf("Hellow world\n");

        pthread_mutex_unlock(&mtx);

}

void main()
{
        pthread_t t1,t2;
        pthread_create(&t1,NULL,print,NULL);
        pthread_create(&t2,NULL,print,NULL);


        pthread_join(t1,NULL);
        pthread_join(t2,NULL);

}
```
## 12.Develop a C program to create two threads that print their thread IDs and synchronize their output?
```c
#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mtx;

void *printid(void *arg)
{
        int id=*(int*)arg;
        pthread_mutex_lock(&mtx);
        printf("the Thread id is : ' %d '\n",id);
        pthread_mutex_unlock(&mtx);
}
void main()
{
        pthread_t t1,t2;
        int id[]={101,102};
        pthread_create(&t1,NULL,printid,&id[0]);
        pthread_create(&t2,NULL,printid,&id[1]);

        pthread_join(t1,NULL);
        pthread_join(t2,NULL);
}
```
## 13
```


