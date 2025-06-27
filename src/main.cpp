/*
Programa: Controle Temperatura ESP32
Autor: Arthur Oliveira
Data da Modificacao: 27/06/2025
Descricao: Leitura de temperatura via DHT11 e controle de lampada por rele com faixa de histerese
Licenca: CC BY
*/

#include <Arduino.h>
#include "temp_controller.h"
#include "relay_actuator.h"

// === CONFIGURACOES GERAIS ===
static constexpr uint8_t     PINO_DHT     = 4;      // pino do sensor
static constexpr uint8_t     TIPO_DHT     = DHT11;  // tipo do DHT
static constexpr float       TEMP_MIN     = 30.0;   // ligar abaixo deste valor
static constexpr float       TEMP_MAX     = 33.0;   // desligar acima deste valor
static constexpr uint8_t     PINO_RELE    = 23;     // pino de controle do rele
static constexpr unsigned long INTERVALO_MS = 5000; // intervalo de leitura (ms)

// Instancias dos modulos
TempController tempCtrl(PINO_DHT, TIPO_DHT, TEMP_MIN, TEMP_MAX, INTERVALO_MS);
RelayActuator  rele(PINO_RELE);

void setup() {
  Serial.begin(115200);
  tempCtrl.begin();  // inicia DHT e temporizador
  rele.begin();      // configura pino do rele
  Serial.println("Sistema de controle de temperatura iniciado.");
}

void loop() {
  // so prossegue quando ha nova leitura disponivel
  if (!tempCtrl.update()) {
    return;
  }

  float temp = tempCtrl.getTemperature();
  if (isnan(temp)) {
    Serial.println("Erro ao ler a temperatura!");
    return;
  }

  Serial.printf("Temperatura atual: %.2f C\n", temp);

  // Histerese: evita acionamentos frequentes
  if (!rele.isOn() && tempCtrl.shouldTurnOn()) {
    rele.turnOn();
    Serial.println("Lampada LIGADA.");
  }
  else if (rele.isOn() && tempCtrl.shouldTurnOff()) {
    rele.turnOff();
    Serial.println("Lampada DESLIGADA.");
  }
}
