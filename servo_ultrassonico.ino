#include <Servo.h>

Servo servo;

const int trigPin = 11; // Pino do trigger
const int echoPin = 12; // Pino do echo

// Variáveis
long duration;
int distance;

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
  servo.attach(13);
  servo.write(180); // Move o servo para 180 graus
  delay(2000);

  pinMode(trigPin, OUTPUT); // Define o trigPin como saída
  pinMode(echoPin, INPUT);   // Define o echoPin como entrada
}

void loop() {
  // Limpa o trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Ativa o sensor ultrassônico
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lê o echoPin e calcula a duração
  duration = pulseIn(echoPin, HIGH);

  // Calcula a distância
  distance = duration * 0.034 / 2;

  // Imprime a distância no Monitor Serial
  Serial.print("Distância: ");
  Serial.println(distance);

  // Controle do servo baseado na distância
  if (distance <= 25) { // Distância limite
    servo.write(180); // Move para 180 graus
    delay(3000); // Atraso de 3 segundos
  } else {
    servo.write(90); // Move para 90 graus
  }

  delay(100); // Atraso opcional para evitar inundação no Monitor Serial
}