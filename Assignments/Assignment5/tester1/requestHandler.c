#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <semaphore.h>
#include <sched.h>


// Handle client requests coming in through the server socket.  This code should run
// indefinitiely.  It should wait for a client to send a request, process it, and then
// close the client connection and wait for another client.  The requests that may be
// handled are as follows:
//
//   SHUTDOWN - causes the fair server to go offline.  No response is returned.
//
//   ADMIT - contains guest's process ID as well. return a list of all rides and their
//			 ticketRequirements.
//
//	 GET_WAIT_ESTIMATE - takes a ride ID as well.   It then returns an estimate as to
//						 how long of a wait (in seconds) the guest would have to wait
//						 in order to get on the ride.
//
//	 GET_IN_LINE - takes a ride ID and guest's process ID as well.  It then causes the
//				   guest to get in line for the specified ride ... assuming that the
//				   ride ID was valid and that the line hasn't reached its maximum.
//				   An OK response should be returned if all went well, otherwise NO.
//
//   LEAVE_FAIR - takes a guest's process ID.  It then causes the guest to leave the fair.
//				  No response is returned.

void *handleIncomingRequests(void *x) {

	int 							 serverSocket, clientSocket;
	struct sockaddr_in serverAddress, clientAddr;
	int 							 status, addrSize, bytesRcv;
	char 							 buffer[30];
	char 							 *response = "";

	// Create the server socket
	serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serverSocket < 0) {

	printf("*** SERVER ERROR: Could not open socket.\n");
	exit(-1);

	}

	// Setup the server address
	memset(&serverAddress, 0, sizeof(serverAddress)); // zeros the struct
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddress.sin_port = htons((unsigned short) SERVER_PORT);

	// Bind the server socket
	status = bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

	if (status < 0) {

	printf("*** SERVER ERROR: Could not bind socket.\n");
	exit(-1);

	}

	// Set up the line-up to handle up to MAX_GUESTS in line
	status = listen(serverSocket, MAX_GUESTS);
	if (status < 0) {

	printf("*** SERVER ERROR: Could not listen on socket.\n");
	exit(-1);

	}
	while(1){

 sched_yield();

		addrSize = sizeof(clientAddr);
	 clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddr, &addrSize);
	 if (clientSocket < 0) {
		 printf("*** SERVER ERROR: Could not accept incoming client connection.\n");
		 exit(-1);
	 }
	 printf("SERVER: Received client connection.\n");


		//// Go into infinite loop to talk to client
		//while(1){

 sched_yield();
		memset(buffer,0,sizeof(buffer));
		bytesRcv = recv(clientSocket, buffer, sizeof(buffer), 0);
		buffer[bytesRcv] = 0; // put a 0 at the end so we can display the string

		char bufferVariable = buffer[0];
		int incomingRequest = (int)(bufferVariable-'0');

		printf("\n");

		printf("THE WHOLE BUFFER: %s\n",buffer);
		printf("FIRST ARGUMENT (REQUEST): %d\n",incomingRequest);

		int numberOfCommasInTheBuffer=0;
		for(int k=0; k<strlen(buffer); k++){
			if(buffer[k]==','){
				numberOfCommasInTheBuffer++;
			}
		}


		int commaIndex[numberOfCommasInTheBuffer];//size of this array should be dynamic
    int commaCounter=0;
    for(int i=0; i<strlen(buffer); i++){
        if(buffer[i]==','){

            commaIndex[commaCounter] = i;
            commaCounter++;

        }
    }

		char secondArgument[30]={0};//second argument, original: afterCommaDetails, after: secondArgument
		int indexOfSecondArgument=0;
		char thirdArgument[30]={0};
		int indexOfThirdArgument=0;

		printf("THE TOTAL NUMBER OF COMMAS IN THE BUFFER: %d\n",numberOfCommasInTheBuffer);

		switch(numberOfCommasInTheBuffer){

			case 1:
				printf("NUMBER OF COMMAS CASE: %d\n",numberOfCommasInTheBuffer);

				for(int m=commaIndex[0]+1; m<strlen(buffer); m++){

					secondArgument[indexOfSecondArgument] = buffer[m];
					indexOfSecondArgument++;

				}

				break;

			case 2: //three arguments
				printf("NUMBER OF COMMAS CASE: %d\n",numberOfCommasInTheBuffer);
				indexOfSecondArgument=0;
				indexOfThirdArgument=0;

				for(int n=commaIndex[0]+1; n<commaIndex[1]; n++){

					secondArgument[indexOfSecondArgument] = buffer[n];
					indexOfSecondArgument++;

				}

				for(int o=commaIndex[1]+1; o<strlen(buffer); o++){

					thirdArgument[indexOfThirdArgument] = buffer[o];
					indexOfThirdArgument++;

				}

				break;


		}//switch completed

		printf("SECOND ARGUMENT AS A STRING: %s\n",secondArgument);
		printf("THIRD ARGUMENT AS A STRING: %s\n",thirdArgument);

		int secondArgumentAsInt;
		secondArgumentAsInt = atoi(secondArgument);

		int thirdArgumentAsInt;
		thirdArgumentAsInt = atoi(thirdArgument);

		printf("SECOND ARGUMENT AS AN INT: %d\n",secondArgumentAsInt);
		printf("THIRD ARGUMENT AS AN INT: %d\n",thirdArgumentAsInt);
		printf("\n");



		usleep(100000);
		//usleep(1);

		Fair *theFair = (Fair *)x;

		//Set up a switch statement to handle each case
		switch(incomingRequest){	//We are supposed to look at the first value in bytesRcv OR buffer?

			case ADMIT:

				printf("IN ADMIT CASE!\n");

				if(theFair->numGuests == MAX_GUESTS){
					printf("THERE IS NO ROOM FOR GUEST TO BE ADMITTED AS THERE ARE ALREADY MAXGUESTS PRESENT\n");
					break;
				}
				else{

					theFair->guestIDs[theFair->numGuests] = (unsigned int)secondArgumentAsInt;
					theFair->numGuests++;

					char *allRideAndTickets="";


					for(int j=0; j<NUM_RIDES; j++){


						char rideNameAndRideTickets[(RIDE_NAME_MAX_CHARS+3)*NUM_RIDES];

						strcat(rideNameAndRideTickets, theFair->rides[j].name);


						char dash = '-';
						strncat(rideNameAndRideTickets, &dash,1);

						int numberOfTicketsRequiredForRide = (int)theFair->rides[j].ticketsRequired;

						char stringTickets[2];

						sprintf(stringTickets, "%d", numberOfTicketsRequiredForRide);

						strcat(rideNameAndRideTickets,stringTickets);

						strcat(rideNameAndRideTickets,",");

						response = rideNameAndRideTickets;


					}

					printf("SERVER: Sending \"%s\" to client\n", response);
					send(clientSocket, response, strlen(response), 0);



				}

				break;




			case GET_WAIT_ESTIMATE:

				printf("IN GET_WAIT_ESTIMATE CASE\n");

				//need to do the num tickets guest has for ride checking here??????

				float guestInLineOverRideCapacity = (theFair->rides[secondArgumentAsInt].lineupSize)/(theFair->rides[secondArgumentAsInt].capacity);

				float rideCombinedRunningLoadingUnloadingTime = (theFair->rides[secondArgumentAsInt].onOffTime)*(theFair->rides[secondArgumentAsInt].capacity*2) + theFair->rides[secondArgumentAsInt].rideTime;

				float finalValue = guestInLineOverRideCapacity*rideCombinedRunningLoadingUnloadingTime;

				char waitTimeInSeconds[RIDE_NAME_MAX_CHARS];

				int theTotalWaitTimeInSeconds = (int)finalValue;

				char stringFormOfWaitTime[RIDE_NAME_MAX_CHARS];
				sprintf(stringFormOfWaitTime, "%d", theTotalWaitTimeInSeconds);

				strcpy(waitTimeInSeconds,stringFormOfWaitTime);

				response = waitTimeInSeconds;

				printf("SERVER: Sending \"%s\" to client\n", response);

				send(clientSocket, response, strlen(response), 0);



				break;

				/*int rideIndex = (int)buffer[2];	//DOUBLE CHECK THE BUFFER INDEX VALUES FOR THE DETAILS ASKED!!!!

				float guestInLineOverRideCapacity = (x->rides[rideIndex].lineupSize)/(x->rides[rideIndex].capacity);

				int rideCombinedRunningLoadingUnloadingTime = (x->rides[rideIndex].onOffTime)*(x->rides[rideIndex].capacity*2) + x->rides[rideIndex].rideTime; //Is this how we have to do the calculation??

				int finalValue = (int)guestInLineOverRideCapacity*rideCombinedRunningLoadingUnloadingTime;
				//SOME ERRORS HERE!!!! How to convert int to string so we can add it to response variable and do send command

				break;*/


			case GET_IN_LINE:

				printf("IN GET_IN_LINE CASE\n");

				/*int rideIndex = (int)buffer[2];	//DOUBLE CHECK THE BUFFER INDEX VALUES FOR THE DETAILS ASKED!!!!

				if((x->rides[rideIndex].lineupSize == MAX_LINEUP) || (rideIndex<0 || rideIndex>9)){
					break;
				}
				else{

					x->rides[rideIndex].waitingLine[x->rides[rideIndex].lineupSize] = buffer[3]; //location of the guest process ID is buffer[3]????

				}

				break;*/



			case LEAVE_FAIR:

				/*unsigned int guestProcessId = buffer[2];	//DOUBLE CHECK THE BUFFER INDEX VALUES FOR THE DETAILS ASKED!!!!

				for(int i=0; i<NUM_RIDES; i++){

					if(x->guestIDs[i] == guestProcessId){

						x->guestIDs[i]=NULL; //remove the guest from the guest process ID array

					}
					else{

						break; //the guest process ID Was not present in the array

					}

				}

				break;*/



			case SHUTDOWN:

			// Don't forget to close the sockets!
			close(serverSocket);
			printf("SERVER: Shutting down.\n");


		}




	//}

}


}
