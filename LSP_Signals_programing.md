## Implement a C program to send a custom signal to another process.
```c
## Process1_Signal_sender
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main() {
    int pid;

    printf("Enter the PID of the process to send SIGUSR1 to: ");
    scanf("%d", &pid);

    // Send SIGUSR1 signal to the given PID
    if (kill(pid, SIGUSR1) == 0) {
        printf("SIGUSR1 sent to process %d\n", pid);
    } else {
        perror("Error sending signal");
    }

    return 0;
}
## process2_signal_receiver
```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig) {
    printf("Received signal: %d\n", sig);
}

int main() {
    signal(SIGUSR1, handle_signal);

    printf("Receiver running. PID = %d\n", getpid());

    // Wait for signal
    while (1) {
        pause(); // Wait for any signal
    }

    return 0;
}
```
## 3. Create a C program to ignore the SIGCHLD signal temporarily.
```c
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
        struct sigaction sa_ignore,sa_default;

        sa_ignore.sa_handler =SIG_IGN;
        sigemptyset(&sa_ignore.sa_mask);
        sa_ignore.sa_flags=0;

        sigaction(SIGCHLD,&sa_ignore,NULL);
        printf("SIGCHLD is now being ignored:\n");
        pid_t pid=fork();
        if(pid==0)
        {
                printf("Child process(PID : %d) exiting\n",getpid());
                exit(0);
        }
        else if (pid>0)
        {
                sleep(2);
                printf("Parent process PID %d resumes. Child exited , but SIGCHLD was ignored\n",getpid());
        sa_default.sa_handler = SIG_DFL;
        sigemptyset(&sa_default.sa_mask);
        sa_default.sa_flags =0;
        sigaction(SIGCHLD,&sa_default,NULL);
        printf("SIGCHLD handling restored to default\n");
        }
        else
        {
                printf("fork failed");
                return 1;
        }
        sleep(2);
        return 0;
}
```
## 4. Write a program to block the SIGTERM signal using sigprocmask().
```c
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
        sigset_t new_set,old_set;

        sigemptyset(&new_set);
        sigaddset(&new_set,SIGTERM);

        if(sigprocmask(SIG_BLOCK, &new_set, &old_set) < 0)
        {
                printf("error Sigpromask");
                exit(EXIT_FAILURE);
        }
        printf("SIGTERM is now blocked : PID :%d\n",getpid());
        printf("Try sending SIGTERM using: kill -15 %d\n",getpid());

        for(int i=10;i>0;i--)
        {
                printf("Running... %d seconds left\n",i);
                sleep(1);
        }
        if(sigprocmask(SIG_SETMASK,&old_set,NULL)<0)
        {
                printf("ERROR Sigpromask restore");
                exit(EXIT_FAILURE);
        }
        printf("SIGTERM is now unblocked program will exit if it was senf during blocking\n");
        sleep(5);

        printf("Exiting normally\n");
        return 0;
}
```
## Simply Blocking
```c
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
int main()
{
        sigset_t set;
        sigemptyset(&set);
        sigaddset(&set,SIGINT);         
        sigprocmask(SIG_BLOCK,&set,NULL);
        sleep(5);
        printf("Exiting normally\n");
        return 0;
}
```





