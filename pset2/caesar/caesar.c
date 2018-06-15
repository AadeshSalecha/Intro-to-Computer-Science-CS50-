#include <string.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    int k = atoi(argv[1]);

    string text = get_string("plaintext: ");
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(isupper(text[i]))
        {
            text[i] = (((text[i] - 'A' + k) % 26) + 'A');
        }

        if(islower(text[i]))
        {
            text[i] = (((text[i] - 'a' + k) % 26) + 'a');
        }
    }

    printf("ciphertext: %s\n", text);
}