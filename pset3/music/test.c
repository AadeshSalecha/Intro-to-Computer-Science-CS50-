#include <cs50.h>
#include <stdio.h>
#include <string.h>

#include "helpers.h"

int main(void)
{
        string note = "A4";
        int f = frequency(note);

        // Print note to screen
        printf("%3s: %i\n", note, f);
}