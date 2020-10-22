from cs50 import get_string

text = get_string("Text: ")

letterCount = 0.0
wordCount = 1.0
sentenceCount = 0.0

for char in text:
    if char.isspace():
        wordCount += 1
    elif char == '.' or char == '!' or char == '?':
        sentenceCount += 1
    elif char.isalpha():
        letterCount += 1

lettersPerHundredWords = (letterCount * 100.0) / float(wordCount)
sentencesPerHundredWords =  (sentenceCount * 100.0) / float(wordCount)

index = 0.0588 * lettersPerHundredWords - 0.296 * sentencesPerHundredWords - 15.8

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {round(index)}")

