#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "pipe_networking.h"

int client_handshake(int *buffsize) {
  char message[MESSAGE_BUFFER_SIZE];
  int pid = getpid();

  //3 creates private fifo
  //4 open public fifo and write private pid
  mkfifo(pid, 0644);
  int wkd = open("fifo", O_WRONLY);
  write(wkd, *pid, 7);

  //5 opens private pipe to block
  open(itoa(pid), O_RDONLY);

  //reads confirmation from server and removes FIFO

  //sends confirmation


  return *buffsize;
}

int server_handshake(int *buffsize) {
  char message[MESSAGE_BUFFER_SIZE];
  //1 & 2
  //makes well known pipe and opens
  mkfifo("fifo", 0644);
  printf("[SERVER]: fifo created")

  int fd = open("fifo", O_RDONLY);

  //6 recives message and removes WKP
  read(fd,message, sizeof(message));
  remove("fifo");

  //7 conects to private fifo and sends message
  int con = open(message, O_WRONLY);
  strcpy( message, "Hello" ); 
  write(con, message, sizeof(message));

  

  
  
  return *buffsize;
}
