// Define os pinos utilizados
const int sensorChuvaPin = A0;  // Pino do sensor de chuva
const int relePin = 3;         // Pino do relé

void setup() {
  pinMode(sensorChuvaPin, INPUT);  // Configura o pino do sensor de chuva como entrada
  pinMode(relePin, OUTPUT);        // Configura o pino do relé como saída

  Serial.begin(9600);  // Inicializa a comunicação serial
}

void loop() {
  // Lê o estado do sensor de chuva
  int estadoChuva = digitalRead(sensorChuvaPin);

  if (estadoChuva == HIGH) {
    // Se estiver chovendo, liga o relé e exibe "Chuva" no monitor serial
    digitalWrite(relePin, HIGH);
    Serial.println("Chuva");
  } else {
    // Se não estiver chovendo, desliga o relé e exibe "Sem Chuva" no monitor serial
    digitalWrite(relePin, LOW);
    Serial.println("Sem Chuva");
  }

  delay(2000);  // Aguarda 1 segundo antes de verificar novamente o estado da chuva
}