//
// Do NOT modify or remove this copyright and license
//
// Copyright (c) 2012 - 2018 Seagate Technology LLC and/or its Affiliates, All Rights Reserved
//
// This software is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//
// ******************************************************************************************
// 
// \file cam_helper.h
// \brief Defines the constants structures specific to Free BSD. 

#ifndef CAM_HELPER_H
#define CAM_HELPER_H

#include "scsi_helper.h"
#include "sat_helper.h"
#include "common_public.h"
#if !defined(DISABLE_NVME_PASSTHROUGH)
#include "nvme_helper.h"
#endif

#if defined (__cplusplus)
extern "C"
{
#endif

// \file cam_helper.h
// \brief Defines the constants structures and function headers to help parse scsi/ata devices
// using FreeBSD Common Access Method (CAM) library.

    #include <sys/cdefs.h>
    #include <sys/ioctl.h>
    #include <inttypes.h>
    #include <sys/types.h>
    #include <sys/endian.h>
    #include <sys/sbuf.h>

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <inttypes.h>
    #include <limits.h>
    #include <fcntl.h>
    #include <ctype.h>
    #include <err.h>
    #include <libutil.h>

    #include <cam/cam.h>
    #include <cam/cam_debug.h>
    #include <cam/cam_ccb.h>
    #include <cam/scsi/scsi_all.h>
    #include <cam/scsi/scsi_da.h>
    #include <cam/scsi/scsi_pass.h>
    #include <cam/scsi/scsi_message.h>
    #include <cam/scsi/smp_all.h>
    #include <cam/ata/ata_all.h>
    #include <camlib.h>

    //-----------------------------------------------------------------------------
    //
    //  send_Scsi_Cam_IO()
    //
    //! \brief   Description:  Function to send a SCSI CAM ioctl
    //
    //  Entry:
    //!   \param scsiIoCtx = pointer to the ScsiIoCtx struct describing the command to send to a device
    //
    //  Exit:
    //!   \return SUCCESS = good, !SUCCESS something went wrong see error codes
    //
    //-----------------------------------------------------------------------------
    int send_Scsi_Cam_IO( ScsiIoCtx *scsiIoCtx );

    //-----------------------------------------------------------------------------
    //
    //  send_Ata_Cam_IO()
    //
    //! \brief   Description:  Function to send a ATA CAM ioctl
    //
    //  Entry:
    //!   \param scsiIoCtx = pointer to the ScsiIoCtx struct describing the command to send to a device
    //
    //  Exit:
    //!   \return SUCCESS = good, !SUCCESS something went wrong see error codes
    //
    //-----------------------------------------------------------------------------
    int send_Ata_Cam_IO( ScsiIoCtx *scsiIoCtx );

    //-----------------------------------------------------------------------------
    //
    //  send_IO()
    //
    //! \brief   Description:  Function to send IO to a device
    //
    //  Entry:
    //!   \param scsiIoCtx = pointer to the ScsiIoCtx struct describing the command to send to a device
    //
    //  Exit:
    //!   \return SUCCESS = good, !SUCCESS something went wrong see error codes
    //
    //-----------------------------------------------------------------------------
    int send_IO( ScsiIoCtx *scsiIoCtx );

#if !defined(DISABLE_NVME_PASSTHROUGH)
    //-----------------------------------------------------------------------------
    //
    //  pci_Read_Bar_Reg()
    //
    //! \brief   Description:  Function to Read PCI Bar register
    //
    //  Entry:
    //!   \param[in]  device = pointer to device context!   
    //!   \param[out] pData =  pointer to data that need to be filled.
    //!                        this needs to be at least the size of a page
    //!                        e.g. getPageSize() in Linux
    //!   \param[out] dataSize =  size of the data
    //! 
    //!
    //  Exit:
    //!   \return SUCCESS = pass, !SUCCESS = something when wrong
    //
    //-----------------------------------------------------------------------------
    int pci_Read_Bar_Reg(tDevice * device, uint8_t * pData, uint32_t dataSize);

    //-----------------------------------------------------------------------------
    //
    //  send_NVMe_IO()
    //
    //! \brief   Description:  Function to send a NVMe command to a device
    //
    //  Entry:
    //!   \param[in] scsiIoCtx = pointer to IO Context!   
    //!
    //  Exit:
    //!   \return SUCCESS = pass, !SUCCESS = something when wrong
    //
    //-----------------------------------------------------------------------------
    int send_NVMe_IO(nvmeCmdCtx *nvmeIoCtx);
#endif

    #if defined (__cplusplus)
}
    #endif

#endif
