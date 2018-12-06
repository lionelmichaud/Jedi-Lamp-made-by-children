EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L +12V #PWR?
U 1 1 58A08FF4
P 1300 1500
F 0 "#PWR?" H 1300 1350 50  0001 C CNN
F 1 "+12V" H 1300 1640 50  0000 C CNN
F 2 "" H 1300 1500 50  0000 C CNN
F 3 "" H 1300 1500 50  0000 C CNN
	1    1300 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 1400 1300 1150
Wire Wire Line
	1300 1150 2300 1150
Wire Wire Line
	3050 1200 3050 1350
$Comp
L LED_ALT D?
U 1 1 58A09202
P 3050 1500
F 0 "D?" H 3050 1600 50  0000 C CNN
F 1 "LED_ALT" H 3050 1400 50  0000 C CNN
F 2 "" H 3050 1500 50  0000 C CNN
F 3 "" H 3050 1500 50  0000 C CNN
	1    3050 1500
	0    -1   -1   0   
$EndComp
$Comp
L GNDREF #PWR?
U 1 1 58A0927E
P 1300 1950
F 0 "#PWR?" H 1300 1700 50  0001 C CNN
F 1 "GNDREF" H 1300 1800 50  0000 C CNN
F 2 "" H 1300 1950 50  0000 C CNN
F 3 "" H 1300 1950 50  0000 C CNN
	1    1300 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 1500 1300 1950
$Comp
L R R?
U 1 1 58A09650
P 2550 1800
F 0 "R?" V 2630 1800 50  0000 C CNN
F 1 "R" V 2550 1800 50  0000 C CNN
F 2 "" V 2480 1800 50  0000 C CNN
F 3 "" H 2550 1800 50  0000 C CNN
	1    2550 1800
	1    0    0    -1  
$EndComp
$EndSCHEMATC
