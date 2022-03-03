#include <sdk.stm32l011.h>

void
gpio_enable(struct sdk_gpio *gpio)
{
	if (gpio == GPIOA)
		RCC->IOPENR |= RCC_IOPENR_IOPAEN;
	if (gpio == GPIOB)
		RCC->IOPENR |= RCC_IOPENR_IOPBEN;
	if (gpio == GPIOC)
		RCC->IOPENR |= RCC_IOPENR_IOPCEN;
	if (gpio == GPIOD)
		RCC->IOPENR |= RCC_IOPENR_IOPDEN;
	if (gpio == GPIOE)
		RCC->IOPENR |= RCC_IOPENR_IOPEEN;
	if (gpio == GPIOH)
		RCC->IOPENR |= RCC_IOPENR_IOPHEN;
}

void
gpio_mode_output(struct sdk_gpio *gpio, uint8_t pin, uint8_t speed)
{
	gpio->OSPEEDR = GPIO_OSPEED(pin, speed);
	gpio->MODER = GPIO_MODE(pin, GPIO_MODE_OUT);
}

void
gpio_mode_altfn(struct sdk_gpio *gpio, uint8_t pin, uint8_t altfn)
{
	uint32_t reg;

	/* setup the port in alternate function mode */
	reg = gpio->MODER & ~GPIO_MODE_MASK(pin);
	gpio->MODER = reg | GPIO_MODE(pin, GPIO_MODE_ALT);

	/* set the actual mode */
	reg = gpio->AFR & ~GPIO_AF_MASK(pin);
	gpio->AFR = reg | GPIO_AF(pin, altfn);
}

void
gpio_port_set(struct sdk_gpio *gpio, uint8_t mask)
{
	gpio->ODR |= mask;
}

void
gpio_port_clear(struct sdk_gpio *gpio, uint8_t mask)
{
	gpio->ODR &= mask;
}
