import socket
import sys
import time
import RPi.GPIO as GPIO

LED = 18
set_bit = 0
time_out = int(sys.argv[1])

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to the port of INADDR_ANY
server_address = ('', 15000)
print >>sys.stderr, 'starting up on %s port %s' % server_address
sock.bind(server_address)

# Listen for incoming connections
sock.listen(2)

while True:
    # Wait for a connection
    print >>sys.stderr, 'waiting for a connection'
    connection, client_address = sock.accept()
    print >>sys.stderr, 'connection from', client_address

    while True:
    # Receive the data  
    	connection.settimeout(time_out)
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(LED,GPIO.OUT)
        print "SETUP READY"

        try:
            set_bit = int(connection.recv(512))
	    GPIO.output(LED, set_bit)
            print "received :", set_bit
        except socket.timeout:
            set_bit = 0
            print "sending :", set_bit
	    GPIO.output(LED, set_bit)
            connection.send(str(set_bit))
            time.sleep(int(time_out * 10))
	    GPIO.cleanup()
            sock.close()
