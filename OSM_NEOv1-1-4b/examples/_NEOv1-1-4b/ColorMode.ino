// ColorChange.ino
///
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////


	 
byte ChangeToSet;

void CCreturnAndSave(void)
{// void CCreturnAndSave
	
	 ////////////////////////////////////////////////////////////////////////////////////////////////
	 ////////////////////////////////////////////////////////////////////////////////////////////////
	 
	if (JUSTONCE)
	{/// if JUSTONCE
		ToBorNotToB = true;
		ONNS = true;
		FirstPrintFlag = 1;
		if (VARIATION == 0)
		{
			VariationOffset = 0;
			ONCE_RESET_COLOR_MODES = 1;
		}
		else
		{
			VariationOffset = 18;
			ONCE_RESET_COLOR_MODES = 0;
		}
		ColorToSave = 0;		
		ONCE_SETUP_COLOR = 1;
		if (STATE == 1)
		{
			SerialSendMode();  // Sends the current Mode via Serial TX
		}
		CSHADE = 0;
		JUSTONCE = 0;
	}// FI JUSTONCE
		
	////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////
	   
	if (ONCE_RESET_COLOR_MODES)// This will bring the modes back to zero
	{// if ONCE_RESET_COLOR_MODES
		//Serial.println(F(" > YOU GET HERE ONLY ONCE ")); // DEBUUUUUUUGGGGGGGGGGGGGGGGGGGGGGGGGGG
		ModeToChange = Mode;
		ModeToChange--; // OFFSET
        CurrentColor = 0;
		ColorMaxCount[0] = 0;// variation 0
		ColorMaxCount[1] = 0;// variation 1
        ONCE_SAVE_COLOR = 0 ;
		///////////// RESET SRAM ///////////////////////
		for (k = 0; k < 36; k++)// reset the mode
		{// for k
			ModeSetSRAM[ModeToChange][(k)] = 0;
			k++;
		}// rof k
		////////////////////////////////////////////////
		////////////////////////////////////////////////
		ModeSetSRAM [ModeToChange][0] = (ColorToSave+1);// Max Colors variation 0
		ModeSetSRAM [ModeToChange][1] = 1; // CC palette variation 0
		ModeSetSRAM [ModeToChange][18] = (ColorToSave+1);// Max Colors variation 1
		ModeSetSRAM [ModeToChange][19] = 1; // CC palette variation 1
		////////////////////////////////////////////////
		ONCE_RESET_COLOR_MODES = 0;
	}// fi ONCE_RESET_COLOR_MODES
	
	
   ////////////////////////////////////////////////////////////////////////////////////////////////
   ////////////////////////////////////////////////////////////////////////////////////////////////
   
   
	if (ONCE_SAVE_COLOR)
	{// if ONCE_SAVE_COLOR
		// DISABLE INTERRUPTS HERE
		noInterrupts();
		// save the color here
		CCSET = 1;// replace with current color set value
		CCR[VARIATION][ColorToSave] =  pgm_read_word_near(&(osmCC_PROGMEM[CCSET][(CurrentColor*3)]));
		CCG[VARIATION][ColorToSave] =  pgm_read_word_near(&(osmCC_PROGMEM[CCSET][(CurrentColor*3)+1]));
		CCB[VARIATION][ColorToSave] =  pgm_read_word_near(&(osmCC_PROGMEM[CCSET][(CurrentColor*3)+2]));
		CCS[VARIATION][ColorToSave] =  CSHADE ;
		// save to local Modeset
		ModeSetSRAM [ModeToChange][(VariationOffset)] = (ColorToSave+1);// MaxColors Change 1
		ModeSetSRAM [ModeToChange][(VariationOffset+1)] = 1;// Color Palette
    	ModeSetSRAM [ModeToChange][((ColorToSave*2)+(VariationOffset+2))] = CurrentColor; // Current Color and offset 4
   		ModeSetSRAM [ModeToChange][((ColorToSave*2)+(VariationOffset+3))] = CSHADE;// Current Color Shade and offset 5
		/// we don't save on eeprom until we are out of here
		ToBorNotToB = 1;
		BlinkyCount = 7;
		osmPWMSCC(0,0,0, 0, 1000);
		while (BlinkyCount > 0)
		{// while BlinkyCount
			osmPWMSCC(CCR[VARIATION][ColorToSave],CCG[VARIATION][ColorToSave],CCB[VARIATION][ColorToSave],CCS[VARIATION][ColorToSave], 10);
			osmPWMSCC(0,0,0, 0, 60);
			BlinkyCount--;
		}// elihw BlinkyCount
		// ENABLE INTERRUPTS HERE
		interrupts();
		Serial.println();
		PrintTopFormula();
        PrintModeFormula(VARIATION);
        PrintMenuAfterOne();
		VirtualPreview = 1;
		COLOR_NAV = 0;// Color Limbo (Chance to Save or Delete)
		ONCE_SETUP_COLOR = 0;
        ONCE_SAVE_COLOR = 0;
	}// fi ONCE_SAVE_COLOR
	
	
    /////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////

	if (ONCE_SETUP_COLOR)
	{// if ONCE_SETUP_COLOR
		CCR[VARIATION][ColorToSave] =  pgm_read_word_near(&(osmCC_PROGMEM[CCSET][(CurrentColor*3)]));
		CCG[VARIATION][ColorToSave] =  pgm_read_word_near(&(osmCC_PROGMEM[CCSET][(CurrentColor*3)+1]));
		CCB[VARIATION][ColorToSave] =  pgm_read_word_near(&(osmCC_PROGMEM[CCSET][(CurrentColor*3)+2]));
		CCS[VARIATION][ColorToSave] =  CSHADE ;
		if (!shadeFlag)
		{
			//if(FirstPrintFlag) {PrintMenuAfterOne(); FirstPrintFlag = 0;}
			
			Serial.println();	
			#if defined(VISUAL)	 
				for (k = (CurrentColor*9); k < ((CurrentColor*9) + 9); k++)
				{// for k
					myChar =  pgm_read_byte_near(osmCC_flahs_names + k);
					Serial.print(myChar);
				}// rof k
				//Serial.println();
				Serial.print(F("/ CC#: ")); Serial.print(CurrentColor); Serial.print(F("   "));
				Serial.print(F(" Red:")); Serial.print((CCR[VARIATION][ColorToSave])); Serial.print(F(" // "));
				Serial.print(F(" Green:")); Serial.print((CCG[VARIATION][ColorToSave])); Serial.print(F(" // "));
				Serial.print(F(" Blue:")); Serial.print((CCB[VARIATION][ColorToSave])); Serial.print(F(" // "));
				Serial.print(F(" Shade:")); Serial.print(CSHADE); Serial.println(F(" // "));
			#endif
		}
		else
		{
			#if defined(VISUAL)
				Serial.print(F("        // Shade:")); 
				Serial.print(CSHADE); Serial.println(F(" // "));
			#endif
		}
		color = 0;
		ONCE_SETUP_COLOR = 0;
	}// fi ONCE_SETUP_COLOR

	
}// diov CCreturnAndSave


/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////










