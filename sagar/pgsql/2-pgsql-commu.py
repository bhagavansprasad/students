#!/usr/bin/python
# -*- coding: utf-8 -*-
import psycopg2
#import sys

def read_rows_from_db1(dbname):
	conn = None
	conn = psycopg2.connect(database=dbname, user="bhagavan", host="127.0.0.1", password="jnjnuh")
	cur = conn.cursor()

	cur.execute("SELECT * FROM contacts")
	rows = cur.fetchall()
	print(rows)
	print(len(rows))

	for temp in rows:
		print(temp)
	print("")

	conn.close()
	return

def read_rows_from_db2(db):
	conn = None
	conn = psycopg2.connect(database="auradb", user="bhagavan", host="127.0.0.1", password="jnjnuh")
	cur = conn.cursor()

	cur.execute("SELECT * FROM contacts WHERE name='Aura Networks'")
	rows = cur.fetchall()
	print(rows)
	print(len(rows))
	for row in rows:
		print(row)
	conn.close()
	return

def insert_rows_to_db(dbname):
	conn = None
	conn = psycopg2.connect(database=dbname, user="bhagavan", host="127.0.0.1", password="jnjnuh")
	cur = conn.cursor()


	add_row_query = "INSERT INTO contacts(name, phone, address, gender, dob) VALUES('Vachan', 9876588, 'Bangalore', 'M', '2017-05-11')"
	cur.execute(add_row_query)
	conn.commit()
	conn.close()

def insert_multiple_rows_to_db(db):
	conn = None
	conn = psycopg2.connect(database="auradb", user="bhagavan", host="127.0.0.1", password="jnjnuh")
	cur = conn.cursor()

	namedict = (
        {"type":"base ball", "color":"white",   "location":"south", "install_date":"2020-01-20"},
        {"type":"cricket",  "color":"white",   "location":"north", "install_date":"2020-01-20"},
        {"type":"tennis",   "color":"red",     "location":"west",  "install_date":"2020-08-10"}
        )

	cur.executemany("INSERT INTO playground(type, color, location, install_date) VALUES (%(type)s, %(color)s, %(location)s, %(install_date)s)", namedict)
	conn.commit()
	conn.close()
	return

def delete_rows_from_db(db):
	conn = None
	conn = psycopg2.connect(database="auradb", user="bhagavan", host="127.0.0.1", password="jnjnuh")
	cur = conn.cursor()

	namedict = (
        {"type":"base ball", "color":"white",   "location":"south", "install_date":"2020-01-20"},
        {"type":"cricket",  "color":"white",   "location":"north", "install_date":"2020-01-20"},
        {"type":"tennis",   "color":"red",     "location":"west",  "install_date":"2020-08-10"}
        )

	cur.executemany("INSERT INTO playground(type, color, location, install_date) VALUES (%(type)s, %(color)s, %(location)s, %(install_date)s)", namedict)
	conn.commit()
	conn.close()
	return

if (__name__ == "__main__"):
	read_rows_from_db1("auradb")
	read_rows_from_db2(db)

	insert_rows_to_db("auradb")
	read_rows_from_db1("auradb")

	exit(1)
	insert_multiple_rows_to_db(db)

