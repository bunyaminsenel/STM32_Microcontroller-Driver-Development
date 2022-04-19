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



#endif /* INC_STM32F767XX_H_ */
