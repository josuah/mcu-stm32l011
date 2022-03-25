#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define LPUART1 ((struct mcu_lpuart *)0x40004800)

struct mcu_lpuart {

	/* 0x00: control register 1 */
	uint32_t volatile CR1;
#define LPUART_CR1_M1				(1u << 3)
#define LPUART_CR1_DEAT4			(1u << 6)
#define LPUART_CR1_DEAT3			(1u << 7)
#define LPUART_CR1_DEAT2			(1u << 8)
#define LPUART_CR1_DEAT1			(1u << 9)
#define LPUART_CR1_DEAT0			(1u << 10)
#define LPUART_CR1_DEDT4			(1u << 11)
#define LPUART_CR1_DEDT3			(1u << 12)
#define LPUART_CR1_DEDT2			(1u << 13)
#define LPUART_CR1_DEDT1			(1u << 14)
#define LPUART_CR1_DEDT0			(1u << 15)
#define LPUART_CR1_CMIE				(1u << 17)
#define LPUART_CR1_MME				(1u << 18)
#define LPUART_CR1_M				(1u << 19)
#define LPUART_CR1_WAKE				(1u << 20)
#define LPUART_CR1_PCE				(1u << 21)
#define LPUART_CR1_PS				(1u << 22)
#define LPUART_CR1_PEIE				(1u << 23)
#define LPUART_CR1_TXEIE			(1u << 24)
#define LPUART_CR1_TCIE				(1u << 25)
#define LPUART_CR1_RXNEIE			(1u << 26)
#define LPUART_CR1_IDLEIE			(1u << 27)
#define LPUART_CR1_TE				(1u << 28)
#define LPUART_CR1_RE				(1u << 29)
#define LPUART_CR1_UESM				(1u << 30)
#define LPUART_CR1_UE				(1u << 31)

	/* 0x04: control register 2 */
	uint32_t volatile CR2;
#define LPUART_CR2_ADDH(x)			((x) << 28)
#define LPUART_CR2_ADDL(x)			((x) << 24)
#define LPUART_CR2_MSBFIRST			(1u << 19)
#define LPUART_CR2_DATAINV			(1u << 18)
#define LPUART_CR2_TXINV			(1u << 17)
#define LPUART_CR2_RXINV			(1u << 16)
#define LPUART_CR2_SWAP				(1u << 15)
#define LPUART_CR2_STOP(x)			((x) << 12)
#define LPUART_CR2_ADDM7			(1u << 4)

	/* 0x08: control register 3 */
	uint32_t volatile CR3;
#define LPUART_CR3_UCESM			(1u << 23)
#define LPUART_CR3_WUFIE			(1u << 22)
#define LPUART_CR3_WUS(x)			((x) << 20)
#define LPUART_CR3_DEP				(1u << 15)
#define LPUART_CR3_DEM				(1u << 14)
#define LPUART_CR3_DDRE				(1u << 13)
#define LPUART_CR3_OVRDIS			(1u << 12)
#define LPUART_CR3_CTSIE			(1u << 10)
#define LPUART_CR3_CTSE				(1u << 9)
#define LPUART_CR3_RTSE				(1u << 8)
#define LPUART_CR3_DMAT				(1u << 7)
#define LPUART_CR3_DMAR				(1u << 6)
#define LPUART_CR3_HDSEL			(1u << 3)
#define LPUART_CR3_EIE				(1u << 0)

	/* 0x0C: baud rate register */
	uint32_t volatile BRR;

	/* 0x10: reserved */
	uint8_t volatile RESERVED1[0x14-0x10];

	/* 0x14: reserved */
	uint8_t volatile RESERVED2[0x18-0x14];

	/* 0x18: reserved */
	uint8_t volatile RESERVED3[0x18-0x18];

	/* 0x18: request register */
	uint32_t volatile RQR;
#define LPUART_RQR_RXFRQ			(1u << 3)
#define LPUART_RQR_MMRQ				(1u << 2)
#define LPUART_RQR_SBKRQ			(1u << 1)

	/* 0x1C: interrupt and status register */
	uint32_t volatile ISR;
#define LPUART_ISR_REACK			(1u << 22)
#define LPUART_ISR_TEACK			(1u << 21)
#define LPUART_ISR_WUF				(1u << 20)
#define LPUART_ISR_RWU				(1u << 19)
#define LPUART_ISR_SBKF				(1u << 18)
#define LPUART_ISR_CMF				(1u << 17)
#define LPUART_ISR_BUSY				(1u << 16)
#define LPUART_ISR_CTS				(1u << 10)
#define LPUART_ISR_CTSIF			(1u << 9)
#define LPUART_ISR_TXE				(1u << 7)
#define LPUART_ISR_TC				(1u << 6)
#define LPUART_ISR_RXNE				(1u << 5)
#define LPUART_ISR_IDLE				(1u << 4)
#define LPUART_ISR_ORE				(1u << 3)
#define LPUART_ISR_NF				(1u << 2)
#define LPUART_ISR_FE				(1u << 1)
#define LPUART_ISR_PE				(1u << 0)

	/* 0x20: interrupt flag clear register */
	uint32_t volatile ICR;
#define LPUART_ICR_WUCF				(1u << 20)
#define LPUART_ICR_CMCF				(1u << 17)
#define LPUART_ICR_CTSCF			(1u << 9)
#define LPUART_ICR_TCCF				(1u << 6)
#define LPUART_ICR_ORECF			(1u << 3)
#define LPUART_ICR_NCF				(1u << 2)
#define LPUART_ICR_FECF				(1u << 1)
#define LPUART_ICR_PECF				(1u << 0)

	/* 0x24: receive data register */
	uint32_t volatile RDR;

	/* 0x28: transmit data regsiter */
	uint32_t volatile TDR;

};

/* set the baudrate of the lpuart */
void lpuart_set_baud_rate(struct mcu_lpuart *lpuart, uint16_t baud_rate);

/* true if the transmission buffer can receive more data */
int lpuart_transmit_ready(struct mcu_lpuart *lpuart);

/* send a single byte through the transmit data register */
void lpuart_transmit_byte(struct mcu_lpuart *lpuart, uint8_t byte);

/* true if each byte were transmitted */
int lpuart_transmit_done(struct mcu_lpuart *lpuart);

/* enable the lpuart peripheral */
void lpuart_enable(struct mcu_lpuart *lpuart);
