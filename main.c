#include "timers.h"

int main(void) {
    
    TIM2_Init();

    while (1) {
         
        TIM2_SetPulse(1); //Pulso de 1 ms

        for (volatile uint32_t i = 0; i < 200000; i++) {  // Espera de 20 ms aproximados(causa de jitter)
        }
    }

    return 0;
}