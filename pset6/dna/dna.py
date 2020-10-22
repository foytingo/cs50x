from sys import argv, exit
import csv

if len(argv) != 3:
    print("Error: Missing command-line argument")
    exit(1)


STRs_from_database = []
persons_from_database = {}

with open(argv[1], mode='r') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    for index, row in enumerate(csv_reader):
        if index == 0:
            STRs_from_database = row[1:]
        else:
            persons_from_database[row[0]] = [int(x) for x in row[1:]]


dna = open(argv[2], mode='r').read()

final_unknown_strs = []

for str in STRs_from_database:

    i = 0
    current_max = 0
    max_strs = -1
    while i < len(dna):
        current = dna[i:i + len(str)]
        if current == str:
            i += len(str)
            current_max += 1
            max_strs = max(max_strs, current_max)

        else:
            i += 1
            current_max = 0

    final_unknown_strs.append(max_strs)


for name, str in persons_from_database.items():
    if str == final_unknown_strs:
        print(name)
        exit(0)
print("No match")

