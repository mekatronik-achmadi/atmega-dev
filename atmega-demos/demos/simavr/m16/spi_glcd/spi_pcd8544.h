#ifndef SPI_PCD8544_H_INCLUDED
#define SPI_PCD8544_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

  #ifndef PORT
    #define PORT PORTB
  #endif
  #ifndef DDR
    #define DDR  DDRB
  #endif
  #ifndef SCK
    #define SCK  PB7  // SCK
  #endif
  #ifndef RST
    #define RST  PB6  // MISO
  #endif
  #ifndef DIN
    #define DIN  PB5  // MOSI
  #endif
  #ifndef CE
    #define CE   PB4  // SS
  #endif
  #ifndef DC
    #define DC   PB1  // INT2
  #endif

  #define MAX_NUM_ROWS 6
  #define MAX_NUM_COLS 84
  #define CACHE_SIZE_MEM (MAX_NUM_ROWS * MAX_NUM_COLS)

  void Pcd8544Init(void);
  void CommandSend(unsigned char data);
  void DataSend(unsigned char data);
  void ResetImpulse(void);
  void ClearScreen(void);
  void UpdateScreen(void);
  char DrawChar(char character);
  void DrawString(char *str);
  char SetTextPosition(unsigned char x, unsigned char y);
  char SetPixelPosition(unsigned char x, unsigned char y);
  char DrawPixel(unsigned char x, unsigned char y);
  char DrawLine(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2);

#endif // SPI_PCD8544_H_INCLUDED
