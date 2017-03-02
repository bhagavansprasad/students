#!/usr/bin/python

import csv
import psycopg2
import sys

conn = None
conn = psycopg2.connect( database="postgres", user="postgres", host="127.0.0.1", password="jnjnuh")
cur = conn.cursor()

'''
cur.execute("INSERT INTO playground(type, color) VALUES('ztennis','white')")
conn.commit()
'''


fd = open('users.csv', 'rt')
reader = csv.reader(fd)
i = 0
for row in reader:
    if (i == 0):
        i = 1
        continue

    print row[0],
    print row[6]

    '''
    query = "INSERT INTO playground(type, color) VALUES (%s,%s)"
    data = (row[0], row[6])
    cur.execute(query, data)
    '''

    '''
    query = "INSERT INTO playground(type, color) VALUES (%s,%s)"
    cur.execute(query, (row[0], row[6]))
    '''

    cur.execute("INSERT INTO playground(type, color) VALUES (%s,%s)", (row[0], row[6]))
    '''
    '''

conn.commit()
fd.close()

cur.execute("SELECT * FROM playground")
rows = cur.fetchall()
print rows
for row in rows:
    print row


