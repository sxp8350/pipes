#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "pipe_networking.h"

void process( char * s );
void sub_server( int from_client, int to_client );

int main() {

  int to_client, from_client;
  char buffer[HANDSHAKE_BUFFER_SIZE];
    
  while (1) {

    from_client = server_handshake1( buffer );    

    int f = fork();
    if ( f == 0 ) {

      to_client = server_handshake2( buffer, from_client );
      sub_server( from_client, to_client );

      exit(0);
    }
  }
  return 0;
}


void sub_server( int from_client, int to_client ) {

  char buffer[MESSAGE_BUFFER_SIZE];
  while (read( from_client, buffer, sizeof(buffer) )) {

    printf("[SERVER %d] received: %s\n", getpid(), buffer );
    process( buffer );
    write( to_client, buffer, sizeof(buffer));    
  }
  
}
void process( char * s ) {

  while ( *s ) {
    *s = (*s - 'a' + 13) % 26 + 'a';
    s++;
  }
}
