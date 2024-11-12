/*************************
 * Date: 10/10/2024
 * Version: 1.0.0
 * Description: The following code is a message client that is responsible for processing user keyboard input data, such that the received data is outputted in the terminal and sent to a server. When EOF is reached (by the user pressing "Ctrl + D"), the program gracefully terminates.
 *************************/
/* msq_client.c */

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MSQKEY 34858
#define MSQSIZE 32

struct msgbuf
{
  long mtype;
  char mtext[MSQSIZE];
};

int main(int argc, char *argv[])
{
  key_t key;
  int n, msqid;
  struct msgbuf mbuf;

  // Get a message queue. The server must have created it.
  key = MSQKEY;
  if ((msqid = msgget(key, 0666)) < 0)
  {
    perror("client: msgget");
    exit(1);
  }

  // Continuously read data from standard input and send the data as messages of type 1.
  while((n = read(0, mbuf.mtext, MSQSIZE)) > 0)
  {
    mbuf.mtype = 1;
    
    if(n == 0)
    {
      break;
    }

    if(msgsnd(msqid, &mbuf, n, 0) < 0)
    {
      perror("client: msgsnd");
      exit(1);
    }
  }
  
  // When an empty message is read, send a message of type 2 to indicate no more data.
  mbuf.mtype = 2;

  if(msgsnd(msqid, &mbuf, 0, 0) < 0)
  {
    perror("client: msgsnd");
    exit(1);
  }
  
  exit(0);
}
