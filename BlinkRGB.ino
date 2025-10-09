void setup() {
  // <------------------------------------------------------------------- No hace falta inicializar nada :P
}

void loop() {
#ifdef RGB_BUILTIN // <-------------------------------------------------- Valor predefinido para el LED del ESP32
  digitalWrite(RGB_BUILTIN, HIGH); // <---------------------------------- LED blanco encendido
  delay(1000); // <------------------------------------------------------ Tiempo de espera (1000 milisegundos)
  digitalWrite(RGB_BUILTIN, LOW); // <----------------------------------- LED blanco apagado
  delay(1000);

  rgbLedWrite(RGB_BUILTIN, RGB_BRIGHTNESS, 0, 0); // <------------------- Enciende el color rojo del LED, verde y azul se apagan con 0
  delay(1000);
  rgbLedWrite(RGB_BUILTIN, 0, RGB_BRIGHTNESS, 0); // <------------------- Enciende el color verde del LED, rojo y azul se apagan con 0
  delay(1000);
  rgbLedWrite(RGB_BUILTIN, 0, 0, RGB_BRIGHTNESS); // <------------------- Enciende el color azul del LED, rojo y verde se apagan con 0
  delay(1000);
  rgbLedWrite(RGB_BUILTIN, 0, 0, 0); // <-------------------------------- Apaga los tres colores y, por ende, el LED totalmente
  delay(1000);
#endif
}
