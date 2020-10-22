from cs50 import get_int

def main():
    height = get_valid_int()
    mario_wall(height)

def mario_wall(height):
    for i in range(height):
        for _ in range(height-i-1):
            print(" ", end="")
        for _ in range(i+1):
            print("#", end="")
        print()

def get_valid_int():
    while True:
        n = get_int("Height: ")
        if n <= 8 and n >= 1:
            break
    return n

main()