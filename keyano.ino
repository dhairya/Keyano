/*
Keyano
Git: dhairya
*/
#include "pitches.h"

#define LED 13
#define CLK 6
#define DAT 10

// if I put the keyboard map in here then keys[scan code] would return 
// the ascii value of the scan code.

unsigned char keys[128] =
{
};

int key=0;
int i =0;


void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(CLK, INPUT);
  pinMode(DAT, INPUT);
  digitalWrite(CLK, HIGH);
  digitalWrite(DAT, HIGH);
  delayMicroseconds(50);
  Serial.begin(9600);
  
}

void loop()
{
  byte b = readkey(); 
  if (b == 0xF0)
  {
    // key released
    b = readkey();
  }
  else
  {
    getTone(b);
  }
}

int getTone(byte b)
{
 switch(b) {
 
 case 14:
  tone(2, NOTE_CS4,300);
  break;
  
 case 22:
  tone(2, NOTE_DS2,300);
  break;

 case 38:
  tone(2, NOTE_FS2,300); 
  break;

 case 37:
  tone(2, NOTE_GS2,300);
  break;

 case 46:
  tone(2, NOTE_AS2,300); 
  break;

 case 61:
  tone(2, NOTE_CS3,300); 
  break;

 case 62:
  tone(2, NOTE_DS3,300); 
  break;

 case 69:
  tone(2, NOTE_FS3,300); 
  break;

 case 78:
  tone(2, NOTE_GS3,300); 
  break;

 case 85:
  tone(2, NOTE_AS3,300);
  break;
  
 case 13:
  tone(2, NOTE_C2,300);
  break;
  
 case 21:
  tone(2, NOTE_D2,300);
  break;

 case 29:
  tone(2, NOTE_E2,300); 
  break;

 case 36:
  tone(2, NOTE_F2,300);
  break;

 case 45:
  tone(2, NOTE_G2,300); 
  break;

 case 44:
  tone(2, NOTE_A2,300); 
  break;

 case 53:
  tone(2, NOTE_B2,300); 
  break;

 case 60:
  tone(2, NOTE_C3,300); 
  break;

 case 67:
  tone(2, NOTE_D3,300); 
  break;

 case 68:
  tone(2, NOTE_E3,300);
  break;

 case 77:
  tone(2, NOTE_F3,300);
  break;
  
 case 84:
  tone(2, NOTE_G3,300);
  break;

 case 91:
  tone(2, NOTE_A3,300); 
  break;

 case 93:
  tone(2, NOTE_B3,300);
  break;

 case 88:
  tone(2, NOTE_CS4,300); 
  break;

 case 28:
  tone(2, NOTE_DS4,300); 
  break;

 case 35:
  tone(2, NOTE_FS4,300); 
  break;

 case 43:
  tone(2, NOTE_GS4,300); 
  break;

 case 52:
  tone(2, NOTE_AS4,300); 
  break;

 case 59:
  tone(2, NOTE_CS4,300);
  break;
  
 case 66:
  tone(2, NOTE_DS4,300);
  break;
  
 case 76:
  tone(2, NOTE_FS4,300);
  break;

 case 82:
  tone(2, NOTE_GS4,300); 
  break;

 case 90:
  tone(2, NOTE_AS4,300);
  break;

 case 18:
  tone(2, NOTE_C4,300); 
  break;

 case 26:
  tone(2, NOTE_D4,300); 
  break;

 case 34:
  tone(2, NOTE_E4,300); 
  break;

 case 33:
  tone(2, NOTE_F4,300); 
  break;

 case 42:
  tone(2, NOTE_G4,300); 
  break;

 case 50:
  tone(2, NOTE_A4,300);
  break;

 case 49:
  tone(2, NOTE_B4,300); 
  break;

 case 58:
  tone(2, NOTE_CS5,300);
  break;

 case 65:
  tone(2, NOTE_D5,300); 
  break;

 case 73:
  tone(2, NOTE_E5,300); 
  break;

 case 74:
  tone(2, NOTE_F5,300); 
  break;

 case 89:
  tone(2, NOTE_G5,300); 
  break;
  
 default:
   break;
 }
}


byte readkey()
{
  byte _start = 0;
  byte buf = 0;
  byte _parity = 0;
  byte _stop = 0;
  
  waitClockLow();
    
  _start = digitalRead(DAT);

  if (_start == 0)
  {
    waitClockLow();
    for (byte c=0; c<8; c++)
    {
      buf = buf | (digitalRead(DAT) << c);
      waitClockLow();
    }
  
    _parity = digitalRead(DAT);
    waitClockLow();
  
    _stop = digitalRead(DAT);
  }
  return buf;
}

void waitClockLow()
{
  if (digitalRead(CLK) == LOW)
    while (digitalRead(CLK) == LOW)
    {
    }
  while (digitalRead(CLK) == HIGH)
  {
  }
}
