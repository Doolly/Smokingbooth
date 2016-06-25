void GetTemp(void) {
  top_humidity = int(dht_t.readHumidity()); // Read temperature as Celsius (the default)
  top_temp = int(dht_t.readTemperature());
  bottom_humidity = int(dht_b.readHumidity());
  bottom_temp = int(dht_b.readTemperature());

  if (isnan(top_humidity) || isnan(top_temp)) {
    Serial.println("Failed to read from top DHT sensor!");
    return;
  }
  if (isnan(bottom_humidity) || isnan(bottom_temp)) {
    Serial.println("Failed to read from bottom DHT sensor!");
    return;
  }
  Serial.print("top_temp = " + String(top_temp) + " *C " + "\n");
  Serial.print("bottom_temp = " + String(bottom_temp) + " *C " + "\n");
}

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
