

const PROGMEM  uint8_t MorphingPattern[9] =
{
	B11111111,
	B11110111,
	B11011101,
	B11010101,
	B10101010,
	B10001010,
	B10000010,
	B10000001,
	B10000000
};





byte xds=0;

/////////////////////////////////////////////////////////////////////////////////////////////
void MorphNonZero(byte xds)
{// void MorphAfterZero
	byte xdata = pgm_read_byte (&MorphingPattern[xds]);
	byte yss=0;
	while (yss<7 && ToBorNotToB)
	{// for yss
		if (xdata & (1<<yss))
		{
			osmPWMtimeless(CCR[VARIATION][color],CCG[VARIATION][color],CCB[VARIATION][color]);
			//PrintThis(0,0,1,0);// debug
		}
		else
		{
			osmPWMtimeless(CCR[VARIATION][color+1],CCG[VARIATION][color+1],CCB[VARIATION][color+1]);
			//PrintThis(0,1,0,0);// debug
		}
		yss++;
	}// rof yss
	//PrintThis(0,0,0,1);// debug
}// diov MorphAfterZero
/////////////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////////////////////
void MorphZero(byte xds)
{// void MorphAfterZero
	byte xdata = pgm_read_byte (&MorphingPattern[xds]);
	byte yss=0;
	while (yss<7 && ToBorNotToB)
	{// for yss
		if (xdata & (1<<yss))
		{
			osmPWMtimeless(CCR[VARIATION][color],CCG[VARIATION][color],CCB[VARIATION][color]);
			//PrintThis(0,0,1,0);// debug
		}
		else
		{
			osmPWMtimeless(CCR[VARIATION][0],CCG[VARIATION][0],CCB[VARIATION][0]);
			//PrintThis(0,1,0,0);// debug
		}
		yss++;
	}// rof yss
	//PrintThis(0,0,0,1);// debug
}// diov MorphAfterZero
/////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///// THIS IS A PRIME
/////////////////////////////////////////////////////////////////////////////////////////////
void PRIME_MORPH(int ColorTime, int BlankTime) //
{// void osm_Morphed
	
	int ThisTime;
	if (color == 0) { osmPWM(0,0,0,Val1[VARIATION]); }
	ColorTime = ColorTime * 1;
	if (color != ColorMaxCount[VARIATION])
	{// if 
		xds=0;
		while (xds<9 && ToBorNotToB)
		{// while xds
			ThisTime = ColorTime;
			while (ThisTime > 0 && ToBorNotToB)
			{ // while ThisTime
				MorphNonZero(xds);
				ThisTime--;
				mmaSensor(PMMAselect, PmmAxis, PAccelSensitivity);
			}// while ThisTime
			xds++;
			osmPWMSCCxyz(0,0,0, 0, BlankTime);
		}// elihw xds
	}// fi != ColorMaxCount[VARIATION]
	else
	{// else
		xds=0;
		while (xds<9 && ToBorNotToB)
		{// while xds
			ThisTime = ColorTime;
			while (ThisTime > 0 && ToBorNotToB)
			{ // while ThisTime
				MorphZero(xds);
				ThisTime--;
				mmaSensor(PMMAselect, PmmAxis, PAccelSensitivity);
			}// while ThisTime
			xds++;
			osmPWMSCCxyz(0,0,0, 0, BlankTime);
		}// elihw xds
	}// esle
	color++;


}// diov osm_Morphed
//////////////////////////////////////////////////////////////////////////////////////////////











/////////////////////////////////////////////////////////////////////////////////////////////
void MorphPulse(byte xds)
{// void MorphAfterZero
	byte xdata = pgm_read_byte (&MorphingPattern[xds]);
	byte yss=0;
	while (yss<7 && ToBorNotToB)
	{// for yss
		if (xdata & (1<<yss))
		{
			osmPWMtimeless(CCR[VARIATION][color],CCG[VARIATION][color],CCB[VARIATION][color]);
			//PrintThis(0,0,1,0);// debug
		}
		else
		{
			osmPWMtimeless(0,0,0);
			//PrintThis(0,1,0,0);// debug
		}
		yss++;
	}// rof yss
	//PrintThis(0,0,0,1);// debug
}// diov MorphAfterZero
/////////////////////////////////////////////////////////////////////////////////////////////



///// THIS IS A PRIME
/////////////////////////////////////////////////////////////////////////////////////////////
void PRIME_PULSE(int ColorTime, int BlankTime, boolean RandomYes, int RandomValue)
{// void osm_Morphed
	
	if (RandomYes)	{ randNumber = random(RandomValue);}
		
	debug(1);
	int ThisTime;
	    osmPWMSCC(255,255,255,0, 1);// Small White Flash
        osmPWMSCCxyz(CCR[VARIATION][color],CCG[VARIATION][color],CCB[VARIATION][color],CCS[VARIATION][color], ColorTime);
		xds=0;
		while (xds<9 && ToBorNotToB)
		{// while xds
			ThisTime = 2;
			while (ThisTime > 0 && ToBorNotToB)
			{ // while ThisTime
				MorphPulse(xds);
				ThisTime--;
			}// while ThisTime
			xds++;
			osmPWMSCCxyz(0,0,0, 0, 10);
		}// elihw xds
		
	 
		
		if (RandomYes)	
		{ osmPWMSCCxyz(0,0,0, 0, randNumber);}
			else
		{ osmPWMSCCxyz(0,0,0, 0, BlankTime); }
	debug(0);		
			
	color++;

}// diov osm_Morphed
//////////////////////////////////////////////////////////////////////////////////////////////













/////////////////////////////////////////////////////////////////////////////////////////////
void MorphBPM(byte xds)
{// void MorphAfterZero
	byte xdata = pgm_read_byte (&MorphingPattern[xds]);
	byte yss=0;
	while (yss<7 && ToBorNotToB)
	{// for yss
		if (xdata & (1<<yss))
		{
			osmPWMtimeless(CCR[VARIATION][color],CCG[VARIATION][color],CCB[VARIATION][color]);
			//PrintThis(0,0,1,0);// debug
		}
		else
		{
			osmPWMtimeless(0,0,0);
			//PrintThis(0,1,0,0);// debug
		}
		yss++;
	}// rof yss
	//PrintThis(0,0,0,1);// debug
}// diov MorphAfterZero
/////////////////////////////////////////////////////////////////////////////////////////////





///// THIS IS A PRIME
/////////////////////////////////////////////////////////////////////////////////////////////
void PRIME_HBBPM(int ColorTime, int BlankTime, int Valof1, int Valof2)
{// void osm_Morphed
	

	debug(1);
	int ThisTime;
	osmPWMSCCxyz(255,255,255,0, 2);// Small White Flash
	osmPWMSCCxyz(CCR[VARIATION][color],CCG[VARIATION][color],CCB[VARIATION][color],CCS[VARIATION][color], ColorTime);
	xds=0;
	while (xds<9 && ToBorNotToB)
	{// while xds
		ThisTime = 1;
		while (ThisTime > 0 && ToBorNotToB)
		{ // while ThisTime
			MorphBPM(xds);
			ThisTime--;
		}// while ThisTime
		xds++;
		osmPWMSCCxyz(0,0,0, 0, 5);
	}// elihw xds
	


	xds=0;
	while (xds<9 && ToBorNotToB)
	{// while xds
		ThisTime = 5;
		while (ThisTime > 0 && ToBorNotToB)
		{ // while ThisTime
			MorphBPM(xds);
			ThisTime--;
		}// while ThisTime
		xds++;
		osmPWMSCCxyz(0,0,0, 0, 10);
	}// elihw xds
	debug(0);

	osmPWMSCCxyz(0,0,0, 0, BlankTime); 

	color++;

}// diov osm_Morphed
//////////////////////////////////////////////////////////////////////////////////////////////
