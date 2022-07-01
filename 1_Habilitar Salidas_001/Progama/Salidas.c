#include <16f877.h>
#fuses HS,NOWDT,NOPUT,NOLVP,NOPROTECT,BROWNOUT
#use delay(clock=20M)
#use fast_io(B)

void main()
{
  set_tris_b(0b00000000);
  output_b(0b00000000);
 
  while(true)
  {
  output_b(0b00001001);
  }
}

