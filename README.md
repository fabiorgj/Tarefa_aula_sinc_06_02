Controle de PWM na Raspberry Pi Pico W

## 📌 Descrição

Este projeto implementa um controle de PWM na Raspberry Pi Pico W, variando o duty cycle entre 2,5% e 12% de forma contínua. A frequência do sinal PWM é de 50 Hz, sendo ideal para o controle de servomotores.

## 🛠 Simulação no Wokwi

Raspberry Pi Pico W

Servomotor (opcional, para testes práticos)

Fonte de alimentação compatível

Jumpers e protoboard (para conexões)

## 🔧 Configuração do PWM

Pino de saída: GP22

Frequência do PWM: 50 Hz

Resolução: 16 bits (wrap = 65535)

Duty Cycle: Varia entre 2,5% e 12%

Incremento/Decremento: A cada 5 µs

Tempo de ajuste: 10 ms por incremento

## 📜 Código Explicado

Configuração do pino GP22 como saída PWM

Determinação do slice e canal PWM correspondentes

Configuração do PWM com resolução de 16 bits e frequência de 50 Hz

Definição de valores mínimos e máximos do duty cycle

Ajustes iniciais estáticos de duty cycle

Loop infinito variando o duty cycle entre 2,5% e 12%
