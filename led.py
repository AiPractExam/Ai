#Displaying Different LED pattern with RPI
#Pattern 1: For glowing all 5 LEDS
import RPI.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(5,GPIO.OUT)
GPIO.setup(6,GPIO.OUT)
GPIO.setup(13,GPIO.OUT)
GPIO.setup(19,GPIO.OUT)
GPIO.setup(26,GPIO.OUT)
Pins = [5,6,13,19,26]
while (1):
	for i in Pins:
		GPIO.output(i,GPIO.HIGH)
		time.sleep(0.5)
		GPIO.output(i,GPIO.LOW)
		time.sleep(0.5)

#Pattern 2: For glowing all Leds Simultaneously and offing them simultaneously

import RPI.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(5,GPIO.OUT)
GPIO.setup(6,GPIO.OUT)
GPIO.setup(13,GPIO.OUT)
GPIO.setup(19,GPIO.OUT)
GPIO.setup(26,GPIO.OUT)
Pins = [5,6,13,19,26]
while (1):
	GPIO.output(Pins,GPIO.HIGH)
	time.sleep(0.5)
	GPIO.output(Pins,GPIO.LOW)
	time.sleep(0.5)


#Pattern 3: For glowing LEDS from start to end and then from end to start

import RPI.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(5,GPIO.OUT)
GPIO.setup(6,GPIO.OUT)
GPIO.setup(13,GPIO.OUT)
GPIO.setup(19,GPIO.OUT)
GPIO.setup(26,GPIO.OUT)
Pins = [5,6,13,19,26]
while (1):
	for i in Pins:
		GPIO.output(i,GPIO.HIGH)
		time.sleep(0.5)
		GPIO.output(i,GPIO.LOW)
		time.sleep(0.5)
	for i in Pins[::-1]:
		GPIO.output(i,GPIO.HIGH)
		time.sleep(0.5)
		GPIO.output(i,GPIO.LOW)
		time.sleep(0.5)

#Pattern 4: For glowing odd nos LEDS and then even nos LED

import RPI.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(5,GPIO.OUT)
GPIO.setup(6,GPIO.OUT)
GPIO.setup(13,GPIO.OUT)
GPIO.setup(19,GPIO.OUT)
GPIO.setup(26,GPIO.OUT)
Pins = [5,6,13,19,26]
while (1):
	for i in Pins[::2]:
		GPIO.output(i,GPIO.HIGH)
		time.sleep(0.5)
		GPIO.output(i,GPIO.LOW)
		time.sleep(0.5)
	for i in Pins[1::2]:
		GPIO.output(i,GPIO.HIGH)
		time.sleep(0.5)
		GPIO.output(i,GPIO.LOW)
		time.sleep(0.5)