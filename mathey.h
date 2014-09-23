// NOTE: I think including a function definiton like this in a header file is a no-no, but
// I'd have to refer to my material (I could instead make a library out of it(maybe?))
void help();
#ifdef __cplusplus
extern "C" {
#endif
void startagain();
int matrix();
int calc();
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include <iostream>
#include <limits>
#include <string>

using namespace std;

#else

#include <stdio.h>

#endif
static void clean()
{
#ifdef __cplusplus
   cin.clear(); // Clears any set error bits
   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Flushes the
                                                                 // input buffer
#else
    char f; //For cleaning stdin before passing to an outside function that requires input(Fixes various bugs)
    while ((f=getchar()) != '\n' && f != EOF); //Making stdin squeeky clean
#endif
}
