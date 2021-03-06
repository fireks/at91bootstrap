/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support
 * ----------------------------------------------------------------------------
 * Copyright (c) 2013, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef __PMECC_H__
#define __PMECC_H__

#include "nand.h"

#define TT_MAX			25

/* The PMECC descripter structure */
struct _PMECC_paramDesc_struct {
	unsigned int pageSize;
	unsigned int spareSize;
	unsigned int sectorSize;
	unsigned int errBitNbrCapability;
	unsigned int eccSizeByte;
	unsigned int eccStartAddress;
	unsigned int eccEndAddress;

	unsigned int nandWR;
	unsigned int spareEna;
	unsigned int modeAuto;
	unsigned int clkCtrl;
	unsigned int interrupt;

	int tt;
	int mm;
	int nn;

	short *alpha_to;
	short *index_of;

	short partialSyn[100];
	short si[100];

	/* sigma table */
	short smu[TT_MAX + 2][2 * TT_MAX + 1];
	/* polynom order */
	short lmu[TT_MAX + 1];

} PMECC_paramDesc;

extern int get_pmecc_bytes();
extern int init_pmecc(struct nand_info *nand);
extern void pmecc_enable(void);
extern void pmecc_start_data_phase(void);
extern int pmecc_process(struct nand_info *nand, unsigned char *buffer);

#endif
