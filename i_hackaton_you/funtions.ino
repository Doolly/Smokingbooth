void temp_humid()
{
  int err;
  int err2; // changed
  float temp, humi;
  float temp2, humi2; // changed
  if( ((err=on_sup1.read(humi, temp))==0)&& (err2=on_sup2.read(humi2, temp2) == 0) )
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
void motor(int motor_speed, volatile int flag)
{
  if(flag == 0) //사람 없음 풀가동
  {
    analogWrite(motor_pwm1, 255);
    analogWrite(motor_pwm2, 255);
  }
  else if(flag == 1) //사람 없음 
  {
  analogWrite(11, (motor_speed / 1) * 255); //온도 습도로 모터 속도를 normalize
  }
}
void pir_on()
{
    flag = 1; //volatile int flag = 0(초기값은 0)
    lcd.clear();
    lcd.backlight();
    lcd.display();
    lcd.print("hello smoker");
}
void pir_off()
{
  if(flag == 1)
  {
    lcd.clear();
    lcd.backlight();
    lcd.display();
    lcd.print("bye smoker");
    flag = 0;
  }
}

