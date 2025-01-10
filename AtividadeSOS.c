#include "pico/stdlib.h"

#define LED_PIN 11

void acender_led(int tempo) {
    gpio_put(LED_PIN, true);
    sleep_ms(tempo);
    gpio_put(LED_PIN, false);
    sleep_ms(125); // Intervalo entre pontos/traços
}

void enviar_sos() {
    // Sinal S (3 pontos)
    for (int i = 0; i < 3; i++) {
        acender_led(200); // Ponto (.)
    }
    sleep_ms(250); // Intervalo entre letras

    // Sinal O (3 traços)
    for (int i = 0; i < 3; i++) {
        acender_led(800); // Traço (-)
    }
    sleep_ms(250); // Intervalo entre letras

    // Sinal S (3 pontos)
    for (int i = 0; i < 3; i++) {
        acender_led(200); // Ponto (.)
    }
}

int main() {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        enviar_sos(); // Envia o sinal SOS
        sleep_ms(3000); // Pausa de 3 segundos antes de reiniciar
    }
}
