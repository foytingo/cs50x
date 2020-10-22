from cs50 import get_int

def main():
    height = get_valid_int()
    mario_wall(height)

def hash(lineNumber):
    for _ in range(lineNumber + 1):
        print("#", end="")

def mario_wall(height):
    for i in range(height):
        for _ in range(height-i-1):
            print(" ", end="")

        hash(i)

        print(" " * 2, end="")

        hash(i)

        print()

def get_valid_int():
    while True:
        n = get_int("Height: ")
        if n <= 8 and n >= 1:
            break
    return n

main()