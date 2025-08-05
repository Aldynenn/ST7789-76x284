#include <TFT_eSPI.h>

#include <impact20pt7b.h>

#define IMPACT20 &impact20pt7b


TFT_eSPI tft = TFT_eSPI();

#define HEIGHT TFT_WIDTH
#define WIDTH TFT_HEIGHT

TFT_eSprite stats = TFT_eSprite(&tft);

static const unsigned char PROGMEM image_arrow_curved_down_right_bits[] = {0x20,0x40,0x40,0xc0,0xe8,0x78,0x38,0x78};
static const unsigned char PROGMEM image_arrow_curved_left_down_bits[] = {0x18,0xbe,0xf1,0xe0,0xf0};
static const unsigned char PROGMEM image_arrow_curved_right_up_bits[] = {0x0f,0x07,0x8f,0x7d,0x18};
static const unsigned char PROGMEM image_arrow_curved_up_left_bits[] = {0xf0,0xe0,0xf0,0xb8,0x18,0x10,0x10,0x20};

void setup(void) {
  tft.init();
  tft.invertDisplay(false);
  tft.setRotation(1);
  pinMode(15, OUTPUT);
  analogWrite(15, 64); // Turn on backlight
  
  tft.fillScreen(TFT_BLACK);

  
  stats.createSprite(284, 76, 1);
  stats.setTextColor(TFT_WHITE, TFT_BLACK);
  stats.setTextSize(1);
}
// int state = 0;
void loop() {
  unsigned long loop_start_time = micros();
  // stats.fillSprite(TFT_BLACK);
  // stats.setCursor(0, 38);
  // stats.print("Started " + String(millis()) + " ms ago");

  // stats.fillSprite(TFT_BLACK);
  // stats.setTextColor(0xFFFF);
  // stats.setTextSize(1);
  // stats.drawString("-- This is a test --", WIDTH/2, HEIGHT/2);
  // stats.drawRect(0, 0, 284, 76, 0xFFFF);
  // stats.fillEllipse(268, 15, 11, 11, 0xFFFF);
  // stats.drawEllipse(15, 15, 11, 11, 0xFFFF);
  // stats.drawLine(4, 70, 280, 70, 0xFFFF);

  
  stats.fillSprite(TFT_BLACK);

  stats.drawBitmap(108, 19, image_arrow_curved_down_right_bits, 5, 8, 0xFFFF);
  stats.drawBitmap(115, 12, image_arrow_curved_left_down_bits, 8, 5, 0xFFFF);
  stats.drawBitmap(115, 29, image_arrow_curved_right_up_bits, 8, 5, 0xFFFF);
  stats.drawBitmap(125, 19, image_arrow_curved_up_left_bits, 5, 8, 0xFFFF);

  stats.setTextDatum(MC_DATUM);
  stats.setFreeFont(IMPACT20);
  stats.drawString(String(millis()), WIDTH/2, HEIGHT/3*2);
  
  stats.setTextDatum(TL_DATUM);
  stats.setFreeFont();
  stats.drawString("Loop duration: " + String(micros() - loop_start_time) + " us", 5, 5);

  stats.pushSprite(0, 0);
}