#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./crack hashofPassword\n");
        return -1;
    }

    string password = argv[1];

    string allCharacter = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\0";
    char tmp[6], tmpSalt[3];

    int all = strlen(allCharacter);

    tmpSalt[0] = password[0];
    tmpSalt[1] = password[1];
    tmpSalt[2] = '\0';

    //printf("%s\n", crypt("ROFL", "50"));
    for(int i = 0; i < all - 1; i++)
    {
        tmp[0] = allCharacter[i];
        for(int j = 0; j < all; j++)
        {
            tmp[1] = allCharacter[j];
            for(int k = 0; k < all; k++)
            {
                tmp[2] = allCharacter[k];
                for(int l = 0; l < all; l++)
                {
                    tmp[3] = allCharacter[l];
                    for(int m = 0; m < all; m++)
                    {
                        tmp[4] = allCharacter[m];
                        if(strcmp(crypt(tmp, tmpSalt), password) == 0)
                        {
                            printf("%s\n", tmp);
                            return 0;
                        }
                    }
                }
            }
        }
    }
}