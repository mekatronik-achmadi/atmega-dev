EESchema Schematic File Version 4
LIBS:circuit-cache
EELAYER 26 0
EELAYER END
$Descr User 7874 5906
encoding utf-8
Sheet 1 1
Title "USBAspLoader"
Date "2019-03-29"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_ATmega:ATmega8A-AU U1
U 1 1 5C9DC3DE
P 2650 2450
F 0 "U1" H 2650 4028 50  0000 C CNN
F 1 "ATmega8A-AU" H 2650 3937 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 2650 2450 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/Microchip%208bit%20mcu%20AVR%20ATmega8A%20data%20sheet%2040001974A.pdf" H 2650 2450 50  0001 C CNN
	1    2650 2450
	1    0    0    -1  
$EndComp
$Comp
L Connector:USB_B_Mini J1
U 1 1 5C9DC7F4
P 4350 2700
F 0 "J1" H 4121 2691 50  0000 R CNN
F 1 "USB_B_Mini" H 4121 2600 50  0000 R CNN
F 2 "Connector_USB:USB_Mini-B_Lumberg_2486_01_Horizontal" H 4500 2650 50  0001 C CNN
F 3 "~" H 4500 2650 50  0001 C CNN
	1    4350 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5C9DCC0D
P 4950 2450
F 0 "R1" H 5020 2496 50  0000 L CNN
F 1 "68" H 5020 2405 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 4880 2450 50  0001 C CNN
F 3 "~" H 4950 2450 50  0001 C CNN
	1    4950 2450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5C9DCC63
P 5050 2450
F 0 "R2" H 5120 2496 50  0000 L CNN
F 1 "68" H 5120 2405 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 4980 2450 50  0001 C CNN
F 3 "~" H 5050 2450 50  0001 C CNN
	1    5050 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 2800 4950 2800
Wire Wire Line
	5050 2800 5050 2600
Wire Wire Line
	4650 2700 4850 2700
Wire Wire Line
	4950 2700 4950 2600
$Comp
L Device:D_Zener D1
U 1 1 5C9DCD50
P 4850 3050
F 0 "D1" V 4804 3129 50  0000 L CNN
F 1 "D_Zener" V 4895 3129 50  0000 L CNN
F 2 "Diode_SMD:D_MELF_Handsoldering" H 4850 3050 50  0001 C CNN
F 3 "~" H 4850 3050 50  0001 C CNN
	1    4850 3050
	0    1    1    0   
$EndComp
$Comp
L Device:D_Zener D2
U 1 1 5C9DCDC6
P 4950 3050
F 0 "D2" V 4904 3129 50  0000 L CNN
F 1 "D_Zener" V 4995 3129 50  0000 L CNN
F 2 "Diode_SMD:D_MELF_Handsoldering" H 4950 3050 50  0001 C CNN
F 3 "~" H 4950 3050 50  0001 C CNN
	1    4950 3050
	0    1    1    0   
$EndComp
Wire Wire Line
	4950 2900 4950 2800
Connection ~ 4950 2800
Wire Wire Line
	4950 2800 5050 2800
Wire Wire Line
	4850 2900 4850 2700
Connection ~ 4850 2700
Wire Wire Line
	4850 2700 4950 2700
Wire Wire Line
	4950 3200 4950 3250
Wire Wire Line
	4950 3250 4850 3250
Wire Wire Line
	4250 3250 4250 3100
Wire Wire Line
	4350 3100 4350 3250
Connection ~ 4350 3250
Wire Wire Line
	4350 3250 4250 3250
Wire Wire Line
	4850 3200 4850 3250
Connection ~ 4850 3250
Wire Wire Line
	4850 3250 4650 3250
$Comp
L power:GND #PWR01
U 1 1 5C9DD1D8
P 4650 3300
F 0 "#PWR01" H 4650 3050 50  0001 C CNN
F 1 "GND" H 4655 3127 50  0000 C CNN
F 2 "" H 4650 3300 50  0001 C CNN
F 3 "" H 4650 3300 50  0001 C CNN
	1    4650 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 3300 4650 3250
Connection ~ 4650 3250
Wire Wire Line
	4650 3250 4350 3250
Wire Wire Line
	5050 2300 5050 2200
Wire Wire Line
	4950 2300 4950 2200
Text Label 4950 2200 0    50   ~ 0
D+
Text Label 5050 2200 0    50   ~ 0
D-
$Comp
L power:+5V #PWR02
U 1 1 5C9DD760
P 4750 2500
F 0 "#PWR02" H 4750 2350 50  0001 C CNN
F 1 "+5V" H 4765 2673 50  0000 C CNN
F 2 "" H 4750 2500 50  0001 C CNN
F 3 "" H 4750 2500 50  0001 C CNN
	1    4750 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 2500 4650 2500
$Comp
L Device:R R3
U 1 1 5C9DDA36
P 5300 2800
F 0 "R3" V 5093 2800 50  0000 C CNN
F 1 "2k2" V 5184 2800 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 5230 2800 50  0001 C CNN
F 3 "~" H 5300 2800 50  0001 C CNN
	1    5300 2800
	0    1    1    0   
$EndComp
Wire Wire Line
	5150 2800 5050 2800
Connection ~ 5050 2800
$Comp
L Device:R R4
U 1 1 5C9DDD14
P 5700 2800
F 0 "R4" V 5493 2800 50  0000 C CNN
F 1 "1k" V 5584 2800 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 5630 2800 50  0001 C CNN
F 3 "~" H 5700 2800 50  0001 C CNN
	1    5700 2800
	0    1    1    0   
$EndComp
$Comp
L Device:LED D3
U 1 1 5C9DDDBC
P 5850 3050
F 0 "D3" V 5888 2933 50  0000 R CNN
F 1 "LED" V 5797 2933 50  0000 R CNN
F 2 "LED_SMD:LED_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 5850 3050 50  0001 C CNN
F 3 "~" H 5850 3050 50  0001 C CNN
	1    5850 3050
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR03
U 1 1 5C9DDE69
P 5500 2700
F 0 "#PWR03" H 5500 2550 50  0001 C CNN
F 1 "+5V" H 5515 2873 50  0000 C CNN
F 2 "" H 5500 2700 50  0001 C CNN
F 3 "" H 5500 2700 50  0001 C CNN
	1    5500 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 2800 5500 2800
Wire Wire Line
	5500 2700 5500 2800
Connection ~ 5500 2800
Wire Wire Line
	5500 2800 5450 2800
Wire Wire Line
	5850 3200 5850 3250
Wire Wire Line
	5850 3250 4950 3250
Connection ~ 4950 3250
Wire Wire Line
	5850 2900 5850 2800
Wire Wire Line
	3250 2850 3350 2850
Wire Wire Line
	3250 2950 3350 2950
Wire Wire Line
	3350 2950 3350 2850
Connection ~ 3350 2850
Wire Wire Line
	3350 2850 3450 2850
Text Label 3450 2850 0    50   ~ 0
D+
Wire Wire Line
	3250 2750 3450 2750
Text Label 3450 2750 0    50   ~ 0
D-
$Comp
L power:GND #PWR07
U 1 1 5C9E1E53
P 5200 3600
F 0 "#PWR07" H 5200 3350 50  0001 C CNN
F 1 "GND" H 5205 3427 50  0000 C CNN
F 2 "" H 5200 3600 50  0001 C CNN
F 3 "" H 5200 3600 50  0001 C CNN
	1    5200 3600
	1    0    0    -1  
$EndComp
Text Label 4450 3600 0    50   ~ 0
USER
Text Label 3450 3050 0    50   ~ 0
USER
$Comp
L Connector:Conn_01x06_Male J2
U 1 1 5C9E3D92
P 3950 1550
F 0 "J2" H 3922 1523 50  0000 R CNN
F 1 "ISP" H 3922 1432 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 3950 1550 50  0001 C CNN
F 3 "~" H 3950 1550 50  0001 C CNN
	1    3950 1550
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3750 1850 3250 1850
Wire Wire Line
	3750 1750 3250 1750
Wire Wire Line
	3750 1650 3250 1650
Wire Wire Line
	3750 1550 3250 1550
$Comp
L power:GND #PWR05
U 1 1 5C9E7206
P 3700 1900
F 0 "#PWR05" H 3700 1650 50  0001 C CNN
F 1 "GND" H 3705 1727 50  0000 C CNN
F 2 "" H 3700 1900 50  0001 C CNN
F 3 "" H 3700 1900 50  0001 C CNN
	1    3700 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 1450 3700 1450
Wire Wire Line
	3700 1450 3700 1900
$Comp
L power:+5V #PWR04
U 1 1 5C9E7CFB
P 3700 1350
F 0 "#PWR04" H 3700 1200 50  0001 C CNN
F 1 "+5V" H 3715 1523 50  0000 C CNN
F 2 "" H 3700 1350 50  0001 C CNN
F 3 "" H 3700 1350 50  0001 C CNN
	1    3700 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 1350 3700 1350
$Comp
L Device:R R5
U 1 1 5C9E8A9D
P 4350 2050
F 0 "R5" V 4143 2050 50  0000 C CNN
F 1 "1k" V 4234 2050 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 4280 2050 50  0001 C CNN
F 3 "~" H 4350 2050 50  0001 C CNN
	1    4350 2050
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 5C9E8B37
P 4350 2150
F 0 "R6" V 4143 2150 50  0000 C CNN
F 1 "1k" V 4234 2150 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 4280 2150 50  0001 C CNN
F 3 "~" H 4350 2150 50  0001 C CNN
	1    4350 2150
	0    1    1    0   
$EndComp
$Comp
L Device:LED D4
U 1 1 5C9EA3CB
P 3900 2050
F 0 "D4" H 3891 2266 50  0000 C CNN
F 1 "LED" H 3891 2175 50  0000 C CNN
F 2 "LED_SMD:LED_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 3900 2050 50  0001 C CNN
F 3 "~" H 3900 2050 50  0001 C CNN
	1    3900 2050
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D5
U 1 1 5C9EA46F
P 3900 2150
F 0 "D5" H 3891 2366 50  0000 C CNN
F 1 "LED" H 3891 2275 50  0000 C CNN
F 2 "LED_SMD:LED_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 3900 2150 50  0001 C CNN
F 3 "~" H 3900 2150 50  0001 C CNN
	1    3900 2150
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR06
U 1 1 5C9EA4D2
P 4650 2000
F 0 "#PWR06" H 4650 1850 50  0001 C CNN
F 1 "+5V" H 4665 2173 50  0000 C CNN
F 2 "" H 4650 2000 50  0001 C CNN
F 3 "" H 4650 2000 50  0001 C CNN
	1    4650 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 2050 3250 2050
Wire Wire Line
	3750 2150 3250 2150
Wire Wire Line
	4200 2050 4050 2050
Wire Wire Line
	4200 2150 4050 2150
Wire Wire Line
	4500 2150 4650 2150
Wire Wire Line
	4650 2150 4650 2050
Wire Wire Line
	4500 2050 4650 2050
Connection ~ 4650 2050
Wire Wire Line
	4650 2050 4650 2000
$Comp
L power:GND #PWR011
U 1 1 5C9EF984
P 3450 2250
F 0 "#PWR011" H 3450 2000 50  0001 C CNN
F 1 "GND" H 3455 2077 50  0000 C CNN
F 2 "" H 3450 2250 50  0001 C CNN
F 3 "" H 3450 2250 50  0001 C CNN
	1    3450 2250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR010
U 1 1 5C9F0E96
P 2650 3950
F 0 "#PWR010" H 2650 3700 50  0001 C CNN
F 1 "GND" H 2655 3777 50  0000 C CNN
F 2 "" H 2650 3950 50  0001 C CNN
F 3 "" H 2650 3950 50  0001 C CNN
	1    2650 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 3950 2650 3900
Wire Wire Line
	2750 3850 2750 3900
Wire Wire Line
	2750 3900 2650 3900
Connection ~ 2650 3900
Wire Wire Line
	2650 3900 2650 3850
$Comp
L power:+5V #PWR09
U 1 1 5C9F34D4
P 1850 1950
F 0 "#PWR09" H 1850 1800 50  0001 C CNN
F 1 "+5V" H 1865 2123 50  0000 C CNN
F 2 "" H 1850 1950 50  0001 C CNN
F 3 "" H 1850 1950 50  0001 C CNN
	1    1850 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 1950 1850 1950
$Comp
L Device:Crystal Y1
U 1 1 5C9F4A41
P 1650 1650
F 0 "Y1" V 1604 1781 50  0000 L CNN
F 1 "12MHz" V 1695 1781 50  0000 L CNN
F 2 "Crystal:Crystal_HC49-4H_Vertical" H 1650 1650 50  0001 C CNN
F 3 "~" H 1650 1650 50  0001 C CNN
	1    1650 1650
	0    1    1    0   
$EndComp
Wire Wire Line
	2050 1750 1750 1750
Wire Wire Line
	1750 1750 1750 1800
Wire Wire Line
	1750 1800 1650 1800
Wire Wire Line
	2050 1550 1750 1550
Wire Wire Line
	1750 1550 1750 1500
Wire Wire Line
	1750 1500 1650 1500
$Comp
L Device:C C1
U 1 1 5C9F7AEB
P 1350 1500
F 0 "C1" V 1098 1500 50  0000 C CNN
F 1 "22p" V 1189 1500 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 1388 1350 50  0001 C CNN
F 3 "~" H 1350 1500 50  0001 C CNN
	1    1350 1500
	0    1    1    0   
$EndComp
$Comp
L Device:C C2
U 1 1 5C9F7C07
P 1350 1800
F 0 "C2" V 1098 1800 50  0000 C CNN
F 1 "22p" V 1189 1800 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 1388 1650 50  0001 C CNN
F 3 "~" H 1350 1800 50  0001 C CNN
	1    1350 1800
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR08
U 1 1 5C9F7C7A
P 1050 1650
F 0 "#PWR08" H 1050 1400 50  0001 C CNN
F 1 "GND" H 1055 1477 50  0000 C CNN
F 2 "" H 1050 1650 50  0001 C CNN
F 3 "" H 1050 1650 50  0001 C CNN
	1    1050 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 1500 1650 1500
Connection ~ 1650 1500
Wire Wire Line
	1500 1800 1650 1800
Connection ~ 1650 1800
Wire Wire Line
	1200 1500 1200 1650
Wire Wire Line
	1050 1650 1200 1650
Connection ~ 1200 1650
Wire Wire Line
	1200 1650 1200 1800
$Comp
L power:+5V #PWR013
U 1 1 5C9FF2DE
P 2650 850
F 0 "#PWR013" H 2650 700 50  0001 C CNN
F 1 "+5V" H 2665 1023 50  0000 C CNN
F 2 "" H 2650 850 50  0001 C CNN
F 3 "" H 2650 850 50  0001 C CNN
	1    2650 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 1050 2650 1050
Wire Wire Line
	2650 850  2650 950 
Connection ~ 2650 1050
$Comp
L Device:R R7
U 1 1 5CA033FF
P 2300 950
F 0 "R7" V 2093 950 50  0000 C CNN
F 1 "2k2" V 2184 950 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 2230 950 50  0001 C CNN
F 3 "~" H 2300 950 50  0001 C CNN
	1    2300 950 
	0    1    1    0   
$EndComp
Wire Wire Line
	2450 950  2650 950 
Connection ~ 2650 950 
Wire Wire Line
	2650 950  2650 1050
Wire Wire Line
	2150 950  2050 950 
Wire Wire Line
	2050 950  2050 1350
Wire Wire Line
	2050 950  1900 950 
Connection ~ 2050 950 
$Comp
L power:GND #PWR012
U 1 1 5CA0E25B
P 1350 1050
F 0 "#PWR012" H 1350 800 50  0001 C CNN
F 1 "GND" H 1355 877 50  0000 C CNN
F 2 "" H 1350 1050 50  0001 C CNN
F 3 "" H 1350 1050 50  0001 C CNN
	1    1350 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 2250 3450 2250
$Comp
L Device:R R8
U 1 1 5C9EF376
P 3750 3050
F 0 "R8" V 3543 3050 50  0000 C CNN
F 1 "2k2" V 3634 3050 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 3680 3050 50  0001 C CNN
F 3 "~" H 3750 3050 50  0001 C CNN
	1    3750 3050
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR0101
U 1 1 5C9EF460
P 4000 3050
F 0 "#PWR0101" H 4000 2900 50  0001 C CNN
F 1 "+5V" H 4015 3223 50  0000 C CNN
F 2 "" H 4000 3050 50  0001 C CNN
F 3 "" H 4000 3050 50  0001 C CNN
	1    4000 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 3050 3900 3050
Wire Wire Line
	3250 3050 3600 3050
Wire Wire Line
	1350 1050 1350 950 
Wire Wire Line
	1350 950  1500 950 
Wire Wire Line
	4450 3600 4700 3600
Wire Wire Line
	5200 3600 5100 3600
$Comp
L Switch:SW_Push SW2
U 1 1 5CA16353
P 4900 3600
F 0 "SW2" H 4900 3885 50  0000 C CNN
F 1 "USER" H 4900 3794 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 4900 3800 50  0001 C CNN
F 3 "" H 4900 3800 50  0001 C CNN
	1    4900 3600
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 5CA18993
P 1700 950
F 0 "SW1" H 1700 1235 50  0000 C CNN
F 1 "RST" H 1700 1144 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 1700 1150 50  0001 C CNN
F 3 "" H 1700 1150 50  0001 C CNN
	1    1700 950 
	1    0    0    -1  
$EndComp
$EndSCHEMATC
