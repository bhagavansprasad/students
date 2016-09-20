# -*- coding: utf-8 -*-
import paho.mqtt.client as mqtt

mqttc = mqtt.Client("python_pub")
print "1\n"
mqttc.connect("test.mosquitto.org", 1883)
print "2\n"
mqttc.publish("hello/world”, “Hello, World!")
print "3\n"
mqttc.loop(2) 
print "4\n"
