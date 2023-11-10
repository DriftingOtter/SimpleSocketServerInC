#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
    // Creating a client socket via socket() function call
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Check if socket creation failed
    if (clientSocket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Creating struct that holds server socket template
    struct sockaddr_in server_addr;

    // Setting server settings/configs
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9001); // Using the same port as the server
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Establishing connection with the server socket
    int connectStatus = connect(clientSocket, (struct sockaddr*)&server_addr, sizeof(server_addr));

    if (connectStatus == -1) {
        perror("Socket connect attempt failed, exiting with [-1] status.\n");
        close(clientSocket); // Close the client socket before exiting
        exit(EXIT_FAILURE);
    } else {
        // Creating a buffer for data
        char buffer[256];

        // Reading data from socket -> buffer
        ssize_t bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);

        // Checking if socket data is correctly loaded into the buffer
        if (bytesReceived == -1) {
            perror("Could not read data into buffer from socket. Exiting with [-1] status.\n");
        } else {
            // Null-terminate the received data to make it a valid C string
            buffer[bytesReceived] = '\0';

            // Outputting data from the socket
            printf("Message from server: %s\n", buffer);
        }
    }

    // Close the client socket
    close(clientSocket);

    return 0;
}
