#include <16f877a.h>     
#fuses HS, NOWDT, NOPUT, NOLVP, NOPROTECT, BROWNOUT
#use delay(clock=20M) 
#use fast_io(B)
#use standard_io(D) // Activa el puerto D

void main ()
{
   set_tris_b(0b11111111); // se habilita el puerto b como entrada
   output_low(PIN_D6);   // inicia el pin D6 en 0
   
   while(true)
   {
      if(input(PIN_B0) == 1)  // SI el pulsador esta presionado
      {
         output_high(PIN_D6); // Pon en 1 la salida
      }
      else  //Si NO esta presionado el pulsador, entonces.
      {
         output_low(PIN_D6); //pon la salida en 0
      }
   }
}

