// libraries
#include <SPI.h>
#include <SdFat.h>
#include <SdFatUtil.h>
#include <SFEMP3Shield.h>

SdFat sd;

SFEMP3Shield MP3player;

//touch value
int currentTouch0 = 0;
int currentTouch1 = 0;
int currentTouch2 = 0;
int currentTouch3 = 0;
int currentTouch4 = 0;
int currentTouch5 = 0;

//storage value
int lastTouch0;
int lastTouch1;
int lastTouch2;
int lastTouch3;
int lastTouch4;
int lastTouch5;

//the number change of touched and before touch
int TouchSensitivity = 5;


void setup() {
  Serial.begin(115200);
  //SD card
  if (!sd.begin(9, SPI_HALF_SPEED)) sd.initErrorHalt();
  if (!sd.chdir("/")) sd.errorHalt("sd.chdir");
  //start MP3 player
  MP3player.begin();
  MP3player.setVolume(10, 10);
  //touch pins
  for (int i = A0; i <= A5; i++) {
    pinMode(i, INPUT);
  }

  TIMSK0 &= !(1 << TOIE0);
}

void loop() {
  //asign reading to the name we create
  currentTouch0 = 1024 - analogRead(A0);
  currentTouch1 = 1024 - analogRead(A1);
  currentTouch2 = 1024 - analogRead(A2);
  currentTouch3 = 1024 - analogRead(A3);
  currentTouch4 = 1024 - analogRead(A4);
  currentTouch5 = 1024 - analogRead(A5);

  // compairing the changes by using if else statement
  if ((currentTouch0 - lastTouch0) >= TouchSensitivity) {
    MP3player.playTrack(0);
  } else if ((currentTouch1 - lastTouch1) >= TouchSensitivity) {
    MP3player.playTrack(1);
  } else if ((currentTouch2 - lastTouch2) >= TouchSensitivity) {
    MP3player.playTrack(2);
  } else if ((currentTouch3 - lastTouch3) >= TouchSensitivity) {
    MP3player.playTrack(3);
  } else if ((currentTouch4 - lastTouch4) >= TouchSensitivity) {
    MP3player.playTrack(4);
  } else if ((currentTouch5 - lastTouch5) >= TouchSensitivity) {
    MP3player.playTrack(5);
  } else {
    MP3player.stopTrack();
  }

  //print out the datas through serial monitor by the channel 115200(begin in the setup)
  Serial.print("currentTouch0: ");
  Serial.print(currentTouch0);
  Serial.print("\t lastTouch0: ");
  Serial.println(lastTouch0);

  //storage for last loop touch data
  lastTouch0 = currentTouch0;
  lastTouch1 = currentTouch1;
  lastTouch2 = currentTouch2;
  lastTouch3 = currentTouch3;
  lastTouch4 = currentTouch4;
  lastTouch5 = currentTouch5;

  //delay 0.1s , 1000 = 1s 
  delay(100);
}
