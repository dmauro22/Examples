#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *name = (char *) malloc(128);
    //char *initials = (char *) malloc(128);
    printf("Name: ");
    *name = 'D';
    name[1] = 'E';
    *(name + 2) = 'H';
    name[3] = '\0';

    //scanf("%s",name);

    printf("%s\n",name);
    return 0;
}
