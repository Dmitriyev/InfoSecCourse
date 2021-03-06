#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char str[100];
	char* res_str = "Hello, client (MyServer 1.1)\n";
	int listen_fd, comm_fd;

	struct sockaddr_in servaddr;
	
	listen_fd = socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htons(INADDR_ANY);
	servaddr.sin_port = htons(22000);

	bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));

	listen(listen_fd,10);
	comm_fd = accept(listen_fd, (struct sockaddr *)NULL,NULL);

	while(1)
	{
		bzero(str,100);
		read(comm_fd,str,100);
		printf("Echoing back - %s",str);
		write(comm_fd,res_str,strlen(res_str)+1);
	}
}
