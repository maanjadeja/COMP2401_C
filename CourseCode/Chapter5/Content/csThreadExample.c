#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <semaphore.h>

#define  NUM_COMMANDS   4
#define  BUFFER_SIZE    30

// This will be used to ensure that only one client communicates with
// the server at a time, so that the variables below are used properly
sem_t   serverBusyIndicator;

// These are the variables used to pass data between threads
char    requestBuffer[BUFFER_SIZE];   // data from client to server
char    responseBuffer[BUFFER_SIZE];  // data from server to client
char    requestReady = 0;    // flag to tell server that request is ready
char    responseReady = 0;   // flag to tell client that response is ready

// These are the commands sent from each client
char   *clientCommands[NUM_COMMANDS] = {"Hello ", "Funny", "Stuff", "STOP"};

// Set up the client so that it sends 4 commands
void *runClient(void *num) {
  int  command = 0;

  // Go into infinite loop to communicate with server now
  while (command < NUM_COMMANDS) {
    // Wait for the server
    sem_wait(&serverBusyIndicator);

    // Send command string to server
    requestBuffer[0] = ((char *)num)[0];
    strcpy(requestBuffer+1, clientCommands[command++]);
    printf("CLIENT: Sending \"%s\" to server.\n", requestBuffer);
    requestReady = 1;

    // Get response from server, should be "OK"
    while (responseReady == 0); // wait for a response

    printf("CLIENT: Got back response \"%s\" from server.\n\n", responseBuffer);
    responseReady = 0;

    // Tell the server we are done
    sem_post(&serverBusyIndicator);

    // Sleep from 0 to 4 seconds randomly
    sleep((int)(rand()/(double)RAND_MAX*5));
  }
}


void *runServer(void *notUsed) {
  // repeat forever
  while (1) {
    // Wait for an incoming client request
    while (requestReady == 0); // wait for a request

    // Get/Receive the message from the client into the char buffer
    requestReady = 0; // reset for next time
    printf("SERVER: Received client request: %s\n", requestBuffer);

    // Respond with an "OK" message
    responseBuffer[0] = requestBuffer[0];
    strcpy(responseBuffer+1, "OK\0");
    printf("SERVER: Sending \"%s\" to client\n", responseBuffer);
    responseReady = 1;

    // Quit if someone sent a STOP command
    if (strcmp(&requestBuffer[1], "STOP") == 0)
      break;
  }

  printf("SERVER: Shutting down.\n");
}


// This main function starts a server and then three clients.
int main() {
  pthread_t    serverThread;
  pthread_t    client[3];

  srand(time(NULL));

  // Initialize semaphore
  sem_init(&serverBusyIndicator, 0, 1);

  // Start the server
  pthread_create(&serverThread, NULL, runServer, NULL);

  // Start up 3 client threads
  pthread_create(&client[0], NULL, runClient, "1");
  pthread_create(&client[1], NULL, runClient, "2");
  pthread_create(&client[2], NULL, runClient, "3");

  // Wait for the server to come back
  pthread_join(serverThread, NULL);
}
