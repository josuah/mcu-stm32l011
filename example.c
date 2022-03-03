#include <sdk.stm32l011.h>

int
main(void)
{
	gpio_enable(GPIOB);
	gpio_mode_output(GPIOB, 3, GPIO_OSPEED_MEDIUM);

	usart_set_baud_rate(USART2, 9600);
	usart_enable(USART2);
	gpio_mode_alternate_function(GPIO_AF_A2_USART2_TX);
	gpio_mode_alternate_function(GPIO_AF_A15_USART2_RX);

	for (;;) {
		while (!usart_transmit_ready(USART2));
		usart_transmit_byte(USART2, '.');
		while (!usart_transmit_done(USART2))
			gpio_port_set(GPIOB, 1 << 3);
	}

	return 0;
}
