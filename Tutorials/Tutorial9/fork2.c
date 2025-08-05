#include “stdio.h”
#include “unistd.h”
int main(int argc, char *argv[]){

	char *param[4];
	param[0] = “morphed”;
	param[1] = “55”;
	param[2] = “Second Command Parameter”;
	param[3] = NULL;
	param[4] = NULL;
	param[5] = NULL;
	
	pid = fork()
	
	if (pid == 0) {
	// child process instructions
	int rc;
	rc = execv(“./morphed”,param);
	printf(" This should not be printed \n"); //this should not be executed because the child is executing a new program
	
	} 
	else {
	// parent process instructions
	printf("Parent program \n");

	}
}
