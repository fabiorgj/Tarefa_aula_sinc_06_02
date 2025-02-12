#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include <stdio.h>

int main() {
    const uint gpio_pin = 22; // Pino GP22
    const float freq = 50;    // Frequência desejada: 50 Hz

    // Configurar o pino para PWM
    gpio_set_function(gpio_pin, GPIO_FUNC_PWM);
    
    // Identificar o "slice" e o "channel" associados ao pino
    uint slice_num = pwm_gpio_to_slice_num(gpio_pin);
    uint channel = pwm_gpio_to_channel(gpio_pin);

    // Resolução de 16 bits (wrap = 65535)
    uint32_t wrap = 65535;
    float divider = 125000000.0f / (freq * (wrap + 1));

    // Configurar o PWM
    pwm_config config = pwm_get_default_config();
    pwm_config_set_wrap(&config, wrap);
    pwm_config_set_clkdiv(&config, divider);
    pwm_init(slice_num, &config, true);

    // Valores de duty cycle (2,5% e 12%)
    uint32_t duty_min = (uint32_t)(0.025f * (wrap + 1)); // 2,5% de 65536
    uint32_t duty_max = (uint32_t)(0.12f * (wrap + 1));   // 12% de 65536
    uint32_t duty_current = duty_min; // Começa em 2,5%
    int direction = 1; // 1 para aumentar, -1 para diminuir

    // Conversão de 5 µs para valor de duty cycle
    const uint32_t step_us = 5; // Passo de 5 µs
    const uint32_t period_us = 20000; // Período de 20.000 µs (50 Hz)
    uint32_t step_duty = (uint32_t)((step_us / (float)period_us) * (wrap + 1)); // Passo em valor de duty

    pwm_set_chan_level(slice_num, channel, wrap*0.12);

    sleep_ms(5000);

    pwm_set_chan_level(slice_num, channel, wrap*0.0735);

    sleep_ms(5000);

    pwm_set_chan_level(slice_num, channel, wrap*0.025);

    sleep_ms(5000);

    while (true) {
        // Ajusta o duty cycle
        pwm_set_chan_level(slice_num, channel, duty_current);

        // Atualiza o duty cycle
        if (direction == 1) {
            duty_current += step_duty; // Incrementa o duty cycle
            if (duty_current >= duty_max) {
                direction = -1; // Inverte a direção
            }
        } else {
            duty_current -= step_duty; // Decrementa o duty cycle
            if (duty_current <= duty_min) {
                direction = 1; // Inverte a direção
            }
        }

        // Delay de 10 ms entre cada ajuste
        sleep_ms(10);
    }
}