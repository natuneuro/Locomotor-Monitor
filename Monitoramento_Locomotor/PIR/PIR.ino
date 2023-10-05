void setup() {
  // put your setup code here, to run once:
 pinMode(2, INPUT);
 pinMode(3, OUTPUT);
 Serial.begin(9600);
}

void loop() {
  // PIR SENSOR
   bool value = digitalRead(2);
   if (value == 1){
      Serial.println("ON");
      digitalWrite(3,HIGH);
     
   } else{
     Serial.println("OFF");
     digitalWrite(3,LOW);
   }
}
