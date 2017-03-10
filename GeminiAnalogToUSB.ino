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



int VolFadL = 2;
int valVolFadL =0;
int mappedvalVolFadL = 0;

int VolFadR = 3;
int valVolFadR =0;
int mappedvalVolFadR = 0;



int HiPotL = 4;
int valHiPotL =0;
int mappedvalHiPotL = 0;

int MidPotL = 5;
int valMidPotL =0;
int mappedvalMidPotL = 0;

int BassPotL = 6;
int valBassPotL =0;
int mappedvalBassPotL = 0;



int HiPotR = 7;
int valHiPotR =0;
int mappedvalHiPotR = 0;

int MidPotR = 8;
int valMidPotR =0;
int mappedvalMidPotR = 0;

int BassPotR = 9;
int valBassPotR =0;
int mappedvalBassPotR = 0;


int FilterL = 10;
int valFilterL =0;
int mappedvalFilterL = 0;

int FilterR = 11;
int valFilterR =0;
int mappedvalFilterR = 0;


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
  // put your setup code here, to run once:

}

void loop() {
  
  valCrossFad = analogRead(CrossFad); // Read Analog Input
  mappedvalCrossFad = map(valCrossFad, 0, 1023, 0, 127); // Map readvalue from 0 to 127
  controlChange(0, 30, mappedvalCrossFad); // Send CC
  MidiUSB.flush(); // Be sure CC is Send

  valVolFadL = analogRead(VolFadL); // Read Analog Input
  mappedvalVolFadL = map(valVolFadL, 0, 1023, 0, 127); // Map readvalue from 0 to 127
  controlChange(0, 31, mappedvalVolFadL); // Send CC
  MidiUSB.flush(); // Be sure CC is Send 

  valVolFadR = analogRead(VolFadR); // Read Analog Input
  mappedvalVolFadR = map(valVolFadR, 0, 1023, 0, 127); // Map readvalue from 0 to 127
  controlChange(0, 32, mappedvalVolFadR); // Send CC
  MidiUSB.flush(); // Be sure CC is Send 

  valHiPotL = analogRead(HiPotL); // Read Analog Input
  mappedvalHiPotL = map(valHiPotL, 0, 1023, 0, 127); // Map readvalue from 0 to 127
  controlChange(0, 33, mappedvalHiPotL); // Send CC
  MidiUSB.flush(); // Be sure CC is Send 

  valMidPotL = analogRead(MidPotL); // Read Analog Input
  mappedvalMidPotL = map(valMidPotL, 0, 1023, 0, 127); // Map readvalue from 0 to 127
  controlChange(0, 34, mappedvalMidPotL); // Send CC
  MidiUSB.flush(); // Be sure CC is Send 

  valBassPotL = analogRead(BassPotL); // Read Analog Input
  mappedvalBassPotL = map(valBassPotL, 0, 1023, 0, 127); // Map readvalue from 0 to 127
  controlChange(0, 35, mappedvalBassPotL); // Send CC
  MidiUSB.flush(); // Be sure CC is Send 

  valHiPotR = analogRead(HiPotR); // Read Analog Input
  mappedvalHiPotR = map(valHiPotR, 0, 1023, 0, 127); // Map readvalue from 0 to 127
  controlChange(0, 36, mappedvalHiPotR); // Send CC
  MidiUSB.flush(); // Be sure CC is Send 

  valMidPotR = analogRead(MidPotR); // Read Analog Input
  mappedvalMidPotR = map(valMidPotR, 0, 1023, 0, 127); // Map readvalue from 0 to 127
  controlChange(0, 37, mappedvalMidPotR); // Send CC
  MidiUSB.flush(); // Be sure CC is Send 

  valBassPotR = analogRead(BassPotR); // Read Analog Input
  mappedvalBassPotR = map(valBassPotR, 0, 1023, 0, 127); // Map readvalue from 0 to 127
  controlChange(0, 38, mappedvalBassPotR); // Send CC
  MidiUSB.flush(); // Be sure CC is Send 


  valFilterL = analogRead(FilterL); // Read Analog Input
  mappedvalFilterL = map(valFilterL, 0, 1023, 0, 127); // Map readvalue from 0 to 127
  controlChange(0, 39, mappedvalFilterL); // Send CC
  MidiUSB.flush(); // Be sure CC is Send 

  valFilterR = analogRead(FilterR); // Read Analog Input
  mappedvalFilterR = map(valFilterR, 0, 1023, 0, 127); // Map readvalue from 0 to 127
  controlChange(0, 40, mappedvalFilterR); // Send CC
  MidiUSB.flush(); // Be sure CC is Send 
}
