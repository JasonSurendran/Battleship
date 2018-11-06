# Battleship

This is an networking program that creates a “server” and a “client”, which both communicate
using TCP/IP protocol style standards in their connections.
When both the server and client are connected, the client is prompted with a input asking for a tag word. 
This input is echoed to the server which searches api.flicker for sample xml data which contains the
inputted tag before echoing it back to the client.  

## Pre-requisites 

- Java JDK (Any version from Java 8 or above works)
- Java IDE (Any Java IDE works)

## Setup and Build

To setup, follow these steps below. 

Files setup:
  - Download zip files and unzip the folder after download
  - Import Java project into IDE
  - Ensure that your Java JDK is added to the project


## Running (From IDE)

To run from IDE, follow the steps below:

1. Open the project in the IDE
2. Navigate to the ServerMain file and run it
3. Navigate to the ClientMain file and run it 
4. Input tag when prompted
5. Let the process run and check console to see if xml is echoed back to client
6. Enjoy!


## Note
   - Server and Client both use Port 5000. 
   - Navigate to the ServerMain and the ClientMain files to change port if needed
