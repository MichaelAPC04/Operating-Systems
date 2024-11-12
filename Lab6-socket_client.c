/*************************
 * Date: 10/10/2024
 * Version: 1.0.0
 * Description: The following code is a socket client that is responsible for processing user keyboard input data, such that the received data is outputted in the terminal and sent to a server. When EOF is reached (by the user pressing "Ctrl + D"), the program gracefully terminates.
 *************************/
/* socket_client.c */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SOCKETNAME "mynewsocket"

int main(int argc, char *argv[])
{
  char buffer[1024];
  int n, sock, len;
  struct sockaddr_un name;

  // Create a new socket.
  sock = socket(AF_UNIX, SOCK_STREAM, 0);
  if(sock < 0)
  {
    perror("client: socket");
    exit(1);
  }

  // Create the address of the server.
  memset(&name, 0, sizeof(struct sockaddr_un));
  name.sun_family = AF_UNIX;
  strcpy(name.sun_path, SOCKETNAME);
  len = sizeof(name.sun_family) + strlen(name.sun_path);

  // Connect to the server.
  if (connect(sock, (struct sockaddr *)&name, SUN_LEN(&name)) < 0)
  {
    perror("client: connect");
    exit(1);
  }

  // Continuously read data from standard input and send the data to the socket.
  while((n = read(0, buffer, sizeof(buffer))) > 0)
  {
    if(send(sock, buffer, n, 0) < 0)
    {
      perror("client: send");
      exit(1);
    }
  }

  close(sock);
  exit(0);
}
