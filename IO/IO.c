/*
 This file is used to get the input by the user and parses the arguments it also makes sure that the input is valid 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "IO.h"

void promptParser(float abc[]){
	int counter = 0;
	double digit;
	char usrIn [100];
	while(counter != 3){
	    printf("Please enter a number greater than 0: ");
	    scanf("%s",usrIn );
	   	printf("%s\n",usrIn);
	    digit = strtod(usrIn,NULL);
	    if(digit != 0){
		    //printf("This works! %lf\n",digit);
		    abc[counter] = digit;
		    counter++;
		}
		else{
			printf("This was an invalid input.Try again!\n");
		}
	}
}
