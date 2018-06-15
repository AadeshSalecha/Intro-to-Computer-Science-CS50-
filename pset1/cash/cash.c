#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float in;
    do
    {
        in = get_float("Change: ");
    }
    while (in < 0);

    // Convert to cents
    int coins = 0, change = round(in*100);

    coins += (change / 25);
    change %= 25;

    coins += (change / 10);
    change %= 10;

    coins += (change / 5);
    change %= 5;

    coins += change;

    printf("%i\n", coins);
}