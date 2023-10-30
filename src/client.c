#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv){

  // Creating A Server Socket via socket() function call
  int socket = socket(AF_INET, SOCK_STREAM, 0);

  // Creating Struct That Holds Server Socket Template
  struct sockaddr_in server_addr;

  // Setting Server Settings/Configs
  server_addr.sin_family = AF_INET; 
  server_addr.sin_port   = htons(999); /* Using random unused port */
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // Establishing Connect With Socket, And Storing Attempt Result
  int connectStatus = connect(socket, (struct sockaddr*)&server_addr, sizeof(server_addr));

  if (connectStatus == -1){
    perror("Socket Connect Attempt Failed, Exiting With [-1] Status.\n");
  } else {

    // Creating A Buffer For Data
    char buffer[256];

    // Reads Data From Socket -> Buffer
    recv(socket, buffer, sizeof(buffer), 0);

    // Checking If Socket Data Is Correctly Loaded Into Buffer
    if (atoi(buffer) == -1){
      perror("Could Not Read Data Into Buffer From Buffer. Exiting With [-1] Status.\n");
    }

    // Outputting Data From Socket
    printf("Message From Socket: %s\n", buffer);
  }
  
  return 0;  
}
