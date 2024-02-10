#include <iostream>
#include <random>
#include <chrono>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_IP "192.168.1.100" // Replace with your server IP address
#define SERVER_PORT 5000 // Replace with your server port number

int main() {
    // Generate random temperature readings
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(20, 40);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "Failed to create socket." << std::endl;
        return 1;
    }

    // Set server details
    sockaddr_in server_address{};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &(server_address.sin_addr)) <= 0) {
        std::cerr << "Invalid server address." << std::endl;
        close(sockfd);
        return 1;
    }

    while (true) {
        // Generate a random temperature reading
        int temperature = dist(gen);

        // Convert temperature to string
        std::string temperature_str = std::to_string(temperature);

        // Send temperature reading to the server
        ssize_t sent_bytes = sendto(sockfd, temperature_str.c_str(), temperature_str.length(), 0,
                                    (struct sockaddr *) &server_address, sizeof(server_address));
        if (sent_bytes < 0) {
            std::cerr << "Failed to send temperature reading." << std::endl;
            close(sockfd);
            return 1;
        }

        // Print the temperature reading
        std::cout << "Temperature: " << temperature << "°C" << std::endl;

        // Wait for 1 second before generating the next reading
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // Close the socket
    close(sockfd);

    return 0;
}
