// SPDX-License-Identifier: GPL-2.0-only
/* Copyright (C) 2020 Felix Fietkau <nbd@nbd.name> */

#ifndef __MTK_WED_REGS_H
#define __MTK_WED_REGS_H

#define MTK_WDMA_DESC_CTRL_LEN1			GENMASK(14, 0)
#define MTK_WDMA_DESC_CTRL_LAST_SEG1		BIT(15)
#define MTK_WDMA_DESC_CTRL_BURST		BIT(16)
#define MTK_WDMA_DESC_CTRL_LEN0			GENMASK(29, 16)
#define MTK_WDMA_DESC_CTRL_LAST_SEG0		BIT(30)
#define MTK_WDMA_DESC_CTRL_DMA_DONE		BIT(31)

struct mtk_wdma_desc {
	__le32 buf0;
	__le32 ctrl;
	__le32 buf1;
	__le32 info;
} __packed __aligned(4);

#define MTK_WED_RESET					0x008
#define MTK_WED_RESET_TX_BM				BIT(0)
#define MTK_WED_RESET_TX_FREE_AGENT			BIT(4)
#define MTK_WED_RESET_WPDMA_TX_DRV			BIT(8)
#define MTK_WED_RESET_WPDMA_RX_DRV			BIT(9)
#define MTK_WED_RESET_WPDMA_INT_AGENT			BIT(11)
#define MTK_WED_RESET_WED_TX_DMA			BIT(12)
#define MTK_WED_RESET_WDMA_RX_DRV			BIT(17)
#define MTK_WED_RESET_WDMA_INT_AGENT			BIT(19)
#define MTK_WED_RESET_WED				BIT(31)

#define MTK_WED_CTRL					0x00c
#define MTK_WED_CTRL_WPDMA_INT_AGENT_EN			BIT(0)
#define MTK_WED_CTRL_WPDMA_INT_AGENT_BUSY		BIT(1)
#define MTK_WED_CTRL_WDMA_INT_AGENT_EN			BIT(2)
#define MTK_WED_CTRL_WDMA_INT_AGENT_BUSY		BIT(3)
#define MTK_WED_CTRL_WED_TX_BM_EN			BIT(8)
#define MTK_WED_CTRL_WED_TX_BM_BUSY			BIT(9)
#define MTK_WED_CTRL_WED_TX_FREE_AGENT_EN		BIT(10)
#define MTK_WED_CTRL_WED_TX_FREE_AGENT_BUSY		BIT(11)
#define MTK_WED_CTRL_RESERVE_EN				BIT(12)
#define MTK_WED_CTRL_RESERVE_BUSY			BIT(13)
#define MTK_WED_CTRL_FINAL_DIDX_READ			BIT(24)
#define MTK_WED_CTRL_MIB_READ_CLEAR			BIT(28)

#define MTK_WED_EXT_INT_STATUS				0x020
#define MTK_WED_EXT_INT_STATUS_TF_LEN_ERR		BIT(0)
#define MTK_WED_EXT_INT_STATUS_TKID_WO_PYLD		BIT(1)
#define MTK_WED_EXT_INT_STATUS_TKID_TITO_INVALID	BIT(4)
#define MTK_WED_EXT_INT_STATUS_TX_FBUF_LO_TH		BIT(8)
#define MTK_WED_EXT_INT_STATUS_TX_FBUF_HI_TH		BIT(9)
#define MTK_WED_EXT_INT_STATUS_RX_FBUF_LO_TH		BIT(12)
#define MTK_WED_EXT_INT_STATUS_RX_FBUF_HI_TH		BIT(13)
#define MTK_WED_EXT_INT_STATUS_RX_DRV_R_RESP_ERR	BIT(16)
#define MTK_WED_EXT_INT_STATUS_RX_DRV_W_RESP_ERR	BIT(17)
#define MTK_WED_EXT_INT_STATUS_RX_DRV_COHERENT		BIT(18)
#define MTK_WED_EXT_INT_STATUS_RX_DRV_INIT_WDMA_EN	BIT(19)
#define MTK_WED_EXT_INT_STATUS_RX_DRV_BM_DMAD_COHERENT	BIT(20)
#define MTK_WED_EXT_INT_STATUS_TX_DRV_R_RESP_ERR	BIT(21)
#define MTK_WED_EXT_INT_STATUS_TX_DRV_W_RESP_ERR	BIT(22)
#define MTK_WED_EXT_INT_STATUS_RX_DRV_DMA_RECYCLE	BIT(24)
#define MTK_WED_EXT_INT_STATUS_ERROR_MASK		(MTK_WED_EXT_INT_STATUS_TF_LEN_ERR | \
							 MTK_WED_EXT_INT_STATUS_TKID_WO_PYLD | \
							 MTK_WED_EXT_INT_STATUS_TKID_TITO_INVALID | \
							 MTK_WED_EXT_INT_STATUS_RX_DRV_R_RESP_ERR | \
							 MTK_WED_EXT_INT_STATUS_RX_DRV_W_RESP_ERR | \
							 MTK_WED_EXT_INT_STATUS_RX_DRV_INIT_WDMA_EN | \
							 MTK_WED_EXT_INT_STATUS_TX_DRV_R_RESP_ERR | \
							 MTK_WED_EXT_INT_STATUS_TX_DRV_W_RESP_ERR)

#define MTK_WED_EXT_INT_MASK				0x028

#define MTK_WED_STATUS					0x060
#define MTK_WED_STATUS_TX				GENMASK(15, 8)

#define MTK_WED_TX_BM_CTRL				0x080
#define MTK_WED_TX_BM_CTRL_VLD_GRP_NUM			GENMASK(6, 0)
#define MTK_WED_TX_BM_CTRL_RSV_GRP_NUM			GENMASK(22, 16)
#define MTK_WED_TX_BM_CTRL_PAUSE			BIT(28)

#define MTK_WED_TX_BM_BASE				0x084

#define MTK_WED_TX_BM_TKID				0x088
#define MTK_WED_TX_BM_TKID_START			GENMASK(15, 0)
#define MTK_WED_TX_BM_TKID_END				GENMASK(31, 16)

#define MTK_WED_TX_BM_BUF_LEN				0x08c

#define MTK_WED_TX_BM_INTF				0x09c
#define MTK_WED_TX_BM_INTF_TKID				GENMASK(15, 0)
#define MTK_WED_TX_BM_INTF_TKFIFO_FDEP			GENMASK(23, 16)
#define MTK_WED_TX_BM_INTF_TKID_VALID			BIT(28)
#define MTK_WED_TX_BM_INTF_TKID_READ			BIT(29)

#define MTK_WED_TX_BM_DYN_THR				0x0a0
#define MTK_WED_TX_BM_DYN_THR_LO			GENMASK(6, 0)
#define MTK_WED_TX_BM_DYN_THR_HI			GENMASK(22, 16)

#define MTK_WED_INT_STATUS				0x200
#define MTK_WED_INT_MASK				0x204

#define MTK_WED_GLO_CFG					0x208
#define MTK_WED_GLO_CFG_TX_DMA_EN			BIT(0)
#define MTK_WED_GLO_CFG_TX_DMA_BUSY			BIT(1)
#define MTK_WED_GLO_CFG_RX_DMA_EN			BIT(2)
#define MTK_WED_GLO_CFG_RX_DMA_BUSY			BIT(3)
#define MTK_WED_GLO_CFG_RX_BT_SIZE			GENMASK(5, 4)
#define MTK_WED_GLO_CFG_TX_WB_DDONE			BIT(6)
#define MTK_WED_GLO_CFG_BIG_ENDIAN			BIT(7)
#define MTK_WED_GLO_CFG_DIS_BT_SIZE_ALIGN		BIT(8)
#define MTK_WED_GLO_CFG_TX_BT_SIZE_LO			BIT(9)
#define MTK_WED_GLO_CFG_MULTI_DMA_EN			GENMASK(11, 10)
#define MTK_WED_GLO_CFG_FIFO_LITTLE_ENDIAN		BIT(12)
#define MTK_WED_GLO_CFG_MI_DEPTH_RD			GENMASK(21, 13)
#define MTK_WED_GLO_CFG_TX_BT_SIZE_HI			GENMASK(23, 22)
#define MTK_WED_GLO_CFG_SW_RESET			BIT(24)
#define MTK_WED_GLO_CFG_FIRST_TOKEN_ONLY		BIT(26)
#define MTK_WED_GLO_CFG_OMIT_RX_INFO			BIT(27)
#define MTK_WED_GLO_CFG_OMIT_TX_INFO			BIT(28)
#define MTK_WED_GLO_CFG_BYTE_SWAP			BIT(29)
#define MTK_WED_GLO_CFG_RX_2B_OFFSET			BIT(31)

#define MTK_WED_RESET_IDX				0x20c
#define MTK_WED_RESET_IDX_TX				GENMASK(3, 0)
#define MTK_WED_RESET_IDX_RX				GENMASK(17, 16)

#define MTK_WED_TX_MIB(_n)				(0x2a0 + (_n) * 4)

#define MTK_WED_RING_TX(_n)				(0x300 + (_n) * 0x10)

#define MTK_WED_RING_RX(_n)				(0x400 + (_n) * 0x10)

#define MTK_WED_WPDMA_INT_TRIGGER			0x504
#define MTK_WED_WPDMA_INT_TRIGGER_RX_DONE		BIT(1)
#define MTK_WED_WPDMA_INT_TRIGGER_TX_DONE		GENMASK(5, 4)

#define MTK_WED_WPDMA_GLO_CFG				0x508
#define MTK_WED_WPDMA_GLO_CFG_TX_DRV_EN			BIT(0)
#define MTK_WED_WPDMA_GLO_CFG_TX_DRV_BUSY		BIT(1)
#define MTK_WED_WPDMA_GLO_CFG_RX_DRV_EN			BIT(2)
#define MTK_WED_WPDMA_GLO_CFG_RX_DRV_BUSY		BIT(3)
#define MTK_WED_WPDMA_GLO_CFG_RX_BT_SIZE		GENMASK(5, 4)
#define MTK_WED_WPDMA_GLO_CFG_TX_WB_DDONE		BIT(6)
#define MTK_WED_WPDMA_GLO_CFG_BIG_ENDIAN		BIT(7)
#define MTK_WED_WPDMA_GLO_CFG_DIS_BT_SIZE_ALIGN		BIT(8)
#define MTK_WED_WPDMA_GLO_CFG_TX_BT_SIZE_LO		BIT(9)
#define MTK_WED_WPDMA_GLO_CFG_MULTI_DMA_EN		GENMASK(11, 10)
#define MTK_WED_WPDMA_GLO_CFG_FIFO_LITTLE_ENDIAN	BIT(12)
#define MTK_WED_WPDMA_GLO_CFG_MI_DEPTH_RD		GENMASK(21, 13)
#define MTK_WED_WPDMA_GLO_CFG_TX_BT_SIZE_HI		GENMASK(23, 22)
#define MTK_WED_WPDMA_GLO_CFG_SW_RESET			BIT(24)
#define MTK_WED_WPDMA_GLO_CFG_FIRST_TOKEN_ONLY		BIT(26)
#define MTK_WED_WPDMA_GLO_CFG_OMIT_RX_INFO		BIT(27)
#define MTK_WED_WPDMA_GLO_CFG_OMIT_TX_INFO		BIT(28)
#define MTK_WED_WPDMA_GLO_CFG_BYTE_SWAP			BIT(29)
#define MTK_WED_WPDMA_GLO_CFG_RX_2B_OFFSET		BIT(31)

#define MTK_WED_WPDMA_RESET_IDX				0x50c
#define MTK_WED_WPDMA_RESET_IDX_TX			GENMASK(3, 0)
#define MTK_WED_WPDMA_RESET_IDX_RX			GENMASK(17, 16)

#define MTK_WED_WPDMA_INT_CTRL				0x520
#define MTK_WED_WPDMA_INT_CTRL_SUBRT_ADV		BIT(21)

#define MTK_WED_WPDMA_INT_MASK				0x524

#define MTK_WED_PCIE_CFG_BASE				0x560

#define MTK_WED_PCIE_INT_TRIGGER			0x570
#define MTK_WED_PCIE_INT_TRIGGER_STATUS			BIT(16)

#define MTK_WED_WPDMA_CFG_BASE				0x580

#define MTK_WED_WPDMA_TX_MIB(_n)			(0x5a0 + (_n) * 4)
#define MTK_WED_WPDMA_TX_COHERENT_MIB(_n)		(0x5d0 + (_n) * 4)

#define MTK_WED_WPDMA_RING_TX(_n)			(0x600 + (_n) * 0x10)
#define MTK_WED_WPDMA_RING_RX(_n)			(0x700 + (_n) * 0x10)
#define MTK_WED_WDMA_RING_RX(_n)			(0x900 + (_n) * 0x10)
#define MTK_WED_WDMA_RX_THRES(_n)			(0x940 + (_n) * 0x4)

#define MTK_WED_WDMA_GLO_CFG				0xa04
#define MTK_WED_WDMA_GLO_CFG_TX_DRV_EN			BIT(0)
#define MTK_WED_WDMA_GLO_CFG_RX_DRV_EN			BIT(2)
#define MTK_WED_WDMA_GLO_CFG_RX_DRV_BUSY		BIT(3)
#define MTK_WED_WDMA_GLO_CFG_BT_SIZE			GENMASK(5, 4)
#define MTK_WED_WDMA_GLO_CFG_TX_WB_DDONE		BIT(6)
#define MTK_WED_WDMA_GLO_CFG_RX_DIS_FSM_AUTO_IDLE	BIT(13)
#define MTK_WED_WDMA_GLO_CFG_WCOMPLETE_SEL		BIT(16)
#define MTK_WED_WDMA_GLO_CFG_INIT_PHASE_RXDMA_BYPASS	BIT(17)
#define MTK_WED_WDMA_GLO_CFG_INIT_PHASE_BYPASS		BIT(18)
#define MTK_WED_WDMA_GLO_CFG_FSM_RETURN_IDLE		BIT(19)
#define MTK_WED_WDMA_GLO_CFG_WAIT_COHERENT		BIT(20)
#define MTK_WED_WDMA_GLO_CFG_AXI_W_AFTER_AW		BIT(21)
#define MTK_WED_WDMA_GLO_CFG_IDLE_DMAD_SUPPLY_SINGLE_W	BIT(22)
#define MTK_WED_WDMA_GLO_CFG_IDLE_DMAD_SUPPLY		BIT(23)
#define MTK_WED_WDMA_GLO_CFG_DYNAMIC_SKIP_DMAD_PREP	BIT(24)
#define MTK_WED_WDMA_GLO_CFG_DYNAMIC_DMAD_RECYCLE	BIT(25)
#define MTK_WED_WDMA_GLO_CFG_RST_INIT_COMPLETE		BIT(26)
#define MTK_WED_WDMA_GLO_CFG_RXDRV_CLKGATE_BYPASS	BIT(30)

#define MTK_WED_WDMA_RESET_IDX				0xa08
#define MTK_WED_WDMA_RESET_IDX_RX			GENMASK(17, 16)
#define MTK_WED_WDMA_RESET_IDX_DRV			GENMASK(25, 24)

#define MTK_WED_WDMA_INT_TRIGGER			0xa28
#define MTK_WED_WDMA_INT_TRIGGER_RX_DONE		GENMASK(17, 16)

#define MTK_WED_WDMA_INT_CTRL				0xa2c
#define MTK_WED_WDMA_INT_CTRL_POLL_SRC_SEL		GENMASK(17, 16)

#define MTK_WED_WDMA_OFFSET0				0xaa4
#define MTK_WED_WDMA_OFFSET1				0xaa8

#define MTK_WED_WDMA_RX_MIB(_n)				(0xae0 + (_n) * 4)
#define MTK_WED_WDMA_RX_RECYCLE_MIB(_n)			(0xae8 + (_n) * 4)
#define MTK_WED_WDMA_RX_PROCESSED_MIB(_n)		(0xaf0 + (_n) * 4)

#define MTK_WED_RING_OFS_BASE				0x00
#define MTK_WED_RING_OFS_COUNT				0x04
#define MTK_WED_RING_OFS_CPU_IDX			0x08
#define MTK_WED_RING_OFS_DMA_IDX			0x0c

#define MTK_WDMA_RING_RX(_n)				(0x100 + (_n) * 0x10)

#define MTK_WDMA_GLO_CFG				0x204
#define MTK_WDMA_GLO_CFG_RX_INFO_PRERES			GENMASK(28, 26)

#define MTK_WDMA_RESET_IDX				0x208
#define MTK_WDMA_RESET_IDX_TX				GENMASK(3, 0)
#define MTK_WDMA_RESET_IDX_RX				GENMASK(17, 16)

#define MTK_WDMA_INT_MASK				0x228
#define MTK_WDMA_INT_MASK_TX_DONE			GENMASK(3, 0)
#define MTK_WDMA_INT_MASK_RX_DONE			GENMASK(17, 16)
#define MTK_WDMA_INT_MASK_TX_DELAY			BIT(28)
#define MTK_WDMA_INT_MASK_TX_COHERENT			BIT(29)
#define MTK_WDMA_INT_MASK_RX_DELAY			BIT(30)
#define MTK_WDMA_INT_MASK_RX_COHERENT			BIT(31)

#define MTK_WDMA_INT_GRP1				0x250
#define MTK_WDMA_INT_GRP2				0x254

#define MTK_PCIE_MIRROR_MAP(n)				((n) ? 0x4 : 0x0)
#define MTK_PCIE_MIRROR_MAP_EN				BIT(0)
#define MTK_PCIE_MIRROR_MAP_WED_ID			BIT(1)

/* DMA channel mapping */
#define HIFSYS_DMA_AG_MAP				0x008

#endif
