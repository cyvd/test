#include<stdio.h>
#include<sys/types.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
int main()
{
int clntsocket;
struct sockaddr_in serveraddr;
socklen_t len;
struct hostent *server;
char msg[50],msg1[50];
bzero(msg,sizeof(msg));
clntsocket=socket(AF_INET,SOCK_STREAM,0);
bzero((char *)&serveraddr,sizeof(serveraddr));
len=sizeof(serveraddr);
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(5015);
server=gethostbyname("127.0.0.1");
bcopy((char *)server->h_addr,(char *)&serveraddr.sin_addr.s_addr,sizeof(server->h_addr));
connect(clntsocket,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
printf("\nConnection process\n");
printf("\nsending message to server\n");
while(1)
{
write(clntsocket,"i am client",sizeof("i am client"));
printf("\nreceiving acknowledgement from server\n");
read(clntsocket,msg1,sizeof(msg1));
printf("\nacknowledgement is %s",msg1);
}
close(clntsocket);
return(0);
} 
