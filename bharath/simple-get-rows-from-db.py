#!/usr/bin/python
import csv
import psycopg2
import sys

conn = psycopg2.connect(database="postgres", user="postgres", host="127.0.0.1", password="jnjnuh")

cur = conn.cursor()

cur.execute("SELECT * FROM student")

rows = cur.fetchall()

print(rows)

