#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define SERVER_IP "127.0.0.1"  // Replace with your server's IP address
#define SERVER_PORT 12345       // Replace with your server's port

void displayMainMenu() {
    printf("\nRole Selection Menu:\n");
    printf("1. Faculty\n");
    printf("2. Student\n");
    printf("3. Admin\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[1024];
    int role_choice;

    // Create a socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address information
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &(server_addr.sin_addr));

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to the server");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    printf("Connected to the server.\n");

    // Role selection menu
    while (1) {
        displayMainMenu();
        scanf("%d", &role_choice);

        if (role_choice == 1) {
            // Send Faculty role choice to the server
            send(client_socket, "Faculty", strlen("Faculty"), 0);
            printf("You selected the Faculty role.\n");
            // Implement faculty-specific functionality here
        } else if (role_choice == 2) {
            // Send Student role choice to the server
            send(client_socket, "Student", strlen("Student"), 0);
            printf("You selected the Student role.\n");
            // Implement student-specific functionality here
        } else if (role_choice == 3) {
            // Send Admin role choice to the server
            send(client_socket, "Admin", strlen("Admin"), 0);
            printf("You selected the Admin role.\n");
            // Implement admin-specific functionality here
        } else if (role_choice == 4) {
            // Exit the program
            send(client_socket, "Exit", strlen("Exit"), 0);
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    // Close the socket
    close(client_socket);

    printf("Disconnected from the server.\n");

    return 0;
}
