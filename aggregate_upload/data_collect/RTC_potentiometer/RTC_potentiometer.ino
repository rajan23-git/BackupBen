#include <DS1307RTC.h>
#include <Wire.h>
#include <TimeLib.h>
boolean rtc_connected;
unsigned long disconnect_time;
unsigned long time_offline;
tmElements_t currTime;
void setup() {
  // put your setup code here, to run once:
  rtc_connected = true;
  disconnect_time = millis();
  
  
  Serial.begin(9600);
  

 
}



void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0){ 
  
    String timeString = "";  
    if(RTC.read(currTime)){
      if(rtc_connected == false){
      breakTime(makeTime(currTime) + time_offline,currTime);
      RTC.write(currTime);
      rtc_connected = true;
      }
      
      timeString  = timeString + currTime.Hour +":"+currTime.Minute+":"+currTime.Second + " " + currTime.Month +"/" + currTime.Day+"/"+tmYearToCalendar(currTime.Year);
      disconnect_time = millis();
    }
    
    else{
      time_offline = (millis() - disconnect_time)/1000;
      rtc_connected = false;
    }
    
    int msg = Serial.read();
    int sensorValue = analogRead(A0);
    float voltage = sensorValue * 5.0 / 1023.0;



    Serial.println(String(timeString)+","+String(voltage));
  }
}
