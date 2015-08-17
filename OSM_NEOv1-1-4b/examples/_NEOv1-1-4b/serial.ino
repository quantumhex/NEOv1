// serial.ino


byte Sred;
byte Sgreen;
byte Sblue;
volatile byte inputChar ;
volatile char inChar;


/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
//void serialEvent(void)
//{// void serialEvent
  //while (Serial.available())
  //{
//
    //if (inChar == '\n')
    //{
      //stringComplete = true;
	  //Mode = GetFromSerial();
	  //ONN = 0;
    //}
  //}
//}// diov serialEvent


void serialEvent() 
{
	//while (Serial.available()) {
		//// get the new byte:
		//char inChar = (char)Serial.read();
		//// add it to the inputString:
		//inputString += inChar;
		//// if the incoming character is a newline, set a flag
		//// so the main loop can do something about it:
		//if (inChar == '\n') {
			//stringComplete = true;
		//}
	//}
}
		
		



// simple get serial, returns int
int GetFromSerial()
{ // int GetFromSerial
  while (Serial.available() <= 0) {
  }
  return Serial.read();
}// tni GetFromSerial








void getSerial()
{
  if (stringComplete)
  {
    Serial.println(inputChar);
    // clear the string:
    Mode = inputChar;
    inputChar = 0;
    stringComplete = false;
  }
}






/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
//void serialEvent()
//{
//  while (Serial.available())
//  {
//    char inChar = (char)Serial.read();
//    Mode = (inChar - 48);
//    inputChar = Mode;
//    stringComplete = true;
//  }
//}





// serial through Processing
void ProcessingRGB(void)
{ // void ProcessingRGB
  // call the returned value from GetFromSerial() function

  //  CC = GetFromSerial();

  if (GetFromSerial() == 'R') {
    Sred = GetFromSerial();
  }
  if (GetFromSerial() == 'G') {
    Sgreen = GetFromSerial();
  }
  if (GetFromSerial() == 'B') {
    Sblue = GetFromSerial();
  }

  osmPWM(Sred, Sgreen, Sblue, 500);
}// diov ProcessingRGB



/// PROCESING

void Mode_20(void) // Variable Values (Remote Programming)
{
	JustOnce();
	ProcessingRGB();
}



/*
This is just a vanity welcome screen to the serial ouptut.
*/
void PrintWelcome1(void)
{
#if defined(VISUAL)
  //Serial.println(F("                               #######  #####  #     # "));
  //Serial.println(F("#    # #    # #    #           #     # #     # ##   ##            ####   ####  #####  ######  ####"));
  //Serial.println(F("#    # #    # #    #           #     # #       # # # #           #    # #    # #    # #      #"));
  //Serial.println(F("#    # #    # #    #           #     #  #####  #  #  #           #      #    # #    # #####   ####"));
  //Serial.println(F("# ## # # ## # # ## #    ###    #     #       # #     #    ###    #      #    # #    # #           #"));
  //Serial.println(F("##  ## ##  ## ##  ##    ###    #     # #     # #     #    ###    #    # #    # #    # #      #    #"));
  //Serial.println(F("#    # #    # #    #    ###    #######  #####  #     #    ###     ####   ####  #####  ######  ####"));
  
  Serial.println();
  Serial.println(F(" www.OSM.codes * NEO v1.1.4 alpha 2 * Open Source Microlight "));
  Serial.println();
#endif  
}

void PrintWelcome2(void)
{
#if defined(VISUAL)
	//Serial.println();
	//Serial.println(F("        **************************************************"));
	Serial.println(F("        *           GREETINGS PROFESSOR FALKEN           *"));
	//Serial.println(F("        *                                                *"));
	//Serial.println(F("        *              SHALL WE PLAY A MODE?             *"));		
	//Serial.println(F("        **************************************************"));
	//Serial.println();
	//Serial.println(F("            ****************************************"));
	//Serial.println(F("            *      PLEASE CLICK YOUR SELECTION     *"));
	//Serial.println(F("            ****************************************"));		
	//Serial.println();
	//Serial.println();
	//Serial.println();
#endif	
}
