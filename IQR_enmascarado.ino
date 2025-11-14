#ifdef RGB_BUILTIN
const int Button1 = 4, Button2 = 5, Button3 = 6, Button4 = 7;
int buttonState1, buttonState2, buttonState3, buttonState4;

void setup() {
  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP);
  pinMode(Button3, INPUT_PULLUP);
  pinMode(Button4, INPUT_PULLUP);
}

void loop() {
  buttonState1 = digitalRead(Button1);
  buttonState2 = digitalRead(Button2);
  buttonState3 = digitalRead(Button3);
  buttonState4 = digitalRead(Button4);

  if(buttonState1 == HIGH){
    digitalWrite(RGB_BUILTIN, LOW);
  } else {
    BlinkRGB();
  }

  if(buttonState2 == HIGH){
    digitalWrite(RGB_BUILTIN, LOW);
  } else {
    SOS();
  }

  if(buttonState3 == HIGH){
    digitalWrite(RGB_BUILTIN, LOW);
  } else {
    Pulse();
  }
}

void BlinkRGB(){
  int counter = 0;
  bool breakCycle = false;

  for (int i = 0; i < 7; i++){
    delay(100);

    digitalWrite(RGB_BUILTIN, HIGH);
    
    while(counter < 500){
      buttonState4 = digitalRead(Button4);
      if(buttonState4 == HIGH){
        delay(1);
        counter++;
      } else {
        breakCycle = true;
        break;
      }
    }
    if(breakCycle == true){
      break;
    }
    counter = 0;

    digitalWrite(RGB_BUILTIN, LOW);
    
    while(counter < 500){
      buttonState4 = digitalRead(Button4);
      if(buttonState4 == HIGH){
        delay(1);
        counter++;
      } else {
        breakCycle = true;
        break;
      }
    }
    if(breakCycle == true){
      break;
    }
    counter = 0;

    rgbLedWrite(RGB_BUILTIN, RGB_BRIGHTNESS, 0, 0);
    
    while(counter < 500){
      buttonState4 = digitalRead(Button4);
      if(buttonState4 == HIGH){
        delay(1);
        counter++;
      } else {
        breakCycle = true;
        break;
      }
    }
    if(breakCycle == true){
      break;
    }
    counter = 0;
    
    rgbLedWrite(RGB_BUILTIN, 0, RGB_BRIGHTNESS, 0);
    
    while(counter < 500){
      buttonState4 = digitalRead(Button4);
      if(buttonState4 == HIGH){
        delay(1);
        counter++;
      } else {
        breakCycle = true;
        break;
      }
    }
    if(breakCycle == true){
      break;
    }
    counter = 0;

    rgbLedWrite(RGB_BUILTIN, 0, 0, RGB_BRIGHTNESS);
    
    while(counter < 500){
      buttonState4 = digitalRead(Button4);
      if(buttonState4 == HIGH){
        delay(1);
        counter++;
      } else {
        breakCycle = true;
        break;
      }
    }
    if(breakCycle == true){
      break;
    }
    counter = 0;

    rgbLedWrite(RGB_BUILTIN, 0, 0, 0);
    
    while(counter < 500){
      buttonState4 = digitalRead(Button4);
      if(buttonState4 == HIGH){
        delay(1);
        counter++;
      } else {
        breakCycle = true;
        break;
      }
    }
    if(breakCycle == true){
      break;
    }
  }
}

void SOS(){
  int counter = 0;
  bool breakCycle = false;

  /* S (. . .) */
  for(int i = 0; i < 3; i++){
    delay(100);

    digitalWrite(RGB_BUILTIN, HIGH);
    
    while(counter < 250){
      buttonState4 = digitalRead(Button4);
      if(buttonState4 == HIGH){
        delay(1);
        counter++;
      } else {
        breakCycle = true;
        break;
      }
    }
    if(breakCycle == true){
      break;
    }
    counter = 0;
    
    digitalWrite(RGB_BUILTIN, LOW);

    while(counter < 250){
      buttonState4 = digitalRead(Button4);
      if(buttonState4 == HIGH){
        delay(1);
        counter++;
      } else {
        breakCycle = true;
        break;
      }
    }
    if(breakCycle == true){
      break;
    }
    counter = 0;
  }

  if(breakCycle == false){
    /* O (_ _ _)*/
    for(int i = 0; i < 3; i++){
      digitalWrite(RGB_BUILTIN, HIGH);
      
      while(counter < 750){
        buttonState4 = digitalRead(Button4);
        if(buttonState4 == HIGH){
          delay(1);
          counter++;
        } else {
          breakCycle = true;
          break;
        }
      }
      if(breakCycle == true){
        break;
      }
      counter = 0;

      digitalWrite(RGB_BUILTIN, LOW);
      
      while(counter < 250){
        buttonState4 = digitalRead(Button4);
        if(buttonState4 == HIGH){
          delay(1);
          counter++;
        } else {
          breakCycle = true;
          break;
        }
      }
      if(breakCycle == true){
        break;
      }
      counter = 0;
    }

    if(breakCycle == false){
      /* S (. . .) */
      for(int i = 0; i < 3; i++){
        digitalWrite(RGB_BUILTIN, HIGH);

        while(counter < 250){
          buttonState4 = digitalRead(Button4);
          if(buttonState4 == HIGH){
            delay(1);
            counter++;
          } else {
            breakCycle = true;
            break;
          }
        }
        if(breakCycle == true){
          break;
        }
        counter = 0;

        digitalWrite(RGB_BUILTIN, LOW);
        
        while(counter < 250){
          buttonState4 = digitalRead(Button4);
          if(buttonState4 == HIGH){
            delay(1);
            counter++;
          } else {
            breakCycle = true;
            break;
          }
        }
        if(breakCycle == true){
          break;
        }
        counter = 0;
      }
    }
  }
}

void Pulse(){
  int brightness = 0, counter = 0;
  bool breakCycle = false;

  for(int i = 0; i < 7; i++){
    while(brightness <= 255){
      rgbLedWrite(RGB_BUILTIN, brightness, brightness, brightness);
      
      while(counter < 10){
        buttonState4 = digitalRead(Button4);
        if(buttonState4 == HIGH){
          delay(1);
          counter++;
        } else {
          breakCycle = true;
          break;
        }
      }
      if(breakCycle == true){
        break;
      }
      counter = 0;

      brightness ++;
    }

    if(breakCycle == true){
      break;
    } else {
      while(brightness >= 0){
        rgbLedWrite(RGB_BUILTIN, brightness, brightness, brightness);
        
        while(counter < 10){
          buttonState4 = digitalRead(Button4);
          if(buttonState4 == HIGH){
            delay(1);
            counter++;
          } else {
            breakCycle = true;
            break;
          }
        }
        if(breakCycle == true){
          break;
        }
        counter = 0;

        brightness --;
      }
    }

    if(breakCycle == true){
      break;
    }
  }
}

#endif