#include <Servo.h>

// ==========================================
// SERVOS
// ==========================================

Servo joelhoL;
Servo joelhoR;
Servo pernaL;
Servo pernaR;


// ==========================================
// ULTRASSÔNICO
// ==========================================

const int TRIG = 7;
const int ECHO = 6;


// ==========================================
// PIEZO
// ==========================================

const int PIEZO = 8;


// ==========================================
// FUNÇÃO PARA MOVER OS 4 SERVOS
// ==========================================

void mover(int jl, int jr, int pl, int pr, int tempo) {

  joelhoL.write(jl);
  joelhoR.write(jr);
  pernaL.write(pl);
  pernaR.write(pr);

  delay(tempo);
}


// ==========================================
// MEDIR DISTÂNCIA
// ==========================================

long distancia() {

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  long duracao = pulseIn(ECHO, HIGH, 30000);

  if (duracao == 0) {
    return 400;
  }

  long cm = duracao / 58;

  return cm;
}


// ==========================================
// SOM DE INICIALIZAÇÃO
// ==========================================

void inicio() {

  tone(PIEZO, 500, 150);
  delay(180);

  tone(PIEZO, 700, 150);
  delay(180);

  tone(PIEZO, 900, 200);
  delay(250);
}


// ==========================================
// SOM DE ALERTA
// ==========================================

void alerta() {

  tone(PIEZO, 1000, 120);
  delay(150);

  tone(PIEZO, 700, 120);
  delay(150);

  tone(PIEZO, 1000, 120);
  delay(150);
}


// ==========================================
// SOM DE PERIGO
// ==========================================

void perigo() {

  for (int i = 0; i < 3; i++) {

    tone(PIEZO, 1500, 100);
    delay(130);

    tone(PIEZO, 700, 100);
    delay(130);
  }
}


// ==========================================
// DANÇA NORMAL
// ==========================================

void danca() {

  // Balança para esquerda
  mover(90, 90, 65, 65, 150);

  // Balança para direita
  mover(90, 90, 115, 115, 150);

  // Esquerda
  mover(90, 90, 65, 65, 150);

  // Direita
  mover(90, 90, 115, 115, 150);

  // Joelhos
  mover(110, 70, 90, 90, 150);
  mover(70, 110, 90, 90, 150);

  // Agacha
  mover(115, 115, 90, 90, 180);

  // Levanta
  mover(90, 90, 90, 90, 180);

  // Pose
  mover(75, 75, 110, 70, 200);

  mover(90, 90, 90, 90, 150);
}


// ==========================================
// DANÇA DE ALERTA
// ==========================================

void dancaAlerta() {

  alerta();

  // Olha para um lado
  mover(90, 90, 65, 65, 200);

  // Olha para o outro
  mover(90, 90, 115, 115, 200);

  // Agacha
  mover(115, 115, 90, 90, 200);

  // Levanta rapidamente
  mover(75, 75, 90, 90, 200);

  // Centro
  mover(90, 90, 90, 90, 150);
}


// ==========================================
// REAÇÃO AO OBSTÁCULO
// ==========================================

void escapar() {

  perigo();

  // ======================================
  // RECULA
  // ======================================

  mover(105, 75, 105, 75, 200);
  mover(90, 90, 90, 90, 150);

  // ======================================
  // GIRA PARA UM LADO
  // ======================================

  mover(90, 90, 60, 120, 250);

  mover(90, 90, 120, 60, 250);

  mover(90, 90, 60, 120, 250);

  mover(90, 90, 120, 60, 250);

  // ======================================
  // CENTRO
  // ======================================

  mover(90, 90, 90, 90, 300);
}


// ==========================================
// SETUP
// ==========================================

void setup() {

  // Servos
  joelhoL.attach(2);
  joelhoR.attach(3);
  pernaL.attach(5);
  pernaR.attach(4);

  // Ultrassônico
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  // Piezo
  pinMode(PIEZO, OUTPUT);

  // Posição inicial
  mover(90, 90, 90, 90, 500);

  // Som de inicialização
  inicio();
}


// ==========================================
// LOOP PRINCIPAL
// ==========================================

void loop() {

  long d = distancia();

  // ========================================
  // OBSTÁCULO MUITO PERTO
  // ========================================

  if (d < 20) {

    escapar();

  }

  // ========================================
  // OBSTÁCULO A MÉDIA DISTÂNCIA
  // ========================================

  else if (d < 40) {

    dancaAlerta();

  }

  // ========================================
  // CAMINHO LIVRE
  // ========================================

  else {

    danca();

  }

  delay(100);
}
