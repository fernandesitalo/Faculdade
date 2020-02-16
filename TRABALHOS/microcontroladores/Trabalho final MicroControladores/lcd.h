/// lcd.h
// --> não é possível acessar o pino R/W da placa

#define comando_lcd(cmd) envia_lcd(0, cmd)
#define dado_lcd(dado) envia_lcd(1, dado)
#define linha_lcd(i) envia_lcd(0, (!i ? 0x80 : 0xc0)) // linha 0 ou 1

void envia_lcd(unsigned char rs, unsigned char dado){
  PORTEbits.RE2 = rs;  // define se é um dado (1) ou um comando (0)
  PORTEbits.RE1 = 1;  // clock para o lcd fazer a leitura (pulso de descida)
  PORTD = dado;
  __delay_ms(2);
  PORTEbits.RE1 = 0;
}

void limpa_lcd(){
  comando_lcd(1);
}

void inicia_lcd(){
  TRISD = 0;
  TRISE = 0;
  ADCON1 = 0x0f;  // configura como porta digital
  comando_lcd(0b00111100);  // via de 8 bits, 2 linhas e formato 5x7
  comando_lcd(0b00001100);  // ativa o display, desativa cursor e caractere não pisca
  limpa_lcd();
}

void imprime_lcd(const char* s){
  for(int i = 0; i < 16 && s[i]; ++i){
    dado_lcd(s[i]);
  }
}

void imprime_int(int x){
  char str[7] = {0};

  char isNeg = 0;
  if(x < 0){ // checa se é nº negativo p/ add sinal
    isNeg = 1;
    x = -x;
  }

  unsigned i = 5;
  if(!x) str[--i] = '0';
  while(x){ // converte p/ string
    str[--i] = x % 10 + '0';
    x /= 10;
  }
  if(isNeg) str[--i] = '-'; // insere sinal

  imprime_lcd(str + i); // imprime
}

void imprime_uint(unsigned x){
  char str[6] = {0};

  unsigned i = 5;
  if(!x) str[--i] = '0';
  while(x){ // converte para string
    str[--i] = x % 10 + '0';
    x /= 10;
  }

  imprime_lcd(str + i); // imprime
}
