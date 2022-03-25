#include "libc.h"
#include "registers.h"
#include "functions.h"

void
clock_msi_enable(void)
{
	RCC->CR |= RCC_CR_MSION;
	return;
}

int
clock_msi_ready(void)
{
	uint32_t field, ready;

	/* is MSI clock ready? */
	ready = (RCC->CR & RCC_CR_MSIRDY);

	field = RCC->CFGR & RCC_CFGR_SWS_MASK;
	ready |= (field == RCC_CFGR_SWS(RCC_CFGR_SWS_MSI));

	return ready;
}

uint16_t
clock_get_ahb_divider(void)
{
	switch (RCC->CFGR | RCC_CFGR_HPRE_MASK) {
	case RCC_CFGR_HPRE(1): return 1;
	case RCC_CFGR_HPRE(2): return 2;
	case RCC_CFGR_HPRE(4): return 4;
	case RCC_CFGR_HPRE(8): return 8;
	case RCC_CFGR_HPRE(16): return 16;
	case RCC_CFGR_HPRE(64): return 64;
	case RCC_CFGR_HPRE(128): return 128;
	case RCC_CFGR_HPRE(256): return 256;
	case RCC_CFGR_HPRE(512): return 512;
	}
	__stop_program();
	return 0;
}

void
clock_set_ahb_divider(uint16_t div)
{
	RCC->CFGR |= RCC_CFGR_HPRE(div);
}
