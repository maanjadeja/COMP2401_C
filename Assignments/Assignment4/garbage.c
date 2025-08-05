#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "obstacles.h"
#include "display.h"


// This is a helper function that determines whether or not line segment
(v1---v2) intersects line segment (v3---v4)
unsigned char linesIntersect(short v1x, short v1y, short v2x, short v2y,
short v3x, short v3y, short v4x, short v4y) {
       float uA = ((v4x-v3x)*(v1y-v3y) - (v4y-v3y)*(v1x-v3x)) /
(float)(((v4y-v3y)*(v2x-v1x) - (v4x-v3x)*(v2y-v1y)));
       float uB = ((v2x-v1x)*(v1y-v3y) - (v2y-v1y)*(v1x-v3x)) /
(float)(((v4y-v3y)*(v2x-v1x) - (v4x-v3x)*(v2y-v1y)));

       // If uA and uB are between 0-1, there is an intersection
       if (uA > 0 && uA < 1 && uB > 0 && uB < 1)
         return 1;

     return 0;
}


TreeNode *findClosestNodeToRandomPoint(short xCoordinate, short
yCoordinate, Environment *env){

   int totalDistanceBetweenRandomPointAndNode = 9999999;


   TreeNode *theClosestNode = NULL;

   for(int i=0; i<env->numNodes; i++){

     int firstDifference = xCoordinate - env->rrt[i]->x;
     int secondDifference = yCoordinate - env->rrt[i]->y;


     //theClosestNode->x = env->rrt[i]->x;
     // theClosestNode->y = env->rrt[i]->y;


     if(totalDistanceBetweenRandomPointAndNode > (sqrt((firstDifference
* firstDifference) + (secondDifference * secondDifference)))){

       totalDistanceBetweenRandomPointAndNode = sqrt((firstDifference *
firstDifference) + (secondDifference * secondDifference));

       // theClosestNode->x = env->rrt[i]->x;
       //theClosestNode->y = env->rrt[i]->y;
       theCosestNode = env->rrt[i];

     }


   }

   return theClosestNode;


}

int checkIfRandomPointIsInObstacle(short xCoordinate, short yCoordinate,
Environment *env){


   if(((xCoordinate <= env->obstacles->x+env->obstacles->w) &&
(xCoordinate >= env->obstacles->x)) && ((yCoordinate <=
env->obstacles->y) && (yCoordinate >= env->obstacles->y -
env->obstacles->h))){

     return 1; //Coordinates are inside obstacles

   }
   else{
      return 0;
   }

}

TreeNode *findPointThatIsDistanceGrowthAmountFromClosestNode(short
xCoordinateOfPointQ, short yCoordinateOfPointQ, short
xCoordinateOfPointN, short yCoordinateOfPointN, Environment *env){

   short xCoordinate=0;
   short yCoordinate=0;

   short angle = atan2(yCoordinateOfPointQ-yCoordinateOfPointN,
xCoordinateOfPointQ-xCoordinateOfPointN);

   TreeNode *pointC = THE CLOSEST NODE PASSED IN

   pointC->x = xCoordinateOfPointN + (cos(angle) * env->growthAmount);
   pointC->y = yCoordinateOfPointN + (sin(angle) * env->growthAmount);

   return pointC;




}

int checkingForObstacleIntersect(TreeNode *pointN, TreeNode *pointC,
Environment *env){

   int result=0;


   if(linesIntersect(pointN->x, pointN->y, pointC->x, pointC->y,
env->obstacles->x, env->obstacles->y,
env->obstacles->x+env->obstacles->w, env->obstacles->y) != 0){

     result=1; //There is an intersection

   }

   else if(linesIntersect(pointN->x, pointN->y, pointC->x, pointC->y,
env->obstacles->x, env->obstacles->y, env->obstacles->x,
env->obstacles->y-env->obstacles->h) !=0){

     result=1;

   }
   else if(linesIntersect(pointN->x, pointN->y, pointC->x, pointC->y,
env->obstacles->x, env->obstacles->y-env->obstacles->h,
env->obstacles->x+env->obstacles->w,
env->obstacles->y-env->obstacles->h) !=0){

     result=1;

   }
   else if(linesIntersect(pointN->x, pointN->y, pointC->x, pointC->y,
env->obstacles->x+env->obstacles->w,
env->obstacles->y-env->obstacles->h,env->obstacles->x+env->obstacles->w,env->obstacles->y)
!=0){

     result=1;

   }
   else{

     result=0;

   }

   return result;







}



// Create a rrt using the growthAmount and maximumNodes parameters in
the given environment.
void createRRT(Environment *env) {

   /*if(env==NULL){
     printf("ENV IS NULL\n");
   }
   else{
     printf("ENV IS NOT NULL\n");

   }*/

   //Create array pf pointers and set env->rrt to that array
   env->rrt = (TreeNode **) malloc(env->maximumNodes * sizeof(TreeNode *));

   //printf("BEFORE THE IF STATEMENTS\n");
   //TreeNode **path[env->maximumNodes];
   if(env->rrt==NULL){

     exit(0);
   }




   //Create root node of with startX and startY
   TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode)); //we have to
dynamically allocate memory for this root, anything we add to the
pointersOfAllTreeNodes, it need to have allocated memory for it and we
must de-allocate it
   root->x = env->startX;
   root->y = env->startY;
   root->parent = NULL;
   root->firstChild = NULL;
   pointersOfAllTreeNodes[0] = root;
   env->numNodes = 1;

   //unsigned short indexOfThePointersOfAllTreeNodesArray=0;
   while (env->numNodes < env->maximumNodes) {
printf("Nodes so far: %d\n", env->numNodes);

     short randomXcoordinateOfPointQ = (rand() % (env->maximumX));
     short randomYcoordinateOfPointQ = (rand() % (env->maximumY));

printf("a\n");
while(checkIfRandomPointIsInObstacle(randomXcoordinateOfPointQ,randomYcoordinateOfPointQ,env)){

       randomXcoordinateOfPointQ = (rand() % (env->maximumX));
       randomYcoordinateOfPointQ = (rand() % (env->maximumY));

     }
printf("b\n");



     TreeNode *n =
findClosestNodeToRandomPoint(randomXcoordinateOfPointQ,randomYcoordinateOfPointQ,env);
printf("c\n");

  int cx, cy;

  findPointThatIsDistanceGrowthAmountFromClosestNode(randomXcoordinateOfPointQ,randomYcoordinateOfPointQ, n, &cx, &cy, env);
printf("d\n");

     Child *childOfPointN; //Add c as a child of point n
     childOfPointN->node=pointC;
     childOfPointN->nextSibling=NULL;
printf("e\n");

     if(checkingForObstacleIntersect(pointN,pointC,env)==0){
       ALLOCATE THE NEW NODE WITH COORDINATES (cx, cy)
       pointN->firstChild = childOfPointN;

     }
printf("f\n");






     //TreeNode *newTreeNode=NULL;
     //newTreeNode->x = randomXcoordinate;
     //newTreeNode->y = randomYcoordinate; //ADD THE COORDINATES TO THE
NEW TREENODE
     //newTreeNode->parent =
pointersOfAllTreeNodes[indexOfThePointersOfAllTreeNodesArray]; //SET THE
FIRST VALUE IN THE pointersOfAllTreeNodes ARRAY AS ITS Parent
//pointersOfAllTreeNodes[indexOfThePointersOfAllTreeNodesArray]->firstChild
= newTreeNode; // SET THE FIRST VALUE'S CHILD TO newTreeNode
//pointersOfAllTreeNodes[indexOfThePointersOfAllTreeNodesArray+1]=newTreeNode;
//ADD newTreeNode TO THE ARRAY

     env->numNodes++;


   }

   printf("AFTER EVERYTHING IN THE FUNCTION\n");


}


// Trace the path back from the node that is closest to the given (x,y)
coordinate to the root
void tracePath(Environment *env, unsigned short x, unsigned short y) {

}


// This procedure cleans up everything by creeing all alocated memory
void cleanupEverything(Environment *env) {
     free(env->obstacles);
}
