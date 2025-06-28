#include <TFT_eSPI.h>
TFT_eSPI tft = TFT_eSPI();

uint8_t rotation;
uint16_t w;
uint16_t h;

void changeRotation(uint8_t rotation)
{
  tft.setRotation(rotation);

  if (rotation == 0 || rotation == 2)
  {
    w = TFT_WIDTH;
    h = TFT_HEIGHT;
  }
  else if (rotation == 1 || rotation == 3)
  {
    w = TFT_HEIGHT;
    h = TFT_WIDTH;
  }
  tft.setRotation(rotation);
}

void setup(void)
{
  rotation = 0;

  tft.init();
  tft.invertDisplay(false);
  changeRotation(rotation);
  tft.setTextFont(2);
}

void drawSpec(void)
{
  tft.setCursor(4, 20);
  tft.print("ST7789");
  tft.setCursor(4, 38);
  tft.print("76x284");
  tft.setCursor(4, 56);
  tft.print("Rot " + String(rotation));
}

void loop()
{
  tft.fillScreen(TFT_CYAN);
  tft.setCursor(4, 2);
  tft.print("Cyan");
  drawSpec();
  tft.drawRect(0, 0, w, h, TFT_WHITE);
  delay(2500);

  tft.fillScreen(TFT_YELLOW);
  tft.setCursor(4, 2);
  tft.print("Yellow");
  drawSpec();
  tft.drawRect(0, 0, w, h, TFT_WHITE);
  delay(2500);

  tft.fillScreen(TFT_MAGENTA);
  tft.setCursor(4, 2);
  tft.print("Magenta");
  drawSpec();
  tft.drawRect(0, 0, w, h, TFT_WHITE);
  delay(2500);

  tft.fillRectHGradient(0, 0, w, h, TFT_RED, TFT_BLUE);
  tft.setCursor(4, 2);
  tft.print("Red-Blue");
  drawSpec();
  tft.drawRect(0, 0, w, h, TFT_WHITE);
  delay(2500);

  tft.fillRectHGradient(0, 0, w, h, TFT_BLUE, TFT_GREEN);
  tft.setCursor(4, 2);
  tft.print("Blue-Green");
  drawSpec();
  tft.drawRect(0, 0, w, h, TFT_WHITE);
  delay(2500);

  tft.fillRectHGradient(0, 0, w, h, TFT_GREEN, TFT_RED);
  tft.setCursor(4, 2);
  tft.print("Green-Red");
  drawSpec();
  tft.drawRect(0, 0, w, h, TFT_WHITE);
  delay(2500);

  if(++rotation == 4) {
    rotation = 0;
  }

  changeRotation(rotation);
}
