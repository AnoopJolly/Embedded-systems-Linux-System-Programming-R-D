// bi directional Client
#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<string.h>

#define KEY 1111
#define SRV_MSG_TYPE 1

void main()
{
	int msg_id;
	char txbuf[100];
	msg_id=msgget(KEY,0);
	printf("Enter message to send to server\n");
	scanf("%s",txbuf+16);
	long* ptr1 = (long*)txbuf;
	ptr1[0]=SRV_MSG_TYPE;
	ptr1[1]=getpid();
	msgsnd(msg_id,txbuf,16+strlen(txbuf+16),0);
	char rxbuf[100];
	printf("Waiting for servers response\n");
	msgrcv(msg_id,rxbuf,100,getpid(),0);
	printf("Respose message is : %s",rxbuf+8);
}


