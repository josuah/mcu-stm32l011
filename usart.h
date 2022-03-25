#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define USART1 ((struct mcu_usart *)0x40013800)
#define USART2 ((struct mcu_usart *)0x40004400)
#define USART4 ((struct mcu_usart *)0x40004C00)
#define USART5 ((struct mcu_usart *)0x40005000)

struct mcu_usart {

	/* control register 1 */
	uint32_t volatile CR1;
#define USART_CR1_M1				(1u << 28)
#define USART_CR1_EOBIE				(1u << 27)
#define USART_CR1_RTOIE				(1u << 26)
#define USART_CR1_DEAT4				(1u << 25)
#define USART_CR1_DEAT3				(1u << 24)
#define USART_CR1_DEAT2				(1u << 23)
#define USART_CR1_DEAT1				(1u << 22)
#define USART_CR1_DEAT0				(1u << 21)
#define USART_CR1_DEDT4				(1u << 20)
#define USART_CR1_DEDT3				(1u << 19)
#define USART_CR1_DEDT2				(1u << 18)
#define USART_CR1_DEDT1				(1u << 17)
#define USART_CR1_DEDT0				(1u << 16)
#define USART_CR1_OVER8				(1u << 15)
#define USART_CR1_CMIE				(1u << 14)
#define USART_CR1_MME				(1u << 13)
#define USART_CR1_M0				(1u << 12)
#define USART_CR1_WAKE				(1u << 11)
#define USART_CR1_PCE				(1u << 10)
#define USART_CR1_PS				(1u << 9)
#define USART_CR1_PEIE				(1u << 8)
#define USART_CR1_TXEIE				(1u << 7)
#define USART_CR1_TCIE				(1u << 6)
#define USART_CR1_RXNEIE			(1u << 5)
#define USART_CR1_IDLEIE			(1u << 4)
#define USART_CR1_TE				(1u << 3)
#define USART_CR1_RE				(1u << 2)
#define USART_CR1_UESM				(1u << 1)
#define USART_CR1_UE				(1u << 0)

	/* 0x04: control register 2 */
	uint32_t volatile CR2;
#define USART_CR2_ADD				(1u << 24)
#define USART_CR2_RTOEN				(1u << 23)
#define USART_CR2_ABRMOD1			(1u << 22)
#define USART_CR2_ABRMOD0			(1u << 21)
#define USART_CR2_ABREN				(1u << 20)
#define USART_CR2_MSBFIRST			(1u << 19)
#define USART_CR2_DATAINV			(1u << 18)
#define USART_CR2_TXINV				(1u << 17)
#define USART_CR2_RXINV				(1u << 16)
#define USART_CR2_SWAP				(1u << 15)
#define USART_CR2_LINEN				(1u << 14)
#define USART_CR2_STOP				(1u << 12)
#define USART_CR2_CLKEN				(1u << 11)
#define USART_CR2_CPOL				(1u << 10)
#define USART_CR2_CPHA				(1u << 9)
#define USART_CR2_LBCL				(1u << 8)
#define USART_CR2_LBDIE				(1u << 6)
#define USART_CR2_LBDL				(1u << 5)
#define USART_CR2_ADDM7				(1u << 4)

	/* 0x08: control register 3 */
	uint32_t volatile CR3;
#define USART_CR3_TCBGTIE			(1u << 24)
#define USART_CR3_UCESM				(1u << 23)
#define USART_CR3_WUFIE				(1u << 22)
#define USART_CR3_WUS				(1u << 20)
#define USART_CR3_SCARCNT			(1u << 17)
#define USART_CR3_DEP				(1u << 15)
#define USART_CR3_DEM				(1u << 14)
#define USART_CR3_DDRE				(1u << 13)
#define USART_CR3_OVRDIS			(1u << 12)
#define USART_CR3_ONEBIT			(1u << 11)
#define USART_CR3_CTSIE				(1u << 10)
#define USART_CR3_CTSE				(1u << 9)
#define USART_CR3_RTSE				(1u << 8)
#define USART_CR3_DMAT				(1u << 7)
#define USART_CR3_DMAR				(1u << 6)
#define USART_CR3_SCEN				(1u << 5)
#define USART_CR3_NACK				(1u << 4)
#define USART_CR3_HDSEL				(1u << 3)
#define USART_CR3_IRLP				(1u << 2)
#define USART_CR3_IREN				(1u << 1)
#define USART_CR3_EIE				(1u << 0)

	/* 0x0C: bit rate register */
	uint32_t volatile BRR;

	/* 0x10: guarantee time register */
	uint32_t volatile GTPR;
#define USART_GTPR_GT				(1u << 8)
#define USART_GTPR_PSC				(1u << 0)

	/* 0x14: receiver timeout register */
	uint32_t volatile RTOR;
#define USART_RTOR_BLEN				(1u << 24)
#define USART_RTOR_RTO				(1u << 0)

	/* 0x18: request register */
	uint32_t volatile RQR;
#define USART_RQR_TXFRQ				(1u << 4)
#define USART_RQR_RXFRQ				(1u << 3)
#define USART_RQR_MMRQ				(1u << 2)
#define USART_RQR_SBKRQ				(1u << 1)
#define USART_RQR_ABRRQ				(1u << 0)

	/* 0x1C: interrupt and status register */
	uint32_t volatile ISR;
#define USART_ISR_TCBGT				(1u << 25)
#define USART_ISR_REACK				(1u << 22)
#define USART_ISR_TEACK				(1u << 21)
#define USART_ISR_WUF				(1u << 20)
#define USART_ISR_RWU				(1u << 19)
#define USART_ISR_SBKF				(1u << 18)
#define USART_ISR_CMF				(1u << 17)
#define USART_ISR_BUSY				(1u << 16)
#define USART_ISR_ABRF				(1u << 15)
#define USART_ISR_ABRE				(1u << 14)
#define USART_ISR_EOBF				(1u << 12)
#define USART_ISR_RTOF				(1u << 11)
#define USART_ISR_CTS				(1u << 10)
#define USART_ISR_CTSIF				(1u << 9)
#define USART_ISR_LBDF				(1u << 8)
#define USART_ISR_TXE				(1u << 7)
#define USART_ISR_TC				(1u << 6)
#define USART_ISR_RXNE				(1u << 5)
#define USART_ISR_IDLE				(1u << 4)
#define USART_ISR_ORE				(1u << 3)
#define USART_ISR_NF				(1u << 2)
#define USART_ISR_FE				(1u << 1)
#define USART_ISR_PE				(1u << 0)

	/* 0x20: interrupt flag clear register */
	uint32_t volatile ICR;
#define USART_ICR_WUCF				(1u << 20)
#define USART_ICR_CMCF				(1u << 17)
#define USART_ICR_EOBCF				(1u << 12)
#define USART_ICR_RTOCF				(1u << 11)
#define USART_ICR_CTSCF				(1u << 9)
#define USART_ICR_LBDCF				(1u << 8)
#define USART_ICR_TCBGTCF			(1u << 7)
#define USART_ICR_TCCF				(1u << 6)
#define USART_ICR_IDLECF			(1u << 4)
#define USART_ICR_ORECF				(1u << 3)
#define USART_ICR_NCF				(1u << 2)
#define USART_ICR_FECF				(1u << 1)
#define USART_ICR_PECF				(1u << 0)

	/* 0x24: receive data register */
	uint32_t volatile RDR;

	/* 0x28: transmit data register */
	uint32_t volatile TDR;

};

/* set the baud rate of the usart */
void usart_set_baud_rate(struct mcu_usart *usart, uint16_t baud_rate);

/* true if the transmission buffer can receive more data */
int usart_transmit_ready(struct mcu_usart *usart);

/* configure pins for input/output */
void usart_transmit_byte(struct mcu_usart *usart, uint8_t byte);

/* true if each byte were transmitted */
int usart_transmit_done(struct mcu_usart *usart);

/* enable the usart peripheral */
void usart_enable(struct mcu_usart *usart);
