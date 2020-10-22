from cs50 import SQL
from sys import argv, exit
import csv

if len(argv) != 2:
    print("Error: Missing Command-Line Argument")
    exit(1)

db = SQL("sqlite:///students.db")

#db.execute("CREATE TABLE students (first TEXT, middle TEXT, last TEXT, house TEXT, birth NUMERIC")
db.execute("DELETE FROM students")

with open(argv[1], "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        fullName = row["name"].split()

        if len(fullName) > 2:
            firstName = fullName[0]
            middleName = fullName[1]
            lastName = fullName[2]
        else:
            firstName = fullName[0]
            middleName = None
            lastName = fullName[1]

        birthYear = int(row["birth"])

        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", firstName, middleName, lastName, row["house"], birthYear)
