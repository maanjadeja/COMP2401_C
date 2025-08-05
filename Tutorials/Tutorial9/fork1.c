

#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>

int main()
{ 
    int pid;
    int i=0;
    
    printf("Ready to fork...\n"); 
    pid = fork();	// create a clone
    printf("Fork returned %d\n",pid); 
    
    pid = fork();
    
    if(pid==0){
    
    // child process instructions
 
   	printf("Child process pid=%d parent process id=%d \n",getpid(), getppid());
	return(55);	
    
    }
    else if(pid>0){
    
    	// parent process instructions
	printf("\t Parent process pid=%d child process id=%d \n",getpid(), pid);
	int cpid = wait(&status)
	printf("\t Parent process cpid=%d child process id=%d" \n,cpid,pid);
	
	return(0);
    }
    else{
    
    	// pid < 0 – an error occurred during the form operation
	printf("\t ERROR - parent process pid=%d could not fork a child process \n",getpid());
	return(1);
	
    }
    
    

    /*for (i = 0; i < 3; i++){
        printf("%d: in foor loop \n",pid);
        sleep(1);
        i++;
	}*/

}

