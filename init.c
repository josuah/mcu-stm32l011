#include "libc.h"
#include "registers.h"
#include "functions.h"

extern int main(void);
extern char __data_start, __data_end, __data_load_start;
extern char __bss_start, __bss_end, __stack_top;

void
__reset_handler(void)
{
	volatile char *dst, *src = &__data_load_start;

	for (dst = &__data_start; dst < &__data_end; *dst++ = *src++);
	for (dst = &__bss_start; dst < &__bss_end; *dst++ = 0);
	main();
	for (int volatile i = 0 ;; i++);
}

/* so that the debugger can immediately see which fault was triggered */
void __null_handler(void)		{ for (int volatile i = 0;; i++); }
void __isr_hard_fault(void)		{ for (int volatile i = 0;; i++); }
void __isr_memory_management(void)	{ for (int volatile i = 0;; i++); }
void __isr_non_maskable_interrupt(void)	{ for (int volatile i = 0;; i++); }
void __isr_bus_fault(void)		{ for (int volatile i = 0;; i++); }
void __isr_usage_fault(void)		{ for (int volatile i = 0;; i++); }
void __isr_secure_fault(void)		{ for (int volatile i = 0;; i++); }

void *__stack_pointer = &__stack_top;	/* 0x00 */

void (*__vectors[])(void) = {
	&__reset_handler,		/* 0x04 -15 ARM Reset */
	&__isr_non_maskable_interrupt,	/* 0x08 -14 ARM NonMaskableInt */
	&__isr_hard_fault,		/* 0x0C -13 ARM HardFault */
	&__isr_memory_management,	/* 0x10 -12 ARM MemoryManagement */
	&__isr_bus_fault,		/* 0x14 -11 ARM BusFault */
	&__isr_usage_fault,		/* 0x18 -10 ARM UsageFault */
	&__isr_secure_fault,		/* 0x1C -9 ARM SecureFault */
	&__null_handler,		/* 0x20 -8 Reserved */
	&__null_handler,		/* 0x24 -7 Reserved */
	&__null_handler,		/* 0x28 -6 Reserved */
	&__null_handler,		/* 0x2C -5 ARM SVCall */
	&__null_handler,		/* 0x30 -4 ARM DebugMonitor */
	&__null_handler,		/* 0x34 -3 Reserved */
	&__null_handler,		/* 0x38 -2 ARM PendSV */
	&__null_handler,		/* 0x3C -1 ARM SysTick */
	&__null_handler,		/* 0x40 #0 WWDG */
	&__null_handler,		/* 0x44 #1 PVD */
	&__null_handler,		/* 0x48 #2 RTC */
	&__null_handler,		/* 0x4C #3 FLASH */
	&__null_handler,		/* 0x50 #4 RCC_CRS */
	&__null_handler,		/* 0x54 #5 EXTI0to1 */
	&__null_handler,		/* 0x58 #6 EXTI2to3 */
	&__null_handler,		/* 0x5C #7 EXTI4to15 */
	&__null_handler,		/* 0x60 #8 Reserved */
	&__null_handler,		/* 0x64 #9 DMA1_CHANNEL1 */
	&__null_handler,		/* 0x68 #10 DMA1_CHANNEL2to3 */
	&__null_handler,		/* 0x6C #11 DMA1_CHANNEL4to7 */
	&__null_handler,		/* 0x70 #12 ADC_COMP */
	&__null_handler,		/* 0x74 #13 LPTIM1  */
	&__null_handler,		/* 0x78 #14 USART4_USART5 */
	&__null_handler,		/* 0x7C #15 TIM2 */
	&__null_handler,		/* 0x80 #16 TIM3 */
	&__null_handler,		/* 0x84 #17 TIM6 */
	&__null_handler,		/* 0x88 #18 TIM7 */
	&__null_handler,		/* 0x8C #19 Reserved */
	&__null_handler,		/* 0x90 #20 TIM21 */
	&__null_handler,		/* 0x94 #21 I2C3 */
	&__null_handler,		/* 0x98 #22 TIM22 */
	&__null_handler,		/* 0x9C #23 I2C1 */
	&__null_handler,		/* 0xA0 #24 I2C2 */
	&__null_handler,		/* 0xA4 #25 SPI1 */
	&__null_handler,		/* 0xA8 #26 SPI2 */
	&__null_handler,		/* 0xAC #27 USART1 */
	&__null_handler,		/* 0xB0 #28 USART2 */
	&__null_handler,		/* 0xB4 #29 LPUART1_AES */
};
