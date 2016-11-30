import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)

LED = 18
set_bit = 0
count = 0

GPIO.setup(LED,GPIO.OUT)

while True:
	GPIO.output(LED, set_bit)
	set_bit = int(set_bit ^ 1)
	time.sleep(1)
	count = count + 1
	if (int(count > 15)):
		break

GPIO.cleanup()
