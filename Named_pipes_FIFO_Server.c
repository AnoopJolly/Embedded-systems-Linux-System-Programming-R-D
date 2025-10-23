//Server (Named pipes)
#include<stdio.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
void main()
{
	mkfifo("srvfifo.obj",0666);
	int fd;
	printf("waiting for client to connect\n");
	fd=open("srvfifo.obj",O_RDONLY,0);
	printf("Client connected\n");
	char rdbuff[32]={0};
	printf("Waiting for message from client \n");
	read(fd,rdbuff,32);
	printf("Message received from client : %s\n",rdbuff);
}

