// Definición de pines para Semáforo 1 (Calle 1)
const int s1Rojo = 2;
const int s1Amarillo = 3;
const int s1Verde = 4;

// Definición de pines para Semáforo 2 (Calle 2)
const int s2Rojo = 5;
const int s2Amarillo = 6;
const int s2Verde = 7;

// Definición de pines para Semáforo Peatonal
const int peatRojo = 8;
const int peatVerde = 9;

void setup() {
  // Configurar todos los pines como salidas
  pinMode(s1Rojo, OUTPUT);
  pinMode(s1Amarillo, OUTPUT);
  pinMode(s1Verde, OUTPUT);
  
  pinMode(s2Rojo, OUTPUT);
  pinMode(s2Amarillo, OUTPUT);
  pinMode(s2Verde, OUTPUT);
  
  pinMode(peatRojo, OUTPUT);
  pinMode(peatVerde, OUTPUT);
}

void loop() {
  // --- FASE 1: Calle 1 en VERDE | Calle 2 en ROJO | Peatón en ROJO ---
  digitalWrite(s1Verde, HIGH);
  digitalWrite(s1Amarillo, LOW);
  digitalWrite(s1Rojo, LOW);
  
  digitalWrite(s2Verde, LOW);
  digitalWrite(s2Amarillo, LOW);
  digitalWrite(s2Rojo, HIGH);
  
  digitalWrite(peatVerde, LOW);
  digitalWrite(peatRojo, HIGH);
  delay(5000); // 5 segundos de paso para Calle 1

  // --- FASE 2: Transición Calle 1 a AMARILLO ---
  digitalWrite(s1Verde, LOW);
  digitalWrite(s1Amarillo, HIGH);
  delay(2000); // 2 segundos de precaución

  // --- FASE 3: Calle 1 en ROJO | Calle 2 en VERDE | Peatón en VERDE ---
  digitalWrite(s1Amarillo, LOW);
  digitalWrite(s1Rojo, HIGH);
  
  digitalWrite(s2Rojo, LOW);
  digitalWrite(s2Verde, HIGH);
  
  digitalWrite(peatRojo, LOW);
  digitalWrite(peatVerde, HIGH);
  delay(5000); // 5 segundos de paso para Calle 2 y peatones

  // --- FASE 4: Advertencia de cierre peatonal (Parpadeo) ---
  for (int i = 0; i < 4; i++) {
    digitalWrite(peatVerde, LOW);
    delay(250);
    digitalWrite(peatVerde, HIGH);
    delay(250);
  }

  // --- FASE 5: Transición Calle 2 a AMARILLO y Peatón a ROJO ---
  digitalWrite(peatVerde, LOW);
  digitalWrite(peatRojo, HIGH);
  
  digitalWrite(s2Verde, LOW);
  digitalWrite(s2Amarillo, HIGH);
  delay(2000); // 2 segundos de amarillo para Calle 2
  
  digitalWrite(s2Amarillo, LOW);
  // Vuelve al inicio del ciclo (Se enciende s1Rojo y s1Verde)
}