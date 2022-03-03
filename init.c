#include <stddef.h>
#include <main.h>

extern int main(void);
extern void __reset_handler(void);

extern char __data_start, __data_end, __data_load_start;
extern char __bss_start, __bss_end, __stack_top;

void *__stack_pointer = &__stack_top;

void (*__vectors[])(void) = {
	&__reset_handler,		/* 0x04 -15 ARM Reset */
	&__stop_program,		/* 0x08 -14 ARM NonMaskableInt */
	&__stop_program,		/* 0x0C -13 ARM HardFault */
	&__stop_program,		/* 0x10 -12 ARM MemoryManagement */
	&__stop_program,		/* 0x14 -11 ARM BusFault */
	&__stop_program,		/* 0x18 -10 ARM UsageFault */
	&__stop_program,		/* 0x1C -9 ARM SecureFault */
	&__stop_program,		/* 0x20 -8 Reserved */
	&__stop_program,		/* 0x24 -7 Reserved */
	&__stop_program,		/* 0x28 -6 Reserved */
	&__stop_program,		/* 0x2C -5 ARM SVCall */
	&__stop_program,		/* 0x30 -4 ARM DebugMonitor */
	&__stop_program,		/* 0x34 -2 ARM PendSV */
	&__stop_program,		/* 0x38 -1 ARM SysTick */
	&__stop_program,		/* 0x3C #0 WWDG */
	&__stop_program,		/* 0x40 #1 PVD */
	&__stop_program,		/* 0x44 #2 RTC */
	&__stop_program,		/* 0x48 #3 FLASH */
	&__stop_program,		/* 0x4C #4 RCC_CRS */
	&__stop_program,		/* 0x50 #5 EXTI0to1 */
	&__stop_program,		/* 0x54 #6 EXTI2to3 */
	&__stop_program,		/* 0x58 #7 EXTI4to15 */
	&__stop_program,		/* 0x5C #8 Reserved */
	&__stop_program,		/* 0x60 #9 DMA1_CHANNEL1 */
	&__stop_program,		/* 0x64 #10 DMA1_CHANNEL2to3 */
	&__stop_program,		/* 0x68 #11 DMA1_CHANNEL4to7 */
	&__stop_program,		/* 0x6C #12 ADC_COMP */
	&__stop_program,		/* 0x70 #13 LPTIM1  */
	&__stop_program,		/* 0x74 #14 USART4_USART5 */
	&__stop_program,		/* 0x78 #15 TIM2 */
	&__stop_program,		/* 0x7C #16 TIM3 */
	&__stop_program,		/* 0x80 #17 TIM6 */
	&__stop_program,		/* 0x84 #18 TIM7 */
	&__stop_program,		/* 0x88 #19 Reserved */
	&__stop_program,		/* 0x8C #20 TIM21 */
	&__stop_program,		/* 0x90 #21 I2C3 */
	&__stop_program,		/* 0x94 #22 TIM22 */
	&__stop_program,		/* 0x98 #23 I2C1 */
	&__stop_program,		/* 0x9C #24 I2C2 */
	&__stop_program,		/* 0xA0 #25 SPI1 */
	&__stop_program,		/* 0xA4 #26 SPI2 */
	&__stop_program,		/* 0xA8 #27 USART1 */
	&__stop_program,		/* 0xAC #28 USART2 */
	&__stop_program,		/* 0xB0 #29 LPUART1_AES */
};

void
__reset_handler(void)
{
	volatile char *src, *dst;

	/* fill initialised and uninitialised variables */
	src = &__data_load_start;
	for (dst = &__data_start; dst < &__data_end; *dst++ = *src++);
	for (dst = &__bss_start; dst < &__bss_end; *dst++ = 0);

	main();
	__stop_program();
}

void
__stop_program(void)
{
	for (int volatile i = 0 ;; i++);
}
