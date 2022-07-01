#include <16f877a.h>     
#device  ADC=10   // Se establece el la resolucion, 10Bits (0-1023). Resolucion= 5/1024 = 4.8mV
#fuses HS, NOWDT, NOPUT, NOLVP, NOPROTECT, BROWNOUT
#use delay(clock=20M) 
#use standard_io(D)
#use fast_io(C)

#define LCD_DB4   PIN_D4
#define LCD_DB5   PIN_D5
#define LCD_DB6   PIN_D6
#define LCD_DB7   PIN_D7
#define LCD_RW    PIN_D2
#define LCD_RS    PIN_D1
#define LCD_E     PIN_D0
#include <LCD.c>

long valor_adc;      // 16 bits = 65536 se declara para almacenar los datos
float temperatura;   // Trabajar con decimales

void main ()
{
   lcd_init();
   setup_adc_ports(AN0); // Se activa el AN0 que adquiere el voltaje analogico
   setup_adc(adc_clock_internal); // En conjunto con AN0 se debe activar el reloj interno del PIC
   
   output_low(PIN_C0);
   set_tris_c(0b00000000);
   
   
   while(true)
   {
      set_adc_channel(0); // Se activa el canal 0 que el pin RA0
      delay_us(2);
      valor_adc=read_adc();   // Lee los valores analogicos 
          
      lcd_putc("\f");
      temperatura=(valor_adc*500.0)/1023.0;  // 500*10mV=5V, 5V es el voltaje de fuente
      lcd_gotoxy(1,1);
      lcd_putc("Temperatura");
      lcd_gotoxy(2,2);
      printf(lcd_putc,"Es C=%f",temperatura);   // LCD agraga punto decimal 
      delay_ms(100);
      
      // Se define la temperatura de activición
      
      if(temperatura >= 40.0)
       {
         output_high(PIN_C0); // Pon en 1 la salida
         delay_ms(10);   // Retardo para ejecutar la instruccion anterior
       }
      if(temperatura <= 39.9)
       {
         output_low(PIN_C0); // Pon en 1 la salida
         delay_ms(10);   // Retardo para ejecutar la instruccion anterior
       }
   }
}

