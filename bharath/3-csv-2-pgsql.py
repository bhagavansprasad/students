#!/usr/bin/python
import csv
import psycopg2
import sys

#open the source csv file
fd = open('/home/bhagavan/Downloads/3-csv-2-pgsql.py', 'rt')

#reading data from csv
reader = csv.reader(fd)

#connecting to database
conn = None
conn = psycopg2.connect( database="auradb", user="postgres", host="127.0.0.1", password="jnjnuh")
cur = conn.cursor()
cur.execute("create table student(name varchar(20) not null,dob date,doj date,gender char)")
a=cur.execute("select * from student")
print(a)
exit(1)

#insert each row of csv file and add to database
i = 0
for row in reader:
    if (i == 0):
        i = 1
        continue

    print("===", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8])
    cur.execute("INSERT INTO students_list(name, fullname, uid, gid, phone, hphone, address, email, status) VALUES (%s, %s, %s, %s, %s, %s, %s, %s, %s)", 
        (row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], "1"))

conn.commit()

#closing csv
fd.close()

#Read all rows from database
cur.execute("SELECT * FROM students_list")
rows = cur.fetchall()
print(rows)

#print each row
for row in rows:
    print(row)

