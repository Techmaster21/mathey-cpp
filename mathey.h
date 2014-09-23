// NOTE: ITS LIKE SUPER BAD PRACTICE TO INCLUDE FUNCTION DEFINITIONS IN HEADER 
// FILES. DON'T DO IT. I'm just doing it until I convert the whole thing to C++ 
// then I'll move it to a static library or something

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
