#include <stdio.h>

// This program simulates a mario brothers pyramid

int main()
{
    int h = 0;
    do
    {
        printf("Enter height: ");
        scanf("%i", &h);
    }
    while (h < 0 || h > 23);

    int j = 1;

    // Copy this whole set and put an 'i' instead of 'h' in (h - j) part of second for loop
    // Outer loop covers the rows
    for (int i = 0; i < h; i++)
    {
        // Two inner loops cover the blank spaces and '#'
        for (int k = 0; k < (h - j); k++)
        {
            printf(" ");
        }
        for (int l = 0; l < j; l++)
        {
            printf("#");
        }
        printf("  ");

        for (int m = 0; m < j; m++)
        {
            printf("#");
        }

        printf("\n");
        j++;
    }
}
