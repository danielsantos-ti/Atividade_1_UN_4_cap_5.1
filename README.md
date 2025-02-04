# Atividade_1_UN_4_cap_5.1

# Atividade_1_UN_4_cap_5

## Descrição
Este projeto implementa um **sistema de semáforo** utilizando um Raspberry Pi Pico. O código controla três LEDs (vermelho, amarelo e verde) para simular o funcionamento de um semáforo, alternando entre os estados a cada 3 segundos.

## Funcionalidades
- Alternância automática entre os LEDs vermelho, amarelo e verde.
- Utilização de um **temporizador repetitivo** para controle do tempo.
- Impressão de mensagens no terminal serial informando o estado do semáforo.

## Requisitos
- **Placa:** Raspberry Pi Pico  
- **Linguagem:** C  
- **Bibliotecas:**  
  - `pico/stdlib.h` (para funções básicas do Raspberry Pi Pico)  
  - `hardware/timer.h` (para manipulação de temporizadores)  
  - `hardware/gpio.h` (para controle dos pinos GPIO)

## Circuito
Os LEDs devem ser conectados aos seguintes pinos do Raspberry Pi Pico:
- **LED Vermelho:** GPIO 11  
- **LED Amarelo:** GPIO 12  
- **LED Verde:** GPIO 13  

## Como Compilar e Executar
1. **Instale o SDK do Raspberry Pi Pico** no seu ambiente de desenvolvimento.  
2. **Clone o repositório**:
   ```sh
   git clone https://github.com/seu-usuario/Atividade_1_UN_4_cap_5.git
   cd Atividade_1_UN_4_cap_5

