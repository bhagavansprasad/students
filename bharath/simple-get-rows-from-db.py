#!/usr/bin/python
import csv
import psycopg2
import sys

conn = psycopg2.connect(database="postgres", user="postgres", host="127.0.0.1", password="jnjnuh")

cur = conn.cursor()
cur.execute("create table student3(name varchar(77),id serial primary key,dob date,doj date)")
cur.execute("insert into student3(name,id,dob,doj)values('bharath',123,'1996/05/06','1996/02/11')")
cur.execute("SELECT * FROM student3")

rows = cur.fetchall()

print(rows)

