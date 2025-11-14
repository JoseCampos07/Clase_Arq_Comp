#ifdef RGB_BUILTIN
const int Button1 = 4, Button2 = 5, Button3 = 6;
int buttonState1, buttonState2, buttonState3;

void setup() {
  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP);
  pinMode(Button3, INPUT_PULLUP);

}

void loop() {
  buttonState1 = digitalRead(Button1);
  buttonState2 = digitalRead(Button2);
  buttonState3 = digitalRead(Button3);
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
  for (int i = 0; i < 7; i++){ // <-------------------------------------- Repite 7 veces el código de BlinkRGB
    digitalWrite(RGB_BUILTIN, HIGH);
    delay(500); // <----------------------------------------------------- Tiempo de espera (500 milisegundos)
    digitalWrite(RGB_BUILTIN, LOW);
    delay(500);
    rgbLedWrite(RGB_BUILTIN, RGB_BRIGHTNESS, 0, 0); // <----------------- Enciende el color rojo del LED, verde y azul se apagan con 0
    delay(500);
    rgbLedWrite(RGB_BUILTIN, 0, RGB_BRIGHTNESS, 0); // <----------------- Enciende el color verde del LED, rojo y azul se apagan con 0
    delay(500);
    rgbLedWrite(RGB_BUILTIN, 0, 0, RGB_BRIGHTNESS); // <----------------- Enciende el color azul del LED, rojo y verde se apagan con 0
    delay(500);
    rgbLedWrite(RGB_BUILTIN, 0, 0, 0); // <------------------------------ Apaga los tres colores y, por ende, el LED totalmente
    delay(500);
  }

  delay(500);
}

void SOS(){
  /* S (. . .) */
  for(int i = 0; i < 3; i++){ // <--------------------------------------- Repetir tres veces encendido con espacio corto (tres puntos)
    digitalWrite(RGB_BUILTIN, HIGH); // <-------------------------------- LED blanco encendido
    delay(250); // <----------------------------------------------------- Tiempo de espera (250 milisegundos)
    digitalWrite(RGB_BUILTIN, LOW); // <--------------------------------- LED blanco apagado
    delay(250);
  }

  /* O (_ _ _)*/
  for(int i = 0; i < 3; i++){ // <--------------------------------------- Repetir tres veces encendido con espacio largo (tres rayas)
    digitalWrite(RGB_BUILTIN, HIGH);
    delay(750); // <----------------------------------------------------- Tiempo de espera (750 milisegundos)
    digitalWrite(RGB_BUILTIN, LOW);
    delay(250);
  }

  /* S (. . .) */
  for(int i = 0; i < 3; i++){
    digitalWrite(RGB_BUILTIN, HIGH);
    delay(250);
    digitalWrite(RGB_BUILTIN, LOW);
    delay(250);
  }
  
  delay(1000); // <------------------------------------------------------ Tiempo de espera (1000 milisegundos = 1 segundo)
}

void Pulse(){
  int brightness = 0; // <----------------------------------------------- Variable entera que controlará el brillo de los tres colores

  for(int i = 0; i < 7; i++){ // <--------------------------------------- Repetirá el código del pulso 7 veces
    while(brightness <= 255){ // <--------------------------------------- Mientras el brillo (brightness) sea menor o igual a 255, el brillo aumentará
      rgbLedWrite(RGB_BUILTIN, brightness, brightness, brightness); // <- Enciende el LED con todos los colores al mismo nivel
      delay(10); // <---------------------------------------------------- Tiempo de espera (10 milisegundos)
      brightness ++; // <------------------------------------------------ Aumenta el valor del brillo
    }

    // <----------------------------------------------------------------- Aquí, el brillo del LED ha llegado al máximo

    while(brightness >= 0){ // <----------------------------------------- Mientras el brillo (brightness) sea mayor a 0, el brillo disminuirá
      rgbLedWrite(RGB_BUILTIN, brightness, brightness, brightness);
      delay(10);
      brightness --; // <------------------------------------------------ Disminuye el valor del brillo
    }

    // <----------------------------------------------------------------- Aquí, el brillo del LED ha llegado a 0
  }
}

#endif