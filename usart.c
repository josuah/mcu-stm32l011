#include <sdk.stm32l011.h>

void
usart_enable(struct sdk_usart *usart)
{
	if (usart == USART2)
		RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	if (usart == USART4)
		RCC->APB1ENR |= RCC_APB1ENR_USART4EN;
	if (usart == USART5)
		RCC->APB1ENR |= RCC_APB1ENR_USART5EN;

	usart->CR1 |= USART_CR1_TE | USART_CR1_UE;
}

int
usart_transmit_ready(struct sdk_usart *usart)
{
	return usart->ISR & USART_ISR_TXE;
}

void
usart_set_baud_rate(struct sdk_usart *usart, uint16_t baud_rate)
{
	usart->BRR = 160000 / 96;
}

void
usart_transmit_byte(struct sdk_usart *usart, uint8_t byte)
{
	usart->TDR = byte;
}

int
usart_transmit_done(struct sdk_usart *usart)
{
	return usart->ISR & USART_ISR_TC;
}
