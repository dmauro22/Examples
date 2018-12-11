#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    // remember filenames
    int shift = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }


    // determine padding for input lines
    int inPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    printf("inPadding: %i\n", inPadding);

    int inWidth = bi.biWidth;

    printf("inWidth: %i\n", inWidth);

    bi.biWidth *= shift;
    bi.biHeight *= shift;
    //bf.bfSize = (bi.biWidth * 3 + padding ) * abs(bi.biHeight) + bf.bfOffBits;

    // determine padding for output lines
    int outPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    printf("outPadding: %i\n", outPadding);

    printf("outWidth: %i\n", bi.biWidth);

    bi.biSizeImage = (bi.biWidth * (bi.biBitCount / 8) + outPadding) * abs(bi.biHeight);


    bf.bfSize = bi.biSizeImage + bf.bfOffBits;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight / shift); i < biHeight; i++)
    {
        // First added loop is below, enables duplication
        // of the rows of the infile 'shift' number of times
        for (int k = 0; k < shift; k++)
        {
            // Pull the infile pointer back one row if we need to do another pass, this happens
            // on every pass of the above loop except the first because the pointer is already in the
            // correct place on that first pass
            if (k > 0)
            {
                fseek(inptr, -(inWidth * sizeof(RGBTRIPLE) + inPadding), SEEK_CUR);
            }

            // iterate over pixels in scanline
            for (int j = 0; j < inWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile
                // Second added loop is below, enables duplication
                // of the pixels (and columns) 'shift' number of times
                for (int l = 0; l < shift; l++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // skip over padding from infile, if any
            fseek(inptr, inPadding, SEEK_CUR);

            // then add padding to outfile, if any
            for (int m = 0; m < outPadding; m++)
            {
                fputc(0x00, outptr);
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
