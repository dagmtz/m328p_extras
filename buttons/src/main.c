/*
 * File:            main.c
 * Author:          Daniel Martinez
 *                  dagmtzs@gmail.com
 * Date:            Sun Jun 22 08:52:51 PM CST 2025
 * Target:          ATmega328P
 * Description:     This is a program to showcase a library 
 *                  intended to ease the use of buttons.
 */

/************************************************
 *       << Area for includes >>                *
 ************************************************/

#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>

#include <util/delay.h>
#include <usart.h>

/************************************************
 *       << Area for macro definitions >>       *
 ************************************************/

/* Size for usartBuffer used in main() */
#define BUFFER_SIZE 30U

/* Select heartbeat source via macro: 0 - No source, 1 - Internal int., 2 - External int. */
#define __HEARTBEAT_SOURCE 2

/* Select time source via macro: 0 - No source, 1 - Internal EEPROM, 2 - External RTC */
#define __TIME_SOURCE 2

/* EEPROM address where time is stored */
#define EEPROM_TIME_ADDR 0x40

/* Uncomment next line if you want to set up the time into EEPROM once, then compile and flash, then comment back and compile and flash again.*/
/* #define EEPROM_TIME_INIT */

/* Uncomment next line if you want to set up the time into RTC once, then compile and flash, then comment back and compile and flash again.*/
/* #define RTC_TIME_INIT */

#define __HALT while(1U){;}
#define UART_INFO uart_puts_P("\r\033[1;33m[INFO]: ")
#define UART_ERROR uart_puts_P("\r\033[1;31m[ERROR]: ")
#define UART_FCLEAN uart_puts_P("\r\033[0m")
#define UART_NL uart_puts_P("\r\n")

/************************************************
 *       << Area for globals >>                 *
 ************************************************/

/************************************************
 *       << Area for custom datatypes >>        *
 ************************************************/


/************************************************
 *       << Area for function prototypes >>     *
 ************************************************/
void initialize(void);


/************************************************
 *       << Main function >>                    *
 ************************************************/
void main(void){	    

    /* Initialization */
    initialize();

#ifdef UART_BUFFER
    char usartBuffer[BUFFER_SIZE];
#endif

    /* Clean format for UART text */
    UART_FCLEAN;
    UART_NL;

    /* Main loop */
    while (1U) 
    {
      /* Hi */
    }
    
    return;
}

void initialize()
{
  uart_init( BAUD_CALC( BAUD ) ); // 8n1 transmission is set as default
	
  stdout = &uart0_io; // attach uart stream to stdout & stdin
  stdin = &uart0_io; // uart0_in and uart0_out are only available if NO_USART_RX or NO_USART_TX is defined

  uart_puts_P( "\033[2J\033[H" );
  UART_INFO;	
  uart_puts_P( "USART ready\r\n" );
}
