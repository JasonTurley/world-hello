#include <unistd.h>

/**
 * Reads and returns one byte from the given socket.
 *
 * Note: no error checking is performed since we are only transmitting a single byte at a
 * time.
 */
char read_byte_from_socket(int sockfd);

/**
 * Writes one byte to the given socket.
 *
 * Note: no error checking is performed since we are only transmitting a single byte at a
 * time.
 */
void write_byte_to_socket(int sockfd, char c);
