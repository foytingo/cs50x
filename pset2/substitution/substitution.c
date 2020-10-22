#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int keyLength = strlen(argv[1]);

    if (keyLength < 26)
    {
        printf("Key must contain 25 characters\n");
        return 1;
    }

    int duplicateKeyCount = 0;

    for (int i = 0; i < keyLength; i++)
    {
        for (int j = i + 1; j < keyLength; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                duplicateKeyCount++;
            }
        }
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        else if (duplicateKeyCount >= 1)
        {
            printf("Key is invalid because duplicate char in key.\n");
            return 1;
        }
        else
        {
            argv[1][i] = tolower(argv[1][i]);
        }
    }

    string plainText = get_string("plaintext: ");
    int plainTextLength = strlen(plainText);

    printf("ciphertext: ");

    for (int i = 0; i < plainTextLength; i++)
    {
        if (isalpha(plainText[i]))
        {
            if (isupper(plainText[i]))
            {
                printf("%c", toupper(argv[1][plainText[i] - 'A']));
            }
            if (islower(plainText[i]))
            {
                printf("%c", tolower(argv[1][plainText[i] - 'a']));
            }
        }
        else
        {
            printf("%c", plainText[i]);
        }
    }
    printf("\n");
    
}