#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "obstacles.h"
#include "display.h"


// This is a helper function that determines whether or not line segment (v1---v2) intersects line segment (v3---v4)
unsigned char linesIntersect(short v1x, short v1y, short v2x, short v2y, short v3x, short v3y, short v4x, short v4y) {

  	float uA = ((v4x-v3x)*(v1y-v3y) - (v4y-v3y)*(v1x-v3x)) / (float)(((v4y-v3y)*(v2x-v1x) - (v4x-v3x)*(v2y-v1y)));
  	float uB = ((v2x-v1x)*(v1y-v3y) - (v2y-v1y)*(v1x-v3x)) / (float)(((v4y-v3y)*(v2x-v1x) - (v4x-v3x)*(v2y-v1y)));

  	// If uA and uB are between 0-1, there is an intersection
  	if (uA > 0 && uA < 1 && uB > 0 && uB < 1)
		return 1;

	return 0;
}


TreeNode *findClosestNodeToRandomPoint(short xCoordinate, short yCoordinate, Environment *env){

  int totalDistanceBetweenRandomPointAndNode=9999999;  //Initialize a large value to begin with, so we can update it to smaller values as we go along


  TreeNode *theClosestNode = NULL;    //Create a new TreeNode where we will set the closest node found to

  for(int i=0; i<env->numNodes; i++){


    //Math formula for distance between 2 points is sqrt((x2-x1)^2 + (y2-y1)^2)

    int firstDifference = xCoordinate - env->rrt[i]->x; //Here we store x2-x1
    int secondDifference = yCoordinate - env->rrt[i]->y; //Here we store y2-y1


    if(totalDistanceBetweenRandomPointAndNode > (sqrt((firstDifference * firstDifference) + (secondDifference * secondDifference)))){

      totalDistanceBetweenRandomPointAndNode = sqrt((firstDifference * firstDifference) + (secondDifference * secondDifference)); //Update the total distance until we find the smallest value

      theClosestNode = env->rrt[i]; //Set theClosestNode to the node we found that is closest to the random point
      theClosestNode->parent = env->rrt[i]->parent; //Set the nodes parent and firstChild according to the env->rrt[i] node
      theClosestNode->firstChild = env->rrt[i]->firstChild;


    }


  }

  return theClosestNode;

}


int checkIfRandomPointIsInObstacle(short xCoordinate, short yCoordinate, Environment *env){

  for(int i=0; i<env->numObstacles; i++){

    //Specify the boundaries as given in the assignment
    if(((xCoordinate <= env->obstacles[i].x+env->obstacles[i].w) && (xCoordinate >= env->obstacles[i].x)) && ((yCoordinate <= env->obstacles[i].y) && (yCoordinate >= env->obstacles[i].y - env->obstacles[i].h))){

      return 1; //Coordinates are inside obstacles

    }


  }

  return 0; //Coordinates are outside the block

}


void findPointThatIsDistanceGrowthAmountFromClosestNode(short xCoordinateOfPointQ, short yCoordinateOfPointQ, short xCoordinateOfPointN, short yCoordinateOfPointN, TreeNode* theClosestNode, int* xCoordinateOfC, int* yCoordinateOfC,Environment *env){


  float angle = atan2(yCoordinateOfPointQ-yCoordinateOfPointN, xCoordinateOfPointQ-xCoordinateOfPointN); //Calculate the angle as given in the specification


  *xCoordinateOfC = (int)(xCoordinateOfPointN + (cos(angle) * env->growthAmount));  //Calculate x coordinate of c as given in the assignment
  *yCoordinateOfC = (int)(yCoordinateOfPointN + (sin(angle) * env->growthAmount));  //Calculate y coordinate of c as given in the assignment

}


int checkingForObstacleIntersect(short xCoordinateOfFirstVertex, short yCoordinateOfFirstVertex, short xCoordinateOfSecondVertex, short yCoordinateOfSecondVertex, Environment *env){

  for(int i=0; i<env->numObstacles; i++){

    if(linesIntersect(xCoordinateOfFirstVertex, yCoordinateOfFirstVertex, xCoordinateOfSecondVertex, yCoordinateOfSecondVertex, env->obstacles[i].x, env->obstacles[i].y, env->obstacles[i].x+env->obstacles[i].w, env->obstacles[i].y) == 1){

      //Boundaries of top line of the obstacle
      return 1; //There is an intersection

    }

    if(linesIntersect(xCoordinateOfFirstVertex, yCoordinateOfFirstVertex, xCoordinateOfSecondVertex, yCoordinateOfSecondVertex, env->obstacles[i].x, env->obstacles[i].y, env->obstacles[i].x, env->obstacles[i].y-env->obstacles[i].h) == 1){

      //Boundaries of left line of the obstacle
      return 1; //There is an intersection

    }
    if(linesIntersect(xCoordinateOfFirstVertex, yCoordinateOfFirstVertex, xCoordinateOfSecondVertex, yCoordinateOfSecondVertex, env->obstacles[i].x, env->obstacles[i].y-env->obstacles[i].h, env->obstacles[i].x+env->obstacles[i].w, env->obstacles[i].y-env->obstacles[i].h) == 1){

      //Boundaries of bottom line of the obstacle
      return 1; //There is an intersection

    }
    if(linesIntersect(xCoordinateOfFirstVertex, yCoordinateOfFirstVertex, xCoordinateOfSecondVertex, yCoordinateOfSecondVertex, env->obstacles[i].x+env->obstacles[i].w, env->obstacles[i].y-env->obstacles[i].h,env->obstacles[i].x+env->obstacles[i].w,env->obstacles[i].y) == 1){

      //Boundaries of right line of the obstacle
      return 1; //There is an intersection

    }


  }


  return 0; //There is no intersection

}



// Create a rrt using the growthAmount and maximumNodes parameters in the given environment.
void createRRT(Environment *env) {

  //Dynamically allocate an array of TreeNode pointers and set env->rrt to that array
  env->rrt = (TreeNode **) malloc(env->maximumNodes * sizeof(TreeNode *));

  if(env->rrt == NULL){
    exit(-1);
  }

  //Create root node of with startX and startY
  TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode)); //we have to dynamically allocate memory for this root, anything we add to the pointersOfAllTreeNodes, it need to have allocated memory for it and we must de-allocate it

  //Checking if root is NULL, if it is not then we set the required values to it
  if(root == NULL){
    exit(-1);
  }
  else{

    root->x = env->startX;
    root->y = env->startY;
    root->parent = NULL;
    root->firstChild = NULL;
    env->rrt[0] = root;
    env->numNodes = 1;

  }

  //While loop for when numNodes is less than maximumNodes to add nodes to the tree
  while (env->numNodes < env->maximumNodes) {


    short randomXcoordinateOfPointQ = (rand() % (env->maximumX)); //Calculate random value for x coordinate of Q in boundary of maximumX
    short randomYcoordinateOfPointQ = (rand() % (env->maximumY)); //Calculate random value for y coordinate of Q in boundary of maximumY


    TreeNode *n = findClosestNodeToRandomPoint(randomXcoordinateOfPointQ,randomYcoordinateOfPointQ,env);  //Create a TreeNode (n in specification) that is closes to the random point calculated above


    int xCoordinateOfC=0; //Intitialize x coordinate of c to 0 as we will change it by calling its address in findPointThatIsDistanceGrowthAmountFromClosestNode() function
    int yCoordinateOfC=0; //Intitialize y coordinate of c to 0 as we will change it by calling its address in findPointThatIsDistanceGrowthAmountFromClosestNode() function

    findPointThatIsDistanceGrowthAmountFromClosestNode(randomXcoordinateOfPointQ,randomYcoordinateOfPointQ, n->x, n->y, n, &xCoordinateOfC, &yCoordinateOfC, env);

    //Create while loop when coordinates are intersecting with loop so we can update the values such that they dont intersect with an obstacle
    while((checkIfRandomPointIsInObstacle(xCoordinateOfC,yCoordinateOfC,env)==1) || (checkingForObstacleIntersect(n->x,n->y,xCoordinateOfC,yCoordinateOfC,env)==1)){

      randomXcoordinateOfPointQ = (rand() % (env->maximumX));
      randomYcoordinateOfPointQ = (rand() % (env->maximumY));

      n = findClosestNodeToRandomPoint(randomXcoordinateOfPointQ,randomYcoordinateOfPointQ,env);


      findPointThatIsDistanceGrowthAmountFromClosestNode(randomXcoordinateOfPointQ,randomYcoordinateOfPointQ, n->x, n->y, n, &xCoordinateOfC, &yCoordinateOfC, env);

    }

    n->parent = NULL; //Set the parent to NULL as it will be set below
    n->firstChild = NULL; //Set the firstChild to NULL as it will be set below


    if(checkingForObstacleIntersect(n->x,n->y,xCoordinateOfC,yCoordinateOfC,env)==0){ //Checking that there is not intersection of point n and c with an obstacle


      TreeNode *newNode = (TreeNode *) malloc(sizeof(TreeNode)); //we have to dynamically allocate memory for this newNode, anything we add to the pointersOfAllTreeNodes, it need to have allocated memory for it and we must de-allocate it
      //Initialize newNode x and y coordinate to coordinates of C
      newNode->x = xCoordinateOfC;
      newNode->y = yCoordinateOfC;
      if(n==NULL){  //Checking if the n is NULL and updating if necessary, otherise set its values

        n = findClosestNodeToRandomPoint(randomXcoordinateOfPointQ,randomYcoordinateOfPointQ,env);

      }
      else{

        newNode->parent = n;  //Set the newNode's paretn to n as given in the specification

      }

      //Create a Child form of the newNode so we can store it into the nextSibling
      Child *newChild = (Child *) malloc(sizeof(Child));
      newChild->node = newNode;
      newChild->nextSibling=NULL;

      if((n->firstChild)==NULL){  //Checking if the n->firstChild is NULL and updating if necessary, otherise set its values
        n->firstChild = newChild;
      }
      else{


        Child *currentChild = n->firstChild;  //Create a Child variable to help navigate the singly-linked list and find an empty space to add the newNode

        while(currentChild->nextSibling!=NULL){

          currentChild = n->firstChild->nextSibling;  //Update currentChild until we find a value that is NULL so we can set it to newNode

        }


        currentChild->nextSibling->node = newNode;  //Set the null location in the singly-linked list to the newNode we created

      }

      env->rrt[env->numNodes] = newNode;  //Add newNode to the rrt array
      env->numNodes++;  //Update numNodes to help while loop proceed


    }

  }


}


// Trace the path back from the node that is closest to the given (x,y) coordinate to the root
void tracePath(Environment *env, unsigned short x, unsigned short y) {

  /*TreeNode *theClosestNode = findClosestNodeToRandomPoint(x,y,env);               //Find the closest node to the given x and y coordinates in the parameters

  TreeNode *rootNode = env->rrt[0];                                                 //Create a TreeNode that stores the root so we can compare it when we reach it while tracing back

  TreeNode *currentNode = theClosestNode;                                           //Create a TreeNode that stores the current location of where it is tracing

  int numberOfNodesInTheArray=0;                                                    //Add a counter variable that will store the number of nodes we travelled through to trace back, and also set the size of dynamically allocated path array

  while((currentNode->parent)!=rootNode){                                           //While loop to update currentNode and numberOfNodesInTheArray

    numberOfNodesInTheArray++;
    currentNode = currentNode->parent;

  }

  env->path = (TreeNode **) malloc(numberOfNodesInTheArray * sizeof(TreeNode *));*/ // Create a dynamically allocated path array that has a size of numberOfNodesInTheArray




}


// This procedure cleans up everything by creeing all alocated memory
void cleanupEverything(Environment *env) {
	free(env->obstacles);

  free(env->rrt);                       //Free the environment rrt array

  for(int i=0; i<env->numNodes; i++){

    free(env->rrt[i]);                  //Free the values in the environment rrt array

  }
  free(env->path);                      //Free the environment path array

  for(int j=0; j<env->numNodes; j++){

    free(env->path[j]);                 //Free values in the environment path array

  }
}
