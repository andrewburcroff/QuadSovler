
//header files
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

void checkSolution(float a, int num){
	if(a == -1){//Check if value passed in is -1 to tell if the value is complex.
		printf("Root %i: is complex \n", num);//Tells user that this float is complex
	}
	else{
	    printf("Root %i: %.7lf\n", num, a);//Returns float that is NOT-complex.
	}
}
