#include <MsTimer2.h>
#include <DHT11.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define on_sup_pin1 0 //온습도 센서 1
#define on_sup_pin2 4
#define pir_pin 2 
#define motor_pwm1 11 //1번 모터 pwm
#define motor_pwm2 9 // 2번 모터 pwm
// #define led 3 // pir센서 테스트용 led 필요없음

LiquidCrystal_I2C lcd(0x3F,16,2); //lcd i2c번호 랑 16*2사이즈라는 뜻

DHT11 on_sup1(on_sup_pin1); // 2번 온습도
DHT11 on_sup2(on_sup_pin2); // 4번 온습도

volatile int flag = 0;

void temp_humid(); //온습도
void pir_on(); //pir rising 
void pir_off(); //pir falling
void motor(int motor_speed,volatile int flag);

void setup()
{
  lcd.init();
  //pinMode(pir_pin, INPUT);
  pinMode(12,OUTPUT);
  pinMode(8, OUTPUT);
  //pinMode(led, OUTPUT);
  attachInterrupt(0,pir_on,RISING);
  attachInterrupt(0,pir_off,FALLING);
  Serial.begin(9600);
}
void loop()
{
  int sensor = digitalRead(pir_pin);
  Serial.println(sensor); // 이 두줄은 그냥 확인용 
  
  temp_humid();
  motor(255, flag);
}
