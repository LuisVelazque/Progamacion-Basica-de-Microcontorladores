#include <16f877a.h>     
#fuses HS, NOWDT, NOPUT, NOLVP, NOPROTECT, BROWNOUT
#use delay(clock=20M)
#use fast_io(B)

void main ()
{
   // Lo que se declare antes del While solo se realiza una vez
   set_tris_b(0b00000000);   //instruccion para utilizar fast_io
   output_b(0b00000000);  // se declara el puerto B en cero al energizar el PIC
      
      while(true) //ciclo infinito, lo que se declare se repitara una y otra vez
      {
         output_high(PIN_B0); //esta instruccion permite poner a B0 en 1
         output_low(PIN_B1);//esta instruccion permite poner a B1 en 0
         output_high(PIN_B2); //esta instruccion permite poner a B0 en 1
         output_low(PIN_B1);
         output_low(PIN_B3);
         delay_ms(1000);  //esta instruccion permite un retardo de 1000 mili segundos o 1 segundo
         output_low(PIN_B2);
         output_low(PIN_B0);
         output_high(PIN_B1);
         output_high(PIN_B3);
         delay_ms(1000);
      }
}

