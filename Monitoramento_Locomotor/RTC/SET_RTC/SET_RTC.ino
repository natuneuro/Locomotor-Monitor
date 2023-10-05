#include <DS3231.h>
DS3231  rtc(SDA, SCL);
void setup() {
  // Setup Serial connection
  Serial.begin(9600);
  // Uncomment the next line if you are using an Arduino Leonardo
  //while (!Serial) {}
  
  // Initialize the rtc object
  rtc.begin();
  
  // The following lines can be uncommented to set the date and time
  rtc.setDOW(THURSDAY);     // Set Day-of-Week
  rtc.setTime(14, 24, 50);     // Set the time (24hr format)
  rtc.setDate(5, 10, 2023);   // Set the date to the current day, month, year
}

void loop() {
  


}
