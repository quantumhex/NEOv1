


/// we are going to use this later
//int C1; // Used on OSMprotocol
//int C2; // Used on OSMprotocol
//int C3; // Used on OSMprotocol
//int V1; // Used on OSMprotocol
//int V2; // Used on OSMprotocol
//int V3; // Used on OSMprotocol





// We will send the Current Mode with this
void SerialSendMode(void)
{// void SerialSendMode
  
  #if defined(VISUAL)
	  Serial.print(F("> Bundle# "));Serial.print((CurrentUserBundle+1));
	  Serial.print(F(" / BundleMode: ")); Serial.print(CurrentUserMode); 
	  Serial.print(F(" / MaxModes# "));Serial.print(MaxUserModes);
	  Serial.print(F(" / Mode#: ")); Serial.println(Mode); 
  #endif
  
	  //if (STATE == 1)
	  //{
		//Serial.print(111);  //Serial.print(F(","));// MASTER send C1 value
	  //}
	  //else
	  //{
		//Serial.print(222);  //Serial.print(F(","));// SLAVE send C1 value
	  //}
//
	  //Serial.println();
   
	  //Serial.print(Mode); Serial.print(F(","));// Mode (0-255) send C2
	  //Serial.print(Change); Serial.print(F(","));// Change (0-255) C3
	  //Serial.print(0); Serial.print(F(","));// N/A V1
	  //Serial.print(0); Serial.print(F(","));// N/A V2
	  //Serial.print(0); Serial.print(F(","));// N/A V3
	  //Serial.print(0); // N/A V4

	#if defined(VISUAL)
		PrintModeFormula(0);
		PrintModeFormula(1);
	#endif
	
	
}// diov SerialSendMode





void PrintModeFormula(byte ThisVariation)
{// void PrintModeFormula

#if defined(VISUAL)
			if (ThisVariation == 0)
			{// if ThisVariation
				VariationOffset = 0;
			}// fi ThisVariation
			else
			{// else
				VariationOffset = 18;
			}// esle
			

				  for (k = 0; k < 18; k++)
				  {// for k
					  myChar =  ModeSetSRAM[(Mode-1)][(VariationOffset+k)];
					  Serial.print(myChar,DEC);Serial.print(F(","));
					  k++;
					  myChar =  ModeSetSRAM[(Mode-1)][(VariationOffset+k)];
					  Serial.print(myChar,DEC);Serial.print(F(",  "));
				  }// rof k
				Serial.print(F("  // Mode ")); Serial.print(Mode);
				Serial.print(F("  // Prime ")); 
				if (ThisVariation == 0) { Serial.println(F("A"));}
				else { Serial.println(F("B"));}
#endif
				
}// diov PrintModeFormula









