#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdio.h>
main()
{
struct sockaddr_in server,client;
int s,n;
char a[10],b[50];
s=socket(AF_INET,SOCK_DGRAM,0);
server.sin_port=1240;
server.sin_family=AF_INET;
server.sin_addr.s_addr=inet_addr("127.0.0.1");
bind(s,(struct sockaddr*)&server,sizeof(server));
n=sizeof(client);
while(1)
{
printf("\nreceived from client");
recvfrom(s,a,sizeof(a),0,(struct sockaddr*)&client,&n);
printf("%s",a);
printf("\n send to client");
scanf("%s",b);
if(strcmp(b,"close")==0)
break;
sendto(s,b,sizeof(b),0,(struct sockaddr*)&client,n);
}
}

