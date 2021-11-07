void main() {
  int LDR;                     //describes the input LDR to be an integer 

  ANSELA.RA1 = 1;      //enables RA1 and sets it as analog
  ANSELD=0;                //sets the pin to digital 
  TRISA.RA1 = 1;        //sets pin to input
  TRISD=0;          //sets the digital pin to output
  
  UART1_Init(9600);      // initialize UART module at 9600bps
  Delay_ms(100);          // delay present to give time for UART module to stabilize 
  
  UART_Write_Text("LDR Readings:");     //prints ‘LDR readings:’ in serial monitor to show user UART module is functioning 
  UART1_Write(13);      //provide backslash (new line)
  UART1_Write(10);      //provide space
  Delay_ms(2000);        // provides a 2 second delay before entering the loop enough for user to read the message

  while(1)                //open endless loop
  {
  LDR = ADC_Read(1);     //convert LDR reading from analog to digital and save in LDR 

  if(LDR > 500)                  //comparator provides condition required for LEDs to turn on 
  {
   UART1_Write_Text("Light enabled");            //when condition is met write light enabled in serial monitor 
   UART1_Write(13);       //provide backslash (new line)
   UART1_Write(10);      //provide space
   Delay_ms(500);          // delay for 0.5 seconds before going through the loop again
   PORTD = 0xFF;           // turn on all LEDs at PORT D, all LEDs light 
   }
   else                             //if condition is not satisfied the following will take place
   {
   UART1_Write_Text("light off");     //if condition is not met write light off in serial monitor
   UART1_Write(13);         //provide backslash (new line)
   UART1_Write(10);        //provide space
   Delay_ms(500);            // delay for 0.5 seconds before going through the loop again
   PORTD = 0x00;        //turn off all LEDs at PORT D 
   }
  }
  }