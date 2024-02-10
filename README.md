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
### connect_to_enb.sh ###

In this updated script, you need to replace the `SERIAL_PORT` variable with the appropriate serial port that corresponds to your GL-M2 router. You can check the available serial ports using the `ls /dev/tty*` command.

The script starts `minicom` with the specified baud rate (`BAUD_RATE`) and serial port (`SERIAL_PORT`). It also appends the output to a log file (`enb.log`) for further analysis if needed.

After starting `minicom`, the script sends the AT command `AT+CONNECT=$ENB_IP:$ENB_PORT` to establish the connection with the eNB node over the air. The command is sent using `tee -a $SERIAL_PORT`, which both sends the command and appends it to the serial port for `minicom` to transmit.

You can save this script to a file (e.g., `connect_to_enb.sh`), make it executable using `chmod +x connect_to_enb.sh`, and then run it on your GL-M2 router. Make sure to replace the variables `SERIAL_PORT`, `BAUD_RATE`, `ENB_IP`, and `ENB_PORT` with the appropriate values.
Do not run this outside a properly prepared and tested RF testing enclosure.

**********************************
