/*
Midbar ESP32 CYD Firebase Edition
Distributed under the MIT License
© Copyright Maxim Bortnikov 2024
For more information please visit
https://github.com/Northstrix/Midbar-ESP32-CYD-Firebase-Edition
https://sourceforge.net/projects/midbar-esp32-cyd-firebase/
Required libraries:
https://github.com/Northstrix/AES_in_CBC_mode_for_microcontrollers
https://github.com/peterferrie/serpent
https://github.com/ulwanski/sha512
https://github.com/Bodmer/TFT_eSPI
https://github.com/intrbiz/arduino-crypto
https://github.com/techpaul/PS2KeyAdvanced
https://github.com/techpaul/PS2KeyMap
https://github.com/mobizt/Firebase-ESP32
*/
// !!! Before uploading this sketch -
// Switch the partition scheme to the
// "Huge APP (3MB No OTA/1MB SPIFFS)" !!!
/*
Credit for photos:
https://www.pexels.com/photo/bird-s-eye-view-of-city-during-daytime-2815170/
https://www.pexels.com/photo/gray-concrete-building-under-blue-sky-10482416/
https://pixabay.com/photos/stairs-park-rise-staircase-2999277/
https://pixabay.com/photos/architecture-city-townscape-3251733/
https://unsplash.com/photos/city-skyline-between-sky-and-body-of-water-Ev0Vj_0PPck
https://unsplash.com/photos/red-and-black-train-on-bridge-over-body-of-water-during-daytime-yLcPSvJkGrM
https://pixabay.com/photos/riyadh-saudi-arabia-city-night-2197496/
https://unsplash.com/photos/aerial-view-of-building-under-blue-sky-during-daytime-FRZ8jQ9j85U
https://unsplash.com/photos/cars-parked-on-street-near-buildings-during-daytime-lQRE1n2Is0s
https://unsplash.com/photos/merlion-singapore-v0BgDZTJyPY
https://unsplash.com/photos/a-city-with-tall-buildings-tNklhdD_D9o
https://pixabay.com/photos/urban-buildings-skyscraper-horizon-1905188/
*/
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>
#include "midbaricon.h"

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library
TFT_eSprite mvng_bc = TFT_eSprite(&tft);

bool display_moving_background = true;

/*
void disp_centered_text(String text, int h) {
  int16_t x1;
  int16_t y1;
  uint16_t width;
  uint16_t height;

  tft.getTextBounds(text, 0, 0, & x1, & y1, & width, & height);
  tft.setCursor((320 - width) / 2, h);
  tft.print(text);
}
*/

void disp_centered_text(String text, int h) {
  tft.drawCentreString(text, 160, h, 1);
}

void disp_centered_text_b_w(String text, int h) {
  tft.setTextColor(0x0882);
  tft.drawCentreString(text, 160, h - 1, 1);
  tft.drawCentreString(text, 160, h + 1, 1);
  tft.drawCentreString(text, 159, h, 1);
  tft.drawCentreString(text, 161, h, 1);
  tft.setTextColor(0xf7de);
  tft.drawCentreString(text, 160, h, 1);
}

int chosen_lock_screen;

void display_lock_screen() {
  chosen_lock_screen = esp_random() % 13;

  if (chosen_lock_screen == 0){
    for (int i = 0; i < 320; i++){
      for (int j = 0; j < 190; j++){
        tft.drawPixel(i, j + 25, Atlanta[i][j]);
      }
    }
  }
  
  if (chosen_lock_screen == 1){
    for (int i = 0; i < 320; i++){
      for (int j = 0; j < 190; j++){
        tft.drawPixel(i, j + 25, Dallas[i][j]);
      }
    }
  }

  if (chosen_lock_screen == 2){
    for (int i = 0; i < 320; i++){
      for (int j = 0; j < 190; j++){
        tft.drawPixel(i, j + 25, Denver[i][j]);
      }
    }
  }

  if (chosen_lock_screen == 3){
    for (int i = 0; i < 320; i++){
      for (int j = 0; j < 190; j++){
        tft.drawPixel(i, j + 25, Haifa[i][j]);
      }
    }
  }

  if (chosen_lock_screen == 4){
    for (int i = 0; i < 320; i++){
      for (int j = 0; j < 190; j++){
        tft.drawPixel(i, j + 25, Jerusalem[i][j]);
      }
    }
  }

  if (chosen_lock_screen == 5){
    for (int i = 0; i < 320; i++){
      for (int j = 0; j < 190; j++){
        tft.drawPixel(i, j + 25, Miami[i][j]);
      }
    }
  }

  if (chosen_lock_screen == 6){
    for (int i = 0; i < 320; i++){
      for (int j = 0; j < 190; j++){
        tft.drawPixel(i, j + 25, New_Orleans[i][j]);
      }
    }
  }

  if (chosen_lock_screen == 7){
    for (int i = 0; i < 320; i++){
      for (int j = 0; j < 190; j++){
        tft.drawPixel(i, j + 25, Pittsburgh[i][j]);
      }
    }
  }

  if (chosen_lock_screen == 8){
    for (int i = 0; i < 320; i++){
      for (int j = 0; j < 190; j++){
        tft.drawPixel(i, j + 25, Riyadh[i][j]);
      }
    }
  }

  if (chosen_lock_screen == 9){
    for (int i = 0; i < 320; i++){
      for (int j = 0; j < 190; j++){
        tft.drawPixel(i, j + 25, Rome[i][j]);
      }
    }
  }

  if (chosen_lock_screen == 10){
    for (int i = 0; i < 320; i++){
      for (int j = 0; j < 190; j++){
        tft.drawPixel(i, j + 25, Singapore[i][j]);
      }
    }
  }

  if (chosen_lock_screen == 11){
    for (int i = 0; i < 320; i++){
      for (int j = 0; j < 190; j++){
        tft.drawPixel(i, j + 25, Tel_Aviv[i][j]);
      }
    }
  }

  if (chosen_lock_screen == 12){
    for (int i = 0; i < 320; i++){
      for (int j = 0; j < 240; j++){
        tft.drawPixel(i, j, Saint_Paul[i][j]);
      }
    }
  }
}

void setup() {
  tft.begin();
  tft.fillScreen(11315);
  tft.setRotation(3);
  display_lock_screen();
  
  delay(1000);

  for (int i = 0; i < 306; i++){
    for (int j = 0; j < 77; j++){
      if (mdb_per[i][j] == 1)
          tft.drawPixel(i+7, j+82, 0xf7de);
    }
  }
  
  tft.setTextSize(2);
  tft.setTextColor(0xf7de);
  disp_centered_text_b_w("Midbar Firebase Edition", 4);
  disp_centered_text_b_w("Press Any Key", 220);
  mvng_bc.createSprite(306, 77);
  mvng_bc.setColorDepth(16);
  mvng_bc.fillSprite(TFT_TRANSPARENT);
}

unsigned int k = 0;
void loop() {
  if (display_moving_background == true) {
    if (chosen_lock_screen == 0) {
      for (int i = 0; i < 306; i++) {
        for (int j = 0; j < 77; j++) {
          if (mdb_icon[i][j] == 1)
            mvng_bc.drawPixel(i, j, Atlanta[(i + 7 + k) % 320][j + 57]);
        }
      }
    }

    if (chosen_lock_screen == 1) {
      for (int i = 0; i < 306; i++) {
        for (int j = 0; j < 77; j++) {
          if (mdb_icon[i][j] == 1)
            mvng_bc.drawPixel(i, j, Dallas[(i + 7 + k) % 320][j + 57]);
        }
      }
    }

    if (chosen_lock_screen == 2) {
      for (int i = 0; i < 306; i++) {
        for (int j = 0; j < 77; j++) {
          if (mdb_icon[i][j] == 1)
            mvng_bc.drawPixel(i, j, Denver[(i + 7 + k) % 320][j + 57]);
        }
      }
    }

    if (chosen_lock_screen == 3) {
      for (int i = 0; i < 306; i++) {
        for (int j = 0; j < 77; j++) {
          if (mdb_icon[i][j] == 1)
            mvng_bc.drawPixel(i, j, Haifa[(i + 7 + k) % 320][j + 57]);
        }
      }
    }

    if (chosen_lock_screen == 4) {
      for (int i = 0; i < 306; i++) {
        for (int j = 0; j < 77; j++) {
          if (mdb_icon[i][j] == 1)
            mvng_bc.drawPixel(i, j, Jerusalem[(i + 7 + k) % 320][j + 57]);
        }
      }
    }

    if (chosen_lock_screen == 5) {
      for (int i = 0; i < 306; i++) {
        for (int j = 0; j < 77; j++) {
          if (mdb_icon[i][j] == 1)
            mvng_bc.drawPixel(i, j, Miami[(i + 7 + k) % 320][j + 57]);
        }
      }
    }

    if (chosen_lock_screen == 6) {
      for (int i = 0; i < 306; i++) {
        for (int j = 0; j < 77; j++) {
          if (mdb_icon[i][j] == 1)
            mvng_bc.drawPixel(i, j, New_Orleans[(i + 7 + k) % 320][j + 57]);
        }
      }
    }

    if (chosen_lock_screen == 7) {
      for (int i = 0; i < 306; i++) {
        for (int j = 0; j < 77; j++) {
          if (mdb_icon[i][j] == 1)
            mvng_bc.drawPixel(i, j, Pittsburgh[(i + 7 + k) % 320][j + 57]);
        }
      }
    }

    if (chosen_lock_screen == 8) {
      for (int i = 0; i < 306; i++) {
        for (int j = 0; j < 77; j++) {
          if (mdb_icon[i][j] == 1)
            mvng_bc.drawPixel(i, j, Riyadh[(i + 7 + k) % 320][j + 57]);
        }
      }
    }

    if (chosen_lock_screen == 9) {
      for (int i = 0; i < 306; i++) {
        for (int j = 0; j < 77; j++) {
          if (mdb_icon[i][j] == 1)
            mvng_bc.drawPixel(i, j, Rome[(i + 7 + k) % 320][j + 57]);
        }
      }
    }

    if (chosen_lock_screen == 10) {
      for (int i = 0; i < 306; i++) {
        for (int j = 0; j < 77; j++) {
          if (mdb_icon[i][j] == 1)
            mvng_bc.drawPixel(i, j, Singapore[(i + 7 + k) % 320][j + 57]);
        }
      }
    }

    if (chosen_lock_screen == 11) {
      for (int i = 0; i < 306; i++) {
        for (int j = 0; j < 77; j++) {
          if (mdb_icon[i][j] == 1)
            mvng_bc.drawPixel(i, j, Tel_Aviv[(i + 7 + k) % 320][j + 57]);
        }
      }
    }
  
    if (chosen_lock_screen == 12){
      for (int i = 0; i < 306; i++){
        for (int j = 0; j < 77; j++){
          if (mdb_icon[i][j] == 1)
            mvng_bc.drawPixel(i, j, Saint_Paul[(i + 7 + k)%320][j+82]);
        }
      }
    }

    mvng_bc.pushSprite(7, 82, TFT_TRANSPARENT);
    k++;
  }
}
