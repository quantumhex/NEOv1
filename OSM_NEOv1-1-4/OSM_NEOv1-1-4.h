/*
 * MMA7660.h - Interface a MMA7660 accelerometer to an AVR via i2c
 * Version 0.1 - http://www.timzaman.com/
 * Copyright (c) 2011 Tim Zaman
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

// EXTRA MODIFICATIONS (SOME DELETED FOR DEV VERSION)
// Quantum Hex LLC / Ramiro Montes De Oca / 2015
// Creative Commons / Attribution 2.5 Generic (CC BY 2.5)


#include "Arduino.h"



#ifndef OSM_NEO_h_v1-1-4
#define OSM_NEO_h_v1-1-4

class MMA
{
  public:
    MMA();
    void init();
	void standby();
    void getValues(int *x,int *y,int *z);
	void getAccel(int *xAcc,int *yAcc,int *zAcc);
	void getRaw(int *xAcc,int *yAcc,int *zAcc);
	void tilt(byte *AccTilt);

private:
	void MMA7660_I2C_SEND(unsigned char REG_ADDRESS, unsigned  char DATA);
};

extern MMA MMA7660;

#endif // SM_MMA7660_h
