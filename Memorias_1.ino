#ifdef RGB_BUILTIN

const int Buttons[7] = {4, 5, 6, 7, 15, 16, 17};
const int LEDs[6] = {1, 2, 42, 41, 40, 39};
int buttonStates[7];
int MineSweeper[6] = {0, 0, 0, 0, 0, 0};
int Attempts[2];

void setup() {
  pinMode(Buttons[0], INPUT_PULLUP);
  pinMode(Buttons[1], INPUT_PULLUP);
  pinMode(Buttons[2], INPUT_PULLUP);
  pinMode(Buttons[3], INPUT_PULLUP);
  pinMode(Buttons[4], INPUT_PULLUP);
  pinMode(Buttons[5], INPUT_PULLUP);
  pinMode(Buttons[6], INPUT_PULLUP);

  pinMode(LEDs[0], OUTPUT);
  pinMode(LEDs[1], OUTPUT);
  pinMode(LEDs[2], OUTPUT);
  pinMode(LEDs[3], OUTPUT);
  pinMode(LEDs[4], OUTPUT);
  pinMode(LEDs[5], OUTPUT);

  Reset();
}

void loop() {
  buttonStates[0] = digitalRead(Buttons[0]);
  buttonStates[1] = digitalRead(Buttons[1]);
  buttonStates[2] = digitalRead(Buttons[2]);
  buttonStates[3] = digitalRead(Buttons[3]);
  buttonStates[4] = digitalRead(Buttons[4]);
  buttonStates[5] = digitalRead(Buttons[5]);
  buttonStates[6] = digitalRead(Buttons[6]);

  if(buttonStates[0] == LOW){
    Sweep(0, 1);
  } else if(buttonStates[1] == LOW){
    Sweep(1, 2);
  } else if(buttonStates[2] == LOW){
    Sweep(2, 42);
  } else if(buttonStates[3] == LOW){
    Sweep(3, 41);
  } else if(buttonStates[4] == LOW){
    Sweep(4, 40);
  } else if(buttonStates[5] == LOW){
    Sweep(5, 39);
  } else if(buttonStates[6] == LOW){
    Reset();
  }
}

void Reset(){
  for(int i = 0; i < 6; i++){
    digitalWrite(LEDs[i], HIGH);
    delay(75);
    digitalWrite(LEDs[i], LOW);
    delay(75);
  }

  for(int i = 5; i > -1; i--){
    digitalWrite(LEDs[i], HIGH);
    delay(75);
    digitalWrite(LEDs[i], LOW);
    delay(75);
  }

  int mine = random(5);
  MineSweeper[mine] = 1;

  for(int i = 0; i < 3; i++){
    Attempts[i] = 0;
  }
}

void Sweep(int buttonPressed, int LEDUsed){
  delay(1000);

  if(MineSweeper[buttonPressed] == 1){
    Win(buttonPressed);
  } else if(Attempts[0] != 0 && Attempts[1] != 0){
    GameOver();
  } else {
    for(int i = 0; i < 2; i++){
      if(Attempts[i] != LEDUsed && Attempts[i] == 0){
        Attempts[i] = LEDUsed;
        break;
      }
    }
  }
}

void Win(int buttonPressed){
  
  digitalWrite(LEDs[buttonPressed], HIGH);

  for(int i = 0; i < 3; i++){
    rgbLedWrite(RGB_BUILTIN, 0, 200, 0);
    delay(250);
    rgbLedWrite(RGB_BUILTIN, 0, 0, 0);
    delay(250);
  }

  digitalWrite(LEDs[buttonPressed], LOW);

  Reset();
}

void GameOver(){
  for(int i = 0; i < 3; i++){
    rgbLedWrite(RGB_BUILTIN, 200, 0, 0);
    delay(250);
    rgbLedWrite(RGB_BUILTIN, 0, 0, 0);
    delay(250);
  }

  Reset();
}
#endif