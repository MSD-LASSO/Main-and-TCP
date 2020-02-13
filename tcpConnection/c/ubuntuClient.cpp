#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

#define SERVER_ADDR "127.0.0.1"
#define PORT 5010
#define MSG_LEN 255

#define Q_LEN 5

int main()
{

	int sockfd;
	struct sockaddr_in server_addr;

	char buffer[MSG_LEN] = "hello";
	char recv_buffer[MSG_LEN];
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		printf("error creating socket\n");
		exit(-1);
	}

	printf("atttempting to connect...\n");
	if (-1 == connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)))
	{
		printf("error connecting to server\n");
		exit(-1);
	}

	write(sockfd, buffer, MSG_LEN);

	read(sockfd, recv_buffer, MSG_LEN);

	printf("SERVER: %s\n", recv_buffer);

	close(sockfd);
	return 0;
}
