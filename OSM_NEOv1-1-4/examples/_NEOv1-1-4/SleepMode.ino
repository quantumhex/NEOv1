



void Mode_00(void)// Blank Sleep
{//////////// MODE 00
	JUSTONCE = 1;
	STATE = 1;
	while (digitalRead (BUTTON) == LOW)
	{// debounce
		osmPWM_Plane(0, 0, 0, 100);
	}// debounce
	
	//osmPWM_Plane(0, 128, 0, 10);
	
	eeCheck();EEPROM.write(5,1);eeCheck();// went to sleep
	
	#if defined(VISUAL)
	Serial.println();
	Serial.println(F("IDLE..."));
	#endif

	osmPWM_Plane(0, 0, 0, 10);


	
	/////////////////////////////////////////////////////////////////////////
	
	//UserCmodes[CurrentUserBundle][CurrentUserMode];
	
	eeCheck();
	EEPROM.write(2,CurrentUserBundle);eeCheck();
	EEPROM.write(3,1);eeCheck();
	 


	long CountDownSleep = 1800;// seconds
	while ( (CountDownSleep > 0) && (digitalRead (BUTTON) == HIGH) )
	{
		CountDownSleep--;
		osmPWM_Plane(0, 0, 0, 10);
	}

	
	Serial.println(F("... SLEEP~"));
	if (digitalRead (BUTTON) == LOW)
	{
		goto OutOfSleep;
	}


	//// Watchdog Reset	////////////
	MMA7660.standby();
	digitalWrite(LDO, LOW); // Power LDO off
	delay(30);
	
	wdt_enable(WDTO_15MS);
	while(1)
	{
		;
	}
	/////////////////////////////////
	
	/////////////////////////////////////////////////////////////////////////
	// THE PROGRAM CONTINUES FROM HERE AFTER WAKING UP
	
	
	OutOfSleep:
	
	delay(30);
	
	#if defined(VISUAL)
	Serial.println();
	Serial.println(F("... wakey wakey!"));
	#endif

	
	//////////////////////////////////////////////////////
	delay(4000);
	//MMA7660.init();
	// check zflip here
	zAcc = 0;
	delay(40);
	MMA7660.getRaw(&xAcc,&yAcc,&zAcc);
	Serial.print(F("  Z: "));Serial.println(zAcc);
	if (zAcc > 37)
	{
		Zflipped = 1;
		zAcc = 0;
		// check zflip here
	}
	//////////////////////////////////////////////////////
	
	Zflip();
	ZNflip();
	
	////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////

	noInterrupts();	// disable interrupts

	if (AllYourBaseAreBelongToUs)// full blast factory reset
	{// AllYourBaseAreBelongToUs
		// reset here
		eepromWrite(0,0);
		eeCheck();
		eepromWriteFactory();
		eepromLoad();
		BLINKPWM(150,150,150 ,300,10);
		AllYourBaseAreBelongToUs = 0;
	}// AllYourBaseAreBelongToUs

	////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////

	CurrentOffCounter = 0;
	BPM_Counter=0;
	MaxUserModes = UserCmodes[CurrentUserBundle][0];
	CurrentUserMode = 1;
	Mode = UserCmodes[CurrentUserBundle][CurrentUserMode]; 
	eeCheck();EEPROM.write(5,0);eeCheck();// did not went to sleep
	
	ToBorNotToB = 1;
	osmPWM_Plane(0, 0, 0, 5);
	Zflipped = 0;
	OFF_MODE = 0;
	STATE = 1;
	Click = 0;
	Int0count = 0;

	interrupts(); // enable interrupts
	
}// MODE 00
/////////////////////////////////////////////








void Zflip(void)
{// void Zflip
	
	if (Zflipped)
	{
		CurrentUserBundle=0;// thank you Omar! (moved this line here)
	}
		
	while ((digitalRead (BUTTON) == LOW)  && (Zflipped))
	{// while Zflipped
		
		
		OgooD = 1;
		while ((CurrentUserBundle == 0) && (digitalRead (BUTTON) == LOW)) // WHITE
		{
			OOOgood();
			BLINKPWM(10,10,10 ,100,2);
		}
		
		OgooD = 1;
		while ((CurrentUserBundle == 1) && (digitalRead (BUTTON) == LOW)) // RED
		{
			OOOgood();
			BLINKPWM(20,0,0 ,100,2);
		}
		
		OgooD = 1;
		while ((CurrentUserBundle == 2) && (digitalRead (BUTTON) == LOW)) // GREEN
		{
			OOOgood();
			BLINKPWM(0,20,0 ,100,2);
		}
		
		OgooD = 1;
		while ((CurrentUserBundle == 3) && (digitalRead (BUTTON) == LOW)) // BLUE
		{
			OOOgood();
			BLINKPWM(0,0,20 ,100,2);
		}
		
		OgooD = 1;
		while ((CurrentUserBundle == 4) && (digitalRead (BUTTON) == LOW)) // YELLOW
		{
			OOOgood();
			BLINKPWM(15,15,0 ,100,2);
		}
		
	}// elihw Zflipped
}// vdiov Zflip





void ZNflip(void)
{// void ZNflip
	while ((digitalRead (BUTTON) == LOW)  && (!Zflipped))
	{// while Zflipped
		
		
		OgooD = 1;
		while ((CurrentOffCounter == 0) && (digitalRead (BUTTON) == LOW)) // RED 1
		{
			AllYourBaseAreBelongToUs = 0;
			BLINKPWM(3,0,0 ,50,2);
		}
		
		OgooD = 1;
		while ((CurrentOffCounter == 1) && (digitalRead (BUTTON) == LOW)) // RED 2
		{
			BLINKPWM(15,0,0 ,50,2);
		}
		
		OgooD = 1;
		while ((CurrentOffCounter == 2) && (digitalRead (BUTTON) == LOW)) // YELLOW
		{
			BLINKPWM(15,15,0 ,50,2);
		}
		
		OgooD = 1;
		while ((CurrentOffCounter == 3) && (digitalRead (BUTTON) == LOW)) // WHITE ( RESET )
		{
			BLINKPWM(30,30,30 ,50,2);
			AllYourBaseAreBelongToUs = 1;
		}
		
		OgooD = 1;
		while ((CurrentOffCounter == 4) && (digitalRead (BUTTON) == LOW)) // WHITE ( RESET )
		{
			BLINKPWM(70,70,70 ,50,2);
			AllYourBaseAreBelongToUs = 1;
		}
		
	}// elihw Zflipped
}// diov ZNflip



