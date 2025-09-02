#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int status;
	int id=fork();
	if(id<0)
	{
		perror("Fork failed");
		exit(1);
	}
	if(id==0)
	{
		printf("Child process created\n");
		printf("PID : %d  PPID : %d\n",getpid(),getppid());
	       execlp("ls","ls","-l",NULL);
       		abort();
 	}
	else

	{
		wait(&status);
		printf("parent process\n");
		printf("PID : %d PPID : %d\n",getpid(),getppid());
		
		
	}
	if(WIFEXITED(status))
	{
		printf(" Child exited with status %d\n",WEXITSTATUS(status));
	}
	else if(WIFSIGNALED(status))
	{
		printf(" Child terminated by %d signal\n",WTERMSIG(status));
	}
	return 0;
}
