/*------ Headers to Include ------*/
#include <MsTimer2.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
/*------ Pin Define ------*/
#define TOP_THERMO 7
#define BOTTOM_THERMO 4
#define PIR 2
#define TOP_FAN 11
#define BOTTOM_FAN 10
/*------ Objects ------*/
LiquidCrystal_I2C lcd(0x3F, 16, 2); // LCD address to 0x3F for 16*2 clcd SDA=A4,SCL=A5
//DHT11 TOP_THERMO1(TOP_THERMO1);
//DHT11 TOP_THERMO2(TOP_THERMO2);
/*------ Functions ------*/
void GetTemp();
void GetPir();
void FanCtrl(int top_fan_speed,int bottom_fan_speed);
void LcdCtrl(int air_condition);
void Change_Value_in_Serial();
/*------ Global Variables ------*/
int people;
int top_fan_speed;
int bottom_fan_speed;
int pir_prev;
unsigned int lastBounceTime;

void setup() {
  pinMode(PIR, INPUT);
  Serial.begin(9600);
  lcd.init();
}
void loop() {
  //GetTemp();
  GetPir();
  FanCtrl(top_fan_speed, bottom_fan_speed); 
  Change_Value_in_Serial();
}
