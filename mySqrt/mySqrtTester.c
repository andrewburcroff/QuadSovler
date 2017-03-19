#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "mySqrt.h"

void testMySqrt1(float a, float b, float disc, int test, float target);
void testMySqrt2(float a, float b, float disc, int test, float target);
float getTarget(float a, float b, float disc);

int main(){
	int test = 0;
	float a = 1.2, b = 2.3, c = 3.4;
	float disc = ((b*b) - (4*a*c));
	float target = getTarget(a, b, disc);	
	testMySqrt1(a, b, disc, ++test, target);
	testMySqrt2(a, b, disc, ++test, target);
	a = 2.3;
	b = 3.4;
	c = 4.5;
	disc = ((b*b) - (4*a*c));
	target = getTarget(a, b, disc);
	testMySqrt1(a, b, disc, ++test, target);
	testMySqrt2(a, b, disc, ++test, target);
	a = 3.4;
	b = 4.5;
	c = 5.6;
	disc = ((b*b) - (4*a*c));
	target = getTarget(a, b, disc);
	testMySqrt1(a, b, disc, ++test, target);
	testMySqrt2(a, b, disc, ++test, target);
	a = 123.123;
	b = 234.234;
	c = 456.456;
	disc = ((b*b) - (4*a*c));
	target = getTarget(a, b, disc);
	testMySqrt1(a, b, disc, ++test, target);
	testMySqrt2(a, b, disc, ++test, target);
	a = 12321;
	b = 98765;
	c = 1231.312;
	disc = ((b*b) - (4*a*c));
	target = getTarget(a, b, disc);
	testMySqrt1(a, b, disc, ++test, target);
	testMySqrt2(a, b, disc, ++test, target);
	a = 2341231.12;
	b = 35436543.112;
	c = 123.46;
	disc = ((b*b) - (4*a*c));
	target = getTarget(a, b, disc);
	testMySqrt1(a, b, disc, ++test, target);
	testMySqrt2(a, b, disc, ++test, target);
	a = 2131.21234;
	b = 90876.723;
	c = 42;
	disc = ((b*b) - (4*a*c));
	target = getTarget(a, b, disc);
	testMySqrt1(a, b, disc, ++test, target);
	testMySqrt2(a, b, disc, ++test, target);
	a = 987543;
	b = 24231;
	c = 6;
	disc = ((b*b) - (4*a*c));
	target = getTarget(a, b, disc);
	testMySqrt1(a, b, disc, ++test, target);
	testMySqrt2(a, b, disc, ++test, target);
	a = 123456;
	b = 123455;
	c = 123454;
	disc = ((b*b) - (4*a*c));
	target = getTarget(a, b, disc);
	testMySqrt1(a, b, disc, ++test, target);
	testMySqrt2(a, b, disc, ++test, target);
}

void testMySqrt1(float a, float b, float disc, int test, float target){
	if (findRoot1(a, b, disc) != target){
		printf("Test %i: ERROR Target = %.6lf.  Answer = %.6lf \n", test, target, findRoot1(a,b,disc));
	}
	else{
		printf("Test %i complete\n", test);	
	}
}

void testMySqrt2(float a, float b, float disc, int test, float target){
	if (findRoot2(a, b, disc) != target){
		printf("Test %i: ERROR Target = %.6lf.  Answer = %.6lf \n", test, target, findRoot2(a,b,disc));
	}
	else{
		printf("Test %i complete\n", test);	
	}
}

float getTarget(float a, float b, float disc){
	float target;	
	if (disc > 0){
		target = (-b+sqrt(disc))/(2*a);
	}
	else if(disc == 0){
		target = -b/2*a;
	}
	else{
		target = -1;
	}
	return target;
}
