int lights[8] = {
  3, 4, 5, 6, 7, 8, 9, 10
};

int powerOf(int a, int n);

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < 8; i++) {
    pinMode(lights[i], OUTPUT);
    digitalWrite(lights[i], HIGH);
    delay(100);
    digitalWrite(lights[i], LOW);
  }
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    if (input == "read") {
      Serial.print((int)readChar());
    } else if (input.length() == 1) {
      char symb = input[0];
      writeChar(symb);
      Serial.print("Updated value to ");
      Serial.println(symb);
    }
  }
}

void writeChar(char c) {
  for (int i = 0; i < 8; i++) {
    bool bit = (c >> (7 - i)) & 1;
    digitalWrite(lights[i], bit ? HIGH : LOW);
  }
}
char readChar() {
  char res = 0;
  for (int i = 0; i < 8; i++) {
    int state = digitalRead(lights[i]);
    res |= (state << (7 - i));
  }
  return res;
}
