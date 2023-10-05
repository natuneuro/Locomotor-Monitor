#include <DS3231.h>
// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);
 
// Code from the Demo Example of the DS3231 Library
 
void setup()
{
   // PIR sensor 
   pinMode(2, INPUT);
   pinMode(3, OUTPUT);
  
   // Setup Serial connection
  Serial.begin(9600);
  // Uncomment the next line if you are using an Arduino Leonardo
  //while (!Serial) {}
  
  // Initialize the rtc object
  rtc.begin();
}
 
void loop()
{

  // PIR SENSOR
   bool value = digitalRead(2);
   if (value == 1){
      Serial.println("ON");
      digitalWrite(3,HIGH);
     
   } else{
     Serial.println("OFF");
     digitalWrite(3,LOW);
   }
  
  // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");
 
  // Send time
  Serial.println(rtc.getTimeStr());
  
  // Wait one second before repeating :)
  delay (1000);
}
