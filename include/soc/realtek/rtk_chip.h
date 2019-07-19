/*
 * rtk_chip.h
 *
 * Copyright (c) 2017 Realtek Semiconductor Corp.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 */

#ifndef _RTK_CHIP_H_INCLUDED_
#define _RTK_CHIP_H_INCLUDED_

enum rtd_chip_id {
	CHIP_ID_RTD129X = 0x1290,
	CHIP_ID_RTD1294 = 0x1294,
	CHIP_ID_RTD1295 = 0x1295,
	CHIP_ID_RTD1296 = 0x1296,
};

int get_rtd_chip_id(void);

enum rtd_chip_revision {
	RTD_CHIP_A00 = 0xA00,
	RTD_CHIP_A01 = 0xA01,
	RTD_CHIP_B00 = 0xB00,
	RTD_CHIP_B01 = 0xB01,
};

int get_rtd_chip_revision(void);

#endif //_RTK_CHIP_H_INCLUDED_
