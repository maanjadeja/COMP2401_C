#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <semaphore.h>

#include "fair.h"
#include "requestHandler.c"
#include "ride.c"
#include "display.c"


// Initialize a ride
void initializeRide(Ride *r, char *n, unsigned char tr, unsigned char cap,  unsigned char onOff, unsigned short rt, unsigned short wt) {
	r->name = n;
	r->ticketsRequired = tr;
	r->capacity = cap;
	r->onOffTime = onOff;
	r->rideTime = rt;
	r->waitTime = wt;
	r->lineupSize = 0;
	r->riders = (unsigned int *) malloc(sizeof(unsigned int) * r->capacity);
	if (r->riders == NULL) {
		printf("FAIR APP: Error allocating array for riders\n");
		exit(-1);
	}
	r->numRiders = 0;
	r->status = STOPPED;
}



// This is where it all begins
int main() {
	// Create a fair with no guests
	Fair	ottawaFair;
	ottawaFair.numGuests = 0;

	// Fill in the fair's ride information
	initializeRide(&(ottawaFair.rides[9]), "Ferris Wheel",   4, 32, 10, 600, 120);
	initializeRide(&(ottawaFair.rides[8]), "Pirate Ship",    4, 30,  5, 240, 120);
	initializeRide(&(ottawaFair.rides[7]), "Merry-Go-Round", 2, 25,  4, 240,  60);
	initializeRide(&(ottawaFair.rides[6]), "Roller Coaster", 5, 24,  5,  75,  60);
	initializeRide(&(ottawaFair.rides[5]), "Fun World",      1, 20,  1, 180,   1);
	initializeRide(&(ottawaFair.rides[4]), "Calm Train",     3, 16,  6, 300,  60);
	initializeRide(&(ottawaFair.rides[3]), "Back Destroyer", 4, 12, 10,  90,  30);
	initializeRide(&(ottawaFair.rides[2]), "Tea Cups",       3, 10, 10, 120,  60);
	initializeRide(&(ottawaFair.rides[1]), "Drop To Death",  5,  8, 20,  20,  30);
	initializeRide(&(ottawaFair.rides[0]), "Tummy Tosser",   5,  6,  7,  60,  30);

	// Start up the ride threads
	// ...
	pthread_t    rideThreads[NUM_RIDES];
	for(int i=0; i<NUM_RIDES; i++){

		pthread_create(&rideThreads[i], NULL, runRide, &ottawaFair.rides[i]); //...and pass in pointer to the ride from the fair that it is running

	}


	// Spawn a thread to handle incoming requests from guests
  	// ...
		pthread_t    serverThread;
		pthread_create(&serverThread, NULL, handleIncomingRequests, &ottawaFair);



  	// Spawn a thread to handle display
  	// ...
		pthread_t    displayThread;
		pthread_create(&displayThread, NULL, showSimulation, &ottawaFair);



    // Wait for the incoming requests thread to complete, from a STOP command
  	// ...
		pthread_join(serverThread, NULL); //.....Not sure if this is correct??????? Is this how we wait for the request handling thread to complete?


	// Shutdown the ride threads and free up the riders arrays
	// ...

				//.....Not sure if this is correct??????? Is this how we shut down all running threads and free up riders array, are we supposed to use pthread_exit????
			 //Change the status for all the rides in rideThreads -> 2nd argument in pthread_join is the status variable
			 //For any guest processes we will only have their ID's so we will have to call a appropriate function to exit the process



		for(int k=0; k<NUM_RIDES; k++){

			ottawaFair.rides[k].status=OFF_LINE;
			free(ottawaFair.rides[k].riders);

		}

  	// Kill all the guest processes for any guests remaining
  	// ...
		//we need to add pid and signal into this function
		for(int l=0; l<ottawaFair.numGuests; l++){

			kill(ottawaFair.guestIDs[l],SIGKILL); //we need to look for the kill command if the second parameter is correct: SIGUSR1 or SIGUSR2

		}



    printf("FAIR APP: ended successfully\n");
}
