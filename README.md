# GL-M2
temperature readings via 5g

# Temperature Sensor


> A C++ program to send temperature readings from a 5g dev board.

## Description

This program simulates temperature readings. It generates random temperature values and sends them to a specific IP address using sockets in C++. The temperature readings can be used to monitor the temperatures remotely.

## Features

- Generates random temperature readings
- Sends temperature readings to a specified IP address
- Simulates real-time data transmission
- Easy to integrate with existing systems

## Getting Started

### Dependencies

- C++ compiler
- Sockets library

### Building

1. Clone the repository.
2. Compile the program:
g++ main.cpp -o temperature-sensor


### Usage

1. Modify the `IP_ADDRESS` constant in the code with the desired IP address.
2. Run the program:
./temperature-sensor

  
3. The program will start sending temperature readings to the specified IP address.

***********************************
###connect_to_enb.sh###

In this script, you need to replace the `ENB_IP` variable with the actual IP address of your eNB node, and `ENB_PORT` with the appropriate port number. 

The script uses the `nc` command (netcat) to initiate a connection to the eNB node. The `-z` option checks if the connection is successful, and the `-v` option provides verbose output. If the connection is successful, it prints a success message; otherwise, it prints a failure message.

You can save this script to a file (e.g., `connect_to_enb.sh`), make it executable using `chmod +x connect_to_enb.sh`, and then run it on startup or as needed. Do not run this outside a properly prepared and tested RF testing enclosure.

**********************************
