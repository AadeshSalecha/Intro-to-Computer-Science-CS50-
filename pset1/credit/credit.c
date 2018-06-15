#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int digits(int num);

int main(void)
{
    long long num;
    do
    {
        num = get_long("Number: ");
    }
    while (num < 0);

    int length = (int) (log(num) / log(10)) + 1, checksum = 0;
    int card[length];

    for(int i = 0; i < length; i++)
    {
        card[i] = (num % 10);
        num /= 10;
    }

    for (int i = 0; i < length; i++)
    {
        if(i % 2)
        {
            checksum += digits(2 * card[i]);
        }
        else
        {
            checksum += card[i];
        }
    }

    if(checksum % 10 != 0 || length < 13 || length > 16)
    {
        printf("INVALID\n");
    }
    else if(card[length - 1] == 4)
    {
        printf("VISA\n");
    }
    else if(card[length - 1] == 5 && (card[length - 2] == 1 || card[length - 2] == 2 || card[length - 2] == 3 || card[length - 2] == 4 || card[length - 2] == 5))
    {
        printf("MASTERCARD\n");
    }
    else if(card[length - 1] == 3 && (card[length - 2] == 4 || card[length - 2] == 7))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int digits(int num)
{
    if(num < 10)
    {
        return num;
    }
    return digits(num / 10) + num % 10;
}