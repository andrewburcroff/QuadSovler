#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mySqrtMock.h"

void mockFindRoot1(float a, float b, float discriminant, float sqrt, float expRoot);
void mockFindRoot2(float a, float b, float discriminant, float sqrt, float expRoot);

int main(){
	float a = 1, b = 1;
	float disc = 1;	/*Filler*/
	float sqrt = 2;
	float expRoot = (-b+sqrt)/(2*a);
	mockFindRoot1(a,b,disc,sqrt,expRoot);
	expRoot = (b+sqrt)/(2*a);
	mockFindRoot2(a,b,disc,sqrt,expRoot);	
	a = 2;
	b = 2;
	sqrt = 8;
	expRoot = (-b+sqrt)/(2*a);
	mockFindRoot1(a,b,disc,sqrt,expRoot);
	expRoot = (b+sqrt)/(2*a);
	mockFindRoot2(a,b,disc,sqrt,expRoot);
	a = 3;
	b = 3;
	sqrt = 13;
	expRoot = (-b+sqrt)/(2*a);
	mockFindRoot1(a,b,disc,sqrt,expRoot);
	expRoot = (b+sqrt)/(2*a);
	mockFindRoot2(a,b,disc,sqrt,expRoot); 
}
