#include <16f877a.h>
#fuses HS, NOWDT, NOPUT, NOLVP, NOPROTECT, BROWNOUT
#use delay(clock=20M)
#define use_portd_lcd TRUE //configuracion de puerto b para LCD
#define use_portb_kbd TRUE // configuracion de puerto bpara teclado
#include <lcd.c>           // libreria LCD 16x2
#include <kbd.c>           // libreria trclado 4x3

char tecla=0;           // Variable para caracter o simbologia
int valor_numerico=0;   // es valor numerico del caracter
long retardo=2000;      // entero de 16bit valor max 2^16

void main()
{
   port_b_pullups(0b11111110); // es necesario una mascara de bits como parametro 1=activa  0=desactiva.
   lcd_init();
   kbd_init();
   lcd_putc("\fTeclado 4x3\nLCD 16x2");  //putc (se envia dato a LCD).
      
      while (true)
      {
         tecla=kbd_getc();       // _getc significa ontener del teclado.
         if(tecla!=0)            // != significa DIFERENTE.
         {
            
            valor_numerico=tecla-48; // operacion lo que se envia del teclado el pic le restara 48.
            printf(lcd_putc,"\fCar=%c   ASCII=%u\n", tecla,tecla); //Al pulsar un digito se 
                                                                     // visualiza y el caracter 
                                                                     // correspondiente asi como 
                                                                     // el codigo ASCII*/
                                                                     // \f limpia 
                                                                     // \n cambio de linea
            printf(lcd_putc,"Num=%u",valor_numerico); // %u Representación de entero sin signo
            delay_ms(retardo);
            lcd_putc("\fTeclado 4x3\nLCD 16x2"); // mesaje principal
            delay_ms(300);
         }
      }
}

