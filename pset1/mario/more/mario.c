#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Read input
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height > 23 || height < 0);

    for (int i = 0; i < height; i++)
    {
        // Print spaces
        for (int j = 0; j < height - 1 - i; j++)
        {
            printf(" ");
        }

        // Print hashes
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        printf("  ");

        // Print hashes
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}