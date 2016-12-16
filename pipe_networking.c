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
  int pid = getpid();

  //open public fifo and write private pid
  mkfifo(pid, 0644);
  int wkd = open("fifo", O_WRONLY);
  write(wkd, *pid, 7);

  //opens private pipe to block
  open(itoa(pid), O_RDONLY);

  return *buffsize;
}

int server_handshake(int *buffsize) {
  mkfifo("fifo", 0644);
  int fd = open("fifo", O_RDONLY);
  
  return *buffsize;
}
