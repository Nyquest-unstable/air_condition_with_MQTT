#include <Arduino.h>

#include <IRremote.h>
#include "TFT_eSPI.h"

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
#include "get_code.h"

// put function declarations here:
// int myFunction(int, int);


const unsigned char IR_pin = WIO_IR;

unsigned int buf[]={4400,4400,
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

  mySender.begin(IR_pin);
  pinMode(IR_pin, OUTPUT);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  static int cnt = 0;
  if (digitalRead(WIO_KEY_A) == LOW) {
    tft.print(cnt);
    tft.println("A Key pressed and open the air condition ");
    cnt ++;
  }
  else if (digitalRead(WIO_KEY_B) == LOW) {
    tft.print(cnt);
    tft.println("B Key pressed");
    cnt ++;
  }
  else if (digitalRead(WIO_KEY_C) == LOW) {
    tft.print(cnt);
    tft.println("C Key pressed and close the air condition ");
    cnt ++;
  }
  if(cnt > 11){
    tft.fillScreen(TFT_BLACK); // fills entire the screen with colour red
    tft.setCursor(tft.getCursorX(), 0);
    cnt = 0;
  }
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