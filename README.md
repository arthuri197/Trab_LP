# Trab_LP

# Controle de Temperatura com ESP32, Sensor DHT11 e Módulo Relé

Este projeto utiliza um **ESP32**, um **sensor de temperatura DHT11** e um **módulo relé** para controlar automaticamente o acionamento de uma lâmpada com base na temperatura ambiente.

---

## 🔧 Materiais utilizados

- ESP32 Dev Module
- Sensor de Temperatura DHT11
- Módulo Relé 5V
- Lâmpada halógena 
- Jumpers
- Protoboard
- Cabos eléticos
  

---

## 🧰 Requisitos de Software

- [VSCode](https://code.visualstudio.com/)
- [PlatformIO](https://platformio.org/)
- Driver USB do ESP32 (ex: CP210x, CH340)
- Git (para clonar o repositório)

---

## 📁 Estrutura do Projeto

esp32_control_temp_lamp/
├── lib/
│ ├── relay_actuator/
│ │ ├── relay_actuator.h
│ │ └── relay_actuator.cpp
│ └── temp_controller/
│ ├── temp_controller.h
│ └── temp_controller.cpp
├── src/
│ └── main.cpp
├── platformio.ini
└── README.md

--

## ⚙️ Instalação e Execução

1. Clone o repositório:

   ```bash
   git clone https://github.com/arthuri197/Trab_LP.git
Abra a pasta clonada no VSCode com a extensão PlatformIO instalada.

2.Conecte o ESP32 via USB no computador.

3.No VSCode, clique no ícone Upload (seta para a direita) para compilar e carregar o código no ESP32.

4.Para monitorar as leituras da temperatura e status do relé, abra o Monitor Serial no PlatformIO (baud rate 115200).


