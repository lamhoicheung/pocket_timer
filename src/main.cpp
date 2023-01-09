#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

/*
  U8g2lib Example Overview:
    Frame Buffer Examples: clearBuffer/sendBuffer. Fast, but may not work with all Arduino boards because of RAM consumption
    Page Buffer Examples: firstPage/nextPage. Less RAM usage, should work with all Arduino boards.
    U8x8 Text Only Example: No RAM usage, direct communication with display controller. No graphics, 8x8 Text only.
    
*/


U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
// U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ 22, /* data=*/ 21);   // ESP32 Thing, HW I2C with pin remapping



void setup(void) {
  Serial.begin(115200);
  pinMode(14, INPUT_PULLUP);
  
  // DOGS102 Shield (http://shieldlist.org/controlconnection/dogs102)
  // u8g2.begin(/* menu_select_pin= */ 5, /* menu_next_pin= */ 4, /* menu_prev_pin= */ 2, /* menu_home_pin= */ 3);
  
  // DOGM128 Shield (http://shieldlist.org/schmelle2/dogm128) + DOGXL160 Shield
  // u8g2.begin(/* menu_select_pin= */ 2, /* menu_next_pin= */ 3, /* menu_prev_pin= */ 7, /* menu_home_pin= */ 8);

  // MKR Zero Test Board
  //u8g2.begin(/*Select=*/ 0, /*Right/Next=*/ 1, /*Left/Prev=*/ 2, /*Up=*/ 4, /*Down=*/ 3, /*Home/Cancel=*/ A6); 

  // Arduboy
  //u8g2.begin(/*Select=*/ A0, /*Right/Next=*/ 5, /*Left/Prev=*/ 9, /*Up=*/ 8, /*Down=*/ 10, /*Home/Cancel=*/ A1); // Arduboy DevKit
//   u8g2.begin(/*Select=*/ 7, /*Right/Next=*/ A1, /*Left/Prev=*/ A2, /*Up=*/ A0, /*Down=*/ A3, /*Home/Cancel=*/ 8); // Arduboy 10 (Production)
  u8g2.begin(14, U8X8_PIN_NONE, U8X8_PIN_NONE, U8X8_PIN_NONE, U8X8_PIN_NONE, U8X8_PIN_NONE);
  u8g2.setFont(u8g2_font_6x12_tr);
}

const char *string_list = 
  "Timer\n"
  "Countdown\n"
  "Setting";

uint8_t current_selection = 3;


void loop(void) {

  // this blocks until some button events happen
  int i = u8g2.userInterfaceSelectionList(
    "Pocket Timer",
    current_selection, 
    string_list);

  Serial.println(i);
  // if ( current_selection == 0 ) {
  //   u8g2.userInterfaceMessage(
	// "Nothing selected.", 
	// "",
	// "",
	// " ok ");
  // } else {
  //   u8g2.userInterfaceMessage(
	// "Selection:", 
	// u8x8_GetStringLineStart(current_selection-1, string_list ),
	// "",
	// " ok \n cancel ");
  // }

  // delay(1000);
  // current_selection++;

  // if (current_selection > 3) current_selection = 1;

}


