CFLAGS_scm.o :=$(call as-instr,.arch_extension sec,-DREQUIRES_SEC=1)

obj-y += io.o dma.o memory.o
obj-y += clock.o clock-voter.o clock-dummy.o clock-generic.o
obj-y += modem_notifier.o acpuclock.o

obj-$(CONFIG_USE_OF) += board-dt.o

obj-$(CONFIG_DEBUG_FS) += nohlt.o clock-debug.o

obj-$(CONFIG_MSM_CORTEX_A7) += clock-a7.o

obj-$(CONFIG_DEBUG_FS) += perf_debug.o

obj-$(CONFIG_SMP) += headsmp.o platsmp.o

obj-$(CONFIG_HOTPLUG_CPU) += hotplug.o

obj-$(CONFIG_CPU_V7) += idle-v7.o

obj-$(CONFIG_MSM_JTAG_MM) +=  jtag-fuse.o jtag-mm.o

quiet_cmd_mkrpcsym = MKCAP   $@
      cmd_mkrpcsym = $(PERL) $(srctree)/$(src)/mkrpcsym.pl $< $@

target += smd_rpc_sym.c
$(obj)/smd_rpc_sym.c: $(src)/smd_rpc_sym $(src)/mkrpcsym.pl
	$(call if_changed,mkrpcsym)

obj-$(CONFIG_MSM_SMD) += smd.o remote_spinlock.o smd_private.o smem.o smd_init_dt.o smd_init_plat.o
obj-$(CONFIG_MSM_SMP2P) += smp2p.o smp2p_gpio.o smp2p_loopback.o
obj-$(CONFIG_MSM_SCM) += scm.o scm-boot.o scm-mpu.o
obj-$(CONFIG_MSM_XPU_ERR_FATAL) += scm-xpu.o
obj-$(CONFIG_MSM_PIL) += peripheral-loader.o scm-pas.o
obj-$(CONFIG_MSM_PIL_LPASS_QDSP6V5) += pil-q6v5.o pil-q6v5-lpass.o
obj-$(CONFIG_MSM_PIL_MSS_QDSP6V5) += pil-q6v5.o pil-msa.o pil-q6v5-mss.o
obj-$(CONFIG_MSM_PIL_PRONTO) += pil-pronto.o
obj-$(CONFIG_MSM_PIL_VENUS) += pil-venus.o
obj-$(CONFIG_MSM_BAM_DMUX) += bam_dmux.o
obj-y += socinfo.o

obj-$(CONFIG_MSM_SMD_TTY) += smd_tty.o
obj-$(CONFIG_MSM_SMD_QMI) += smd_qmi.o
obj-$(CONFIG_MSM_SMD_PKT) += smd_pkt.o
obj-$(CONFIG_MSM_SMD_NMEA) += smd_nmea.o

obj-$(CONFIG_MSM_IPC_ROUTER_SMD_XPRT) += ipc_router_smd_xprt.o
obj-$(CONFIG_MSM_IPC_ROUTER) += ipc_router.o ipc_socket.o
obj-$(CONFIG_MSM_IPC_ROUTER_SECURITY)+= msm_ipc_router_security.o

obj-$(CONFIG_MSM_QMI_INTERFACE) += msm_qmi_interface.o

obj-$(CONFIG_DEBUG_FS) += smd_rpc_sym.o

obj-$(CONFIG_MSM_AUDIO_QDSP6V2) += qdsp6v2/

obj-$(CONFIG_PM) += pm-boot.o

obj-$(CONFIG_MSM_IDLE_STATS) += pm-stats.o

obj-$(CONFIG_MSM_SPM_V2) += spm-v2.o spm_devices.o

obj-$(CONFIG_SURF_FFA_GPIO_KEYPAD) += keypad-surf-ffa.o

obj-$(CONFIG_MSM_BOOT_STATS) += boot_stats.o

obj-$(CONFIG_MSM_RPM_REGULATOR_SMD) += rpm-regulator-smd.o

obj-$(CONFIG_MSM_SPM_REGULATOR) += spm-regulator.o

ifdef CONFIG_MSM_SUBSYSTEM_RESTART
	obj-y += subsystem_notif.o
	obj-y += subsystem_restart.o
	obj-y += ramdump.o
endif

obj-$(CONFIG_MSM_SYSMON_COMM) += sysmon.o

obj-$(CONFIG_MSM_ENABLE_WDOG_DEBUG_CONTROL) += wdog_debug.o

obj-$(CONFIG_MSM_WATCHDOG_V2) += msm_watchdog_v2.o

obj-$(CONFIG_MSM_MEMORY_DUMP) += msm_memory_dump.o

obj-$(CONFIG_QPNP_BMS) += bms-batterydata.o bms-batterydata-desay.o batterydata-lib.o
obj-$(CONFIG_QPNP_BMS) += bms-batterydata-oem.o bms-batterydata-qrd-4v35-2000mah.o bms-batterydata-qrd-4v2-1300mah.o

obj-$(CONFIG_ARCH_MSM8226) += gdsc.o

obj-$(CONFIG_ARCH_MSM8226) += board-8226.o board-8226-gpiomux.o
obj-$(CONFIG_ARCH_MSM8226) += clock-local2.o clock-pll.o clock-8226.o clock-rpm.o clock-voter.o clock-mdss-8974.o
obj-$(CONFIG_ARCH_MSM8226) += acpuclock-8226.o acpuclock-cortex.o

obj-$(CONFIG_MSM_PM) += msm-pm.o pm-data.o ext-buck-control.o

CFLAGS_msm_vibrator.o += -Idrivers/staging/android

obj-$(CONFIG_HTC_PWRSINK) += htc_pwrsink.o
obj-$(CONFIG_MSM_RPM) += rpm.o rpm_resources.o
obj-$(CONFIG_MSM_RPM_SMD) += rpm-smd.o lpm_levels.o
obj-$(CONFIG_MSM_MPM_OF) += mpm-of.o
obj-$(CONFIG_MSM_MPM) += mpm.o
obj-$(CONFIG_MSM_RPM_STATS_LOG) += rpm_stats.o rpm_master_stat.o
obj-$(CONFIG_MSM_RPM_RBCPR_STATS_LOG) += rpm_rbcpr_stats.o
obj-$(CONFIG_MSM_RPM_RBCPR_STATS_V2_LOG) += rpm_rbcpr_stats_v2.o
obj-$(CONFIG_MSM_RPM_LOG) += rpm_log.o
obj-$(CONFIG_MSM_TZ_LOG) += tz_log.o
obj-$(CONFIG_MSM_XO) += msm_xo.o
obj-$(CONFIG_MSM_BUS_SCALING) += msm_bus/
obj-$(CONFIG_MSM_BUSPM_DEV) += msm-buspm-dev.o

obj-$(CONFIG_MSM_IOMMU)		+= iommu_domains.o

obj-$(CONFIG_MSM_EVENT_TIMER)		+= event_timer.o

obj-$(CONFIG_MSM_OCMEM) += ocmem.o ocmem_allocator.o ocmem_notifier.o
obj-$(CONFIG_MSM_OCMEM) += ocmem_sched.o ocmem_api.o ocmem_rdm.o ocmem_core.o
obj-$(CONFIG_SENSORS_ADSP) += sensors_adsp.o

obj-$(CONFIG_ARCH_MSM8226) += gpiomux-v2.o gpiomux.o

obj-$(CONFIG_MSM_SLEEP_STATS_DEVICE) += idle_stats_device.o
obj-$(CONFIG_MSM_DCVS) += msm_dcvs_scm.o msm_dcvs.o msm_mpdecision.o
obj-$(CONFIG_MSM_RUN_QUEUE_STATS) += msm_rq_stats.o
obj-$(CONFIG_MSM_SHOW_RESUME_IRQ) += msm_show_resume_irq.o
obj-$(CONFIG_BT_MSM_PINTEST)  += btpintest.o
obj-$(CONFIG_MSM_FAKE_BATTERY) += fish_battery.o
obj-$(CONFIG_MSM_RPC_VIBRATOR) += msm_vibrator.o
obj-$(CONFIG_MSM_NATIVE_RESTART) += restart.o
obj-$(CONFIG_MSM_MODEM_RESTART) += restart_7k.o

obj-$(CONFIG_MSM_PROC_COMM_REGULATOR) += proccomm-regulator.o

obj-$(CONFIG_ARCH_MSM8960) += mdm2.o mdm_common.o
obj-$(CONFIG_MSM_RTB) += msm_rtb.o
obj-$(CONFIG_MSM_CACHE_ERP) += cache_erp.o
obj-$(CONFIG_MSM_EBI_ERP) += ebi_erp.o
obj-$(CONFIG_MSM_CACHE_DUMP) += msm_cache_dump.o

obj-$(CONFIG_MSM_HSIC_SYSMON) += hsic_sysmon.o
obj-$(CONFIG_MSM_HSIC_SYSMON_TEST) += hsic_sysmon_test.o

obj-$(CONFIG_MSM_RPM_SMD) += rpm-smd.o
obj-$(CONFIG_MSM_CPR) += msm_cpr.o
obj-$(CONFIG_MSM_VP_REGULATOR) += msm_vp.o
obj-$(CONFIG_MSM_RPC_PMIC) += pmic.o
obj-$(CONFIG_MSM_RPC_USB) += rpc_hsusb.o rpc_fsusb.o
obj-$(CONFIG_MSM_RPC_PMAPP) += rpc_pmapp.o

obj-$(CONFIG_MSM_FIQ) += msm7k_fiq.o
obj-$(CONFIG_MSM_FIQ) += msm7k_fiq_handler.o

obj-$(CONFIG_MEMORY_HOLE_CARVEOUT) +=  msm_mem_hole.o

obj-$(CONFIG_MSM_SMCMOD) += smcmod.o
obj-$(CONFIG_MSM_CPU_PWRCTL) +=  msm_cpu_pwrctl.o

obj-$(CONFIG_ARCH_MSM8974) += msm_mpmctr.o
obj-$(CONFIG_MSM_CPR_REGULATOR) += cpr-regulator.o
obj-$(CONFIG_CPU_FREQ_MSM) += cpufreq.o
obj-$(CONFIG_MSM_DEVFREQ_CPUBW) += devfreq_cpubw.o

obj-$(CONFIG_WALL_CLK) += wallclk.o
obj-$(CONFIG_WALL_CLK_SYSFS) += wallclk_sysfs.o
obj-$(CONFIG_HAS_MACH_MEMUTILS) += memutils/
obj-$(CONFIG_ARCH_RANDOM) += early_random.o
obj-$(CONFIG_PERFMAP) += perfmap.o
obj-$(CONFIG_FORCE_FAST_CHARGE) += fastchg.o

