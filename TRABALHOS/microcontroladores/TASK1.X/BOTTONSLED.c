#define _XTAL_FREQ 4000000

#include <xc.h>
#include <stdlib.h>


#define BOTAO1 PORTBbits.RB4
#define BOTAO2 PORTBbits.RB5
#define BOTAO3 PORTBbits.RB6


#define LED1    PORTDbits.RD3
#define LED2    PORTDbits.RD4
#define LED3    PORTDbits.RD5
#define LED4    PORTDbits.RD6

#define OFF 0
#define ON 	1

// #define TIME 500

void main( ) {  
    
    TRISB = 1; // configurar portaB como entrada .: sao os botoes
	TRISD = 0x0; //configura portd como saida
	PORTD = 0x0;
	// inicializacao dos leds
	LED1 = LED2 = LED3 = 0;
	
	while(1){
		while(BOTAO1 == 1){
			LED1 = ON;
			LED2 = ON;
			LED3 = ON;
			LED4 = ON;
			__delay_ms(500);
			LED1 = OFF;
			LED2 = OFF;
			LED3 = OFF;
			LED4 = OFF;
		}
		
		while(BOTAO2 == 1){
			LED1 = ON;	
			LED2 = ON;
			__delay_ms(500);
			LED3 = ON;
			LED4 = ON;
			LED1 = OFF;
			LED2 = OFF;
			__delay_ms(500);
			LED3 = OFF;
			LED4 = OFF;
		}
        
        while(BOTAO3 == 1){
			LED1 = ON;	
			LED3 = ON;
			__delay_ms(500);
			LED2 = ON;
			LED4 = ON;
			LED1 = OFF;
			LED3 = OFF;
			__delay_ms(500);
			LED2 = OFF;
			LED4 = OFF;
		}
	}
}
