#include <string.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

bool allAlpha(string s);

int main(int argc, char** argv)
{
    if (argc != 2 || !allAlpha(argv[1]))
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    string k = argv[1];
    int keyLength = strlen(k);
    for (int i = 0, n = strlen(k); i < n; i++)
    {
        if(isupper(k[i]))
        {
            k[i] = k[i] - 'A';
        }

        if(islower(k[i]))
        {
            k[i] = k[i] - 'a';
        }
    }

    string text = get_string("plaintext: ");
    for (int i = 0, n = strlen(text), count = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] = (((text[i] - 'A' + k[count]) % 26) + 'A');
            }

            if (islower(text[i]))
            {
                text[i] = (((text[i] - 'a' + k[count]) % 26) + 'a');
            }
            count = (count + 1) % keyLength;
        }
    }

    printf("ciphertext: %s\n", text);
}

bool allAlpha(string s)
{
    for(int i = 0, n = strlen(s); i < n; i++)
    {
        if(!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}