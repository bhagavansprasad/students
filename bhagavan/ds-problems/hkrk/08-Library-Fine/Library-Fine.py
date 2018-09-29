import datetime
from dateutil import relativedelta

def libraryFine(d1, m1, y1, d2, m2, y2):
    # Complete this function
	#date = datetime(year=int(s[0:4]), month=int(s[4:6]), day=int(s[6:8]))
	fine = 0
	d1 = datetime.date(year=y1, month=m1, day=d1)
	d2 = datetime.date(year=y2, month=m2, day=d2)
	print (d1), 
	print (d2), 
	print(d1-d2),

	r = relativedelta.relativedelta(d1, d2)
	print ("days :%d, months :%d, years :%d" % (r.days, r.months, r.years))

	if (r.days > 0):
		fine = r.days * 15
        
	if (r.months > 0):
		fine = r.months * 500

	if (r.years > 0):
		fine = r.years * 10000
       
	return fine

def main():
	print(libraryFine(9, 7, 2015, 6, 6, 2015))
	print(libraryFine(9, 6, 2017, 6, 6, 2015))
	print(libraryFine(2, 5, 2015, 30, 5, 2015))
	print(libraryFine(2, 7, 2015, 1, 2, 2014))
	print(libraryFine(5, 5, 2014, 23, 2, 2014))

if (__name__ == "__main__"):
	main()

