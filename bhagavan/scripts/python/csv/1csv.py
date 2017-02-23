import csv
import sys

fd = open('users.csv', 'r')

reader = csv.reader(fd)

for row in reader:
    print row

fd.close()
