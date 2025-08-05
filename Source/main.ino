#include <LiquidCrystal.h>

int sensorPin = 0;
const int celsius = 35;

// initialize the library with the numbers of the interface pins
// REGISTER SELECT PIN,ENABLE PIN,D4 PIN,D5 PIN, D6 PIN, D7 PIN
LiquidCrystal lcd(3, 4, 8, 9, 10, 11);

void setup() {
  // set up the LCD's number of columns and rows:
  pinMode(A0, INPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
}
 
void loop() {

  // Getting the voltage reading from the temperature sensor
  int reading = analogRead(sensorPin);

  // Converting that reading to voltage, for 3.3v arduino use 3.3
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  float temperatureC = (voltage - 0.5) * 100 ;   //converting from 10 mv per degree with 500 mV offset
                                                //to degrees ((voltage - 500mV) times 100)
  Serial.println(temperatureC);
  if (temperatureC >= 35) {
    digitalWrite(7, HIGH);
  }
  
  else {
    digitalWrite(7, LOW);
    
  }
  
  // set the cursor to column 0, line 1
  lcd.print(temperatureC);//print temperature
  lcd.setCursor(0, 0);// set the cursor to column 0, line1
  delay(1000);
  lcd.clear();
}
