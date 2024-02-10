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
