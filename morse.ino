// C++ code
//
#define LED 13


char Letras[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
String Morse[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
                   ".--", "-..-", "-.--", "--.." };



String mensaje = "Hola Mundo";

void setup() {
  Serial.begin(115200);
  Serial.println(">Mostrando mensaje de inicialización"); /*
  pinMode(LED, OUTPUT);
     delay(1000); // Wait for 1000 millisecond(s)
      digitalWrite(LED, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
     digitalWrite(LED, LOW);
         delay(500); // Wait for 1000 millisecond(s)
      digitalWrite(LED, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
     digitalWrite(LED, LOW);
         delay(500); // Wait for 1000 millisecond(s)
      digitalWrite(LED, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
     digitalWrite(LED, LOW);
      delay(1000);*/
  Serial.println(">Mensaje de inicialización completado");
}

void loop() {
  int espera = 3;
  Serial.println(">Inicia ciclo de mostrado de letras");

  for (int i = 0; i < mensaje.length(); i++) {        ///Se recorre cada caracter del mensaje
    for (int x = 0; x < sizeof(Letras); x++) {        //El caracter se compara con su equivalente en array Letras
      if (toupper(mensaje.charAt(i)) == Letras[x]) {  //Si corresponde a una letra de Letras, entonces se envía el Morse correspondiente a encenderMorse
        Serial.println("Mostrando " + String(Letras[x]) + " " + String(Morse[x]));
        encenderMorse(Morse[x]);
        delay(espera * 1000);  //tres segundos de espera entre cada letra*/
      }
    }
  }
}

void encenderMorse(String morse) {
  int tiempo = 0;
  for (int i = 0; i < morse.length(); i++) {
    if (morse.charAt(i) == '-') {
      tiempo = 3;
    } else if (morse.charAt(i) == '.') {
      tiempo = 1;
    } else if (morse.charAt(i) == ' ') {
      tiempo = 7;
    }


    digitalWrite(LED, HIGH);
    delay((tiempo * 1000) / 2);
    digitalWrite(LED, LOW);
    delay(500);  //Medio segundo entre partes de la misma letra
  }
}
