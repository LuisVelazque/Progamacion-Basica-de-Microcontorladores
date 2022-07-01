#include <16f877a.h>     
#fuses HS, NOWDT, NOPUT, NOLVP, NOPROTECT, BROWNOUT
#use delay(clock=20M) 
#use fast_io(B)
int tiempo = 1000; 

void main ()
{
   set_tris_b(0b00000000);
   output_b(0b00000000);
   
   while(true)
   {
      output_d(0b10000001);
      delay_ms(tiempo);
      output_d(0b01000010);
      delay_ms(tiempo);
      output_d(0b00100100);
      delay_ms(tiempo);
      output_d(0b00011000);
      delay_ms(tiempo);
      output_d(0b00100100);
      delay_ms(tiempo);
      output_d(0b01000010);
      delay_ms(tiempo);
      output_d(0b10000001);
      delay_ms(tiempo);
      output_d(0b0000000);
      delay_ms(tiempo);
    }
}

