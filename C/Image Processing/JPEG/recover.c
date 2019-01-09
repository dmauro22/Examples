#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    // Make sure we have the correct number of arguments
    if (argc != 2)
    {
        fprintf(stderr, "Incorrect number of arguments\n");
        return 1;
    }

    char *infile = argv[1];         // Input with the 'wiped' jpegs
    char *outfile = NULL;           // Will use this to write output later
    unsigned char buffer[512];      // JPGs are stored in 512 byte blocks
    int count = 0;                  // Use this to check size of input, when != 512 bytes, we are at the end of file
    int fileName = 0;               // Used for naming the individual JPGs
    bool flag = 0;                  // Used to indicate that we have found the first JPG


    FILE *inptr = fopen(infile, "r");

    FILE *outptr = NULL;

    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // Pull in first set of 512 bytes
    count = fread(buffer, 1, 512, inptr);

    // As long as we are not at end of file...
    while (count == 512)
    {
        // This 'if' statement is looking for the standard JPG header signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            flag = 1;

            // If we have found a new JPG, and there is already one open, then close the one that is open
            if (fileName > 0)
            {
                fclose(outptr);
            }


            char *name = (char *) malloc(8);
            sprintf(name, "%03d.jpg", fileName);
            outptr = fopen(name, "w");
            free(name);
            fileName++;
        }

        // If we dont have the start of a new JPG, but we have already found one JPG so far
        // then write the buffer to the existing JPEG and then pull in a new 512 byte block
        if (flag)
        {
            fwrite(buffer, 1, 512, outptr);
            count = fread(buffer, 1, 512, inptr);
        }

        // Else discard the current buffer and pull in a new 512 byte block
        else
        {
            count = fread(buffer, 1, 512, inptr);
        }

    }

    fclose(outptr);

    // success
    return 0;

}
