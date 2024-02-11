/*
Steps:
1. Edit pcmConfig.h
   a: On Uno or non-mega boards, #define buffSize 128. May need to increase.
   b: Uncomment #define ENABLE_RECORDING and #define BLOCK_COUNT 10000UL

2. Usage is as below. See https://github.com/TMRh20/TMRpcm/wiki/Advanced-Features#wiki-recording-audio for
  additional informaiton.
*/

#include <SD.h>
#include <SPI.h>
#include <TMRpcm.h>
#include <pcmConfig.h>
#define SD_ChipSelectPin 8
TMRpcm audio;
// int audiofile = 0; //the number to name the file
int theButton = 7;
int recCount = 0;
bool wasON = false;

void setup() {
 pinMode(A0, INPUT);
 pinMode(theButton, INPUT_PULLUP);
 // attachInterrupt(0, button, LOW);
 SD.begin(SD_ChipSelectPin);
 audio.CSPin = SD_ChipSelectPin;
 Serial.begin(9600);
 Serial.println("started");
 if (SD.exists("LATEST.wav")) {
   SD.remove("LATEST.wav");;
 }
}

void loop() {
 if (digitalRead(theButton) == LOW && wasON == false) {  //if button is pressed
   Serial.println("button pressed");
   wasON = true;
   /* start recording when button is first pressed */
   Serial.println("started recording");
   audio.startRecording("LATEST.wav", 16000, A0);
 }
 /* stop recording when button is let go, but wasON has to be true while  */
 if (digitalRead(theButton) == HIGH && wasON == true) {  //if button released
   wasON = false;
   audio.stopRecording("LATEST.wav");
   Serial.println("stopped recording");
 }
}