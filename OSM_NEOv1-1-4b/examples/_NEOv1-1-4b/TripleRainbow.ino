// Rainbow color changing RGB leds example
// I am using common cathode RGB leds
//int PIN_RED = 9;
//int PIN_GREEN = 6;
//int PIN_BLUE = 5;
int counter = 0;

// Number of colors used for animating, higher = smoother and slower animation)
//int numColors; // default 32


/////////// THIS IS A PRIME //////////////////////
//////////////////////////////////////////////////
void PRIME_TRIPLERAINBOW( int RainbowTime, int RainBlankTime, byte numRainbows, int numColors)
{
	

	// This part takes care of displaying the
	// color changing in reverse by counting backwards if counter
	// is above the number of available colors
	float colorNumber = counter > numColors ? counter - numColors: counter;
	
	// Play with the saturation and brightness values
	// to see what they do
	float saturation = 1; // Between 0 and 1 (0 = gray, 1 = full color)
	float brightness = 1; // Between 0 and 1 (0 = dark, 1 is full brightness) .05
	float hue = (colorNumber / float(numColors)) * 360; // Number between 0 and 360
	long color = HSBtoRGB(hue, saturation, brightness);
	
	// Get the red, blue and green parts from generated color
	int red = color >> 16 & 255;
	int green = color >> 8 & 255;
	int blue = color & 255;


	if (numRainbows == 1 && ToBorNotToB)
	{
		osmPWMSCCxyz(red,green,blue, 0, RainbowTime);
		osmPWMSCCxyz(0,0,0,0, RainBlankTime);
	}

	if (numRainbows == 2 && ToBorNotToB)
	{
		osmPWMSCCxyz(red,green,blue, 0, RainbowTime);
		osmPWMSCCxyz(0,0,0,0, RainBlankTime);
		osmPWMSCCxyz(blue,red,green, 0, RainbowTime);
		osmPWMSCCxyz(0,0,0,0, RainBlankTime);
	}
	
	if (numRainbows == 3 && ToBorNotToB)
	{
		osmPWMSCCxyz(red,green,blue, 0, RainbowTime);
		osmPWMSCCxyz(0,0,0,0, RainBlankTime);
		osmPWMSCCxyz(blue,red,green, 0, RainbowTime);
		osmPWMSCCxyz(0,0,0,0, RainBlankTime);
		osmPWMSCCxyz(green,blue,red, 0, RainbowTime);
		osmPWMSCCxyz(0,0,0,0, RainBlankTime);
	}

	///////////////// UNCOMMENT THIS TO GET ALL TE VALUES OF THIS MORPH VIA SERIAL
	///////////////// THIS IS GREAT IF YOU WANT TO MAKE A PERFECT COLOR PALETTE

	//Serial.print("   ");Serial.print(red);
	//Serial.print(" , ");Serial.print(green);
	//Serial.print(" , ");Serial.print(blue);
	//Serial.print(",   //  Color #");Serial.println((counter+1));
	//////////////////////////////////////////////////////////////////////////////
	
	
	// Counter can never be greater then 2 times the number of available colors
	// the colorNumber = line above takes care of counting backwards (nicely looping animation)
	// when counter is larger then the number of available colors
	counter = (counter + 1) % (numColors * 2);
	
	// If you uncomment this line the color changing starts from the
	// beginning when it reaches the end (animation only plays forward)
	// counter = (counter + 1) % (numColors);
}












long HSBtoRGB(float _hue, float _sat, float _brightness)

{// long HSBtoRGB
	float red = 0.0;
	float green = 0.0;
	float blue = 0.0;
	
	if (_sat == 0.0) {
		red = _brightness;
		green = _brightness;
		blue = _brightness;
		} else {
		if (_hue == 360.0) {
			_hue = 0;
		}

		int slice = _hue / 60.0;
		float hue_frac = (_hue / 60.0) - slice;

		float aa = _brightness * (1.0 - _sat);
		float bb = _brightness * (1.0 - _sat * hue_frac);
		float cc = _brightness * (1.0 - _sat * (1.0 - hue_frac));
		
		switch(slice) {
			case 0:
			red = _brightness;
			green = cc;
			blue = aa;
			break;
			case 1:
			red = bb;
			green = _brightness;
			blue = aa;
			break;
			case 2:
			red = aa;
			green = _brightness;
			blue = cc;
			break;
			case 3:
			red = aa;
			green = bb;
			blue = _brightness;
			break;
			case 4:
			red = cc;
			green = aa;
			blue = _brightness;
			break;
			case 5:
			red = _brightness;
			green = aa;
			blue = bb;
			break;
			default:
			red = 0.0;
			green = 0.0;
			blue = 0.0;
			break;
		}
	}

	long ired = red * 255.0;
	long igreen = green * 255.0;
	long iblue = blue * 255.0;
	
	return long((ired << 16) | (igreen << 8) | (iblue));
}// gnol HSBtoRGB
