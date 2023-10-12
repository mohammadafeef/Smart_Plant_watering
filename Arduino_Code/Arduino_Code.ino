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

      else if(info == '\n'){
        Serial.println(num);
        return num;
      }
    }
  }
}

void set(){
  //This function will let you to set the time through serial port
  Serial.println("Setting the RTC Activated");
  Serial.print("Enter the Year: ");
  int year = SerialreadInt();
  Serial.print("Enter the Month: ");
  int month = SerialreadInt();
  Serial.print("Enter the date: ");
  int date = SerialreadInt();
  Serial.print("Enter the Hour: ");
  int hour = SerialreadInt();
  Serial.print("Enter the Minute: ");
  int minute = SerialreadInt();
  Serial.print("Enter the Seconds: ");
  int seconds = SerialreadInt();
  //setting the time in this function
  rtc.adjust(DateTime(year, month, date, hour, minute, seconds));
  Serial.println("Time set completed!");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //To activate the set function '!' is sent
  if(Serial.available()>0){
    char info = Serial.read();
    if(info == '!'){
      while(Serial.read()!='\n'); // Discard any remaining characters in the input buffer
      set();
    }
  }
  DateTime now = rtc.now();

  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  delay(1000);


}
