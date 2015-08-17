// pwms.ino

void BLINKPWM(byte red, byte green, byte blue, int time,byte BlinkTimes)
{ // void osmPWM
	while (BlinkTimes > 0 && ToBorNotToB)
	{ // while time
		osmPWM(red,green,blue,time);
		osmPWM(0,0,0,time);
		BlinkTimes--;
	}// elihw time
}// diov osmPWM


// this is the light engine
void osmPWM(byte red, byte green, byte blue, int time)
{ // void osmPWM
  time = time * 19;
  while (time > 0 && ToBorNotToB)
  { // while time
    analogWrite(5, blue); // blue
    analogWrite(6, green); // green
    analogWrite(9, red); // red
    time--;
  }// elihw time
}// diov osmPWM





// this is the light engine
void osmPWMtimeless(byte red, byte green, byte blue)
{ // void osmPWMtimeless
		analogWrite(5, blue); // blue
		analogWrite(6, green); // green
		analogWrite(9, red); // red
}// diov osmPWMtimeless



// THIS ROUTINE WILL TURN OFF THE LIGHT
void AnalogBlank(void)
{ // void blankPWM
	analogWrite(5, 0);
	analogWrite(6, 0);
	analogWrite(9, 0);
}// diov blankPWM






// this is the light engine
void osmPWMSCC(byte red, byte green, byte blue, byte shade, int time)
{ // void osmPWM
	
	time = time * 19;
	while (time > 0 && ToBorNotToB)
	{ // while time
		analogWrite(5, blue); // blue
		analogWrite(6, green); // green
		analogWrite(9, red); // red
		
		if (shade>0)
		{// if shade > 0
			ShaderFactor = 4;
			while (ShaderFactor>0 && ToBorNotToB)
			{// while shader 1
				AnalogBlank();
				ShaderFactor--;
				time--;
			}// elihw shader 1
			
			if (shade>1)
			{// if shade >1
				ShaderFactor = 4;
				while (ShaderFactor>0 && ToBorNotToB)
				{// while shader 2
					AnalogBlank();
					ShaderFactor--;
					time--;
				}// elihw shader 2
				
				if (shade>2)
				{// if shade >2
					ShaderFactor = 6;
					while (ShaderFactor>0 && ToBorNotToB)
					{// while shader 2
						AnalogBlank();
						ShaderFactor--;
						time--;
					}// elihw shader 2
				}// fi shade >2	
				
			}// fi shade >1
			
		}// fi shade > 0
		
		time--;
		
	}// elihw time
	
}// diov osmPWM




// this is the light engine
void osmPWMSCCxyz(byte red, byte green, byte blue, byte shade, int time)
{ // void osmPWM
	
	TTtime = time * 19;
	while ((TTtime > 0) && (ToBorNotToB) && (Armed) )
	{ // while time
		analogWrite(5, blue); // blue
		analogWrite(6, green); // green
		analogWrite(9, red); // red
		mmaSensor(PMMAselect, PmmAxis, PAccelSensitivity);
		if (shade>0)
		{// if shade > 0
			ShaderFactor = 4;
			while (ShaderFactor>0 && ToBorNotToB)
			{// while shader 1
				AnalogBlank();
				ShaderFactor--;
				TTtime--;
			}// elihw shader 1
			
			if (shade>1)
			{// if shade >1
				ShaderFactor = 4;
				while (ShaderFactor>0 && ToBorNotToB)
				{// while shader 2
					AnalogBlank();
					ShaderFactor--;
					TTtime--;
				}// elihw shader 2
				
				if (shade>2)
				{// if shade >2
					ShaderFactor = 6;
					while (ShaderFactor>0 && ToBorNotToB)
					{// while shader 2
						AnalogBlank();
						ShaderFactor--;
						TTtime--;
					}// elihw shader 2
				}// fi shade >2
				
			}// fi shade >1
			
		}// fi shade > 0
		
		TTtime--;
		
	}// elihw time
	
}// diov osmPWM





// this is the light engine
void osmPWM_Plane(byte red, byte green, byte blue, int time)
{ // void osmPWM
	time = time * 19;
	while (time > 0)
	{ // while time
		analogWrite(5, blue); // blue
		analogWrite(6, green); // green
		analogWrite(9, red); // red
		time--;
	}// elihw time
}// diov osmPWM




void osmPWMCC(byte CColorN, int Ctime)
{// void osmPWMCC

osmPWM(CCR[VARIATION][CColorN], CCG[VARIATION][CColorN], CCB[VARIATION][CColorN], Ctime);

}// diov osmPWMCC





// BLINKY FLASH A BOOLEAN OF RED, GREEN, BLUE (1 = ON, 0 = OFF)
void Blinky(boolean reddy, boolean greeny, boolean bluey, int delayly)
{
	  while (delayly > 0)
	  {
  digitalWrite(9, reddy); // 9 RED
  digitalWrite(6, greeny); // 6 GREEN
  digitalWrite(5, bluey); // 5 BLUE
  for (int vv = 180; vv > 0; vv--)
		{
		NOP;	
		}
   delayly--;
  }
}




// BLINKY FLASH A BOOLEAN OF RED, GREEN, BLUE (1 = ON, 0 = OFF)
void BlinkyInterrupt(boolean reddy, boolean greeny, boolean bluey)
{
	digitalWrite(9, reddy); // 9 RED
	digitalWrite(6, greeny); // 6 GREEN
	digitalWrite(5, bluey); // 5 BLUE
}


