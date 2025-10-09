void setup() {
  // <------------------------------------------------------------------- No hace falta inicializar nada :P
}

void loop() {
#ifdef RGB_BUILTIN // <-------------------------------------------------- Valor predefinido para el LED del ESP32

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

#endif
}
