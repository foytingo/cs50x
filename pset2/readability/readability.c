#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int calculateLetterCount(string text);
int calculateWordCount(string text);
int calculateSentenceCount(string text);
float calculateHundredsPerWord(int count, int wordCount);
float calculateIndex(float lettersPerHundredWords, float sentencesPerHundredWords);

int main(void)
{
    string text = get_string("Text: ");

    int letterCount = calculateLetterCount(text);
    int wordCount = calculateWordCount(text) + 1;
    int sentenceCount = calculateSentenceCount(text);

    float lettersPerHundredWords = calculateHundredsPerWord(letterCount, wordCount);
    float sentencesPerHundredWords = calculateHundredsPerWord(sentenceCount, wordCount);

    float index = calculateIndex(lettersPerHundredWords, sentencesPerHundredWords);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }

}


int calculateLetterCount(string text)
{
    int letterCount = 0;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letterCount++;
        }
    }
    return letterCount;
}


int calculateWordCount(string text)
{
    int wordCount = 0;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if (isspace(text[i]))
        {
            wordCount++;
        }
    }
    return wordCount;
}

int calculateSentenceCount(string text)
{
    int sentenceCount = 0;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentenceCount++;
        }
    }
    return sentenceCount;
}

float calculateHundredsPerWord(int count, int wordCount)
{
    return ((float) count * 100) / (float) wordCount;
}

float calculateIndex(float lettersPerHundredWords, float sentencesPerHundredWords)
{
    return 0.0588 * lettersPerHundredWords - 0.296 * sentencesPerHundredWords - 15.8;
}
