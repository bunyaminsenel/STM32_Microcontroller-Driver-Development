/*
 * stm32f767xx.h
 *
 *  Created on: Apr 18, 2022
 *      Author: Bunyamin
 */

#ifndef INC_STM32F767XX_H_
#define INC_STM32F767XX_H_

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
#define SPI2_BASE_ADDR          (APB2_BASE_ADDR + 0x3400UL)         /* SPI2 Base Address   */

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

#endif /* INC_STM32F767XX_H_ */
