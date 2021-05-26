#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
#include <EEPROM.h>
#include "GravityTDS.h"
 
#define TdsSensorPin A1
GravityTDS gravityTds;
 #include <OneWire.h>
#include <DallasTemperature.h>
#define USE_ARDUINO_INTERRUPTS true    /
const int SENSOR_PIN = 8; // Arduino pin connected to DS18B20 sensor's DQ pin

OneWire oneWire(SENSOR_PIN);         // setup a oneWire instance
DallasTemperature sensors(&oneWire); // pass oneWire to DallasTemperature library

int temperature = 25,tdsValue = 0;
 
void setup()
{
    sensors.begin();
    Serial.begin(9600);
    lcd.begin(16,2);
    gravityTds.setPin(TdsSensorPin);
    gravityTds.setAref(5.0);  //reference voltage on ADC, default 5.0V on Arduino UNO
    gravityTds.setAdcRange(1024);  //1024 for 10bit ADC;4096 for 12bit ADC
    gravityTds.begin();  //initialization
       lcd.setCursor(0, 0);
        lcd.print("water quality ");
           lcd.setCursor(0, 1);
        lcd.print("monitoring system");
}
 
void loop()
{
  sensors.requestTemperatures();             // send the command to get temperatures
  int tempCelsius = sensors.getTempCByIndex(0);  // read temperature in Celsius

   int sensorValue = analogRead(A0);
  int voltage = sensorValue * (5.0 / 1024.0);

   //temperature = readTemperature();  //add your temperature sensor and read it
    gravityTds.setTemperature(temperature);  // set the temperature and execute temperature compensation
    gravityTds.update();  //sample and calculate
    tdsValue = gravityTds.getTdsValue();  // then get the value

   if(tempCelsius>=20){
  
    Serial.write(tempCelsius);
     lcd.clear();
     lcd.setCursor(0, 0);
        lcd.print("tem: ");
         lcd.print(tempCelsius);
         delay(5000);
   }
     if(voltage<20){
     Serial.write(voltage);
     lcd.clear();
    lcd.setCursor(0, 0);
        lcd.print("turbidity: ");
         lcd.print(voltage);
   delay(5000);
    }
     if(tdsValue >=0){
    Serial.write(tdsValue);
    lcd.clear();
     lcd.clear();
    lcd.setCursor(0, 0);
        lcd.print("tds:");
         lcd.print(tdsValue);
delay(5000);
    }      
}
