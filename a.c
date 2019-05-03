#include<stdio.h>
#include<sys/types.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
int main()
{
int clntsocket,serversocket;
char msg[50],msg1[50];
struct sockaddr_in serveraddr,clntaddr;
socklen_t len;
bzero(msg,sizeof(msg));
serversocket=socket(AF_INET,SOCK_STREAM,0);
printf("\n SERVER PROCESS\n");
bzero((char *)&serveraddr,sizeof(serveraddr));
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(5015);
serveraddr.sin_addr.s_addr=INADDR_ANY;
bind(serversocket,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
bzero((char*)&clntaddr,sizeof(clntaddr));
len=sizeof(clntaddr);
printf("\n*****\n");
listen(serversocket,5);
printf("\nWaiting for client connectivity\n");
clntsocket=accept(serversocket,(struct sockaddr*)&clntaddr,&len);
printf("\nClient connectivity is received\n");
printf("\nReading message from client\n");
while(1)
{
read(clntsocket,msg,sizeof(msg));
printf("\nClient message is \t%s",msg);
printf("\nsending acknowledgement to client\n");
write(clntsocket,"your msg is received",sizeof("your msg is received"));
}
close(clntsocket);
close(serversocket);
}


