/*
 * stm32f767xx.h
 *
 *  Created on: Apr 18, 2022
 *      Author: Bunyamin
 */

#ifndef INC_STM32F767XX_H_
#define INC_STM32F767XX_H_

#include <stdint.h>
#include <stdio.h>

#include "RCC.h"

#define __IO volatile

#define SET_BITS(REG,BIT) 			( (REG) |= (BIT) )
#define CLEAR_BITS(REG,BIT)			( (REG) &= ~(BIT) )
#define READ_BITS(REG,BIT)			( (REG) &  (BIT) )

/*
 * 	Memory Bade Address
 */

#define FLASH_BASE_ADDR			(0x08000000UL) /* Flash Base Address (up to 2MB) */
#define SRAM1_BASE_ADDR			(0x20020000UL) /* SRAM Base Address 368KB 		 */
#define SRAM2_BASE_ADDR			(0x2007C000UL) /* SRAM2 Base Address 16KB 		 */

/*
 * 	Peripheral Base Address
 */

#define PERIPH_BASE_ADDR		(0x40000000UL) 				   		/* Base Address for All Peripherals */

#define APB1_BASE_ADDR			 PERIPH_BASE_ADDR 			   		/* APB1 Bus Domain Base Address     */
#define APB2_BASE_ADDR			(PERIPH_BASE_ADDR + 0x00010000UL) 	/* APB2 Bus Domain Base Address     */
#define AHB1_BASE_ADDR			(PERIPH_BASE_ADDR + 0x00020000UL) 	/* AHB1 Bus Domain Base Address     */
#define AHB2_BASE_ADDR			(PERIPH_BASE_ADDR + 0x10000000UL) 	/* AHB2 Bus Domain Base Address     */

/*
*  APB1 Peripherals Base Address
*/

#define TIM2_BASE_ADDR          (APB1_BASE_ADDR + 0x0000UL)         /* TIMER2 Base Address */
#define TIM3_BASE_ADDR          (APB1_BASE_ADDR + 0x0400UL)         /* TIMER3 Base Address */
#define TIM4_BASE_ADDR          (APB1_BASE_ADDR + 0x0800UL)         /* TIMER4 Base Address */
#define TIM5_BASE_ADDR          (APB1_BASE_ADDR + 0x0C00UL)         /* TIMER5 Base Address */
#define TIM6_BASE_ADDR          (APB1_BASE_ADDR + 0x1000UL)         /* TIMER6 Base Address */
#define TIM7_BASE_ADDR          (APB1_BASE_ADDR + 0x1400UL)         /* TIMER7 Base Address */

#define SPI2_BASE_ADDR          (APB1_BASE_ADDR + 0x3800UL)         /* SPI2 Base Address */
#define SPI3_BASE_ADDR          (APB1_BASE_ADDR + 0x3C00UL)         /* SPI3 Base Address */

#define USART2_BASE_ADRR        (APB1_BASE_ADDR + 0x4400UL)         /* USART2 Base Address */
#define USART3_BASE_ADRR        (APB1_BASE_ADDR + 0x4800UL)         /* USART2 Base Address */
#define UART4_BASE_ADRR         (APB1_BASE_ADDR + 0x4C00UL)         /* UART4 Base Address  */
#define UART5_BASE_ADRR         (APB1_BASE_ADDR + 0x5000UL)         /* UART5 Base Address  */ 
    
#define I2C1_BASE_ADDR          (APB1_BASE_ADDR + 0x5400UL)         /* I2C1 Base Address  */
#define I2C2_BASE_ADDR          (APB1_BASE_ADDR + 0x5800UL)         /* I2C2 Base Address  */
#define I2C3_BASE_ADDR          (APB1_BASE_ADDR + 0x5C00UL)         /* I2C3 Base Address  */
#define I2C4_BASE_ADDR          (APB1_BASE_ADDR + 0x6000UL)         /* I2C4 Base Address  */

/*
*  APB2 Peripherals Base Address
*/

#define TIM1_BASE_ADDR          (APB2_BASE_ADDR + 0x0000UL)         /* TIM1 Base Address  */
#define TIM8_BASE_ADDR          (APB2_BASE_ADDR + 0x0400UL)         /* TIM2 Base Address  */

#define USART1_BASE_ADDR        (APB2_BASE_ADDR + 0x1000UL)         /* USART1 Base Address */
#define USART6_BASE_ADDR        (APB2_BASE_ADDR + 0x1400UL)         /* USART6 Base Address */

#define SPI1_BASE_ADDR          (APB2_BASE_ADDR + 0x3000UL)         /* SPI1 Base Address   */    
#define SPI4_BASE_ADDR          (APB2_BASE_ADDR + 0x3400UL)         /* SPI2 Base Address   */

#define SYSCFG_BASE_ADRR        (APB2_BASE_ADDR + 0x3800UL)         /* SYSCFG Base Address */
#define EXTI_BASE_ADDR          (APB2_BASE_ADDR + 0x3C00UL)         /* EXTI Base Address   */

/*
*  AHB1 Peripherals Base Address
*/

#define GPIOA_BASE_ADDR         (AHB1_BASE_ADDR + 0x0000UL)          /* GPIOA Base Address  */
#define GPIOB_BASE_ADDR         (AHB1_BASE_ADDR + 0x0400UL)          /* GPIOB Base Address  */
#define GPIOC_BASE_ADDR         (AHB1_BASE_ADDR + 0x0800UL)          /* GPIOC Base Address  */
#define GPIOD_BASE_ADDR         (AHB1_BASE_ADDR + 0x0C00UL)          /* GPIOD Base Address  */
#define GPIOE_BASE_ADDR         (AHB1_BASE_ADDR + 0x1000UL)          /* GPIOE Base Address  */

#define RCC_BASE_ADDR           (AHB1_BASE_ADDR + 0x3800UL)           /* RCC Base Address  */

/*
*   Peripherals Structure Definitions
*/

typedef struct 
{
	__IO    uint32_t MODER;			/* <!GPIO port mode register 				Address Offset = 0x0000 >*/
	__IO    uint32_t OTYPER;		/* <!GPIO port output type register 		Address Offset = 0x0004 >*/
	__IO    uint32_t OSPEEDR;		/* <!GPIO port output speed register 		Address Offset = 0x0008 >*/
	__IO    uint32_t PUPDR;			/* <!GPIO port pull-up/pull-down register 	Address Offset = 0x000C	>*/
	__IO    uint32_t IDR;			/* <!GPIO port input data register 			Address Offset = 0x0010 >*/
	__IO    uint32_t ODR;			/* <!GPIO port output data register 		Address Offset = 0x0014 >*/
	__IO    uint32_t BSRR;			/* <!GPIO port bit set/reset register 		Address Offset = 0x0018 >*/
	__IO    uint32_t LCKR;			/* <!GPIO port configuration lock register 	Address Offset = 0x001C >*/
	__IO    uint32_t AFR[2];		/* <!GPIO alternate function  register 		Address Offset = 0x0020 >*/

}GPIO_TypeDef_t;

typedef struct{

	__IO uint32_t RCC_CR;				/* <!RCC clock control register 					Address Offset = 0x0000 >*/
	__IO uint32_t RCC_PLLCFGR;			/* <!RCC PLL configuration register 				Address Offset = 0x0004 >*/
	__IO uint32_t RCC_CFGR;				/* <!RCC clock configuration register 				Address Offset = 0x0008 >*/
	__IO uint32_t RCC_CIR;				/* <!RCC clock interrupt register 					Address Offset = 0x000C >*/
	__IO uint32_t RCC_AHB1RSTR;			/* <!RCC AHB1 peripheral reset register 			Address Offset = 0x0010	>*/
	__IO uint32_t RCC_AHB2RSTR;			/* <!RCC AHB2 peripheral reset register 			Address Offset = 0x0014 >*/
	__IO uint32_t RCC_AHB3RSTR;			/* <!RCC AHB3 peripheral reset register 			Address Offset = 0x0018 >*/
	__IO uint32_t Reserved0;			/* <!Reserved  register 							Address Offset = 0x001C >*/
	__IO uint32_t RCC_APB1RSTR;			/* <!RCC APB1 peripheral reset register 			Address Offset = 0x0020 >*/
	__IO uint32_t RCC_APB2RSTR;			/* <!RCC APB2 peripheral reset register 			Address Offset = 0x0024 >*/
	__IO uint32_t Reserved1;			/* <!Reserved1  register 							Address Offset = 0x0028 >*/
	__IO uint32_t Reserved2;			/* <!Reserved2  register 							Address Offset = 0x002C >*/
	__IO uint32_t RCC_AHB1ENR;			/* <!RCC AHB1 peripheral clock register 			Address Offset = 0x0030 >*/
	__IO uint32_t RCC_AHB2ENR;			/* <!RCC AHB2 peripheral clock enable register 		Address Offset = 0x0034 >*/
	__IO uint32_t RCC_AHB3ENR;			/* <!RCC AHB3 peripheral clock enable register 		Address Offset = 0x0038 >*/
	__IO uint32_t Reserved3;			/* <!Reserved3  register 							Address Offset = 0x003C >*/
	__IO uint32_t RCC_APB1ENR;			/* <!RCC APB1 peripheral clock enable register 		Address Offset = 0x0040 >*/
	__IO uint32_t RCC_APB2ENR;			/* <!RCC APB2 peripheral clock enable register 		Address Offset = 0x0044 >*/
	__IO uint32_t Reserved4;			/* <!Reserved4  register			 				Address Offset = 0x0048 >*/
	__IO uint32_t Reserved5;			/* <!Reserved5  register 							Address Offset = 0x004C >*/
	__IO uint32_t RCC_AHB1LPENR;		/* <!RCC AHB1 peripheral clock enable in low-power mode register 	Address Offset = 0x0050 >*/
	__IO uint32_t RCC_AHB2LPENR;		/* <!RCC AHB1 peripheral clock enable in low-power mode register 	Address Offset = 0x0054 >*/
	__IO uint32_t RCC_AHB3LPENR;		/* <!RCC AHB2 peripheral clock enable in low-power mode register 	Address Offset = 0x0058 >*/
	__IO uint32_t Reserved6;			/* <!Reserved5  register 							Address Offset = 0x005C >*/
	__IO uint32_t RCC_APB1LPENR;		/* <!RCC APB1 peripheral clock enable in low-power mode register 	Address Offset = 0x0060 >*/
	__IO uint32_t RCC_APB2LPENR;		/* <!RCC APB2 peripheral clock enable in low-power mode register 	Address Offset = 0x0064 >*/
	__IO uint32_t Reserved7;			/* <!Reserved7  register 							Address Offset = 0x0068 >*/
	__IO uint32_t Reserved8;			/* <!Reserved8  register 							Address Offset = 0x006C >*/
	__IO uint32_t RCC_BDCR;				/* <!RCC backup domain control register 			Address Offset = 0x0070 >*/
	__IO uint32_t RCC_CSR;				/* <!RCC clock control & status register 			Address Offset = 0x0074 >*/
	__IO uint32_t Reserved9;			/* <!Reserved9  register 							Address Offset = 0x0078 >*/
	__IO uint32_t Reserved10;			/* <!Reserved10  register 							Address Offset = 0x007C >*/
	__IO uint32_t RCC_SSCGR;			/* <!RCC spread spectrum clock generation register 	Address Offset = 0x0080 >*/
	__IO uint32_t RCC_PLLI2SCFGR;		/* <!RCC PLLI2S configuration register 				Address Offset = 0x0084 >*/
	__IO uint32_t RCC_PLLSAICFGR;		/* <!RCC PLLSAI configuration register 				Address Offset = 0x0088 >*/
	__IO uint32_t RCC_DCKCFGR1;			/* <!RCC dedicated clocks configuration register 	Address Offset = 0x008C >*/
	__IO uint32_t RCC_DCKCFGR2;			/* <!RCC dedicated clocks configuration register 	Address Offset = 0x0090 >*/

}RCC_TypeDef_t;

typedef struct{
	__IO uint32_t MEMRMP;				/* <! SYSCFG memory remap register 						Address Offset = 0x0000 */
	__IO uint32_t PMC;					/* <! SYSCFG peripheral mode configuration register 	Address Offset = 0x0004 */
	__IO uint32_t EXTICR[4];			/* <! SYSCFG external interrupt configuration registers Address Offset = 0x0008 */
	__IO uint32_t CBR;					/* <! Class B register									Address Offset = 0x001C */
	__IO uint32_t CMPCR;				/* <! Compensation cell control register				Address Offset = 0x0020 */


}SYSCFG_TypeDef_t;

#define GPIOA			( (GPIO_TypeDef_t* )(GPIOA_BASE_ADDR) )
#define GPIOB           ( (GPIO_TypeDef_t* )(GPIOB_BASE_ADDR) )
#define GPIOC           ( (GPIO_TypeDef_t* )(GPIOC_BASE_ADDR) )
#define GPIOD           ( (GPIO_TypeDef_t* )(GPIOD_BASE_ADDR) )
#define GPIOE           ( (GPIO_TypeDef_t* )(GPIOE_BASE_ADDR) )

#define RCC				( (RCC_TypeDef_t *)(RCC_BASE_ADDR))

#define SYSCFG			( (SYSCFG_BASE_ADRR*)(SYSCFG_BASE_ADRR) )

/*
 * BIT Definitions
 */

#define RCC_AHB1ENR_GPIOAEN_Pos		(0U)								// RCC AHB1ENR register GPIOAEN Bit Position
#define RCC_AHB1ENR_GPIOAEN_Msk		(0x01 << RCC_AHB1ENR_GPIOAEN_Pos) 	// RCC AHB1ENR register GPIOAEN Bit Mask
#define	RCC_AHB1_GPIOAEN			RCC_AHB1ENR_GPIOAEN_Msk				// RCC AHB!ENR register GPIOAEN Macro

#define RCC_AHB1ENR_GPIOBEN_Pos		(1U)								// RCC AHB1ENR register GPIOBEN Bit Position
#define RCC_AHB1ENR_GPIOBEN_Msk		(0x01 << RCC_AHB1ENR_GPIOBEN_Pos) 	// RCC AHB1ENR register GPIOBEN Bit Mask
#define	RCC_AHB1_GPIOBEN			RCC_AHB1ENR_GPIOBEN_Msk				// RCC AHB!ENR register GPIOBEN Macro

#define RCC_AHB1ENR_GPIOCEN_Pos		(2U)								// RCC AHB1ENR register GPIOCEN Bit Position
#define RCC_AHB1ENR_GPIOCEN_Msk		(0x01 << RCC_AHB1ENR_GPIOCEN_Pos) 	// RCC AHB1ENR register GPIOCEN Bit Mask
#define	RCC_AHB1_GPIOCEN			RCC_AHB1ENR_GPIOCEN_Msk				// RCC AHB!ENR register GPIOCEN Macro

#define RCC_AHB1ENR_GPIODEN_Pos		(3U)								// RCC AHB1ENR register GPIODEN Bit Position
#define RCC_AHB1ENR_GPIODEN_Msk		(0x01 << RCC_AHB1ENR_GPIODEN_Pos) 	// RCC AHB1ENR register GPIODEN Bit Mask
#define	RCC_AHB1_GPIODEN			RCC_AHB1ENR_GPIODEN_Msk				// RCC AHB!ENR register GPIODEN Macro

#define RCC_AHB1ENR_GPIOEEN_Pos		(4U)								// RCC AHB1ENR register GPIOEEN Bit Position
#define RCC_AHB1ENR_GPIOEEN_Msk		(0x01 << RCC_AHB1ENR_GPIOEEN_Pos) 	// RCC AHB1ENR register GPIOEEN Bit Mask
#define	RCC_AHB1_GPIOEEN			RCC_AHB1ENR_GPIOEEN_Msk				// RCC AHB!ENR register GPIOEEN Macro


#endif /* INC_STM32F767XX_H_ */
