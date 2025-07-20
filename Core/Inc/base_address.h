/*
 * base_address_register.h
 *
 *  Created on: Mar 30, 2025
 *      Author: 84903
 */

#ifndef INC_BASE_ADDRESS_REGISTER_H_
#define INC_BASE_ADDRESS_REGISTER_H_

#define GPIOA_BASE_ADDR 	0x40020000
#define GPIOB_BASE_ADDR 	0X40020400
#define GPIOC_BASE_ADDR 	0x40020800
#define GPIOD_BASE_ADDR 	0x40020C00
#define GPIOE_BASE_ADDR 	0x40021000
#define GPIOH_BASE_ADDR 	0x40021C00

#define EXTI_BASE_ADDR		0x40013C00

#define UART1_BASE_ADDR		0x40011000

#define I2C_BASE_ADDR		0x40005400

#define SPI1_BASE_ADDR		0x40013000

#define ADC1_BASE_ADDR		0x40012000

//Timer
#define TIM1_BASE_ADDR		0x40010000	 //16bit
#define TIM2_BASE_ADDR		0x40000000	 //32bit
#define TIM3_BASE_ADDR 		0x40000400   //16bit
#define TIM4_BASE_ADDR		0x40000800	 //16bit
#define TIM5_BASE_ADDR		0x40000C00	 //32bit

// GPIO OFFSET
#define offset_MODER_ADDR   	0x00
#define offset_OTYPER_ADDR  	0x04
#define offset_OSPEEDR_ADDR 	0x08
#define offset_PUPDR_ADDR   	0x0C
#define offset_IDR_ADDR     	0x10
#define offset_ODR_ADDR     	0x14
#define offset_BSRR_ADDR		0x18
#define offset_AFRL_ADDR		0x20
#define offset_AFRH_ADDR		0x24

//EXTI and EXTI0 offset
#define offset_IMR				0x00
#define offset_EMR				0x04
#define offset_RTSR				0x08
#define offset_FTSR				0x0C
#define offset_SWIER			0x10
#define offset_PR				0x14

//UART1 offset
#define offset_USART1_SR				0x00
#define offset_USART1_DR				0x04
#define offset_USART1_BRR				0x08
#define offset_USART1_CR1				0x0C
#define offset_USART1_CR2				0x10
#define offset_USART1_CR3				0x14
#define offset_USART1_GTPR				0x18

//I2C offset
#define offset_CR1				0x00
#define offset_CR2				0x04
#define offset_OAR1				0x08
#define offset_OAR2				0x12
#define offset_DR				0x10
#define offset_SR1				0x14
#define offset_SR2				0x18
#define offset_CRR				0x1C
#define offset_TRISE			0x20
#define offset_FLTR				0x24

//SPI1 offset
#define offset_SPI_CR1			0x00
#define offset_SPI_CR2			0x04
#define offset_SPI_SR			0x08
#define offset_SPI_DR			0x0C
#define offset_SPI_CRCPR		0x10
#define offset_SPI_RXCRCR		0x14
#define offset_SPI_TXCRCR		0x18

//TIM1 offset
#define offset_TIM1_CR1			0x00
#define offset_TIM1_CR2			0x04
#define offset_TIM1_SMCR		0x08
#define offset_TIM1_DIER		0x0C
#define offset_TIM1_SR			0x10
#define offset_TIM1_EGR			0x14
#define offset_TIM1_CCMR1		0x18
#define offset_TIM1_CCMR2		0x1C
#define offset_TIM1_CCER		0x20
#define offset_TIM1_CNT			0x24
#define offset_TIM1_PSC			0x28
#define offset_TIM1_ARR			0x2C
#define offset_TIM1_RCR			0x30
#define offset_TIM1_CCR1		0x34
#define offset_TIM1_CCR2		0x38
#define offset_TIM1_CCR3		0x3C
#define offset_TIM1_CCR4		0x40
#define offset_TIM1_BDTR		0x44
#define offset_TIM1_DCR			0x48
#define offset_TIM1_DMAR		0x4C

//ADC1 offset
#define offset_ADC_SR			0x00
#define offset_ADC_CR1			0x04
#define offset_ADC_CR2			0x08
#define offset_ADC_JSQR			0x38

//MODER
#define GPIOA_MODER		((volatile uint32_t*)(GPIOA_BASE_ADDR + offset_MODER_ADDR))
#define GPIOB_MODER		((volatile uint32_t*)(GPIOB_BASE_ADDR + offset_MODER_ADDR))
#define GPIOC_MODER		((volatile uint32_t*)(GPIOC_BASE_ADDR + offset_MODER_ADDR))
#define GPIOD_MODER		((volatile uint32_t*)(GPIOD_BASE_ADDR + offset_MODER_ADDR))
#define GPIOE_MODER		((volatile uint32_t*)(GPIOE_BASE_ADDR + offset_MODER_ADDR))
#define GPIOH_MODER		((volatile uint32_t*)(GPIOH_BASE_ADDR + offset_MODER_ADDR))

//OTYPER
#define GPIOA_OTYPER	((volatile uint32_t*)(GPIOA_BASE_ADDR + offset_OTYPER_ADDR))
#define GPIOB_OTYPER	((volatile uint32_t*)(GPIOB_BASE_ADDR + offset_OTYPER_ADDR))
#define GPIOC_OTYPER	((volatile uint32_t*)(GPIOC_BASE_ADDR + offset_OTYPER_ADDR))
#define GPIOD_OTYPER	((volatile uint32_t*)(GPIOD_BASE_ADDR + offset_OTYPER_ADDR))
#define GPIOE_OTYPER	((volatile uint32_t*)(GPIOE_BASE_ADDR + offset_OTYPER_ADDR))
#define GPIOH_OTYPER	((volatile uint32_t*)(GPIOH_BASE_ADDR + offset_OTYPER_ADDR))

//OSPEEDR
#define GPIOA_OSPEEDR	((volatile uint32_t*)(GPIOA_BASE_ADDR + offset_OSPEEDR_ADDR))
#define GPIOB_OSPEEDR	((volatile uint32_t*)(GPIOB_BASE_ADDR + offset_OSPEEDR_ADDR))
#define GPIOC_OSPEEDR	((volatile uint32_t*)(GPIOC_BASE_ADDR + offset_OSPEEDR_ADDR))
#define GPIOD_OSPEEDR	((volatile uint32_t*)(GPIOD_BASE_ADDR + offset_OSPEEDR_ADDR))
#define GPIOE_OSPEEDR	((volatile uint32_t*)(GPIOE_BASE_ADDR + offset_OSPEEDR_ADDR))
#define GPIOH_OSPEEDR	((volatile uint32_t*)(GPIOH_BASE_ADDR + offset_OSPEEDR_ADDR))

//PUPDR
#define GPIOA_PUPDR		((volatile uint32_t*)(GPIOA_BASE_ADDR + offset_PUPDR_ADDR))
#define GPIOB_PUPDR		((volatile uint32_t*)(GPIOB_BASE_ADDR + offset_PUPDR_ADDR))
#define GPIOC_PUPDR		((volatile uint32_t*)(GPIOC_BASE_ADDR + offset_PUPDR_ADDR))
#define GPIOD_PUPDR		((volatile uint32_t*)(GPIOD_BASE_ADDR + offset_PUPDR_ADDR))
#define GPIOE_PUPDR		((volatile uint32_t*)(GPIOE_BASE_ADDR + offset_PUPDR_ADDR))
#define GPIOH_PUPDR		((volatile uint32_t*)(GPIOH_BASE_ADDR + offset_PUPDR_ADDR))

//IDR
#define GPIOA_IDR		((volatile uint32_t*)(GPIOA_BASE_ADDR + offset_IDR_ADDR))
#define GPIOB_IDR		((volatile uint32_t*)(GPIOB_BASE_ADDR + offset_IDR_ADDR))
#define GPIOC_IDR		((volatile uint32_t*)(GPIOC_BASE_ADDR + offset_IDR_ADDR))
#define GPIOD_IDR		((volatile uint32_t*)(GPIOD_BASE_ADDR + offset_IDR_ADDR))
#define GPIOE_IDR		((volatile uint32_t*)(GPIOE_BASE_ADDR + offset_IDR_ADDR))
#define GPIOH_IDR		((volatile uint32_t*)(GPIOH_BASE_ADDR + offset_IDR_ADDR))

//ODR
#define GPIOA_ODR		((volatile uint32_t*)(GPIOA_BASE_ADDR + offset_ODR_ADDR))
#define GPIOB_ODR		((volatile uint32_t*)(GPIOB_BASE_ADDR + offset_ODR_ADDR))
#define GPIOC_ODR		((volatile uint32_t*)(GPIOC_BASE_ADDR + offset_ODR_ADDR))
#define GPIOD_ODR		((volatile uint32_t*)(GPIOD_BASE_ADDR + offset_ODR_ADDR))
#define GPIOE_ODR		((volatile uint32_t*)(GPIOE_BASE_ADDR + offset_ODR_ADDR))
#define GPIOH_ODR		((volatile uint32_t*)(GPIOH_BASE_ADDR + offset_ODR_ADDR))

//BSRR
#define GPIOA_BSRR		((volatile uint32_t*)(GPIOA_BASE_ADDR + offset_BSRR_ADDR))
#define GPIOB_BSRR		((volatile uint32_t*)(GPIOB_BASE_ADDR + offset_BSRR_ADDR))
#define GPIOC_BSRR		((volatile uint32_t*)(GPIOC_BASE_ADDR + offset_BSRR_ADDR))
#define GPIOD_BSRR		((volatile uint32_t*)(GPIOD_BASE_ADDR + offset_BSRR_ADDR))
#define GPIOE_BSRR		((volatile uint32_t*)(GPIOE_BASE_ADDR + offset_BSRR_ADDR))
#define GPIOH_BSRR		((volatile uint32_t*)(GPIOH_BASE_ADDR + offset_BSRR_ADDR))

//AFRL -alternate function for low register
#define GPIOA_AFRL		((volatile uint32_t*)(GPIOA_BASE_ADDR + offset_AFRL_ADDR))
#define GPIOB_AFRL		((volatile uint32_t*)(GPIOB_BASE_ADDR + offset_AFRL_ADDR))
#define GPIOC_AFRL		((volatile uint32_t*)(GPIOC_BASE_ADDR + offset_AFRL_ADDR))
#define GPIOD_AFRL		((volatile uint32_t*)(GPIOD_BASE_ADDR + offset_AFRL_ADDR))
#define GPIOE_AFRL		((volatile uint32_t*)(GPIOE_BASE_ADDR + offset_AFRL_ADDR))
#define GPIOH_AFRL		((volatile uint32_t*)(GPIOH_BASE_ADDR + offset_AFRL_ADDR))

//AFRH - alternate function for high register
#define GPIOA_AFRH		((volatile uint32_t*)(GPIOA_BASE_ADDR + offset_AFRH_ADDR))
#define GPIOB_AFRH		((volatile uint32_t*)(GPIOB_BASE_ADDR + offset_AFRH_ADDR))
#define GPIOC_AFRH		((volatile uint32_t*)(GPIOC_BASE_ADDR + offset_AFRH_ADDR))
#define GPIOD_AFRH		((volatile uint32_t*)(GPIOD_BASE_ADDR + offset_AFRH_ADDR))
#define GPIOE_AFRH		((volatile uint32_t*)(GPIOE_BASE_ADDR + offset_AFRH_ADDR))
#define GPIOH_AFRH		((volatile uint32_t*)(GPIOH_BASE_ADDR + offset_AFRH_ADDR))


//EXTI
#define EXTI_IMR		((volatile uint32_t*)(EXTI_BASE_ADDR + offset_IMR))
#define EXTI_EMR		((volatile uint32_t*)(EXTI_BASE_ADDR + offset_EMR))
#define EXTI_RTSR		((volatile uint32_t*)(EXTI_BASE_ADDR + offset_RTSR))
#define EXTI_FTSR		((volatile uint32_t*)(EXTI_BASE_ADDR + offset_FTSR))
#define EXTI_SWIER		((volatile uint32_t*)(EXTI_BASE_ADDR + offset_SWIER))
#define EXTI_PR			((volatile uint32_t*)(EXTI_BASE_ADDR + offset_PR))

//I2C
#define I2C_CR1			((volatile uint32_t*)(I2C_BASE_ADDR + offset_CR1))
#define I2C_CR2			((volatile uint32_t*)(I2C_BASE_ADDR + offset_CR2))
#define I2C_OAR1		((volatile uint32_t*)(I2C_BASE_ADDR + offset_OAR1))
#define I2C_OAR2		((volatile uint32_t*)(I2C_BASE_ADDR + offset_OAR2))
#define I2C_DR			((volatile uint32_t*)(I2C_BASE_ADDR + offset_DR))
#define I2C_SR1			((volatile uint32_t*)(I2C_BASE_ADDR + offset_SR1))
#define I2C_SR2			((volatile uint32_t*)(I2C_BASE_ADDR + offset_SR2))
#define I2C_CRR			((volatile uint32_t*)(I2C_BASE_ADDR + offset_CRR))
#define I2C_TRISE		((volatile uint32_t*)(I2C_BASE_ADDR + offset_TRISE))
#define I2C_FLTR		((volatile uint32_t*)(I2C_BASE_ADDR + offset_FLTR))

//UART1
#define UART1_BRR 		((volatile uint32_t*)(UART1_BASE_ADDR + offset_USART1_BRR))
#define UART1_CR1 		((volatile uint32_t*)(UART1_BASE_ADDR + offset_USART1_CR1))
#define UART1_DR 		((volatile uint32_t*)(UART1_BASE_ADDR + offset_USART1_DR))
#define UART1_SR 		((volatile uint32_t*)(UART1_BASE_ADDR + offset_USART1_SR))

//SPI1
#define SPI1_CR1		((volatile uint32_t*)(SPI1_BASE_ADDR + offset_SPI_CR1))
#define SPI1_CR2		((volatile uint32_t*)(SPI1_BASE_ADDR + offset_SPI_CR2))
#define SPI1_SR			((volatile uint32_t*)(SPI1_BASE_ADDR + offset_SPI_SR))
#define SPI1_DR			((volatile uint32_t*)(SPI1_BASE_ADDR + offset_SPI_DR))
#define SPI1_CRCPR		((volatile uint32_t*)(SPI1_BASE_ADDR + offset_SPI_CRCPR))
#define SPI1_RXCRCR		((volatile uint32_t*)(SPI1_BASE_ADDR + offset_SPI_RXCRCR))
#define SPI1_TXCRCR		((volatile uint32_t*)(SPI1_BASE_ADDR + offset_SPI_TXCRCR))


//TIMER1
#define TIM1_CR1		((volatile uint32_t*)(TIM1_BASE_ADDR + offset_TIM1_CR1))
#define TIM1_CR2		((volatile uint32_t*)(TIM1_BASE_ADDR + offset_TIM1_CR2))
#define TIM1_SMCR		((volatile uint32_t*)(TIM1_BASE_ADDR + offset_TIM1_SMCR))
#define TIM1_DIER		((volatile uint32_t*)(TIM1_BASE_ADDR + offset_TIM1_DIER))
#define TIM1_SR			((volatile uint32_t*)(TIM1_BASE_ADDR + offset_TIM1_SR))
#define TIM1_EGR		((volatile uint32_t*)(TIM1_BASE_ADDR + offset_TIM1_EGR))
#define TIM1_CCMR1		((volatile uint32_t*)(TIM1_BASE_ADDR + offset_TIM1_CCMR1))
#define TIM1_CCMR2		((volatile uint32_t*)(TIM1_BASE_ADDR + offset_TIM1_CCMR2))
#define TIM1_CCER		((volatile uint32_t*)(TIM1_BASE_ADDR + offset_TIM1_CCER))
#define TIM1_CNT		((volatile uint32_t*)(TIM1_BASE_ADDR + offset_TIM1_CNT))
#define TIM1_PSC		((volatile uint32_t*)(TIM1_BASE_ADDR + offset_TIM1_PSC))
#define TIM1_ARR		((volatile uint32_t*)(TIM1_BASE_ADDR + offset_TIM1_ARR))
#define TIM1_RCR		((volatile uint32_t*)(TIM1_BASE_ADDR + offset_TIM1_RCR))
#define TIM1_CCR1		((volatile uint32_t*)(TIM1_BASE_ADDR + offset_TIM1_CCR1))
#define TIM1_CCR2		((volatile uint32_t*)(TIM1_BASE_ADDR + offset_TIM1_CCR2))
#define TIM1_CCR3		((volatile uint32_t*)(TIM1_BASE_ADDR + offset_TIM1_CCR3))
#define TIM1_CCR4		((volatile uint32_t*)(TIM1_BASE_ADDR + offset_TIM1_CCR4))
#define TIM1_BDTR		((volatile uint32_t*)(TIM1_BASE_ADDR + offset_TIM1_BDTR))
#define TIM1_DCR		((volatile uint32_t*)(TIM1_BASE_ADDR + offset_TIM1_DCR))
#define TIM1_DMAR		((volatile uint32_t*)(TIM1_BASE_ADDR + offset_TIM1_DMAR))

//ADC
#define ADC_JSQR		((volatile uint32_t*)(ADC1_BASE_ADDR + offset_ADC_JSQR))


#define NVIC_ISER0  	((volatile uint32_t*)(0xE000E100))
#define my_VTOR 		((volatile uint32_t*)(0xE000ED08)) //Vector table offset register
#endif /* INC_BASE_ADDRESS_REGISTER_H_ */
