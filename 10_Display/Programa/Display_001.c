#include <16f877a.h>     
#fuses HS, NOWDT, NOPUT, NOLVP, NOPROTECT, BROWNOUT
#use delay(clock=20M) 
#use fast_io(B)
#define pulsadorASC PIN_A0 // se define el pulsador que incrementa
#define pulsadorDSC PIN_A1 // se define el pulsador que decrementa

int display [10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f}; 
int contador;

void main ()
{
   set_tris_b(0b00000000); // inicia en cero
   output_b(0b00000000);
   
   while(true)
   {
   
      if(input(pulsadorASC)==1)
        {
        
         while(input(pulsadorASC) == 1); //Impide un doble contacto del pulsador
            delay_ms(2);
            
            contador++; // se incrementa el contador
            output_b(display[contador]); // se muestra en el display
         
               if(contador > 9)  // Si en contador es mayor a 9
               {
                  contador = 9;  // se queda en 9
                  output_b(display[contador]); // se muestra en display
               }
         }
      
      if(input(pulsadorDSC) == 1)
      {
      
         while(input(pulsadorDSC) == 1); //Impide un doble contacto del pulsador
            delay_ms(2);
            
            contador--; // se decrementa el contador
            output_b(display[contador]); // se muestra en el display
         
               if(contador == -1) //si el contador es igual a menos 1
               {
                  contador = 0; // el contador se queda en cero
                  output_b(display[contador]); // y se muestra en el display
               }
      }
   }
}

