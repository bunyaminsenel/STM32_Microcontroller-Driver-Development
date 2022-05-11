/*
 * GPIO.c
 *
 *  Created on: 26 Apr 2022
 *      Author: Bunyamin
 */

#include "GPIO.h"

void GPIO_Init(GPIO_TypeDef_t* GPIOx, GPIO_InitTypeDef_t* GPIO_ConfigStruct ){

	uint32_t possion;
	uint32_t fakepossion = 0;
	uint32_t lastpossion = 0;
	for(possion = 0; possion < 16; possion++){

		fakepossion = (0x1 << possion);
		lastpossion = (uint32_t)(GPIO_ConfigStruct->pinNumber) & fakepossion;

		if (fakepossion == lastpossion){

			/* Mode Config */
			uint32_t tempValue = GPIOx->MODER;
			tempValue &= ~(0x3U << (possion * 2));
			tempValue |= (GPIO_ConfigStruct->Mode << (possion * 2 ));

			GPIOx->MODER = tempValue;

			if(GPIO_ConfigStruct->Mode == GPIO_MODE_OUTPUT || GPIO_MODE_AF){

				/* Otype Config */
				tempValue = GPIOx->OTYPER;
				tempValue &= ~(0x1 << possion);
				tempValue |= (GPIO_ConfigStruct->Otype << possion );
				GPIOx->OTYPER = tempValue;

				/* Speed Config */
				tempValue = GPIOx->OSPEEDR;
				tempValue &= ~(0x3U << (possion * 2));
				tempValue |= ((GPIO_ConfigStruct->Speed << possion * 2 ) );
				GPIOx->OSPEEDR = tempValue;

			}

			/* PUPD Config */
			tempValue = GPIOx->PUPDR;
			tempValue &= ~(0x3U << ( possion * 2 ) );
			tempValue |= (GPIO_ConfigStruct->PuPd << (possion * 2 ));
			GPIOx->PUPDR = tempValue;
		}
	}

}


void GPIO_WritePin(GPIO_TypeDef_t* GPIOx, uint16_t pinNumber, GPIO_Pin_State_t pinState ){

	if (pinState == GPIO_PIN_SET){
		GPIOx->BSRR = pinNumber;
	}
	else{
		GPIOx->BSRR = ( pinNumber << 0x10U );
	}
}

/**
  * @brief  Sets or clears the selected data port bit.
  *
  * @note   This function uses GPIOx_BSRR register to allow atomic read/modify
  *         accesses. In this way, there is no risk of an IRQ occurring between
  *         the read and the modify access.
  *
  * @param  GPIOx where x can be (A..E) to select the GPIO peripheral.
  *
  * @param  GPIO_Pin specifies the port bit to be written.
  *          This parameter can be one of GPIO_PIN_x where x can be (0..15).
  *
  * @param  PinState specifies the value to be written to the selected bit.
  *          This parameter can be one of the GPIO_PinState enum values:
  *            @arg GPIO_PIN_RESET: to clear the port pin
  *            @arg GPIO_PIN_SET: to set the port pin
  * @retval None
  */

GPIO_Pin_State_t GPIO_Read_PIN(GPIO_TypeDef_t* GPIOx, uint16_t pinNumber){

	GPIO_Pin_State_t bitstatus = GPIO_PIN_RESET;

	if( ( GPIOx->IDR & pinNumber) != GPIO_PIN_RESET ) {

		bitstatus = GPIO_PIN_SET;
	}

	return bitstatus;

}

void GPIO_LockPin(GPIO_TypeDef_t* GPIOx, uint16_t pinNumber){

	uint32_t temp = ( 0x1 << 16 ) | pinNumber;
	GPIOx->LCKR = temp ;
	GPIOx->LCKR = pinNumber;
	GPIOx->LCKR = temp;
	temp = GPIOx->LCKR;

}

void GPIO_Toggle(GPIO_TypeDef_t* GPIOx, uint16_t pinmuber){

	uint32_t tempODR = GPIOx->ODR;
	GPIOx->BSRR = ( (tempODR & pinmuber) << 16U ) | ( (~tempODR) & (pinmuber) );
}





