#ifdef RGB_BUILTIN
const int Button1 = 4, Button2 = 5, Button3 = 6, Button4 = 7;
int buttonState1, buttonState2, buttonState3, buttonState4;
int id_signal = 0, id_loop = 1, id_step = 1, id_brightness = 0;

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
    BlinkRGB(1, 1);
    buttonState4 = HIGH;
  }

  if(buttonState2 == HIGH){
    digitalWrite(RGB_BUILTIN, LOW);
  } else {
    SOS(1, 1);
    buttonState4 = HIGH;
  }

  if(buttonState3 == HIGH){
    digitalWrite(RGB_BUILTIN, LOW);
  } else {
    Pulse(1, 1, 0);
    buttonState4 = HIGH;
  }

  buttonState4 = digitalRead(Button4);
  if(buttonState4 == HIGH){
    digitalWrite(RGB_BUILTIN, LOW);
  } else {
    Pause();
  }
}

void BlinkRGB(int actual_loop, int actual_step){
  delay(1000);
  int running_loop = actual_loop;
  int running_step = actual_step;
  int counter = 0;
  bool breakCycle = false;

  while(running_loop <= 7){
    delay(100);

    if(running_step <= 1){
      digitalWrite(RGB_BUILTIN, HIGH); // ======================================== Step 1
    
      while(counter < 500){
        buttonState1 = digitalRead(Button1);
        buttonState2 = digitalRead(Button2);
        buttonState3 = digitalRead(Button3);
        buttonState4 = digitalRead(Button4);
        if(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH && buttonState4 == HIGH){
          delay(1);
          counter++;
        } else {
          delay(1000);
          if(buttonState1 == LOW){
            BlinkRGB(1, 1);
          } else if(buttonState2 == LOW){
            SOS(1, 1);
          } else if(buttonState3 == LOW){
            Pulse(1, 1, 0);
          } else {
            running_step = 1;
          }
          breakCycle = true;
          break;
        }
      }
      if(breakCycle == true){
        break;
      }
      counter = 0;
    }

    if(running_step <= 2){
      digitalWrite(RGB_BUILTIN, LOW); // ============================================= Step 2
    
      while(counter < 500){
        buttonState1 = digitalRead(Button1);
        buttonState2 = digitalRead(Button2);
        buttonState3 = digitalRead(Button3);
        buttonState4 = digitalRead(Button4);
        if(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH && buttonState4 == HIGH){
          delay(1);
          counter++;
        } else {
          delay(1000);
          if(buttonState1 == LOW){
            BlinkRGB(1, 1);
          } else if(buttonState2 == LOW){
            SOS(1, 1);
          } else if(buttonState3 == LOW){
            Pulse(1, 1, 0);
          } else {
            running_step = 2;
          }
          breakCycle = true;
          break;
        }
      }
      if(breakCycle == true){
        break;
      }
      counter = 0;
    }

    if(running_step <= 3){
      rgbLedWrite(RGB_BUILTIN, RGB_BRIGHTNESS, 0, 0); // ================================= Step 3
    
      while(counter < 500){
        buttonState1 = digitalRead(Button1);
        buttonState2 = digitalRead(Button2);
        buttonState3 = digitalRead(Button3);
        buttonState4 = digitalRead(Button4);
        if(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH && buttonState4 == HIGH){
          delay(1);
          counter++;
        } else {
          delay(1000);
          if(buttonState1 == LOW){
            BlinkRGB(1, 1);
          } else if(buttonState2 == LOW){
            SOS(1, 1);
          } else if(buttonState3 == LOW){
            Pulse(1, 1, 0);
          } else {
            running_step = 3;
          }
          breakCycle = true;
          break;
        }
      }
      if(breakCycle == true){
        break;
      }
      counter = 0;
    }
    
    if(running_step <= 4){
      rgbLedWrite(RGB_BUILTIN, 0, RGB_BRIGHTNESS, 0); // ========================================= Step 4
    
      while(counter < 500){
        buttonState1 = digitalRead(Button1);
        buttonState2 = digitalRead(Button2);
        buttonState3 = digitalRead(Button3);
        buttonState4 = digitalRead(Button4);
        if(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH && buttonState4 == HIGH){
          delay(1);
          counter++;
        } else {
          delay(1000);
          if(buttonState1 == LOW){
            BlinkRGB(1, 1);
          } else if(buttonState2 == LOW){
            SOS(1, 1);
          } else if(buttonState3 == LOW){
            Pulse(1, 1, 0);
          } else {
            running_step = 4;
          }
          breakCycle = true;
          break;
        }
      }
      if(breakCycle == true){
        break;
      }
      counter = 0;
    }

    if(running_step <= 5){
      rgbLedWrite(RGB_BUILTIN, 0, 0, RGB_BRIGHTNESS); // ========================================= Step 5
    
      while(counter < 500){
        buttonState1 = digitalRead(Button1);
        buttonState2 = digitalRead(Button2);
        buttonState3 = digitalRead(Button3);
        buttonState4 = digitalRead(Button4);
        if(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH && buttonState4 == HIGH){
          delay(1);
          counter++;
        } else {
          delay(1000);
          if(buttonState1 == LOW){
            BlinkRGB(1, 1);
          } else if(buttonState2 == LOW){
            SOS(1, 1);
          } else if(buttonState3 == LOW){
            Pulse(1, 1, 0);
          } else {
            running_step = 5;
          }
          breakCycle = true;
          break;
        }
      }
      if(breakCycle == true){
        break;
      }
      counter = 0;
    }

    if(running_step <= 6){
      rgbLedWrite(RGB_BUILTIN, 0, 0, 0); // ================================================ Step 6
    
      while(counter < 500){
        buttonState1 = digitalRead(Button1);
        buttonState2 = digitalRead(Button2);
        buttonState3 = digitalRead(Button3);
        buttonState4 = digitalRead(Button4);
        if(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH && buttonState4 == HIGH){
          delay(1);
          counter++;
        } else {
          delay(1000);
          if(buttonState1 == LOW){
            BlinkRGB(1, 1);
          } else if(buttonState2 == LOW){
            SOS(1, 1);
          } else if(buttonState3 == LOW){
            Pulse(1, 1, 0);
          } else {
            running_step = 6;
          }
          breakCycle = true;
          break;
        }
      }
      if(breakCycle == true){
        break;
      }
    }

    running_step = 1;
    running_loop++;
  }

  if(breakCycle == false){
    id_signal = 0;
    id_loop = 1;
    id_step = 1;
  } else if(id_signal == 0 && buttonState4 == LOW){
    id_signal = 1;
    id_loop = running_loop;
    id_step = running_step;
  } else {
    Pause();
  }
}

void SOS(int actual_loop, int actual_step){
  delay(1000);
  int running_loop = actual_loop;
  int running_step = actual_step;
  int counter = 0;
  bool breakCycle = false;

  /* S (. . .) */
  while(running_loop <= 3){
    delay(100);

    if(running_step <= 1){
      digitalWrite(RGB_BUILTIN, HIGH); // ================================================== Step 1
    
      while(counter < 250){
        buttonState1 = digitalRead(Button1);
        buttonState2 = digitalRead(Button2);
        buttonState3 = digitalRead(Button3);
        buttonState4 = digitalRead(Button4);
        if(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH && buttonState4 == HIGH){
          delay(1);
          counter++;
        } else {
          delay(1000);
          if(buttonState1 == LOW){
            BlinkRGB(1, 1);
          } else if(buttonState2 == LOW){
            SOS(1, 1);
          } else if(buttonState3 == LOW){
            Pulse(1, 1, 0);
          } else {
            running_step = 1;
          }
          breakCycle = true;
          break;
        }
      }
      if(breakCycle == true){
        break;
      }
      counter = 0;
    }
    
    if(running_step <= 2){
      digitalWrite(RGB_BUILTIN, LOW); // ================================================= Step 2

      while(counter < 250){
        buttonState1 = digitalRead(Button1);
        buttonState2 = digitalRead(Button2);
        buttonState3 = digitalRead(Button3);
        buttonState4 = digitalRead(Button4);
        if(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH && buttonState4 == HIGH){
          delay(1);
          counter++;
        } else {
          delay(1000);
          if(buttonState1 == LOW){
            BlinkRGB(1, 1);
          } else if(buttonState2 == LOW){
            SOS(1, 1);
          } else if(buttonState3 == LOW){
            Pulse(1, 1, 0);
          } else {
            running_step = 2;
          }
          breakCycle = true;
          break;
        }
      }
      if(breakCycle == true){
        break;
      }
      counter = 0;
    }
    running_loop++;
  }

  if(breakCycle == false){
    /* O (_ _ _)*/
    while(running_loop <= 6){
      
      if(running_step <= 3){
        digitalWrite(RGB_BUILTIN, HIGH); // ================================================== Step 3
      
        while(counter < 750){
          buttonState1 = digitalRead(Button1);
          buttonState2 = digitalRead(Button2);
          buttonState3 = digitalRead(Button3);
          buttonState4 = digitalRead(Button4);
          if(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH && buttonState4 == HIGH){
            delay(1);
            counter++;
          } else {
            delay(1000);
            if(buttonState1 == LOW){
              BlinkRGB(1, 1);
            } else if(buttonState2 == LOW){
              SOS(1, 1);
            } else if(buttonState3 == LOW){
              Pulse(1, 1, 0);
            } else {
              running_step = 3;
            }
            breakCycle = true;
            break;
          }
        }
        if(breakCycle == true){
          break;
        }
        counter = 0;
      }

      if(running_step <= 4){
        digitalWrite(RGB_BUILTIN, LOW); // ====================================================== Step 4
      
        while(counter < 250){
          buttonState1 = digitalRead(Button1);
          buttonState2 = digitalRead(Button2);
          buttonState3 = digitalRead(Button3);
          buttonState4 = digitalRead(Button4);
          if(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH && buttonState4 == HIGH){
            delay(1);
            counter++;
          } else {
            delay(1000);
            if(buttonState1 == LOW){
              BlinkRGB(1, 1);
            } else if(buttonState2 == LOW){
              SOS(1, 1);
            } else if(buttonState3 == LOW){
              Pulse(1, 1, 0);
            } else {
              running_step = 4;
            }
            breakCycle = true;
            break;
          }
        }
        if(breakCycle == true){
          break;
        }
        counter = 0;
      }
      running_loop++;
    }

    if(breakCycle == false){
      /* S (. . .) */
      while(running_loop <= 9){
        
        if(running_step <= 5){
          digitalWrite(RGB_BUILTIN, HIGH); // ============================================== Step 5

          while(counter < 250){
            buttonState1 = digitalRead(Button1);
            buttonState2 = digitalRead(Button2);
            buttonState3 = digitalRead(Button3);
            buttonState4 = digitalRead(Button4);
            if(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH && buttonState4 == HIGH){
              delay(1);
              counter++;
            } else {
              delay(1000);
              if(buttonState1 == LOW){
                BlinkRGB(1, 1);
              } else if(buttonState2 == LOW){
                SOS(1, 1);
              } else if(buttonState3 == LOW){
                Pulse(1, 1, 0);
              } else {
                running_step = 5;
              }
              breakCycle = true;
              break;
            }
          }
          if(breakCycle == true){
            break;
          }
          counter = 0;
        }

        if(running_step <= 6){
          digitalWrite(RGB_BUILTIN, LOW); // ==================================================== Step 6
        
          while(counter < 250){
            buttonState1 = digitalRead(Button1);
            buttonState2 = digitalRead(Button2);
            buttonState3 = digitalRead(Button3);
            buttonState4 = digitalRead(Button4);
            if(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH && buttonState4 == HIGH){
              delay(1);
              counter++;
            } else {
              delay(1000);
              if(buttonState1 == LOW){
                BlinkRGB(1, 1);
              } else if(buttonState2 == LOW){
                SOS(1, 1);
              } else if(buttonState3 == LOW){
                Pulse(1, 1, 0);
              } else {
                running_step = 6;
              }
              breakCycle = true;
              break;
            }
          }
          if(breakCycle == true){
            break;
          }
          counter = 0;
        }
        running_loop++;
      }
    }
  }

  if(breakCycle == false){
    id_signal = 0;
    id_loop = 1;
    id_step = 1;
  } else if(id_signal == 0 && buttonState4 == LOW){
    id_signal = 2;
    id_loop = running_loop;
    id_step = running_step;
  } else {
    Pause();
  }
}

void Pulse(int actual_loop, int actual_step, int actual_brightness){
  delay(1000);
  int running_loop = actual_loop;
  int running_step = actual_step;
  int brightness = actual_brightness;
  int counter = 0;
  bool breakCycle = false;

  while(running_loop <= 7){
    
    if(running_step <= 1){
      while(brightness <= 255){ // ================================================================= Step 1
        rgbLedWrite(RGB_BUILTIN, brightness, brightness, brightness);
        
        while(counter < 10){
          buttonState1 = digitalRead(Button1);
          buttonState2 = digitalRead(Button2);
          buttonState3 = digitalRead(Button3);
          buttonState4 = digitalRead(Button4);
          if(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH && buttonState4 == HIGH){
            delay(1);
            counter++;
          } else {
            delay(1000);
            if(buttonState1 == LOW){
              BlinkRGB(1, 1);
            } else if(buttonState2 == LOW){
              SOS(1, 1);
            } else if(buttonState3 == LOW){
              Pulse(1, 1, 0);
            } else {
              running_step = 1;
            }
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
    }

    if(breakCycle == true){
      break;
    } else {
      
      if(running_step <= 2){
        while(brightness >= 0){ // ================================================================= Step 2
          rgbLedWrite(RGB_BUILTIN, brightness, brightness, brightness);
          
          while(counter < 10){
            buttonState1 = digitalRead(Button1);
            buttonState2 = digitalRead(Button2);
            buttonState3 = digitalRead(Button3);
            buttonState4 = digitalRead(Button4);
            if(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH && buttonState4 == HIGH){
              delay(1);
              counter++;
            } else {
              delay(1000);
              if(buttonState1 == LOW){
                BlinkRGB(1, 1);
              } else if(buttonState2 == LOW){
                SOS(1, 1);
              } else if(buttonState3 == LOW){
                Pulse(1, 1, 0);
              } else {
                running_step = 2;
              }
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
        if(running_step == 2){
          running_step = 1;
        }
      }
    }
    if(breakCycle == true){
      break;
    }

    running_loop++;
  }

  if(breakCycle == false){
    id_signal = 0;
    id_loop = 1;
    id_step = 1;
  } else if(id_signal == 0 && buttonState4 == LOW){
    id_signal = 3;
    id_loop = running_loop;
    id_step = running_step;
    id_brightness = brightness;
  } else {
    Pause();
  }
}

void Pause(){
  delay(1000);

  switch(id_signal){
    case 1: BlinkRGB(id_loop, id_step);break;

    case 2: SOS(id_loop, id_step); break;

    case 3: Pulse(id_loop, id_step, id_brightness); break;
    
    default: digitalWrite(RGB_BUILTIN, LOW); break;
  }
}

#endif