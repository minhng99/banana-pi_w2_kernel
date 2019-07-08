/*
 * rtk_ipc_shm.h
 *
 * Copyright (c) 2017 Realtek Semiconductor Corp.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 */

#ifndef __ASM_ARCH_RTK_IPC_SHM_H
#define __ASM_ARCH_RTK_IPC_SHM_H

extern volatile void __iomem *rpc_common_base;
#define IPC_SHM_VIRT (rpc_common_base + 0x000000C4)

struct rtk_ipc_shm {
	volatile uint32_t sys_assign_serial;
	volatile uint32_t pov_boot_vd_std_ptr;
	volatile uint32_t pov_boot_av_info;
	volatile uint32_t audio_rpc_flag;
	volatile uint32_t suspend_mask;
	volatile uint32_t suspend_flag;
	volatile uint32_t vo_vsync_flag;
	volatile uint32_t audio_fw_entry_pt;
	volatile uint32_t power_saving_ptr;
	volatile unsigned char printk_buffer[24];
	volatile uint32_t ir_extended_tbl_pt;
	volatile uint32_t vo_int_sync;
	volatile uint32_t bt_wakeup_flag;
	volatile uint32_t ir_scancode_mask;
	volatile uint32_t ir_wakeup_scancode;
	volatile uint32_t suspend_wakeup_flag;
	volatile uint32_t acpu_resume_state;
	volatile uint32_t gpio_wakeup_enable;
	volatile uint32_t gpio_wakeup_activity;
	volatile uint32_t gpio_output_change_enable;
	volatile uint32_t gpio_output_change_activity;
	volatile uint32_t audio_reciprocal_timer_sec;
	volatile uint32_t u_boot_version_magic;
	volatile uint32_t u_boot_version_info;
	volatile uint32_t suspend_watchdog;
	volatile uint32_t xen_domu_boot_st;
	volatile uint32_t gpio_wakeup_enable2;
	volatile uint32_t gpio_wakeup_activity2;
	volatile uint32_t gpio_output_change_enable2;
	volatile uint32_t gpio_output_change_activity2;
};

#endif /* End of  __ASM_ARCH_RTK_IPC_SHM_H */
