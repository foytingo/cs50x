#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);

    for (int i = 1; i <= height; i++)
    {
        for (int spaceCount = 1; spaceCount <= height - i; spaceCount++) 
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) 
        {
            printf("#");
        }
        printf("\n");
    }

}

