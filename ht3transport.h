#ifndef HT3TRANSPORT_H
#define HT3TRANSPORT_H
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>


#define UART_TRANSMIT_COMPLETE_INTERRUPT USART_TX_vect
#define UART_RECEIVE_INTERRUPT   USART_RX_vect
#define UART_TRANSMIT_INTERRUPT  USART_UDRE_vect
#define UART_STATUS   UCSR0A
#define UART_CONTROL  UCSR0B
#define UART_DATA     UDR0
#define UART_UDRIE    UDRIE0
#define UCSRC UCSR0C
#define RXCIE RXCIE0
#define TXCIE TXCIE0
#define RXEN RXEN0
#define TXEN TXEN0
#define UCSZ0 UCSZ00
#define U2X U2X0
#define UBRRH UBRR0H
#define UBRRL UBRR0L

#define BAUD 9600

#ifndef F_CPU
#error " F_CPU not defined "
#else
   #define UBRR (F_CPU / 8 / BAUD ) -1 
#endif

#define waitForSync 0
#define waitForFrame 1
#define receive 2
volatile uint8_t recstate;

#define noData 0
#define dataValid 1
volatile uint8_t datastate;

volatile uint8_t bufpos;
volatile uint8_t buffer[64];

extern void ht3Init(void);
uint8_t ht3CheckCRC(volatile uint8_t * buffer, volatile uint8_t bufpos);

#endif 
