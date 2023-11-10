#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char** argv) {

    // Creating a server socket via socket() function call
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Check if socket creation failed
    if (serverSocket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Create a message to send to the client node
    char* serverMsg = "Message From The Server To The Client. Hello!\n";

    // Creating struct that holds server socket template
    struct sockaddr_in server_addr;

    // Setting server settings/configs
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9001); // Using random unused port
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Binding to network port, listening for connections to server
    if (bind(serverSocket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for connections...
    if (listen(serverSocket, 1) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    /*
    Awaits for connect to its socket.
    When found, creates new socket to communicate
    */
    int clientSocket = accept(serverSocket, NULL, NULL);

    // Try to send server data to client
    int msg_value = send(clientSocket, serverMsg, strlen(serverMsg) + 1, 0);

    // Checking if data was properly sent to client socket
    if (msg_value == -1) {
        perror("Could not send data to client socket. Exiting with [-1] status.\n");
    }

    // Close the sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}
