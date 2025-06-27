#include "temp_controller.h"

// Construtor: armazena parametros e inicializa estado
TempController::TempController(uint8_t pin_dht, uint8_t type_dht,
                               float t_min, float t_max, unsigned long interval_ms)
  : _dht(pin_dht, type_dht),
    _t_min(t_min),
    _t_max(t_max),
    _interval(interval_ms),
    _last_millis(0),
    _last_temp(NAN)
{}

// Inicializa o sensor e marca o tempo de referencia
void TempController::begin() {
  _dht.begin();
  _last_millis = millis();
}

// Se ja passou _interval desde a ultima leitura, faz nova leitura
bool TempController::update() {
  unsigned long now = millis();
  if (now - _last_millis < _interval) {
    return false;
  }
  _last_millis = now;
  _last_temp   = _dht.readTemperature();
  return true;
}

// Retorna a ultima leitura (pode ser NAN em caso de erro)
float TempController::getTemperature() const {
  return _last_temp;
}

// Verifica se deve ligar (temp abaixo do limite minimo)
bool TempController::shouldTurnOn() const {
  return !isnan(_last_temp) && _last_temp < _t_min;
}

// Verifica se deve desligar (temp acima do limite maximo)
bool TempController::shouldTurnOff() const {
  return !isnan(_last_temp) && _last_temp > _t_max;
}
