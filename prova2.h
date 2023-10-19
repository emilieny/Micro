#include "stm32f4xx.h"

#include <stdio.h>

#include "Utility.h"
#include "AUDIO.h"

void q1(void);
void q2(void);
void q3(void);
void q4(void);
void q5(void);


void q1(void){
	Utility_Init();

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= 0b011 << 8;

	RCC->APB1ENR |= RCC_APB1ENR_DACEN;
	DAC->CR |= DAC_CR_EN1;

	while(1){

	int contador;

	for(contador = 0; contador < 4095; contador++){
			DAC->DHR12R1 = contador;
			Delay_us(500);
		}

	 contador = 0;

	 for(contador = 4095; contador > 0; contador--){
		DAC->DHR12R1 = contador;
		Delay_us(500);
	}
	}
}

void q2(void){
	//array com amostras do sinal
	const uint16_t samples[200]={
			2048, 2086, 2125, 2164, 2203, 2241, 2280, 2318, 2356, 2393, 2431, 2468, 2504, 2540, 2575, 2610, 2645, 2679, 2712, 2744, 2776, 2808, 2838, 2868, 2896, 2924, 2951, 2978, 3003, 3027, 3051, 3073, 3094, 3115, 3134, 3152, 3169, 3186, 3200, 3214, 3227, 3238, 3249, 3258, 3266, 3272, 3278, 3282, 3285, 3287, 3288, 3287, 3285, 3282, 3278, 3272, 3266, 3258, 3249, 3238, 3227, 3214, 3200, 3186, 3169, 3152, 3134, 3115, 3094, 3073, 3051, 3027, 3003, 2978, 2951, 2924, 2896, 2868, 2838, 2808, 2776, 2744, 2712, 2679, 2645, 2610, 2575, 2540, 2504, 2468, 2431, 2393, 2356, 2318, 2280, 2241, 2203, 2164, 2125, 2086, 2048, 2009, 1970, 1931, 1892, 1854, 1815, 1777, 1739, 1702, 1664, 1627, 1591, 1555, 1520, 1485, 1450, 1416, 1383, 1351, 1319, 1287, 1257, 1227, 1199, 1171, 1144, 1117, 1092, 1068, 1044, 1022, 1001, 980, 961, 943, 926, 909, 895, 881, 868, 857, 846, 837, 829, 823, 817, 813, 810, 808, 808, 808, 810, 813, 817, 823, 829, 837, 846, 857, 868, 881, 895, 909, 926, 943, 961, 980, 1001, 1022, 1044, 1068, 1092, 1117, 1144, 1171, 1199, 1227, 1257, 1287, 1319, 1351, 1383, 1416, 1450, 1485, 1520, 1555, 1591, 1627, 1664, 1702, 1739, 1777, 1815, 1854, 1892, 1931, 1970, 2009};

	//Programa principal
	Configure_Clock(); //configura o sistema de clock
	Delay_Start(); //inicializa funções de Delay

	RCC->AHB1ENR |= 1; //habilita o clock do GPIOA
	GPIOA->MODER |= 0b11 << 10; //inicialização do pino PA5 no modo analógico
	RCC->APB1ENR |= 1 << 29; //habilita o clock da interface digital do DAC
	DAC->CR |= 1; //habilita o canal 1 do DAC
	uint8_t contador =0; //indexador do array de amostras do sinal
	while(1)
	{
	DAC->DHR12R1 = samples[contador]; //escreve no DAC1
	++contador; //atualiza o indexador
	if(contador == 199) contador = 0; //verifica se chegou ao final do array
	Delay_us(42); //aguarda para a próxima amostra (testar com 42)

	}
}

void q3(void){
	Utility_Init();
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= 0b11 << 8;

	RCC->APB1ENR |= DAC_CR_EN1;

	while(1){
		for(uint32_t contador=0; contador<sizeof(AUDIO); contador++){
			DAC->DHR8R1 = AUDIO[contador];
			Delay_us(22);
		}
	}
}

void q4(void){
	Utility_Init();

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //habilita o clock de GPIOA
	GPIOA->MODER |= 0b11;               // pino PA0 como entrada analógica
	GPIOA->MODER |= 0b11 << 2;          // pino PA1 como entrada analógica
	GPIOA->MODER |= 0b01 << 4;          // pino PA2 como saída
	GPIOA->MODER |= 0b01 << 6;          // pino PA3 como saída

	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;        //liga o clock do ADC1

	ADC->CCR |= 0b01 << 16;            //prescaler /4
	ADC1->SQR1 = 1 << 20;            //conversão de dois canais
	ADC1->SQR3 = (0 << 0)|(1 << 5);    //canais IN_0 e IN_1 (PA0 e PA1)
	ADC1->CR1 = ADC_CR1_SCAN;        //habilita o modo scan
	ADC1->CR2 = ADC_CR2_EOCS;        //sinal EOC ao fim de cada conversão
	ADC1->CR2 |= ADC_CR2_ADON;    //liga o conversor AD


	while(1){
		ADC1->CR2 |= ADC_CR2_SWSTART;
		while(!(ADC1->SR & ADC_SR_EOC));
		uint16_t leitura1 = ((2000*(float)(ADC1->DR))/4095)+500;
		while(!(ADC1->SR & ADC_SR_EOC));
		uint16_t leitura2 = ((2000*(float)(ADC1->DR))/4095)+500;

		//servo motor 1
		GPIOA->ODR |= 1 << 2;
		Delay_us(leitura1);
		GPIOA->ODR &= ~(1 << 2);
		Delay_us(20000);

		//servo motor 2
		GPIOA->ODR |= 1 << 3;
		Delay_us(leitura2);
		GPIOA->ODR &= ~(1 << 3);
		Delay_us(20000);
	}

}

void q5(void){
	Configure_Clock(); //configura o sistema de clock
	USART1_Init(); //inicializa a USART1
	Delay_Start(); //inicializa funções de Delay

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //habilita o clock de GPIOA
	GPIOA->MODER |= 0b11;               // pino PA0 como entrada analógica
	GPIOA->MODER |= 0b01 << 12;         // pino PA6 como saída digital (LED 1)
	GPIOA->MODER |= 0b01 << 14;         // pino PA7 como saída digital (LED 2)
	GPIOA->MODER |= 0b01 << 4;          // pino PA2 como saída (BUZZER)


	RCC->APB2ENR |= 1 << 8; //liga o clock da interface digital do ADC1

	ADC->CCR |= 0b01 << 16; //prescaler /4
	ADC1->SQR1 &= ~(0xF << 20); //conversão de apenas um canal
	ADC1->SQR3 |= 16; //seleção do canal a ser convertido (IN_16)
	ADC1->SMPR1 |= (7 << 18); //tempo de amostragem igual a 480 ciclos de ADCCLK
	ADC->CCR |= (1 << 23); //liga o sensor de temperatura
	ADC1->CR2 |= 1; //liga o conversor AD

	uint32_t *p = (uint32_t *) 0x1FFF7A2C; //cria ponteiro para uma posição de memória
	uint32_t Word = p[0]; //lê o conteúdo da memória
	uint16_t TS_CAL1 = (Word & 0x0000FFFF); //lê o valor de TS_CAL1
	uint16_t TS_CAL2 = (Word & 0xFFFF0000) >> 16; //lê o valor de TS_CAL2


	while(1){
		uint32_t valor = 0;
		for(int i=0; i < 50; i++){
		ADC1->CR2 |= ADC_CR2_SWSTART;               //inicia a coversão
		while(!(ADC1->SR & ADC_SR_EOC));          //aguarda o fim da conversão
		valor +=ADC1->DR;
		}
		uint8_t temperatura = ((80*((valor/50) - TS_CAL1))/(TS_CAL2-TS_CAL1)) + 30;


		printf("Temperatura = %d °C\n", temperatura);
		Delay_ms(500);


		if(temperatura <= 45){
			printf("Temperatura = %d °C, temperatura dentro da faixa segura de operação!\n", temperatura);
			GPIOA->ODR |= (1 << 7);
			GPIOA->ODR |= (1 << 6);
		}

		else if((temperatura > 45) & (temperatura <=55)){
			printf("Temperatura = %d °C, temperatura dentro da faixa de atenção!\n", temperatura);
			GPIOA->ODR &= ~(1 << 6); // liga o LED 1
			GPIOA->ODR |= 1 << 7;
		}

		else if(temperatura > 55){
			printf("Temperatura = %d °C, temperatura dentro da faixa de superaquecimento!\n", temperatura);
			GPIOA->ODR &= ~(1 << 6);
			GPIOA->ODR &= ~(1 << 7); // liga o LED 2
			GPIOA->ODR |= 1 << 2; // liga
			Delay_ms(50);
			GPIOA->ODR &= ~(1 << 2); // desliga
			Delay_ms(50);
			GPIOA->ODR |= 1 << 2; // liga
			Delay_ms(50);
			GPIOA->ODR &= ~(1 << 2); // desliga
			Delay_ms(50);
			GPIOA->ODR |= 1 << 2; // liga
			Delay_ms(50);
			GPIOA->ODR &= ~(1 << 2); // desliga
			Delay_ms(50);
			GPIOA->ODR |= 1 << 2; // liga
			Delay_ms(50);
			GPIOA->ODR &= ~(1 << 2); // desliga
		}
	}
}
