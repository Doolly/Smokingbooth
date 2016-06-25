#include <MsTimer2.h>
#include <DHT11.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TOP_THERMO 10
#define BOTTOM_THERMO 4
#define PIR 2
#define TOP_FAN 11
#define BOTTOM_FAN 9

LiquidCrystal_I2C lcd(0x3F, 16, 2); //lcd init
DHT11 TOP_THERMO1(TOP_THERMO1);
DHT11 TOP_THERMO2(TOP_THERMO2);

int GetTemp();
int GetPir();
void FanCtrl(int top, int bottom);

volatile int pir_flag = 0;

void setup() {
  attachInterrupt(0, GetPir, RISING);
  Serial.begin(9600);
  lcd.init();
}
void loop() {
  int sensor = digitalRead(pir_pin);
  Serial.println(sensor); // 이 두줄은 그냥 확인용

  temp_humid();
  motor(255, flag);
}
