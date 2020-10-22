#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    int coinCount = 0;
    float change;

    do
    {
        change = get_float("Change owed: ");
    }
    while (change <= 0);

    int cents = round(change * 100);

    do
    {
        coinCount++;

        if (cents >= 25)
        {
            cents = cents - 25;
        }
        else if (cents >= 10)
        {
            cents = cents - 10;
        }
        else if (cents >= 5)
        {
            cents = cents - 5;
        }
        else
        {
            cents = cents - 1;
        }
    }
    while (cents > 0);

    printf("%i\n", coinCount);

}