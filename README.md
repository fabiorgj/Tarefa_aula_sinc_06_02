Embarcatech  

Tarefa da aula síncrona do dia 06/02/2025  

Aluno: Fábio Rocha Gomes Jardim  

Matrícula: TIC370100723  


# Controle de PWM na Raspberry Pi Pico W

## 🎬 Vídeo

O vídeo da atividade pode ser assistido no drive: [Link do vídeo](https://drive.google.com/file/d/1D_gU8s0DD5AXJANPGSaPp9UO3t2wsQHt/view?usp=sharing)

## 📌 Descrição

Este projeto implementa um controle de PWM na Raspberry Pi Pico W, variando o duty cycle entre 2,5% e 12%, primeiro, de maneira discreta com os valores 12%, 7,35% e 2,5% e em seguida de forma contínua. A frequência aplicada ao sinal PWM foi de 50 Hz. O sinal PWM foi aplicado a um servo motor usando o Wokwi, **integrado ao VS Code**, como plataforma de simulação.

## 🛠 Simulação no Wokwi

No Wokwi foi utilizado uma Raspberry Pi Pico W e um servo motor genérico, conectados conforme ilustradoa seguir 

![diagrama wokwi](https://github.com/fabiorgj/Tarefa_aula_sinc_06_02/blob/main/diagramawokwi.png)

A simulação pode ser feita no Wokwi web, clicando aqui: https://wokwi.com/projects/422627103776578561

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
