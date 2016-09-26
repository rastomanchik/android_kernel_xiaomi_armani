#
# Makefile for the Linux network device drivers.
#

#
# Networking Core Drivers
#
obj-$(CONFIG_DUMMY)     += dummy.o
obj-$(CONFIG_MII)       += mii.o
obj-$(CONFIG_NET)       += Space.o loopback.o
obj-$(CONFIG_TUN)       += tun.o

#
# Networking Drivers
#
obj-$(CONFIG_ETHERNET)  += ethernet/
obj-$(CONFIG_PPP)       += ppp/
obj-$(CONFIG_PPP_ASYNC) += ppp/
obj-$(CONFIG_PPP_BSDCOMP) += ppp/
obj-$(CONFIG_PPP_DEFLATE) += ppp/
obj-$(CONFIG_PPP_MPPE)  += ppp/
obj-$(CONFIG_PPP_SYNC_TTY) += ppp/
obj-$(CONFIG_PPPOE)     += ppp/
obj-$(CONFIG_PPPOL2TP)  += ppp/
obj-$(CONFIG_PPTP)      += ppp/
obj-$(CONFIG_SLHC)      += slip/
obj-$(CONFIG_WLAN)      += wireless/

obj-$(CONFIG_USB_USBNET)    += usb/

