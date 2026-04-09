#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> //by Adafruit

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
  Wire.begin(1, 3); //(SDA, SCL) 1,3:ConnectorA 5,4:ConnectorB

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    for(;;); //Infinite loop when screen initialization fails
  }

  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 5);
  display.print(F("Hello"));
  display.setCursor(20, 25);
  display.print(F("My"));
  display.setCursor(30, 45);
  display.print(F("Friend"));
  display.startscrolldiagright(0x00, 0x0f);
  display.display();
  
}

void loop()
{
}