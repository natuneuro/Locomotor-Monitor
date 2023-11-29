#include <DS3231.h>
#include <SPI.h>
#include <SD.h>

// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);
 
// Code from the Demo Example of the DS3231 Library
bool set_date = false;  //Bool to set Date in the RTC module

// SDcard Variables
File myFile;
String rtc_date;
String date_file;
String rtc_time;
String rtc_day;
String pir_sensor;
String header = "Test:";

bool button_status = false;
 
void setup()
{
   // PIR sensor 
   pinMode(2, INPUT);
   pinMode(4, OUTPUT);

   // BUTTON CONFIG
   pinMode(3, INPUT_PULLUP);

   attachInterrupt(digitalPinToInterrupt(3), button_press, FALLING);
   attachInterrupt(digitalPinToInterrupt(2), pir_change, CHANGE);

  
   // Setup Serial connection
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // Initialize the rtc object
  rtc.begin();

  // Set the date to the RTC if bollena set_date is true
  if (set_date){
    // The following lines can be uncommented to set the date and time
    rtc.setDOW(THURSDAY);     // Set Day-of-Week
    rtc.setTime(14, 15, 50);     // Set the time (24hr format)
    rtc.setDate(10, 10, 2023);   // Set the date to the current day, month, year  
  }

  // SDCard Initialization
  Serial.print("Initializing SD card...");

  if (!SD.begin(10)) {
    Serial.println(F("initialization failed!"));
    while (1);
  }
  Serial.println(F("initialization done."));

  date_file = rtc.getDateStr(FORMAT_LONG,FORMAT_LITTLEENDIAN,'-');
  date_file.remove(2,1);
  date_file.remove(4,1);
  date_file =date_file+".txt";
  Serial.println(date_file);
}
 
void loop()
{
   
   // PIR SENSOR
<<<<<<< Updated upstream
   //bool value = digitalRead(2);
   //if (value == 1){
   //   pir_sensor ="ON";
   //   digitalWrite(4,HIGH);
     
   //} else{
   //  pir_sensor = "OFF";
   //  digitalWrite(4,LOW);
   //}
=======
   bool value = digitalRead(2);
   if (value == 1){
      pir_sensor = int(1);
      digitalWrite(3,HIGH);
     
   } else{
     pir_sensor = int(0);
     digitalWrite(3,LOW);
   }


  // Send Day-of-Week
  rtc_day = rtc.getDOWStr();
  Serial.println(rtc_day);
  
  // Send date
  rtc_date = rtc.getDateStr();
  Serial.println(rtc_date);

  // Send time
  rtc_time = rtc.getTimeStr();
  Serial.println(rtc_time);

  String sd_save = rtc_day+","+rtc_date+","+rtc_time+","+pir_sensor;
  Serial.println(sd_save);
  
  if(button_status == true){
    myFile = SD.open(date_file, FILE_WRITE);
    if (myFile) {
       myFile.println(sd_save);
        Serial.println("Saved...");
    }else{
      // if the file didn't open, print an error:
      Serial.println("error opening"+date_file);
    }
    myFile.close();
  }
  // Wait one second before repeating :)
  delay (1000);
}

// BUTTON LECTURE
void button_press(){
  button_status = true;
}

void pir_change(){
   bool value = digitalRead(2);
   if (value == 1){
      pir_sensor ="ON";
      digitalWrite(4,HIGH);
     
   } else{
     pir_sensor = "OFF";
     digitalWrite(4,LOW);
   }
}
