void GetTemp()
{
  int err;
  int err2; 
  float temp, humi;
  float temp2, humi2; // changed
  if( ((err=TOP_THERMO1.read(humi, temp))==0)&& (err2=TOP_THERMO2.read(humi2, temp2) == 0) )
  {
    //공기 청정 지수 계산
    int air_condition;
    LcdCtrl(air_condition);
  }
  else 
  {
    LcdCtrl(-1); //온도값이 들어오지 않은 에러 상황
  }
}
int GetPir()
{
  int pir_value  = digitalRead(PIR);
  return pir_value;
}
void FanCtrl(int top, int bottom) //TOP_FAN 11 BOTTOM_FAN 9
{
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  
  analogWrite(TOP_FAN, top);
  analogWrite(BOTTOM_FAN, bottom);
}
void LcdCtrl(int air_condition)
{
    lcd.clear();
    lcd.backlight();
    lcd.display();
    if(air_conditon < 0)
    {
      lcd.print("TEMPERATURE ERROR");
    }
    else
    {
      lcd.print("Air Condition :  ");
      lcd.print(air_condition);
    }
}
