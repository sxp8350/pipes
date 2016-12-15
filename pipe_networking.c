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
  
  return *buffsize;
}

int server_handshake(int *buffsize) {
  mkfifo("fifo", 0644);
  int fd = open("fifo", O_WRONLY);

  return *buffsize;
}
