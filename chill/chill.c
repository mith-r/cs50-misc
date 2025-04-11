/*
 * chill.c Mithun Rameshkumar April 10,2025
 *
 * This file computes wind chill given temperature and wind speed.
 *
 * If the user runs the file with no arguments, the program will print 
 * out a table of temperatures (from -10 to +40 by 10's) and wind speeds
 * (from 5 to 15 by 5's).
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Computes the wind chill based on temperature and wind speed 
 * using the National Weather Service's formula
 *
 * Inputs:
 *  temp - temperature in degrees
 *  wind - wind speed in miles per hour
 *
 *Returns: 
 *  wind chill in degrees
 */

float windChill(float temp, float wind)
{
  return 35.74 + (0.6215 * temp) - (35.75*pow(wind, 0.16))
    + (0.4275 * temp * pow(wind, 0.16));
}

/*
 * Prints appropriate chart depending on number of inputs.
 * Inputs:
 *  inputTemp - if inputed, used as temp, if not marked as NAN
 *  inputWind - if inputed, used as wind, if not marked as NAN
 */

void printChart(float inputTemp, float inputWind)
{
  //Prints headings
  printf(" Temp   Wind  Chill\n");
  printf("-----  -----  -----\n");
  
  float temp = inputTemp;
  float maxTemp = temp; //Assuming temperature is inputed, sets max to equal input
  float tempInterval = 10.0;
  
  //if no input, sets defaults
  if (isnan(inputTemp)){
    temp = -10.0;
    maxTemp = 40.0;
  } 
   
  while (temp <= maxTemp){
    float wind = inputWind;
    float maxWind = wind; //Assuming wind is inputed, sets max to equal input
    float windInterval = 5.0;
    
    //if no input, sets default
    if (isnan(inputWind)){
      wind = 5.0;
      maxWind = 15.0;
    }

    while (wind <= maxWind){
      printf("%5.1f  %5.1f  %5.1f\n", temp, wind, windChill(temp, wind));
      wind += windInterval;
    }

    printf("\n");
    temp += tempInterval;
  }
}
  

int main(const int argc, const char* argv[])
{ 
  if (argc == 1) { //no input
    printChart(NAN, NAN);
  }
  else if (argc == 2) { //one input

    if (atof(argv[1]) > 50.0){ //error checking
      printf("./chill: Temperate must be less than or equal to 50.0 degrees Fahrenheit\n");
      return 1;
    }

    printChart(atoi(argv[1]), NAN);
  }
  else if (argc == 3) { //two inputs

   if (atof(argv[1]) > 50.0){ //error checking
      printf("./chill: Temperate must be less than or equal to 50.0 degrees Fahrenheit\n");
      return 1;
   }
   if (atof(argv[2]) < 0.5){ //error checkign
     printf("./chill: Wind velocity must be greater than or equal to 0.5 MPH\n");
     return 1;
   }

    printChart(atof(argv[1]), atof(argv[2]));
  }
  else { //if more than two arguments
    printf("Usage: ./chill [optional-temp] [optional-wind]\n");
    return 1;
  }
  
  return 0;
}



