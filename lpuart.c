#include <sdk.stm32l011.h>

void
lpuart_enable(struct sdk_lpuart *lpuart)
{
	if (lpuart == LPUART1)
		RCC->APB1ENR |= RCC_APB1ENR_LPUART1EN;

	lpuart->CR1 |= LPUART_CR1_TE | LPUART_CR1_TE | LPUART_CR1_UE;
}

void
lpuart_set_baud_rate(struct sdk_lpuart *lpuart, uint16_t baud_rate)
{
//	uint32_t fck = 32768;

//	lpuart->BRR = fck * 256 / baud_rate;
	lpuart->BRR =  0x369;
	gpio_port_set(GPIOB, 1 << 3);
}

int
lpuart_transmit_ready(struct sdk_lpuart *lpuart)
{
	return lpuart->ISR & LPUART_ISR_TXE;
}

void
lpuart_transmit_byte(struct sdk_lpuart *lpuart, uint8_t byte)
{
	lpuart->TDR = byte;
}

int
lpuart_transmit_done(struct sdk_lpuart *lpuart)
{
	return !!(lpuart->ISR & LPUART_ISR_TC);
}
