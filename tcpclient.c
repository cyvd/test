#include<netdb.h> 
#include<stdio.h> 
#include<arpa/inet.h>
#include<netinet/in.h> 
#include<stdlib.h> 
#include<string.h> 
#include<sys/types.h>
#include<sys/socket.h> 
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 
void func(int sockfd) 
{ 
	char buff1[MAX],buff2[MAX],buff[MAX]; 
	int n; 
	for (;;) { 
		bzero(buff, sizeof(buff)); 
		printf("Enter the string 1: "); 
		n = 0; 
		while ((buff1[n++] = getchar()) != '\n') 
			; 
		printf("Enter the string 2: "); 
		n = 0; 
		while ((buff2[n++] = getchar()) != '\n') 
			; 
		write(sockfd, buff1, sizeof(buff1)); 
		write(sockfd, buff2, sizeof(buff2)); 
		bzero(buff, sizeof(buff)); 
		read(sockfd, buff, sizeof(buff)); 
		printf("From Server : %s", buff); 
		if ((strncmp(buff, "exit", 4)) == 0) { 
			printf("Client Exit...\n"); 
			break; 
		} 
	} 
} 

int main() 
{ 
	int sockfd, connfd; 
	struct sockaddr_in servaddr, cli; 

	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	servaddr.sin_port = htons(PORT);  
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
		printf("connection with the server failed...\n"); 
		exit(0); 
	} 
	else
		printf("connected to the server..\n"); 

	func(sockfd); 
	close(sockfd); 
} 
