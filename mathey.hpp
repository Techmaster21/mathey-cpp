// NOTE: I think including a function definiton like this in a header file is a no-no, but
// I'd have to refer to my material (I could instead make a library out of it(maybe?))
#ifndef MatheyH     // This should keep the compiler from including the header
#define MatheyH     // twice
#ifdef __cplusplus  // If we're using a C++ compiler, declare the functions as
extern "C" {        // external C functions
#endif
void startagain();
int matrix();
int calc();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus  // If we're using a C++ compiler, give us some headers for 
                    // our clean function
#include <iostream>
#include <limits>

using namespace std;

#else               // Otherwise, give us a different header for our C-based
                    // clean function
#include <stdio.h>

#endif

static void clean() // Declared as static to prevent compiler from including 
{                   // twice and complaining about an error it caused >.>
                    // I think 'inline' would also work.
#ifdef __cplusplus  // If using C++ compiler, define one way
   cin.clear();     // Clears any set error bits
   cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    //^ Flushes the input buffer
#else               // Otherwise, define the other way
    char f;         // For cleaning stdin before passing to an outside function 
                    // that requires input(Fixes various bugs)
    while ((f=getchar()) != '\n' && f != EOF); //Making stdin squeeky clean
#endif
}
#endif
