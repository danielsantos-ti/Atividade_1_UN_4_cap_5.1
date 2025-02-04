#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"
#include <stdio.h>


//#define LED_VERMELHO 1     // Pino do LED vermelho
//#define LED_AMARELO 5  // Pino do LED amarelo
//#define LED_VERDE 9   // Pino do LED verde

#define LED_VERMELHO 11     // Pino do LED vermelho
#define LED_AMARELO 12  // Pino do LED amarelo
#define LED_VERDE 13   // Pino do LED verde

volatile int estado = 0; // Variável para controlar o estado do semáforo

// Função de callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Alterna entre os estados do semáforo
    if (estado == 0) {
        gpio_put(LED_VERMELHO, 1);
        gpio_put(LED_AMARELO, 0);
        gpio_put(LED_VERDE, 0);
        estado = 1;
    }
    else if (estado == 1) {
        gpio_put(LED_VERMELHO, 0);
        gpio_put(LED_AMARELO, 1);
        gpio_put(LED_VERDE, 0);
        estado = 2;
    }
    else {
        gpio_put(LED_VERMELHO, 0);
        gpio_put(LED_AMARELO, 0);
        gpio_put(LED_VERDE, 1);
        estado = 0;
    }
    return true; // Mantém o timer rodando
}

int main() {
    stdio_init_all(); // Inicializa a comunicação serial

    // Configuração dos pinos
    gpio_init(LED_VERMELHO);
    gpio_init(LED_AMARELO);
    gpio_init(LED_VERDE);

    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer); // Timer de 3 segundos

    while (1) {
        printf("Semáforo em operação...\n"); // Mensagem na porta serial
        sleep_ms(1000); // Espera 1 segundo
    }

    return 0;
}


