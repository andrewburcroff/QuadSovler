#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <ctype.h>

float [] promptParser();
float [] promptParserTest();


float [] promptParser(){
float abc[3];
int counter = 0;
double digit;
char *token;
char usrIn [100];
char *usrPtr;
  while(counter != 3){
    printf("Please enter a number greater than 0: ");
    scanf("%s",usrIn );
    printf("%s\n",usrIn);
    digit = strtod(usrIn,NULL);

    if(digit != 0){
    printf("This works! %lf\n",digit);
    abc[counter] = digit;
    counter++;
  }
  else{
    printf("This was an invalid input.Try again!\n");
  }

 }
return abc;
}

promptParserTest(){
FILE * fp;
fp = fopen("TestFile.txt","r");
float abc[3];
int counter = 0;
double digit;
char *token;
char usrIn [100];
char *usrPtr;
while(fgets(usrIn,sizeof(usrIn),fp)!=NULL){
  while(counter != 3){
    printf("Please enter a number greater than 0: ");
    fgets(usrIn,sizeof(usrIn),fp);
    digit = strtod(usrIn,NULL);

    if(digit > 0){
    printf("This works! %lf\n",digit);
    abc[counter] = digit;
    counter++;
  }
  else{
    printf("This was an invalid input.Try again!\n");
  }

 }
}
}
