//  LIGHT DELTA


/////////////////////////////////////////////////////////////////////////////////////////////
void osm_MASTER_BUILDER
(volatile byte MMAselect,  volatile byte mmAxis,  int AccelSensitivity, 
 volatile byte PrimeA, volatile int ColorTimeA, volatile int BlankTimeA,  volatile int Val1A, volatile int Val2A, volatile boolean VPA,  
 volatile byte PrimeB, volatile int ColorTimeB, volatile int BlankTimeB,  volatile int Val1B, volatile int Val2B, volatile boolean VPB)
{
	
	
	if (JUSTONCE)
	{// if JUSTONCE	
		PMMAselect = MMAselect;
		PmmAxis = mmAxis;
		PAccelSensitivity = AccelSensitivity*10;
			
		PrimeType[0] = PrimeA;
		PrimeType[1] = PrimeB;
		ColorTime[0] = ColorTimeA;
		ColorTime[1] = ColorTimeB;
		BlankTime[0] = BlankTimeA;
		BlankTime[1] = BlankTimeB;
		Val1[0] = Val1A;
		Val1[1] = Val1B;
		Val2[0] = Val2A;
		Val2[1] = Val2B;
		Preview[0]= VPA;
		Preview[1]= VPB;
		
		AUTOCHANGE=UserBPM[(CurrentUserBundle*2)];
		BPM_Selector = UserBPM[((CurrentUserBundle*2)+1)];
		FloatResult = BPM_Bars(BPM_Selector,2);
		BPM_Factor = FloatResult;
		SetSelection(PMMAselect,PmmAxis,PrimeType[0],PrimeType[1]);
	}// fi JUSTONCE
	
	
	ToBorNotToB = 1;
	JustOnceModeSet();
	while ((STATE == 1)  && (GLOBALCHANGE) && (ToBorNotToB) )// Modes
	{// while STATE 1
		ToBorNotToB = 1;
		PRIMER(PrimeType[VARIATION]);
		PushYed();
	}// elihw STATE 1
	
	
	if (STATE == 2)
	{// IF STATE 2
		SetSelection(MMAselect,mmAxis,PrimeA,PrimeB);
	}// FI STATE 2
	
	ToBorNotToB = 1;
	while ( (STATE == 2) && (GLOBALCHANGE) )// Color Change
	{// state 2
		//PRIMER(PrimeType[VARIATION]);
		PRIMERCOLOR(PrimeType[VARIATION]);
		PushYcolors();
	}// state 2
	

}
//////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////
void SetSelection(volatile byte MMAselect,  volatile byte mmAxis, volatile byte PrimeA, volatile byte PrimeB)
{
	#if defined(VISUAL)
		Serial.println();Serial.println();
		
		PrintThis(0,0,85,1);//byte PrintSpace, byte PrintEqual, byte PrintAsterisch, boolean LineEnd);
		Serial.print(F("> Mode# "));
		Serial.print(Mode);
		
		if (STATE != 2)
		{// if STATE !=2
			Serial.print(F(" , ("));
			PrintAccel(MMAselect);// NO ACCELEROMTER / TILT / SHAKE
			if (MMAselect == 1) { PrintAxis(mmAxis);  Serial.print(F(" Axis")); }
			if (MMAselect>0)  { Serial.print(F(" ) , from: "));}	
			
			SetModeExtras(0,0,PrimeType[0]); // (byte LNstart, byte LNend, byte Message)
			Serial.print(F(" (")); Serial.print(ColorTime[0]);Serial.print(F(","));Serial.print(BlankTime[0]);Serial.print(F(")"));
			if (MMAselect>0)
			{
				Serial.print(F(" to ")); SetModeExtras(0,0,PrimeType[1]);
				Serial.print(F(" (")); Serial.print(ColorTime[1]);Serial.print(F(","));Serial.print(BlankTime[1]);Serial.print(F(")"));
				{Serial.println();}
					
			}
			else {Serial.println();}
			PrintThis(0,0,85,1);//byte PrintSpace, byte PrintEqual, byte PrintAsterisch, boolean LineEnd);	
		}// fi STATE !=2
		
		

		if (STATE == 2)
		{// IF STATE 2 
			Serial.print(F(" , EDIT COLORS OF PRIME "));
			if (VARIATION == 0)
			{// if VARIATION 0
				Serial.print(F("A / "));
				SetModeExtras(0,0,PrimeType[0]); // (byte LNstart, byte LNend, byte Message)
				Serial.print(F(" (")); Serial.print(ColorTime[0]);Serial.print(F(","));Serial.print(BlankTime[0]);Serial.print(F(")"));Serial.println();
			}// fi VARIATION 0
				if (VARIATION == 1)
			{// if VARIATION 1
				Serial.print(F("B / "));
				SetModeExtras(0,0,PrimeType[1]); // (byte LNstart, byte LNend, byte Message)
				Serial.print(F(" (")); Serial.print(ColorTime[1]);Serial.print(F(","));Serial.print(BlankTime[1]);Serial.print(F(")"));Serial.println();
			}// fi VARIATION 1
	
		}// FI STATE 2	    

    #endif
}// DIOV SETSELECTION




