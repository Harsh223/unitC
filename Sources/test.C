/*
 * File:   test.c
 * Author: Harsh Kumar
 *
 * @see https://harsh.one
 *
 * Created on 01 June 2022, 03:56
 */

#include <stdio.h>
#include <stdlib.h>
#include "unitC.h"

// This is a test function
int func(int x, int y)
{
     assert(x != y);
     return x * y + 1;
}


int main(void)
{

    unitC_test("Test of Zero values:", assert(func(0, 0) < 2));
    unitC_test("Test of Positive Integers:", assert(func(1, 1) < 2));
    unitC_test("Test of Negative Integers:", assert(func(-1, -2)< 2));
    unitC_feedback(); // Getting Feedback and Report of all the tests
    return 0;
}
