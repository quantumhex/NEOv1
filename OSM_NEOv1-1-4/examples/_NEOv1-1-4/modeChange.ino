// modeChange



void JustOnce(void)
{// void JustOnce
	if (JUSTONCE)
	{// if JUSTONCE
	ToBorNotToB = true;	
	ONNS = true;
	SerialSendMode();  // Sends the current Mode via Serial TX
	JUSTONCE = 0;
	}// fi JUSTONCE
}// diov JustOnce


byte variationset;
byte MaxOffset;

void JustOnceModeSet(void)
{// void JustOnceColorChange
	if (JUSTONCE)
	{// if JUSTONCE
		CurrentMode = Mode;
		ModeToChange = Mode;
		ToBorNotToB = true;
		ONNS = true;
		STATE = 1;
		VARIATION = 0;
		SerialSendMode();  // Sends the current Mode via Serial TX
		
		noInterrupts();
		variationset = 0;
		while (variationset < 2)// these are 2 loops
		{// while variationset
			if (variationset == 0) {VariationOffset = 0;} else {VariationOffset = 18;}
			ColorMaxCount[variationset] = ModeSetSRAM[(ModeToChange-1)][VariationOffset] ;
			colorSet = 0;
			color = 0;
			CCSET = ModeSetSRAM[(ModeToChange-1)][(VariationOffset+colorSet+1)];
			//CCSET = 0;
			MaxOffset = ColorMaxCount[variationset];
			while (color < ColorMaxCount[variationset])
			{// while color
				CR = ModeSetSRAM[(ModeToChange-1)][(VariationOffset+colorSet+2)];
				CCR[variationset][color] =  pgm_read_word_near(&(osmCC_PROGMEM[CCSET][(CR*3)]));
				CCG[variationset][color] =  pgm_read_word_near(&(osmCC_PROGMEM[CCSET][(CR*3)+1]));
				CCB[variationset][color] =  pgm_read_word_near(&(osmCC_PROGMEM[CCSET][(CR*3)+2]));
				CCS[variationset][color] =  ModeSetSRAM[(ModeToChange-1)][(VariationOffset+colorSet+3)];
				colorSet = colorSet+2;
				color++;
			}// elihw color
			ColorMaxCount[variationset] = (MaxOffset - 1) ;// OFFSET
			variationset++;
		}// elihw variationset

		
		interrupts();
		colorSet = 0;
		JUSTONCE = 0;// CLEAR FLAG
	}// fi JUSTONCE
}// diov JustOnceColorChange






