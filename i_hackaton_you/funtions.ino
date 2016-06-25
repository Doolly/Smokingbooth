//void GetTemp() {
//  int err;
//  int err2;
//  float temp, humi;
//  float temp2, humi2; // changed
//  if ( ((err = TOP_THERMO1.read(humi, temp)) == 0) && (err2 = TOP_THERMO2.read(humi2, temp2) == 0) )
//  {
//    //공기 청정 지수 계산
//    int air_condition;
//    LcdCtrl(air_condition);
//  }
//  else
//  {
//    LcdCtrl(-1); //온도값이 들어오지 않은 에러 상황
//  }
//}

void GetPir() {
  int pir_now = digitalRead(PIR);

  if (pir_now != pir_prev)
    lastBounceTime = millis();

  if ((millis() - lastBounceTime) > 5000) {
    if ((pir_now != people) && pir_now == 0)
      people = pir_now; //people = 0
  }
  if (pir_now == 1) {
    people = pir_now; //people = 1
  }
  pir_prev = pir_now;
}

void FanCtrl(int top_fan_speed, int bottom_fan_speed) {
  analogWrite(TOP_FAN, top_fan_speed);
  analogWrite(BOTTOM_FAN, bottom_fan_speed);
}

//void LcdCtrl(int air_condition) {
//  lcd.clear();
//  lcd.backlight();
//  lcd.display();
//  if (air_conditon < 0)
//  {
//    lcd.print("TEMPERATURE ERROR");
//  }
//  else
//  {
//    lcd.print("Air Condition :  ");
//    lcd.print(air_condition);
//  }
//}

String command;
void Change_Value_in_Serial() { //new line
  if (Serial.available()) {
    char c = Serial.read();

    if (c == '\n') {
      String part1;
      String part2;

      part1 = command.substring(0, command.indexOf(" "));
      part2 = command.substring(command.indexOf(" ") + 1);

      if (part1.equalsIgnoreCase("top_fan_speed"))
        top_fan_speed = part2.toInt();

      else if (part1.equalsIgnoreCase("bottom_fan_speed"))
        bottom_fan_speed = part2.toInt();

      command = "";
    }

    else
      command += c;

  }
}
