/*************************
 * Date: 10/10/2024
 * Version: 1.0.0
 * Description: The following code is a message server that is responsible for processing received data from the user in the "msq_client" instance, such that the received data is also outputted in the terminal. When EOF is reached (by the user pressing "Ctrl + D"), the program gracefully terminates.
 *************************/
/* msq_server.c */

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
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

  key = MSQKEY;

  // Create a new message queue.
  if ((msqid = msgget(key, IPC_CREAT | 0666)) < 0)
    {
        perror("server: msgget");
        exit(1);
    }

  /*
  * Receive messages from the queue. 
  * Messages of type 1 are to be printed on the standard output; 
  * a message of type 2 indicates that no more data.
  */
  while ((n = msgrcv(msqid, &mbuf, MSQSIZE, 0, 0)) > 0)
  {

    // Write message of type 1 to standard output.
    if (mbuf.mtype == 1)
    {
      printf("%s\n", mbuf.mtext);
    }

    if (mbuf.mtype == 2)
    {
      // Remove the message queue from the system.
      if (msgctl(msqid, IPC_RMID, (struct msqid_ds *)0) < 0)
      {
        perror("server: msgctl");
        exit(1);
      }
    }
  }

  exit(0);
}
