#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SH110X.h>
#include "Images.h"

#define i2c_Address 0x3c // initialize with the I2C addr 0x3C Typically eBay OLED's
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1    // QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
    Serial.begin(9600);
    display.begin(i2c_Address, true);
    display.display(); // show the adafruit splash screen
    delay(2000);
}

void loop()
{
    for (int i = 0; i < bmpCount; i++)
    {
        display.clearDisplay();
        display.drawBitmap(0, 0, bmpArray[i], 128, 64, 1);
        display.display();
        delay(8000);
    }
}
