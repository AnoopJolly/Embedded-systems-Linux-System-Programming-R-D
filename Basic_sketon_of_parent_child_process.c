#include<stdio.h>
#include<unistd.h>//for fork()
#include<sys/wait.h>// for wait() waitpid() WIFEXITED WIFSIGNALED WTERMSIG WEXITSTATUS
#include<stdlib.h>//for exit()
void main()
{
	int status;
	int pid;
	pid=fork();
	if(pid==0)
	{
		for(int i = 0; i < 10; i++)
		{
			printf("Child process\n");
			sleep(1);
		}
		exit(1);
	}
	else
	{
		for(int i=0;i<5;i++)
		{

			printf("Parent process\n");
			sleep(1);
		}
		
	}
	printf("parent process completed and waiting for child process to complete successfully\n");
	wait(&status);
	printf("Exit code received from child %d   \n",WEXITSTATUS(status));
}
