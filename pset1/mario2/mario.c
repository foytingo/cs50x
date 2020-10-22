#include <stdio.h>
#include <cs50.h>

void hash(int lineNumber);

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

        hash(i);

        printf("  ");

        hash(i);

        printf("\n");
    }
}

void hash(int lineNumber)
{
    for (int j = 1; j <= lineNumber; j++)
    {
        printf("#");
    }
}