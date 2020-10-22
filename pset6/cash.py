from cs50 import get_float

def main():
    change = get_valid_float()
    print(calculate_coint_count(change))

def calculate_coint_count(change):
    coinCount = 0
    cents = change * 100
    while True:
        if cents >= 25:
            cents -= 25
        elif cents >= 10:
            cents -= 10
        elif cents >= 5:
            cents -= 5
        elif cents >= 1:
            cents -= 1
        else:
            break
        coinCount += 1
    return coinCount

def get_valid_float():
    while True:
        n = get_float("Change owned: ")
        if n > 0:
            break
    return n

main()