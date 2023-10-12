#include <RTClib.h>

//A global time variable
RTC_DS3231 rtc;

void set(){
  //This function will let you to set the time through serial port
  Serial.print("Enter the Year: ");
  int year = Serial.read();
  Serial.print("Enter the Month: ");
  int month = Serial.read();
  Serial.print("Enter the date: ");
  int date = Serial.read();
  Serial.print("Enter the Hour: ");
  int hour = Serial.read();
  Serial.print("Enter the Minute: ");
  int minute = Serial.read();
  Serial.print("Enter the Seconds: ");
  int seconds = Serial.read();
  //setting the time in this function
  rtc.adjust(DateTime(year, month, date, hour, minute, seconds));
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}
