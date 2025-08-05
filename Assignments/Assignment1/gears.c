#include<stdio.h>
#include<stdlib.h>

//Defining Pi Value
#define PI 3.14159265358979323846

int main(int argc, char **argv){
    //Variable Declaration
    int motorGear;                    //Number of teeth in motor gear
    int wheelGear;                    //Number of teeth in wheel gear
    int wheelDiameter;                //Diamater in cm of wheel attached to wheel gear
    int motorSpeed;                   //Speed of the motor in rpm (rotainos per minute)
    float ratioValue;                 //Store value of ratio of number of teeth of motor gear and wheel gear, depending on which one is greater
    float rpmValue;                   //Storing the value of rpm (motor speed * ratio value) after calculation
    float wheelCircumference;         //Storing the wheel's circumference after calulating pi * wheel diameter
    float circumferenceAndWheelSpeed; //Store value to help calculate km/h by multiplying wheel circumference and rpm value
    float kmPerHour;                  //Store valye of wheel speed in km/h
    float cmPerSecond;                //Store valye of wheel speed in cm/s

    //Prompting user to input data
    printf("Enter number of teeth in the motor gear: ");
    scanf("%d", &motorGear);
    printf("Enter number of teeth in the wheel gear: ");
    scanf("%d", &wheelGear);
    printf("Enter wheel diameter (in cm): ");
    scanf("%d", &wheelDiameter);
    printf("Enter the motor speed as rotations per minute (rpm): ");
    scanf("%d", &motorSpeed);

    //Handling the case where the number of teeth in the motor gear is greater than the number of teeth in the wheel gear
    if(motorGear > wheelGear){

      //Calculating the ratio value and presenting it to the user
      ratioValue = (float)motorGear/wheelGear;
      printf("The gear ratio is 1:%.1f\n",ratioValue);

      //Calculating the rpm value and presenting it to the user
      rpmValue = (float)motorSpeed * ratioValue;
      printf("At a motor speed of %d rpm, the speed of a %.2f cm diameter wheel is: %.2f rpm\n",motorSpeed, (float)wheelDiameter, rpmValue);

      //All below calculations are to find the the speed in cm/s and km/h
      wheelCircumference = PI * wheelDiameter;

      circumferenceAndWheelSpeed = wheelCircumference * rpmValue;

      kmPerHour = (circumferenceAndWheelSpeed * 60)/(100000);

      cmPerSecond = kmPerHour * 27.777778;

      //Presenting the speed in cm/s and km/h to the user
      printf("The wheel will move at %.2f cm per second  (i.e., %.2f km/h). \n",cmPerSecond, kmPerHour);


    }

    //Handling the case where the number of teeth in the wheel gear is greater than the number of teeth in the motor gear
    else{

      //Calculating the ratio value and presenting it to the user
      ratioValue = (float)wheelGear/motorGear;
      printf("The gear ratio is %.1f:1\n",ratioValue);

      //Calculating the rpm value and presenting it to the user
      rpmValue = (float)motorSpeed/ratioValue;
      printf("At a motor speed of %d rpm, the speed of a %.2f cm diameter wheel is: %.2f rpm\n",motorSpeed, (float)wheelDiameter, rpmValue);

      //All below calculations are to find the the speed in cm/s and km/h
      wheelCircumference = PI * wheelDiameter;

      circumferenceAndWheelSpeed = wheelCircumference * rpmValue;

      kmPerHour = (circumferenceAndWheelSpeed * 60)/(100000);

      cmPerSecond = kmPerHour * 27.777778;

      //Presenting the speed in cm/s and km/h to the user
      printf("The wheel will move at %.2f cm per second  (i.e., %.2f km/h). \n",cmPerSecond, kmPerHour);


    }


    return(0);
}
