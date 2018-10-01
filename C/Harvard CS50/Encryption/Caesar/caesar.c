#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[argc + 1])
{
    int key = 15;
    int length = 0;
    int temp = 0;
    char *in = (char *) malloc(128);
    char *cipher = (char *) malloc(128);


    // Check to make sure a key has been passed to the function
    if (argc == 2)
    {
        key = (atoi(argv[1]) % 26);
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

    length = strlen(in);

    // Run through string char by char, converting as appropriate
    for (int i = 0; i < length; i++)
    {
        // Will only convert if it is an actual letter (skipping over punctuation, etc)
        if (isupper(in[i]))
        {
            temp = in[i] + key;
            if (temp > 90)
            {
                temp -= 26;
            }
            in[i] = temp;
        }

        else if (islower(in[i]))
        {
            temp = in[i] + key;
            if (temp > 122)
            {
                temp -= 26;
            }
            in[i] = temp;
        }
    }

    // Output the encrypted string
    cipher = in;
    printf("ciphertext:%s\n", cipher);

    return 0;
}
