### Programming line

#### atmega128x/256x programming line
```
5v  --> VCC
5v  --> AVCC
0v  --> GND
SS  --> RESET
MOSI--> PE.0 (PDI)
MISO--> PE.1 (PDO)
SCK --> PB.1
```

#### other atmega programming line
```
5v  --> VCC
5v  --> AVCC
0v  --> GND
SS  --> RESET
MOSI--> PB.3
MISO--> PB.4
SCK --> PB.5
```

### Unix Virtual Serial-Port

#### in one terminal shell
~~~
socat -d -d pty,raw,echo=0 pty,raw,echo=0
~~~

#### in one other terminal shell
~~~
sudo ln -sf /dev/pts/3 /dev/ttyV3
sudo ln -sf /dev/pts/4 /dev/ttyV4
minicom -b 9600 -D /dev/ttyV4
~~~

### unsupported part

#### simavr
- Timer 16bit Phase Correct PWM Mode.
- UART in SPI mode.
- Analog Comparator
- Main Clock divider calculation
- TWI/I2C

#### simulide
