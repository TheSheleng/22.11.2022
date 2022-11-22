#pragma once

#ifndef FIRSTDLL_API
#define FIRSTDLL_API extern "C" __declspec(dllimport)
#endif

FIRSTDLL_API float Sum(float a, float b);
FIRSTDLL_API float Min(float a, float b);
FIRSTDLL_API float Mult(float a, float b);
FIRSTDLL_API float Div(float a, float b);