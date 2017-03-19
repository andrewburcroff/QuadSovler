#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
This mehtod will call three parameters. It will find the discriminant or what is in the square root part of the equation.
Then it print the discriminat, and return that value that it represents.
*/

float getDiscriminant(float a, float b, float c)
{
	float discriminant = b*b-(4*a*c);//Figuring out the discriminant for by being the sqaure part of the equation.
	printf("discriminant is %.8lf\n", discriminant);//Printing out the value of the discriminant 
	return discriminant;//return the value of the discriminant 
}//end of method
