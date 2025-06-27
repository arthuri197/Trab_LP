#ifndef RELAY_ACTUATOR_H
#define RELAY_ACTUATOR_H

#include <Arduino.h>

/**
 * @brief Abstrai o controle de um modulo de rele digital
 */
class RelayActuator {
  public:
    /**
     * @param pin_relay   Pino digital onde o rele e acionado
     * @param active_high true se HIGH ativa o rele, false se LOW ativa
     */
    RelayActuator(uint8_t pin_relay, bool active_high = true);

    /// Configura o pino como OUTPUT e garante estado desligado
    void begin();

    /// Aciona o rele
    void turnOn();

    /// Desliga o rele
    void turnOff();

    /// @return estado atual (true = ligado)
    bool isOn() const;

  private:
    uint8_t _pin;         ///< pino do rele
    bool    _active_high; ///< polaridade de ativacao
    bool    _state;       ///< estado atual do rele
};

#endif // RELAY_ACTUATOR_H
