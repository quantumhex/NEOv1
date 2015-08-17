// MMAsensor.ino


volatile boolean ShakeX;
volatile boolean ShakeY;
volatile boolean ShakeZ;



void mmaSensor( byte MMAselectMMA, byte mmaAxisMMA, int SensitivityMMA)
{// void mmaSensor
	if (STATE == 1)// only available on Mode Play
	{// if STATE
		
		/////////////////////////////////////////////////////////////////////////////////////////////////
		if ((MMAselectMMA == 1) && (ToBorNotToB))// Tilt
		{// if Tilt
			volatile char Accel[3];
			accelCounter++;
			if (accelCounter>SensitivityMMA)
			{// if SenseY
				MMA7660.getAccel(&xAcc,&yAcc,&zAcc);

				
				Accel[0] = xAcc;
				Accel[1] = yAcc;
				Accel[2] = zAcc;
				
				if ((Accel[mmaAxisMMA])  > 1 && (ToBorNotToB))
				{// if Tilt
					if (VARIATION == 0) {;}
					else
					{VARIATION = 0; ToBorNotToB = 0;}
				}// fi Tilt
				
				if ((Accel[mmaAxisMMA])  < 1 && (ToBorNotToB))
				{// if Tilt
					if (VARIATION == 1) {;}
					else
					{VARIATION = 1; ToBorNotToB = 0;}
				}// fi Tilt
				
				xAcc = 0;// clear
				yAcc = 0;// clear
				zAcc = 0;// clear
				accelCounter=0;
			}// fi Sensey
		}// fi Tilt
		
		/////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////
		
		if ((MMAselectMMA == 2) && (ToBorNotToB))// Shake
		{// if Shake
			accelCounter++;
			if (accelCounter>(SensitivityMMA) && (ToBorNotToB))
			{// if accelCounter
				MMA7660.getRaw(&xAcc,&yAcc,&zAcc);
				if ((xAcc < 37) && (xAcc > 24) )   {ShakeX = 1;} else {ShakeX = 0;}
				if ((yAcc < 37) && (yAcc > 24) )   {ShakeY = 1;} else {ShakeY = 0;}
				if ((zAcc < 37) && (zAcc > 24) )   {ShakeZ = 1;} else {ShakeZ = 0;}
				accelCounter=0;
				if ( ShakeX || ShakeY || ShakeZ )
				{// if Shake
					if (VARIATION == 1) {;}
					else
					{VARIATION = 1; ToBorNotToB = 0;}
						
					ShakeX = 0;
					ShakeY = 0;
					ShakeZ = 0;
				}// fi Shake
				else
				{// else					
					VARIATION = 0;
					//if (VARIATION == 1) {ToBorNotToB = false;}
				}// else
			}// fi accelCounter
		}// fi Shake
		/////////////////////////////////////////////////////////////////////////////////////////////////

	}// fi STATE
}// diov mmaSensor




void mmaTilt( byte TiltAxis, byte SenseY)
{
	volatile char Accel[3];
	accelCounter++;
	if (accelCounter>SenseY)
	{// if SenseY
		MMA7660.getAccel(&xAcc,&yAcc,&zAcc);

		
		Accel[0] = xAcc;
		Accel[1] = yAcc;
		Accel[2] = zAcc;
		
		if (Accel[TiltAxis]  > 1) 
		{// if Tilt
			VARIATION = 0;
			if (VARIATION == 1) {ToBorNotToB = false;}
		}// fi Tilt 
			else 
		{// else
			VARIATION = 1;
			if (VARIATION == 0) {ToBorNotToB = false;}
		}// esle
		
		xAcc = 0;// clear
		yAcc = 0;// clear
		zAcc = 0;// clear
		accelCounter=0;
	}// fi Sensey
}


//boolean aBit0;
//boolean aBit1;
//boolean aBit2;
//boolean aBit3;
//boolean aBit4;
//boolean aBit5;
//boolean aBit6;
//boolean aBit7;



//void mmaTilt(void)
//{
//accelCounter++;
//if (accelCounter>20)
//{
//delay(100);
//MMA7660.tilt(&AccTilt);
//aBit7 = bitRead(AccTilt,7);
//aBit6 = bitRead(AccTilt,6);
//aBit5 = bitRead(AccTilt,5);
//aBit4 = bitRead(AccTilt,4);
//aBit3 = bitRead(AccTilt,3);
//aBit2 = bitRead(AccTilt,2);
//aBit1 = bitRead(AccTilt,1);
//aBit0 = bitRead(AccTilt,0);
//
//Serial.print(F(" : "));Serial.print(aBit7);
//Serial.print(F(" : "));Serial.print(aBit6);
//Serial.print(F(" : "));Serial.print(aBit5);
//Serial.print(F(" : "));Serial.print(aBit4);
//Serial.print(F(" : "));Serial.print(aBit3);
//Serial.print(F(" : "));Serial.print(aBit2);
//Serial.print(F(" : "));Serial.print(aBit1);
//Serial.print(F(" : "));Serial.println(aBit0);
//
//accelCounter=0;
//}
//
//}
