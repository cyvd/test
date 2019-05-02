#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 

int main()
{ int pid,fd1[2],status;
char a[30],ab[30];
pid=fork();

if (pid==-1) {printf("Child not created");}
else if (pid==0){

printf("inside child process id %d\n",getpid());
gets(ab);
close(fd1[0]);
write(fd1[1],ab, 30);
}
else{
wait(&status);
printf("inside parent process id %d\n",getpid());

close(fd1[1]);
read(fd1[0], a, 30); 
printf("the string is %s",a);
close(fd1[0]);
}

return 0;
}
