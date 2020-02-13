#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 5010
#define MSG_LEN 255

#define Q_LEN 5

int main()
{
	int sockfd;
	int clientfd;
	struct sockaddr_in self;
	struct sockaddr_in client_addr;
	unsigned int client_addrlen = sizeof(client_addr);

	char buffer[MSG_LEN];

	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("error creating socket\n");
		exit(errno);
	}
	
	// initialize socket
	self.sin_family = AF_INET;
	self.sin_port = htons(PORT);
	self.sin_addr.s_addr = INADDR_ANY;

	// bind socket
	if (bind(sockfd, (struct sockaddr*)&self, sizeof(self)) != 0)
	{
		printf("error binding socket\n");
		exit(errno);
	}	

	if (listen(sockfd, Q_LEN) != 0)
	{
		printf("error listening\n");
		exit(errno);
	}

	printf("Waiting for client...\n");
	clientfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_addrlen);
	printf("Connected to %s on port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

	// receive
	recv(clientfd, buffer, MSG_LEN, 0);

	printf("received msg %s\n", buffer);

	// echo back
	send(clientfd, buffer, MSG_LEN, 0);

	close(clientfd);

	close(sockfd);
	return 0;
}
