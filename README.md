<h1 align="center">🎵 共融藝術 ✕ 科技 學生工作坊 🎵</h1>
<p align="center"> 2024/25 Phase 2: Student Workshop </p>
<p align="center">🧑‍🏫 Cat &emsp;&emsp;👨‍🏫 Lazarus&emsp;&emsp;👩‍🏫 Yan</p>


## 🎨 工作坊內容簡介：
賽馬會科藝共融計劃（Jockey Club Project IDEA）由香港賽馬會慈善信託基金捐助、香港城市大學主辦，旨在提升本地中學教師及學生對藝術科技的認識和能力，透過工作坊讓他們掌握如何應用數碼科技進行藝術創作，為傳統創作方式注入新元素，創造更多別樹一格的表現方式。同時，本計劃將透過分享和體驗活動提升學生對共融藝術的意識，啟發他們反思如何讓殘疾人士欣賞藝術及參與藝術活動，透過藝術科技建立共融的社會。 

## Useful Links:
1. Soundtrack trimmer  https://mp3cut.net/
2. Text to mp3 https://voicemaker.in/ <br>
      ACC: jcidea2425p2@gmail.com    <br>  PW: workshop@2425P2
3. Free Sound https://freesound.org/ <br>
      ACC: jcidea   <br>   PW: workshop2425p2
4. Free Sound Effects https://pixabay.com/sound-effects/
5. Free Sound https://mixkit.co/
6. Theremin https://synth.playtronica.com/theremin/
7. Rolan 50 Studio https://roland50.studio/
8. Ableton Playground https://learningsynths.ableton.com/en/playground 

## Related Links:
1. iii https://instrumentinventors.org/ 
2. Waveforms Visualize https://pudding.cool/2018/02/waveforms/

## Artwork Submission:
1. Sumbit Artwork (Google Form) https://tinyurl.com/JCIDEA-ex20252

## Touch Slider
```sh
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
```

## Touch To Play MP3
```sh
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
```
