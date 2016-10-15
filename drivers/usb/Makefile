#
# Makefile for the kernel USB device drivers.
#

# Object files in subdirectories

obj-$(CONFIG_USB)		+= core/

obj-$(CONFIG_USB_OTG_UTILS)	+= otg/

obj-$(CONFIG_USB_MON)		+= mon/

obj-$(CONFIG_USB_EHCI_HCD)	+= host/
obj-$(CONFIG_USB_ISP116X_HCD)	+= host/
obj-$(CONFIG_USB_OHCI_HCD)	+= host/
obj-$(CONFIG_USB_UHCI_HCD)	+= host/
obj-$(CONFIG_USB_FHCI_HCD)	+= host/
obj-$(CONFIG_USB_XHCI_HCD)	+= host/
obj-$(CONFIG_USB_SL811_HCD)	+= host/
obj-$(CONFIG_USB_ISP1362_HCD)	+= host/
obj-$(CONFIG_USB_U132_HCD)	+= host/
obj-$(CONFIG_USB_R8A66597_HCD)	+= host/
obj-$(CONFIG_USB_HWA_HCD)	+= host/
obj-$(CONFIG_USB_ISP1760_HCD)	+= host/
obj-$(CONFIG_USB_IMX21_HCD)	+= host/
obj-$(CONFIG_USB_FSL_MPH_DR_OF)	+= host/
obj-$(CONFIG_USB_PEHCI_HCD)	+= host/
obj-$(CONFIG_USB_ICE40_HCD)	+= host/

obj-$(CONFIG_USB_ACM)		+= class/
obj-$(CONFIG_USB_PRINTER)	+= class/
obj-$(CONFIG_USB_WDM)		+= class/
obj-$(CONFIG_USB_TMC)		+= class/
obj-$(CONFIG_USB_CCID_BRIDGE)	+= class/

obj-$(CONFIG_USB_STORAGE)	+= storage/
obj-$(CONFIG_USB)		+= storage/

obj-$(CONFIG_USB)		+= misc/

obj-$(CONFIG_USB_GADGET)	+= gadget/

obj-$(CONFIG_USB_COMMON)	+= usb-common.o
