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
  Serial.begin(115200);
  Serial.println("Starting setup...");
  
  // Add current task to watchdog with default timeout
  
  Serial.println("Initializing display...");
  tft.init();
  
  tft.invertDisplay(false);
  tft.setRotation(1);
  
  Serial.println("Setting up backlight...");
  pinMode(9, OUTPUT);
  analogWrite(9, 200); // Turn on backlight
  
  Serial.println("Filling screen black...");
  tft.fillScreen(TFT_BLACK);

  Serial.println("Creating sprite...");
  stats.createSprite(284, 76, 1);
  stats.setTextColor(TFT_WHITE, TFT_BLACK);
  stats.setTextSize(1);
  
  Serial.println("Setup complete!");
}

void loop() {
  
  unsigned long loop_start_time = micros();
  
  stats.fillSprite(TFT_BLACK);

  // Draw arrows
  stats.drawBitmap(108, 19, image_arrow_curved_down_right_bits, 5, 8, 0xFFFF);
  stats.drawBitmap(115, 12, image_arrow_curved_left_down_bits, 8, 5, 0xFFFF);
  stats.drawBitmap(115, 29, image_arrow_curved_right_up_bits, 8, 5, 0xFFFF);
  stats.drawBitmap(125, 19, image_arrow_curved_up_left_bits, 5, 8, 0xFFFF);

  // Draw main text with custom font
  stats.setTextDatum(MC_DATUM);
  stats.setFreeFont(IMPACT20);
  stats.drawString(String(millis()), WIDTH/2, HEIGHT/3*2);
  
  // Draw performance info
  stats.setTextDatum(TL_DATUM);
  stats.setFreeFont();
  stats.drawString("Loop: " + String(micros() - loop_start_time) + "us", 5, 5);

  stats.pushSprite(0, 0);
  
  // Add small delay to prevent overwhelming the display
  delay(50);  // 50ms delay for ~20 FPS
  
}