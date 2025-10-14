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



