# Certificadora-2
# 🔥 Sistema de Alarme de Incêndio com ESP32

Este projeto consiste em um **sistema embarcado de alarme de incêndio** utilizando **ESP32**, sensores de gás e temperatura, e um display I2C para monitoramento em tempo real. Ele detecta situações de risco e aciona sinais visuais e sonoros para alertar sobre possíveis incêndios.

---

## 🛠️ Componentes Utilizados
- **ESP32** – Microcontrolador principal  
- **Módulo Relé** – Controle do alarme e LEDs de status  
- **LED Verde** – Indica ambiente seguro  
- **LED Vermelho** – Indica situação de alerta/incêndio  
- **Sensor MQ-2** – Detecção de fumaça e gases inflamáveis  
- **Sensor de Temperatura** (módulo de calor) – Para análise de risco de incêndio  
- **Buzzer** – Alarme sonoro  
- **Display I2C (LCD 16x2)** – Exibição dos status em tempo real  

---

## ⚙️ Funcionamento
1. **Monitoramento contínuo** de temperatura e gases pelo **sensor MQ-2** e módulo de calor.  
2. Se os valores detectados estiverem dentro da faixa de segurança:  
   - LED verde permanece aceso.  
   - Display mostra: `"Ambiente Seguro"`.  
3. Se valores críticos forem detectados:  
   - LED vermelho acende.  
   - Buzzer é acionado.  
   - Display mostra mensagem de alerta.  

---

## 🚀 Como Usar
1. **Faça o upload do firmware** para o ESP32 via Arduino IDE ou PlatformIO.  
2. **Conecte os componentes** conforme o esquema elétrico (ver seção abaixo).  
3. **Alimente o sistema** com 5V/USB ou fonte externa.  
4. Monitore as informações no display e aguarde os alertas em caso de risco.

---

## 🔌 Esquema de Ligação
> *(Adicione aqui um diagrama ou tabela de conexões para facilitar a montagem)*

| Componente        | Pino no ESP32 |
|------------------|--------------|
| MQ-2             | GPIO XX      |
| Sensor de calor  | GPIO XX      |
| Relé             | GPIO XX      |
| LED Verde        | GPIO XX      |
| LED Vermelho     | GPIO XX      |
| Buzzer           | GPIO XX      |
| Display I2C SDA  | GPIO 21      |
| Display I2C SCL  | GPIO 22      |

---

## 📚 Dependências
- Biblioteca do LCD (`LiquidCrystal_I2C.h`)  
- Biblioteca para o sensor MQ-2 (opcional, pode ser código manual)

---

## 📈 Possíveis Melhorias
- Envio de notificações via Wi-Fi ou Bluetooth.  
- Registro de histórico de eventos em memória ou servidor.  
- Integração com aplicativo para celular.  

---

## 📝 Licença
Este projeto é de código aberto. Sinta-se livre para usar, modificar e distribuir conforme necessário.
