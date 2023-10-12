#include <RTClib.h>

//A global time variable
RTC_DS3231 rtc;

int SerialreadInt(){
  int num = 0; 
  while(1){
    if(Serial.available()){

      char info = Serial.read();

      if(info>='0'&&info<='9')
        num = (num*10)+(info-'0');

      else if(info == ' ')
        return num;
    }
  }
}

void set(){
  //This function will let you to set the time through serial port
  Serial.println("Setting the RTC Activated");
  Serial.print("\nEnter the Year: ");
  int year = SerialreadInt();
  Serial.print("\nEnter the Month: ");
  int month = SerialreadInt();
  Serial.print("\nEnter the date: ");
  int date = SerialreadInt();
  Serial.print("\nEnter the Hour: ");
  int hour = SerialreadInt();
  Serial.print("\nEnter the Minute: ");
  int minute = SerialreadInt();
  Serial.print("\nEnter the Seconds: ");
  int seconds = SerialreadInt();
  //setting the time in this function
  rtc.adjust(DateTime(year, month, date, hour, minute, seconds));
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //To activate the set function '!' is sent
  if(Serial.available()>0){
    char info = Serial.read();
    if(info == '!')
      set();
  }


}
