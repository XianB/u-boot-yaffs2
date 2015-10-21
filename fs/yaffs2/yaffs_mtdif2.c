/*
 * YAFFS: Yet Another Flash File System. A NAND-flash specific file system.
 *
 * Copyright (C) 2002-2007 Aleph One Ltd.
 *   for Toby Churchill Ltd and Brightstar Engineering
 *
 * Created by Charles Manning <charles@aleph1.co.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

/* mtd interface for YAFFS2 */

/* XXX U-BOOT XXX */
#include <common.h>
#include "asm/errno.h"

const char *yaffs_mtdif2_c_version =
    "$Id: yaffs_mtdif2.c,v 1.17 2007/02/14 01:09:06 wookey Exp $";

#include "yportenv.h"


#include "yaffs_mtdif2.h"

#include "linux/mtd/mtd.h"
#include "linux/types.h"
#include "linux/time.h"

#include "yaffs_packedtags2.h"
#include "yaffs_trace.h"

int nandmtd2_write_chunk_tags(struct yaffs_dev *dev, int chunkInNAND, const u8 *data, const struct yaffs_ext_tags *tags)
{
	struct mtd_info *mtd = (struct mtd_info *)(dev->driver_context);
//#if (LINUX_VERSION_CODE > KERNEL_VERSION(2,6,17))
#if 0
	struct mtd_oob_ops ops;
#else
	size_t dummy;
#endif
	int retval = 0;

	loff_t addr = ((loff_t) chunkInNAND) * dev->data_bytes_per_chunk;

	//yaffs_PackedTags2 pt;
	struct yaffs_packed_tags2 pt;

	T(YAFFS_TRACE_MTD,
	  (TSTR
	   ("nandmtd2_WriteChunkWithTagsToNAND chunk %d data %p tags %p"
	    TENDSTR), chunkInNAND, data, tags));

//#if (LINUX_VERSION_CODE > KERNEL_VERSION(2,6,17))
#if 0
	if (tags)
		yaffs_PackTags2(&pt, tags);
	else
		BUG(); /* both tags and data should always be present */

	if (data) {
		ops.mode = MTD_OOB_AUTO;
		ops.ooblen = sizeof(pt);
		ops.len = dev->data_bytes_per_chunk;
		ops.ooboffs = 0;
		ops.datbuf = (__u8 *)data;
		ops.oobbuf = (void *)&pt;
		retval = mtd->write_oob(mtd, addr, &ops);
	} else
		BUG(); /* both tags and data should always be present */
#else

	if (tags) {
		yaffs_pack_tags2(&pt, tags, 1);
	}

	if (data && tags) {
		if (dev->param.use_nand_ecc)
			retval =
			    mtd->write_ecc(mtd, addr, dev->data_bytes_per_chunk,
					   &dummy, data, (__u8 *) & pt, NULL);
		else
			retval =
			    mtd->write_ecc(mtd, addr, dev->data_bytes_per_chunk,
					   &dummy, data, (__u8 *) & pt, NULL);
	} else {
		if (data)
			retval =
			    mtd->write(mtd, addr, dev->data_bytes_per_chunk, &dummy,
				       data);
		if (tags)
			retval =
			    mtd->write_oob(mtd, addr, mtd->oobsize, &dummy,
					   (__u8 *) & pt);

	}
#endif

	if (retval == 0)
		return YAFFS_OK;
	else
		return YAFFS_FAIL;
}

int nandmtd2_read_chunk_tags(struct yaffs_dev *dev, int chunkInNAND, u8 *data, struct yaffs_ext_tags *tags)
{
	struct mtd_info *mtd = (struct mtd_info *)(dev->driver_context);
//#if (LINUX_VERSION_CODE > KERNEL_VERSION(2,6,17))
#if 0
	struct mtd_oob_ops ops;
#endif
	size_t dummy;
	int retval = 0;

	loff_t addr = ((loff_t) chunkInNAND) * dev->data_bytes_per_chunk;

	//yaffs_PackedTags2 pt;
	struct yaffs_packed_tags2 pt;

	T(YAFFS_TRACE_MTD,
	  (TSTR
	   ("nandmtd2_ReadChunkWithTagsFromNAND chunk %d data %p tags %p"
	    TENDSTR), chunkInNAND, data, tags));

//#if (LINUX_VERSION_CODE > KERNEL_VERSION(2,6,17))
#if 0
	if (data && !tags)
		retval = mtd->read(mtd, addr, dev->data_bytes_per_chunk,
				&dummy, data);
	else if (tags) {
		ops.mode = MTD_OOB_AUTO;
		ops.ooblen = sizeof(pt);
		ops.len = data ? dev->data_bytes_per_chunk : sizeof(pt);
		ops.ooboffs = 0;
		ops.datbuf = data;
		ops.oobbuf = dev->spareBuffer;
		retval = mtd->read_oob(mtd, addr, &ops);
	}
#else
	if (data && tags) {
		if (dev->param.use_nand_ecc) {
			retval =
			    mtd->read_ecc(mtd, addr, dev->data_bytes_per_chunk,
					  &dummy, data, dev->spareBuffer,
					  NULL);
		} else {
			retval =
			    mtd->read_ecc(mtd, addr, dev->data_bytes_per_chunk,
					  &dummy, data, dev->spareBuffer,
					  NULL);
		}
	} else {
		if (data)
			retval =
			    mtd->read(mtd, addr, dev->data_bytes_per_chunk, &dummy,
				      data);
		if (tags)
			retval =
			    mtd->read_oob(mtd, addr, mtd->oobsize, &dummy,
					  dev->spareBuffer);
	}
#endif

	memcpy(&pt, dev->spareBuffer, sizeof(pt));

	if (tags)
		yaffs_unpack_tags2(tags, &pt, 1);

	if(tags && retval == -EBADMSG && tags->ecc_result == YAFFS_ECC_RESULT_NO_ERROR)
		tags->ecc_result = YAFFS_ECC_RESULT_UNFIXED;

	if (retval == 0)
		return YAFFS_OK;
	else
		return YAFFS_FAIL;
}


int nandmtd2_MarkNANDBlockBad(struct yaffs_dev *dev, int blockNo)
{
	struct mtd_info *mtd = (struct mtd_info *)(dev->driver_context);
	int retval;
	T(YAFFS_TRACE_MTD,
	  (TSTR("nandmtd2_MarkNANDBlockBad %d" TENDSTR), blockNo));

	retval =
	    mtd->block_markbad(mtd,
			       blockNo * dev->param.chunks_per_block *
			       dev->data_bytes_per_chunk);

	if (retval == 0)
		return YAFFS_OK;
	else
		return YAFFS_FAIL;

}


int nandmtd2_QueryNANDBlock(struct yaffs_dev *dev, int blockNo, enum yaffs_block_state *state, u32 *sequenceNumber)
{
	struct mtd_info *mtd = (struct mtd_info *)(dev->driver_context);
	int retval;

	T(YAFFS_TRACE_MTD,
	  (TSTR("nandmtd2_QueryNANDBlock %d" TENDSTR), blockNo));
	retval =
	    mtd->block_isbad(mtd,
			     blockNo * dev->param.chunks_per_block *
			     dev->data_bytes_per_chunk);

	if (retval) {
		T(YAFFS_TRACE_MTD, (TSTR("block is bad" TENDSTR)));

		*state = YAFFS_BLOCK_STATE_DEAD;
		*sequenceNumber = 0;
	} else {
//		yaffs_ExtendedTags t;
		struct yaffs_ext_tags t;
		nandmtd2_ReadChunkWithTagsFromNAND(dev,
						   blockNo *
						   dev->param.chunks_per_block, NULL,
						   &t);

		if (t.chunk_used) {
			*sequenceNumber = t.seq_number;
			*state = YAFFS_BLOCK_STATE_NEEDS_SCAN;
		} else {
			*sequenceNumber = 0;
			*state = YAFFS_BLOCK_STATE_EMPTY;
		}
	}
	T(YAFFS_TRACE_MTD,
	  (TSTR("block is bad seq %d state %d" TENDSTR), *sequenceNumber,
	   *state));

	if (retval == 0)
		return YAFFS_OK;
	else
		return YAFFS_FAIL;
}
