/***********************************************************************
Report sizeof() values, and the machine epsilon and smallest
floating-point number, to investigate floating-point support.

[21-Nov-2001]
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "args.h"

#if defined(HAVE_LONG_DOUBLE)
typedef long double LONG_DOUBLE;
#else
typedef double LONG_DOUBLE;
#endif

#if STDC
float fstore(float x)
#else
float fstore(x)
float x;
#endif
{
    return (x);
}

#if STDC
double dstore(double x)
#else
double dstore(x)
double x;
#endif
{
    return (x);
}

#if defined(HAVE_LONG_DOUBLE)

#if STDC
LONG_DOUBLE ldstore(LONG_DOUBLE x)
#else
LONG_DOUBLE 
ldstore(x)
LONG_DOUBLE x;
#endif

{
    return (x);
}

#if STDC
LONG_DOUBLE fppow2(int n)
#else
LONG_DOUBLE 
fppow2(n)
int n;
#endif
{
    LONG_DOUBLE x, power;
    x = (n < 0) ? ((LONG_DOUBLE)1.0/(LONG_DOUBLE)2.0) : (LONG_DOUBLE)2.0;
    n = (n < 0) ? -n : n;
    power = (LONG_DOUBLE)1.0;
    while (n-- > 0)
	power *= x;
    return (power);
}
#else

#if STDC
double fppow2(int n)
#else
double fppow2(n)
int n;
#endif
{
    double x, power;
    x = (n < 0) ? ((LONG_DOUBLE)1.0/(LONG_DOUBLE)2.0) : (LONG_DOUBLE)2.0;
    n = (n < 0) ? -n : n;
    power = (LONG_DOUBLE)1.0;
    while (n-- > 0)
	power *= x;
    return (power);
}
#endif

void test_float(VOID_ARG)
{
    float x;

    (void)printf("float:\n");

    (void)printf("\tsizeof(float) =              %2u\n", (unsigned int)sizeof(float));
    (void)printf("\tFLT_MANT_DIG =               %2d\n", FLT_MANT_DIG);

    x = (float)1.0;
    while (fstore((float)1.0 + x/(float)2.0) != (float)1.0)
	x /= (float)2.0;
    (void)printf("\tmachine epsilon =           %13.5e  ", x);

    if (x == (float)fppow2(-23))
	(void)printf("[IEEE 754 32-bit macheps]\n");
    else
	(void)printf("[not IEEE 754 conformant]\n");

    x = (float)1.0;
    while (fstore(x / (float)2.0) != (float)0.0)
	x /= (float)2.0;
    (void)printf("\tsmallest positive number =  %13.5e  ", x);

    if (x == (float)fppow2(-149))
	(void)printf("[IEEE 754 smallest 32-bit subnormal]\n");
    else if (x == (float)fppow2(-126))
	(void)printf("[IEEE 754 smallest 32-bit normal]\n");
    else
	(void)printf("[not IEEE 754 conformant]\n");
    (void)printf("\n");
}

void test_double(VOID_ARG)
{
    double x;

    (void)printf("double:\n");

    (void)printf("\tsizeof(double) =             %2u\n", (unsigned int)sizeof(double));
    (void)printf("\tDBL_MANT_DIG =               %2d\n", DBL_MANT_DIG);

    x = 1.0;
    while (dstore(1.0 + x/2.0) != 1.0)
	x /= 2.0;
    (void)printf("\tmachine epsilon =           %13.5le  ", x);

    if (x == (double)fppow2(-52))
	(void)printf("[IEEE 754 64-bit macheps]\n");
    else
	(void)printf("[not IEEE 754 conformant]\n");

    x = 1.0;
    while (dstore(x / 2.0) != 0.0)
	x /= 2.0;
    (void)printf("\tsmallest positive number =  %13.5le  ", x);

    if (x == (double)fppow2(-1074))
	(void)printf("[IEEE 754 smallest 64-bit subnormal]\n");
    else if (x == (double)fppow2(-1022))
	(void)printf("[IEEE 754 smallest 64-bit normal]\n");
    else
	(void)printf("[not IEEE 754 conformant]\n");
    (void)printf("\n");
}

void test_long_double(VOID_ARG)
{
#if defined(HAVE_LONG_DOUBLE)
    LONG_DOUBLE x;

    (void)printf("LONG_DOUBLE:%s\n",
		 (sizeof(double) == sizeof(LONG_DOUBLE)) ?
		 "  [**WARNING**: LONG_DOUBLE is really double]" : "");

    (void)printf("\tsizeof(LONG_DOUBLE) =        %2u\n", (unsigned int)sizeof(LONG_DOUBLE));
    (void)printf("\tLDBL_MANT_DIG =             %3d\n", LDBL_MANT_DIG);

    x = (LONG_DOUBLE)1.0;
    while (ldstore((LONG_DOUBLE)1.0 + x/(LONG_DOUBLE)2.0) != (LONG_DOUBLE)1.0)
	x /= (LONG_DOUBLE)2.0;
    (void)printf("\tmachine epsilon =           %13.5Le  ", x);

    if (x == (LONG_DOUBLE)fppow2(-52))
	(void)printf("[IEEE 754 64-bit macheps]\n");
    else if (x == (LONG_DOUBLE)fppow2(-63))
	(void)printf("[IEEE 754 80-bit macheps]\n");
    else if (x == (LONG_DOUBLE)fppow2(-112))
	(void)printf("[IEEE 754 128-bit macheps]\n");
    else
	(void)printf("[not IEEE 754 conformant]\n");

    x = (LONG_DOUBLE)1.0;
    while (ldstore(x / (LONG_DOUBLE)2.0) != (LONG_DOUBLE)0.0)
	x /= (LONG_DOUBLE)2.0;
    (void)printf("\tsmallest positive number =  %13.5Le  ", x);

#if LDBL_MANT_DIG == 53
    if (x == (LONG_DOUBLE)fppow2(-1074))
	(void)printf("[IEEE 754 smallest 64-bit subnormal]\n");
    else if (x == (LONG_DOUBLE)fppow2(-1022))
	(void)printf("[IEEE 754 smallest 64-bit normal]\n");
    else
	(void)printf("[not IEEE 754 conformant]\n");
#elif LDBL_MANT_DIG == 64
    if (x == (LONG_DOUBLE)fppow2(-16446))
	(void)printf("[IEEE 754 smallest 80-bit subnormal]\n");
    else if (x == (LONG_DOUBLE)fppow2(-16382))
	(void)printf("[IEEE 754 smallest 80-bit normal]\n");
    else
	(void)printf("[not IEEE 754 conformant]\n");
#elif LDBL_MANT_DIG == 113
    if (x == (LONG_DOUBLE)fppow2(-16494))
	(void)printf("[IEEE 754 smallest 128-bit subnormal]\n");
    else if (x == (LONG_DOUBLE)fppow2(-16382))
	(void)printf("[IEEE 754 smallest 128-bit normal]\n");
    else
	(void)printf("[not IEEE 754 conformant]\n");
#else
    (void)printf("[not IEEE 754 conformant]\n");
#endif

#endif
    (void)printf("\n");
}


int
main(VOID_ARG)
{
    test_float();
    test_double();
    test_long_double();

    return (EXIT_SUCCESS);
}

