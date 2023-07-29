// Function to calculate the Square root of a number

#include <stdio.h>
#include <stdbool.h>

// Declare Functions
float absoluteValue (float); // Function to calculate the absolute value of a number
float squareRoot (float); // Function to calculate the square root of a number

int main(void) {

  // Calculate square roots
  printf ("squareRoot(2.0) = %f\n", squareRoot(2.0));
  printf ("squareRoot(144.0) = %f\n", squareRoot(144.0));
  printf ("squareRoot(17.5) = %f\n", squareRoot(17.5));

  return 0;
}

// Define Functions

float absoluteValue (float x) {
  if (x < 0)
    x *= -1;

  return x;
}

float squareRoot (float x) {
  const float epsilon = .01;
  const float upperBound = 1 + epsilon;
  const float lowerBound = 1 - epsilon;
  
  float guess = 1;
  float ratio = absoluteValue (guess / x);
  bool withinRange = false;

  while (!withinRange) {
    
    // Test if "guess" is within tolerance
    if (lowerBound <= ratio && ratio <= upperBound) {
      withinRange = true;
    }
    else {
      // Update guess
      guess = (x / guess + guess) / 2.0;
      
      // Update ratio
      ratio = absoluteValue (guess * guess / x);
    }
  } 

  return guess;
}