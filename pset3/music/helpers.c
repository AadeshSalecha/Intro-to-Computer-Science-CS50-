// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int X = fraction[0] - '0';
    int Y = fraction[2] - '0';
    return (X * 8) / Y;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char letter;
    int num, semitone = 0;
    if (strlen(note) == 2)
    {
        letter = note[0];
        num = note[1] - '0';
    }
    else
    {
        letter = note[0];
        num = note[2] - '0';
    }

    // If note is After A4
    if (num > 4)
    {
        // for A#4 and B4
        semitone += 2;

        //
        semitone += (num - 5) * (12);

        // now walk
        switch (letter)
        {
            case 'C':
                semitone += 1;
                break;
            case 'D':
                semitone += 3;
                break;
            case 'E':
                semitone += 5;
                break;
            case 'F':
                semitone += 6;
                break;
            case 'G':
                semitone += 8;
                break;
            case 'A':
                semitone += 10;
                break;
            case 'B':
                semitone += 12;
                break;
        }

        if (strlen(note) == 3)
        {
            if (note[1] == '#')
            {
                semitone++;
            }
            else
            {
                semitone--;
            }
        }
    }
    // If note is before A4
    else if (num < 4)
    {
        semitone += 9;

        semitone += (3 - num) * 12;

        switch (letter)
        {
            case 'B':
                semitone += 1;
                break;
            case 'A':
                semitone += 3;
                break;
            case 'G':
                semitone += 5;
                break;
            case 'F':
                semitone += 7;
                break;
            case 'E':
                semitone += 8;
                break;
            case 'D':
                semitone += 10;
                break;
            case 'C':
                semitone += 12;
                break;
        }

        if (strlen(note) == 3)
        {
            if (note[1] == '#')
            {
                semitone--;
            }
            else
            {
                semitone++;
            }
        }
        semitone = -semitone;
    }
    // If its in the 4th Octave
    else
    {
        switch (letter)
        {
            case 'B':
                semitone += 2;
                break;
            case 'G':
                semitone += 2;
                break;
            case 'F':
                semitone += 4;
                break;
            case 'E':
                semitone += 5;
                break;
            case 'D':
                semitone += 7;
                break;
            case 'C':
                semitone += 9;
                break;
        }

        if (strlen(note) == 3)
        {
            if (letter == 'B')
            {
                if (note[1] == '#')
                {
                    semitone++;
                }
                else
                {
                    semitone--;
                }
            }
            else if (note[1] == '#')
            {
                semitone--;
            }
            else
            {
                semitone++;
            }
        }

        if (letter != 'B')
        {
            semitone = -semitone;
        }
    }
    //printf("Frequency: Letter: %c Number: %i Semi: %i Ans: %f\n", letter, num, semitone, pow(2,(semitone / 12.00)) * 440);
    return round(pow(2, (semitone / 12.00)) * 440);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    return (strcmp(s, "") == 0);
}
