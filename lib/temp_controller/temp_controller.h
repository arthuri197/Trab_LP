#ifndef TEMP_CONTROLLER_H
#define TEMP_CONTROLLER_H

#include <Arduino.h>
#include <DHT.h>

/**
 * @brief Le a temperatura de um sensor DHT e aplica histerese
 */
class TempController {
  public:
    /**
     * @param pin_dht     Pino digital onde o DHT esta conectado
     * @param type_dht    Tipo de sensor DHT (DHT11 ou DHT22)
     * @param t_min       Temperatura minima para ligar o atuador
     * @param t_max       Temperatura maxima para desligar o atuador
     * @param interval_ms Intervalo entre leituras em milissegundos
     */
    TempController(uint8_t pin_dht, uint8_t type_dht,
                   float t_min, float t_max, unsigned long interval_ms);

    /// Inicializa o sensor DHT e ajusta o temporizador
    void begin();

    /**
     * @brief Deve ser chamado em loop(); faz a leitura a cada interval_ms
     * @return true se houve nova leitura, false caso contrario
     */
    bool update();

    /// @return Ultima temperatura lida (ou NAN se erro)
    float getTemperature() const;

    /// @return true se temperatura < t_min
    bool shouldTurnOn() const;

    /// @return true se temperatura > t_max
    bool shouldTurnOff() const;

  private:
    DHT          _dht;           ///< objeto de leitura do sensor DHT
    float        _t_min, _t_max; ///< limites de histerese
    unsigned long _interval;     ///< intervalo entre leituras
    unsigned long _last_millis;  ///< registro da ultima leitura
    float        _last_temp;     ///< valor da ultima temperatura lida
};

#endif // TEMP_CONTROLLER_H
