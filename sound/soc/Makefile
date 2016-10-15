snd-soc-core-objs := soc-core.o soc-dapm.o soc-jack.o soc-cache.o soc-utils.o
snd-soc-core-objs += soc-pcm.o soc-compress.o soc-io.o

ifneq ($(CONFIG_SND_SOC_DMAENGINE_PCM),)
snd-soc-core-objs += soc-dmaengine-pcm.o
endif

obj-$(CONFIG_SND_SOC)	+= snd-soc-core.o
obj-$(CONFIG_SND_SOC)	+= codecs/
obj-$(CONFIG_SND_SOC)	+= msm/

