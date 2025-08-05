#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "fair.h"



// This program takes 3 command line arguments.
// 1 - The number of tickets that the guest has (e.g., 5 to 40)
// 2 - The maximum time (in seconds) that the guest is willing to wait in line for a ride (e.g., 600 - 1200)
// 3 - The first ride that this guest wants to go on (i.e., 0 to NUM_RIDES)

void main(int argc, char *argv[]) {


	int 								clientSocket;
	struct sockaddr_in  serverAddress;
	int 								status, bytesRcv;
	char 								inStr[80]; // stores user input from keyboard
	char 								buffer[80]; // stores user input from keyboard

	// Create the client socket
	clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (clientSocket < 0) {

		printf("*** CLIENT ERROR: Could not open socket.\n");
		exit(-1);

	}

	// Setup address
	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = inet_addr(SERVER_IP);
	serverAddress.sin_port = htons((unsigned short) SERVER_PORT);

	// Connect to server
	status = connect(clientSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));

	if (status < 0) {

		printf("*** CLIENT ERROR: Could not connect.\n");
		exit(-1);

	}

	// Set the random seed
	srand(time(NULL));

	// Get the number of tickets, willing wait time and first ride from the command line arguments
  	// ...
		unsigned char numberOfTicketsOnGuest;
		unsigned short willingWaitTimeOnGuest;
		int firstRideGuestWantsToGoOn;

		numberOfTicketsOnGuest = (unsigned char)(atoi(argv[1]));
		willingWaitTimeOnGuest = (unsigned short)(atoi(argv[2]));
		firstRideGuestWantsToGoOn = atoi(argv[3]);

		printf("NUM TICKETS: %u \n",numberOfTicketsOnGuest);
		printf("WILLING WAIT TIME: %u \n",willingWaitTimeOnGuest);
		printf("FIRST RIDE GUEST WANTS: %d\n",firstRideGuestWantsToGoOn);


	// Request a admission to the fair.  If cannot get in (i.e., MAX_GUESTS reached), then quit.
	// ...

		char admissionCharValue[80];
		snprintf(admissionCharValue, sizeof(admissionCharValue), "%d", ADMIT);
		strcat(admissionCharValue, ",");
		signed int pid = getpid();
		char pidvalue[80];
		sprintf(pidvalue, "%d", pid);
		strcat(admissionCharValue, pidvalue);

		//find the endpoint of admissionCharValue so we can put in the guest process ID using getpid()!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		strcpy(buffer,admissionCharValue);
		printf("CLIENT: Sending \"%s\" to server.\n", buffer);
		send(clientSocket, buffer, strlen(buffer), 0);

	// Now simulate the going on rides until no more tickets remain (you will want to change the "1" here)
	while (1) {
		// Make sure that the guest has enough tickets for the desired ride
		// otherwise chose a different ride
		// ...


		// Get wait time estimate for that ride
		// ...


		// If the guest is willing to wait, then get into line for that ride
		// ...


		// Wait until the ride has boarded this guest, completed the ride and unboarded the guest
		// ...


		// Delay a bit (DO NOT CHANGE THIS LINE)
		//usleep(100000);
		usleep(1);

		// Choose a new ride at random
		// ...
	}

	// When out of tickets, inform the Fair that you are leaving
	// ...
}
