#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "utils.h"

#define HOST "127.0.0.1"
#define PORT "8888"

/**
 * Returns a socket connected to a remote server.
 */
int connect_to_server(const char *host, const char *port) {

	struct addrinfo hints, *result;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;

	int s = getaddrinfo(host, port, &hints, &result);
	if (s == -1) {
		fprintf(stderr, "getaddrinfo %s\n", gai_strerror(s));
		exit(1);
	}	

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		perror("socket");
		exit(1);
	}

	if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
		perror("connect");
		exit(1);
	}
	
	freeaddrinfo(result);
    	return sockfd;
}

void cleanup(int sockfd)
{
	if (sockfd > 0)
		close(sockfd);
}

int main()
{
	int sockfd = connect_to_server(HOST, PORT);
	char buf = read_byte_from_socket(sockfd);
	write(1, &buf, sizeof(buf));
	cleanup(sockfd);

	return 0;
}
