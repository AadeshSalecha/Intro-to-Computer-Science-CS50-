#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover raw_image\n");
        return 1;
    }

    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s\n", argv[1]);
        return 2;
    }

    int count = 0, num = 0;
    uint8_t tmpArr[512];
    char fileName[8];

    FILE *newFile = NULL;
    while (fread(tmpArr, 512, 1, inptr))
    {
        if (tmpArr[0] == 0xff && tmpArr[1] == 0xd8 && tmpArr[2] == 0xff && (tmpArr[3] == 0xe0 || tmpArr[3] == 0xe1))
        {
            if (newFile != NULL)
            {
                fclose(newFile);
            }

            sprintf(fileName, "%03i.jpg", count++);
            newFile = fopen(fileName, "w");

            if (newFile == NULL)
            {
                fprintf(stderr, "Not able to open new files.\n");
            }
        }

        if (newFile != NULL)
        {
            fwrite(tmpArr, 512, 1, newFile);
        }
        num += 1;
    }

    if (newFile != NULL)
    {
        fclose(newFile);
    }
    fclose(inptr);
    printf("%i %i\n", count++, num);
}