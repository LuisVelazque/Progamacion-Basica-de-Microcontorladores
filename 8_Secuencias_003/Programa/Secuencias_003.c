#include <16f877a.h>
#fuses HS,NOWDT,NOPUT,NOLVP,NOPROTECT,BROWNOUT
#use delay(clock=20M)
#use standard_io(B)
#use fast_io(D)

int tiempo=1000; // se declara una constante con valor numerico entero.
int i1; // se declaran las i1, i2 y i3, pueden declararse en la sentencia FOR después del abrir el paréntesis 
int i2;
int i3;
void main()
{
   set_tris_d(0b00000000);
   output_d(0b00000000);
   
   while(true)
   {
      if(input(PIN_B0) == 1) // si se presiona el pulsador de B0
      {
         for(i1=0; i1<3; i1++) // comienza en cero; si es menor de 4 veces; entonces incrementa hata 4 veces.
         {
            output_d(0b00000001);
            delay_ms(tiempo);
            output_d(0b00000010);
            delay_ms(tiempo);
            output_d(0b00000100);
            delay_ms(tiempo);
            output_d(0b00001000);
            delay_ms(tiempo);
            output_d(0b00010000);
            delay_ms(tiempo);
            output_d(0b00100000);
            delay_ms(tiempo);
            output_d(0b01000000);
            delay_ms(tiempo);
            output_d(0b10000000);
            delay_ms(tiempo);
         }
      }
      if(input(PIN_B1) == 1) // si se presiona el pulsador de B1
      {
         for(i2=0; i2<3; i2++)
         {
            output_d(0b10000000);
            delay_ms(tiempo);
            output_d(0b01000000);
            delay_ms(tiempo);
            output_d(0b00100000);
            delay_ms(tiempo);
            output_d(0b00010000);
            delay_ms(tiempo);
            output_d(0b00001000);
            delay_ms(tiempo);
            output_d(0b00000100);
            delay_ms(tiempo);
            output_d(0b00000010);
            delay_ms(tiempo);
            output_d(0b00000001);
            delay_ms(tiempo);
         }
      }     
      if(input(PIN_B2) == 1) // si se presiona el pulsador de B2
      {
         for(i3=0; i3<3; i3++)
         {
            output_d(0b10000001);
            delay_ms(tiempo);
            output_d(0b01000010);
            delay_ms(tiempo);
            output_d(0b00100100);
            delay_ms(tiempo);
            output_d(0b00011000);
            delay_ms(tiempo);
            output_d(0b00011000);
            delay_ms(tiempo);
            output_d(0b00100100);
            delay_ms(tiempo);
            output_d(0b01000010);
            delay_ms(tiempo);
            output_d(0b10000001);
            delay_ms(tiempo);
         }
      }
      
      else
      {
         output_d(0b00000000); // SI NO se presiona ningun pulsador, entonces el puerto debe estar apagado.
      }
   }
}

