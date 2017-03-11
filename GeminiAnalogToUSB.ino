/*
 * GeminiAnalogToUSB
 *
 * Created: 10/3/2017 
 * Author: HyDz
 * USB Midified Gemini DJ-M1 for Traktor
 */ 

#include "MIDIUSB.h" // Lib For Due recognized as midi usb controller

/*
Declare analog input
*/

int CrossFad = 1;
int valCrossFad =0;
int mappedvalCrossFad = 0;
int lastCrossFad= 0;


int VolFadL = 2;
int valVolFadL =0;
int mappedvalVolFadL = 0;
int lastVolFadL= 0;

int VolFadR = 3;
int valVolFadR =0;
int mappedvalVolFadR = 0;
int lastVolFadR= 0;


int HiPotL = 4;
int valHiPotL =0;
int mappedvalHiPotL = 0;
int lastHiPotL= 0;

int MidPotL = 5;
int valMidPotL =0;
int mappedvalMidPotL = 0;
int lastMidPotL= 0;

int BassPotL = 6;
int valBassPotL =0;
int mappedvalBassPotL = 0;
int lastBassPotL= 0;


int HiPotR = 7;
int valHiPotR =0;
int mappedvalHiPotR = 0;
int lastHiPotR= 0;

int MidPotR = 8;
int valMidPotR =0;
int mappedvalMidPotR = 0;
int lastMidPotR= 0;

int BassPotR = 9;
int valBassPotR =0;
int mappedvalBassPotR = 0;
int lastBassPotR= 0;

int FilterL = 10;
int valFilterL =0;
int mappedvalFilterL = 0;
int lastFilterL= 0;

int FilterR = 11;
int valFilterR =0;
int mappedvalFilterR = 0;
int lastFilterR= 0;

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}


void setup() {
  Serial.begin(115200);

}

void loop() {
  
  valCrossFad = analogRead(CrossFad); // Read Analog Input
  mappedvalCrossFad = map(valCrossFad, 0, 1023, 0, 127); // Map readvalue from 0 to 127
  if (lastCrossFad != mappedvalCrossFad){ // Only send Midi CC if changed is detected use (abs(lastCrossFad - mappedvalCrossFad))>=1) for more smooth
  controlChange(0, 30, mappedvalCrossFad); // Send CC
  MidiUSB.flush(); // Be sure CC is Send
  lastCrossFad = mappedvalCrossFad;
  }
  
  valVolFadL = analogRead(VolFadL); // Read Analog Input
  mappedvalVolFadL = map(valVolFadL, 0, 1023, 0, 127); // Map readvalue from 0 to 127
  if (lastVolFadL != mappedvalVolFadL){ // Only send Midi CC if changed is detected
  controlChange(0, 31, mappedvalVolFadL); // Send CC
  MidiUSB.flush(); // Be sure CC is Send 
  lastVolFadL = mappedvalVolFadL;
  }
  
  valVolFadR = analogRead(VolFadR); // Read Analog Input
  mappedvalVolFadR = map(valVolFadR, 0, 1023, 0, 127); // Map readvalue from 0 to 127
  if (lastVolFadR != mappedvalVolFadR){ // Only send Midi CC if changed is detected
  controlChange(0, 32, mappedvalVolFadR); // Send CC
  MidiUSB.flush(); // Be sure CC is Send 
  lastVolFadR = mappedvalVolFadR;
  }

  

  valHiPotL = analogRead(HiPotL); // Read Analog Input
  mappedvalHiPotL = map(valHiPotL, 0, 1023, 0, 127); // Map readvalue from 0 to 127
  if (lastHiPotL != mappedvalHiPotL){ // Only send Midi CC if changed is detected
  controlChange(0, 33, mappedvalHiPotL); // Send CC
  MidiUSB.flush(); // Be sure CC is Send 
  lastHiPotL = mappedvalHiPotL;
  }
  
  valMidPotL = analogRead(MidPotL); // Read Analog Input
  mappedvalMidPotL = map(valMidPotL, 0, 1023, 0, 127); // Map readvalue from 0 to 127
  if (lastMidPotL != mappedvalMidPotL){ // Only send Midi CC if changed is detected
  controlChange(0, 34, mappedvalMidPotL); // Send CC
  MidiUSB.flush(); // Be sure CC is Send 
  lastMidPotL = mappedvalMidPotL;
  }

  valBassPotL = analogRead(BassPotL); // Read Analog Input
  mappedvalBassPotL = map(valBassPotL, 0, 1023, 0, 127); // Map readvalue from 0 to 127
  if (lastBassPotL != mappedvalBassPotL){ // Only send Midi CC if changed is detected
  controlChange(0, 35, mappedvalBassPotL); // Send CC
  MidiUSB.flush(); // Be sure CC is Send 
  lastBassPotL = mappedvalBassPotL;
  }

   valHiPotR = analogRead(HiPotR); // Read Analog Input
  mappedvalHiPotR = map(valHiPotR, 0, 1023, 0, 127); // Map readvalue from 0 to 127
  if (lastHiPotR != mappedvalHiPotR){ // Only send Midi CC if changed is detected
  controlChange(0, 36, mappedvalHiPotR); // Send CC
  MidiUSB.flush(); // Be sure CC is Send 
  lastHiPotR = mappedvalHiPotR;
  }
  
  valMidPotR = analogRead(MidPotR); // Read Analog Input
  mappedvalMidPotR = map(valMidPotR, 0, 1023, 0, 127); // Map readvalue from 0 to 127
  if (lastMidPotR != mappedvalMidPotR){ // Only send Midi CC if changed is detected
  controlChange(0, 37, mappedvalMidPotR); // Send CC
  MidiUSB.flush(); // Be sure CC is Send 
  lastMidPotR = mappedvalMidPotR;
  }

  valBassPotR = analogRead(BassPotR); // Read Analog Input
  mappedvalBassPotR = map(valBassPotR, 0, 1023, 0, 127); // Map readvalue from 0 to 127
  if (lastBassPotR != mappedvalBassPotR){ // Only send Midi CC if changed is detected
  controlChange(0, 38, mappedvalBassPotR); // Send CC
  MidiUSB.flush(); // Be sure CC is Send 
  lastBassPotR = mappedvalBassPotR;
  }

  valFilterL = analogRead(FilterL); // Read Analog Input
  mappedvalFilterL = map(valFilterL, 0, 1023, 0, 127); // Map readvalue from 0 to 127
  if (lastFilterL != mappedvalFilterL){ // Only send Midi CC if changed is detected
  controlChange(0, 39, mappedvalFilterL); // Send CC
  MidiUSB.flush(); // Be sure CC is Send 
  lastFilterL = mappedvalFilterL;
  }
  
  valFilterR = analogRead(FilterR); // Read Analog Input
  mappedvalFilterR = map(valFilterR, 0, 1023, 0, 127); // Map readvalue from 0 to 127
  if (lastFilterR != mappedvalFilterR){ // Only send Midi CC if changed is detected
  controlChange(0, 40, mappedvalFilterR); // Send CC
  MidiUSB.flush(); // Be sure CC is Send 
  lastFilterR = mappedvalFilterR;
  }

}
