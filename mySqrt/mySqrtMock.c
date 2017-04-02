#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mySqrtMock.h"

void mockFindRoot1(float a, float b, float discriminant, float sqrt, float expRoot){
	/*printf("Finding root 1\n");*/
	float root;
	if(discriminant > 0)
	{
		root = (-b+sqrt)/(2*a);	
		//printf("root = %f\n", root);
		if(root != expRoot)
		{
			printf("Failure with root 1: root %.6f != expectedRoot %.6f\n", root, expRoot);
		}
	}	
}

void mockFindRoot2(float a, float b, float discriminant, float sqrt, float expRoot){
	/*printf("Finding root 2\n");*/
	float root;
	if(discriminant > 0)
	{
		root = (b+sqrt)/(2*a);
		//printf("root = %f\n", root);
		if(root != expRoot)
		{
			printf("Failure with root 2: root %.6f != expectedRoot %.6f\n", root, expRoot);
		}
	}	
}
