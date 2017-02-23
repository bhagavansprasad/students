#!/usr/bin/python
# -*- coding: utf-8 -*-

import psycopg2
import sys

conn = None
conn = psycopg2.connect( database="postgres", user="postgres", host="127.0.0.1", password="jnjnuh")
cur = conn.cursor()
cur.execute("SELECT * FROM playground")
rows = cur.fetchall()

print rows
for row in rows:
    print row
