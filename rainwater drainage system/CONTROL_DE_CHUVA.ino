// Definindo os pinos para o sensor ultrassônico
const int trigPin = 2; // Pino de transmissão
const int echoPin = 3; // Pino de recepção

// Definindo os pinos para os LEDs
const int ledVermelho = 8;
const int ledAzul = 9;

// Variáveis para armazenar as medições do sensor 
long duracao;
int distancia;

void setup() {
  // Inicializa os pinos
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAzul, OUTPUT);

  // Inicializa a comunicação serial para monitoramento
  Serial.begin(9600);
}

void loop() {
  // Gera um pulso no pino de transmissão do sensor ultrassônico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Mede o tempo de retorno do pulso no pino de recepção
  duracao = pulseIn(echoPin, HIGH);

  // Converte o tempo em microssegundos para distância em centímetros
  distancia = duracao * 0.034 / 2;

  // Exibe a distância no monitor serial
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Verifica se há um obstáculo a uma distância específica (ajuste conforme necessário)
  if (distancia < 20) {
    // Se um obstáculo for detectado, apaga o LED azul e acende o LED vermelho
    digitalWrite(ledAzul, LOW);
    piscarLedVermelho(); // Chama a função para piscar o LED vermelho
  } else {
    // Caso contrário, apaga o LED vermelho e acende o LED azul
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAzul, HIGH);
  }
}

// Função para piscar o LED vermelho

d
void piscarLedVermelho() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledVermelho, HIGH);
    delay(500);
    digitalWrite(ledVermelho, LOW);
    delay(500);
  }

}
