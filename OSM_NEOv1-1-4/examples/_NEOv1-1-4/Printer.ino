
/// Serial Print messages takes a lot memory space...
/// ... this is were we save that space.




//////////////////////////////////////////////////////////////////////////////////////////////
void PrintThis(byte PrintSpace, byte PrintEqual, byte PrintAsterisch, boolean LineEnd)
{
	#if defined(VISUAL)
	
		while (PrintSpace > 0)
		{
			Serial.print(F(" "));
			PrintSpace--;
		}

		while (PrintEqual > 0)
		{
			Serial.print(F("="));
			PrintEqual--;
		}

		while (PrintAsterisch > 0)
		{
			Serial.print(F("*"));
			PrintAsterisch--;
		}
		
		if (LineEnd)
		{
			Serial.println();
		}
	
	#endif
}
//////////////////////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////////////////////
void PrintAccel(byte Message)

{// void PrintMessage
	
	#if defined(VISUAL)
	
	if (Message == 0)
	{
		Serial.print(F(" NO ACCELEROMETER ) , "));
	}
	
	if (Message == 1)
	{
		Serial.print(F(" TILT "));
	}
	
	if (Message == 2)
	{
		Serial.print(F(" SHAKE "));
	}		
					
	
	#endif
}// diov PrintMessage
//////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////
void PrintAxis(byte Message)

{// void PrintMessage
	
	#if defined(VISUAL)

	if (Message == 0)
	{
		Serial.print(F("X"));
	}
	
	if (Message == 1)
	{
		Serial.print(F("Y"));
	}
	
	if (Message == 2)
	{
		Serial.print(F("Z"));
	}
	
	
	#endif
}// diov PrintMessage
//////////////////////////////////////////////////////////////////////////////////////////////






//
////////////////////////////////////////////////////////////////////////////////////////////////
//void PrintMessage(byte PrintSpace, byte PrintEqual, byte PrintAsterisch, byte Message)
//
//{// void PrintMessage
	//
	//#if defined(VISUAL)
	//
		//Serial.println();
		//PrintThis(0,PrintEqual,0,0);PrintThis(1,0,0,0);
//
	//
		//if (Message == 8)
		//{
			//Serial.print(F("SELECT YOUR TRACE COLOR"));
		//}
		//
		//if (Message == 9)
		//{
			//Serial.print(F("SELECT UP TO 9 COLORS (NO SHADES)"));
		//}
   //
	   //PrintThis(1,0,0,0);
	   //PrintThis(0,PrintEqual,0,1);
	   //
    //#endif
//}// diov PrintMessage
////////////////////////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////////////////////
void SetModeExtras(byte LNstart, byte LNend, byte Message)
{
	
	#if defined(VISUAL)
	PrintThis(0,0,0,LNstart);
	// (byte PrintSpace, byte PrintEqual, byte PrintAsterisch, boolean LineEnd)
    #endif
	
	if (Message == 1)
	{
		#if defined(VISUAL)
		Serial.print(F("STROBE"));
	    #endif
	}
	
	if (Message == 2)
	{
		#if defined(VISUAL)
		Serial.print(F("TRACE"));
		#endif
	}
	
	
	if (Message == 3)
	{
		#if defined(VISUAL)
		Serial.print(F("MORPH"));
		#endif
	}
	
	if (Message == 4)
	{
		#if defined(VISUAL)
		Serial.print(F("PULSE"));
		#endif
	}
	
	if (Message == 5)
	{
		#if defined(VISUAL)
		Serial.print(F("TRIPLE_RAINBOW"));
		#endif
	}
	
	if (Message == 6)
	{
		#if defined(VISUAL)
		Serial.print(F("HEART_BEAT_BPM"));
		#endif
	}
	
	if (Message == 7)
	{
		#if defined(VISUAL)
		Serial.print(F("SANDBOX_1"));
		#endif
	}

	if (Message == 8)
	{
		#if defined(VISUAL)
		Serial.print(F("SANDBOX_2"));
		#endif
	}
	
	if (Message == 9)
	{
		#if defined(VISUAL)
		Serial.print(F("SANDBOX_3"));
		#endif
	}

	if (Message == 10)
	{
		#if defined(VISUAL)
		Serial.print(F("SANDBOX_4"));
		#endif
	}
	
	if (Message == 11)
	{
		#if defined(VISUAL)
		Serial.print(F("SANDBOX_5"));
		#endif
	}
	
	if (Message == 12)
	{
		#if defined(VISUAL)
		Serial.print(F("SANDBOX_6"));
		#endif
	}
	

	
	if (Message == 100)
	{
	
	Serial.print(F("> Bundle# "));
	Serial.println(CurrentUserBundle+1);
	}


	
	#if defined(VISUAL)
	PrintThis(0,0,0,LNend);
	#endif
}
//////////////////////////////////////////////////////////////////////////////////////////////




void OOOgood(void)

{
	#if defined(VISUAL)
		if (OgooD)
		{
			SetModeExtras(1,1,100);
			OgooD = 0;
		}
	#endif
}







void PrintMenuAfterOne(void)
{// void PrintMenuAfterOne

#if defined(VISUAL)
	
	PrintThis(0,85,0,1);
	Serial.println();
	PrintThis(5,0,70,1);
	PrintThis(31,0,0,0); Serial.println(F("www.OSM.codes/NEO"));
	PrintThis(5,0,70,1);

	PrintThis(5,0,1,0);
	if (ColorToSave > 7)
	{
	Serial.print(F(" SAVE  "));
	}
	
	else
	{
		Serial.print(F(" CLICK "));
	}
	
	Serial.print(F("|"));PrintThis(0,12,0,0);Serial.print(F(" SAVE"));PrintThis(1,12,0,0);Serial.print(F("|"));PrintThis(0,10,0,0);Serial.print(F(" DELETE"));PrintThis(1,11,0,0);Serial.println(F("|"));
	
	PrintThis(5,0,0,0); Serial.print(F("|")); PrintThis(0,0,7,0); Serial.print(F("|")); PrintThis(0,0,30,0); Serial.print(F("|")); PrintThis(0,0,29,0); Serial.println(F("|"));
	PrintThis(5,0,0,0); Serial.print(F("|"));

#endif

}// diov PrintMenuAfterOne





void PrintTopFormula(void)
{
	#if defined(VISUAL)
	
		Serial.println();Serial.println();

    #endif
}






