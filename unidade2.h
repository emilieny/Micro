#include "stm32f4xx.h"

#include <stdio.h>
#include "Utility.h"

void aula_remota1(void); //exemplo 1
void aula_remota2(void); //exemplo 2
void aula_remota3(void); //exemplo 3
void aula25_04(void);
void aula02_05(void);
void aula05_05(void);


void aula_remota1(void){
	// exemplo 1

	Utility_Init();
	USART1_Init();

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //habilita o clock de GPIOA
	GPIOA->MODER |= 0b11;               // pino PA0 como entrada analógica

	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN; //liga o clock do ADC1
	ADC->CCR |= 0b01 << 16;             //prescaler /4 (fADC=21MHz)
	ADC1->SQR1 &= ~(0xF << 20);         //conversão de apenas um canal
	ADC1->SQR3 &= ~(0x1F);              //seleção do canal a ser convertido
	ADC1->CR2 |= 1;                     //liga o conversor AD

	while(1){
	ADC1->CR2 |= 1 << 30;               //inicia a coversão
	while(!(ADC1->SR & 0x02));          //aguarda o fim da conversão
	uint16_t leitura = ADC1->DR;        // faz a leitura do valor convertido

	printf("Leitura = %d\n", leitura);
	Delay_ms(500);
	}
}

void aula_remota2(void){
	// exemplo 2

	Utility_Init();
	USART1_Init();

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //habilita o clock de GPIOA
	GPIOA->MODER |= 0b11;               // pino PA0 como entrada analógica

	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN; //liga o clock do ADC1
	ADC->CCR |= 0b01 << 16;             //prescaler /4 (fADC=21MHz)
	ADC1->SQR1 &= ~(0xF << 20);         //conversão de apenas um canal
	ADC1->SQR3 &= ~(0x1F);              //seleção do canal a ser convertido
	ADC1->CR2 |= 1;                     //liga o conversor AD

	ADC1->CR2 |= 1 << 30;               //inicia a coversão
	while(!(ADC1->SR & 0x02));          //aguarda o fim da conversão
	uint16_t leitura = ADC1->DR;        // faz a leitura do valor convertido

	if(leitura > 3000)
		GPIOA->ODR &= ~(1 << 6); //liga o LED
	if(leitura < 2000)
		GPIOA->ODR |= 1 << 6; //desliga o LED

}

void aula_remota3(void){
	// exemplo 3

	Utility_Init();
	USART1_Init();

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //habilita o clock de GPIOA
	GPIOA->MODER |= 0b11;               // pino PA0 como entrada analógica

	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN; //liga o clock do ADC1
	ADC->CCR |= 0b01 << 16;             //prescaler /4 (fADC=21MHz)
	ADC1->SQR1 &= ~(0xF << 20);         //conversão de apenas um canal
	ADC1->SQR3 &= ~(0x1F);              //seleção do canal a ser convertido
	ADC1->CR2 |= 1;                     //liga o conversor AD

	ADC1->CR2 |= 1 << 30;               //inicia a coversão
	while(!(ADC1->SR & 0x02));          //aguarda o fim da conversão
	uint16_t leitura = ADC1->DR;        // faz a leitura do valor convertido

	GPIOA->ODR &= ~(1 << 6); //liga o LED
	Delay_us(leitura);
	GPIOA->ODR |= 1 << 6; //desliga o LED
	Delay__us(4095-leitura);
}

void aula25_04(void){
	// mostrando a tensão (de 0v a 3,3v) ao invés do código (0 a 4095)

	Utility_Init();
	USART1_Init();

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //habilita o clock de GPIOA
	GPIOA->MODER |= 0b11;               // pino PA0 como entrada analógica

	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN; //liga o clock do ADC1
	ADC->CCR |= 0b01 << 16;             //prescaler /4 (fADC=21MHz)
	ADC1->SQR1 &= ~(0xF << 20);         //conversão de apenas um canal
	ADC1->SQR3 &= ~(0x1F);              //seleção do canal a ser convertido
	ADC1->CR2 |= 1;                     //liga o conversor AD

	while(1){
	ADC1->CR2 |= 1 << 30;               //inicia a coversão
	while(!(ADC1->SR & 0x02));          //aguarda o fim da conversão
	uint16_t leitura = ADC1->DR;        // faz a leitura do valor convertido

	printf("%.2f\n", ((float)leitura/4095)*3.3);
	Delay_ms(500);
	}
}

void aula02_05(void){
	// alterando a intensidade dos leds com o joystick

	Utility_Init();
	USART1_Init();

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //habilita o clock de GPIOA
	GPIOA->MODER |= 0b11;               // pino PA0 como entrada analógica
	GPIOA->MODER |= 0b01 << 12;
	GPIOA->MODER |= 0b01 << 14;


	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN; //liga o clock do ADC1
	ADC->CCR |= 0b01 << 16;             //prescaler /4 (fADC=21MHz)
	ADC1->SQR1 &= ~(0xF << 20);         //conversão de apenas um canal
	ADC1->SQR3 &= ~(0x1F);              //seleção do canal a ser convertido
	ADC1->CR2 |= 1;                     //liga o conversor AD

	while(1){
	ADC1->CR2 |= 1 << 30;               //inicia a coversão
	while(!(ADC1->SR & 0x02));          //aguarda o fim da conversão
	uint16_t leitura = ADC1->DR;        // faz a leitura do valor convertido

	if(leitura < 2048){
		GPIOA->ODR |= 1 << 7; //desliga o LED
		GPIOA->ODR |= 1 << 6; //desliga o LED
		Delay_us(leitura);
		GPIOA->ODR &= ~(1 << 6); //liga o LED
		Delay_us(2048-leitura);
	}else{
		GPIOA->ODR |= 1 << 6; //desliga o LED
	}

	if(leitura >= 2048){
		leitura -= 2048;
		GPIOA->ODR |= 1 << 6; //desliga o LED
		GPIOA->ODR |= 1 << 7; //desliga o LED
		Delay_us(2048-leitura);
		GPIOA->ODR &= ~(1 << 7); //liga o LED
		Delay_us(leitura);
	}else{
		GPIOA->ODR |= 1 << 7; //desliga o LED
	}

 }
}

void aula05_05(void){
    Configure_Clock();            //configura o sistema de clock
    USART1_Init();                //inicializa a USART1
    Delay_Start();                //inicializa funções de Delay

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;    //habilita o clock do GPIOA
    GPIOA->MODER |= 0b11;                    //pino PA0 como entrada analógica
    GPIOA->MODER |= 0b11 << 2;                //pino PA1 como entrada analógica
    GPIOA->MODER |= 0b01 << 12;
    GPIOA->MODER |= 0b01 << 14;

    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;        //liga o clock do ADC1

    ADC->CCR |= 0b01 << 16;            //prescaler /4
    ADC1->SQR1 = 1 << 20;            //conversão de dois canais
    ADC1->SQR3 = (0 << 0)|(1 << 5);    //canais IN_0 e IN_1 (PA0 e PA1)
    ADC1->CR1 = ADC_CR1_SCAN;        //habilita o modo scan
    ADC1->CR2 = ADC_CR2_EOCS;        //sinal EOC ao fim de cada conversão
    ADC1->CR2 |= ADC_CR2_ADON;    //liga o conversor AD

    while(1)
    {
        ADC1->CR2 |= ADC_CR2_SWSTART;        //inicia a conversão
        while(!(ADC1->SR & ADC_SR_EOC));    //aguarda o fim da primeira conversão
        uint16_t leitura1 = ADC1->DR;        //faz a leitura do valor convertido
        while(!(ADC1->SR & ADC_SR_EOC));    //aguarda o fim da segunda conversão
        uint16_t leitura2 = ADC1->DR;        //faz a leitura do valor convertido

    	GPIOA->ODR &= ~(1 << 6); //liga o LED
    	Delay_us(leitura1);
    	GPIOA->ODR |= 1 << 6; //desliga o LED
    	Delay_us(4095-leitura1);

    	GPIOA->ODR &= ~(1 << 7); //liga o LED
    	Delay_us(leitura2);
    	GPIOA->ODR |= 1 << 7; //desliga o LED
    	Delay_us(4095-leitura2);


    }
}
