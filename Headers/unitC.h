/*
 * File:   unitC.h
 * Author: Harsh Kumar
 *
 * @see https://harsh.one
 *
 * Created on 22 May 2022, 03:56
 */

#ifndef UNITC_H_INCLUDED
#define UNITC_H_INCLUDED

#ifdef NDEBUG
#undef NDEBUG
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <setjmp.h>
#include <signal.h>

int unitc_test_case;
int unitc_test_pass;
jmp_buf unitc_jmpbuf;

static void unitc_signal(int field)
{
  longjmp(unitc_jmpbuf, 1);
}


#define unitC_test(message, test)  do                        \
{                                                             \
    printf("Test %d %s ... ", unitc_test_case, message);       \
    signal(SIGABRT, unitc_signal);                              \
    ++unitc_test_case;                                           \
    if (!setjmp(unitc_jmpbuf))                                    \
        {                                                          \
      test;                                                         \
      puts("CASE PASSED\n");                                         \
      ++unitc_test_pass;                                              \
    }                                                                  \
    else                                                                \
    {                                                                    \
      puts("CASE FAILED\n");                                              \
    }                                                                      \
    fflush(stdin);                                                          \
  }                                                                          \
  while (0)



#define unitC_feedback() do                                                   \
{                                                                              \
  if(unitc_test_case == unitc_test_pass)                                        \
  {                                                                              \
    printf("TOTAL TESTS: %d \nALL TEST CASES PASSED\n",unitc_test_case);          \
    }                                                                              \
  else                                                                              \
    {                                                                                \
        printf("TOTAL TESTS: %d \nFAILED TESTS: %d                                    \
           \nPASSED TESTS : %d \n",unitc_test_case, unitc_test_case -                  \
           unitc_test_pass, unitc_test_pass);                                           \
        }                                                                                \
  unitc_test_pass = 0;                                                                    \
  unitc_test_case = 0;                                                                     \
  }                                                                                         \
  while (0)




#endif // UNITC_H_INCLUDED


