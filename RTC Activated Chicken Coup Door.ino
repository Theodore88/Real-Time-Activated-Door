#include <DS3231.h>
DS3231  rtc(SDA, SCL); // Initialize the DS3231 using the hardware interface
Time t;
const int OnHour = 3; //Set time for actuator to extend (24 hour format)
const int OnMin = 53;
const int OffHour = 7; // Set time for actuator to retract (24 hour format)
const int OffMin = 54;
byte extend = 10; // Define extend pin on Arduino 
byte retract = 9; // Define retract pin on Arduino
void setup() {
  Serial.begin(9600);
  pinMode(extend, OUTPUT); 
  pinMode(retract, OUTPUT); 
// Define retract and extend pins as an output pins
  digitalWrite(extend,LOW); 
  digitalWrite(retract,LOW);
// Set extend and retract too LOW too ensure acuator does not extend or retract once code is uploaded
  rtc.begin();
}

void loop() 
{
  t = rtc.getTime();
  Serial.print(t.hour);
  Serial.print(" hour(s), ");
  Serial.print(t.min);
  Serial.print(" minute(s)");
  Serial.println(" ");
  // Print time on DS3231 to serial monitor
  delay (1000);
  
  if(t.hour == OnHour && t.min == OnMin){
  digitalWrite(extend,HIGH);
  digitalWrite(retract,LOW);    
  Serial.println("Extend");
  }
// Extend actuator if ON time is detected on DS3231
    
  else if(t.hour == OffHour && t.min == OffMin){
  digitalWrite(extend,LOW);
  digitalWrite(retract,HIGH);    
  Serial.println("Retract");
  }
// Retract actuator if OFF time is detected on DS3231
}