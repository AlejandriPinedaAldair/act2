#include "timers.h"

int main(void) {
    // Inicializar el GPIO para el pin PA0 como salida de TIM2_CH1
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;  // Habilitar el reloj para GPIOA
    GPIOA->CRL &= ~(0xF << (0 * 4));     // Limpiar los bits de configuración para PA0
    GPIOA->CRL |= (0xB << (0 * 4));      // Configurar PA0 como salida en modo alternativo (TIM2_CH1)

    // Inicializar el TIM2
    TIM2_Init();

    while (1) {
        TIM2_SetPulse(1);  // Establecer un pulso de 1 ms

        // Espera aproximada de 20 ms (con jitter)
        for (volatile uint32_t i = 0; i < 200000; i++) {}
    }

    return 0;
}