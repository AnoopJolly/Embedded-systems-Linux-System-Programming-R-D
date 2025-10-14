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
```
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


