#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "qSolve.h"

void testqSolve(float a, float b, float c, float target, int test);

int main(){
	int test = 0;
	float a = 1.2, b = 2.3, c = 3.4;
	float disc = ((b*b) - (4*a*c));
	testqSolve(a, b, c, disc, ++test);
	a = 2.3;
	b = 3.4;
	c = 4.5;
	disc = ((b*b) - (4*a*c));
	testqSolve(a, b, c, disc, ++test);
	a = 3.4;
	b = 4.5;
	c = 5.6;
	disc = ((b*b) - (4*a*c));
	testqSolve(a, b, c, disc, ++test);
	a = 123.123;
	b = 234.234;
	c = 456.456;
	disc = ((b*b) - (4*a*c));
	testqSolve(a, b, c, disc, ++test);
	a = 12321;
	b = 98765;
	c = 1231.312;
	disc = ((b*b) - (4*a*c));
	testqSolve(a, b, c, disc, ++test);
	a = 2341231.12;
	b = 35436543.112;
	c = 123.46;
	disc = ((b*b) - (4*a*c));
	testqSolve(a, b, c, disc, ++test);
	a = 2131.21234;
	b = 90876.723;
	c = 42;
	disc = ((b*b) - (4*a*c));
	testqSolve(a, b, c, disc, ++test);
	a = 987543;
	b = 24231;
	c = 6;
	disc = ((b*b) - (4*a*c));
	testqSolve(a, b, c, disc, ++test);
	a = 123456;
	b = 123455;
	c = 123454;
	disc = ((b*b) - (4*a*c));
	testqSolve(a, b, c, disc, ++test);
}

void testqSolve(float a, float b, float c, float target, int test)
	if ((getDiscriminant(a,b,c)) != target){
		printf("Test %i: ERROR Target = %.6lf.  Answer = %.2lf \n", test, target, getDiscriminant(a,b,c));
	}
	else{
		printf("Test %i complete\n", test);	
	}
}
