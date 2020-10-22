from cs50 import get_int


def main():
    cardNumber = get_int("Enter Credit Card Number: ")
    lengthOfCardNumber = len(str(cardNumber))
    
    totalCheckSum = calculateTotalCheckSum(cardNumber, lengthOfCardNumber)
    firstNumber = calculateSelectedNumberCount(cardNumber, 1)
    firstTwoNumber = calculateSelectedNumberCount(cardNumber, 2)
    
    if totalCheckSum % 10 == 0:
        if lengthOfCardNumber >= 13 and lengthOfCardNumber <= 16 and firstNumber == 4:
            print("VISA")
        elif lengthOfCardNumber == 16 and firstTwoNumber >= 51 and firstTwoNumber <= 55:
            print("MASTERCARD")
        elif lengthOfCardNumber == 15 and (firstTwoNumber == 34 or firstTwoNumber == 37):
            print("AMEX")
        else:
            print("INVALID")
    else:
        print("INVALID")


def calculateTotalCheckSum(cardNumber, digitCount):
    
    cardNumberString = str(cardNumber)
    
    checkSum1 = 0
    checkSum2 = 0
    
    for i, number in enumerate(cardNumberString[::-1]):
        if (i+1) % 2 == 0:
            doubleDigit = int(number) * 2
            if len(str(doubleDigit)) > 1:
                checkSum1 += int((doubleDigit % 10) + (doubleDigit / 10))
            else:
                checkSum1 += doubleDigit
        else:
            checkSum2 += int(number)
    
    return checkSum1 + checkSum2         


def calculateSelectedNumberCount(cardNumber, whichNumber):
    number = ""
    for i in range(whichNumber):
        number +=  str(cardNumber)[i]
    
    return int(number)    
    
main()