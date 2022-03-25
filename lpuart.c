#include "libc.h"
#include "registers.h"
#include "functions.h"

void
lpuart_enable(struct mcu_lpuart *lpuart)
{
	if (lpuart == LPUART1)
		RCC->APB1ENR |= RCC_APB1ENR_LPUART1EN;

	lpuart->CR1 |= LPUART_CR1_TE | LPUART_CR1_TE | LPUART_CR1_UE;
}

void
lpuart_set_baud_rate(struct mcu_lpuart *lpuart, uint16_t baud_rate)
{
//	uint32_t fck = 32768;

//	lpuart->BRR = fck * 256 / baud_rate;
	lpuart->BRR =  0x369;
	gpio_port_set(GPIOB, 1 << 3);
}

int
lpuart_transmit_ready(struct mcu_lpuart *lpuart)
{
	return lpuart->ISR & LPUART_ISR_TXE;
}

void
lpuart_transmit_byte(struct mcu_lpuart *lpuart, uint8_t byte)
{
	lpuart->TDR = byte;
}

int
lpuart_transmit_done(struct mcu_lpuart *lpuart)
{
	return !!(lpuart->ISR & LPUART_ISR_TC);
}
