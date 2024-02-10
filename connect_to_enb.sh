#!/bin/bash

# Set the IP address and port of the eNB node
ENB_IP="192.168.1.100"  # Replace with the IP address of the eNB node
ENB_PORT=1234  # Replace with the port number of the eNB node

# Connect to the eNB node
echo "Connecting to eNB node at $ENB_IP:$ENB_PORT..."
nc -zvw3 $ENB_IP $ENB_PORT

# Check the connection status
if [ $? -eq 0 ]; then
    echo "Connected to eNB node successfully."
else
    echo "Failed to connect to eNB node."
fi

# Additional commands or configurations can be added here

# End of script
```
