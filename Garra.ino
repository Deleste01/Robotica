#include <Servo.h>

Servo ombro;
Servo cintura;
Servo cotovelo;
Servo garra;

// Posições atuais dos servos
int posOmbro = 90;
int posCintura = 90;
int posCotovelo = 90;
int posGarra = 90;

void setup() {

  ombro.attach(2);
  cintura.attach(3);
  cotovelo.attach(4);
  garra.attach(5);

  // Posição inicial
  ombro.write(posOmbro);
  cintura.write(posCintura);
  cotovelo.write(posCotovelo);
  garra.write(posGarra);

  delay(1000);
}

void loop() {
  
  executarMovimentos();
  
  direita(20);
  delay(300);

  executarMovimentos();

  esquerda(20);
  delay(300);

  
}



// ===============================
// OMBRO
// ===============================

void ombroBaixo(int velo) {

  for (int i = 90; i >= 35; i--) {
    ombro.write(i);
    delay(velo);
  }

  posOmbro = 30;
}


void ombroCima(int velo) {

  for (int i = 35; i <= 90; i++) {
    ombro.write(i);
    delay(velo);
  }

  posOmbro = 90;
}


// ===============================
// COTOVELO
// ===============================

void cotoveloBaixo(int velo) {

  for (int i = 0; i <= 180; i++) {
    cotovelo.write(i);
    delay(velo);
  }

  posCotovelo = 180;
}


void cotoveloCima(int velo) {

  for (int i = 180; i >= 0; i--) {
    cotovelo.write(i);
    delay(velo);
  }

  posCotovelo = 90;
}


// ===============================
// GARRA
// ===============================

void abrirGarra(int velo) {

  for (int i = posGarra; i <= 150; i++) {
    garra.write(i);
    delay(velo);
  }

  posGarra = 150;
}


void fecharGarra(int velo) {

  for (int i = posGarra; i >= 85; i--) {
    garra.write(i);
    delay(velo);
  }

  posGarra = 90;
}

void direita(int velo){
  for (int i = 90; i <= 180; i++){
    cintura.write(i);
    delay(velo);
  }
}

void esquerda(int velo){
  for (int i = 180; i >= 90; i--){
    cintura.write(i);
    delay(velo);
  }
}

void executarMovimentos() {
  cotoveloBaixo(20);
  delay(300);

  ombroBaixo(20);
  delay(300);

  abrirGarra(20);
  delay(300);

  fecharGarra(20);
  delay(300);

  cotoveloCima(20);
  delay(300);

  ombroCima(20);
  delay(300);

 
}