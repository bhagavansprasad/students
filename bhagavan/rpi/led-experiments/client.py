import RPi.GPIO as GPIO
import time
import socket
import sys
import time

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect the socket to the port where the server is listening
server_address = (sys.argv[1], 15000)
print >>sys.stderr, 'connecting to %s port %s' % server_address
sock.connect(server_address)

TRIG = 16 
ECHO = 19

Led_set = 0
print "Distance Measurement In Progress"

GPIO.setmode(GPIO.BCM)
GPIO.setup(TRIG,GPIO.OUT)
GPIO.setup(ECHO,GPIO.IN)

GPIO.output(TRIG, False)
print "Waiting For Sensor To Settle"
time.sleep(2)

try:
    # Send data
    while True:
	GPIO.output(TRIG, True)
	time.sleep(0.00001)
	GPIO.output(TRIG, False)

	while GPIO.input(ECHO)==0:
  		pulse_start = time.time()

	while GPIO.input(ECHO)==1:
  		pulse_end = time.time()

	pulse_duration = pulse_end - pulse_start
	distance = pulse_duration * 17150
	distance = round(distance, 2)
	print "Distance:",distance,"cm"

	if (distance >= 2 and distance <= 9):
		Led_set = int(Led_set ^ 1)
        	print "sending :", Led_set
        	sock.sendall(str(Led_set))

        sock.settimeout(int(sys.argv[2]))

        try:
            Led_status = int(sock.recv(512))
            print "received :", Led_set
            break
        except socket.timeout:
            time.sleep(int(sys.argv[2]))

finally:
    sock.close()
