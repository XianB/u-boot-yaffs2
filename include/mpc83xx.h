/*
 * Copyright (C) 2004-2007 Freescale Semiconductor, Inc.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */

#ifndef __MPC83XX_H__
#define __MPC83XX_H__

#include <config.h>
#if defined(CONFIG_E300)
#include <asm/e300.h>
#endif

/* MPC83xx cpu provide RCR register to do reset thing specially
 */
#define MPC83xx_RESET

/* System reset offset (PowerPC standard)
 */
#define EXC_OFF_SYS_RESET		0x0100
#define	_START_OFFSET			EXC_OFF_SYS_RESET

/* IMMRBAR - Internal Memory Register Base Address
 */
#define CONFIG_DEFAULT_IMMR		0xFF400000	/* Default IMMR base address */
#define IMMRBAR				0x0000		/* Register offset to immr */
#define IMMRBAR_BASE_ADDR		0xFFF00000	/* Base address mask */
#define IMMRBAR_RES			~(IMMRBAR_BASE_ADDR)

/* LAWBAR - Local Access Window Base Address Register
 */
#define LBLAWBAR0			0x0020		/* Register offset to immr */
#define LBLAWAR0			0x0024
#define LBLAWBAR1			0x0028
#define LBLAWAR1			0x002C
#define LBLAWBAR2			0x0030
#define LBLAWAR2			0x0034
#define LBLAWBAR3			0x0038
#define LBLAWAR3			0x003C
#define LAWBAR_BAR			0xFFFFF000	/* Base address mask */

/* SPRIDR - System Part and Revision ID Register
 */
#define SPRIDR_PARTID			0xFFFF0000	/* Part Id */
#define SPRIDR_REVID			0x0000FFFF	/* Revision Id */

#if defined(CONFIG_MPC834X)
#define REVID_MAJOR(spridr)		((spridr & 0x0000FF00) >> 8)
#define REVID_MINOR(spridr)		(spridr & 0x000000FF)
#else
#define REVID_MAJOR(spridr)		((spridr & 0x000000F0) >> 4)
#define REVID_MINOR(spridr)		(spridr & 0x0000000F)
#endif

#define PARTID_NO_E(spridr)		((spridr & 0xFFFE0000) >> 16)
#define IS_E_PROCESSOR(spridr)		(!(spridr & 0x00010000)) /* has SEC */

#define SPR_8311			0x80B2
#define SPR_8313			0x80B0
#define SPR_8314			0x80B6
#define SPR_8315			0x80B4
#define SPR_8321			0x8066
#define SPR_8323			0x8062
#define SPR_8343			0x8036
#define SPR_8347_TBGA_			0x8032
#define SPR_8347_PBGA_			0x8034
#define SPR_8349			0x8030
#define SPR_8358_TBGA_			0x804A
#define SPR_8358_PBGA_			0x804E
#define SPR_8360			0x8048
#define SPR_8377			0x80C6
#define SPR_8378			0x80C4
#define SPR_8379			0x80C2

/* SPCR - System Priority Configuration Register
 */
#define SPCR_PCIHPE			0x10000000	/* PCI Highest Priority Enable */
#define SPCR_PCIHPE_SHIFT		(31-3)
#define SPCR_PCIPR			0x03000000	/* PCI bridge system bus request priority */
#define SPCR_PCIPR_SHIFT		(31-7)
#define SPCR_OPT			0x00800000	/* Optimize */
#define SPCR_OPT_SHIFT			(31-8)
#define SPCR_TBEN			0x00400000	/* E300 PowerPC core time base unit enable */
#define SPCR_TBEN_SHIFT			(31-9)
#define SPCR_COREPR			0x00300000	/* E300 PowerPC Core system bus request priority */
#define SPCR_COREPR_SHIFT		(31-11)

#if defined(CONFIG_MPC834X)
/* SPCR bits - MPC8349 specific */
#define SPCR_TSEC1DP			0x00003000	/* TSEC1 data priority */
#define SPCR_TSEC1DP_SHIFT		(31-19)
#define SPCR_TSEC1BDP			0x00000C00	/* TSEC1 buffer descriptor priority */
#define SPCR_TSEC1BDP_SHIFT		(31-21)
#define SPCR_TSEC1EP			0x00000300	/* TSEC1 emergency priority */
#define SPCR_TSEC1EP_SHIFT		(31-23)
#define SPCR_TSEC2DP			0x00000030	/* TSEC2 data priority */
#define SPCR_TSEC2DP_SHIFT		(31-27)
#define SPCR_TSEC2BDP			0x0000000C	/* TSEC2 buffer descriptor priority */
#define SPCR_TSEC2BDP_SHIFT		(31-29)
#define SPCR_TSEC2EP			0x00000003	/* TSEC2 emergency priority */
#define SPCR_TSEC2EP_SHIFT		(31-31)

#elif defined(CONFIG_MPC831X) || defined(CONFIG_MPC837X)
/* SPCR bits - MPC831x and MPC837x specific */
#define SPCR_TSECDP			0x00003000	/* TSEC data priority */
#define SPCR_TSECDP_SHIFT		(31-19)
#define SPCR_TSECBDP			0x00000C00	/* TSEC buffer descriptor priority */
#define SPCR_TSECBDP_SHIFT		(31-21)
#define SPCR_TSECEP			0x00000300	/* TSEC emergency priority */
#define SPCR_TSECEP_SHIFT		(31-23)
#endif

/* SICRL/H - System I/O Configuration Register Low/High
 */
#if defined(CONFIG_MPC834X)
/* SICRL bits - MPC8349 specific */
#define SICRL_LDP_A			0x80000000
#define SICRL_USB1			0x40000000
#define SICRL_USB0			0x20000000
#define SICRL_UART			0x0C000000
#define SICRL_GPIO1_A			0x02000000
#define SICRL_GPIO1_B			0x01000000
#define SICRL_GPIO1_C			0x00800000
#define SICRL_GPIO1_D			0x00400000
#define SICRL_GPIO1_E			0x00200000
#define SICRL_GPIO1_F			0x00180000
#define SICRL_GPIO1_G			0x00040000
#define SICRL_GPIO1_H			0x00020000
#define SICRL_GPIO1_I			0x00010000
#define SICRL_GPIO1_J			0x00008000
#define SICRL_GPIO1_K			0x00004000
#define SICRL_GPIO1_L			0x00003000

/* SICRH bits - MPC8349 specific */
#define SICRH_DDR			0x80000000
#define SICRH_TSEC1_A			0x10000000
#define SICRH_TSEC1_B			0x08000000
#define SICRH_TSEC1_C			0x04000000
#define SICRH_TSEC1_D			0x02000000
#define SICRH_TSEC1_E			0x01000000
#define SICRH_TSEC1_F			0x00800000
#define SICRH_TSEC2_A			0x00400000
#define SICRH_TSEC2_B			0x00200000
#define SICRH_TSEC2_C			0x00100000
#define SICRH_TSEC2_D			0x00080000
#define SICRH_TSEC2_E			0x00040000
#define SICRH_TSEC2_F			0x00020000
#define SICRH_TSEC2_G			0x00010000
#define SICRH_TSEC2_H			0x00008000
#define SICRH_GPIO2_A			0x00004000
#define SICRH_GPIO2_B			0x00002000
#define SICRH_GPIO2_C			0x00001000
#define SICRH_GPIO2_D			0x00000800
#define SICRH_GPIO2_E			0x00000400
#define SICRH_GPIO2_F			0x00000200
#define SICRH_GPIO2_G			0x00000180
#define SICRH_GPIO2_H			0x00000060
#define SICRH_TSOBI1			0x00000002
#define SICRH_TSOBI2			0x00000001

#elif defined(CONFIG_MPC8360)
/* SICRL bits - MPC8360 specific */
#define SICRL_LDP_A			0xC0000000
#define SICRL_LCLK_1			0x10000000
#define SICRL_LCLK_2			0x08000000
#define SICRL_SRCID_A			0x03000000
#define SICRL_IRQ_CKSTP_A		0x00C00000

/* SICRH bits - MPC8360 specific */
#define SICRH_DDR			0x80000000
#define SICRH_SECONDARY_DDR		0x40000000
#define SICRH_SDDROE			0x20000000
#define SICRH_IRQ3			0x10000000
#define SICRH_UC1EOBI			0x00000004
#define SICRH_UC2E1OBI			0x00000002
#define SICRH_UC2E2OBI			0x00000001

#elif defined(CONFIG_MPC832X)
/* SICRL bits - MPC832X specific */
#define SICRL_LDP_LCS_A			0x80000000
#define SICRL_IRQ_CKS			0x20000000
#define SICRL_PCI_MSRC			0x10000000
#define SICRL_URT_CTPR			0x06000000
#define SICRL_IRQ_CTPR			0x00C00000

#elif defined(CONFIG_MPC8313)
/* SICRL bits - MPC8313 specific */
#define SICRL_LBC			0x30000000
#define SICRL_UART			0x0C000000
#define SICRL_SPI_A			0x03000000
#define SICRL_SPI_B			0x00C00000
#define SICRL_SPI_C			0x00300000
#define SICRL_SPI_D			0x000C0000
#define SICRL_USBDR			0x00000C00
#define SICRL_ETSEC1_A			0x0000000C
#define SICRL_ETSEC2_A			0x00000003

/* SICRH bits - MPC8313 specific */
#define SICRH_INTR_A			0x02000000
#define SICRH_INTR_B			0x00C00000
#define SICRH_IIC			0x00300000
#define SICRH_ETSEC2_B			0x000C0000
#define SICRH_ETSEC2_C			0x00030000
#define SICRH_ETSEC2_D			0x0000C000
#define SICRH_ETSEC2_E			0x00003000
#define SICRH_ETSEC2_F			0x00000C00
#define SICRH_ETSEC2_G			0x00000300
#define SICRH_ETSEC1_B			0x00000080
#define SICRH_ETSEC1_C			0x00000060
#define SICRH_GTX1_DLY			0x00000008
#define SICRH_GTX2_DLY			0x00000004
#define SICRH_TSOBI1			0x00000002
#define SICRH_TSOBI2			0x00000001

#elif defined(CONFIG_MPC8315)
/* SICRL bits - MPC8315 specific */
#define SICRL_DMA_CH0			0xc0000000
#define SICRL_DMA_SPI			0x30000000
#define SICRL_UART			0x0c000000
#define SICRL_IRQ4			0x02000000
#define SICRL_IRQ5			0x01800000
#define SICRL_IRQ6_7			0x00400000
#define SICRL_IIC1			0x00300000
#define SICRL_TDM			0x000c0000
#define SICRL_TDM_SHARED		0x00030000
#define SICRL_PCI_A			0x0000c000
#define SICRL_ELBC_A			0x00003000
#define SICRL_ETSEC1_A			0x000000c0
#define SICRL_ETSEC1_B			0x00000030
#define SICRL_ETSEC1_C			0x0000000c
#define SICRL_TSEXPOBI			0x00000001

/* SICRH bits - MPC8315 specific */
#define SICRH_GPIO_0			0xc0000000
#define SICRH_GPIO_1			0x30000000
#define SICRH_GPIO_2			0x0c000000
#define SICRH_GPIO_3			0x03000000
#define SICRH_GPIO_4			0x00c00000
#define SICRH_GPIO_5			0x00300000
#define SICRH_GPIO_6			0x000c0000
#define SICRH_GPIO_7			0x00030000
#define SICRH_GPIO_8			0x0000c000
#define SICRH_GPIO_9			0x00003000
#define SICRH_GPIO_10			0x00000c00
#define SICRH_GPIO_11			0x00000300
#define SICRH_ETSEC2_A			0x000000c0
#define SICRH_TSOBI1			0x00000002
#define SICRH_TSOBI2			0x00000001

#elif defined(CONFIG_MPC837X)
/* SICRL bits - MPC837x specific */
#define SICRL_USB_A			0xC0000000
#define SICRL_USB_B			0x30000000
#define SICRL_USB_B_MASK	0x30000000
#define SICRL_USB_B_SD		0x20000000
#define SICRL_UART			0x0C000000
#define SICRL_GPIO_A			0x02000000
#define SICRL_GPIO_B			0x01000000
#define SICRL_GPIO_C			0x00800000
#define SICRL_GPIO_D			0x00400000
#define SICRL_GPIO_E			0x00200000
#define SICRL_GPIO_F			0x00180000
#define SICRL_GPIO_G			0x00040000
#define SICRL_GPIO_H			0x00020000
#define SICRL_GPIO_I			0x00010000
#define SICRL_GPIO_J			0x00008000
#define SICRL_GPIO_K			0x00004000
#define SICRL_GPIO_L			0x00003000
#define SICRL_DMA_A			0x00000800
#define SICRL_DMA_B			0x00000400
#define SICRL_DMA_C			0x00000200
#define SICRL_DMA_D			0x00000100
#define SICRL_DMA_E			0x00000080
#define SICRL_DMA_F			0x00000040
#define SICRL_DMA_G			0x00000020
#define SICRL_DMA_H			0x00000010
#define SICRL_DMA_I			0x00000008
#define SICRL_DMA_J			0x00000004
#define SICRL_LDP_A			0x00000002
#define SICRL_LDP_B			0x00000001

/* SICRH bits - MPC837x specific */
#define SICRH_DDR			0x80000000
#define SICRH_TSEC1_A			0x10000000
#define SICRH_TSEC1_B			0x08000000
#define SICRH_TSEC2_A			0x00400000
#define SICRH_TSEC2_B			0x00200000
#define SICRH_TSEC2_C			0x00100000
#define SICRH_TSEC2_D			0x00080000
#define SICRH_TSEC2_E			0x00040000
#define SICRH_TMR			0x00010000
#define SICRH_GPIO2_A			0x00008000
#define SICRH_GPIO2_B			0x00004000
#define SICRH_GPIO2_C			0x00002000
#define SICRH_GPIO2_D			0x00001000
#define SICRH_GPIO2_E			0x00000C00
#define SICRH_GPIO2_F			0x00000300
#define SICRH_GPIO2_G			0x000000C0
#define SICRH_GPIO2_H			0x00000030
#define SICRH_SPI			0x00000003
#define SICRH_SPI_MASK		0x00000003
#define SICRH_SPI_SD		0x00000001
#endif

/* SWCRR - System Watchdog Control Register
 */
#define SWCRR				0x0204		/* Register offset to immr */
#define SWCRR_SWTC			0xFFFF0000	/* Software Watchdog Time Count */
#define SWCRR_SWEN			0x00000004	/* Watchdog Enable bit */
#define SWCRR_SWRI			0x00000002	/* Software Watchdog Reset/Interrupt Select bit */
#define SWCRR_SWPR			0x00000001	/* Software Watchdog Counter Prescale bit */
#define SWCRR_RES			~(SWCRR_SWTC | SWCRR_SWEN | SWCRR_SWRI | SWCRR_SWPR)

/* SWCNR - System Watchdog Counter Register
 */
#define SWCNR				0x0208		/* Register offset to immr */
#define SWCNR_SWCN			0x0000FFFF	/* Software Watchdog Count mask */
#define SWCNR_RES			~(SWCNR_SWCN)

/* SWSRR - System Watchdog Service Register
 */
#define SWSRR				0x020E		/* Register offset to immr */

/* ACR - Arbiter Configuration Register
 */
#define ACR_COREDIS			0x10000000	/* Core disable */
#define ACR_COREDIS_SHIFT		(31-7)
#define ACR_PIPE_DEP			0x00070000	/* Pipeline depth */
#define ACR_PIPE_DEP_SHIFT		(31-15)
#define ACR_PCI_RPTCNT			0x00007000	/* PCI repeat count */
#define ACR_PCI_RPTCNT_SHIFT		(31-19)
#define ACR_RPTCNT			0x00000700	/* Repeat count */
#define ACR_RPTCNT_SHIFT		(31-23)
#define ACR_APARK			0x00000030	/* Address parking */
#define ACR_APARK_SHIFT			(31-27)
#define ACR_PARKM			0x0000000F	/* Parking master */
#define ACR_PARKM_SHIFT			(31-31)

/* ATR - Arbiter Timers Register
 */
#define ATR_DTO				0x00FF0000	/* Data time out */
#define ATR_ATO				0x000000FF	/* Address time out */

/* AER - Arbiter Event Register
 */
#define AER_ETEA			0x00000020	/* Transfer error */
#define AER_RES				0x00000010	/* Reserved transfer type */
#define AER_ECW				0x00000008	/* External control word transfer type */
#define AER_AO				0x00000004	/* Address Only transfer type */
#define AER_DTO				0x00000002	/* Data time out */
#define AER_ATO				0x00000001	/* Address time out */

/* AEATR - Arbiter Event Address Register
 */
#define AEATR_EVENT			0x07000000	/* Event type */
#define AEATR_MSTR_ID			0x001F0000	/* Master Id */
#define AEATR_TBST			0x00000800	/* Transfer burst */
#define AEATR_TSIZE			0x00000700	/* Transfer Size */
#define AEATR_TTYPE			0x0000001F	/* Transfer Type */

/* HRCWL - Hard Reset Configuration Word Low
 */
#define HRCWL_LBIUCM			0x80000000
#define HRCWL_LBIUCM_SHIFT		31
#define HRCWL_LCL_BUS_TO_SCB_CLK_1X1	0x00000000
#define HRCWL_LCL_BUS_TO_SCB_CLK_2X1	0x80000000

#define HRCWL_DDRCM			0x40000000
#define HRCWL_DDRCM_SHIFT		30
#define HRCWL_DDR_TO_SCB_CLK_1X1	0x00000000
#define HRCWL_DDR_TO_SCB_CLK_2X1	0x40000000

#define HRCWL_SPMF			0x0f000000
#define HRCWL_SPMF_SHIFT		24
#define HRCWL_CSB_TO_CLKIN_16X1		0x00000000
#define HRCWL_CSB_TO_CLKIN_1X1		0x01000000
#define HRCWL_CSB_TO_CLKIN_2X1		0x02000000
#define HRCWL_CSB_TO_CLKIN_3X1		0x03000000
#define HRCWL_CSB_TO_CLKIN_4X1		0x04000000
#define HRCWL_CSB_TO_CLKIN_5X1		0x05000000
#define HRCWL_CSB_TO_CLKIN_6X1		0x06000000
#define HRCWL_CSB_TO_CLKIN_7X1		0x07000000
#define HRCWL_CSB_TO_CLKIN_8X1		0x08000000
#define HRCWL_CSB_TO_CLKIN_9X1		0x09000000
#define HRCWL_CSB_TO_CLKIN_10X1		0x0A000000
#define HRCWL_CSB_TO_CLKIN_11X1		0x0B000000
#define HRCWL_CSB_TO_CLKIN_12X1		0x0C000000
#define HRCWL_CSB_TO_CLKIN_13X1		0x0D000000
#define HRCWL_CSB_TO_CLKIN_14X1		0x0E000000
#define HRCWL_CSB_TO_CLKIN_15X1		0x0F000000

#define HRCWL_VCO_BYPASS		0x00000000
#define HRCWL_VCO_1X2			0x00000000
#define HRCWL_VCO_1X4			0x00200000
#define HRCWL_VCO_1X8			0x00400000

#define HRCWL_COREPLL			0x007F0000
#define HRCWL_COREPLL_SHIFT		16
#define HRCWL_CORE_TO_CSB_BYPASS	0x00000000
#define HRCWL_CORE_TO_CSB_1X1		0x00020000
#define HRCWL_CORE_TO_CSB_1_5X1		0x00030000
#define HRCWL_CORE_TO_CSB_2X1		0x00040000
#define HRCWL_CORE_TO_CSB_2_5X1		0x00050000
#define HRCWL_CORE_TO_CSB_3X1		0x00060000

#if defined(CONFIG_MPC8360) || defined(CONFIG_MPC832X)
#define HRCWL_CEVCOD			0x000000C0
#define HRCWL_CEVCOD_SHIFT		6
#define HRCWL_CE_PLL_VCO_DIV_4		0x00000000
#define HRCWL_CE_PLL_VCO_DIV_8		0x00000040
#define HRCWL_CE_PLL_VCO_DIV_2		0x00000080

#define HRCWL_CEPDF			0x00000020
#define HRCWL_CEPDF_SHIFT		5
#define HRCWL_CE_PLL_DIV_1X1		0x00000000
#define HRCWL_CE_PLL_DIV_2X1		0x00000020

#define HRCWL_CEPMF			0x0000001F
#define HRCWL_CEPMF_SHIFT		0
#define HRCWL_CE_TO_PLL_1X16_		0x00000000
#define HRCWL_CE_TO_PLL_1X2		0x00000002
#define HRCWL_CE_TO_PLL_1X3		0x00000003
#define HRCWL_CE_TO_PLL_1X4		0x00000004
#define HRCWL_CE_TO_PLL_1X5		0x00000005
#define HRCWL_CE_TO_PLL_1X6		0x00000006
#define HRCWL_CE_TO_PLL_1X7		0x00000007
#define HRCWL_CE_TO_PLL_1X8		0x00000008
#define HRCWL_CE_TO_PLL_1X9		0x00000009
#define HRCWL_CE_TO_PLL_1X10		0x0000000A
#define HRCWL_CE_TO_PLL_1X11		0x0000000B
#define HRCWL_CE_TO_PLL_1X12		0x0000000C
#define HRCWL_CE_TO_PLL_1X13		0x0000000D
#define HRCWL_CE_TO_PLL_1X14		0x0000000E
#define HRCWL_CE_TO_PLL_1X15		0x0000000F
#define HRCWL_CE_TO_PLL_1X16		0x00000010
#define HRCWL_CE_TO_PLL_1X17		0x00000011
#define HRCWL_CE_TO_PLL_1X18		0x00000012
#define HRCWL_CE_TO_PLL_1X19		0x00000013
#define HRCWL_CE_TO_PLL_1X20		0x00000014
#define HRCWL_CE_TO_PLL_1X21		0x00000015
#define HRCWL_CE_TO_PLL_1X22		0x00000016
#define HRCWL_CE_TO_PLL_1X23		0x00000017
#define HRCWL_CE_TO_PLL_1X24		0x00000018
#define HRCWL_CE_TO_PLL_1X25		0x00000019
#define HRCWL_CE_TO_PLL_1X26		0x0000001A
#define HRCWL_CE_TO_PLL_1X27		0x0000001B
#define HRCWL_CE_TO_PLL_1X28		0x0000001C
#define HRCWL_CE_TO_PLL_1X29		0x0000001D
#define HRCWL_CE_TO_PLL_1X30		0x0000001E
#define HRCWL_CE_TO_PLL_1X31		0x0000001F

#elif defined(CONFIG_MPC8315)
#define HRCWL_SVCOD			0x30000000
#define HRCWL_SVCOD_SHIFT		28
#define HRCWL_SVCOD_DIV_2		0x00000000
#define HRCWL_SVCOD_DIV_4		0x10000000
#define HRCWL_SVCOD_DIV_8		0x20000000
#define HRCWL_SVCOD_DIV_1		0x30000000

#elif defined(CONFIG_MPC837X)
#define HRCWL_SVCOD			0x30000000
#define HRCWL_SVCOD_SHIFT		28
#define HRCWL_SVCOD_DIV_4		0x00000000
#define HRCWL_SVCOD_DIV_8		0x10000000
#define HRCWL_SVCOD_DIV_2		0x20000000
#define HRCWL_SVCOD_DIV_1		0x30000000
#endif

/* HRCWH - Hardware Reset Configuration Word High
 */
#define HRCWH_PCI_HOST			0x80000000
#define HRCWH_PCI_HOST_SHIFT		31
#define HRCWH_PCI_AGENT			0x00000000

#if defined(CONFIG_MPC834X)
#define HRCWH_32_BIT_PCI		0x00000000
#define HRCWH_64_BIT_PCI		0x40000000
#endif

#define HRCWH_PCI1_ARBITER_DISABLE	0x00000000
#define HRCWH_PCI1_ARBITER_ENABLE	0x20000000

#define HRCWH_PCI_ARBITER_DISABLE	0x00000000
#define HRCWH_PCI_ARBITER_ENABLE	0x20000000

#if defined(CONFIG_MPC834X)
#define HRCWH_PCI2_ARBITER_DISABLE	0x00000000
#define HRCWH_PCI2_ARBITER_ENABLE	0x10000000

#elif defined(CONFIG_MPC8360)
#define HRCWH_PCICKDRV_DISABLE		0x00000000
#define HRCWH_PCICKDRV_ENABLE		0x10000000
#endif

#define HRCWH_CORE_DISABLE		0x08000000
#define HRCWH_CORE_ENABLE		0x00000000

#define HRCWH_FROM_0X00000100		0x00000000
#define HRCWH_FROM_0XFFF00100		0x04000000

#define HRCWH_BOOTSEQ_DISABLE		0x00000000
#define HRCWH_BOOTSEQ_NORMAL		0x01000000
#define HRCWH_BOOTSEQ_EXTENDED		0x02000000

#define HRCWH_SW_WATCHDOG_DISABLE	0x00000000
#define HRCWH_SW_WATCHDOG_ENABLE	0x00800000

#define HRCWH_ROM_LOC_DDR_SDRAM		0x00000000
#define HRCWH_ROM_LOC_PCI1		0x00100000
#if defined(CONFIG_MPC834X)
#define HRCWH_ROM_LOC_PCI2		0x00200000
#endif
#if defined(CONIFG_MPC837X)
#define HRCWH_ROM_LOC_ON_CHIP_ROM	0x00300000
#endif
#define HRCWH_ROM_LOC_LOCAL_8BIT	0x00500000
#define HRCWH_ROM_LOC_LOCAL_16BIT	0x00600000
#define HRCWH_ROM_LOC_LOCAL_32BIT	0x00700000

#if defined(CONFIG_MPC831X) || defined(CONFIG_MPC837X)
#define HRCWH_ROM_LOC_NAND_SP_8BIT	0x00100000
#define HRCWH_ROM_LOC_NAND_SP_16BIT	0x00200000
#define HRCWH_ROM_LOC_NAND_LP_8BIT	0x00500000
#define HRCWH_ROM_LOC_NAND_LP_16BIT	0x00600000

#define HRCWH_RL_EXT_LEGACY		0x00000000
#define HRCWH_RL_EXT_NAND		0x00040000

#define HRCWH_TSEC1M_IN_MII		0x00000000
#define HRCWH_TSEC1M_IN_RMII		0x00002000
#define HRCWH_TSEC1M_IN_RGMII		0x00006000
#define HRCWH_TSEC1M_IN_RTBI		0x0000A000
#define HRCWH_TSEC1M_IN_SGMII		0x0000C000

#define HRCWH_TSEC2M_IN_MII		0x00000000
#define HRCWH_TSEC2M_IN_RMII		0x00000400
#define HRCWH_TSEC2M_IN_RGMII		0x00000C00
#define HRCWH_TSEC2M_IN_RTBI		0x00001400
#define HRCWH_TSEC2M_IN_SGMII		0x00001800
#endif

#if defined(CONFIG_MPC834X)
#define HRCWH_TSEC1M_IN_RGMII		0x00000000
#define HRCWH_TSEC1M_IN_RTBI		0x00004000
#define HRCWH_TSEC1M_IN_GMII		0x00008000
#define HRCWH_TSEC1M_IN_TBI		0x0000C000
#define HRCWH_TSEC2M_IN_RGMII		0x00000000
#define HRCWH_TSEC2M_IN_RTBI		0x00001000
#define HRCWH_TSEC2M_IN_GMII		0x00002000
#define HRCWH_TSEC2M_IN_TBI		0x00003000
#endif

#if defined(CONFIG_MPC8360)
#define HRCWH_SECONDARY_DDR_DISABLE	0x00000000
#define HRCWH_SECONDARY_DDR_ENABLE	0x00000010
#endif

#define HRCWH_BIG_ENDIAN		0x00000000
#define HRCWH_LITTLE_ENDIAN		0x00000008

#define HRCWH_LALE_NORMAL		0x00000000
#define HRCWH_LALE_EARLY		0x00000004

#define HRCWH_LDP_SET			0x00000000
#define HRCWH_LDP_CLEAR			0x00000002

/* RSR - Reset Status Register
 */
#if defined(CONFIG_MPC831X) || defined(CONFIG_MPC837X)
#define RSR_RSTSRC			0xF0000000	/* Reset source */
#define RSR_RSTSRC_SHIFT		28
#else
#define RSR_RSTSRC			0xE0000000	/* Reset source */
#define RSR_RSTSRC_SHIFT		29
#endif
#define RSR_BSF				0x00010000	/* Boot seq. fail */
#define RSR_BSF_SHIFT			16
#define RSR_SWSR			0x00002000	/* software soft reset */
#define RSR_SWSR_SHIFT			13
#define RSR_SWHR			0x00001000	/* software hard reset */
#define RSR_SWHR_SHIFT			12
#define RSR_JHRS			0x00000200	/* jtag hreset */
#define RSR_JHRS_SHIFT			9
#define RSR_JSRS			0x00000100	/* jtag sreset status */
#define RSR_JSRS_SHIFT			8
#define RSR_CSHR			0x00000010	/* checkstop reset status */
#define RSR_CSHR_SHIFT			4
#define RSR_SWRS			0x00000008	/* software watchdog reset status */
#define RSR_SWRS_SHIFT			3
#define RSR_BMRS			0x00000004	/* bus monitop reset status */
#define RSR_BMRS_SHIFT			2
#define RSR_SRS				0x00000002	/* soft reset status */
#define RSR_SRS_SHIFT			1
#define RSR_HRS				0x00000001	/* hard reset status */
#define RSR_HRS_SHIFT			0
#define RSR_RES				~(RSR_RSTSRC | RSR_BSF | RSR_SWSR | RSR_SWHR |\
					 RSR_JHRS | RSR_JSRS | RSR_CSHR | RSR_SWRS |\
					 RSR_BMRS | RSR_SRS | RSR_HRS)
/* RMR - Reset Mode Register
 */
#define RMR_CSRE			0x00000001	/* checkstop reset enable */
#define RMR_CSRE_SHIFT			0
#define RMR_RES				~(RMR_CSRE)

/* RCR - Reset Control Register
 */
#define RCR_SWHR			0x00000002	/* software hard reset */
#define RCR_SWSR			0x00000001	/* software soft reset */
#define RCR_RES				~(RCR_SWHR | RCR_SWSR)

/* RCER - Reset Control Enable Register
 */
#define RCER_CRE			0x00000001	/* software hard reset */
#define RCER_RES			~(RCER_CRE)

/* SPMR - System PLL Mode Register
 */
#define SPMR_LBIUCM			0x80000000
#define SPMR_DDRCM			0x40000000
#define SPMR_SPMF			0x0F000000
#define SPMR_CKID			0x00800000
#define SPMR_CKID_SHIFT			23
#define SPMR_COREPLL			0x007F0000
#define SPMR_CEVCOD			0x000000C0
#define SPMR_CEPDF			0x00000020
#define SPMR_CEPMF			0x0000001F

/* OCCR - Output Clock Control Register
 */
#define OCCR_PCICOE0			0x80000000
#define OCCR_PCICOE1			0x40000000
#define OCCR_PCICOE2			0x20000000
#define OCCR_PCICOE3			0x10000000
#define OCCR_PCICOE4			0x08000000
#define OCCR_PCICOE5			0x04000000
#define OCCR_PCICOE6			0x02000000
#define OCCR_PCICOE7			0x01000000
#define OCCR_PCICD0			0x00800000
#define OCCR_PCICD1			0x00400000
#define OCCR_PCICD2			0x00200000
#define OCCR_PCICD3			0x00100000
#define OCCR_PCICD4			0x00080000
#define OCCR_PCICD5			0x00040000
#define OCCR_PCICD6			0x00020000
#define OCCR_PCICD7			0x00010000
#define OCCR_PCI1CR			0x00000002
#define OCCR_PCI2CR			0x00000001
#define OCCR_PCICR			OCCR_PCI1CR

/* SCCR - System Clock Control Register
 */
#define SCCR_ENCCM			0x03000000
#define SCCR_ENCCM_SHIFT		24
#define SCCR_ENCCM_0			0x00000000
#define SCCR_ENCCM_1			0x01000000
#define SCCR_ENCCM_2			0x02000000
#define SCCR_ENCCM_3			0x03000000

#define SCCR_PCICM			0x00010000
#define SCCR_PCICM_SHIFT		16

#if defined(CONFIG_MPC834X)
/* SCCR bits - MPC834x specific */
#define SCCR_TSEC1CM			0xc0000000
#define SCCR_TSEC1CM_SHIFT		30
#define SCCR_TSEC1CM_0			0x00000000
#define SCCR_TSEC1CM_1			0x40000000
#define SCCR_TSEC1CM_2			0x80000000
#define SCCR_TSEC1CM_3			0xC0000000

#define SCCR_TSEC2CM			0x30000000
#define SCCR_TSEC2CM_SHIFT		28
#define SCCR_TSEC2CM_0			0x00000000
#define SCCR_TSEC2CM_1			0x10000000
#define SCCR_TSEC2CM_2			0x20000000
#define SCCR_TSEC2CM_3			0x30000000

/* The MPH must have the same clock ratio as DR, unless its clock disabled */
#define SCCR_USBMPHCM			0x00c00000
#define SCCR_USBMPHCM_SHIFT		22
#define SCCR_USBDRCM			0x00300000
#define SCCR_USBDRCM_SHIFT		20
#define SCCR_USBCM			0x00f00000
#define SCCR_USBCM_SHIFT		20
#define SCCR_USBCM_0			0x00000000
#define SCCR_USBCM_1			0x00500000
#define SCCR_USBCM_2			0x00A00000
#define SCCR_USBCM_3			0x00F00000

#elif defined(CONFIG_MPC8313)
/* TSEC1 bits are for TSEC2 as well */
#define SCCR_TSEC1CM			0xc0000000
#define SCCR_TSEC1CM_SHIFT		30
#define SCCR_TSEC1CM_0			0x00000000
#define SCCR_TSEC1CM_1			0x40000000
#define SCCR_TSEC1CM_2			0x80000000
#define SCCR_TSEC1CM_3			0xC0000000

#define SCCR_TSEC1ON			0x20000000
#define SCCR_TSEC1ON_SHIFT		29
#define SCCR_TSEC2ON			0x10000000
#define SCCR_TSEC2ON_SHIFT		28

#define SCCR_USBDRCM			0x00300000
#define SCCR_USBDRCM_SHIFT		20
#define SCCR_USBDRCM_0			0x00000000
#define SCCR_USBDRCM_1			0x00100000
#define SCCR_USBDRCM_2			0x00200000
#define SCCR_USBDRCM_3			0x00300000

#elif defined(CONFIG_MPC8315)
/* SCCR bits - MPC8315 specific */
#define SCCR_TSEC1CM			0xc0000000
#define SCCR_TSEC1CM_SHIFT		30
#define SCCR_TSEC1CM_0			0x00000000
#define SCCR_TSEC1CM_1			0x40000000
#define SCCR_TSEC1CM_2			0x80000000
#define SCCR_TSEC1CM_3			0xC0000000

#define SCCR_TSEC2CM			0x30000000
#define SCCR_TSEC2CM_SHIFT		28
#define SCCR_TSEC2CM_0			0x00000000
#define SCCR_TSEC2CM_1			0x10000000
#define SCCR_TSEC2CM_2			0x20000000
#define SCCR_TSEC2CM_3			0x30000000

#define SCCR_USBDRCM			0x00c00000
#define SCCR_USBDRCM_SHIFT		22
#define SCCR_USBDRCM_0			0x00000000
#define SCCR_USBDRCM_1			0x00400000
#define SCCR_USBDRCM_2			0x00800000
#define SCCR_USBDRCM_3			0x00c00000

#define SCCR_PCIEXP1CM			0x00300000
#define SCCR_PCIEXP2CM			0x000c0000

#define SCCR_SATA1CM			0x00003000
#define SCCR_SATA1CM_SHIFT		12
#define SCCR_SATACM			0x00003c00
#define SCCR_SATACM_SHIFT		10
#define SCCR_SATACM_0			0x00000000
#define SCCR_SATACM_1			0x00001400
#define SCCR_SATACM_2			0x00002800
#define SCCR_SATACM_3			0x00003c00

#define SCCR_TDMCM			0x00000030
#define SCCR_TDMCM_SHIFT		4
#define SCCR_TDMCM_0			0x00000000
#define SCCR_TDMCM_1			0x00000010
#define SCCR_TDMCM_2			0x00000020
#define SCCR_TDMCM_3			0x00000030

#elif defined(CONFIG_MPC837X)
/* SCCR bits - MPC837x specific */
#define SCCR_TSEC1CM			0xc0000000
#define SCCR_TSEC1CM_SHIFT		30
#define SCCR_TSEC1CM_0			0x00000000
#define SCCR_TSEC1CM_1			0x40000000
#define SCCR_TSEC1CM_2			0x80000000
#define SCCR_TSEC1CM_3			0xC0000000

#define SCCR_TSEC2CM			0x30000000
#define SCCR_TSEC2CM_SHIFT		28
#define SCCR_TSEC2CM_0			0x00000000
#define SCCR_TSEC2CM_1			0x10000000
#define SCCR_TSEC2CM_2			0x20000000
#define SCCR_TSEC2CM_3			0x30000000

#define SCCR_SDHCCM			0x0c000000
#define SCCR_SDHCCM_SHIFT		26
#define SCCR_SDHCCM_0			0x00000000
#define SCCR_SDHCCM_1			0x04000000
#define SCCR_SDHCCM_2			0x08000000
#define SCCR_SDHCCM_3			0x0c000000

#define SCCR_USBDRCM			0x00c00000
#define SCCR_USBDRCM_SHIFT		22
#define SCCR_USBDRCM_0			0x00000000
#define SCCR_USBDRCM_1			0x00400000
#define SCCR_USBDRCM_2			0x00800000
#define SCCR_USBDRCM_3			0x00c00000

#define SCCR_PCIEXP1CM			0x00300000
#define SCCR_PCIEXP1CM_SHIFT		20
#define SCCR_PCIEXP1CM_0		0x00000000
#define SCCR_PCIEXP1CM_1		0x00100000
#define SCCR_PCIEXP1CM_2		0x00200000
#define SCCR_PCIEXP1CM_3		0x00300000

#define SCCR_PCIEXP2CM			0x000c0000
#define SCCR_PCIEXP2CM_SHIFT		18
#define SCCR_PCIEXP2CM_0		0x00000000
#define SCCR_PCIEXP2CM_1		0x00040000
#define SCCR_PCIEXP2CM_2		0x00080000
#define SCCR_PCIEXP2CM_3		0x000c0000

/* All of the four SATA controllers must have the same clock ratio */
#define SCCR_SATA1CM			0x000000c0
#define SCCR_SATA1CM_SHIFT		6
#define SCCR_SATACM			0x000000ff
#define SCCR_SATACM_SHIFT		0
#define SCCR_SATACM_0			0x00000000
#define SCCR_SATACM_1			0x00000055
#define SCCR_SATACM_2			0x000000aa
#define SCCR_SATACM_3			0x000000ff
#endif

/* CSn_BDNS - Chip Select memory Bounds Register
 */
#define CSBNDS_SA			0x00FF0000
#define CSBNDS_SA_SHIFT			8
#define CSBNDS_EA			0x000000FF
#define CSBNDS_EA_SHIFT			24

/* CSn_CONFIG - Chip Select Configuration Register
 */
#define CSCONFIG_EN			0x80000000
#define CSCONFIG_AP			0x00800000
#define CSCONFIG_ODT_WR_ACS		0x00010000
#define CSCONFIG_ROW_BIT		0x00000700
#define CSCONFIG_ROW_BIT_12		0x00000000
#define CSCONFIG_ROW_BIT_13		0x00000100
#define CSCONFIG_ROW_BIT_14		0x00000200
#define CSCONFIG_COL_BIT		0x00000007
#define CSCONFIG_COL_BIT_8		0x00000000
#define CSCONFIG_COL_BIT_9		0x00000001
#define CSCONFIG_COL_BIT_10		0x00000002
#define CSCONFIG_COL_BIT_11		0x00000003

/* TIMING_CFG_0 - DDR SDRAM Timing Configuration 0
 */
#define TIMING_CFG0_RWT			0xC0000000
#define TIMING_CFG0_RWT_SHIFT		30
#define TIMING_CFG0_WRT			0x30000000
#define TIMING_CFG0_WRT_SHIFT		28
#define TIMING_CFG0_RRT			0x0C000000
#define TIMING_CFG0_RRT_SHIFT		26
#define TIMING_CFG0_WWT			0x03000000
#define TIMING_CFG0_WWT_SHIFT		24
#define TIMING_CFG0_ACT_PD_EXIT		0x00700000
#define TIMING_CFG0_ACT_PD_EXIT_SHIFT	20
#define TIMING_CFG0_PRE_PD_EXIT		0x00070000
#define TIMING_CFG0_PRE_PD_EXIT_SHIFT	16
#define TIMING_CFG0_ODT_PD_EXIT		0x00000F00
#define TIMING_CFG0_ODT_PD_EXIT_SHIFT	8
#define TIMING_CFG0_MRS_CYC		0x0000000F
#define TIMING_CFG0_MRS_CYC_SHIFT	0

/* TIMING_CFG_1 - DDR SDRAM Timing Configuration 1
 */
#define TIMING_CFG1_PRETOACT		0x70000000
#define TIMING_CFG1_PRETOACT_SHIFT	28
#define TIMING_CFG1_ACTTOPRE		0x0F000000
#define TIMING_CFG1_ACTTOPRE_SHIFT	24
#define TIMING_CFG1_ACTTORW		0x00700000
#define TIMING_CFG1_ACTTORW_SHIFT	20
#define TIMING_CFG1_CASLAT		0x00070000
#define TIMING_CFG1_CASLAT_SHIFT	16
#define TIMING_CFG1_REFREC		0x0000F000
#define TIMING_CFG1_REFREC_SHIFT	12
#define TIMING_CFG1_WRREC		0x00000700
#define TIMING_CFG1_WRREC_SHIFT		8
#define TIMING_CFG1_ACTTOACT		0x00000070
#define TIMING_CFG1_ACTTOACT_SHIFT	4
#define TIMING_CFG1_WRTORD		0x00000007
#define TIMING_CFG1_WRTORD_SHIFT	0
#define TIMING_CFG1_CASLAT_20		0x00030000	/* CAS latency = 2.0 */
#define TIMING_CFG1_CASLAT_25		0x00040000	/* CAS latency = 2.5 */
#define TIMING_CFG1_CASLAT_30		0x00050000	/* CAS latency = 2.5 */

/* TIMING_CFG_2 - DDR SDRAM Timing Configuration 2
 */
#define TIMING_CFG2_CPO			0x0F800000
#define TIMING_CFG2_CPO_SHIFT		23
#define TIMING_CFG2_ACSM		0x00080000
#define TIMING_CFG2_WR_DATA_DELAY	0x00001C00
#define TIMING_CFG2_WR_DATA_DELAY_SHIFT	10
#define TIMING_CFG2_CPO_DEF		0x00000000	/* default (= CASLAT + 1) */

#define TIMING_CFG2_ADD_LAT		0x70000000
#define TIMING_CFG2_ADD_LAT_SHIFT	28
#define TIMING_CFG2_WR_LAT_DELAY	0x00380000
#define TIMING_CFG2_WR_LAT_DELAY_SHIFT	19
#define TIMING_CFG2_RD_TO_PRE		0x0000E000
#define TIMING_CFG2_RD_TO_PRE_SHIFT	13
#define TIMING_CFG2_CKE_PLS		0x000001C0
#define TIMING_CFG2_CKE_PLS_SHIFT	6
#define TIMING_CFG2_FOUR_ACT		0x0000003F
#define TIMING_CFG2_FOUR_ACT_SHIFT	0

/* DDR_SDRAM_CFG - DDR SDRAM Control Configuration
 */
#define SDRAM_CFG_MEM_EN		0x80000000
#define SDRAM_CFG_SREN			0x40000000
#define SDRAM_CFG_ECC_EN		0x20000000
#define SDRAM_CFG_RD_EN			0x10000000
#define SDRAM_CFG_SDRAM_TYPE_DDR1	0x02000000
#define SDRAM_CFG_SDRAM_TYPE_DDR2	0x03000000
#define SDRAM_CFG_SDRAM_TYPE_MASK	0x07000000
#define SDRAM_CFG_SDRAM_TYPE_SHIFT	24
#define SDRAM_CFG_DYN_PWR		0x00200000
#define SDRAM_CFG_32_BE			0x00080000
#define SDRAM_CFG_8_BE			0x00040000
#define SDRAM_CFG_NCAP			0x00020000
#define SDRAM_CFG_2T_EN			0x00008000
#define SDRAM_CFG_HSE			0x00000008
#define SDRAM_CFG_BI			0x00000001

/* DDR_SDRAM_MODE - DDR SDRAM Mode Register
 */
#define SDRAM_MODE_ESD			0xFFFF0000
#define SDRAM_MODE_ESD_SHIFT		16
#define SDRAM_MODE_SD			0x0000FFFF
#define SDRAM_MODE_SD_SHIFT		0
#define DDR_MODE_EXT_MODEREG		0x4000		/* select extended mode reg */
#define DDR_MODE_EXT_OPMODE		0x3FF8		/* operating mode, mask */
#define DDR_MODE_EXT_OP_NORMAL		0x0000		/* normal operation */
#define DDR_MODE_QFC			0x0004		/* QFC / compatibility, mask */
#define DDR_MODE_QFC_COMP		0x0000		/* compatible to older SDRAMs */
#define DDR_MODE_WEAK			0x0002		/* weak drivers */
#define DDR_MODE_DLL_DIS		0x0001		/* disable DLL */
#define DDR_MODE_CASLAT			0x0070		/* CAS latency, mask */
#define DDR_MODE_CASLAT_15		0x0010		/* CAS latency 1.5 */
#define DDR_MODE_CASLAT_20		0x0020		/* CAS latency 2 */
#define DDR_MODE_CASLAT_25		0x0060		/* CAS latency 2.5 */
#define DDR_MODE_CASLAT_30		0x0030		/* CAS latency 3 */
#define DDR_MODE_BTYPE_SEQ		0x0000		/* sequential burst */
#define DDR_MODE_BTYPE_ILVD		0x0008		/* interleaved burst */
#define DDR_MODE_BLEN_2			0x0001		/* burst length 2 */
#define DDR_MODE_BLEN_4			0x0002		/* burst length 4 */
#define DDR_REFINT_166MHZ_7US		1302		/* exact value for 7.8125us */
#define DDR_BSTOPRE			256		/* use 256 cycles as a starting point */
#define DDR_MODE_MODEREG		0x0000		/* select mode register */

/* DDR_SDRAM_INTERVAL - DDR SDRAM Interval Register
 */
#define SDRAM_INTERVAL_REFINT		0x3FFF0000
#define SDRAM_INTERVAL_REFINT_SHIFT	16
#define SDRAM_INTERVAL_BSTOPRE		0x00003FFF
#define SDRAM_INTERVAL_BSTOPRE_SHIFT	0

/* DDR_SDRAM_CLK_CNTL - DDR SDRAM Clock Control Register
 */
#define DDR_SDRAM_CLK_CNTL_SS_EN		0x80000000
#define DDR_SDRAM_CLK_CNTL_CLK_ADJUST_025	0x01000000
#define DDR_SDRAM_CLK_CNTL_CLK_ADJUST_05	0x02000000
#define DDR_SDRAM_CLK_CNTL_CLK_ADJUST_075	0x03000000
#define DDR_SDRAM_CLK_CNTL_CLK_ADJUST_1		0x04000000

/* ECC_ERR_INJECT - Memory data path error injection mask ECC
 */
#define ECC_ERR_INJECT_EMB		(0x80000000>>22)	/* ECC Mirror Byte */
#define ECC_ERR_INJECT_EIEN		(0x80000000>>23)	/* Error Injection Enable */
#define ECC_ERR_INJECT_EEIM		(0xff000000>>24)	/* ECC Erroe Injection Enable */
#define ECC_ERR_INJECT_EEIM_SHIFT	0

/* CAPTURE_ECC - Memory data path read capture ECC
 */
#define CAPTURE_ECC_ECE			(0xff000000>>24)
#define CAPTURE_ECC_ECE_SHIFT		0

/* ERR_DETECT - Memory error detect
 */
#define ECC_ERROR_DETECT_MME		(0x80000000>>0)		/* Multiple Memory Errors */
#define ECC_ERROR_DETECT_MBE		(0x80000000>>28)	/* Multiple-Bit Error */
#define ECC_ERROR_DETECT_SBE		(0x80000000>>29)	/* Single-Bit ECC Error Pickup */
#define ECC_ERROR_DETECT_MSE		(0x80000000>>31)	/* Memory Select Error */

/* ERR_DISABLE - Memory error disable
 */
#define ECC_ERROR_DISABLE_MBED		(0x80000000>>28)	/* Multiple-Bit ECC Error Disable */
#define ECC_ERROR_DISABLE_SBED		(0x80000000>>29)	/* Sinle-Bit ECC Error disable */
#define ECC_ERROR_DISABLE_MSED		(0x80000000>>31)	/* Memory Select Error Disable */
#define ECC_ERROR_ENABLE		~(ECC_ERROR_DISABLE_MSED | ECC_ERROR_DISABLE_SBED |\
					 ECC_ERROR_DISABLE_MBED)
/* ERR_INT_EN - Memory error interrupt enable
 */
#define ECC_ERR_INT_EN_MBEE		(0x80000000>>28)	/* Multiple-Bit ECC Error Interrupt Enable */
#define ECC_ERR_INT_EN_SBEE		(0x80000000>>29)	/* Single-Bit ECC Error Interrupt Enable */
#define ECC_ERR_INT_EN_MSEE		(0x80000000>>31)	/* Memory Select Error Interrupt Enable */
#define ECC_ERR_INT_DISABLE		~(ECC_ERR_INT_EN_MBEE | ECC_ERR_INT_EN_SBEE |\
					 ECC_ERR_INT_EN_MSEE)
/* CAPTURE_ATTRIBUTES - Memory error attributes capture
 */
#define ECC_CAPT_ATTR_BNUM		(0xe0000000>>1)		/* Data Beat Num */
#define ECC_CAPT_ATTR_BNUM_SHIFT	28
#define ECC_CAPT_ATTR_TSIZ		(0xc0000000>>6)		/* Transaction Size */
#define ECC_CAPT_ATTR_TSIZ_FOUR_DW	0
#define ECC_CAPT_ATTR_TSIZ_ONE_DW	1
#define ECC_CAPT_ATTR_TSIZ_TWO_DW	2
#define ECC_CAPT_ATTR_TSIZ_THREE_DW	3
#define ECC_CAPT_ATTR_TSIZ_SHIFT	24
#define ECC_CAPT_ATTR_TSRC		(0xf8000000>>11)	/* Transaction Source */
#define ECC_CAPT_ATTR_TSRC_E300_CORE_DT	0x0
#define ECC_CAPT_ATTR_TSRC_E300_CORE_IF	0x2
#define ECC_CAPT_ATTR_TSRC_TSEC1	0x4
#define ECC_CAPT_ATTR_TSRC_TSEC2	0x5
#define ECC_CAPT_ATTR_TSRC_USB		(0x06|0x07)
#define ECC_CAPT_ATTR_TSRC_ENCRYPT	0x8
#define ECC_CAPT_ATTR_TSRC_I2C		0x9
#define ECC_CAPT_ATTR_TSRC_JTAG		0xA
#define ECC_CAPT_ATTR_TSRC_PCI1		0xD
#define ECC_CAPT_ATTR_TSRC_PCI2		0xE
#define ECC_CAPT_ATTR_TSRC_DMA		0xF
#define ECC_CAPT_ATTR_TSRC_SHIFT	16
#define ECC_CAPT_ATTR_TTYP		(0xe0000000>>18)	/* Transaction Type */
#define ECC_CAPT_ATTR_TTYP_WRITE	0x1
#define ECC_CAPT_ATTR_TTYP_READ		0x2
#define ECC_CAPT_ATTR_TTYP_R_M_W	0x3
#define ECC_CAPT_ATTR_TTYP_SHIFT	12
#define ECC_CAPT_ATTR_VLD		(0x80000000>>31)	/* Valid */

/* ERR_SBE - Single bit ECC memory error management
 */
#define ECC_ERROR_MAN_SBET		(0xff000000>>8)		/* Single-Bit Error Threshold 0..255 */
#define ECC_ERROR_MAN_SBET_SHIFT	16
#define ECC_ERROR_MAN_SBEC		(0xff000000>>24)	/* Single Bit Error Counter 0..255 */
#define ECC_ERROR_MAN_SBEC_SHIFT	0

/* BR - Base Registers
 */
#define BR0				0x5000		/* Register offset to immr */
#define BR1				0x5008
#define BR2				0x5010
#define BR3				0x5018
#define BR4				0x5020
#define BR5				0x5028
#define BR6				0x5030
#define BR7				0x5038

#define BR_BA				0xFFFF8000
#define BR_BA_SHIFT			15
#define BR_PS				0x00001800
#define BR_PS_SHIFT			11
#define BR_PS_8				0x00000800	/* Port Size 8 bit */
#define BR_PS_16			0x00001000	/* Port Size 16 bit */
#define BR_PS_32			0x00001800	/* Port Size 32 bit */
#define BR_DECC				0x00000600
#define BR_DECC_SHIFT			9
#define BR_DECC_OFF			0x00000000
#define BR_DECC_CHK			0x00000200
#define BR_DECC_CHK_GEN			0x00000400
#define BR_WP				0x00000100
#define BR_WP_SHIFT			8
#define BR_MSEL				0x000000E0
#define BR_MSEL_SHIFT			5
#define BR_MS_GPCM			0x00000000	/* GPCM */
#define BR_MS_FCM			0x00000020	/* FCM */
#define BR_MS_SDRAM			0x00000060	/* SDRAM */
#define BR_MS_UPMA			0x00000080	/* UPMA */
#define BR_MS_UPMB			0x000000A0	/* UPMB */
#define BR_MS_UPMC			0x000000C0	/* UPMC */
#if !defined(CONFIG_MPC834X)
#define BR_ATOM				0x0000000C
#define BR_ATOM_SHIFT			2
#endif
#define BR_V				0x00000001
#define BR_V_SHIFT			0

#if defined(CONFIG_MPC834X)
#define BR_RES				~(BR_BA | BR_PS | BR_DECC | BR_WP | BR_MSEL | BR_V)
#else
#define BR_RES				~(BR_BA | BR_PS | BR_DECC | BR_WP | BR_MSEL | BR_ATOM | BR_V)
#endif

/* OR - Option Registers
 */
#define OR0				0x5004		/* Register offset to immr */
#define OR1				0x500C
#define OR2				0x5014
#define OR3				0x501C
#define OR4				0x5024
#define OR5				0x502C
#define OR6				0x5034
#define OR7				0x503C

#define OR_GPCM_AM			0xFFFF8000
#define OR_GPCM_AM_SHIFT		15
#define OR_GPCM_BCTLD			0x00001000
#define OR_GPCM_BCTLD_SHIFT		12
#define OR_GPCM_CSNT			0x00000800
#define OR_GPCM_CSNT_SHIFT		11
#define OR_GPCM_ACS			0x00000600
#define OR_GPCM_ACS_SHIFT		9
#define OR_GPCM_ACS_0b10		0x00000400
#define OR_GPCM_ACS_0b11		0x00000600
#define OR_GPCM_XACS			0x00000100
#define OR_GPCM_XACS_SHIFT		8
#define OR_GPCM_SCY			0x000000F0
#define OR_GPCM_SCY_SHIFT		4
#define OR_GPCM_SCY_1			0x00000010
#define OR_GPCM_SCY_2			0x00000020
#define OR_GPCM_SCY_3			0x00000030
#define OR_GPCM_SCY_4			0x00000040
#define OR_GPCM_SCY_5			0x00000050
#define OR_GPCM_SCY_6			0x00000060
#define OR_GPCM_SCY_7			0x00000070
#define OR_GPCM_SCY_8			0x00000080
#define OR_GPCM_SCY_9			0x00000090
#define OR_GPCM_SCY_10			0x000000a0
#define OR_GPCM_SCY_11			0x000000b0
#define OR_GPCM_SCY_12			0x000000c0
#define OR_GPCM_SCY_13			0x000000d0
#define OR_GPCM_SCY_14			0x000000e0
#define OR_GPCM_SCY_15			0x000000f0
#define OR_GPCM_SETA			0x00000008
#define OR_GPCM_SETA_SHIFT		3
#define OR_GPCM_TRLX			0x00000004
#define OR_GPCM_TRLX_SHIFT		2
#define OR_GPCM_EHTR			0x00000002
#define OR_GPCM_EHTR_SHIFT		1
#define OR_GPCM_EAD			0x00000001
#define OR_GPCM_EAD_SHIFT		0

#define OR_FCM_AM			0xFFFF8000
#define OR_FCM_AM_SHIFT				15
#define OR_FCM_BCTLD			0x00001000
#define OR_FCM_BCTLD_SHIFT			12
#define OR_FCM_PGS			0x00000400
#define OR_FCM_PGS_SHIFT			10
#define OR_FCM_CSCT			0x00000200
#define OR_FCM_CSCT_SHIFT			 9
#define OR_FCM_CST			0x00000100
#define OR_FCM_CST_SHIFT			 8
#define OR_FCM_CHT			0x00000080
#define OR_FCM_CHT_SHIFT			 7
#define OR_FCM_SCY			0x00000070
#define OR_FCM_SCY_SHIFT			 4
#define OR_FCM_SCY_1			0x00000010
#define OR_FCM_SCY_2			0x00000020
#define OR_FCM_SCY_3			0x00000030
#define OR_FCM_SCY_4			0x00000040
#define OR_FCM_SCY_5			0x00000050
#define OR_FCM_SCY_6			0x00000060
#define OR_FCM_SCY_7			0x00000070
#define OR_FCM_RST			0x00000008
#define OR_FCM_RST_SHIFT			 3
#define OR_FCM_TRLX			0x00000004
#define OR_FCM_TRLX_SHIFT			 2
#define OR_FCM_EHTR			0x00000002
#define OR_FCM_EHTR_SHIFT			 1

#define OR_UPM_AM			0xFFFF8000
#define OR_UPM_AM_SHIFT			15
#define OR_UPM_XAM			0x00006000
#define OR_UPM_XAM_SHIFT		13
#define OR_UPM_BCTLD			0x00001000
#define OR_UPM_BCTLD_SHIFT		12
#define OR_UPM_BI			0x00000100
#define OR_UPM_BI_SHIFT			8
#define OR_UPM_TRLX			0x00000004
#define OR_UPM_TRLX_SHIFT		2
#define OR_UPM_EHTR			0x00000002
#define OR_UPM_EHTR_SHIFT		1
#define OR_UPM_EAD			0x00000001
#define OR_UPM_EAD_SHIFT		0

#define OR_SDRAM_AM			0xFFFF8000
#define OR_SDRAM_AM_SHIFT		15
#define OR_SDRAM_XAM			0x00006000
#define OR_SDRAM_XAM_SHIFT		13
#define OR_SDRAM_COLS			0x00001C00
#define OR_SDRAM_COLS_SHIFT		10
#define OR_SDRAM_ROWS			0x000001C0
#define OR_SDRAM_ROWS_SHIFT		6
#define OR_SDRAM_PMSEL			0x00000020
#define OR_SDRAM_PMSEL_SHIFT		5
#define OR_SDRAM_EAD			0x00000001
#define OR_SDRAM_EAD_SHIFT		0

#define OR_AM_32KB			0xFFFF8000
#define OR_AM_64KB			0xFFFF0000
#define OR_AM_128KB			0xFFFE0000
#define OR_AM_256KB			0xFFFC0000
#define OR_AM_512KB			0xFFF80000
#define OR_AM_1MB			0xFFF00000
#define OR_AM_2MB			0xFFE00000
#define OR_AM_4MB			0xFFC00000
#define OR_AM_8MB			0xFF800000
#define OR_AM_16MB			0xFF000000
#define OR_AM_32MB			0xFE000000
#define OR_AM_64MB			0xFC000000
#define OR_AM_128MB			0xF8000000
#define OR_AM_256MB			0xF0000000
#define OR_AM_512MB			0xE0000000
#define OR_AM_1GB			0xC0000000
#define OR_AM_2GB			0x80000000
#define OR_AM_4GB			0x00000000

#define LBLAWAR_EN			0x80000000
#define LBLAWAR_4KB			0x0000000B
#define LBLAWAR_8KB			0x0000000C
#define LBLAWAR_16KB			0x0000000D
#define LBLAWAR_32KB			0x0000000E
#define LBLAWAR_64KB			0x0000000F
#define LBLAWAR_128KB			0x00000010
#define LBLAWAR_256KB			0x00000011
#define LBLAWAR_512KB			0x00000012
#define LBLAWAR_1MB			0x00000013
#define LBLAWAR_2MB			0x00000014
#define LBLAWAR_4MB			0x00000015
#define LBLAWAR_8MB			0x00000016
#define LBLAWAR_16MB			0x00000017
#define LBLAWAR_32MB			0x00000018
#define LBLAWAR_64MB			0x00000019
#define LBLAWAR_128MB			0x0000001A
#define LBLAWAR_256MB			0x0000001B
#define LBLAWAR_512MB			0x0000001C
#define LBLAWAR_1GB			0x0000001D
#define LBLAWAR_2GB			0x0000001E

/* LBCR - Local Bus Configuration Register
 */
#define LBCR_LDIS			0x80000000
#define LBCR_LDIS_SHIFT			31
#define LBCR_BCTLC			0x00C00000
#define LBCR_BCTLC_SHIFT		22
#define LBCR_LPBSE			0x00020000
#define LBCR_LPBSE_SHIFT		17
#define LBCR_EPAR			0x00010000
#define LBCR_EPAR_SHIFT			16
#define LBCR_BMT			0x0000FF00
#define LBCR_BMT_SHIFT			8

/* LCRR - Clock Ratio Register
 */
#define LCRR_DBYP			0x80000000
#define LCRR_DBYP_SHIFT			31
#define LCRR_BUFCMDC			0x30000000
#define LCRR_BUFCMDC_SHIFT		28
#define LCRR_BUFCMDC_1			0x10000000
#define LCRR_BUFCMDC_2			0x20000000
#define LCRR_BUFCMDC_3			0x30000000
#define LCRR_BUFCMDC_4			0x00000000
#define LCRR_ECL			0x03000000
#define LCRR_ECL_SHIFT			24
#define LCRR_ECL_4			0x00000000
#define LCRR_ECL_5			0x01000000
#define LCRR_ECL_6			0x02000000
#define LCRR_ECL_7			0x03000000
#define LCRR_EADC			0x00030000
#define LCRR_EADC_SHIFT			16
#define LCRR_EADC_1			0x00010000
#define LCRR_EADC_2			0x00020000
#define LCRR_EADC_3			0x00030000
#define LCRR_EADC_4			0x00000000
#define LCRR_CLKDIV			0x0000000F
#define LCRR_CLKDIV_SHIFT		0
#define LCRR_CLKDIV_2			0x00000002
#define LCRR_CLKDIV_4			0x00000004
#define LCRR_CLKDIV_8			0x00000008

/* DMAMR - DMA Mode Register
 */
#define DMA_CHANNEL_START			0x00000001	/* Bit - DMAMRn CS */
#define DMA_CHANNEL_TRANSFER_MODE_DIRECT	0x00000004	/* Bit - DMAMRn CTM */
#define DMA_CHANNEL_SOURCE_ADRESSS_HOLD_EN	0x00001000	/* Bit - DMAMRn SAHE */
#define DMA_CHANNEL_SOURCE_ADDRESS_HOLD_1B	0x00000000	/* 2Bit- DMAMRn SAHTS 1byte */
#define DMA_CHANNEL_SOURCE_ADDRESS_HOLD_2B	0x00004000	/* 2Bit- DMAMRn SAHTS 2bytes */
#define DMA_CHANNEL_SOURCE_ADDRESS_HOLD_4B	0x00008000	/* 2Bit- DMAMRn SAHTS 4bytes */
#define DMA_CHANNEL_SOURCE_ADDRESS_HOLD_8B	0x0000c000	/* 2Bit- DMAMRn SAHTS 8bytes */
#define DMA_CHANNEL_SNOOP			0x00010000	/* Bit - DMAMRn DMSEN */

/* DMASR - DMA Status Register
 */
#define DMA_CHANNEL_BUSY			0x00000004	/* Bit - DMASRn CB */
#define DMA_CHANNEL_TRANSFER_ERROR		0x00000080	/* Bit - DMASRn TE */

/* CONFIG_ADDRESS - PCI Config Address Register
 */
#define PCI_CONFIG_ADDRESS_EN		0x80000000
#define PCI_CONFIG_ADDRESS_BN_SHIFT	16
#define PCI_CONFIG_ADDRESS_BN_MASK	0x00ff0000
#define PCI_CONFIG_ADDRESS_DN_SHIFT	11
#define PCI_CONFIG_ADDRESS_DN_MASK	0x0000f800
#define PCI_CONFIG_ADDRESS_FN_SHIFT	8
#define PCI_CONFIG_ADDRESS_FN_MASK	0x00000700
#define PCI_CONFIG_ADDRESS_RN_SHIFT	0
#define PCI_CONFIG_ADDRESS_RN_MASK	0x000000fc

/* POTAR - PCI Outbound Translation Address Register
 */
#define POTAR_TA_MASK			0x000fffff

/* POBAR - PCI Outbound Base Address Register
 */
#define POBAR_BA_MASK			0x000fffff

/* POCMR - PCI Outbound Comparision Mask Register
 */
#define POCMR_EN			0x80000000
#define POCMR_IO			0x40000000	/* 0-memory space 1-I/O space */
#define POCMR_SE			0x20000000	/* streaming enable */
#define POCMR_DST			0x10000000	/* 0-PCI1 1-PCI2 */
#define POCMR_CM_MASK			0x000fffff
#define POCMR_CM_4G			0x00000000
#define POCMR_CM_2G			0x00080000
#define POCMR_CM_1G			0x000C0000
#define POCMR_CM_512M			0x000E0000
#define POCMR_CM_256M			0x000F0000
#define POCMR_CM_128M			0x000F8000
#define POCMR_CM_64M			0x000FC000
#define POCMR_CM_32M			0x000FE000
#define POCMR_CM_16M			0x000FF000
#define POCMR_CM_8M			0x000FF800
#define POCMR_CM_4M			0x000FFC00
#define POCMR_CM_2M			0x000FFE00
#define POCMR_CM_1M			0x000FFF00
#define POCMR_CM_512K			0x000FFF80
#define POCMR_CM_256K			0x000FFFC0
#define POCMR_CM_128K			0x000FFFE0
#define POCMR_CM_64K			0x000FFFF0
#define POCMR_CM_32K			0x000FFFF8
#define POCMR_CM_16K			0x000FFFFC
#define POCMR_CM_8K			0x000FFFFE
#define POCMR_CM_4K			0x000FFFFF

/* PITAR - PCI Inbound Translation Address Register
 */
#define PITAR_TA_MASK			0x000fffff

/* PIBAR - PCI Inbound Base/Extended Address Register
 */
#define PIBAR_MASK			0xffffffff
#define PIEBAR_EBA_MASK			0x000fffff

/* PIWAR - PCI Inbound Windows Attributes Register
 */
#define PIWAR_EN			0x80000000
#define PIWAR_PF			0x20000000
#define PIWAR_RTT_MASK			0x000f0000
#define PIWAR_RTT_NO_SNOOP		0x00040000
#define PIWAR_RTT_SNOOP			0x00050000
#define PIWAR_WTT_MASK			0x0000f000
#define PIWAR_WTT_NO_SNOOP		0x00004000
#define PIWAR_WTT_SNOOP			0x00005000
#define PIWAR_IWS_MASK			0x0000003F
#define PIWAR_IWS_4K			0x0000000B
#define PIWAR_IWS_8K			0x0000000C
#define PIWAR_IWS_16K			0x0000000D
#define PIWAR_IWS_32K			0x0000000E
#define PIWAR_IWS_64K			0x0000000F
#define PIWAR_IWS_128K			0x00000010
#define PIWAR_IWS_256K			0x00000011
#define PIWAR_IWS_512K			0x00000012
#define PIWAR_IWS_1M			0x00000013
#define PIWAR_IWS_2M			0x00000014
#define PIWAR_IWS_4M			0x00000015
#define PIWAR_IWS_8M			0x00000016
#define PIWAR_IWS_16M			0x00000017
#define PIWAR_IWS_32M			0x00000018
#define PIWAR_IWS_64M			0x00000019
#define PIWAR_IWS_128M			0x0000001A
#define PIWAR_IWS_256M			0x0000001B
#define PIWAR_IWS_512M			0x0000001C
#define PIWAR_IWS_1G			0x0000001D
#define PIWAR_IWS_2G			0x0000001E

/* PMCCR1 - PCI Configuration Register 1
 */
#define PMCCR1_POWER_OFF		0x00000020

/* FMR - Flash Mode Register
 */
#define FMR_CWTO		0x0000F000
#define FMR_CWTO_SHIFT		12
#define FMR_BOOT		0x00000800
#define FMR_ECCM		0x00000100
#define FMR_AL			0x00000030
#define FMR_AL_SHIFT		4
#define FMR_OP			0x00000003
#define FMR_OP_SHIFT		0

/* FIR - Flash Instruction Register
 */
#define FIR_OP0			0xF0000000
#define FIR_OP0_SHIFT		28
#define FIR_OP1			0x0F000000
#define FIR_OP1_SHIFT		24
#define FIR_OP2			0x00F00000
#define FIR_OP2_SHIFT		20
#define FIR_OP3			0x000F0000
#define FIR_OP3_SHIFT		16
#define FIR_OP4			0x0000F000
#define FIR_OP4_SHIFT		12
#define FIR_OP5			0x00000F00
#define FIR_OP5_SHIFT		8
#define FIR_OP6			0x000000F0
#define FIR_OP6_SHIFT		4
#define FIR_OP7			0x0000000F
#define FIR_OP7_SHIFT		0
#define FIR_OP_NOP		0x0 /* No operation and end of sequence */
#define FIR_OP_CA		0x1 /* Issue current column address */
#define FIR_OP_PA		0x2 /* Issue current block+page address */
#define FIR_OP_UA		0x3 /* Issue user defined address */
#define FIR_OP_CM0		0x4 /* Issue command from FCR[CMD0] */
#define FIR_OP_CM1		0x5 /* Issue command from FCR[CMD1] */
#define FIR_OP_CM2		0x6 /* Issue command from FCR[CMD2] */
#define FIR_OP_CM3		0x7 /* Issue command from FCR[CMD3] */
#define FIR_OP_WB		0x8 /* Write FBCR bytes from FCM buffer */
#define FIR_OP_WS		0x9 /* Write 1 or 2 bytes from MDR[AS] */
#define FIR_OP_RB		0xA /* Read FBCR bytes to FCM buffer */
#define FIR_OP_RS		0xB /* Read 1 or 2 bytes to MDR[AS] */
#define FIR_OP_CW0		0xC /* Wait then issue FCR[CMD0] */
#define FIR_OP_CW1		0xD /* Wait then issue FCR[CMD1] */
#define FIR_OP_RBW		0xE /* Wait then read FBCR bytes */
#define FIR_OP_RSW		0xF /* Wait then read 1 or 2 bytes */

/* FCR - Flash Command Register
 */
#define FCR_CMD0		0xFF000000
#define FCR_CMD0_SHIFT		24
#define FCR_CMD1		0x00FF0000
#define FCR_CMD1_SHIFT		16
#define FCR_CMD2		0x0000FF00
#define FCR_CMD2_SHIFT		8
#define FCR_CMD3		0x000000FF
#define FCR_CMD3_SHIFT		0

/* FBAR - Flash Block Address Register
 */
#define FBAR_BLK		0x00FFFFFF

/* FPAR - Flash Page Address Register
 */
#define FPAR_SP_PI		0x00007C00
#define FPAR_SP_PI_SHIFT	10
#define FPAR_SP_MS		0x00000200
#define FPAR_SP_CI		0x000001FF
#define FPAR_SP_CI_SHIFT	0
#define FPAR_LP_PI		0x0003F000
#define FPAR_LP_PI_SHIFT	12
#define FPAR_LP_MS		0x00000800
#define FPAR_LP_CI		0x000007FF
#define FPAR_LP_CI_SHIFT	0

/* LTESR - Transfer Error Status Register
 */
#define LTESR_BM		0x80000000
#define LTESR_FCT		0x40000000
#define LTESR_PAR		0x20000000
#define LTESR_WP		0x04000000
#define LTESR_ATMW		0x00800000
#define LTESR_ATMR		0x00400000
#define LTESR_CS		0x00080000
#define LTESR_CC		0x00000001

/* DDRCDR - DDR Control Driver Register
 */
#define DDRCDR_DHC_EN		0x80000000
#define DDRCDR_EN		0x40000000
#define DDRCDR_PZ		0x3C000000
#define DDRCDR_PZ_MAXZ		0x00000000
#define DDRCDR_PZ_HIZ		0x20000000
#define DDRCDR_PZ_NOMZ		0x30000000
#define DDRCDR_PZ_LOZ		0x38000000
#define DDRCDR_PZ_MINZ		0x3C000000
#define DDRCDR_NZ		0x3C000000
#define DDRCDR_NZ_MAXZ		0x00000000
#define DDRCDR_NZ_HIZ		0x02000000
#define DDRCDR_NZ_NOMZ		0x03000000
#define DDRCDR_NZ_LOZ		0x03800000
#define DDRCDR_NZ_MINZ		0x03C00000
#define DDRCDR_ODT		0x00080000
#define DDRCDR_DDR_CFG		0x00040000
#define DDRCDR_M_ODR		0x00000002
#define DDRCDR_Q_DRN		0x00000001

/* PCIE Bridge Register
 */
#define PEX_CSB_CTRL_OBPIOE	0x00000001
#define PEX_CSB_CTRL_IBPIOE	0x00000002
#define PEX_CSB_CTRL_WDMAE	0x00000004
#define PEX_CSB_CTRL_RDMAE	0x00000008

#define PEX_CSB_OBCTRL_PIOE	0x00000001
#define PEX_CSB_OBCTRL_MEMWE	0x00000002
#define PEX_CSB_OBCTRL_IOWE	0x00000004
#define PEX_CSB_OBCTRL_CFGWE	0x00000008

#define PEX_CSB_IBCTRL_PIOE	0x00000001

#define PEX_OWAR_EN		0x00000001
#define PEX_OWAR_TYPE_CFG	0x00000000
#define PEX_OWAR_TYPE_IO	0x00000002
#define PEX_OWAR_TYPE_MEM	0x00000004
#define PEX_OWAR_RLXO		0x00000008
#define PEX_OWAR_NANP		0x00000010
#define PEX_OWAR_SIZE		0xFFFFF000

#define PEX_IWAR_EN		0x00000001
#define PEX_IWAR_TYPE_INT	0x00000000
#define PEX_IWAR_TYPE_PF	0x00000004
#define PEX_IWAR_TYPE_NO_PF	0x00000006
#define PEX_IWAR_NSOV		0x00000008
#define PEX_IWAR_NSNP		0x00000010
#define PEX_IWAR_SIZE		0xFFFFF000
#define PEX_IWAR_SIZE_1M	0x000FF000
#define PEX_IWAR_SIZE_2M	0x001FF000
#define PEX_IWAR_SIZE_4M	0x003FF000
#define PEX_IWAR_SIZE_8M	0x007FF000
#define PEX_IWAR_SIZE_16M	0x00FFF000
#define PEX_IWAR_SIZE_32M	0x01FFF000
#define PEX_IWAR_SIZE_64M	0x03FFF000
#define PEX_IWAR_SIZE_128M	0x07FFF000
#define PEX_IWAR_SIZE_256M	0x0FFFF000

#define PEX_LTSSM_STAT		0x404
#define PEX_GCLK_RATIO		0x440

#ifndef __ASSEMBLY__
struct pci_region;
void mpc83xx_pci_init(int num_buses, struct pci_region **reg, int warmboot);
#endif

#endif	/* __MPC83XX_H__ */
