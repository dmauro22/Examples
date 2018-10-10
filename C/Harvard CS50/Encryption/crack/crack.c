#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <cs50.h>

int keyCheck(char);

int main(int argc, char *argv[argc + 1])
{
    // Check to make sure correct number of arguments were passed to the program
    if (argc != 2)
    {
        return 1;
    }

    char *ref = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *test = (char *) malloc(128);
    char *salt = (char *) malloc(128);
    char *start = (char *) malloc(128);
    char *crypted = (char *) malloc(128);

    strncpy(salt, argv[1], 2);
    strncpy(start, argv[1], 13);

    for (int i = 0; i < 52; i++)
    {
        test[0] = ref[i];
        test[1] = '\0';
        crypted = crypt(test, salt);
        //printf("Crypted guess: %s\n", crypted);
        if (strcmp(crypted, start) == 0)
        {
            printf("%s\n", test);
            return 0;
        }

    }
    //printf("Cycle 1 done\n");



    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            test[0] = ref[i];
            test[1] = ref[j];
            test[2] = '\0';
            crypted = crypt(test, salt);
            if (strcmp(crypted, start) == 0)
            {
                printf("%s\n", test);
                return 0;
            }

        }
    }
    //printf("Cycle 2 done\n");

    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            for (int k = 0; k < 52; k++)
            {
                test[0] = ref[i];
                test[1] = ref[j];
                test[2] = ref[k];
                test[3] = '\0';
                crypted = crypt(test, salt);
                if (strcmp(crypted, start) == 0)
                {
                    printf("%s\n", test);
                    return 0;
                }
            }
        }
    }
    //printf("Cycle 3 done\n");

    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            for (int k = 0; k < 52; k++)
            {
                for (int l = 0; l < 52; l++)
                {
                    test[0] = ref[i];
                    test[1] = ref[j];
                    test[2] = ref[k];
                    test[3] = ref[l];
                    test[4] = '\0';
                    crypted = crypt(test, salt);
                    if (strcmp(crypted, start) == 0)
                    {
                        printf("%s\n", test);
                        return 0;
                    }
                }
            }
        }
    }
    //printf("Cycle 4 done\n");

    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            for (int k = 0; k < 52; k++)
            {
                for (int l = 0; l < 52; l++)
                {
                    for (int m = 0; m < 52; m++)
                    {
                        test[0] = ref[i];
                        test[1] = ref[j];
                        test[2] = ref[k];
                        test[3] = ref[l];
                        test[4] = ref[m];
                        test[5] = '\0';
                        crypted = crypt(test, salt);
                        if (strcmp(crypted, start) == 0)
                        {
                            printf("%s\n", test);
                            return 0;
                        }
                    }
                }
            }
        }
        //printf("Cycle 5, 1 of 52 done\n");
    }

    // If no matches, print nothing and return 0
    return 0;
}
