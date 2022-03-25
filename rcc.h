#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define RCC ((struct mcu_rcc *)0x40021000)

struct mcu_rcc {

	/* 0x00: control register */
	uint32_t volatile CR;

	/* 0x04: internal clock source calibration register */
	uint32_t volatile ICSCR;

	/* 0x08: reserved */
	uint8_t volatile RESERVED1[0x0C-0x08];

	/* 0x0C: clock configuration register */
	uint32_t volatile CFGR;
#define RCC_CFGR_SW				(1u << 0)
#define RCC_CFGR_SWS(x)				((x) << 2)
#define RCC_CFGR_SWS_MASK			RCC_CFGR_SWS(B00000011)
#define RCC_CFGR_SWS_MSI			B00000000
#define RCC_CFGR_SWS_HSI			B00000001
#define RCC_CFGR_SWS_HSE			B00000010
#define RCC_CFGR_SWS_PLL			B00000011
#define RCC_CFGR_HPRE(x)			((x) << 4)
#define RCC_CFGR_HPRE_MASK			RCC_CFGR_HPRE(B00001111)
#define RCC_CFGR_HPRE_DIV1			0u
#define RCC_CFGR_HPRE_DIV2			8u
#define RCC_CFGR_HPRE_DIV4			9u
#define RCC_CFGR_HPRE_DIV8			10u
#define RCC_CFGR_HPRE_DIV16			11u
#define RCC_CFGR_HPRE_DIV64			12u
#define RCC_CFGR_HPRE_DIV128			13u
#define RCC_CFGR_HPRE_DIV256			14u
#define RCC_CFGR_HPRE_DIV512			15u
#define RCC_CFGR_PPRE1				(1u << 8)
#define RCC_CFGR_PPRE2				(1u << 11)
#define RCC_CFGR_STOPWUCK			(1u << 15)
#define RCC_CFGR_PLLSRC				(1u << 16)
#define RCC_CFGR_PLLMUL				(1u << 18)
#define RCC_CFGR_PLLDIV				(1u << 22)
#define RCC_CFGR_MCOSEL				(1u << 24)
#define RCC_CFGR_MCOPRE				(1u << 28)

	/* 0x10: clock interrupt enable register */
	uint32_t volatile CIER;

	/* 0x14: clock interrupt flag register */
	uint32_t volatile CIFR;

	/* 0x18: clock interrupt clear register */
	uint32_t volatile CICR;

	/* 0x1C: GPIO reset register */
	uint32_t volatile IOPRSTR;

	/* 0x20: AHB peripheral reset register */
	uint32_t volatile AHBRSTR;

	/* 0x24: APB2 peripheral reset register */
	uint32_t volatile APB2RSTR;

	/* 0x28: APB1 peripheral reset register */
	uint32_t volatile APB1RSTR;

	/* I/O peripheral enable register */
	uint32_t volatile IOPENR;
#define RCC_IOPENR_IOPAEN			(1u << 0)
#define RCC_IOPENR_IOPBEN			(1u << 1)
#define RCC_IOPENR_IOPCEN			(1u << 2)
#define RCC_IOPENR_IOPDEN			(1u << 3)
#define RCC_IOPENR_IOPEEN			(1u << 4)
#define RCC_IOPENR_IOPHEN			(1u << 7)

	/* 0x30: AMBA high-performance bus enable register */
	uint32_t volatile AHBENR;
#define RCC_AHBENR_CRYPEN			(1u << 24)
#define RCC_AHBENR_CRCEN			(1u << 12)
#define RCC_AHBENR_MIFEN			(1u << 8)
#define RCC_AHBENR_DMAEN			(1u << 0)

	/* 0x34: APB2 peripheral clock enable register */
	uint32_t volatile APB2ENR;
#define RCC_APB2ENR_SYSCFEN			(1u << 0)
#define RCC_APB2ENR_TIM21EN			(1u << 2)
#define RCC_APB2ENR_TIM22EN			(1u << 5)
#define RCC_APB2ENR_FWEN			(1u << 7)
#define RCC_APB2ENR_ADCEN			(1u << 9)
#define RCC_APB2ENR_SPI1EN			(1u << 12)
#define RCC_APB2ENR_USART1EN			(1u << 14)
#define RCC_APB2ENR_DBGEN			(1u << 22)

	/* 0x38: APB1 peripheral clock enable register */
	uint32_t volatile APB1ENR;
#define RCC_APB1ENR_TIM2EN			(1u << 0)
#define RCC_APB1ENR_TIM3EN			(1u << 1)
#define RCC_APB1ENR_TIM6EN			(1u << 4)
#define RCC_APB1ENR_TIM7EN			(1u << 5)
#define RCC_APB1ENR_WWDGEN			(1u << 11)
#define RCC_APB1ENR_SPI2EN			(1u << 14)
#define RCC_APB1ENR_USART2EN			(1u << 17)
#define RCC_APB1ENR_LPUART1EN			(1u << 18)
#define RCC_APB1ENR_USART4EN			(1u << 19)
#define RCC_APB1ENR_USART5EN			(1u << 20)
#define RCC_APB1ENR_I2C1EN			(1u << 21)
#define RCC_APB1ENR_I2C2EN			(1u << 22)
#define RCC_APB1ENR_PWREN			(1u << 28)
#define RCC_APB1ENR_I2C3EN			(1u << 30)
#define RCC_APB1ENR_LPTIM1EN			(1u << 31)

	/* 0x3C: GPIO clock enable in sleep mode register */
	uint32_t volatile IOPSMENR;
#define RCC_IOPSMENR_IOPASMEN			(1u << 0)
#define RCC_IOPSMENR_IOPBSMEN			(1u << 1)
#define RCC_IOPSMENR_IOPCSMEN			(1u << 2)
#define RCC_IOPSMENR_IOPDSMEN			(1u << 3)
#define RCC_IOPSMENR_IOPESMEN			(1u << 4)
#define RCC_IOPSMENR_IOPHSMEN			(1u << 7)

};
