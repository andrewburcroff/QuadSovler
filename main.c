#include <stdio.h>
#include "mySqrt.h"
#include "qSolve.h"
#include <stdlib.h>
#include "output.h"
#include "IO.h"

int main(){
	float values[3];
	float a, b, c, discriminant, root1, root2;
	promptParser(values);
	a = values[0];
	printf("a = %lf\n", a);
	b = values[1];
	printf("b = %lf\n", b);
	c = values[2];
	printf("c = %lf\n", c);
	discriminant = getDiscriminant(a,b,c);
	root1 = findRoot1(a,b, discriminant);
	root2 = findRoot2(a,b, discriminant);
	checkSolution(root1, 1);
	checkSolution(root2, 2);
	return 0;
}
