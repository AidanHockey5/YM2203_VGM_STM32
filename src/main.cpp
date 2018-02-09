#include "LTC6903.h"
#include "YM2203.h"
#include "SdFat.h"

LTC6903 masterClock(11, 957, PA4);

SdFat SD;
File vgm;

int YM_Datapins[8] = {PA15, PB3, PB4, PB5, PB6, PB7, PB8, PB9};
const int YM_CS = PA2;
const int YM_RD = PA1;
const int YM_WR = PA0;
const int YM_A0 = PC15;
const int YM_IC = PC14; 
const int YM_IRQ = NULL;

YM2203 ym2203(YM_Datapins, YM_CS, YM_RD, YM_WR, YM_A0, YM_IRQ, YM_IC);
//SD card chip select = PB0
void setup() 
{
    // put your setup code here, to run once:
    masterClock.Set();
    pinMode(PC14, OUTPUT);
}

void loop() 
{
    // put your main code here, to run repeatedly:
    digitalWrite(PC14, HIGH);
    delay(150);
    digitalWrite(PC14, LOW);
    delay(150);
}