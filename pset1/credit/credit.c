#include <stdio.h>
#include <cs50.h>
#include <math.h>

int calculateDigitCount(long long number);
int calculateTotalCheckSum(long long number, int digitCount);
int calculateSelectedNumberCount(long long number, int whichNumber);

int main(void)
{
    long long cardNumber;

    do
    {
        cardNumber = get_long_long("Enter Credit Card Number: ");
    }
    while (cardNumber < 1);

    int digitCount = calculateDigitCount(cardNumber);
    int totalChekSum = calculateTotalCheckSum(cardNumber, digitCount);
    int firstNumber = calculateSelectedNumberCount(cardNumber, 1);
    int firstTwoNumber = calculateSelectedNumberCount(cardNumber, 2);


    if (totalChekSum % 10 == 0)
    {
        if (digitCount >= 13 && digitCount <= 16 && firstNumber == 4)
        {
            printf("VISA\n");
        }
        else if (digitCount == 16 && firstTwoNumber >= 51 && firstTwoNumber <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (digitCount == 15 && (firstTwoNumber == 34 || firstTwoNumber == 37))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}

int calculateDigitCount(long long number)
{
    int digitCount = 0;
    while (number != 0)
    {
        number /= 10;
        digitCount++;
    }

    return digitCount;
}

int calculateTotalCheckSum(long long number, int digitCount)
{
    int checkSum1 = 0;
    int checkSum2 = 0;

    for (int i = 1; i <= digitCount; i += 1)
    {
        long long digit = number % 10;

        if (i % 2 == 0)
        {
            int doubleDigit = digit * 2;
            if (calculateDigitCount(doubleDigit) > 1)
            {
                checkSum1 = checkSum1 + ((doubleDigit  % 10) + (doubleDigit / 10));
            }
            else
            {
                checkSum1 = checkSum1 + doubleDigit;
            }

        }
        else
        {
            checkSum2 = checkSum2 + digit;
        }

        number = number / 10;
    }

    return (checkSum1 + checkSum2);
}

int calculateSelectedNumberCount(long long number, int whichNumber)
{
    int digitCount = calculateDigitCount(number);

    for (int i = 1; i <= digitCount - whichNumber; i += 1)
    {
        long long digit = number % 10;
        number = number / 10;
    }
    return number;
}

