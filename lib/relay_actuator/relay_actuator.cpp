#include "relay_actuator.h"

// Construtor: armazena pino e polaridade
RelayActuator::RelayActuator(uint8_t pin_relay, bool active_high)
  : _pin(pin_relay),
    _active_high(active_high),
    _state(false)
{}

// Inicializa o pino e garante estado desligado
void RelayActuator::begin() {
  pinMode(_pin, OUTPUT);
  if (_active_high) {
    digitalWrite(_pin, LOW);
  } else {
    digitalWrite(_pin, HIGH);
  }
}

// Liga o rele e marca estado
void RelayActuator::turnOn() {
  digitalWrite(_pin, _active_high ? HIGH : LOW);
  _state = true;
}

// Desliga o rele e marca estado
void RelayActuator::turnOff() {
  digitalWrite(_pin, _active_high ? LOW : HIGH);
  _state = false;
}

// Retorna estado interno
bool RelayActuator::isOn() const {
  return _state;
}
