#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <ctype.h>
#include "IOTest.h"

void promptParserTest(float abc[]){
	FILE * fp;
	fp = fopen("TestFile.txt","r");
	double digit;
	char usrIn [100];
	while(fgets(usrIn,sizeof(usrIn),fp)!=NULL){
		digit = strtod(usrIn,NULL);
		if(digit > 0){
			printf("Input = %lf\n",digit);
		}
		else{
			printf("This was an invalid input.Try again!\n");
		}
	}
}
