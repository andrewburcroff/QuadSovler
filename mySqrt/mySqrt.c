/*This file contains 2 functions that both return the root of a quadratic equation.
 *Each function accepts 3 floats.  If the discriminant is negative, then it returns an error code for output.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

float findRoot1(float a, float b, float discriminant)
{
	/*printf("Finding root 1\n");*/
	if(discriminant > 0)
	{
		return (-b+sqrt(discriminant))/(2*a);
	}
	else if(discriminant == 0)
	{
		return -b/2*a;
	}
	else
	{
		/*printf("discriminant is negative\n");*/
		return -1;
	}	
}

float findRoot2(float a, float b, float discriminant)
{
	/*printf("Finding root 2\n");*/
	if(discriminant > 0)
	{
		return (-b-sqrt(discriminant))/(2*a);
	}
	else if(discriminant == 0)
	{
		return -b/2*a;
	}
	else
	{
		/*printf("discriminant is negative\n");*/
		return -1;
	}	
}


