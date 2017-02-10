/*
* Project Title: Quad Solver
* Names: Max Ellsberry, Stephen Wimsatt, Mohammed Rasak, Andrew Burcroff
* This program is our Quad Solver, it will ask the user to input A, B, and
* C for the equation. Then it will determine if the three variables are
* valid. If found false it will ask the user for another input. If found true
* then it will print out the answer for those given variables. In the end it
* will return V1 and V2.
*/

#include<stdio.h>
#include<math.h>

int main(){
  float a,b,c;

  printf("Enter a for the quadratic equation: ");
  scanf("%f",&a);
  printf("Enter b for the quadratic equation: ");
  scanf("%f",&b);
  printf("Enter c for the quadratic equation: ");
  scanf("%f",&c);

  printf("%f %f %f\n",&a , &b, &c);
}
//this work
//Wimsatt - I am attempting to add something to this.
