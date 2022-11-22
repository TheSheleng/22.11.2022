#define FIRSTDLL_API extern "C" __declspec(dllexport)

#include "Main.h"

FIRSTDLL_API float Sum(float a, float b)
{
	return a + b;
}

FIRSTDLL_API float Min(float a, float b)
{
	return a - b;
}

FIRSTDLL_API float Mult(float a, float b)
{
	return a * b;
}

FIRSTDLL_API float Div(float a, float b)
{
	if (b == 0) throw "Can't divide by zero\n";
	return a / b;
}