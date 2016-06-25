#include <DHT11.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  
//
int pin=2;
int pin2=4; //changed
DHT11 dht11(pin); 
DHT11 dht11_2(pin2); // changed

int inputPin = 7; // 센서 시그널핀
int pirState = LOW; // PIR 초기상태
int val = 0; // Signal 입력값

void setup()
{
  lcd.init();
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int err;
  int err2; // changed
  float temp, humi;
  float temp2, humi2; // changed
  if( ((err=dht11.read(humi, temp))==0)&& (err2=dht11_2.read(humi2, temp2) == 0) )
  {
    lcd.backlight();
    lcd.display();
    lcd.print("TEMP :    ");
    lcd.print(temp);
    lcd.setCursor(0,1);
    lcd.print("HUMIDITY :");
    lcd.print(humi);
 
    Serial.print("temp: ");
    Serial.print(temp);
    Serial.print("humi: ");
    Serial.print(humi);
    val = digitalRead(inputPin);
    if(val == HIGH)
    {
      pirState == LOW;
      Serial.println("yes");
    }
    else
    {
      pirState == HIGH;
      Serial.println("NO"); 
    }
    Serial.println();
///////////////////////////////////////changed
    delay(2000);
    lcd.clear();
    lcd.backlight();
    lcd.display();
    lcd.print("TEMP2:    ");
    lcd.print(temp2);
    lcd.setCursor(0,1);
    lcd.print("HUMIDITY2:");
    lcd.print(humi2);
 
    Serial.print("temp: ");
    Serial.print(temp);
    Serial.print("humi: ");
    Serial.print(humi);
    Serial.println();

    val = digitalRead(inputPin);
    if(val == HIGH)
    {
      pirState == LOW;
      Serial.println("yes");
    }
    else
    {
      pirState == HIGH;
      Serial.println("NO"); 
    }
    Serial.println();
  }
  else
  {
    lcd.backlight();
    lcd.display();
    lcd.print("ERROR NO.: ");
    lcd.print(err);
  }
  delay(2000); //10초마다 Refresh
  lcd.clear();
}

