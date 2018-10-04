#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *name = (char *) malloc(128);

    // Initializing the values by alternating between 
    // array and pointer notation
    *name = 'D';
    name[1] = 'a';
    *(name + 2) = 'n';
    name[3] = '\0';

    // Printing tha values by alternating between
    // array and pointer notation
    printf("%c\n", name[0]);
    printf("%c\n", *(name + 1));
    printf("%c\n", name[2]);
    
    // The full name
    printf("%s\n", name);
    
    return 0;
}
