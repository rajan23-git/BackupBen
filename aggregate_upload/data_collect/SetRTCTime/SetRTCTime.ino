#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>


tmElements_t tm;

void setup() {
  tm.Hour = 0;
  tm.Minute = 16;
  tm.Second = 30;
  tm.Month = 3;
  tm.Day = 30;
  tm.Year = CalendarYrToTm(2023);
  RTC.write(tm);
}
void loop(){

}
