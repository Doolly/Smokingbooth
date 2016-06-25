#include <MsTimer2.h>
#include <DHT11.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  
//
int pin=2;  //dht11 
int pin2=4; //dht11
int led = 3; 
DHT11 dht11(pin); // 2번 온습도
DHT11 dht11_2(pin2); // 4번 온습도
int pirPin = 7; // pir 센서 시그널핀
int motor1 = 11; //pwm motor1 

int timer_count =0;

void pir_sensor()
{
  int sensor = digitalRead(pirPin);
  Serial.println(sensor);
  if(sensor == 1)
  {
    digitalWrite(led, HIGH);
  }
  else if(sensor == 0)
  {
    timer_count++;
    if(timer_count > 20)
    {
      digitalWrite(led,LOW);
      timer_count = 0;
    }
  }
}

void setup()
{
  lcd.init();
  pinMode(pirPin, INPUT);
  pinMode(led, OUTPUT);
  MsTimer2::set(50 , pir_sensor);
  MsTimer2::start();
  Serial.begin(9600);
}

void temp_humid()
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

    delay(2000);
    lcd.clear();
    lcd.backlight();
    lcd.display();
    lcd.print("TEMP2:    ");
    lcd.print(temp2);
    lcd.setCursor(0,1);
    lcd.print("HUMIDITY2:");
    lcd.print(humi2);
  }
  else
  {
    lcd.backlight();
    lcd.display();
    lcd.print("ERROR NO.: ");
    lcd.print(err);
  }
  delay(2000); //2초마다 Refresh
  lcd.clear();
}
void loop()
{
  temp_humid();
}

