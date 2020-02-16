// CONFIG1H
#pragma config OSC = HS         // Oscillator Selection bits (HS oscillator)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown Out Reset Voltage bits (Minimum setting)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = PORTC   // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = OFF      // MCLR Pin Enable bit (RE3 input pin enabled; MCLR disabled)

// CONFIG4L
#pragma config STVREN = OFF     // Stack Full/Underflow Reset Enable bit (Stack full/underflow will not cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#define _XTAL_FREQ 8000000

#include <xc.h>
#include "../lcd.h"

#define VENTOINHA_ATIVADA T1CONbits.TMR1ON

int vmax; // velocidade máxima da ventoinha

void iniciaRegistradores(){  
  TRISD = 0b00000000;         // Habilita porta D como saída dado LCD  
  TRISE = 0b00000000;        // porta E saida controle do LCD
     
  // setupADC
  TRISA = 0b00000011;         // Habilita pino A0-A2 como entrada

  ADCON1 = 0b00001101;        // pinos analogicos e referência

  ADCON2bits.ADCS = 0b110;    // Clock do AD: Fosc/64
  ADCON2bits.ACQT = 0b100;    // Tempo de aquisição: 8 Tad
  ADCON2bits.ADFM = 0b1;      // Formato: à direita

  ADCON0 = 0;                 
  ADCON0bits.CHS = 0b0000;     // Seleciona o canal AN?
  ADCON0bits.ADON = 1;        // Liga o AD
  
  ADCON1 = 0x0F; 

  RCONbits.IPEN = 0;
  INTCONbits.GIE = 1;
  INTCONbits.PEIE = 1;

  INTCON3bits.INT1IF = 0;
  INTCON3bits.INT1IE = 1;
  INTCON2bits.INTEDG1 = 1;
}

const char teclas[4][3] = {{'1','2','3'},
                           {'4','5','6'},
                           {'7','8','9'},
                           {'.','0','*'}};

// retorna tecla pressionada (0 se nada foi pressionado)
char le_tecla(){
  TRISB = 0xf0;
  for(int j = 0; j < 3; ++j){
    PORTB = ~(1u << (3 - j)); // seleciona uma coluna da matriz
    for(int i = 4; i < 8; ++i){
      if(!(PORTB & (1 << i))){  // checa a linha
        PORTB = 0xff;
        return teclas[i][j];
      }
    }
  }
  PORTB = 0xff;
  return 0;
}

// lê um número do teclado
unsigned le_int(){
  INTCON = 0;
  TRISA = 0b00000111;         // Habilita pino A0-A2 como entrada

  unsigned valor = 0;
  while(1){
    TRISD = 0xFF;
    TRISB = 0x00;
    PORTB = 0xFF;
    PORTD = 0xFF;

    char tecla = 0;
    while(!tecla){  // enquanto não fizer leitura
      tecla = le_tecla();  // busca uma tecla
    }
    if(tecla == '.' || tecla == '*'){ // encerra entrada do número
      break;
    }
    valor = 10 * valor + tecla - '0';

    //*
    inicia_lcd();
    comando_lcd(128);
    imprime_int(valor);
    __delay_ms(500);
    //*/
  }

  return valor;
}

// seta velocidade da ventoinha de acordo com o potenciômetro
void atualizaVentoinha(){
  TRISD = 0x00;
  PORTD = 0xFF;

  TMR2 = 0x00;   // Começa a contar de 0
  PR2 = 255;      // periodo
  CCP1CON = 0b00001100; // Ativa PWM
  
  // leitura do potenciômetro
  ADCON1 = 0b00001101;
  ADCON0bits.ADON = 1;
  ADCON0bits.GO = 1;  // Inicia a conversão A/D
  while(ADCON0bits.GO);
  
  // calcula tensão do conversor
  int t = ADRESH * 0x100 + ADRESL;
  t *= 0.249266862;
  CCPR1L = t; // ciclo ativo
  
  // verifica se a velocidade está acima da máxima
  int v = 0.31372549 * t; // 80t/255
  TRISCbits.RC1 = 0;
  PORTCbits.RC1 = v <= vmax || !VENTOINHA_ATIVADA; // abaixo do limite ou desligado: não buzina
  
  inicia_lcd();
  comando_lcd(128);
  if(PORTCbits.RC1)
    imprime_int(v);
  else
    imprime_lcd("UAU! MT. RAPIDO!");
  comando_lcd(192);
  imprime_int(vmax);
  
  TMR2IF = 0;                     // Limpa flag do TMR2
  TRISCbits.RC2 = 0;              // "liga" bit de saída DO PWM
  T2CON = 0b00000100;             // Liga timer 2
}

void ativaVentoinha(){
  atualizaVentoinha();

  INTCONbits.GIE = 1;
  
  // ativa interrupção para ler o potenciômetro
  PIE1bits.TMR1IE = 1;
  PIR1bits.TMR1IF = 0;
  TMR1H = 0;  // 262ms
  TMR1L = 0;
  T1CON = 0b11110101; // 16 bits, pre-scaler = 1:8, ligado
}

void desativaVentoinha(){
  limpa_lcd();
  T1CONbits.TMR1ON = 0; // desliga timer1
  CCPR1L = 0; // desliga PWM
  PORTCbits.RC1 = 1;  // desliga buzina
}

void interrupt isr(){
  if(PIR1bits.TMR1IF && PIE1bits.TMR1IE){
    TMR1H = 0;  // 262ms
    TMR1L = 0;
    PIR1bits.TMR1IF = 0;
    atualizaVentoinha();
  }
  
  // ativa/desativa ventoinha
  if(INTCON3bits.INT1IF && INTCON3bits.INT1E){
    INTCON3bits.INT1IF = 0;
    T1CONbits.TMR1ON ? desativaVentoinha() : ativaVentoinha();
  }
}

void main()
{
  inicia_lcd();
  comando_lcd(128);
  imprime_lcd("Entre com a");
  comando_lcd(192);
  imprime_lcd("velocidade max.");
  
  vmax = le_int();
  
  ativaVentoinha();
  iniciaRegistradores();
  
  while(1);
}
