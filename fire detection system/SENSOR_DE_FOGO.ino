// DEFINIÇÕES DE PINOS
#define pinSensor 8
#define pinBuzzer 2
#define pinLedVermelho 3 // Adicionado o pino do LED vermelho

#define FOGO LOW

// DEFINIÇÕES

#define DEBUG
// INSTANCIANDO OBJETOS


// DECLARAÇÃO DE FUNÇÕES
void controleAlarme(byte funcao, unsigned long tempo = 500);

// DECLARAÇÃO DE VARIÁVEIS


void setup() {
  Serial.begin(9600);

  pinMode(pinSensor, INPUT);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinLedVermelho, OUTPUT); // Configura o pino do LED vermelho como saída

#ifdef DEBUG
  Serial.println("Setup concluído!");
#endif
}

void loop() {
  if (digitalRead(pinSensor) == FOGO) {
    controleAlarme(HIGH);
    digitalWrite(pinLedVermelho, HIGH); // Acende o LED vermelho
  } else {
    controleAlarme(LOW);
    digitalWrite(pinLedVermelho, LOW); // Apaga o LED vermelho
  }
}

// IMPLEMENTO DE FUNÇÕES

// FUNÇÃO PARA EFEITO DE ALARME
void controleAlarme(byte funcao, unsigned long tempo = 500) {
  static unsigned long controleTempo = millis();
  static bool flag = true;
  if (funcao == true) {
    if (flag == true) {
      if (millis() < (controleTempo + tempo)) {
        digitalWrite(pinBuzzer, HIGH);
      } else {
        flag = false;
      }
    } else if (millis() < (controleTempo + tempo + tempo)) {
      digitalWrite(pinBuzzer, LOW);
    } else if (millis() > (controleTempo + tempo + tempo)) {
      flag = true;
      controleTempo = millis();
    }
  } else {
    digitalWrite(pinBuzzer, LOW);
  }
}
