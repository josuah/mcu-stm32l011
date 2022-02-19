#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define GPIOA ((struct zmcu_gpio *)0x50000000)
#define GPIOB ((struct zmcu_gpio *)0x50000400)
#define GPIOC ((struct zmcu_gpio *)0x50000800)
#define GPIOD ((struct zmcu_gpio *)0x50000C00)
#define GPIOE ((struct zmcu_gpio *)0x50001000)
#define GPIOH ((struct zmcu_gpio *)0x50001C00)

struct zmcu_gpio {

	/* 0x00: mode register */
	uint32_t volatile MODER;
#define GPIO_MODE(pin, x)			((x) << 2 * (pin))
#define GPIO_MODE_MASK(pin)			GPIO_MODE(pin, B00000111)
#define GPIO_MODE_IN				0u
#define GPIO_MODE_OUT				1u
#define GPIO_MODE_ALT				2u
#define GPIO_MODE_ANALOG			3u

	/* 0x04: type register */
	uint32_t volatile OTYPER;
#define GPIO_OTYPE(pin, x)			((x) << (pin))
#define GPIO_OTYPE_PUSH_PULL			0u
#define GPIO_OTYPE_OPEN_DRAIN			1u

	/* 0x08: port output speed register */
	uint32_t volatile OSPEEDR;
#define GPIO_OSPEED(pin, x)			((x) << 2 * (pin))
#define GPIO_OSPEED_MASK(pin)			GPIO_OSPEED(pin, B00000111)
#define GPIO_OSPEED_LOW				0u
#define GPIO_OSPEED_MEDIUM			1u
#define GPIO_OSPEED_HIGH			2u
#define GPIO_OSPEED_VERY_HIGH			3u
	/* output speed for this chip */
#define GPIO_SPEED_400KHZ			GPIO_OSPEED_MEDIUM
#define GPIO_SPEED_2MHZ				GPIO_OSPEED_LOW
#define GPIO_SPEED_10MHZ			GPIO_OSPEED_HIGH
#define GPIO_SPEED_40MHZ			GPIO_OSPEED_VERYHIGH

	/* port pull-up/pull-down register */
	uint32_t volatile PUPDR;
#define GPIO_PUPD(pin, x)			((x) << 2 * (pin))
#define GPIO_PUPD_MASK(pin)			GPIO_PUPD(pin, B00000111)
#define GPIO_PUPD_FLOATING			0u
#define GPIO_PUPD_ANALOG			0u
#define GPIO_PUPD_PULLUP			1u
#define GPIO_PUPD_PULLDOWN			2u

	/* 0x10: input data register */
	uint32_t volatile IDR;
#define GPIO_ID(pin, x)				((x) << (pin))

	/* 0x14: output data register */
	uint32_t volatile ODR;
#define GPIO_OD(pin, x)				((x) << (pin))

	/* 0x18: bit set and reset register */
	uint32_t volatile BSRR;
#define GPIO_BS(pin, x)				((x) << (pin))
#define GPIO_BR(n)				((x) << (pin)+16)

	/* 0x1C: locking mechanism */
	uint32_t volatile LCKR;
#define GPIO_LCK(pin, x)			((x) << (pin))
#define GPIO_LCKK				16u

	/* 0x20: alternate function register (low) */
	uint32_t volatile AFR;
#define GPIO_AF(pin, x)				((x) << (pin))
#define GPIO_AF_MASK(pin)			GPIO_AF(pin, B00001111)

	/* 0x24: analog function register (high) */
	uint32_t volatile BRR;

};

/* enable the port to use as GPIO */
void gpio_enable(struct zmcu_gpio *gpio);

/* setup a port in output mode */
void gpio_mode_output(struct zmcu_gpio *gpio, uint8_t pin, uint8_t speed);

/* setup a port in alternate function mode */
void gpio_mode_altfn(struct zmcu_gpio *gpio, uint8_t pin, uint8_t altfn);

/* for each bit set on `mask`, set the same pin up on port `base` */
void gpio_port_set(struct zmcu_gpio *gpio, uint8_t mask);

/* for each bit set on `mask`, set the same pin down on port `base` */
void gpio_port_clear(struct zmcu_gpio *gpio, uint8_t mask);
