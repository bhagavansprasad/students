#!/usr/bin/python
import csv
import sys


fd = 0
try:
    fd = open('data.csv', 'rt')
except IOError as e:
    print "I/O error({0}): {1}".format(e.errno, e.strerror)
    exit(1)


a = []
reader = csv.reader(fd)

print "reader type :", type(reader)
print next(reader)
print next(reader)
print reader.next()
print reader.previous()

for row in reader:
    print "row type :", type(row), "row[0] type :", type(row[0]), row[0], "row[3] type :", type(row[3]), row[3]
    a.append(row)

print a

print "a type ", type(a)
for row in a:
    print row

fd.seek(0)

for row in a:
    print row

print a[0]
print a[1]

print a[0][0]
print type(a[0][0])
print int(a[0][0])
print type(int(a[0][0]))

if  (int(a[0][0]) > int(a[1][0])):
    t = a[0]
    a[0] = a[1]
    a[1] = t

print a[0]
print a[1]

fd.close()


