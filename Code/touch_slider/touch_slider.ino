// libraries
#include <SPI.h>
#include <SdFat.h>
#include <SdFatUtil.h>
#include <SFEMP3Shield.h>
#include <Tone.h>


SdFat sd;

SFEMP3Shield MP3player;

Tone notePlayer;
int slider = 0;

void setup() {
  Serial.begin(115200);
  notePlayer.begin(8);
}

void loop() {
  slider = analogRead(A0);

  Serial.println(slider);
  int sound = map(slider, 0, 1023, 0, 2000);
  notePlayer.play(sound);
  delay(100);
}
