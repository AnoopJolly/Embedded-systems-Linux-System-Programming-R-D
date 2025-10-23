//client named pipes
#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
void main()
{
	int fd;
	fd=open("srvfifo.obj",O_WRONLY,0);
	char wrbuff[32]={0};
	printf("Enter the message for server\n");
	scanf("%s",wrbuff);
	write(fd,wrbuff,strlen(wrbuff));
	printf("Message sent to server \n");

}


