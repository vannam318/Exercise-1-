#include "stm32f10x.h"

// Function prototypes
void config(void);
void delay_1_ms(void);
void delay_ms(uint32_t u32Delay); 

int main(void) {
    // Cau hinh GPIO
    config();

    while (1) {
        GPIO_SetBits(GPIOC, GPIO_Pin_13);
        delay_ms(1000);  // Delay for 1 second
        GPIO_ResetBits(GPIOC, GPIO_Pin_13);
        delay_ms(1000);  // Delay for 1 second
    }
}

void config(void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStruct);
}

void delay_1_ms(void)
{
		SysTick->LOAD = 72*100 - 1;
		SysTick->VAL = 0;
		SysTick->CTRL = 5;
		while (!(SysTick->CTRL & (1 << 16))) {
		}
}	
void delay_ms(uint32_t u32Delay){
	while (u32Delay){
		delay_1_ms();
		--u32Delay;
	}
} 
