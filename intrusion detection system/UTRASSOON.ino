const int chamaPin = A0;  // Pino analógico para a saída do sensor de chama
const int buzzerPin = 8; // Pino digital para o buzzer
const int ledPin = 9;    // Pino digital para o LED
const int digitalPin = 7; // Pino digital para a saída digital do sensor de chama

void setup() {
  pinMode(chamaPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(digitalPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int valorAnalogico = analogRead(chamaPin);
  int valorDigital = digitalRead(digitalPin);

  Serial.print("Valor Analógico: ");
  Serial.println(valorAnalogico);
  Serial.print("Valor Digital: ");
  Serial.println(valorDigital);

  // Se o sensor de chama detectar fogo
  if (valorDigital == HIGH) {
    acionarAlarme();
  } else {
    desativarAlarme();
  }

  delay(1000); // Aguarda 1 segundo entre as leituras
}

void acionarAlarme() {
  digitalWrite(buzzerPin, HIGH);
  piscarLed();
}

void desativarAlarme() {
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);
}

void piscarLed() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
}
