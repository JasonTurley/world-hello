#include <unistd.h>
#include <stdlib.h>

#include "utils.h"

char read_byte_from_socket(int sockfd)
{
	char buf;
	ssize_t byte = read(sockfd, &buf, sizeof(buf));

	return buf;

}

void write_byte_to_socket(int sockfd, char c)
{
	// TODO: implement me
}
