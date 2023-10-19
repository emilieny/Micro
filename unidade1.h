#include "stm32f4xx.h"
#include "Utility.h"


#define k0 !(GPIOE->IDR & (1 << 4)) // botão
#define k1 !(GPIOE->IDR & (1 << 3)) // botão

void piscaDois(void);
void piscaUmDeCadaVez(void);
void sirenizinha(void);
void exercicioPratico(void);
void lendoBotao(void);
void lendoBotao2(void);
void lendoBotao3(void);
void aula_14_03(void);
void aula_14_03_p2(void);


void piscaDois(void){
	// Aula 03/03/2023

	Utility_Init();
	//liga o clock de GPIOC e GPIOA
	RCC-> AHB1ENR |=0b0101;

	//configurando os pinos pa2 e pc9 como saídas

	GPIOA->MODER |= 0b01 << 4;
	GPIOC->MODER |= 0b01 << 18;

	while(1){
		GPIOA->ODR |= 1 << 2; // liga
		GPIOC->ODR |= 1 << 9; // liga
		Delay_ms(1000);
		GPIOA->ODR &= ~(1 << 2); // desliga
		GPIOC->ODR &= ~(1 << 9); // desliga
		Delay_ms(1000);
	}
}

void piscaUmDeCadaVez(void){
	// Aula 03/03/2023

	Utility_Init();
	//liga o clock de GPIOC e GPIOA
	RCC-> AHB1ENR |=0b0101;

	//configurando os pinos pa2 e pc9 como saídas

	GPIOA->MODER |= 0b01 << 4;
	GPIOC->MODER |= 0b01 << 18;

	while(1){
		GPIOA->ODR |= 1 << 2; // liga
		Delay_ms(1000);
		GPIOC->ODR |= 1 << 9; // liga
		GPIOA->ODR &= ~(1 << 2); // desliga
		Delay_ms(1000);
		GPIOC->ODR &= ~(1 << 9); // desliga
		}
}

void sirenizinha(void){
	// Aula 03/03/2023

	Utility_Init();
	//liga o clock de GPIOA
	RCC-> AHB1ENR |= 1;

	//configurando os pinos pa2 como saída

	GPIOA->MODER |= 0b01 << 4;

	while(1){
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
		Delay_ms(1000);

		}
}

void exercicioPratico(void){
	// Aula 07/03/23

	Utility_Init();

	//liga o clock de GPIOA
	RCC-> AHB1ENR |= 1;

	//configurando os pinos pa2, pa6 e pa7 como saída

	GPIOA->MODER |= 0b01 << 4;
	GPIOA->MODER |= 0b01 << 12;
	GPIOA->MODER |= 0b01 << 14;

	while(1){
		GPIOA->ODR |= (1 << 6)|(1 << 7);
		GPIOA->ODR &= ~(1 << 2);
		Delay_ms(400);
		GPIOA->ODR &= ~(1 << 6 | 1 << 7);
		GPIOA->ODR |= 1 << 2;
		Delay_ms(400);
		GPIOA->ODR |= (1 << 6)|(1 << 7);
		GPIOA->ODR &= ~(1 << 2);
		Delay_ms(400);
		GPIOA->ODR &= ~(1 << 6 | 1 << 7);
		GPIOA->ODR |= 1 << 2;
		Delay_ms(400);
		GPIOA->ODR |= (1 << 6)|(1 << 7);
		GPIOA->ODR &= ~(1 << 2);
		Delay_ms(400);
		GPIOA->ODR &= ~(1 << 6 | 1 << 7);
		GPIOA->ODR |= 1 << 2;
		Delay_ms(400);
		GPIOA->ODR |= (1 << 6)|(1 << 7);
		GPIOA->ODR &= ~(1 << 2);
		Delay_ms(400);
		GPIOA->ODR &= ~(1 << 6 | 1 << 7);
		GPIOA->ODR |= 1 << 2;
		Delay_ms(400);
		GPIOA->ODR |= (1 << 6)|(1 << 7);
		GPIOA->ODR &= ~(1 << 2);

	}
}

void lendoBotao(void){
	// Aula 10/03/23

	 Utility_Init();

	 //ligando o clock da porta E e A
	 RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN | RCC_AHB1ENR_GPIOAEN; // forma mais clara de ligar o clock

	 //configurando pa6 como saída
	 GPIOA->MODER |= 0b01 << 12;

	 //configurando pe4 como entrada
	 GPIOE->MODER &= ~(0b11 << 8);

	 //ligando o resistor de pull-up no pino pe4
	 GPIOE->PUPDR |= (0b01 << 8);

	 while(1){
		 //testando se o pino tem nível lógico alto ou baixo
		 if(!(GPIOE->IDR & (1 << 4)))
			 GPIOA->ODR &= ~(1 << 6); //liga o LED, se nível alto
		 else
			 GPIOA->ODR |= (1 << 6); //desliga o LED, se nível baixo
	 }
}

void lendoBotao2(void){
	 // Aula 10/03/23
	 Utility_Init();

	 //ligando o clock da porta E e A
	 RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN | RCC_AHB1ENR_GPIOAEN; // forma mais clara de ligar o clock

	 //configurando pa6 e pa7 como saída
	 GPIOA->MODER |= 0b01 << 12;
	 GPIOA->MODER |= 0b01 << 14;

	 //configurando pe4 e pe3 como entrada
	 GPIOE->MODER &= ~(0b11 << 8);
	 GPIOE->MODER &= ~(0b11 << 6);

	 //ligando o resistor de pull-up no pino pe4 e pe3
	 GPIOE->PUPDR |= (0b01 << 8);
	 GPIOE->PUPDR |= (0b01 << 6);

	 while(1){
	 		 //testando se o pino tem nível lógico alto ou baixo
	 		 if(!(GPIOE->IDR & (1 << 4))){
	 			 GPIOA->ODR &= ~(1 << 6); //liga o LED, se nível alto
	 		 }else{
	 			 GPIOA->ODR |= (1 << 6); //desliga o LED, se nível baixo
	 		 }

	 		 if(!(GPIOE->IDR & (1 << 3))){
				 GPIOA->ODR &= ~(1 << 7); //liga o LED, se nível alto
	 		 }else{
				 GPIOA->ODR |= (1 << 7); //desliga o LED, se ní
	 		 }
	 	 }
}

void lendoBotao3(void){
	//Aula 10/03/23
	// Fazer isso depois
	// ligar os dois leds somente se apertar os dois botões
}

void aula_14_03(void){
	Utility_Init();

	//ligando o clock da porta A e E, respectivamente
	 RCC->AHB1ENR |= (1 | (1 << 4)); // outra forma de ligar os clocks

	 //pino pa6 como saída
	 GPIOA->MODER |= 0b01 << 12;

	 //pinos pe4 e pe3 como entradas
	 GPIOE->MODER &= ~(0b11 << 8);
	 GPIOE->MODER &= ~(0b11 << 6);

	 //ligando o resistor de pull-up nos pinos pe4 e pe3
	 GPIOE->PUPDR |= 0b01 << 8;
	 GPIOE->PUPDR |= 0b01 << 6;

	 while(1){
		 // if (k0 ^ k1) outra forma mais simples

		 if((k0 || k1) && !(k0 && k1))        //testa se presiona o botão
			 GPIOA->ODR &= ~(1 << 6);         //se sim, liga o LED
		 else
			 GPIOA->ODR |= 1 << 6;            //se não, desliga o LED


		 //quando aperta o botão, o nível lógico é baixo
	 }

}

void aula_14_03_p2(void){
	Utility_Init();

		//ligando o clock da porta A e E, respectivamente
		 RCC->AHB1ENR |= (1 | (1 << 4)); // outra forma de ligar os clocks

		 //pino pa6 como saída
		 GPIOA->MODER |= 0b01 << 12;

		 //pino pe4 e pe3 como entradas
		 GPIOE->MODER &= ~(0b11 << 8);
		 GPIOE->MODER &= ~(0b11 << 6);

		 //ligando o resistor de pull-up nos pinos pe4 e pe3
		 GPIOE->PUPDR |= 0b01 << 8;
		 GPIOE->PUPDR |= 0b01 << 6;

		 while(1){
			 while(k0 && !(k1)){
				 GPIOA->ODR |= (1 << 6);
				 while(k0 && k1)
					 GPIOA->ODR &= ~(1 << 6);
			 }
			GPIOA->ODR |= 1 << 6;

			 //outro desafio da aula
	 }
}
