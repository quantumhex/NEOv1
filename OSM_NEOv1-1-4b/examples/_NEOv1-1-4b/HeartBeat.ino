// HeartBeat.ino
//////////////////////////
//////////////////////////


void PRIME_HEARTBEAT(byte BeatColor)
{
	byte CCSET;
	int ColorSelection;
	float in, out;
	//debug(1);
	if (ONLYUNO)
	{
		eeCheck();
		ColorSelection = EEPROM.read((Mode*20)+2);
		eeCheck();
		if (VARIATION == 0) {VariationOffset = 0;} else {VariationOffset = 18;}
		CCSET = ModeSetSRAM[ModeToChange][(VariationOffset+2)];// Custom Color Pallette #2
		ONLYUNO=0;
	}
	//////////////////////// STEP 1
	//for (in = 0; in < 6.283; in = in + 0.001)
	in = 0;
	while ((in < 6.283) && (digitalRead (BUTTON) == HIGH) && (VARIATION == 0) )
	{// WHILE STEP 1
		in = in + 0.009;
		//out = sin(in) * 127.5 + 127.5;
		out = sin(in) * 127.5 + 63.75;
		
		if (BeatColor == 1)
		{
			analogWrite(9,out);
		}
		
		else if (BeatColor == 2)
		{
			analogWrite(6,out);
		}
		
		else if (BeatColor == 3)
		{
			analogWrite(5,out);
		}
		
		else
		{
			analogWrite(6,out);
		}
		
		//mmaTeleShake_Change_1to2(2);
		mmaSensor(MMAselect, mmAxis, AccelSensitivity);
	}// ELIHW STEP 1
	//////////////////////// STEP 1
    //debug(0);
	//////////////////////// STEP 2
	in = 0;
	while ((in < 6.283) && (digitalRead (BUTTON) == HIGH) && (VARIATION == 0)  )
	{// WHILE STEP 2
		in = in + 0.02;
		out = sin(in) * 127.5 + 127.5;
		analogWrite(5,out);
		//mmaTeleShake_Change_1to2(2);
		mmaSensor(MMAselect, mmAxis, AccelSensitivity);
	}// ELIHW STEP 2
	//////////////////////// STEP 2
	
}
