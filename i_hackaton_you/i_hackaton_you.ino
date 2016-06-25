#include <MsTimer2.h>
#include <DHT11.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TOP_THERMO 7
#define BOTTOM_THERMO 4
#define PIR 2
#define TOP_FAN 11
#define BOTTOM_FAN 10

LiquidCrystal_I2C lcd(0x3F, 16, 2); //lcd init
DHT11 TOP_THERMO1(TOP_THERMO1);
DHT11 TOP_THERMO2(TOP_THERMO2);

void GetTemp();
int GetPir();
void FanCtrl(int top, int bottom);

void LcdCtrl(int air_condition);
int pir_how_to;
//volatile int pir_flag = 0; 인터럽트 안씀

void setup() {
//  attachInterrupt(0, GetPir, RISING); 인터럽트 안씀
  pinMode(PIR, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  lcd.init();
}
void loop() {
  int sensor = digitalRead(pir_pin);
  Serial.println(sensor); // 이 두줄은 그냥 확인용
  GetTemp();
  GetPir();
  FanCtrl(int top, int bottom); // pir 이란 normalize 잡아야 함
}
