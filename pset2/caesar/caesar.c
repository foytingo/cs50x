#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    int keyLength = strlen(argv[1]);
    for (int i = 0; i < keyLength; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);

    if (key > 0)
    {
        string plainText = get_string("plaintext: ");
        printf("ciphertext: ");
        int length = strlen(plainText);

        for (int i = 0; i < length; i++)
        {
            if (isalpha(plainText[i]))
            {
                if (isupper(plainText[i]))
                {
                    int newInt = ((plainText[i] - 'A') + key) % 26 + 'A';
                    printf("%c", newInt);
                }
                else if (islower(plainText[i]))
                {
                    int newInt = ((plainText[i] - 'a') + key) % 26 + 'a';
                    printf("%c", newInt);
                }
            }
            else
            {
                printf("%c", plainText[i]);
            }

        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
}

