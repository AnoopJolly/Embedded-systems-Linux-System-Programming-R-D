// bi-directional server
#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>
#include<unistd.h>

#define KEY 1111
#define SRV_MSG_TYPE 1

void main()
{
	int msg_id;
	char rxbuf[100];
	msg_id=msgget(KEY,IPC_CREAT|0666);
	printf("Waiting for client to send message\n");
	msgrcv(msg_id,rxbuf,100,SRV_MSG_TYPE,0);
	printf("Message from client : %s\n",rxbuf+16);
	char txbuf[100];
	long *ptr1 = (long*)rxbuf;
	long *ptr2 = (long*)txbuf;
	ptr2[0]=ptr1[1];
	printf("Enter Response message to client");
	scanf("%s",txbuf+8);
	msgsnd(msg_id,txbuf,8+strlen(txbuf+8),0);
	printf("Message send\n");
		
}



