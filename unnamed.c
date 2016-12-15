#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define READ 0
#define WRITE 1

int main() {

  int fds[2];
  
  pipe( fds );

  
  int f = fork();
  if ( f == 0 ) {
    close(fds[WRITE]);

    printf("[child] listening\n");
    char s[20];
    //int x;    
    read( fds[READ], s, sizeof(s) );
    printf("[child] got: %s\n", s);
  }
  else {
    close(fds[READ]);
    
    printf("[parent] sleeping\n");
    sleep(5);    
    write( fds[WRITE], "hello there", 12 );    
  }
  return 0;
}
