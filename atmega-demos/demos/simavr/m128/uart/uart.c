#include "uart.h"

volatile int inInt;
char inString[CHAR_LEN];
FILE uart_out = {0} ;
FILE uart_in = {0} ;

static int uart_putchar(char ch,FILE*stream)
{
    if(ch=='\n'){uart_putchar('\r',stream);}
    while ((UCSR0A & (1 << UDRE0)) == 0) {};
    UDR0=ch;
    return 0;
}

static int uart_getchar(FILE*stream)
{
    (void) stream;
    char temp;

    while ((UCSR0A & (1 << RXC0)) == 0) {};
    temp=UDR0;
    return(temp);
}

static void uart_baud(void){
    UBRR0H=(((F_CPU / (BAUDRATE * 16UL))) - 1)>>8;
    UBRR0L=(((F_CPU / (BAUDRATE * 16UL))) - 1);
}

static void uart_retarget(void){
    fdev_setup_stream (&uart_out, uart_putchar, NULL, _FDEV_SETUP_WRITE);
    fdev_setup_stream (&uart_in, NULL, uart_getchar, _FDEV_SETUP_READ);
    stdout = &uart_out;
    stdin = &uart_in;
}

void uart_init(void){
	DDRE |= 1<<1;

    UCSR0B |= 1<<RXEN0 | 1<<TXEN0;
    UCSR0B |= 1<<RXCIE0;
    UCSR0C |= 1<<UCSZ01| 1<<UCSZ00;

    uart_baud();
    uart_retarget();

    sei();
}

ISR(USART0_RX_vect){
    scanf("%s",inString);

	if(strcmp(inString,"test")==0){
		printf("serial OK\n\r");
	}
	else{
		inInt = atoi(inString);
		if(inInt>0){
			printf("%2i \n\r",inInt);
		}
		else{
			printf("%s ?\n\r",inString);
		}
	}
    return;
}
