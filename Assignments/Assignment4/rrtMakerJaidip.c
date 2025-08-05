#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "obstacles.h"
#include "display.h"


// This is a helper function that determines whether or not line segment (v1---v2) intersects line segment (v3---v4)
unsigned char linesIntersect(short v1x, short v1y, short v2x, short v2y, short v3x, short v3y, short v4x, short v4y) {
  	float uA = ((v4x-v3x)*(v1y-v3y) - (v4y-v3y)*(v1x-v3x)) / (float)(((v4y-v3y)*(v2x-v1x) - (v4x-v3x)*(v2y-v1y)));
  	float uB = ((v2x-v1x)*(v1y-v3y) - (v2y-v1y)*(v1x-v3x)) / (float)(((v4y-v3y)*(v2x-v1x) - (v4x-v3x)*(v2y-v1y)));

    //printf("uA %f uB %f \n",uA,uB);
  	// If uA and uB are between 0-1, there is an intersection
  	if (uA > 0 && uA < 1 && uB > 0 && uB < 1)
		return 1;

	return 0;
}


TreeNode *findClosestNodeToRandomPoint(short xCoordinate, short yCoordinate, Environment *env){

  int totalDistanceBetweenRandomPointAndNode=9999999;


  TreeNode *theClosestNode = NULL;

  for(int i=0; i<env->numNodes; i++){

    //printf("x coordinate: %d at index: %d\n",env->rrt[i]->x,i);
    //printf("y coordinate: %d at index: %d\n",env->rrt[i]->y,i);


    int firstDifference = xCoordinate - env->rrt[i]->x;
    int secondDifference = yCoordinate - env->rrt[i]->y;


    //theClosestNode->x = env->rrt[i]->x;
    //theClosestNode->y = env->rrt[i]->y;


    if(totalDistanceBetweenRandomPointAndNode > (sqrt((firstDifference * firstDifference) + (secondDifference * secondDifference)))){

      totalDistanceBetweenRandomPointAndNode = sqrt((firstDifference * firstDifference) + (secondDifference * secondDifference));

      //theClosestNode->x = env->rrt[i]->x;
      //theClosestNode->y = env->rrt[i]->y;
      theClosestNode = env->rrt[i];


    }


  }

  return theClosestNode;


}

int checkIfRandomPointIsInObstacle(short xCoordinate, short yCoordinate, Environment *env){


  for(int i=0; i<env->numObstacles; i++){

    if(((xCoordinate <= env->obstacles[i].x+env->obstacles[i].w) && (xCoordinate >= env->obstacles[i].x)) && ((yCoordinate <= env->obstacles[i].y) && (yCoordinate >= env->obstacles[i].y - env->obstacles[i].h))){

      return 1; //Coordinates are inside obstacles

    }


  }

  return 0;



}

void findPointThatIsDistanceGrowthAmountFromClosestNode(short xCoordinateOfPointQ, short yCoordinateOfPointQ, short xCoordinateOfPointN, short yCoordinateOfPointN, TreeNode* theClosestNode, int* xCoordinateOfC, int* yCoordinateOfC,Environment *env){

  short xCoordinate=0;
  short yCoordinate=0;

  float angle = atan2(yCoordinateOfPointQ-yCoordinateOfPointN, xCoordinateOfPointQ-xCoordinateOfPointN);

  TreeNode *pointC = theClosestNode;


  *xCoordinateOfC = (int)(xCoordinateOfPointN + (cos(angle) * env->growthAmount));
  *yCoordinateOfC = (int)(yCoordinateOfPointN + (sin(angle) * env->growthAmount));




}

int checkingForObstacleIntersect(short xCoordinateOfFirstVertex, short yCoordinateOfFirstVertex, short xCoordinateOfSecondVertex, short yCoordinateOfSecondVertex, Environment *env){


  //int result=0;

  for(int i=0; i<env->numObstacles; i++){




    if(linesIntersect(xCoordinateOfFirstVertex, yCoordinateOfFirstVertex, xCoordinateOfSecondVertex, yCoordinateOfSecondVertex, env->obstacles[i].x, env->obstacles[i].y, env->obstacles[i].x+env->obstacles[i].w, env->obstacles[i].y) == 1){

      //top line
      return 1; //There is an intersection

    }

    if(linesIntersect(xCoordinateOfFirstVertex, yCoordinateOfFirstVertex, xCoordinateOfSecondVertex, yCoordinateOfSecondVertex, env->obstacles[i].x, env->obstacles[i].y, env->obstacles[i].x, env->obstacles[i].y-env->obstacles[i].h) == 1){

      /*printf("xCoordinateOfFirstVertex: %d\n",xCoordinateOfFirstVertex);
      printf("yCoordinateOfFirstVertex: %d\n",yCoordinateOfFirstVertex);
      printf("xCoordinateOfSecondVertex: %d\n",xCoordinateOfSecondVertex);
      printf("yCoordinateOfSecondVertex: %d\n",yCoordinateOfSecondVertex);
      printf("env->obstacles[i].x: %d\n",env->obstacles[i].x);
      printf("env->obstacles[i].y: %d\n",env->obstacles[i].y);
      printf("env->obstacles[i].x: %d\n",env->obstacles[i].x);
      printf("env->obstacles[i].y-env->obstacles[i].h: %d\n",env->obstacles[i].y-env->obstacles[i].h);*/

      //left line
      return 1; //There is an intersection

    }
    if(linesIntersect(xCoordinateOfFirstVertex, yCoordinateOfFirstVertex, xCoordinateOfSecondVertex, yCoordinateOfSecondVertex, env->obstacles[i].x, env->obstacles[i].y-env->obstacles[i].h, env->obstacles[i].x+env->obstacles[i].w, env->obstacles[i].y-env->obstacles[i].h) == 1){

      //bottom line
      return 1; //There is an intersection

    }
    if(linesIntersect(xCoordinateOfFirstVertex, yCoordinateOfFirstVertex, xCoordinateOfSecondVertex, yCoordinateOfSecondVertex, env->obstacles[i].x+env->obstacles[i].w, env->obstacles[i].y-env->obstacles[i].h,env->obstacles[i].x+env->obstacles[i].w,env->obstacles[i].y) == 1){

      //right line
      return 1; //There is an intersection

    }


  }


  return 0;


}



// Create a rrt using the growthAmount and maximumNodes parameters in the given environment.
void createRRT(Environment *env) {



  //Create array pf pointers and set env->rrt to that array
  env->rrt = (TreeNode **) malloc(env->maximumNodes * sizeof(TreeNode *));

  if(env->rrt == NULL){

    exit(-1);
  }

 
  //Create root node of with startX and startY
  TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode)); //we have to dynamically allocate memory for this root, anything we add to the pointersOfAllTreeNodes, it need to have allocated memory for it and we must de-allocate it

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




  //unsigned short indexOfThePointersOfAllTreeNodesArray=0;
  while (env->numNodes < env->maximumNodes) {


    short randomXcoordinateOfPointQ = (rand() % (env->maximumX));
    short randomYcoordinateOfPointQ = (rand() % (env->maximumY));

    TreeNode *n = findClosestNodeToRandomPoint(randomXcoordinateOfPointQ,randomYcoordinateOfPointQ,env);


    int xCoordinateOfC=0;
    int yCoordinateOfC=0;

    findPointThatIsDistanceGrowthAmountFromClosestNode(randomXcoordinateOfPointQ,randomYcoordinateOfPointQ, n->x, n->y, n, &xCoordinateOfC, &yCoordinateOfC, env);


    //TreeNode *pointC =

    while((checkIfRandomPointIsInObstacle(xCoordinateOfC,yCoordinateOfC,env)==1) || (checkingForObstacleIntersect(n->x,n->y,xCoordinateOfC,yCoordinateOfC,env)==1)){

      randomXcoordinateOfPointQ = (rand() % (env->maximumX));
      randomYcoordinateOfPointQ = (rand() % (env->maximumY));

    
      n = findClosestNodeToRandomPoint(randomXcoordinateOfPointQ,randomYcoordinateOfPointQ,env);


      findPointThatIsDistanceGrowthAmountFromClosestNode(randomXcoordinateOfPointQ,randomYcoordinateOfPointQ, n->x, n->y, n, &xCoordinateOfC, &yCoordinateOfC, env);

    }

//jay: no need for following two statment
   // n->parent = NULL;
    //n->firstChild = NULL;


//jay: we alredy checkd same before so takeout this
   // if(checkingForObstacleIntersect(n->x,n->y,xCoordinateOfC,yCoordinateOfC,env)==0){


      TreeNode *newNode = (TreeNode *) malloc(sizeof(TreeNode)); //we have to dynamically allocate memory for this root, anything we add to the pointersOfAllTreeNodes, it need to have allocated memory for it and we must de-allocate it
      newNode->x = xCoordinateOfC;
      newNode->y = yCoordinateOfC;
      newNode->parent = n;
      //jay: check for nullability of n
      //this will help to find when we don't have parent - segementation error in trace
      //lines are drawn from node to first child/sibiling way so that issue is happning in following section
      
      //newNode->firstChild = NULL;

      Child *newChild = (Child *) malloc(sizeof(Child));
      newChild->node = newNode;
      newChild->nextSibling=NULL;

      if((n->firstChild)==NULL){
        n->firstChild = newChild;
      }
      else{

      //  jay: no need for memeroy allocation so taking out
        //Child *theNewChild = (Child *) malloc(sizeof(Child));
        theNewChild = n->firstChild;

        while(theNewChild->nextSibling!=NULL){

          //jay: this should correct breaks 
          //we need to navigate to next sibiling and take ass thenNewChild
          theNewChild = theNewChild->nextSibling;
          //corrected from following
         // theNewChild = n->firstChild->nextSibling;

        }

        theNewChild->nextSibling->node = newNode;
       
       //jay:following wrong .. not always next sibling
       // n->firstChild->nextSibling=theNewChild;



      //}jay: as if commented out

      printf("env->rrt[env->numNodes-1] indexValue: %d\n",env->numNodes-1);
      env->rrt[env->numNodes] = newNode;
      env->numNodes++;



      //pointN->firstChild = childOfPointN;

    }







    //TreeNode *newTreeNode=NULL;
    //newTreeNode->x = randomXcoordinate;
    //newTreeNode->y = randomYcoordinate; //ADD THE COORDINATES TO THE NEW TREENODE
    //newTreeNode->parent = pointersOfAllTreeNodes[indexOfThePointersOfAllTreeNodesArray]; //SET THE FIRST VALUE IN THE pointersOfAllTreeNodes ARRAY AS ITS Parent
    //pointersOfAllTreeNodes[indexOfThePointersOfAllTreeNodesArray]->firstChild = newTreeNode; // SET THE FIRST VALUE'S CHILD TO newTreeNode
    //pointersOfAllTreeNodes[indexOfThePointersOfAllTreeNodesArray+1]=newTreeNode; //ADD newTreeNode TO THE ARRAY

    //env->numNodes++;


  }

  printf("AFTER EVERYTHING IN THE FUNCTION\n");


}


// Trace the path back from the node that is closest to the given (x,y) coordinate to the root
void tracePath(Environment *env, unsigned short x, unsigned short y) {

  TreeNode *theClosestNode = findClosestNodeToRandomPoint(x,y,env);

  TreeNode *rootNode = env->rrt[0];

  TreeNode *currentNode = theClosestNode;

  int numberOfNodesInTheArray=0;

  while((currentNode->parent)!=rootNode){ //ERROR IS CAUSING HERE BECAUSE THE NODES THAT WERE PRESENT ON THE TREE ALL ARE NOT CONNECTED

    numberOfNodesInTheArray++;
    currentNode = currentNode->parent;

  }

  env->path = (TreeNode **) malloc(numberOfNodesInTheArray * sizeof(TreeNode *));









}


// This procedure cleans up everything by creeing all alocated memory
void cleanupEverything(Environment *env) {
	free(env->obstacles);

  free(env->rrt);

  for(int i=0; i<env->numNodes; i++){

    free(env->rrt[i]);

  }
  free(env->path);
  for(int j=0; j<env->numNodes; j++){

    free(env->path[j]);

  }
}
