#
# Makefile for the video capture/playback device drivers.
#

tuner-objs	:=	tuner-core.o

msp3400-objs	:=	msp3400-driver.o msp3400-kthreads.o

stkwebcam-objs	:=	stk-webcam.o stk-sensor.o

omap2cam-objs	:=	omap24xxcam.o omap24xxcam-dma.o

videodev-objs	:=	v4l2-dev.o v4l2-ioctl.o v4l2-device.o v4l2-fh.o \
			v4l2-event.o v4l2-ctrls.o v4l2-subdev.o

# V4L2 core modules

obj-$(CONFIG_VIDEO_DEV) += videodev.o v4l2-int-device.o
obj-$(CONFIG_VIDEO_V4L2_COMMON) += v4l2-common.o


# All i2c modules must come first:

obj-$(CONFIG_VIDEO_TUNER) += tuner.o
obj-$(CONFIG_VIDEO_TVAUDIO) += tvaudio.o
obj-$(CONFIG_VIDEO_TDA7432) += tda7432.o
obj-$(CONFIG_VIDEO_SAA6588) += saa6588.o
obj-$(CONFIG_VIDEO_TDA9840) += tda9840.o
obj-$(CONFIG_VIDEO_TEA6415C) += tea6415c.o
obj-$(CONFIG_VIDEO_TEA6420) += tea6420.o
obj-$(CONFIG_VIDEO_SAA7110) += saa7110.o
obj-$(CONFIG_VIDEO_SAA711X) += saa7115.o
obj-$(CONFIG_VIDEO_SAA717X) += saa717x.o
obj-$(CONFIG_VIDEO_SAA7127) += saa7127.o
obj-$(CONFIG_VIDEO_SAA7185) += saa7185.o
obj-$(CONFIG_VIDEO_SAA7191) += saa7191.o
obj-$(CONFIG_VIDEO_ADV7170) += adv7170.o
obj-$(CONFIG_VIDEO_ADV7175) += adv7175.o
obj-$(CONFIG_VIDEO_ADV7180) += adv7180.o
obj-$(CONFIG_VIDEO_ADV7183) += adv7183.o
obj-$(CONFIG_VIDEO_ADV7343) += adv7343.o
obj-$(CONFIG_VIDEO_VPX3220) += vpx3220.o
obj-$(CONFIG_VIDEO_VS6624)  += vs6624.o
obj-$(CONFIG_VIDEO_BT819) += bt819.o
obj-$(CONFIG_VIDEO_BT856) += bt856.o
obj-$(CONFIG_VIDEO_BT866) += bt866.o
obj-$(CONFIG_VIDEO_KS0127) += ks0127.o
obj-$(CONFIG_VIDEO_THS7303) += ths7303.o
obj-$(CONFIG_VIDEO_VINO) += indycam.o
obj-$(CONFIG_VIDEO_TVP5150) += tvp5150.o
obj-$(CONFIG_VIDEO_TVP514X) += tvp514x.o
obj-$(CONFIG_VIDEO_TVP7002) += tvp7002.o
obj-$(CONFIG_VIDEO_MSP3400) += msp3400.o
obj-$(CONFIG_VIDEO_CS5345) += cs5345.o
obj-$(CONFIG_VIDEO_CS53L32A) += cs53l32a.o
obj-$(CONFIG_VIDEO_M52790) += m52790.o
obj-$(CONFIG_VIDEO_TLV320AIC23B) += tlv320aic23b.o
obj-$(CONFIG_VIDEO_WM8775) += wm8775.o
obj-$(CONFIG_VIDEO_WM8739) += wm8739.o
obj-$(CONFIG_VIDEO_VP27SMPX) += vp27smpx.o
obj-$(CONFIG_VIDEO_UPD64031A) += upd64031a.o
obj-$(CONFIG_VIDEO_UPD64083) += upd64083.o
obj-$(CONFIG_VIDEO_OV7670) 	+= ov7670.o
obj-$(CONFIG_VIDEO_TCM825X) += tcm825x.o
obj-$(CONFIG_VIDEO_TVEEPROM) += tveeprom.o
obj-$(CONFIG_VIDEO_MT9M032) += mt9m032.o
obj-$(CONFIG_VIDEO_MT9P031) += mt9p031.o
obj-$(CONFIG_VIDEO_MT9T001) += mt9t001.o
obj-$(CONFIG_VIDEO_MT9V011) += mt9v011.o
obj-$(CONFIG_VIDEO_MT9V032) += mt9v032.o
obj-$(CONFIG_VIDEO_SR030PC30)	+= sr030pc30.o
obj-$(CONFIG_VIDEO_NOON010PC30)	+= noon010pc30.o
obj-$(CONFIG_VIDEO_S5K6AA)	+= s5k6aa.o
obj-$(CONFIG_VIDEO_ADP1653)	+= adp1653.o
obj-$(CONFIG_VIDEO_AS3645A)	+= as3645a.o

obj-$(CONFIG_SOC_CAMERA_IMX074)		+= imx074.o
obj-$(CONFIG_SOC_CAMERA_MT9M001)	+= mt9m001.o
obj-$(CONFIG_SOC_CAMERA_MT9M111)	+= mt9m111.o
obj-$(CONFIG_SOC_CAMERA_MT9T031)	+= mt9t031.o
obj-$(CONFIG_SOC_CAMERA_MT9T112)	+= mt9t112.o
obj-$(CONFIG_SOC_CAMERA_MT9V022)	+= mt9v022.o
obj-$(CONFIG_SOC_CAMERA_OV2640)		+= ov2640.o
obj-$(CONFIG_SOC_CAMERA_OV5642)		+= ov5642.o
obj-$(CONFIG_SOC_CAMERA_OV6650)		+= ov6650.o
obj-$(CONFIG_SOC_CAMERA_OV772X)		+= ov772x.o
obj-$(CONFIG_SOC_CAMERA_OV9640)		+= ov9640.o
obj-$(CONFIG_SOC_CAMERA_OV9740)		+= ov9740.o
obj-$(CONFIG_SOC_CAMERA_RJ54N1)		+= rj54n1cb0c.o
obj-$(CONFIG_SOC_CAMERA_TW9910)		+= tw9910.o

# And now the v4l2 drivers:

obj-$(CONFIG_VIDEO_CQCAM) += c-qcam.o
obj-$(CONFIG_VIDEO_BWQCAM) += bw-qcam.o
obj-$(CONFIG_VIDEO_W9966) += w9966.o
obj-$(CONFIG_VIDEO_PMS) += pms.o
obj-$(CONFIG_VIDEO_VINO) += vino.o
obj-$(CONFIG_VIDEO_MEYE) += meye.o
obj-$(CONFIG_VIDEO_MXB) += mxb.o
obj-$(CONFIG_VIDEO_HEXIUM_ORION) += hexium_orion.o
obj-$(CONFIG_VIDEO_HEXIUM_GEMINI) += hexium_gemini.o
obj-$(CONFIG_VIDEO_TIMBERDALE)	+= timblogiw.o

obj-$(CONFIG_VIDEOBUF_GEN) += videobuf-core.o
obj-$(CONFIG_VIDEOBUF_DMA_SG) += videobuf-dma-sg.o
obj-$(CONFIG_VIDEOBUF_DMA_CONTIG) += videobuf-dma-contig.o
obj-$(CONFIG_VIDEOBUF_VMALLOC) += videobuf-vmalloc.o
obj-$(CONFIG_VIDEOBUF_DVB) += videobuf-dvb.o
obj-$(CONFIG_VIDEO_BTCX)  += btcx-risc.o

obj-$(CONFIG_VIDEOBUF2_CORE)		+= videobuf2-core.o
obj-$(CONFIG_VIDEOBUF2_MEMOPS)		+= videobuf2-memops.o
obj-$(CONFIG_VIDEOBUF2_VMALLOC)		+= videobuf2-vmalloc.o
obj-$(CONFIG_VIDEOBUF2_DMA_CONTIG)	+= videobuf2-dma-contig.o
obj-$(CONFIG_VIDEOBUF2_DMA_SG)		+= videobuf2-dma-sg.o
obj-$(CONFIG_VIDEOBUF2_MSM_MEM)		+= videobuf2-msm-mem.o

obj-$(CONFIG_V4L2_MEM2MEM_DEV) += v4l2-mem2mem.o

obj-$(CONFIG_VIDEO_M32R_AR_M64278) += arv.o

obj-$(CONFIG_VIDEO_CX2341X) += cx2341x.o

obj-$(CONFIG_VIDEO_VIA_CAMERA) += via-camera.o

obj-$(CONFIG_USB_ZR364XX)       += zr364xx.o
obj-$(CONFIG_USB_STKWEBCAM)     += stkwebcam.o

obj-$(CONFIG_USB_S2255)		+= s2255drv.o

obj-$(CONFIG_VIDEO_VIU) += fsl-viu.o
obj-$(CONFIG_VIDEO_VIVI) += vivi.o

obj-$(CONFIG_VIDEO_AK881X)		+= ak881x.o

obj-$(CONFIG_VIDEO_OMAP2)		+= omap2cam.o
obj-$(CONFIG_SOC_CAMERA)		+= soc_camera.o soc_mediabus.o
obj-$(CONFIG_SOC_CAMERA_PLATFORM)	+= soc_camera_platform.o
# soc-camera host drivers have to be linked after camera drivers
obj-$(CONFIG_VIDEO_MX1)			+= mx1_camera.o
obj-$(CONFIG_VIDEO_MX2)			+= mx2_camera.o
obj-$(CONFIG_VIDEO_MX3)			+= mx3_camera.o
obj-$(CONFIG_VIDEO_PXA27x)		+= pxa_camera.o
obj-$(CONFIG_VIDEO_SH_MOBILE_CSI2)	+= sh_mobile_csi2.o
obj-$(CONFIG_VIDEO_SH_MOBILE_CEU)	+= sh_mobile_ceu_camera.o
obj-$(CONFIG_VIDEO_OMAP1)		+= omap1_camera.o
obj-$(CONFIG_VIDEO_ATMEL_ISI)		+= atmel-isi.o

obj-$(CONFIG_VIDEO_MX2_EMMAPRP)		+= mx2_emmaprp.o

obj-$(CONFIG_VIDEO_SH_VOU)		+= sh_vou.o

obj-$(CONFIG_USB_VIDEO_CLASS)	+= uvc/

obj-$(CONFIG_VIDEO_IR_I2C)  += ir-kbd-i2c.o

ccflags-y += -I$(srctree)/drivers/media/dvb/dvb-core
ccflags-y += -I$(srctree)/drivers/media/dvb/frontends
ccflags-y += -I$(srctree)/drivers/media/common/tuners
