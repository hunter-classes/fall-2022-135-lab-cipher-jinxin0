#include <cctype>
#include "funcs.h"

// A helper function to shift one character by rshift
char shiftChar(char c, int rshift)
{
    char starting_character = -1;

    if (std::islower(c))
        starting_character = 'a';
    if (std::isupper(c))
        starting_character = 'A';

    if (starting_character == -1)
        return c;
    
    return ((c - starting_character + rshift) % 26) + starting_character;
}
