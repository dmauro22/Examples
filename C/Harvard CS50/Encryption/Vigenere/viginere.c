#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function that converts all lower case to upper
int keyCheck(char);

int main(int argc, char *argv[argc + 1])
{
    int length = 0;
    int keyLength = 0;
    int temp = 0;
    int index = 0;
    char *key = (char *) malloc(128);
    char *in = (char *) malloc(128);
    char *cipher = (char *) malloc(128);

    // Check to make sure a key has been passed to the function
    if (argc == 2)
    {
        key = argv[1];
        keyLength = strlen(argv[1]);
        for (int n = 0; n < keyLength; n++)
        {
            int a = (int)key[n];
            if (a < 65 || a > 122 || (a > 90 && a < 97))
            {
                printf("Invalid key input on commmand line, exiting program\n");
                return 1;
            }
        }
    }
    // Exit program if wrong number of arguments has been passed
    else
    {
        printf("Invalid key input on commmand line, exiting program\n");
        return 1;
    }

    // Get string to be encrypted
    printf("plaintext: ");
    scanf("%s", in);
    //in = get_string("plaintext: ");

    length = strlen(in);

    // Run through string char by char, converting as appropriate
    for (int i = 0; i < length; i++)
    {
        // Will only convert if it is an actual letter (rather than punctuation etc)
        if (isupper(in[i]))
        {
            temp = in[i] + keyCheck(key[index]);
            if (temp > 90)
            {
                temp -= 26;
            }
            in[i] = temp;
            index++;
        }

        else if (islower(in[i]))
        {
            temp = in[i] + keyCheck(key[index]);
            if (temp > 122)
            {
                temp -= 26;
            }
            in[i] = temp;
            index++;
        }
        if (index >= keyLength)
        {
            index = 0;
        }
    }

    // Output the encrypted string
    cipher = in;
    printf("ciphertext:%s\n", cipher);

    return 0;
}

// Function that converts all lower case to upper
int keyCheck(char c)
{
    int shifter = 0;
    if (islower(c))
    {
        c -= 32;
    }

    shifter = c - 65;

    return shifter;
};
