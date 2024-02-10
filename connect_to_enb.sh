#!/bin/bash

# Set the serial port parameters
SERIAL_PORT="/dev/ttyUSB0"  # Replace with the appropriate serial port
BAUD_RATE=115200  # Replace with the desired baud rate

# Set the IP address and port of the eNB node
ENB_IP="192.168.1.100"  # Replace with the IP address of the eNB node
ENB_PORT=1234  # Replace with the port number of the eNB node

# Start minicom to establish the serial connection
echo "Starting minicom..."
minicom -b $BAUD_RATE -D $SERIAL_PORT -C enb.log

# Check if minicom was started successfully
if [ $? -eq 0 ]; then
    echo "minicom started successfully."
else
    echo "Failed to start minicom."
    exit 1
fi

# Send AT command to establish the connection with the eNB node
echo "Sending AT command to establish connection..."
echo "AT+CONNECT=$ENB_IP:$ENB_PORT" | tee -a $SERIAL_PORT


