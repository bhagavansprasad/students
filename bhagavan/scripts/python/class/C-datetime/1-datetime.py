#!/usr/bin/python
import time;  # This is required to include time module.
import calendar
import datetime

ticks = time.time()
print "Number of ticks since 12:00am, January 1, 1970:", ticks

print ""

localtime = time.localtime(time.time())
print "Local current time :", localtime

cal = calendar.month(2017, 1)
print "Here is the calendar:"
print cal

print "Time in seconds since the epoch: %s" %time.time()
print "Current date and time          :", datetime.datetime.now()
print "Or like this                   :", datetime.datetime.now().strftime("%y-%m-%d-%H-%M")
print "Current year                   :", datetime.date.today().strftime("%Y")
print "Month of year                  :", datetime.date.today().strftime("%B")
print "Week number of the year        :", datetime.date.today().strftime("%W")
print "Weekday of the week            :", datetime.date.today().strftime("%w")
print "Day of year                    :", datetime.date.today().strftime("%j")
print "Day of the month               :", datetime.date.today().strftime("%d")
print "Day of week                    :", datetime.date.today().strftime("%A")


now = datetime.datetime(2003, 8, 4, 12, 30, 45)
print now
print repr(now)
print type(now)
print now.year, now.month, now.day
print now.hour, now.minute, now.second
print now.microsecond


t = datetime.time(1, 2, 3)
print t
print 'hour  :', t.hour
print 'minute:', t.minute
print 'second:', t.second
print 'microsecond:', t.microsecond
print 'tzinfo:', t.tzinfo


today = datetime.date.today()
print 'Today    :', today

one_day = datetime.timedelta(days=1)
print 'One day  :', one_day

yesterday = today - one_day
print 'Yesterday:', yesterday

tomorrow = today + one_day
print 'Tomorrow :', tomorrow

print 'tomorrow - yesterday:', tomorrow - yesterday
print 'yesterday - tomorrow:', yesterday - tomorrow

print 'Times:'
t1 = datetime.time(12, 55, 0)
print '\tt1:', t1
t2 = datetime.time(13, 5, 0)
print '\tt2:', t2
print '\tt1 < t2:', t1 < t2

print 'Dates:'
d1 = datetime.date.today()
print '\td1:', d1
d2 = datetime.date.today() + datetime.timedelta(days=1)
print '\td2:', d2
print '\td1 > d2:', d1 > d2
