##//communication between related Process (Parent and child)
```c
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

void main()
{
	int fd[2];
	int pid;
	pipe(fd);
	pid=fork();
	if(pid==0)
	{
		close(fd[0]);
		char wrbuff[32]={0};
		printf("Enter the data\n");
		scanf("%s",wrbuff);
		write(fd[1],wrbuff,strlen(wrbuff));
	}
	else
	{
		close(fd[1]);
		char  rdbuff[32]={0};
		printf("waiting for child to send\n");
		read(fd[0],rdbuff,32);
		printf("Data recevied from child process: %s\n",rdbuff);
	}
}
```

