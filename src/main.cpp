#include <Arduino.h>

#include <IRremote.h>
#include <cstdint>
#include "TFT_eSPI.h"
#include "variant.h"

// #include ""
// #include <stdio.h>
// #include <FreeRTOS.h>
// // #include <Serial.h>

// #include <IRLibSendBase.h>    // First include the send base
// //Now include only the protocols you wish to actually use.
// //The lowest numbered protocol should be first but remainder 
// //can be any order.
// #include <IRLib_P01_NEC.h>
// #include <IRLib_P02_Sony.h>
// #include <IRLibCombo.h>     // After all protocols, include this
// All of the above automatically creates a universal sending
// class called "IRsend" containing only the protocols you want.
// Now declare an instance of that sender.
extern "C" {
#include "get_code.h"
}


// put function declarations here:
// int myFunction(int, int);


const unsigned char IR_pin = WIO_IR;

const uint8_t C_raw = 0x00;
uint8_t C_temp_part = 0x00; /*C码温度部分*/
uint8_t C_mode_part = 0x00; /*C码模式部分*/
uint8_t c_temp_cal = 0xD0;

uint16_t buf[]={4400,4400,
                           550,1660,550,550,550,1660,550,1660,550,550,550,550,550,1660,550,550,
                           550,550,550,1660,550,550,550,550,550,1660,550,1660,550,550,550,1660,
                           550,550,550,1660,550,550,550,1660,550,1660,550,1660,550,1660,550,1660,
                           550,1660,550,550,550,1660,550,550,550,550,550,550,550,550,550,550,
                           550,1660,550,1660,550,550,550,1660,550,550,550,550,550,550,550,550,
                           550,550,550,550,550,1660,550,550,550,1660,550,1660,550,1660,550,1660,
                           550,5220,
                           4400,4400,
                           550,1660,550,550,550,1660,550,1660,550,550,550,550,550,1660,550,550,
                           550,550,550,1660,550,550,550,550,550,1660,550,1660,550,550,550,1660,
                           550,550,550,1660,550,550,550,1660,550,1660,550,1660,550,1660,550,1660,
                           550,1660,550,550,550,1660,550,550,550,550,550,550,550,550,550,550,
                           550,1660,550,1660,550,550,550,1660,550,550,550,550,550,550,550,550,
                           550,550,550,550,550,1660,550,550,550,1660,550,1660,550,1660,550,1660,
                           550,8000};

IRsend mySender;

uint8_t tempreture_increas(int temp_offset, int mode){
  uint8_t final_c;

  C_temp_part += temp_offset;
  if(mode == 0){ /*制热模式*/
    C_mode_part = 0x03;
    }
  else if(mode == 1){ /*制冷模式*/
    C_mode_part = 0x00;
  }

  final_c = C_temp_part << 4 | C_mode_part << 2 | C_raw;
  return final_c;
}

void sendMeidi_CLOSE(){
  mySender.sendRaw(buf_close, 300, 38);
}

TFT_eSPI tft;
void setup() {

  tft.begin();
  tft.setRotation(3);

  Serial.begin(9600);
  delay(2000); //while (!Serial); //delay for Leonardo
  Serial.println(F("Every time you press a key is a serial monitor we will send."));


  tft.fillScreen(TFT_BLACK); // fills entire the screen with colour red
  // delay(2000);
  // // Turning off the LCD backlight
  // digitalWrite(LCD_BACKLIGHT, LOW);
  // delay(2000);
  tft.println("test");
  // Turning on the LCD backlight
  digitalWrite(LCD_BACKLIGHT, HIGH);
  pinMode(WIO_KEY_A, INPUT_PULLUP);
  pinMode(WIO_KEY_B, INPUT_PULLUP);
  pinMode(WIO_KEY_C, INPUT_PULLUP);
  pinMode(WIO_5S_UP, INPUT_PULLUP);
  pinMode(WIO_5S_DOWN, INPUT_PULLUP);

  mySender.begin(IR_pin);
  pinMode(IR_pin, OUTPUT);
}

 
void sendMeidi_OPEN(unsigned char A,unsigned char B,unsigned char C){
  getcode(A, B, C, buf); 
  mySender.sendRaw(buf,200,38);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  static int cnt = 0;
  static int air_cnt = air_cnt;
  static int air_mode = 1;
  if (digitalRead(WIO_KEY_A) == LOW) {
    tft.print(cnt);
    tft.println("A Key pressed: Open the air condition ");
    sendMeidi_OPEN(0xB2,0xAF,c_temp_cal);  
    cnt ++;
  }
  else if (digitalRead(WIO_KEY_B) == LOW) {
    tft.print(cnt);
    air_mode = !air_mode;
    tft.print("B Key pressed Mode: ");
    tft.println(air_mode);
    cnt ++;
  }
  else if (digitalRead(WIO_KEY_C) == LOW) {
    tft.print(cnt);
    tft.println("C Key pressed: Close the air condition ");
    sendMeidi_CLOSE();
    cnt ++;
  }
  else if (digitalRead(WIO_5S_DOWN) == LOW) {
    tft.print(cnt);
    air_cnt --;
    tft.print("WIO_5S_DOWN: T:");
    tft.println(air_cnt + 17);
    cnt ++;
  }
  else if (digitalRead(WIO_5S_UP) == LOW) {
    tft.print(cnt);
    air_cnt ++;
    tft.print("WIO_5S_up: T:");
    tft.println(air_cnt + 17);
    cnt ++;
  }

  if(cnt > 11){
    tft.fillScreen(TFT_BLACK); // fills entire the screen with colour red
    tft.setCursor(tft.getCursorX(), 0);
    cnt = 0;
  }
  if (air_cnt > 13){
    air_cnt = 13;
  }
  if (air_cnt < 0){
    air_cnt = 0;
  }
  c_temp_cal = tempreture_increas(air_cnt, air_mode);
  delay(200);
  // if (Serial.read() != -1) {
  // //   send a code every time a character is received from the 
  // //   serial port. You could modify this sketch to send when you
  // //   push a button connected to an digital input pin.
  // //   Substitute values and protocols in the following statement
  // //   for device you have available.
  // //  mySender.send(SONY,0xa8bca, 20);//Sony DVD power A8BCA, 20 bits
  //   // mySender.send(NEC,0x61a0f00f,0);//NEC TV power button=0x61a0f00f
  //   mySender.sendRaw(buf, 200, 38);
  //   Serial.println(F("Sent signal."));
  // }
}

// put function definitions here:
int myFunction(int x, int y) {
  // return x + y;
}