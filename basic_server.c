#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;
  char line[100];
  from_client = server_handshake( &to_client );
  while(1) {
  	while(from_client) {
			read(from_client,line,sizeof(line));
			int counter;
			for(counter = 0; counter < strlen(line); counter++) {
				line[counter] = toupper(line[counter]);
			}
			write(to_client, line, sizeof(line));
  	}
  	from_client = server_handshake( &to_client );
  }
}