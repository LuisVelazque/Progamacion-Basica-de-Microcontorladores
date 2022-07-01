#include <16f877a.h>
#fuses HS, NOWDT, NOPUT, NOLVP, NOPROTECT, BROWNOUT
#use delay(clock=20M)
#use standard_io(D)
#use fast_io(B)
/////////// Se definen los pines donde la LDC recibe datos
#define LCD_DB4   PIN_D4
#define LCD_DB5   PIN_D5
#define LCD_DB6   PIN_D6
#define LCD_DB7   PIN_D7
#define LCD_RW    PIN_D2
#define LCD_RS    PIN_D1
#define LCD_E     PIN_D0
#include <LCD.c>  // libreria de LCD 2x16

void main ()
{
   set_tris_b(0b11111111);
   lcd_init();
     
   while(true)
      {
         if(input(PIN_B0) == 1)  
         {
          lcd_gotoxy(1,1); // esta instración permite seleccionar la fila superior
          lcd_putc("Luis Enrique"); // esta instracción emite el mensaje
          delay_ms(500);
          
          lcd_gotoxy(1,2); // esta instración permite seleccionar la fila inferior
          lcd_putc("Velazquez Gonzalez"); // esta instracción emite el mensaje
          delay_ms(1000);
         }
        if(input(PIN_B1) == 1)
         {
          lcd_putc("\f"); // esta instracción borra el mensaje 
          delay_ms(200);
         }
      }
}

