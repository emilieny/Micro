#include "stm32f4xx.h"
#include "Utility.h"

#define k0 !(GPIOE->IDR & (1 << 4)) // botão
#define k1 !(GPIOE->IDR & (1 << 3)) // botão

//Atividade Prática
void questao1(void);
void questao2(void);
void questao3(void);
void questao4(void);
void questao5(void);
void questao6(void);
void questao7(void);
void questao8(void);
void questao9(void);
void questao10(void);
void questao11(void);
void questao12(void);
void questao13(void);
void questao14(void);
void questao15(void);
void questao16(void);
void questao17(void);
void questao18(void);
void questao19(void);
void questao20(void);
void questao21(void);
void questao22(void);
void questao23(void);
void questao24(void);
void questao25(void);
void questao26(void);
void questao27(void);
void questao28(void);
void questao29(void);
void questao30(void);


void questao1(void){
	Utility_Init();
		//liga o clock de GPIOA
		RCC-> AHB1ENR |= 1;

		//configurando os pino pa6 como saída
		GPIOA->MODER |= 0b01 << 12;


		while(1){
			GPIOA->ODR |= 1 << 6; // liga
			Delay_ms(250);
			GPIOA->ODR &= ~(1 << 6); // desliga
			Delay_ms(250);
			GPIOA->ODR |= 1 << 6; // liga
			Delay_ms(250);
			GPIOA->ODR &= ~(1 << 6); // desliga
			Delay_ms(250);

		}
}

void questao2(void){
	Utility_Init();
		//liga o clock de GPIOA
		RCC-> AHB1ENR |= 1;

		//configurando os pino pa6 como saída
		GPIOA->MODER |= 0b01 << 12;


		while(1){
			GPIOA->ODR |= 1 << 6; // liga
			Delay_ms(2000);
			GPIOA->ODR &= ~(1 << 6); // desliga
			Delay_ms(100);
			GPIOA->ODR |= 1 << 6; // liga
			Delay_ms(2000);
			GPIOA->ODR &= ~(1 << 6); // desliga
			Delay_ms(100);

		}
}

void questao3(void){
	Utility_Init();
		//liga o clock de GPIOA
		RCC-> AHB1ENR |= 1;

		//configurando os pino pa6 como saída
		GPIOA->MODER |= 0b01 << 12;


		while(1){
			GPIOA->ODR &= ~(1 << 6); // desliga
			Delay_ms(50);
			GPIOA->ODR |= 1 << 6; // liga
			Delay_ms(1000);
			GPIOA->ODR &= ~(1 << 6); // desliga
			Delay_ms(50);
			GPIOA->ODR |= 1 << 6; // liga
			Delay_ms(50);
			GPIOA->ODR &= ~(1 << 6); // desliga
			Delay_ms(50);
			GPIOA->ODR |= 1 << 6; // liga
			Delay_ms(2000);

		}
}

void questao4(void){
	Utility_Init();
		//liga o clock de GPIOA
		RCC-> AHB1ENR |= 1;

		//configurando os pino pa6 como saída
		GPIOA->MODER |= 0b01 << 12;


		while(1){
			int tempo = 1000;
			for(int i = 0; i <= 100; i++){
				GPIOA->ODR &= ~(1 << 6);
				Delay_ms(50);
				GPIOA->ODR |= 1 << 6;
				Delay_ms(tempo);
				tempo -= 10;
			}

		}
}

void questao5(void){
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

void questao6(void){
	Utility_Init();
	//liga o clock de GPIOA
	RCC-> AHB1ENR |= 1;

	//configurando os pino pa6 como saída
	GPIOA->MODER |= 0b01 << 12;

	while(1){

		int tempo = 1000;
		while(tempo >= 0){
			GPIOA->ODR |= 1 << 6;
			Delay_us(1);
			GPIOA->ODR &= ~(1 << 6);
			Delay_us(1000-tempo);

		}
	}
}

void questao7(void){
	Utility_Init();
	//liga o clock de GPIOA
	RCC-> AHB1ENR |= 1;

	//configurando os pino pa6 como saída
	GPIOA->MODER |= 0b01 << 12;

	while(1){
		int tempo = 0;
		while(tempo <= 2000 ){
			GPIOA->ODR |= 1 << 6; // liga
			Delay_us(tempo);
			GPIOA->ODR &= ~(1 << 6); // desliga
			Delay_us(2000-tempo);
			++tempo;
		}

		tempo = 2000;
		while(tempo >= 0 ){
			GPIOA->ODR |= 1 << 6; // liga
			Delay_us(tempo);
			GPIOA->ODR &= ~(1 << 6); // desliga
			Delay_us(2000-tempo);
			--tempo;
	}
}
}

void questao8(void){
	Utility_Init();
	//liga o clock de GPIOA
	RCC-> AHB1ENR |= 1;

	//configurando os pinos pa6 e pa7 como saídas

	GPIOA->MODER |= 0b01 << 12;
	GPIOA->MODER |= 0b01 << 14;

	while(1){
		GPIOA->ODR |= 1 << 6; // liga
		GPIOA->ODR &= ~(1 << 7); // desliga
		Delay_ms(250);
		GPIOA->ODR |= 1 << 7; // liga
		GPIOA->ODR &= ~(1 << 6); // desliga
		Delay_ms(250);
	}
}

void questao9(void){
	Utility_Init();
	//liga o clock de GPIOA
	RCC-> AHB1ENR |= 1;

	//configurando os pino pa6 e pa7 como saídas
	GPIOA->MODER |= 0b01 << 12;
	GPIOA->MODER |= 0b01 << 14;

	while(1){
		GPIOA->ODR |= 1 << 6; // desliga
		GPIOA->ODR |= 1 << 7; // desliga
		Delay_ms(1000);
		GPIOA->ODR &= ~(1 << 6); // desliga
		GPIOA->ODR |= 1 << 7; // liga
		Delay_ms(1000);
		GPIOA->ODR |= 1 << 6; // liga
		GPIOA->ODR &= ~(1 << 7); // desliga
		Delay_ms(1000);
		GPIOA->ODR &= ~(1 << 6); // liga
		GPIOA->ODR &= ~(1 << 7); // liga
		Delay_ms(1000);
}
}

void questao10(void){
	Utility_Init();
	//liga o clock de GPIOA
	RCC-> AHB1ENR |= 1;

	//configurando os pino pa6 e pa7 como saídas
	GPIOA->MODER |= 0b01 << 12;
	GPIOA->MODER |= 0b01 << 14;

	while(1){
		int tempo = 0;
		while(tempo <= 1000 ){
			GPIOA->ODR |= 1 << 6; // liga
			GPIOA->ODR &= ~(1 << 7);
			Delay_us(tempo);
			GPIOA->ODR &= ~(1 << 6); // desliga
			GPIOA->ODR |= 1 << 7;
			Delay_us(1000-tempo);
			++tempo;
		}

		tempo = 1000;
		while(tempo >= 0){
			GPIOA->ODR &= ~(1 << 7);
			GPIOA->ODR |= 1 << 6;
			Delay_us(tempo);
			GPIOA->ODR |= 1 << 7;
			GPIOA->ODR &= ~(1 << 6);
			Delay_us(1000-tempo);
			--tempo;
		}
	}
}

void questao11(void){
	Utility_Init();
	//liga o clock de GPIOD
	RCC-> AHB1ENR |= 1 << 3;

	//configurando os pinos pd0 a pd5 como saídas

	GPIOD->MODER |= 0b01;
	GPIOD->MODER |= 0b01 << 2;
	GPIOD->MODER |= 0b01 << 4;
	GPIOD->MODER |= 0b01 << 6;
	GPIOD->MODER |= 0b01 << 8;
	GPIOD->MODER |= 0b01 << 10;
	GPIOD->MODER |= 0b01 << 12;
	GPIOD->MODER |= 0b01 << 14;

	for(int i=0; i <= 255; i++){

		GPIOD->ODR |= i; //liga
		Delay_ms(200);
		GPIOD->ODR &= ~(i); // desliga

	}

}

void questao12(void){
	Utility_Init();
	//liga o clock de GPIOD
	RCC-> AHB1ENR |= 1 << 3;

	//configurando os pinos pd0 a pd5 como saídas

	GPIOD->MODER |= 0b01;
	GPIOD->MODER |= 0b01 << 2;
	GPIOD->MODER |= 0b01 << 4;
	GPIOD->MODER |= 0b01 << 6;
	GPIOD->MODER |= 0b01 << 8;
	GPIOD->MODER |= 0b01 << 10;
	GPIOD->MODER |= 0b01 << 12;
	GPIOD->MODER |= 0b01 << 14;

	while(1){
		int contador = 0;
		while(contador <= 7){
		GPIOD->ODR |= 1 << contador; // liga
		Delay_ms(100);
		GPIOD->ODR &= ~(1 << contador); // desliga
		++contador;
	}

		contador = 6;
		while(contador >= 0){
		GPIOD->ODR |= 1 << contador; // liga
		Delay_ms(100);
		GPIOD->ODR &= ~(1 << contador); // desliga
		--contador;
	}
}
}

void questao13(void){
	Utility_Init();
	//liga o clock de GPIOD
	RCC-> AHB1ENR |= 1 << 3;

	//configurando os pinos pd0 a pd5 como saídas

	GPIOD->MODER |= 0b01;
	GPIOD->MODER |= 0b01 << 2;
	GPIOD->MODER |= 0b01 << 4;
	GPIOD->MODER |= 0b01 << 6;
	GPIOD->MODER |= 0b01 << 8;
	GPIOD->MODER |= 0b01 << 10;

	while(1){
		GPIOD->ODR |= 1; // liga verde
		GPIOD->ODR |= 1 << 5; //liga vermelho
		Delay_ms(1000);
		GPIOD->ODR &= ~(1); // desliga verde
		GPIOD->ODR |= 1 << 1; //liga amarelo
		Delay_ms(1000);
		GPIOD->ODR &= ~(1 << 1); // desliga amarelo
		GPIOD->ODR |= 1 << 2; //liga vermelho
		GPIOD->ODR &= ~(1 << 5); // desliga vermelho
		GPIOD->ODR |= 1 << 3; //liga verde
		Delay_ms(1000);
		GPIOD->ODR &= ~(1 << 3); // desliga verde
		GPIOD->ODR |= 1 << 4; //liga amarelo
		Delay_ms(1000);
		GPIOD->ODR &= ~(1 << 4); // desliga amarelo
		GPIOD->ODR |= 1 << 5; //liga vermelho
		GPIOD->ODR &= ~(1 << 2); // desliga vermelho
		GPIOD->ODR |= 1 ; //liga verde
		Delay_ms(1000);
	}
}

void questao14(void){
	Utility_Init();
	//liga o clock de GPIOD
	RCC-> AHB1ENR |= 1;

	//configurando os pinos pA1 a pA7 como saídas

	GPIOA->MODER |= 0b01 << 2;
	GPIOA->MODER |= 0b01 << 4;
	GPIOA->MODER |= 0b01 << 6;
	GPIOA->MODER |= 0b01 << 8;
	GPIOA->MODER |= 0b01 << 10;
	GPIOA->MODER |= 0b01 << 12;
	GPIOA->MODER |= 0b01 << 14;

	while(1){
		GPIOA->ODR = 0b00111111 << 1;
		Delay_ms(500);
		GPIOA->ODR = 0b00000110 << 1;
		Delay_ms(500);
		GPIOA->ODR = 0b01011011 << 1;
		Delay_ms(500);
		GPIOA->ODR = 0b01001111 << 1;
		Delay_ms(500);
		GPIOA->ODR = 0b01100110 << 1;
		Delay_ms(500);
		GPIOA->ODR = 0b01111101 << 1;
		Delay_ms(500);
		GPIOA->ODR = 0b01111101 << 1;
		Delay_ms(500);
		GPIOA->ODR = 0b00000111 << 1;
		Delay_ms(500);
		GPIOA->ODR = 0b01111111 << 1;
		Delay_ms(500);
		GPIOA->ODR = 0b01111011 << 1;
		Delay_ms(500);
		GPIOA->ODR = 0b01110111 << 1;
		Delay_ms(500);
		GPIOA->ODR = 0b00011111 << 1;
		Delay_ms(500);
		GPIOA->ODR = 0b01001110 << 1;
		Delay_ms(500);
		GPIOA->ODR = 0b00111101 << 1;
		Delay_ms(500);
		GPIOA->ODR = 0b01001111 << 1;
		Delay_ms(500);
		GPIOA->ODR = 0b01000111 << 1;
		Delay_ms(500);


	}

}

void questao17(void){
	Utility_Init();
	//liga o clock de GPIOA
	RCC-> AHB1ENR |= 1;

	//configurando os pino pa6 como saída
	GPIOA->MODER |= 0b01 << 12;

	int x = 1;

	while(1){
		if(x){
			for(int i=500; i <= 2500; i+=50){
				Delay_ms(20);
				GPIOA->ODR |= 1 << 6;
				Delay_us(i);
				GPIOA->ODR &= ~(1 << 6);
			}
			x = 0;
		}
		else{
			for(int i=2500; i >= 500; i-=50){
				Delay_ms(20);
				GPIOA->ODR |= 1 << 6;
				Delay_us(i);
				GPIOA->ODR &= ~(1 << 6);

			}
			x = 1;
		}


}
}

void questao18(void){
	Utility_Init();
	//liga o clock de GPIOA
	RCC-> AHB1ENR |= 1;

	//configurando os pino pa0, pa1 e pa6 como saída
	GPIOA->MODER |= 0b01;
	GPIOA->MODER |= 0b01 << 2;
	GPIOA->MODER |= 0b01 << 12;

	while(1){
		GPIOA->ODR &= ~(1);
		GPIOA->ODR |= 1 << 1;

		int tempo = 0;
		while(tempo <= 2000 ){
			GPIOA->ODR |= 1 << 6; // liga
			Delay_us(tempo);
			GPIOA->ODR &= ~(1 << 6); // desliga
			Delay_us(2000-tempo);
			++tempo;
		}

		tempo = 2000;
		while(tempo >= 0 ){
			GPIOA->ODR |= 1 << 6; // l	iga
			Delay_us(tempo);
			GPIOA->ODR &= ~(1 << 6); // desliga
			Delay_us(2000-tempo);
			--tempo;
		}

		GPIOA->ODR |= 1;
		GPIOA->ODR &= ~(1 << 1);

		tempo = 0;
		while(tempo <= 2000 ){
			GPIOA->ODR |= 1 << 6; // liga
			Delay_us(tempo);
			GPIOA->ODR &= ~(1 << 6); // desliga
			Delay_us(2000-tempo);
			++tempo;
		}

		tempo = 2000;
		while(tempo >= 0 ){
			GPIOA->ODR |= 1 << 6; // l	iga
			Delay_us(tempo);
			GPIOA->ODR &= ~(1 << 6); // desliga
			Delay_us(2000-tempo);
			--tempo;
		}
}
}

void questao19(void){
	Utility_Init();
	//liga o clock de GPIOA
	RCC-> AHB1ENR |= 1;

	//configurando os pino pa2 como saída
	GPIOA->MODER |= 0b01 << 12;
	GPIOA->OTYPER |= 0b01 << 12;


	while(1){
		GPIOA->ODR |= 1 << 6; // liga
		GPIOA->OTYPER |= 1 << 6; // liga
		Delay_ms(250);
		GPIOA->ODR |= 1 << 6; // liga
		GPIOA->OTYPER &= ~(1 << 6); // desliga
		Delay_ms(250);

	}
}

void questao21(void){
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

void questao22(void){
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

void questao23(void){
	Utility_Init();

	 //ligando o clock da porta E e A
	RCC->AHB1ENR |= (1 | (1 << 4));

	 //configurando pa6 como saída
	 GPIOA->MODER |= 0b01 << 12;

	 //configurando pe4  como entrada
	 GPIOE->MODER &= ~(0b11 << 8);

	 //ligando o resistor de pull-up no pino pe4
	 GPIOE->PUPDR |= (0b01 << 8);


	 while(1){
	/*	 while(k0 && (x % 2 == 0)){
			 GPIOA->ODR |= 1 << 6;
			 x += 1;
		}
		 while(k0 && (x % 2 != 0)){
			 GPIOA->ODR &= ~(1 << 6);
			 x += 1;
		}
	} */
		 // Verificar se o botão K0 foi pressionado
		 if ((GPIOE->IDR & (1 << 4)) == 0) {
			 // Esperar um curto intervalo para evitar debounce
			 Delay_ms(50);
			 // Verificar novamente se o botão K0 continua pressionado
			 if ((GPIOE->IDR & (1 << 4)) == 0) {
				 // Inverter o estado do LED D2
				 GPIOA->ODR ^= (1 << 6);
				 // Esperar até que o botão K0 seja liberado
				 while ((GPIOE->IDR & (1 << 4)) == 0) {
					 Delay_ms(50);
				 }
			 }
		 }
	 }
}

void questao24(void){
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

 }
}

void questao25(void){
	Utility_Init();

	RCC->AHB1ENR |= 1;         //habilita o clock do GPIOA
	RCC->AHB1ENR |= 1<<4;    //habilita o clock do GPIOE

	//configurando PA6 como saída (o pino PA6 tem um LED conectado)
	GPIOA->MODER |= (0b01 << 12);

	//Configurando o pino PE3 como entrada
	GPIOE->MODER &= ~(0b11 << 6);
	GPIOE->PUPDR |= (0b01 << 6);    //habilita o resistor de pull up para garantir nível lógico alto quando o botão estiver solto
	//Configurando o pino PE4 como entrada
	GPIOE->MODER &= ~(0b11 << 8);
	GPIOE->PUPDR |= (0b01 << 8);    //habilita o resistor de pull up para garantir nível lógico alto quando o botão estiver solto

	while(1){
		(GPIOA->ODR |= (1 << 6));

		if(k0 && !k1){
			uint32_t a = 0;
			while(k0){
				Delay_ms(100);
				if(k1){
					if(a<=1000){
						(GPIOA->ODR &= ~(1 << 6));
					}
				}
				else{
					(GPIOA->ODR |= (1 << 6));
				}
				a += 100;
			}
		}
	}
}

void questao26(void){
	Utility_Init();
	//liga o clock de GPIOA e GPIOE
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN | RCC_AHB1ENR_GPIOAEN;

	//configurando os pino pa6 como saída
	GPIOA->MODER |= 0b01 << 12;

	//configurando pe4 e pe3 como entrada
	 GPIOE->MODER &= ~(0b11 << 8);
	 GPIOE->MODER &= ~(0b11 << 6);

	 //ligando o resistor de pull-up no pino pe4 e pe3
	 GPIOE->PUPDR |= (0b01 << 8);
	 GPIOE->PUPDR |= (0b01 << 6);


	while(1){
		if(k1 && !(k0)){

				Delay_ms(20);
				GPIOA->ODR |= 1 << 6;
				Delay_us(500);
				GPIOA->ODR &= ~(1 << 6);

		}
		if(k0 && !(k1)){
				Delay_ms(20);
				GPIOA->ODR |= 1 << 6;
				Delay_us(2500);
				GPIOA->ODR &= ~(1 << 6);


		}

}
}
