#include <DS3231.h>
DS3231  rtc(SDA, SCL);  // Initialize the DS3231 using the hardware interface
void setup()
{
  Serial.begin(9600);  // Setup Serial connection
  rtc.begin();
  rtc.setDOW(TUESDAY);     // Set day of week
  rtc.setTime(7, 54, 0);     // Set the time (24 hour format)
  rtc.setDate(4, 1, 2023);   // Set the date
}

void loop()
{
  // Send Day of week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // Send time
  Serial.println(rtc.getTimeStr());
  
  delay (1000);
}
