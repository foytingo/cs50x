from sys import argv, exit
from cs50 import SQL

if len(argv) != 2:
    print("Error: Missing Command-Line Argument")
    exit(1)

db = SQL("sqlite:///students.db")

house = argv[1]

list = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last ASC, first ASC", house)

for student in list:
    if student['middle'] == None:
        print(f"{student['first']} {student['last']} born {student['birth']}")
    else:
        print(f"{student['first']} {student['middle']} {student['last']} born {student['birth']}")



