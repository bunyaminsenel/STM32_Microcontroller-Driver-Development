/*
 * GPIO.h
 *
 *  Created on: 26 Apr 2022
 *      Author: Bunyamin
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "stm32f767xx.h"

/*
 * @def_group GPIO_Pins
 */

#define GPIO_PIN_0	(uint16_t)0x0001	/* GPIO Pin 0 Selected*/
#define GPIO_PIN_1	(uint16_t)0x0002	/* GPIO Pin 1 Selected*/
#define GPIO_PIN_2	(uint16_t)0x0004	/* GPIO Pin 2 Selected*/
#define GPIO_PIN_3	(uint16_t)0x0008	/* GPIO Pin 3 Selected*/
#define GPIO_PIN_4	(uint16_t)0x0010	/* GPIO Pin 4 Selected*/
#define GPIO_PIN_5	(uint16_t)0x0020	/* GPIO Pin 5 Selected*/
#define GPIO_PIN_6	(uint16_t)0x0040	/* GPIO Pin 6 Selected*/
#define GPIO_PIN_7	(uint16_t)0x0080	/* GPIO Pin 7 Selected*/
#define GPIO_PIN_8	(uint16_t)0x0100	/* GPIO Pin 8 Selected*/
#define GPIO_PIN_9	(uint16_t)0x0200	/* GPIO Pin 9 Selected*/
#define GPIO_PIN_10	(uint16_t)0x0400	/* GPIO Pin 10 Selected*/
#define GPIO_PIN_11 (uint16_t)0x0800	/* GPIO Pin 11 Selected*/
#define GPIO_PIN_12	(uint16_t)0x1000	/* GPIO Pin 12 Selected*/
#define GPIO_PIN_13	(uint16_t)0x2000	/* GPIO Pin 13 Selected*/
#define GPIO_PIN_14	(uint16_t)0x4000	/* GPIO Pin 14 Selected*/
#define GPIO_PIN_15	(uint16_t)0x8000	/* GPIO Pin 15 Selected*/
#define GPIO_PIN_ALL(uint16_t)0xFFFF	/* GPIO Pin All Selected*/

/*
 * @def_group GPIO_Pin_Modes
 */

#define GPIO_MODE_INPUT		(0X0U)
#define GPIO_MODE_OUTPUT	(0X1U)
#define GPIO_MODE_AF		(0X2U)
#define GPIO_MODE_ANALOG	(0X3U)

/*
 * @def_group GPIO_Otype_Modes
 */

#define OTYPE_PP		(0x0U)
#define OTYPE_OD		(0x1U)

/*
 * @def_group PuPd_Modes
 */

#define PUPD_NOPULL		(0x0U)
#define PUPD_PULLUP		(Ox1U)
#define PUPD_PULLDOWN	(0x2U)
#define RESERVED		(0x3U)

/*
 * @def_group Speed_Modes
 */
#define	SPEED_LOW		(0X0U)
#define SPEED_MEDIUM	(0X1U)
#define SPEED_HIGH		(0X2U)
#define SPEED_VERYHIGH	(0X3U)


typedef enum{

	GPIO_PIN_RESET = 0,
	GPIO_PIN_SET
}GPIO_Pin_State_t;

typedef struct{

	uint32_t pinNumber; /* GPIO Pin Numbers @def_group GPIO_Pins 		 */
	uint32_t Mode;		/* GPIO Pin Numbers @def_group GPIO_Pin_Modes 	 */
	uint32_t Otype;		/* GPIO Pin Numbers @def_group GPIO_Otype_Modes  */
	uint32_t PuPd;		/* GPIO Pin Numbers @def_group GPIO_PuPd_Modes  */
	uint32_t Speed;		/* GPIO Pin Numbers @def_group GPIO_Speed_Modes  */
	uint32_t Alternate;


}GPIO_InitTypeDef_t;

void GPIO_Init(GPIO_TypeDef_t* GPIOx, GPIO_InitTypeDef_t* GPIO_ConfigStruct );


void GPIO_WritePin(GPIO_TypeDef_t* GPIOx, uint16_t pinNumber,GPIO_Pin_State_t pinState );

GPIO_Pin_State_t GPIO_ReadPin(GPIO_TypeDef_t* GPIOx, uint16_t pinNumber);

void GPIO_LockPin(GPIO_TypeDef_t* GPIOx, uint16_t pinNumber);

void GPIO_Toggle(GPIO_TypeDef_t* GPIOx, uint16_t pinmuber);


#endif /* INC_GPIO_H_ */
